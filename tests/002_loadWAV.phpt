--TEST--
sdl_mixer_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('SDL_mixer')) {
	echo 'skip';
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

$wav = Mix_LoadWAV(__DIR__.'/boing.ogg');
var_dump($wav instanceof Mix_Chunk);

?>
--EXPECT--
bool(false)
string(28) "Mix_LoadWAV_RW with NULL src"
bool(true)
