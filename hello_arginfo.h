/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 98f0f266d7ae0f9347881031443ee1dc7332d35a */

#define HELLO_VERSION "0.1.2"
#define HELLO_DEFAULT_MESSAGE "Hello, world!"

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Hello___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Hello_message, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Hello_write, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Hello_version arginfo_class_Hello_message

ZEND_METHOD(Hello, __construct);
ZEND_METHOD(Hello, message);
ZEND_METHOD(Hello, write);
ZEND_METHOD(Hello, version);

static const zend_function_entry class_Hello_methods[] = {
	ZEND_ME(Hello, __construct, arginfo_class_Hello___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Hello, message, arginfo_class_Hello_message, ZEND_ACC_PUBLIC)
	ZEND_ME(Hello, write, arginfo_class_Hello_write, ZEND_ACC_PUBLIC)
	ZEND_ME(Hello, version, arginfo_class_Hello_version, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Hello(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "Hello", class_Hello_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);

    zend_declare_class_constant_string(class_entry, "VERSION", sizeof("VERSION") - 1, HELLO_VERSION);
    zend_declare_class_constant_string(class_entry, "MESSAGE", sizeof("MESSAGE") - 1, HELLO_DEFAULT_MESSAGE);

	return class_entry;
}
