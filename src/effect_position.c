#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "effect_position.h"

PHP_FUNCTION(Mix_SetPosition)
{
	zend_long channel;
	zend_long angle;
	zend_long distance;

	ZEND_PARSE_PARAMETERS_START(3, 3);
		Z_PARAM_LONG(channel)
		Z_PARAM_LONG(angle)
		Z_PARAM_LONG(distance)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_SetPosition(channel, angle, distance);

	RETURN_LONG(result);
}

PHP_FUNCTION(Mix_SetDistance)
{
	zend_long channel;
	zend_long distance;

	ZEND_PARSE_PARAMETERS_START(2, 2);
		Z_PARAM_LONG(channel)
		Z_PARAM_LONG(distance)
	ZEND_PARSE_PARAMETERS_END();

	int result = Mix_SetDistance(channel, distance);

	RETURN_LONG(result);
}
