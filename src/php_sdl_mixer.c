/*
   +----------------------------------------------------------------------+
   | Author: Manuel Baldassarri <manuel@baldassarri.me>                   |
   +----------------------------------------------------------------------+
*/

#include "php_sdl_mixer.h"
#include "mixer.h"
#include "music.h"
#include "php_sdl_mixer_arginfo.h"

#ifdef COMPILE_DL_SDL_MIXER
ZEND_GET_MODULE(sdl_mixer)
#endif

#define PHP_MINIT_CALL(func) PHP_MINIT(func)(INIT_FUNC_ARGS_PASSTHRU)

PHP_MINIT_FUNCTION(sdl_mixer)
{
#if defined(ZTS) && defined(COMPILE_DL_SDL_MIXER)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	if (SUCCESS == PHP_MINIT_CALL(mix_chunk)
		&& SUCCESS == PHP_MINIT_CALL(mix_music)
	) {
		return SUCCESS;
	}

    return FAILURE;
}

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

zend_module_entry sdl_mixer_module_entry = {
	STANDARD_MODULE_HEADER,
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

