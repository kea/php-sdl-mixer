/*
   +----------------------------------------------------------------------+
   | PHP Version 8                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2021 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Manuel Baldassarri <manuel@baldassarri.me>                   |
   +----------------------------------------------------------------------+
*/


#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "chunk.h"

static zend_class_entry *php_mix_chunk_ce;
static zend_object_handlers php_mix_chunk_handlers;

struct php_mix_chunk
{
	Mix_Chunk *intern;
	zend_object zo;
};
typedef struct php_mix_chunk php_mix_chunk_t;

static zend_object *php_mix_chunk_create_object(zend_class_entry *ce)
{
	php_mix_chunk_t *php_mix_chunk;

	php_mix_chunk = (php_mix_chunk_t *)ecalloc(1, sizeof(php_mix_chunk_t) + zend_object_properties_size(ce));

	zend_object_std_init(&php_mix_chunk->zo, ce);
	object_properties_init(&php_mix_chunk->zo, ce);

	php_mix_chunk->intern = NULL;
	php_mix_chunk->zo.handlers = (zend_object_handlers *)&php_mix_chunk_handlers;

	return &php_mix_chunk->zo;
}

static void php_mix_chunk_free_object(zend_object *zo)
{
	// Mix_FreeChunk ???
	php_mix_chunk_t *php_mix_chunk = (php_mix_chunk_t *)((char *)zo - zo->handlers->offset);
	zend_object_std_dtor(&php_mix_chunk->zo);
}

static inline Mix_Chunk *mix_chunk_from_zval(zval *zmix_chunk)
{
	zend_object *zo = Z_OBJ_P(zmix_chunk);
	php_mix_chunk_t *php_mix_chunk = (php_mix_chunk_t *)((char *)zo - zo->handlers->offset);
	return php_mix_chunk->intern;
}

static inline void mix_chunk_to_zval(Mix_Chunk *mix_chunk, zval *zvalue)
{
	object_init_ex(zvalue, php_mix_chunk_ce);
	zend_object *zo = Z_OBJ_P(zvalue);
	php_mix_chunk_t *php_mix_chunk = (php_mix_chunk_t *)((char *)zo - zo->handlers->offset);
	php_mix_chunk->intern = mix_chunk;
}

PHP_FUNCTION(Mix_OpenAudio)
{
	zend_long frequency;
	zend_long format;
	zend_long nchannels;
	zend_long chunksize;

	ZEND_PARSE_PARAMETERS_START(4, 4)
	Z_PARAM_LONG(frequency)
	Z_PARAM_LONG(format)
	Z_PARAM_LONG(nchannels)
	Z_PARAM_LONG(chunksize)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(Mix_OpenAudio((int)frequency, (Uint16)format, (int)nchannels, (int)chunksize));
}

PHP_FUNCTION(Mix_LoadWAV)
{
	zend_string *path;
	Mix_Chunk *mix_chunk = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();

	mix_chunk = Mix_LoadWAV_RW(SDL_RWFromFile(ZSTR_VAL(path), "rb"), 1);

	if (!mix_chunk) {
		RETURN_NULL();
	}

	mix_chunk_to_zval(mix_chunk, return_value);
}

PHP_FUNCTION(Mix_PlayChannel)
{
	zval *zchunk;
	zend_string *path;
	Mix_Chunk *mix_chunk = NULL;
	zend_long channel;
	zend_long loops;
	int nchannels;

	ZEND_PARSE_PARAMETERS_START(3, 3)
	Z_PARAM_LONG(channel)
	Z_PARAM_OBJECT_OF_CLASS(zchunk, php_mix_chunk_ce)
	Z_PARAM_LONG(loops)
	ZEND_PARSE_PARAMETERS_END();

	mix_chunk = mix_chunk_from_zval(zchunk);
	nchannels = Mix_PlayChannelTimed((int)channel,mix_chunk,(int)loops,-1);

	RETURN_LONG(nchannels);
}

PHP_FUNCTION(Mix_Volume)
{
	zend_long channel;
	zend_long volume;
	int ret_volume;

	ZEND_PARSE_PARAMETERS_START(3, 3)
	Z_PARAM_LONG(channel)
	Z_PARAM_LONG(volume)
	ZEND_PARSE_PARAMETERS_END();

	ret_volume = Mix_Volume((int)channel, (int)volume);

	RETURN_LONG(ret_volume);
}

PHP_FUNCTION(Mix_VolumeChunk)
{
	zval *zchunk;
	zend_string *path;
	Mix_Chunk *mix_chunk = NULL;
	zend_long volume;
	int ret_volume;

	ZEND_PARSE_PARAMETERS_START(2, 2)
	Z_PARAM_OBJECT_OF_CLASS(zchunk, php_mix_chunk_ce)
	Z_PARAM_LONG(volume)
	ZEND_PARSE_PARAMETERS_END();

	mix_chunk = mix_chunk_from_zval(zchunk);
	ret_volume = Mix_VolumeChunk(mix_chunk,(int)volume);

	RETURN_LONG(ret_volume);
}

PHP_MINIT_FUNCTION(mix_chunk)
{
	REGISTER_LONG_CONSTANT("MIX_DEFAULT_CHANNELS", MIX_DEFAULT_CHANNELS, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("MIX_DEFAULT_FREQUENCY", MIX_DEFAULT_FREQUENCY, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("MIX_DEFAULT_FORMAT", MIX_DEFAULT_FORMAT, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("MIX_MAX_VOLUME", MIX_MAX_VOLUME, CONST_CS | CONST_PERSISTENT);

	zend_class_entry mix_chunk_ce;
	INIT_CLASS_ENTRY(mix_chunk_ce, "Mix_Chunk", NULL);

	php_mix_chunk_ce = zend_register_internal_class(&mix_chunk_ce);
	php_mix_chunk_ce->create_object = php_mix_chunk_create_object;

	memcpy(&php_mix_chunk_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	php_mix_chunk_handlers.free_obj = php_mix_chunk_free_object;
	php_mix_chunk_handlers.offset = XtOffsetOf(php_mix_chunk_t, zo);

	return SUCCESS;
}
