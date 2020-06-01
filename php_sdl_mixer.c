/* sdl_mixer extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php_sdl_mixer.h"

extern int Mix_OpenAudio(int frequency, Uint16 format, int nchannels, int chunksize)

/*
Mix_Chunk *gScratch = NULL;
Mix_Music *gMusic = NULL;

gMusic = Mix_LoadMUS( "beat.wav" );
gScratch = Mix_LoadWAV( "scratch.wav" );

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

/* {{{ proto SDL_Texture Mix_OpenAudio(string file)

	PHP note: stream are supported

 *  Load a texture from a file.
 extern int Mix_OpenAudio(int frequency, Uint16 format, int nchannels, int chunksize)
 */
PHP_FUNCTION(Mix_OpenAudio)
{
    int frequency, Uint16 format, int nchannels, int chunksize;
    zend_string *path;
	SDL_Texture *texture = NULL;

	zval *z_renderer = NULL;
	SDL_Renderer *renderer = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(frequency)
        Z_PARAM_LONG(format)
        Z_PARAM_LONG(nchannels)
        Z_PARAM_LONG(chunksize)
	ZEND_PARSE_PARAMETERS_END();

    RETURN_INT(Mix_OpenAudio(frequency, format, nchannels, chunksize));
}
/* }}} */

static const zend_function_entry php_sdl_mixer_functions[] = {
	PHP_FE(Mix_OpenAudio,		arginfo_Mix_OpenAudio)

    PHP_FE_END
};

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(sdl_mixer)
{
#if defined(ZTS) && defined(COMPILE_DL_SDL_IMAGE)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

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
	"SDL_ mixer",					/* Extension name */
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

#ifdef COMPILE_DL_SDL_IMAGE
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(sdl_mixer)
#endif
