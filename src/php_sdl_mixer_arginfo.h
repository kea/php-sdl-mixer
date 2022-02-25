/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 1a36e3ed90a9a7c0ff05a89516ad4bcec0ef0d44 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_Init, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_Quit, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_OpenAudio, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, frequency, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channels, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, chunksize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_OpenAudioDevice, 0, 6, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, frequency, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channels, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, chunksize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, device, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, allowed_changes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_AllocateChannels, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, numchans, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_QuerySpec, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, frequency, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, channels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Mix_LoadWAV_RW, 0, 2, Mix_Chunk, 0)
	ZEND_ARG_OBJ_INFO(0, src, SDL_RWops, 0)
	ZEND_ARG_TYPE_INFO(0, freesrc, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Mix_LoadWAV, 0, 1, Mix_Chunk, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_FreeChunk, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, chunk, Mix_Chunk, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_GetNumChunkDecoders, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_GetChunkDecoder, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_HasChunkDecoder, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_ReserveChannels, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_GroupChannel, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, which, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_GroupChannels, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, from, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, to, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_GroupAvailable, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_GroupCount arginfo_Mix_GroupAvailable

#define arginfo_Mix_GroupOldest arginfo_Mix_GroupAvailable

#define arginfo_Mix_GroupNewer arginfo_Mix_GroupAvailable

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_PlayChannel, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, chunk, Mix_Chunk, 0)
	ZEND_ARG_TYPE_INFO(0, loops, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_PlayChannelTimed, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, chunk, Mix_Chunk, 0)
	ZEND_ARG_TYPE_INFO(0, loops, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ticks, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_FadeInChannelTimed, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, chunk, Mix_Chunk, 0)
	ZEND_ARG_TYPE_INFO(0, loops, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ms, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ticks, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_Volume, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, volume, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_VolumeChunk, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, chunk, Mix_Chunk, 0)
	ZEND_ARG_TYPE_INFO(0, volume, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_HaltChannel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_HaltGroup arginfo_Mix_GroupAvailable

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_ExpireChannel, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ticks, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_FadeOutChannel, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, which, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ms, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_FadeOutGroup, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ms, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_Pause, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_Resume arginfo_Mix_Pause

#define arginfo_Mix_Paused arginfo_Mix_HaltChannel

#define arginfo_Mix_Playing arginfo_Mix_HaltChannel

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Mix_GetChunk, 0, 1, Mix_Chunk, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_CloseAudio arginfo_Mix_Quit

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Mix_LoadMUS, 0, 1, Mix_Music, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Mix_LoadMUS_RW, 0, 2, Mix_Music, 0)
	ZEND_ARG_OBJ_INFO(0, src, SDL_RWops, 0)
	ZEND_ARG_TYPE_INFO(0, freesrc, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_FreeMusic, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, music, Mix_Music, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_GetNumMusicDecoders arginfo_Mix_GetNumChunkDecoders

#define arginfo_Mix_GetMusicDecoder arginfo_Mix_GetChunkDecoder

#define arginfo_Mix_HasMusicDecoder arginfo_Mix_HasChunkDecoder

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_PlayMusic, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, music, Mix_Music, 0)
	ZEND_ARG_TYPE_INFO(0, loops, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_FadeInMusic, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, music, Mix_Music, 0)
	ZEND_ARG_TYPE_INFO(0, loops, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ms, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_FadeInMusicPos, 0, 4, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, music, Mix_Music, 0)
	ZEND_ARG_TYPE_INFO(0, loops, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ms, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_VolumeMusic, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, volume, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_HaltMusic arginfo_Mix_GetNumChunkDecoders

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_FadeOutMusic, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ms, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_PauseMusic arginfo_Mix_Quit

#define arginfo_Mix_ResumeMusic arginfo_Mix_Quit

#define arginfo_Mix_RewindMusic arginfo_Mix_Quit

#define arginfo_Mix_PausedMusic arginfo_Mix_GetNumChunkDecoders

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_SetMusicPosition, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_PlayingMusic arginfo_Mix_GetNumChunkDecoders

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_SetMusicCMD, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, command, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_SetSynchroValue, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_GetSynchroValue arginfo_Mix_GetNumChunkDecoders

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_SetSoundFonts, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paths, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_GetSoundFonts, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_SetPosition, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, angle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, distance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_SetDistance, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, distance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_SetReverseStereo, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flip, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_Mix_SetError arginfo_Mix_GetSoundFonts

#define arginfo_Mix_GetError arginfo_Mix_GetSoundFonts

#define arginfo_Mix_ClearError arginfo_Mix_GetSoundFonts


ZEND_FUNCTION(Mix_Init);
ZEND_FUNCTION(Mix_Quit);
ZEND_FUNCTION(Mix_OpenAudio);
ZEND_FUNCTION(Mix_OpenAudioDevice);
ZEND_FUNCTION(Mix_AllocateChannels);
ZEND_FUNCTION(Mix_QuerySpec);
ZEND_FUNCTION(Mix_LoadWAV_RW);
ZEND_FUNCTION(Mix_LoadWAV);
ZEND_FUNCTION(Mix_FreeChunk);
ZEND_FUNCTION(Mix_GetNumChunkDecoders);
ZEND_FUNCTION(Mix_GetChunkDecoder);
ZEND_FUNCTION(Mix_HasChunkDecoder);
ZEND_FUNCTION(Mix_ReserveChannels);
ZEND_FUNCTION(Mix_GroupChannel);
ZEND_FUNCTION(Mix_GroupChannels);
ZEND_FUNCTION(Mix_GroupAvailable);
ZEND_FUNCTION(Mix_GroupCount);
ZEND_FUNCTION(Mix_GroupOldest);
ZEND_FUNCTION(Mix_GroupNewer);
ZEND_FUNCTION(Mix_PlayChannel);
ZEND_FUNCTION(Mix_PlayChannelTimed);
ZEND_FUNCTION(Mix_FadeInChannelTimed);
ZEND_FUNCTION(Mix_Volume);
ZEND_FUNCTION(Mix_VolumeChunk);
ZEND_FUNCTION(Mix_HaltChannel);
ZEND_FUNCTION(Mix_HaltGroup);
ZEND_FUNCTION(Mix_ExpireChannel);
ZEND_FUNCTION(Mix_FadeOutChannel);
ZEND_FUNCTION(Mix_FadeOutGroup);
ZEND_FUNCTION(Mix_Pause);
ZEND_FUNCTION(Mix_Resume);
ZEND_FUNCTION(Mix_Paused);
ZEND_FUNCTION(Mix_Playing);
ZEND_FUNCTION(Mix_GetChunk);
ZEND_FUNCTION(Mix_CloseAudio);
ZEND_FUNCTION(Mix_LoadMUS);
ZEND_FUNCTION(Mix_LoadMUS_RW);
ZEND_FUNCTION(Mix_FreeMusic);
ZEND_FUNCTION(Mix_GetNumMusicDecoders);
ZEND_FUNCTION(Mix_GetMusicDecoder);
ZEND_FUNCTION(Mix_HasMusicDecoder);
ZEND_FUNCTION(Mix_PlayMusic);
ZEND_FUNCTION(Mix_FadeInMusic);
ZEND_FUNCTION(Mix_FadeInMusicPos);
ZEND_FUNCTION(Mix_VolumeMusic);
ZEND_FUNCTION(Mix_HaltMusic);
ZEND_FUNCTION(Mix_FadeOutMusic);
ZEND_FUNCTION(Mix_PauseMusic);
ZEND_FUNCTION(Mix_ResumeMusic);
ZEND_FUNCTION(Mix_RewindMusic);
ZEND_FUNCTION(Mix_PausedMusic);
ZEND_FUNCTION(Mix_SetMusicPosition);
ZEND_FUNCTION(Mix_PlayingMusic);
ZEND_FUNCTION(Mix_SetMusicCMD);
ZEND_FUNCTION(Mix_SetSynchroValue);
ZEND_FUNCTION(Mix_GetSynchroValue);
ZEND_FUNCTION(Mix_SetSoundFonts);
ZEND_FUNCTION(Mix_GetSoundFonts);
ZEND_FUNCTION(Mix_SetPosition);
ZEND_FUNCTION(Mix_SetDistance);
ZEND_FUNCTION(Mix_SetReverseStereo);
ZEND_FUNCTION(SDL_SetError);
ZEND_FUNCTION(SDL_GetError);
ZEND_FUNCTION(SDL_ClearError);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(Mix_Init, arginfo_Mix_Init)
	ZEND_FE(Mix_Quit, arginfo_Mix_Quit)
	ZEND_FE(Mix_OpenAudio, arginfo_Mix_OpenAudio)
	ZEND_FE(Mix_OpenAudioDevice, arginfo_Mix_OpenAudioDevice)
	ZEND_FE(Mix_AllocateChannels, arginfo_Mix_AllocateChannels)
	ZEND_FE(Mix_QuerySpec, arginfo_Mix_QuerySpec)
	ZEND_FE(Mix_LoadWAV_RW, arginfo_Mix_LoadWAV_RW)
	ZEND_FE(Mix_LoadWAV, arginfo_Mix_LoadWAV)
	ZEND_FE(Mix_FreeChunk, arginfo_Mix_FreeChunk)
	ZEND_FE(Mix_GetNumChunkDecoders, arginfo_Mix_GetNumChunkDecoders)
	ZEND_FE(Mix_GetChunkDecoder, arginfo_Mix_GetChunkDecoder)
	ZEND_FE(Mix_HasChunkDecoder, arginfo_Mix_HasChunkDecoder)
	ZEND_FE(Mix_ReserveChannels, arginfo_Mix_ReserveChannels)
	ZEND_FE(Mix_GroupChannel, arginfo_Mix_GroupChannel)
	ZEND_FE(Mix_GroupChannels, arginfo_Mix_GroupChannels)
	ZEND_FE(Mix_GroupAvailable, arginfo_Mix_GroupAvailable)
	ZEND_FE(Mix_GroupCount, arginfo_Mix_GroupCount)
	ZEND_FE(Mix_GroupOldest, arginfo_Mix_GroupOldest)
	ZEND_FE(Mix_GroupNewer, arginfo_Mix_GroupNewer)
	ZEND_FE(Mix_PlayChannel, arginfo_Mix_PlayChannel)
	ZEND_FE(Mix_PlayChannelTimed, arginfo_Mix_PlayChannelTimed)
	ZEND_FE(Mix_FadeInChannelTimed, arginfo_Mix_FadeInChannelTimed)
	ZEND_FE(Mix_Volume, arginfo_Mix_Volume)
	ZEND_FE(Mix_VolumeChunk, arginfo_Mix_VolumeChunk)
	ZEND_FE(Mix_HaltChannel, arginfo_Mix_HaltChannel)
	ZEND_FE(Mix_HaltGroup, arginfo_Mix_HaltGroup)
	ZEND_FE(Mix_ExpireChannel, arginfo_Mix_ExpireChannel)
	ZEND_FE(Mix_FadeOutChannel, arginfo_Mix_FadeOutChannel)
	ZEND_FE(Mix_FadeOutGroup, arginfo_Mix_FadeOutGroup)
	ZEND_FE(Mix_Pause, arginfo_Mix_Pause)
	ZEND_FE(Mix_Resume, arginfo_Mix_Resume)
	ZEND_FE(Mix_Paused, arginfo_Mix_Paused)
	ZEND_FE(Mix_Playing, arginfo_Mix_Playing)
	ZEND_FE(Mix_GetChunk, arginfo_Mix_GetChunk)
	ZEND_FE(Mix_CloseAudio, arginfo_Mix_CloseAudio)
	ZEND_FE(Mix_LoadMUS, arginfo_Mix_LoadMUS)
	ZEND_FE(Mix_LoadMUS_RW, arginfo_Mix_LoadMUS_RW)
	ZEND_FE(Mix_FreeMusic, arginfo_Mix_FreeMusic)
	ZEND_FE(Mix_GetNumMusicDecoders, arginfo_Mix_GetNumMusicDecoders)
	ZEND_FE(Mix_GetMusicDecoder, arginfo_Mix_GetMusicDecoder)
	ZEND_FE(Mix_HasMusicDecoder, arginfo_Mix_HasMusicDecoder)
	ZEND_FE(Mix_PlayMusic, arginfo_Mix_PlayMusic)
	ZEND_FE(Mix_FadeInMusic, arginfo_Mix_FadeInMusic)
	ZEND_FE(Mix_FadeInMusicPos, arginfo_Mix_FadeInMusicPos)
	ZEND_FE(Mix_VolumeMusic, arginfo_Mix_VolumeMusic)
	ZEND_FE(Mix_HaltMusic, arginfo_Mix_HaltMusic)
	ZEND_FE(Mix_FadeOutMusic, arginfo_Mix_FadeOutMusic)
	ZEND_FE(Mix_PauseMusic, arginfo_Mix_PauseMusic)
	ZEND_FE(Mix_ResumeMusic, arginfo_Mix_ResumeMusic)
	ZEND_FE(Mix_RewindMusic, arginfo_Mix_RewindMusic)
	ZEND_FE(Mix_PausedMusic, arginfo_Mix_PausedMusic)
	ZEND_FE(Mix_SetMusicPosition, arginfo_Mix_SetMusicPosition)
	ZEND_FE(Mix_PlayingMusic, arginfo_Mix_PlayingMusic)
	ZEND_FE(Mix_SetMusicCMD, arginfo_Mix_SetMusicCMD)
	ZEND_FE(Mix_SetSynchroValue, arginfo_Mix_SetSynchroValue)
	ZEND_FE(Mix_GetSynchroValue, arginfo_Mix_GetSynchroValue)
	ZEND_FE(Mix_SetSoundFonts, arginfo_Mix_SetSoundFonts)
	ZEND_FE(Mix_GetSoundFonts, arginfo_Mix_GetSoundFonts)
	ZEND_FE(Mix_SetPosition, arginfo_Mix_SetPosition)
	ZEND_FE(Mix_SetDistance, arginfo_Mix_SetDistance)
	ZEND_FE(Mix_SetReverseStereo, arginfo_Mix_SetReverseStereo)
	ZEND_FALIAS(Mix_SetError, SDL_SetError, arginfo_Mix_SetError)
	ZEND_FALIAS(Mix_GetError, SDL_GetError, arginfo_Mix_GetError)
	ZEND_FALIAS(Mix_ClearError, SDL_ClearError, arginfo_Mix_ClearError)
	ZEND_FE_END
};


static const zend_function_entry class_Mix_Chunk_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_Mix_Music_methods[] = {
	ZEND_FE_END
};

static zend_class_entry *register_class_Mix_Chunk(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "Mix_Chunk", class_Mix_Chunk_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}

static zend_class_entry *register_class_Mix_Music(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "Mix_Music", class_Mix_Music_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}
