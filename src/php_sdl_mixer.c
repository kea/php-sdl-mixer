#include "php_sdl_mixer.h"
#include "mixer.h"
#include "music.h"

#ifdef COMPILE_DL_SDL_MIXER
ZEND_GET_MODULE(sdl_mixer)
#endif

#define PHP_MINIT_CALL(func) PHP_MINIT(func)(INIT_FUNC_ARGS_PASSTHRU)

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(sdl_mixer)
{
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

PHP_MINFO_FUNCTION(sdl_mixer)
{
	char buffer[128];
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
	NULL, /* PHP_MSHUTDOWN - Module shutdown */
	NULL, /* PHP_RINIT - Request initialization */
	NULL, /* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(sdl_mixer),
	PHP_SDL_MIXER_VERSION,
	STANDARD_MODULE_PROPERTIES
};

