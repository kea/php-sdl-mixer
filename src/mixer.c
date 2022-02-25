#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "mixer.h"

static zend_class_entry *php_mix_chunk_ce;
static zend_object_handlers php_mix_chunk_handlers;

extern zend_class_entry *mix_chunk_ce;
extern zend_class_entry *get_php_sdl_rwops_ce(void);
extern SDL_RWops *zval_to_sdl_rwops(zval *z_val);
#define php_sdl_rwops_from_zval_p zval_to_sdl_rwops

PHP_FUNCTION(Mix_Init)
{
	zend_long flags;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_Init(flags);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_Quit)
{
	ZEND_PARSE_PARAMETERS_NONE();

	Mix_Quit();
}

PHP_FUNCTION(Mix_OpenAudio)
{
	zend_long frequency;
	zend_long format;
	zend_long channels;
	zend_long chunksize;

	ZEND_PARSE_PARAMETERS_START(4, 4);
		Z_PARAM_LONG(frequency)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(channels)
		Z_PARAM_LONG(chunksize)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_OpenAudio(frequency, format, channels, chunksize);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_OpenAudioDevice)
{
	zend_long frequency;
	zend_long format;
	zend_long channels;
	zend_long chunksize;

	char *device = NULL;
	size_t device_len = 0;

	zend_long allowed_changes;

	ZEND_PARSE_PARAMETERS_START(6, 6);
		Z_PARAM_LONG(frequency)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(channels)
		Z_PARAM_LONG(chunksize)
		Z_PARAM_STRING(device, device_len)
		Z_PARAM_LONG(allowed_changes)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_OpenAudioDevice(frequency, format, channels, chunksize, (const char*)device, allowed_changes);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_AllocateChannels)
{
	zend_long numchans;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(numchans)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_AllocateChannels(numchans);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_QuerySpec)
{
	zval *z_frequency = NULL;
	int frequency;
	zval *z_format = NULL;
	Uint16 format;
	zval *z_channels = NULL;
	int channels;

	ZEND_PARSE_PARAMETERS_START(3, 3);
		Z_PARAM_ZVAL(z_frequency)
		Z_PARAM_ZVAL(z_format)
		Z_PARAM_ZVAL(z_channels)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_QuerySpec(&frequency, &format, &channels);
	ZEND_TRY_ASSIGN_REF_LONG(z_frequency, frequency);
	ZEND_TRY_ASSIGN_REF_LONG(z_format, format);
	ZEND_TRY_ASSIGN_REF_LONG(z_channels, channels);
	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_LoadWAV_RW)
{
	zval *SRC;
	SDL_RWops *src;

	zend_long freesrc;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_OBJECT_OF_CLASS(SRC, get_php_sdl_rwops_ce())
		Z_PARAM_LONG(freesrc)
	ZEND_PARSE_PARAMETERS_END();
	src = php_sdl_rwops_from_zval_p(SRC);

	Mix_Chunk * result = Mix_LoadWAV_RW(src, freesrc);

	if (result == NULL) {
		RETURN_NULL();
	}

	mix_chunk_to_zval(result, return_value);
}

PHP_FUNCTION(Mix_LoadWAV)
{
	char *file = NULL;
	size_t file_len = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_STRING(file, file_len)
	ZEND_PARSE_PARAMETERS_END();

	Mix_Chunk * result = Mix_LoadWAV((const char*)file);

	if (result == NULL) {
		RETURN_NULL();
	}

	mix_chunk_to_zval(result, return_value);
}

PHP_FUNCTION(Mix_FreeChunk)
{
	zval *CHUNK;
	Mix_Chunk *chunk;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_OBJECT_OF_CLASS(CHUNK, mix_chunk_ce)
	ZEND_PARSE_PARAMETERS_END();
	chunk = php_mix_chunk_from_zval_p(CHUNK);
	Mix_FreeChunk(chunk);
}

PHP_FUNCTION(Mix_GetNumChunkDecoders)
{
	ZEND_PARSE_PARAMETERS_NONE();

	int result = Mix_GetNumChunkDecoders();

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GetChunkDecoder)
{
	zend_long index;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();

	const char * result = Mix_GetChunkDecoder(index);

	RETURN_STRING(result);
}

PHP_FUNCTION(Mix_HasChunkDecoder)
{
	char *name = NULL;
	size_t name_len = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_STRING(name, name_len)
	ZEND_PARSE_PARAMETERS_END();

	SDL_bool result = Mix_HasChunkDecoder((const char*)name);

	RETURN_BOOL(result == SDL_TRUE);
}

