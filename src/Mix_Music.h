
/** {{{ Mix_Music */
static zend_class_entry *mix_music_ce = NULL;
static zend_object_handlers php_mix_music_object_handlers;

typedef struct _php_mix_music_object {
	Mix_Music *mix_music;
	zend_object std;
} php_mix_music_object;

static php_mix_music_object *php_mix_music_object_from_zend_object(zend_object *zobj)
{
	return ((php_mix_music_object*)(zobj + 1)) - 1;
}

static zend_object *php_mix_music_object_to_zend_object(php_mix_music_object *obj)
{
	return ((zend_object*)(obj + 1)) - 1;
}

Mix_Music* php_mix_music_from_zval_p(zval* zp)
{
	return php_mix_music_object_from_zend_object(Z_OBJ_P(zp))->mix_music;
}


static inline void mix_music_to_zval(Mix_Music *mix_music, zval *zp)
{
	object_init_ex(zp, mix_music_ce);
	php_mix_music_object *php_mix_music = php_mix_music_object_from_zend_object(Z_OBJ_P(zp));
	php_mix_music->mix_music = mix_music;
}

static zend_object *php_mix_music_object_create(zend_class_entry *ce)
{
	php_mix_music_object *obj = zend_object_alloc(sizeof(php_mix_music_object), ce);
	zend_object *zobj = php_mix_music_object_to_zend_object(obj);

	obj->mix_music = NULL;
	zend_object_std_init(zobj, ce);
	object_properties_init(zobj, ce);
	zobj->handlers = &php_mix_music_object_handlers;

	return zobj;
}

static void php_mix_music_object_free(zend_object *zobj)
{
	php_mix_music_object *obj = php_mix_music_object_from_zend_object(zobj);

	if (obj->mix_music) {
		// @todo implement free es. TTF_CloseFont(obj->mix_music);
		obj->mix_music = NULL;
	}

	zend_object_std_dtor(zobj);
}

static zend_function *php_mix_music_object_get_constructor(zend_object *object)
{
	zend_throw_error(NULL, "You cannot initialize a Mix_Music object except through helper functions");
	return NULL;
}

static void php_mix_music_minit_helper(void)
{
	mix_music_ce = register_class_Mix_Music();
	mix_music_ce->create_object = php_mix_music_object_create;

	memcpy(&php_mix_music_object_handlers, &std_object_handlers, sizeof(zend_object_handlers));
	php_mix_music_object_handlers.clone_obj = NULL;
	php_mix_music_object_handlers.free_obj = php_mix_music_object_free;
	php_mix_music_object_handlers.get_constructor = php_mix_music_object_get_constructor;
	php_mix_music_object_handlers.offset = XtOffsetOf(php_mix_music_object, std);
}

/** }}} */