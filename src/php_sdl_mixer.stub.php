<?php

/** @generate-function-entries */

// General

//function Mix_Linked_Version(): SDL_version {}
//function Mix_Init(): void {}
//function Mix_Quit(): void {}

function Mix_OpenAudio(int $frequency, int $format, int $nchannels, int $chunksize): int {}

//function Mix_CloseAudio(): void {}
//function Mix_SetError(): void {}

function Mix_GetError(): string {};

function Mix_QuerySpec(int &$frequency, int &$format, int &$channels): int {}

// Samples

function Mix_LoadWAV(string $path): ?Mix_Chunk {}

function Mix_VolumeChunk(Mix_Chunk $chunk, int $volume): int {}

// Channels

function Mix_Volume(int $channel, int $volume): int {}

function Mix_PlayChannel(int $channel, Mix_Chunk $chunk, int $loops): int {}

// Music

function Mix_LoadMUS(string $path): ?Mix_Music {}

function Mix_FreeMusic(Mix_Music $music): void {}

function Mix_PlayMusic(Mix_Music $music, int $loops): int {}

function Mix_VolumeMusic(int $volume): int {}
