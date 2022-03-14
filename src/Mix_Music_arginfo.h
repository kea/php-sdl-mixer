/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: c6b5d170cc55f739aa2b0cb08eae7d8d2bb45404 */




static const zend_function_entry class_Mix_Music_methods[] = {
	ZEND_FE_END
};

static zend_class_entry *register_class_Mix_Music(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "Mix_Music", class_Mix_Music_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}
