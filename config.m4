dnl config.m4 for extension sdl_mixer

PHP_ARG_ENABLE([sdl_mixer],
    [whether to enable sdl_mixer support],
    [AS_HELP_STRING([--enable-sdl_mixer],
        [Enable sdl_mixer support])],
    [no])

if test "$PHP_SDL_MIXER" != "no"; then
    AC_DEFINE(WITH_SDL_MIXER, 1, [Whether you want SDL Mixer])
    AC_MSG_CHECKING([for SDL_mixer.h])
    for i in $PHP_SDL_MIXER /usr/local /usr; do
      if test -r $i/include/SDL2/SDL_mixer.h; then
        SDL_MIXER_DIR=$i
        AC_DEFINE(HAVE_SDL_MIXER_H, 1, [Whether you have SDL2/SDL_mixer.h])
        PHP_ADD_INCLUDE($i/include/SDL2)
      fi
    done

    if test -z "$SDL_MIXER_DIR"; then
      AC_MSG_RESULT([not found])
      AC_MSG_ERROR([Please reinstall the SDL_mixer distribution including development files])
    else
      AC_MSG_RESULT([found])
    fi

    AC_CHECK_LIB(SDL2_mixer, Mix_PlayMusic, [
      PHP_ADD_LIBRARY(SDL2_mixer,, SDL_MIXER_SHARED_LIBADD)
    ], [
      AC_MSG_ERROR([libSDL2_mixer not found!])
    ])

    AC_CHECK_LIB(SDL2_mixer, Mix_HasMusicDecoder, [
      AC_DEFINE(HAVE_MIX_HASMUSICDECODER, 1, [ Have sdl_mixer support ])
    ])

  AC_DEFINE(HAVE_SDL_MIXER, 1, [ Have sdl_mixer support ])

  PHP_ADD_BUILD_DIR(PHP_EXT_BUILDDIR(sdl_mixer)[/src])
  PHP_SUBST(SDL_MIXER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(sdl_mixer, src/effect_position.c src/effect_stereoreverse.c src/Mix_Music.c src/Mix_Chunk.c src/music.c src/mixer.c src/php_sdl_mixer.c, $ext_shared)
  PHP_ADD_EXTENSION_DEP(sdl_mixer, sdl)
fi
