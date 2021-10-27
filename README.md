# SDL_mixer PHP Extension
[SDL_mixer](https://www.libsdl.org/projects/SDL_mixer/) for PHP allows to easily load audio files (WAV, OGG, etc.) and play them.
It requires SDL PHP Extension.

## Building

```bash
$ phpize
$ ./configure --enable-sdl_mixer
$ make
$ make install
```

Run tests with installed PHP (avoids skipped tests):

```
$ php run-tests.php --show-diff -q
```

## Requirements

Require PHP 8+ and SDL PHP extension

```
$ pecl install sdl-devel
```