<?php
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