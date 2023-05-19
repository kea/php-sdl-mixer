dnl config.m4 for extension sdl_mixer

PHP_ARG_WITH([sdl_mixer],
  [whether to enable sdl_mixer support],
  [AS_HELP_STRING([[--with-sdl_mixer[=DIR]]],
    [Include SDL_mixer support. DIR is the SDL_mixer base include and lib directory])])

if test "$PHP_SDL_MIXER" != "no"; then
  SEARCH_PATH="/usr/local /usr"
  SEARCH_FOR="/include/SDL2/SDL_mixer.h"
  AC_MSG_CHECKING([for SDL_mixer files])
  if test -r $PHP_SDL_MIXER/$SEARCH_FOR; then # path given as parameter
    SDL_MIXER_DIR=$PHP_SDL_MIXER
  else # search default path list
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        SDL_MIXER_DIR=$i
      fi
    done
  fi

  if test -z "$SDL_MIXER_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the SDL_mixer distribution])
  fi

  PHP_ADD_INCLUDE($SDL_MIXER_DIR/include)
  AC_MSG_RESULT(found in $SDL_MIXER_DIR)

  PKG_CHECK_MODULES([_SDL2], [sdl2 < 3.0])
  PHP_EVAL_INCLINE($_SDL2_CFLAGS)

  LIBNAME=SDL2_mixer
  LIBSYMBOL=Mix_PlayMusic
  AC_CHECK_LIB($LIBNAME, $LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SDL_MIXER_DIR/$PHP_LIBDIR, SDL_MIXER_SHARED_LIBADD)
    AC_DEFINE(HAVE_SDL_MIXER_FEATURE, 1, [ ])
  ],[
    AC_MSG_ERROR([$LIBNAME not found!])
  ],[
    -L$SDL_MIXER_DIR/$PHP_LIBDIR $_SDL2_LIBS
  ])

  PHP_SUBST(SDL_MIXER_SHARED_LIBADD)

  AC_DEFINE(HAVE_SDL_MIXER, 1, [ Have sdl_mixer support ])

  PHP_SUBST(SDL_MIXER_SHARED_LIBADD)
  PHP_NEW_EXTENSION(sdl_mixer, src/effect_position.c src/effect_stereoreverse.c src/Mix_Music.c src/Mix_Chunk.c src/music.c src/mixer.c php_sdl_mixer.c, $ext_shared)
  PHP_ADD_EXTENSION_DEP(sdl_mixer, sdl)
fi
