#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_hello.h"
#include "hello_arginfo.h"

/* MACRO: For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

PHP_METHOD(Hello, __construct)
{
	// ...
}

PHP_METHOD(Hello, message)
{
	php_printf("Hello, world!\r\n");
}

PHP_METHOD(Hello, write)
{
	char* message;
	size_t message_length = sizeof(message) - 1;
	zend_string* result;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(message, message_length)
	ZEND_PARSE_PARAMETERS_END();

	result = strpprintf(0, "%s", message);

	RETURN_STR(result);
}

PHP_METHOD(Hello, version)
{
	php_printf("%s\r\n", PHP_HELLO_VERSION);
}

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(hello)
{
	register_class_Hello();

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(hello)
{
#if defined(ZTS) && defined(COMPILE_DL_HELLO)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(hello)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "hello support", "enabled");
	php_info_print_table_row(2, "version", PHP_HELLO_VERSION);
	php_info_print_table_end();
}
/* }}} */

/* {{{ hello_module_entry */
zend_module_entry hello_module_entry = {
	STANDARD_MODULE_HEADER,     // Core: This MACRO fills in everything up to the 'deps' field
	"hello",					// Extension: Name
	class_Hello_methods,		// Core: Struct 'zend_function_entry'
	PHP_MINIT(hello),			// Core: PHP_MINIT (module initialization)
	NULL,						// Core: PHP_MSHUTDOWN (module shutdown)
	PHP_RINIT(hello),			// Core: PHP_RINIT (request initialization)
	NULL,						// Core: PHP_RSHUTDOWN (request shutdown0
	PHP_MINFO(hello),			// Core: PHP_MINFO (Module info)
	PHP_HELLO_VERSION,			// Extension: Version
	STANDARD_MODULE_PROPERTIES  // Core: This MACRO will fill in the rest of the structure 
};
/* }}} */

#ifdef COMPILE_DL_HELLO
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(hello)
#endif
