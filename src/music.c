#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "music.h"

extern zend_class_entry *mix_music_ce;
extern zend_class_entry *get_php_sdl_rwops_ce(void);
extern SDL_RWops *zval_to_sdl_rwops(zval *z_val);
#define php_sdl_rwops_from_zval_p zval_to_sdl_rwops

PHP_FUNCTION(Mix_LoadMUS)
{
	char *file = NULL;
	size_t file_len = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_STRING(file, file_len)
	ZEND_PARSE_PARAMETERS_END();

	Mix_Music * result = Mix_LoadMUS((const char*)file);

	if (result == NULL) {
		RETURN_NULL();
	}

	mix_music_to_zval(result, return_value);
}

PHP_FUNCTION(Mix_LoadMUS_RW)
{
	zval *SRC;
	SDL_RWops *src;

	zend_long freesrc;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_OBJECT_OF_CLASS(SRC, get_php_sdl_rwops_ce())
		Z_PARAM_LONG(freesrc)
	ZEND_PARSE_PARAMETERS_END();
	src = php_sdl_rwops_from_zval_p(SRC);

	Mix_Music * result = Mix_LoadMUS_RW(src, freesrc);

	if (result == NULL) {
		RETURN_NULL();
	}

	mix_music_to_zval(result, return_value);
}

PHP_FUNCTION(Mix_FreeMusic)
{
	zval *MUSIC;
	Mix_Music *music;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_OBJECT_OF_CLASS(MUSIC, mix_music_ce)
	ZEND_PARSE_PARAMETERS_END();
	music = php_mix_music_from_zval_p(MUSIC);
	Mix_FreeMusic(music);
}

PHP_FUNCTION(Mix_GetNumMusicDecoders)
{
	ZEND_PARSE_PARAMETERS_NONE();

	int result = Mix_GetNumMusicDecoders();

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GetMusicDecoder)
{
	zend_long index;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();

	const char * result = Mix_GetMusicDecoder(index);

	RETURN_STRING(result);
}

PHP_FUNCTION(Mix_HasMusicDecoder)
{
	char *name = NULL;
	size_t name_len = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_STRING(name, name_len)
	ZEND_PARSE_PARAMETERS_END();

	SDL_bool result = Mix_HasMusicDecoder((const char*)name);

	RETURN_BOOL(result == SDL_TRUE);
}

PHP_FUNCTION(Mix_PlayMusic)
{
	zval *MUSIC;
	Mix_Music *music;

	zend_long loops;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_OBJECT_OF_CLASS(MUSIC, mix_music_ce)
		Z_PARAM_LONG(loops)
	ZEND_PARSE_PARAMETERS_END();
	music = php_mix_music_from_zval_p(MUSIC);

	int result = Mix_PlayMusic(music, loops);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_FadeInMusic)
{
	zval *MUSIC;
	Mix_Music *music;

	zend_long loops;

	zend_long ms;

	ZEND_PARSE_PARAMETERS_START(3, 3);
		Z_PARAM_OBJECT_OF_CLASS(MUSIC, mix_music_ce)
		Z_PARAM_LONG(loops)
		Z_PARAM_LONG(ms)
	ZEND_PARSE_PARAMETERS_END();
	music = php_mix_music_from_zval_p(MUSIC);

	int result = Mix_FadeInMusic(music, loops, ms);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_FadeInMusicPos)
{
	zval *MUSIC;
	Mix_Music *music;
	zend_long loops;
	zend_long ms;
	double position;

	ZEND_PARSE_PARAMETERS_START(4, 4);
		Z_PARAM_OBJECT_OF_CLASS(MUSIC, mix_music_ce)
		Z_PARAM_LONG(loops)
		Z_PARAM_LONG(ms)
		Z_PARAM_DOUBLE(position)
	ZEND_PARSE_PARAMETERS_END();
	music = php_mix_music_from_zval_p(MUSIC);

	int result = Mix_FadeInMusicPos(music, loops, ms, position);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_VolumeMusic)
{
	zend_long volume;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(volume)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_VolumeMusic(volume);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_HaltMusic)
{
	ZEND_PARSE_PARAMETERS_NONE();

	int result = Mix_HaltMusic();

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_FadeOutMusic)
{
	zend_long ms;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(ms)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_FadeOutMusic(ms);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_PauseMusic)
{
	ZEND_PARSE_PARAMETERS_NONE();

	Mix_PauseMusic();
}

PHP_FUNCTION(Mix_ResumeMusic)
{
	ZEND_PARSE_PARAMETERS_NONE();

	Mix_ResumeMusic();
}

PHP_FUNCTION(Mix_RewindMusic)
{
	ZEND_PARSE_PARAMETERS_NONE();

	Mix_RewindMusic();
}

PHP_FUNCTION(Mix_PausedMusic)
{
	ZEND_PARSE_PARAMETERS_NONE();

	int result = Mix_PausedMusic();

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_SetMusicPosition)
{
	double position;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_DOUBLE(position)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_SetMusicPosition(position);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_PlayingMusic)
{
	ZEND_PARSE_PARAMETERS_NONE();

	int result = Mix_PlayingMusic();

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_SetMusicCMD)
{
	char *command = NULL;
	size_t command_len = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_STRING(command, command_len)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_SetMusicCMD((const char*)command);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_SetSynchroValue)
{
	zend_long value;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_SetSynchroValue(value);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GetSynchroValue)
{
	ZEND_PARSE_PARAMETERS_NONE();

	int result = Mix_GetSynchroValue();

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_SetSoundFonts)
{
	char *paths = NULL;
	size_t paths_len = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_STRING(paths, paths_len)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_SetSoundFonts((const char*)paths);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GetSoundFonts)
{
	ZEND_PARSE_PARAMETERS_NONE();

	const char* result = Mix_GetSoundFonts();

	RETURN_STRING(result);
}
