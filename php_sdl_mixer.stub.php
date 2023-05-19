<?php

/**
 * @generate-function-entries
 * @generate-class-entries
 */

function Mix_Init(int $flags): int {}
function Mix_Quit(): void {}
function Mix_OpenAudio(int $frequency, int $format, int $channels, int $chunksize): int {}
function Mix_OpenAudioDevice(int $frequency, int $format, int $channels, int $chunksize, string $device, int $allowed_changes): int {}
function Mix_AllocateChannels(int $numchans): int {}
function Mix_QuerySpec(int &$frequency, int &$format, int &$channels): int {}
function Mix_LoadWAV_RW(SDL_RWops $src, int $freesrc): Mix_Chunk {}
function Mix_LoadWAV(string $file): Mix_Chunk {}
function Mix_FreeChunk(Mix_Chunk $chunk): void {}
function Mix_GetNumChunkDecoders(): int {}
function Mix_GetChunkDecoder(int $index): string {}
function Mix_HasChunkDecoder(string $name): bool {}
function Mix_ReserveChannels(int $num): int {}
function Mix_GroupChannel(int $which, int $tag): int {}
function Mix_GroupChannels(int $from, int $to, int $tag): int {}
function Mix_GroupAvailable(int $tag): int {}
function Mix_GroupCount(int $tag): int {}
function Mix_GroupOldest(int $tag): int {}
function Mix_GroupNewer(int $tag): int {}
function Mix_PlayChannel(int $channel, Mix_Chunk $chunk, int $loops): int {}
function Mix_PlayChannelTimed(int $channel, Mix_Chunk $chunk, int $loops, int $ticks): int {}
function Mix_FadeInChannelTimed(int $channel, Mix_Chunk $chunk, int $loops, int $ms, int $ticks): int {}
function Mix_Volume(int $channel, int $volume): int {}
function Mix_VolumeChunk(Mix_Chunk $chunk, int $volume): int {}
function Mix_HaltChannel(int $channel): int {}
function Mix_HaltGroup(int $tag): int {}
function Mix_ExpireChannel(int $channel, int $ticks): int {}
function Mix_FadeOutChannel(int $which, int $ms): int {}
function Mix_FadeOutGroup(int $tag, int $ms): int {}
function Mix_Pause(int $channel): void {}
function Mix_Resume(int $channel): void {}
function Mix_Paused(int $channel): int {}
function Mix_Playing(int $channel): int {}
function Mix_GetChunk(int $channel): Mix_Chunk {}
function Mix_CloseAudio(): void {}
function Mix_LoadMUS(string $file): Mix_Music {}
function Mix_LoadMUS_RW(SDL_RWops $src, int $freesrc): Mix_Music {}
function Mix_FreeMusic(Mix_Music $music): void {}
function Mix_GetNumMusicDecoders(): int {}
function Mix_GetMusicDecoder(int $index): string {}
#ifdef HAVE_MIX_HASMUSICDECODER
function Mix_HasMusicDecoder(string $name): bool {}
#endif
function Mix_PlayMusic(Mix_Music $music, int $loops): int {}
function Mix_FadeInMusic(Mix_Music $music, int $loops, int $ms): int {}
function Mix_FadeInMusicPos(Mix_Music $music, int $loops, int $ms, float $position): int {}
function Mix_VolumeMusic(int $volume): int {}
function Mix_HaltMusic(): int {}
function Mix_FadeOutMusic(int $ms): int {}
function Mix_PauseMusic(): void {}
function Mix_ResumeMusic(): void {}
function Mix_RewindMusic(): void {}
function Mix_PausedMusic(): int {}
function Mix_SetMusicPosition(float $position): int {}
function Mix_PlayingMusic(): int {}
function Mix_SetMusicCMD(string $command): int {}
function Mix_SetSynchroValue(int $value): int {}
function Mix_GetSynchroValue(): int {}
function Mix_SetSoundFonts(string $paths): int {}
function Mix_GetSoundFonts(): string {}
function Mix_SetPosition(int $channel, int $angle, int $distance): int {}
function Mix_SetDistance(int $channel, int $distance): int {}
function Mix_SetReverseStereo(int $channel, int $flip): int {}

/** @alias SDL_SetError */
function Mix_SetError(): string {}
/** @alias SDL_GetError */
function Mix_GetError(): string {}
/** @alias SDL_ClearError */
function Mix_ClearError(): string {}

