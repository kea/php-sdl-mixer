--TEST--
Mix_OpenAudio, Mix_LoadWAV file not exists
--EXTENSIONS--
SDL_mixer
--SKIPIF--
<?php
if (version_compare(phpversion('sdl_mixer'), '1.0.0', '<')) {
	die('skip @todo check segmentation fault');
}

?>
--FILE--
<?php

if (\Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    throw new RuntimeException("Cannot open audio device");
}

$wav = Mix_LoadWAV(__DIR__.'/boing_doesnt_exist.ogg');
var_dump($wav instanceof Mix_Chunk);
var_dump(Mix_GetError());

?>
--EXPECT--
bool(false)
string(28) "Mix_LoadWAV_RW with NULL src"
