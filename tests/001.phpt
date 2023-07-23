--TEST--
Check if can be instatiate Hello object
--EXTENSIONS--
hello
--FILE--
<?php
$hello = new Hello();

var_dump($hello);
?>
--EXPECT--
object(Hello)#1 (0) {
}
