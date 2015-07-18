<?php
//780 && 559
	//Manda el flujo
	ob_start();
	//Inicia sesion
	session_start();
	//Si ya ha captura la resolucion
	  if (isset($_GET['ancho']) && isset($_GET['alto'])) 
	  {
		 if($_GET['ancho'] > 780 && $_GET['alto'] > 559)
		 {
			 include('Privado/conectar.php');
			//Configura la zona horaria
			date_default_timezone_set('America/Mexico_City');		
			//Guarda sesion
			$sesion= $_COOKIE["PHPSESSID"];
			//Obtiene la IP
			$ip= getIP();
			//Conecta
			$conecta = mysqli_connect(SERVERBD, USERBD, CONTRABD, BD);		
			$fecha = date('Y-m-d H:i:s');		
			$sql = "insert into estadisticas (ID, IP, FECHA) values ('$sesion', '$ip', '$fecha')";
			//Ejecuta la consulta
			$res = mysqli_query($conecta, $sql);
			//Redirecciona
			mysqli_close($conecta);		
			header('Location: keymanky.html');
		 }
		 else
		 {
			echo "<script language='javascript'>\n";			 
			echo "alert('La resolucion de su pantalla es muy baja. Espera la version para MOBILES')";
			echo "</script>\n";
		 }
	  } 
	  else 
	  {
		 // enviar las variables al servidor. Envio sobre si mismo
		 echo "<script language='javascript'>\n";
		 echo  "location.href=\"${_SERVER['SCRIPT_NAME']}?${_SERVER['QUERY_STRING']}" .  "&ancho=\" + screen.availWidth + \"&alto=\" + screen.availHeight;\n";
		 echo "</script>\n";
		 exit();
	  }
?>