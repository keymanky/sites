<?php
	define('SERVERBD' , 'localhost');
	define('CONTRABD' ,  '12345');
	define('USERBD','root');
	define('BD', 'test');
	$mysqli = new mysqli(SERVERBD,USERBD,CONTRABD,BD);
	
	if ($mysqli->connect_errno) {
	    printf("Error Fatal de Conexion: %s\n", $mysqli->connect_error);
	    exit();
	}
?>