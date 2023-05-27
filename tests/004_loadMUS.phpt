--TEST--
Mix_OpenAudio, Mix_LoadMUS ogg file
--EXTENSIONS--
SDL_mixer
--FILE--
<?php

if (\Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    throw new RuntimeException("Cannot open audio device");
}

$wav = Mix_LoadMUS(__DIR__.'/boing.ogg');
var_dump($wav instanceof Mix_Music);

?>
--EXPECTF--
bool(true)
