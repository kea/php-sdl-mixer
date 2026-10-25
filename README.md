# SDL_mixer PHP Extension
[SDL_mixer](https://www.libsdl.org/projects/SDL_mixer/) for PHP allows to easily load audio files (WAV, OGG, etc.) and play them.
It requires SDL PHP Extension.

## Installing with PIE

Install with [PIE](https://github.com/php/pie) (PHP Installer for Extensions):

```bash
$ pie install kea/php-sdl-mixer
```

The SDL_mixer development files (e.g. `libsdl2-mixer-dev` on Debian/Ubuntu) and the SDL PHP extension must be installed first.
If SDL_mixer is in a non-standard location:

```bash
$ pie install kea/php-sdl-mixer --with-sdl_mixer=/opt/sdl_mixer
```

## Install via Pecl

```bash
$ pecl install sdl-beta sdl_mixer-devel
```

## Building

```bash
$ phpize
$ ./configure --with-sdl_mixer
$ make
$ make install
```

### Run tests with installed PHP:

```
$ php run-tests.php --show-diff -q
```

### Run tests with docker

```bash
$ docker build --build-arg PHP_VERSION=8.4 -t php-sdl-mixer:8.4 .
$ docker run --rm php-sdl-mixer:8.4
```
