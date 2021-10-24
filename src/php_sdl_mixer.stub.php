<?php

/** @generate-function-entries */

function Mix_LoadMUS(string $path): ?Mix_Music {}

function Mix_PlayMusic(Mix_Music $music, int $loops): int {}

function Mix_VolumeMusic(int $volume): int {}

function Mix_OpenAudio(int $frequency, int $format, int $nchannels, int $chunksize): int {}

function Mix_LoadWAV(string $path): ?Mix_Chunk {}

function Mix_PlayChannel(int $channel, Mix_Chunk $chunk, int $loops): int {}

function Mix_GetError(): string {};