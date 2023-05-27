# SDL_mixer PHP Extension
[SDL_mixer](https://www.libsdl.org/projects/SDL_mixer/) for PHP allows to easily load audio files (WAV, OGG, etc.) and play them.
It requires SDL PHP Extension.

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

### Run test with docker (ubuntu or fedora)
```bash
$ docker build --rm  -t sdl_mixer:fedora -f Dockerfile.fedora .
$ docker run -it --rm sdl_mixer:fedora 
```
or
```bash
$ docker build --rm  -t sdl_mixer:ubuntu -f Dockerfile.ubuntu .
$ docker run -it --rm sdl_mixer:ubuntu 
```
