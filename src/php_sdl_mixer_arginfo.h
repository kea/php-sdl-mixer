/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: b2d5b4e3567654bb633bfc8527f7e2946272b23c */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Mix_LoadMUS, 0, 1, Mix_Music, 1)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_PlayMusic, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, music, Mix_Music, 0)
	ZEND_ARG_TYPE_INFO(0, loops, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_VolumeMusic, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, volume, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_OpenAudio, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, frequency, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nchannels, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, chunksize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_Mix_LoadWAV, 0, 1, Mix_Chunk, 1)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_PlayChannel, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, channel, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, chunk, Mix_Chunk, 0)
	ZEND_ARG_TYPE_INFO(0, loops, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Mix_GetError, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_FUNCTION(Mix_LoadMUS);
ZEND_FUNCTION(Mix_PlayMusic);
ZEND_FUNCTION(Mix_VolumeMusic);
ZEND_FUNCTION(Mix_OpenAudio);
ZEND_FUNCTION(Mix_LoadWAV);
ZEND_FUNCTION(Mix_PlayChannel);
ZEND_FUNCTION(Mix_GetError);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(Mix_LoadMUS, arginfo_Mix_LoadMUS)
	ZEND_FE(Mix_PlayMusic, arginfo_Mix_PlayMusic)
	ZEND_FE(Mix_VolumeMusic, arginfo_Mix_VolumeMusic)
	ZEND_FE(Mix_OpenAudio, arginfo_Mix_OpenAudio)
	ZEND_FE(Mix_LoadWAV, arginfo_Mix_LoadWAV)
	ZEND_FE(Mix_PlayChannel, arginfo_Mix_PlayChannel)
	ZEND_FE(Mix_GetError, arginfo_Mix_GetError)
	ZEND_FE_END
};
