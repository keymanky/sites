<?php
			require ('PHPMailer_v5.1/class.phpmailer.php');
			require ('PHPMailer_v5.1/class.smtp.php');
			$mail = new PHPMailer();
			//Consiguraciones de gmail
			$mail->CharSet = 'UTF-8';
			$mail->SMTPAuth = true;
			$mail->SMTPSecure = "ssl";
			$mail->Host = "smtp.gmail.com";
			$mail->Port = 465;
			$mail->Username = 'keypiratey@gmail.com';
			$mail->Password = '307310822';
			//Configuraciones del envio
			$mail->FromName = 'George Sitio Version 3.5'; //From es del q envia
			$mail->From = 'test@gob.mx';
			$mail->AddAddress('keypiratey@gmail.com', 'Comentario');
			//$mail->AddCC('copia@dominio.com', 'copia');
			$mail->Subject = 'Un nuevo comentario';
			//$mail->MsgHTML('<hr>Registro completo<hr>');//cuerpo con html			
?>