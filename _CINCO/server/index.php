<?php
    include('scripts/insert_estadisticas.php');
?>
<!DOCTYPE HTML>
<html>

<head>
  <meta charset="UTF-8">
  <title> .-+ GEORGE +-.</title> 
  <link rel="stylesheet" type="text/css" href="css/style.css" />  
  <link rel="stylesheet" type="text/css" href="css/style_common.css" />   
  <!--modernizr enables HTML5 elements and feature detects -->
  <script src="js/modernizr-1.5.min.js"></script>
  <script src="js/jquery-1.7.1.js"></script>  
  <script src="js/sliding_effect.js"></script>   
  <script src="js/propios.js"></script>
  <script type="text/javascript" src="js/tinybox.js"></script>
</head>

<body>
<header></header>
  <div id="main">
    <!--Siguiente es el contenido del sitio-->
    <div id="site_content">
    	<!--Barra de la izquierda -->
		<div id="sidebar_container">
        	<div class="sidebar_logo">
	            <a href="#" onclick="javascript:refresca()";><img src="images/logo2.png" height="150" /></a>
            </div>
        	<div class="sidebar">
                  <h3>Seleccione:</h3>
				    	<ul id="sliding-navigation"> 
                            <li class="sliding-element"><a href="#" onclick="show('desplegar')">Acerca de ...</a>
                                   <div id="desplegar" style="display:none;">
                                        <ul>
                                	       <li><a href="acerca.php#Perfil">Perfil</a></li>
                                	       <li><a href="acerca.php#M@C">M@C</a></li>
                                           <li><a href="acerca.php#Contacto">Contacto</a></li>
                                        </ul>
                                    </div>
                            </li>
                             <li class="sliding-element"><a href="servicios.php">Servicios</a></li>
                             <li class="sliding-element"><a class="seleccionado" href="#" onclick="javascript:refresca()";>Proyectos</a></li> 
					   </ul>
            </div>
        </div>
        
        <!--Contenido principal -->
        <div class="content">
        	<div class="view view-sixth">
                <a href="#" onclick="TINY.box.show({iframe:'frames/base.php',boxid:'frameless',width:600,height:400,fixed:false,maskopacity:40,closejs:function(){closeJS()}})">
            	<img src="images/base.png" />
                <div class="mask">
                	<h2>Base de datos</h2>
                    <p>Diversas bases de datos recopiladas de la WEB: Unam, Sexo, Codigos, Empresas, SPAM , Escuelas Publicas.<br/>En .sql MYSQL</p>
                </div>
                </a>
            </div>     
        	<div class="view view-sixth">
                <a href="#" onclick="TINY.box.show({iframe:'frames/correos.php',boxid:'frameless',width:600,height:400,fixed:false,maskopacity:40,closejs:function(){closeJS()}})"">
            	<img src="images/correos.png" />
                <div class="mask">
                	<h2>Correos de M&eacute;xico</h2>
                    <p>Interfaz tipo Office con Altas, Bajas, Cambios y B&uacute;squeda a la base de correos de M&eacute;xico, proyecto desarrollado en Administraci&oacute;n de Base de datos.</p>
                </div>
                </a>
            </div>
        	<div class="view view-sixth">
                <a href="#" onclick="TINY.box.show({iframe:'frames/virus.php',boxid:'frameless',width:600,height:400,fixed:false,maskopacity:40,closejs:function(){closeJS()}})">
            	<img src="images/virus.png" />
                <div class="mask">
                	<h2>Virus Windows</h2>
                    <p>Ataca directamente los archivos del usuario actual; tu antivirus no lo pela.</p>
                </div>
                </a>
            </div>  
        	<div class="view view-sixth">
                <a href="#" onclick="TINY.box.show({iframe:'frames/sitios.php',boxid:'frameless',width:600,height:400,fixed:false,maskopacity:40,closejs:function(){closeJS()}})">
            	<img src="images/sitios.png" />
                <div class="mask">
                	<h2>Herramientas novedosas</h2>
                    <p>Ve las librerias y lo que puedes hacer con ellas.</p>
                </div>
                </a>
            </div>
        	<div class="view view-sixth">
                <a href="#" onclick="TINY.box.show({iframe:'frames/c.php',boxid:'frameless',width:600,height:400,fixed:false,maskopacity:40,closejs:function(){closeJS()}})">
            	<img src="images/libreria.png" />
                <div class="mask">
                	<h2>Librer&iacute;a .h</h2>
                    <p>M&aacute;s de 2000 l&iacute;neas de C&oacute;digo en C.<br/>Contiene diversas funciones compiladas en Dev-c.</p>
                </div>
                </a>
            </div>  
        	<div class="view view-sixth">
                <a href="#" onclick="TINY.box.show({iframe:'frames/h5.php',boxid:'frameless',width:600,height:400,fixed:false,maskopacity:40,closejs:function(){closeJS()}})">
            	<img src="images/tm.png" />
                <div class="mask">
                	<h2>Html 5 y processing</h2>
                    <p>Proyectos de Audio, Imagen y Video.<br />Desarrollado en la materia de Tecnolog&iacute;a Multimedia.</p>
                </div>
                </a>
            </div>
        	<div class="view view-sixth">
                <a href="#" onclick="TINY.box.show({iframe:'frames/store.php',boxid:'frameless',width:600,height:400,fixed:false,maskopacity:40,closejs:function(){closeJS()}})">
            	<img src="images/tienda.png" />
                <div class="mask">
                	<h2>Tienda online PHP</h2>
                    <p>Carrito de compras cl&aacute;sico desarrollado en PHP para la materia de Ingenier&iacute;a de Software.</p>
                </div>
                </a>
            </div> 
            <div class="view view-sixth">
                <a href="#" onclick="TINY.box.show({iframe:'frames/masivo.php',boxid:'frameless',width:600,height:400,fixed:false,maskopacity:40,closejs:function(){closeJS()}})">
            	<img src="images/masivo.png" />
                <div class="mask">
                	<h2>Envio masivo de Emails</h2>
                    <p>Envia miles de emails sin ser detectado como spam. !!!</p>
                </div>
                </a>
            </div>                                             
        </div>
    </div>    
    <footer>
      <p>Keymanky Copyright &copy; | Jorge Salgado Mendoza |</p>
    </footer>
  </div>
  <p>&nbsp;</p>
  <!-- javascript at the bottom for fast page loading -->
</body>
</html>