/* sdl_mixer extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php_sdl_mixer.h"

static zend_class_entry *php_mix_chunk_ce;
static zend_object_handlers php_mix_chunk_handlers;

struct php_mix_chunk
{
    Mix_Chunk *intern;
    zend_object zo;
};
typedef struct php_mix_chunk php_mix_chunk_t;

static zend_object *php_mix_chunk_create_object(zend_class_entry *ce)
{
    php_mix_chunk_t *php_mix_chunk;

    php_mix_chunk = (php_mix_chunk_t *)ecalloc(1, sizeof(php_mix_chunk_t) + zend_object_properties_size(ce));

    zend_object_std_init(&php_mix_chunk->zo, ce);
    object_properties_init(&php_mix_chunk->zo, ce);

    php_mix_chunk->intern = NULL;
    php_mix_chunk->zo.handlers = (zend_object_handlers *)&php_mix_chunk_handlers;

    return &php_mix_chunk->zo;
}

static void php_mix_chunk_free_object(zend_object *zo)
{
    // Mix_FreeChunk ???
    php_mix_chunk_t *php_mix_chunk = (php_mix_chunk_t *)((char *)zo - zo->handlers->offset);
    zend_object_std_dtor(&php_mix_chunk->zo);
}

static inline Mix_Chunk *mix_chunk_from_zval(zval *zmix_chunk)
{
    zend_object *zo = Z_OBJ_P(zmix_chunk);
    php_mix_chunk_t *php_mix_chunk = (php_mix_chunk_t *)((char *)zo - zo->handlers->offset);
    return php_mix_chunk->intern;
}

static inline void mix_chunk_to_zval(Mix_Chunk *mix_chunk, zval *zvalue)
{
    object_init_ex(zvalue, php_mix_chunk_ce);
    zend_object *zo = Z_OBJ_P(zvalue);
    php_mix_chunk_t *php_mix_chunk = (php_mix_chunk_t *)((char *)zo - zo->handlers->offset);
    php_mix_chunk->intern = mix_chunk;
}


/*
Mix_Chunk *gScratch = NULL;
Mix_Music *gMusic = NULL;

gMusic = Mix_LoadMUS( "beat.wav" );
gScratch = Mix_LoadWAV( "scratch.wav" );

Mix_PlayChannel( -1, gHigh, 0 );

Mix_FreeChunk( gScratch );
Mix_FreeMusic( gMusic );
Mix_Quit();

Mix_PlayingMusic()
Mix_PlayMusic( gMusic, -1 )
Mix_PausedMusic()
Mix_ResumeMusic()
Mix_PauseMusic()
Mix_HaltMusic()
*/

/* {{{ proto int Mix_OpenAudio(string file)
  extern int Mix_OpenAudio(int frequency, Uint16 format, int nchannels, int chunksize)
 */
PHP_FUNCTION(Mix_OpenAudio)
{
    zend_long frequency;
    zend_long format;
    zend_long nchannels;
    zend_long chunksize;

	ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(frequency)
        Z_PARAM_LONG(format)
        Z_PARAM_LONG(nchannels)
        Z_PARAM_LONG(chunksize)
	ZEND_PARSE_PARAMETERS_END();

    RETURN_LONG(Mix_OpenAudio((int)frequency, (Uint16)format, (int)nchannels, (int)chunksize));
}
/* }}} */

/* {{{ proto Mix_Chunk * Mix_LoadWAV(string file)
  #define Mix_LoadWAV(file)   Mix_LoadWAV_RW(SDL_RWFromFile(file, "rb"), 1)
  extern DECLSPEC Mix_Chunk * SDLCALL Mix_LoadWAV_RW(SDL_RWops *src, int freesrc);
 */
PHP_FUNCTION(Mix_LoadWAV)
{
    zend_string *path;
    Mix_Chunk *mix_chunk = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();

    mix_chunk = Mix_LoadWAV_RW(SDL_RWFromFile(ZSTR_VAL(path), "rb"), 1);

    mix_chunk_to_zval(mix_chunk, return_value);
}
/* }}} */

/* {{{ proto int Mix_PlayChannel(-1, chunk, 0)
  #define Mix_PlayChannel(channel,chunk,loops) Mix_PlayChannelTimed(channel,chunk,loops,-1)
  extern DECLSPEC int SDLCALL Mix_PlayChannelTimed(int channel, Mix_Chunk *chunk, int loops, int ticks);
 */
PHP_FUNCTION(Mix_PlayChannel)
{
    zval *zchunk;
    zend_string *path;
    Mix_Chunk *mix_chunk = NULL;
    zend_long channel;
    zend_long loops;
    int nchannels;

	ZEND_PARSE_PARAMETERS_START(3, 3)
	    Z_PARAM_LONG(channel)
		Z_PARAM_OBJECT_OF_CLASS(zchunk, php_mix_chunk_ce)
		Z_PARAM_LONG(loops)
	ZEND_PARSE_PARAMETERS_END();

    mix_chunk = mix_chunk_from_zval(zchunk);
    nchannels = Mix_PlayChannelTimed((int)channel,mix_chunk,(int)loops,-1);

    RETURN_LONG(nchannels);
}
/* }}} */

static const zend_function_entry php_sdl_mixer_functions[] = {
	PHP_FE(Mix_OpenAudio,	    arginfo_Mix_OpenAudio)
	PHP_FE(Mix_LoadWAV,		    arginfo_Mix_LoadWAV)
	PHP_FE(Mix_PlayChannel,	    arginfo_Mix_PlayChannel)

    PHP_FE_END
};

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(sdl_mixer)
{
#if defined(ZTS) && defined(COMPILE_DL_SDL_IMAGE)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

    REGISTER_LONG_CONSTANT("MIX_DEFAULT_CHANNELS", MIX_DEFAULT_CHANNELS, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("MIX_DEFAULT_FREQUENCY", MIX_DEFAULT_FREQUENCY, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("MIX_DEFAULT_FORMAT", MIX_DEFAULT_FORMAT, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("MIX_MAX_VOLUME", MIX_MAX_VOLUME, CONST_CS | CONST_PERSISTENT);

    zend_class_entry mix_chunk_ce;
    INIT_CLASS_ENTRY(mix_chunk_ce, "Mix_Chunk", NULL);

    php_mix_chunk_ce = zend_register_internal_class(&mix_chunk_ce);
    php_mix_chunk_ce->create_object = php_mix_chunk_create_object;

    memcpy(&php_mix_chunk_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    php_mix_chunk_handlers.free_obj = php_mix_chunk_free_object;
    php_mix_chunk_handlers.offset = XtOffsetOf(php_mix_chunk_t, zo);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(sdl_mixer)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "sdl_mixer support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ sdl_mixer_module_entry
 */
zend_module_entry sdl_mixer_module_entry = {
	STANDARD_MODULE_HEADER,
	"SDL_mixer",					/* Extension name */
	php_sdl_mixer_functions,		/* zend_function_entry */
	PHP_MINIT(sdl_mixer),	        /* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	NULL,               			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(sdl_mixer),			/* PHP_MINFO - Module info */
	PHP_SDL_IMAGE_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SDL_MIXER
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(sdl_mixer)
#endif
