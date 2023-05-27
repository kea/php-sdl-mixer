--TEST--
Mix_OpenAudio, Mix_ClearError, Mix_QuerySpec, Mix_GetError
--EXTENSIONS--
SDL_mixer
--FILE--
<?php

if (\Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    throw new RuntimeException("Cannot open audio device");
}

Mix_ClearError();
$opened = \Mix_QuerySpec($frequency, $format, $channels);
var_dump($opened);
var_dump($frequency);
var_dump($format);
var_dump($channels);
var_dump(Mix_GetError());

?>
--EXPECTF--
int(1)
int(44100)
int(32784)
int(2)
string(0) ""