PHP_FUNCTION(Mix_ReserveChannels)
{
	zend_long num;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(num)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_ReserveChannels(num);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GroupChannel)
{
	zend_long which;
	zend_long tag;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_LONG(which)
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_GroupChannel(which, tag);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GroupChannels)
{
	zend_long from;
	zend_long to;
	zend_long tag;

	ZEND_PARSE_PARAMETERS_START(3, 3);
		Z_PARAM_LONG(from)
		Z_PARAM_LONG(to)
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_GroupChannels(from, to, tag);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GroupAvailable)
{
	zend_long tag;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_GroupAvailable(tag);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GroupCount)
{
	zend_long tag;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_GroupCount(tag);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GroupOldest)
{
	zend_long tag;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_GroupOldest(tag);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GroupNewer)
{
	zend_long tag;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_GroupNewer(tag);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_PlayChannel)
{
	zend_long channel;
	zval *CHUNK;
	Mix_Chunk *chunk;
	zend_long loops;

	ZEND_PARSE_PARAMETERS_START(3, 3);
		Z_PARAM_LONG(channel)
		Z_PARAM_OBJECT_OF_CLASS(CHUNK, mix_chunk_ce)
		Z_PARAM_LONG(loops)
	ZEND_PARSE_PARAMETERS_END();

	chunk = php_mix_chunk_from_zval_p(CHUNK);

	int result = Mix_PlayChannel(channel, chunk, loops);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_PlayChannelTimed)
{
	zend_long channel;
	zval *CHUNK;
	Mix_Chunk *chunk;
	zend_long loops;
	zend_long ticks;

	ZEND_PARSE_PARAMETERS_START(4, 4);
		Z_PARAM_LONG(channel)
		Z_PARAM_OBJECT_OF_CLASS(CHUNK, mix_chunk_ce)
		Z_PARAM_LONG(loops)
		Z_PARAM_LONG(ticks)
	ZEND_PARSE_PARAMETERS_END();

	chunk = php_mix_chunk_from_zval_p(CHUNK);

	int result = Mix_PlayChannelTimed(channel, chunk, loops, ticks);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_FadeInChannelTimed)
{
	zend_long channel;
	zval *CHUNK;
	Mix_Chunk *chunk;
	zend_long loops;
	zend_long ms;
	zend_long ticks;

	ZEND_PARSE_PARAMETERS_START(5, 5);
		Z_PARAM_LONG(channel)
		Z_PARAM_OBJECT_OF_CLASS(CHUNK, mix_chunk_ce)
		Z_PARAM_LONG(loops)
		Z_PARAM_LONG(ms)
		Z_PARAM_LONG(ticks)
	ZEND_PARSE_PARAMETERS_END();

	chunk = php_mix_chunk_from_zval_p(CHUNK);

	int result = Mix_FadeInChannelTimed(channel, chunk, loops, ms, ticks);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_Volume)
{
	zend_long channel;
	zend_long volume;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_LONG(channel)
		Z_PARAM_LONG(volume)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_Volume(channel, volume);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_VolumeChunk)
{
	zval *CHUNK;
	Mix_Chunk *chunk;
	zend_long volume;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_OBJECT_OF_CLASS(CHUNK, mix_chunk_ce)
		Z_PARAM_LONG(volume)
	ZEND_PARSE_PARAMETERS_END();
	chunk = php_mix_chunk_from_zval_p(CHUNK);

	int result = Mix_VolumeChunk(chunk, volume);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_HaltChannel)
{
	zend_long channel;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(channel)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_HaltChannel(channel);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_HaltGroup)
{
	zend_long tag;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_HaltGroup(tag);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_ExpireChannel)
{
	zend_long channel;
	zend_long ticks;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_LONG(channel)
		Z_PARAM_LONG(ticks)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_ExpireChannel(channel, ticks);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_FadeOutChannel)
{
	zend_long which;
	zend_long ms;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_LONG(which)
		Z_PARAM_LONG(ms)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_FadeOutChannel(which, ms);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_FadeOutGroup)
{
	zend_long tag;
	zend_long ms;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_LONG(tag)
		Z_PARAM_LONG(ms)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_FadeOutGroup(tag, ms);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_Pause)
{
	zend_long channel;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(channel)
	ZEND_PARSE_PARAMETERS_END();

	Mix_Pause(channel);
}

PHP_FUNCTION(Mix_Resume)
{
	zend_long channel;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(channel)
	ZEND_PARSE_PARAMETERS_END();

	Mix_Resume(channel);
}

PHP_FUNCTION(Mix_Paused)
{
	zend_long channel;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(channel)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_Paused(channel);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_Playing)
{
	zend_long channel;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(channel)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_Playing(channel);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_GetChunk)
{
	zend_long channel;

	ZEND_PARSE_PARAMETERS_START(1, 1);
		Z_PARAM_LONG(channel)
	ZEND_PARSE_PARAMETERS_END();

	Mix_Chunk * result = Mix_GetChunk(channel);

	if (result == NULL) {
		RETURN_NULL();
	}

	mix_chunk_to_zval(result, return_value);
}

PHP_FUNCTION(Mix_CloseAudio)
{
	ZEND_PARSE_PARAMETERS_NONE();

	Mix_CloseAudio();
}

PHP_FUNCTION(Mix_GetError) {
	const char *error;

	if (zend_parse_parameters_none() == FAILURE) {
		RETURN_THROWS();
	}

	error = Mix_GetError();
	if (error) {
		RETURN_STRING(error);
	}
}