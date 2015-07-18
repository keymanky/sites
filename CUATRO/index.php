<?php 
	session_start();
	if(isset($_GET['primera']) && $_GET['primera']== true)
	{
	
	}
	else
	{
		$primera = true;
		header("Location:index.php?primera=$primera");
	}
?>
<!DOCTYPE HTML>
	<head>
		<title>.:. keymanky .:.</title>
		<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
		<meta http-equiv="pragma" content="nocache" />        
        <link rel="shortcut icon" href="Imagenes/Icono.ico" />        
		<link href="Css/error.css" rel="stylesheet" type="text/css" />
		<link href="Jquery-ui-1.8.16/css/dark-hive/jquery-ui-1.8.16.custom.css" rel="stylesheet" type="text/css" />
        <script language="javascript" type="text/javascript" src="Jquery-ui-1.8.16/js/jquery-1.6.2.min.js"></script>
        <script language="javascript" type="text/javascript" src="Jquery-ui-1.8.16/js/jquery-ui-1.8.16.custom.min.js"></script>
	<script type="text/javascript">
	$(document).ready(function(){		
		$( "#dialog:ui-dialog" ).dialog( "destroy" );
		$( "#dialog-confirm" ).dialog({
			resizable: false,
			modal: true,
			width : 500,
			height: 400,
			buttons: {
				Ok: function() {
					$( this ).dialog( "close" );
					<?php
						$_SESSION['ACEPTO'] = true;
						$_SESSION['NOPOSTBACK'] = true;
						$_SESSION['NOMBRE'] = "";
					?>
					location.href= "keymanky.php"
				},
				Cancel: function() {
				}
			}
		});
	});
	</script>
    <script type="text/javascript">
	  var _gaq = _gaq || [];
	  _gaq.push(['_setAccount', 'UA-27922266-1']);
	  _gaq.push(['_trackPageview']);
	  (function() {
		var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
		ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
		var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
	  })();
	</script>
	</head>
	<body>
    	<div id="error">
   	    	<img src="Imagenes/error.png" alt="Error">
        </div>
    	<div>
            <div id="dialog-confirm" title="T&eacute;rminos y Condiciones de Uso">El usuario se hace responsable por el uso que le de a la informaci&oacute;n de este sitio, ya que esta es sencible y se le puede dar un uso perjudicial; asi mismo toda la informaci&oacute;n aqu&iacute; presentada (imagenes, efectos y animaciones) no tienen derechos de autor y son de licencia libre.<br />Todo el texto y el sitio completo es propiedad de JSM.<br /><br />Si esta de acuerdo de Clic en OK y sera redireccionado, en otro caso no podra ver el contenido.</div>
        </div>

        <footer>
        	Sitio Optimizado: (versiones 2010 o superiores):&nbsp;&nbsp;&nbsp;<img src="Imagenes/nav.png" /><br /><br/>
         <marquee id="creditos" behavior="scroll" direction="up" scrollamount="2">Hecho en México, todos los derechos reservados 2011. Esta página puede ser reproducida con fines no lucrativos, siempre y cuando no se mutile, se cite la fuente completa y su dirección electrónica. De otra forma, requiere permiso previo por el autor. <br />Sitio web administrado por: JSM</marquee>   
        </footer>
	</body>
</html>