--TEST--
Check if can be call message method
--EXTENSIONS--
hello
--FILE--
<?php
$hello = new Hello();
$message = $hello->message();

var_dump($message);
?>
--EXPECT--
Hello, world!
