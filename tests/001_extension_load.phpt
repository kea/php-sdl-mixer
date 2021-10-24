--TEST--
Check if sdl_mixer is loaded
--FILE--
<?php
if (!extension_loaded('SDL_mixer')) {
	throw new RuntimeException();
}

echo 'The extension "SDL_mixer" is available';
?>
--EXPECT--
The extension "SDL_mixer" is available
