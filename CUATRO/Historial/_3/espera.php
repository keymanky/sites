<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml 1-Transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title> </title>
    <link href="Css/capas.css" rel="stylesheet" type="text/css" />  
    <script type="text/javascript">
    window.seconds = 7; 
    window.onload = function()
    {
        if (window.seconds != 0)
        {
            document.getElementById('secondsDisplay').innerHTML = '' +
                window.seconds + ' segundo' + ((window.seconds > 1) ? 's' : ''); 
            window.seconds--;
            setTimeout(window.onload, 1000);
        }
        else
        {
            window.location = 'keymanky.html';
        }
    }
    </script>
</head>

<body>
    <p class="titulo">Se esta validando su informaci&oacute;n favor de esperar:
    <span id="secondsDisplay"></span></p><br />
    <?php
		$exito = '';
		$error = '';
		date_default_timezone_set('America/Mexico_City');	
		require('Privado/george.php');
		include('Privado/conectar.php');		
		$fecha = date('Y-m-d H:i:s');
		$conecta = mysqli_connect( SERVERBD, USERBD, CONTRABD, BD);			
		$nom = mysqli_real_escape_string($conecta ,stripslashes(trim(htmlspecialchars($_POST['user'], ENT_QUOTES))));
		$dice = mysqli_real_escape_string($conecta ,stripslashes(trim(htmlspecialchars($_POST['comentario'], ENT_QUOTES))));
		$email = mysqli_real_escape_string($conecta ,stripslashes(trim(htmlspecialchars($_POST['pass'], ENT_QUOTES))));			
			
		if( strlen($nom)> 3 && strlen($dice) > 5)
		{
			//Si el correo es valido
			if (preg_match( '/^[^0-9][a-zA-Z0-9_]+([.][a-zA-Z0-9_]+)*[@][a-zA-Z0-9_]+([.][a-zA-Z0-9_]+)*[.][a-zA-Z]{2,4}$/', $email))			
				$sql = "INSERT INTO sugerencias (NOMBRE, FECHA, COMENTARIO, CORREO) VALUES ('$nom', '$fecha', '$dice', '$email')";
			else
				$sql = "INSERT INTO sugerencias (NOMBRE, FECHA, COMENTARIO) VALUES ('$nom', '$fecha', '$dice')";
			$r = mysqli_query($conecta, $sql);	
			//Mandamos el correo
			$mensaje = $nom . " : \n" . $dice;
			$mail->Body = $mensaje;
			//$mail->AddAttachment("archivo.zip");//adjuntos un archivo al mensaje			
			if(!$mail->Send()) 
				$error .= $mail->ErrorInfo;//si no se envía correctamente se guarda en la variable error
			else
				{
					$exito .= 'Se ha notificado automaticamente<br />';	
					$exito .= 'Nombre y Comentarios validos<br />';				
				}
		}
		else
		{
			$error .= 'Nombre minimo 3 caracteres y Comentario minimo 5 caracteres';
		}
		mysqli_close($conecta);			
		
		if(strlen($error)>1)
	    	print '<p class="error">' . $error .'</p>';
		else
	    	print '<p class="titulo">' . $exito . '</p>';
		?>
</body>

</html>