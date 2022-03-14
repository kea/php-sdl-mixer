#include "php_sdl_mixer.h"
#include "mixer.h"
#include "music.h"
#include "php_sdl_mixer_arginfo.h"
#include "zend_smart_string.h"

#ifdef COMPILE_DL_SDL_MIXER
ZEND_GET_MODULE(sdl_mixer)
#endif

#define PHP_MINIT_CALL(func) PHP_MINIT(func)(INIT_FUNC_ARGS_PASSTHRU)

static int sld_mixer_flags;

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(sdl_mixer)
{
	sld_mixer_flags = Mix_Init(MIX_INIT_FLAC|MIX_INIT_MOD|MIX_INIT_MP3|MIX_INIT_OGG|MIX_INIT_MID|MIX_INIT_OPUS);

	php_mix_chunk_minit_helper();
	php_mix_music_minit_helper();

    REGISTER_LONG_CONSTANT("MIX_DEFAULT_CHANNELS", MIX_DEFAULT_CHANNELS, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("MIX_DEFAULT_FREQUENCY", MIX_DEFAULT_FREQUENCY, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("MIX_DEFAULT_FORMAT", MIX_DEFAULT_FORMAT, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("MIX_MAX_VOLUME", MIX_MAX_VOLUME, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("MIX_CHANNELS", MIX_CHANNELS, CONST_CS | CONST_PERSISTENT);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(sdl_mixer)
{
	Mix_Quit();

	return SUCCESS;
}
/* }}} */

PHP_MINFO_FUNCTION(sdl_mixer)
{
	char buffer[128];
	smart_string info = {0};
	SDL_version compile_version;
	const SDL_version *link_version = Mix_Linked_Version();
	SDL_MIXER_VERSION(&compile_version);

	php_info_print_table_start();
	php_info_print_table_row(2, "SDL_mixer support", "enabled");
	php_info_print_table_row(2, "SDL_mixer PHP extension version", PHP_SDL_MIXER_VERSION);
	snprintf(buffer, sizeof(buffer), "%d.%d.%d", link_version->major, link_version->minor, link_version->patch);
	php_info_print_table_row(2, "SDL_mixer linked version", buffer);
	snprintf(buffer, sizeof(buffer), "%d.%d.%d", compile_version.major, compile_version.minor, compile_version.patch);
	php_info_print_table_row(2, "SDL_mixer compiled version", buffer);
	if (sld_mixer_flags & MIX_INIT_FLAC) {
		smart_string_appends(&info, "flac");
	}
	if (sld_mixer_flags & MIX_INIT_MOD) {
		smart_string_appends(&info, ", mod");
	}
	if (sld_mixer_flags & MIX_INIT_MP3) {
		smart_string_appends(&info, ", mp3");
	}
	if (sld_mixer_flags & MIX_INIT_OGG) {
		smart_string_appends(&info, ", ogg");
	}
	if (sld_mixer_flags & MIX_INIT_MID) {
		smart_string_appends(&info, ", mid");
	}
	if (sld_mixer_flags & MIX_INIT_OPUS) {
		smart_string_appends(&info, ", opus");
	}
	smart_string_0(&info);
	php_info_print_table_row(2, "SDL_mixer flags", info.c);
	smart_string_free(&info);

	php_info_print_table_end();
}

static const zend_module_dep ext_deps[] = {
    ZEND_MOD_REQUIRED("sdl")
    ZEND_MOD_END
};

zend_module_entry sdl_mixer_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	ext_deps,
	"SDL_mixer",
	ext_functions,
	PHP_MINIT(sdl_mixer),
	PHP_MSHUTDOWN(sdl_mixer),
	NULL, /* PHP_RINIT - Request initialization */
	NULL, /* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(sdl_mixer),
	PHP_SDL_MIXER_VERSION,
	STANDARD_MODULE_PROPERTIES
};

