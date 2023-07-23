--TEST--
Check if can be call version method
--EXTENSIONS--
hello
--FILE--
<?php
$hello = new Hello();
$version = $hello->version();

var_dump(version);
?>
--EXPECT--
0.2.0
