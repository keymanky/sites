<?php
	define('SERVERBD' , 'mysql15.000webhost.com');
	define('CONTRABD' ,  '12345kl');
	define('USERBD','a5798299_george');
	define('BD', 'a5798299_site');
	
	function getIP() 
	{
		if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
		   $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
		}
		elseif (isset($_SERVER['HTTP_VIA'])) {
		   $ip = $_SERVER['HTTP_VIA'];
		}
		elseif (isset($_SERVER['REMOTE_ADDR'])) {
		   $ip = $_SERVER['REMOTE_ADDR'];
		}
		else {
		   $ip = "unknown";
		}
		return $ip;
	}	
?>