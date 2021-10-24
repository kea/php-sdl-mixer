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

#include "music.h"

static zend_class_entry *php_mix_music_ce;
static zend_object_handlers php_mix_music_handlers;

struct php_mix_music
{
	Mix_Music *intern;
	zend_object zo;
};
typedef struct php_mix_music php_mix_music_t;

static zend_object *php_mix_music_create_object(zend_class_entry *ce)
{
	php_mix_music_t *php_mix_music;

	php_mix_music = (php_mix_music_t *)ecalloc(1, sizeof(php_mix_music_t) + zend_object_properties_size(ce));

	zend_object_std_init(&php_mix_music->zo, ce);
	object_properties_init(&php_mix_music->zo, ce);

	php_mix_music->intern = NULL;
	php_mix_music->zo.handlers = (zend_object_handlers *)&php_mix_music_handlers;

	return &php_mix_music->zo;
}

static void php_mix_music_free_object(zend_object *zo)
{
	// Mix_FreeChunk ???
	php_mix_music_t *php_mix_music = (php_mix_music_t *)((char *)zo - zo->handlers->offset);
	zend_object_std_dtor(&php_mix_music->zo);
}

static inline Mix_Music *mix_music_from_zval(zval *zmix_music)
{
	zend_object *zo = Z_OBJ_P(zmix_music);
	php_mix_music_t *php_mix_music = (php_mix_music_t *)((char *)zo - zo->handlers->offset);
	return php_mix_music->intern;
}

static inline void mix_music_to_zval(Mix_Music *mix_music, zval *zvalue)
{
	object_init_ex(zvalue, php_mix_music_ce);
	zend_object *zo = Z_OBJ_P(zvalue);
	php_mix_music_t *php_mix_music = (php_mix_music_t *)((char *)zo - zo->handlers->offset);
	php_mix_music->intern = mix_music;
}

PHP_FUNCTION(Mix_LoadMUS)
{
	zend_string *path;
	Mix_Music *mix_music = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();

	mix_music = Mix_LoadMUS(ZSTR_VAL(path));

	if (!mix_music) {
		RETURN_NULL();
	}

	mix_music_to_zval(mix_music, return_value);
}

PHP_FUNCTION(Mix_PlayMusic)
{
	zval *music;
	zend_string *path;
	Mix_Music *mix_music = NULL;
	zend_long loops;
	int retval;

	ZEND_PARSE_PARAMETERS_START(2, 2)
	Z_PARAM_OBJECT_OF_CLASS(music, php_mix_music_ce)
	Z_PARAM_LONG(loops)
	ZEND_PARSE_PARAMETERS_END();

	mix_music = mix_music_from_zval(music);
	retval = Mix_PlayMusic(mix_music,(int)loops);

	RETURN_BOOL(retval == 0);
}

/*
    volume < 0 get volume
    volume > 0 set volume
*/
PHP_FUNCTION(Mix_VolumeMusic)
{
	zend_long volume;
	int new_volume;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_LONG(volume)
	ZEND_PARSE_PARAMETERS_END();

	new_volume = Mix_VolumeMusic((int)volume);

	RETURN_LONG(new_volume);
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

PHP_MINIT_FUNCTION(mix_music)
{
	zend_class_entry mix_music_ce;
	INIT_CLASS_ENTRY(mix_music_ce, "Mix_Music", NULL);

	php_mix_music_ce = zend_register_internal_class(&mix_music_ce);
	php_mix_music_ce->create_object = php_mix_music_create_object;

	memcpy(&php_mix_music_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
	php_mix_music_handlers.free_obj = php_mix_music_free_object;
	php_mix_music_handlers.offset = XtOffsetOf(php_mix_music_t, zo);

	return SUCCESS;
}
