--TEST--
Check if can be call version method
--FILE--
<?php
$hello = new Hello();
$version = $hello->version();

var_dump($version);
?>
--EXPECT--
string(5) "0.1.1"
