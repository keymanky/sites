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

</head>

<body>
<header></header>
  <div id="main">
    <!--Siguiente es el contenido del sitio-->
    <div id="site_content">
    	<!--Barra de la izquierda -->
		<div id="sidebar_container">
        	<div class="sidebar_logo">
	            <a href="index.php";><img src="images/logo2.png" height="150" /></a>
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
                             <li class="sliding-element"><a class="seleccionado" href="#" onclick="javascript:refresca()">Servicios</a></li>
                             <li class="sliding-element"><a href="index.php">Proyectos</a></li>
					   </ul>
            </div>
        </div>
        
        <!--Contenido principal -->
        <div class="content" style="height: 600px; overflow: auto; text-align:justify; padding: 10px 10px 10px 0px;">
            <a onclick="show('dm2')">Porque las nuevas tecnologias ... (Leer m&aacute;s)</a><br />
        	<div id="dm2" style="display:none;"><p>En el mundo de hoy, se ha vuelto una prioridad fundamental, para la competencia y el crecimiento de empresas el uso de las Tecnolog&iacute;as de la informaci&oacute;n. Las nuevas Tecnolog&iacute;as deben estar presentes en toda actividad de una empresa:  etapas de entrada, conversi&oacute;n y salida. </p>
            <p>Como profesional de TI ofresco mis servicios para desarrollo de sistemas tanto para las &eacute;tapas de entrada y de conversi&oacute;n. Para el &eacute;tapa final ofresco mis servicios de creaci&oacute;n de un sitio web.</p>
            </div>
            <a onclick="show('dm')">Porque tener un sitio Web ...(Leer m&aacute;s)</a><div id="dm" style="display:none;"><p>Un sitio m&aacute;s que nada crea la necesidad en el usuario de consumir, es otro medio de publicidad y medio de comunicaci&oacute;n directa con el cliente, el servicio hace la diferiencia, pero adicionalmente un sitio web proporciona:</p></div>
            <ol>
            	<li>+ Mayor alcance</li>
                <li>+ Dar a conocer novedades y ofertas</li>
                <li>+ Conocer al consumidor e interactuar con el</li>
                <li>+ Facilitar informaci&oacute;n util</li>
                <li>+ Resolver necesidades especificas de la empresa</li>
                <li>+ Y muchas m&aacute;s ...</li>
            </ol>
            <fieldset>
                <legend>$  Precios Sitios Web  $</legend>
                 <p>Puedes mirar mis proyectos y darte cuenta de lo que puedes lograr, aprovecha y actualizate. Presupuesto Gratis !!! [:)]</p>
            <table>
                <tr>
                    <td style="background:#2dc32b">Economico</td>
                    <td style="background:#e500ff">Personalizado</td>
                    <td style="background:#00c8ff">Profesional</td>
                </tr>

                <tr>
                    <td style="background:#2dc32b">$500</td>
                    <td style="background:#e500ff">$1000</td>
                    <td style="background:#00c8ff">Desde $1500</td>
                </tr>
            </table>
            <br />
            </fieldset>
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