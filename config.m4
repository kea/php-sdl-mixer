dnl config.m4 for extension sdl_mixer

PHP_ARG_ENABLE([sdl_mixer],
  [whether to enable sdl_mixer support],
  [AS_HELP_STRING([--enable-sdl_mixer],
    [Enable sdl_mixer support])],
  [no])

if test "$PHP_SDL_MIXER" != "no"; then
  PKG_CHECK_MODULES([LIBSDL_MIXER], [SDL2_mixer >= 2.0])
  PHP_EVAL_INCLINE($LIBSDL_MIXER_CFLAGS)
  PHP_EVAL_LIBLINE($LIBSDL_MIXER_LIBS, SDL_MIXER_SHARED_LIBADD)

  AC_DEFINE(HAVE_SDL_MIXER, 1, [ Have sdl_mixer support ])

  PHP_SUBST(SDL_MIXER_SHARED_LIBADD)
  SDL_MIXER_SOURCE_FILES="`find src -name "*.c"`"
  PHP_NEW_EXTENSION(sdl_mixer, $SDL_MIXER_SOURCE_FILES, $ext_shared)

  PHP_ADD_EXTENSION_DEP(sdl_mixer, sdl)
fi
