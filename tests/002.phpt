--TEST--
sdl_mixer_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('sdl_mixer')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = sdl_mixer_test1();

var_dump($ret);
?>
--EXPECT--
The extension sdl_mixer is loaded and working!
NULL
