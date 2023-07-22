--TEST--
message() Check if message is print
--EXTENSIONS--
hello
--FILE--
<?php
var_dump(message());
var_dump(message('PHP'));
?>
--EXPECT--
string(3) "PHP"
