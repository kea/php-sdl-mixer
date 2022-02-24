PHP_FUNCTION(Mix_SetPosition)
{
    zend_long channel;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_LONG(channel)
    ZEND_PARSE_PARAMETERS_END();

    int result = Mix_SetPosition(channel);

    RETURN_LONG(result);
}

PHP_FUNCTION(Mix_SetDistance)
{
    zend_long channel;

    ZEND_PARSE_PARAMETERS_START(1, 1);
        Z_PARAM_LONG(channel)
    ZEND_PARSE_PARAMETERS_END();

    int result = Mix_SetDistance(channel);

    RETURN_LONG(result);
}
