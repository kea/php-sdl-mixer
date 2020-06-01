--TEST--
sdl_mixer_test2() Basic test
--SKIPIF--
<?php
if (!extension_loaded('sdl_mixer')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(sdl_mixer_test2());
var_dump(sdl_mixer_test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
