--TEST--
Check if sdl_mixer is loaded
--SKIPIF--
<?php
if (!extension_loaded('sdl_mixer')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "sdl_mixer" is available';
?>
--EXPECT--
The extension "sdl_mixer" is available
