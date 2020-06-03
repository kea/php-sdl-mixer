dnl config.m4 for extension sdl_mixer

dnl If your extension references something external, use 'with':

PHP_ARG_ENABLE([sdl_mixer],
  [whether to enable sdl_mixer support],
  [AS_HELP_STRING([--enable-sdl_mixer],
    [Enable sdl_mixer support])],
  [no])

if test "$PHP_SDL_MIXER" != "no"; then

  PKG_CHECK_MODULES([LIBSDL_MIXER], [sdl2_mixer >= 2.0])
  PHP_EVAL_INCLINE($LIBSDL_MIXER_CFLAGS)
  PHP_EVAL_LIBLINE($LIBSDL_MIXER_LIBS, SDL_MIXER_SHARED_LIBADD)

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_SDL_MIXER_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your sdl_mixer library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl In case of no dependencies
  AC_DEFINE(HAVE_SDL_MIXER, 1, [ Have sdl_mixer support ])

  PHP_SUBST(SDL_MIXER_SHARED_LIBADD)
  SDL_MIXER_SOURCE_FILES="`find src -name "*.c"`"
  PHP_NEW_EXTENSION(sdl_mixer, $SDL_MIXER_SOURCE_FILES, $ext_shared)

  PHP_ADD_EXTENSION_DEP(sdl_mixer, sdl)
fi
