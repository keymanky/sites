<?php
	define('SERVERBD' , 'mysql15.000webhost.com');
	define('CONTRABD' ,  '123asd');
	define('USERBD','a5798299_sites');
	define('BD', 'a5798299_site');
	$mysqli = new mysqli(SERVERBD,USERBD,CONTRABD,BD);
	
	if ($mysqli->connect_errno) {
	    printf("Error Fatal de Conexion: %s\n", $mysqli->connect_error);
	    exit();
	}
?>