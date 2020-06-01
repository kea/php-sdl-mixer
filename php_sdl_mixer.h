/* sdl_mixer extension for PHP */

#ifndef PHP_SDL_IMAGE_H
# define PHP_SDL_IMAGE_H

#define PHP_SDL_IMAGE_VERSION "0.1.0"

#if defined(__APPLE__) && defined(__MACH__)
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif

#include "php.h"
#include "ext/standard/info.h"

# include <SAPI.h>
# include <Zend/zend_extensions.h>

extern zend_module_entry sdl_mixer_module_entry;
#define phpext_sdl_mixer_ptr &sdl_mixer_module_entry

ZEND_BEGIN_ARG_INFO(arginfo_Mix_OpenAudio, 0)
    ZEND_ARG_INFO(0, frequency)
    ZEND_ARG_INFO(0, format)
    ZEND_ARG_INFO(0, nchannels)
    ZEND_ARG_INFO(0, chunksize)
ZEND_END_ARG_INFO()

PHP_FUNCTION(Mix_OpenAudio);

PHP_MINIT_FUNCTION(sdl_mixer);

# if defined(ZTS) && defined(COMPILE_DL_SDL_IMAGE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_SDL_IMAGE_H */
