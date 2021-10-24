/*
   +----------------------------------------------------------------------+
   | PHP Version 8                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2021 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Manuel Baldassarri <manuel@baldassarri.me>                   |
   +----------------------------------------------------------------------+
*/

#include "php_sdl_mixer.h"
#include "chunk.h"
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
	php_info_print_table_start();
	php_info_print_table_header(2, "SDL_mixer support", "enabled");
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

