/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) The PHP Group                                          |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | https://www.php.net/license/3_01.txt                                 |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
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
