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

#ifndef PHP_MIX_MUSIC_H
#define PHP_MIX_MUSIC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "php_sdl_mixer.h"
#include "SDL_mixer.h"

  ZEND_BEGIN_ARG_INFO(arginfo_Mix_LoadMUS, 0)
      ZEND_ARG_INFO(0, path)
  ZEND_END_ARG_INFO()
  PHP_FUNCTION(Mix_LoadMUS);

  ZEND_BEGIN_ARG_INFO_EX(arginfo_Mix_PlayMusic, 0, 0, 2)
    ZEND_ARG_OBJ_INFO(0, music, Mix_Music, 0)
    ZEND_ARG_TYPE_INFO(0, loops, IS_LONG, 0)
  ZEND_END_ARG_INFO()
  PHP_FUNCTION(Mix_PlayMusic);

  ZEND_BEGIN_ARG_INFO_EX(arginfo_Mix_VolumeMusic, 0, 0, 1)
    ZEND_ARG_TYPE_INFO(0, volume, IS_LONG, 0)
  ZEND_END_ARG_INFO()
  PHP_FUNCTION(Mix_VolumeMusic);

  PHP_MINIT_FUNCTION(mix_music);

#ifdef __cplusplus
}
#endif

#endif
