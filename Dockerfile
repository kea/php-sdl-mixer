# Build and test the extension against an official PHP image:
#   docker build --build-arg PHP_VERSION=8.4 -t php-sdl-mixer:8.4 .
#   docker run --rm php-sdl-mixer:8.4
ARG PHP_VERSION=8.4
FROM php:${PHP_VERSION}-cli

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -yq --no-install-recommends \
        ca-certificates \
        git \
        libsdl2-dev \
        libsdl2-mixer-dev \
        pkg-config \
    && rm -rf /var/lib/apt/lists/*

# sdl 2.7.0 on PECL does not build on PHP 8.5 and emits startup warnings
# on PHP 8.x: build it from an upstream commit that fixes both.
ARG SDL_REF=419eb9d759e8d56b106455c5a84d25fe67526c63
RUN git clone https://github.com/Ponup/php-sdl.git /usr/src/php-sdl \
    && cd /usr/src/php-sdl \
    && git checkout "$SDL_REF" \
    && phpize \
    && ./configure \
    && make -j"$(nproc)" \
    && make install

WORKDIR /opt/php-sdl-mixer
COPY config.m4 php_sdl_mixer.c php_sdl_mixer.h php_sdl_mixer_arginfo.h ./
COPY src ./src
COPY tests ./tests

RUN phpize \
    && ./configure --with-sdl_mixer \
    && make -j"$(nproc)"

ENV SDL_AUDIODRIVER=dummy
CMD ["sh", "-c", "php /usr/local/lib/php/build/run-tests.php -d extension=sdl.so -d extension=$PWD/modules/sdl_mixer.so --offline --show-diff --set-timeout 120 -q tests"]
