--TEST--
Mix_OpenAudio, Mix_LoadWAV ogg file
--EXTENSIONS--
sdl_mixer
--FILE--
<?php

if (\Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    throw new RuntimeException("Cannot open audio device");
}

$wav = Mix_LoadWAV(__DIR__.'/boing.ogg');
var_dump($wav instanceof Mix_Chunk);

?>
--EXPECT--
bool(true)
