/*
   +----------------------------------------------------------------------+
   | Author: Manuel Baldassarri <manuel@baldassarri.me>                   |
   +----------------------------------------------------------------------+
*/

#ifndef PHP_SDL_MIXER_H
#define PHP_SDL_MIXER_H

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include <zend_exceptions.h>

#define PHP_SDL_MIXER_VERSION "0.2.0"

#if defined(__APPLE__) && defined(__MACH__)
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include <php.h>
#include <ext/standard/info.h>
#include "php_sdl_mixer_arginfo.h"

#ifdef  __cplusplus
} // extern "C"
#endif
#ifdef  __cplusplus
extern "C" {
#endif

extern zend_module_entry sdl_mixer_module_entry;
#define phpext_sdl_mixer_ptr &sdl_mixer_module_entry

#ifdef PHP_WIN32
#define PHP_SDL_API __declspec(dllexport)
#else
#define PHP_SDL_API
#endif

PHP_MINIT_FUNCTION(sdl_mixer);
PHP_MINFO_FUNCTION(sdl_mixer);

#ifdef ZTS
#include "TSRM.h"
#endif

#ifdef  __cplusplus
} // extern "C"
#endif

#endif /* PHP_SDL_MIXER_H */
