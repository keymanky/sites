<?php
	//Primero guardamos todo el codigo de php ya que hearder no necesita q se envie nada al cliente; por default se envia todo al final del script
	ob_start();
	//En cada pagina php que necesitemos usar las varialbes de sesion de otras paginas debemos declarar la sig linea
	session_start();
	if ($_SESSION['ACEPTO'])
	{
		if($_SESSION['NOPOSTBACK'])
		{
				include('conectar.php');
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
				mysqli_close($conecta);	
				$_SESSION['NOPOSTBACK'] = false;
				$_SESSION['ID'] = $sesion;	
		}
		echo '<!DOCTYPE HTML>
<head>
                    <title>.:. keymanky .:.</title>
                    <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
                    <meta http-equiv="pragma" content="nocache" />        
                    <link rel="shortcut icon" href="Imagenes/Icono.ico" />    
                    <link rel="stylesheet" type="text/css" href="Css/animado.css" />    
                    <link href="Css/principal.css" rel="stylesheet" type="text/css" />
					<link rel="stylesheet" type="text/css" media="screen" href="Css/menu.css">
                    <link href="Jquery-ui-1.8.16/css/dark-hive/jquery-ui-1.8.16.custom.css" rel="stylesheet" type="text/css" />  
                    <link rel="stylesheet" href="Css/acordeon.css" type="text/css" />                    
				    <link href="Css/tTip.css" rel="stylesheet" type="text/css" media="all" />
					<link rel="stylesheet" href="Css/uniform.default.css" type="text/css" media="screen">                                         
					<script type="text/javascript" src="Jquery-ui-1.8.16/js/jquery-1.6.2.min.js"></script>
                    <script type="text/javascript" src="Jquery-ui-1.8.16/js/jquery.jqDock.min.js"></script>
                    <script type="text/javascript" src="Jquery-ui-1.8.16/js/jquery-corner.js"></script>
					<script type="text/javascript" src="Jquery-ui-1.8.16/js/jquery-easing-1.3.pack.js"></script>
                    <script type="text/javascript" src="Jquery-ui-1.8.16/js/jquery-easing-compatibility.1.2.pack.js"></script>
                    <script type="text/javascript" src="Jquery-ui-1.8.16/js/coda-slider.1.1.1.pack.js"></script>     
                    <script type="text/javascript" src="Jquery-ui-1.8.16/js/todos.js"></script>                                       
                    <script type="text/javascript" src="Jquery-ui-1.8.16/js/jquery.betterTooltip.js"></script>
                    <script src="Jquery-ui-1.8.16/js/jquery.uniform.js" type="text/javascript" charset="utf-8"></script>                
                    <script type="text/javascript">
						//Ocultar div Ver
						function mostrar_oculta() {
						div = document.getElementById(\'ocultar\');
						var vista = document.getElementById(\'ocultar\').style.display;
						if(vista == \'none\'){
							div.style.display = \'\';
							}
						else{
							div.style.display=\'none\';
							}
						}
						function no(){
							var div = document.getElementById(\'ocultar\');
							div.style.display = \'none\';
						}
					</script>
</head>
<body>
                <!--Logo -->
                <header id="logo">
                	<table>
                    	<tr>
                        	<td width="250px"  height="150px" style="vertical-align:middle; text-align:center"><img src="Imagenes/yo.png" /></td>
                            <td width="100%"><br />--: Desarrollamos t&uacute; proyecto :--<br/><hr/>Confia en Nosotros, te podemos ayudar.</td>
                            <td width="250px"><img src="Imagenes/yo2.png" /></td>
                        </tr>
                    </table>
                </header><br />
                <!-- Noticias -->
                <nav id="relevante" class="test">
				<div class="accordion">
				<!--Slider Menu rotatorio-->  
                <h3><a href="javascript:mostrar_oculta();"><div class="accordion tTip" title="Da clic para ver/ocultar">Destacados</div></a></h3>
                <div id="ocultar">
                <div id="page-wrap">						
                    <div class="slider-wrap">
                        <div id="main-photo-slider" class="csw">
                            <div class="panelContainer">
                                    <div class="panel" title="2012">
                                    <div class="wrapper">
                                        <img src="Imagenes/pena.png" alt="temp" />
                                        <div class="photo-meta-data">
                                            Y aun as&iacute;: votar&eacute; por: &nbsp;<a href="http://www.fileserve.com/file/BMc8bSe" target="_new">Enrique Pe&ntilde;a Nieto (Descargar Libro)</a><br />
                                            <span>Elecciones 2012, este libro nos dice todas las mentiras de Pe&ntilde;a.</span>
                                        </div>
                                    </div>
                                </div>
                                <div class="panel" title="Base datos">
                                    <div class="wrapper">
                                        <img src="Imagenes/base.png" alt="temp" />
                                        <div class="photo-meta-data">
                                            Bases de datos para tu web: Paises mundo, Codigos postales Mexico, Empresas Mexicanas, Nombres y Sexo
                                            <span><a href="http://www.fileserve.com/file/BMc8bSe" target="_new">Aqu&iacute;</a></span>
                                        </div>
                                    </div>
                                </div>		
                                <div class="panel" title="Internet Gratis">
                                    <div class="wrapper">
                                        <img src="Imagenes/hack.png" alt="temp"/>
                                        <div class="photo-meta-data">
                                            Internet gratis en M&eacute;xico. Necesitas Ubuntu para hackear<br />
                                            <span>Descargar video: <a href="http://www.fileserve.com/file/BMc8bSe" target="_new">Aqu&iacute;</a></span>
                                        </div>                        
                                    </div>
                                </div>
                                <div class="panel" title="Sistema GRADUS">
                                    <div class="wrapper">
                                        <img src="Imagenes/gradus.png" alt="temp" />
                                        <div class="photo-meta-data">
                                            El sistema de titulaci&oacute; online<br />
                                            <span>El CEDETEC espera su lanzamiento para el 2013 !</span>
                                        </div>
                                    </div>
                                </div>
                                <div class="panel" title="Historial">
                                    <div class="wrapper">
                                        <img src="Imagenes/historial.png" alt="temp" border="0" usemap="#Map" />
                                        <map name="Map">
                                          <area shape="poly" coords="149,116,153,101" href="Historial/_1/index.html" alt="Ir a 1er Sitio">
                                          <area shape="poly" coords="147,113,148,109,151,112" href="Historial/_1/index.html" alt="Ir a 1er Sitio">
                                          <area shape="poly" coords="6,5,149,4,149,102,137,112,148,116,4,117,3,104,4,58,5,29" href="Historial/_1/index.html" alt="1er Sitio">
                                          <area shape="poly" coords="158,101,146,119,143,209,294,209,294,101" href="Historial/_2/index.html" alt="2do Sitio">
                                          <area shape="poly" coords="294,155,296,209" href="Historial/_1/index.html" alt="2do Sitio">
                                          <area shape="poly" coords="295,155,415,153,414,225,294,226,251,227,249,212,293,211" href="Historial/_3/index.php" alt="3er Sitio">
                                        </map>
                                        <div class="photo-meta-data">
                                        Visita mis versiones anteriores. Da click sobre el que quieras visitar<br />
                                            <span>Aqu&iacute; encontraras la evoluci&oacute;n de mis sitios web</span>
                                      	</div>
                                  </div>
                                </div>
                                <div class="panel" title="Envio masivo Email">
                                    <div class="wrapper">
                                        <img src="Imagenes/masivo.png" alt="temp" />
                                        <div class="photo-meta-data">
                                            Di si al SPAM y haz trabajar a la Internet<br />
                                            <span>EN PROCESO DE DESARROLLO</span>
                                        </div>
                                    </div>
                                </div>
                            </div>
                        </div>
                        
                        <a href="#1" class="cross-link"><img src="Imagenes/mini-pena.png" class="nav-thumb" alt="temp-thumb" /></a>
                        <div id="movers-row">
                            <div><a href="#2" class="cross-link"><img src="Imagenes/mini-base.png" class="nav-thumb" alt="temp-thumb" /></a></div>
                            <div><a href="#3" class="cross-link"><img src="Imagenes/mini-hack.png" class="nav-thumb" alt="temp-thumb" /></a></div>
                            <div><a href="#4" class="cross-link"><img src="Imagenes/mini-gradus.png" class="nav-thumb" alt="temp-thumb" /></a></div>
                            <div><a href="#5" class="cross-link"><img src="Imagenes/mini-historial.png" class="nav-thumb" alt="temp-thumb" /></a></div> 
                            <div><a href="#6" class="cross-link"><img src="Imagenes/mini-masivo.png" class="nav-thumb" alt="temp-thumb" /></a></div>                             
                        </div>
                    </div>
                    </div>                           
					<!---Fin Slider!--> 
                    
                <!--Banner -->                  
                <div id="banner">';
				if(isset($_POST['nombre']))
				{
					if($_SESSION['NOMBRE'] == $_POST['nombre'])
					{
						
					}
					else
					{
						include('conectar.php');
						$conecta = mysqli_connect(SERVERBD, USERBD, CONTRABD, BD);
						$nombre = mysqli_real_escape_string($conecta ,stripslashes(trim(htmlspecialchars($_POST['nombre'], ENT_QUOTES))));
						$comn = mysqli_real_escape_string($conecta ,stripslashes(trim(htmlspecialchars($_POST['comentario'], ENT_QUOTES))));
						$id = $_SESSION['ID'];
						$sql = "update estadisticas SET NOMBRE = '$nombre', COMENTARIO = '$comn' where ID = '$id'";
						//Ejecuta la consulta
						$res = mysqli_query($conecta, $sql);
						mysqli_close($conecta);							
						$_SESSION['NOMBRE'] = $_POST['nombre'];
					}
					echo 'Tu comentario se envio correctamente<img src="Imagenes/exito.png" alt="temp" /></div>';
				}
				else
				{
					echo '<form style="text-align:left; background:#E6E6E6;" action="keymanky.php" method="post">
                    <fieldset><legend>Escr&iacute;beme: </legend>
                      <label>Nombre</label><br /><input type="text" size="18" maxlength="18" name="nombre"/><br />
                      <label>Mensaje</label><br /><textarea cols="20" rows="10" name="comentario"></textarea><br />
                      <input type="submit" value="enviar" />
					  <input type="hidden" name="send" value="true" />
					</fieldset>
                    </form></div>       
    			';
				}
    			
                echo '<div id="google_translate_element"></div><script>
function googleTranslateElementInit() {
  new google.translate.TranslateElement({
    pageLanguage: \'es\'
  }, \'google_translate_element\');
}
</script><script src="//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit"></script>
                </div>       
                </div>
                </nav><br />
                
                
                <!--Cambia con ajax Area contenido -->
                <section id="contenido">
                      <hr /><h3>Bienvenido</h3><hr  />
                      <p>Est&aacute; es la &uacute;ltima versi&oacute;n del sitio Web de Jorge S.M<br/>Aca encontraras varias secciones que podras navegar con el men&uacute; que se encuentra de tu lado izquierdo, al dar clik sobre cualquier categor&iacute;a este espacio cambiara; tambi&eacute;n podras ocultar la secci&oacute;n de Destacados que se encuentra en la parte superior.<br/>No olvides visitarme y navegar por todo el sitio que,<br /> pensando en t&iacute; lo dise&ntilde;e; y de paso enviame un comentario que con gusto leere.
                      <br/><br /><br />Adicionalmente ofresco mis servicios profesionales que incluyen (todo a mitad de precio):<br />
                      <ul>
                        <li>Desarrollo de Software</li>
                        <li>Desarrollo de Sitio Web</li>
                        <li>Desarrollo de Aplicaciones</li>
                        <li>Mantenimiento y Actualizaci&oacute;n de Sistemas y Sitios Web</li>
                      <ul>
                      <br />M&aacute;s informaci&oacute;n da click en la secci&oacute;n de <strong>Servicios</strong> del men&uacute;<br />
                      <img src="Imagenes/portfolio-sm.png" />
                      </p>
                </section>
                <!--Rss-->
                <aside id="noticias">
                    <div>
                        <div data-sqwidget="src:http://www.bbc.co.uk/worldservice/widget/live/v2/bbcwswidget-es.js"
                            data-sqwidget-settings="package:es;"
                            style="padding:0; margin:0; margin-top:30px; border:none; width:230px;" id="bbc-es-widget-1">
                        </div>
                        <script src="http://www.bbc.co.uk/worldservice/widget/sqwidget.js" type="text/javascript" async="async"></script> 
                    </div>                
                </aside>

                <!--Menu-->
                        <div id="dockContainer">
                            <ul id="jqDock">
                                <li><a class="dockItem" href="javascript:Enviar(\'Paginas/inicio.html\',\'contenido\'),no()"><img src="Imagenes/home-sm.png" alt="Inicio" title="Inicio" /></a></li>
                                <li><a class="dockItem" href="javascript:Enviar(\'Paginas/acerca.html\',\'contenido\'),no()"><img src="Imagenes/email-sm.png" alt="Acerca de ..." title="Acerca de ..." /></a></li>
                                <li><a class="dockItem" href="javascript:Enviar(\'Paginas/servicios.html\',\'contenido\'),no()"><img src="Imagenes/portfolio-sm.png" alt="Servicios" title="Servicios" /></a></li>
                                <li><a class="dockItem" href="javascript:Enviar(\'Paginas/proyectos.html\',\'contenido\'),no()"><img src="Imagenes/video-sm.png" alt="Proyectos" title="Proyectos" /></a></li>
                                <li><a class="dockItem" href="javascript:Enviar(\'Paginas/enlaces.html\',\'contenido\'),no()"><img src="Imagenes/link-sm.png" alt="Links" title="Enlaces" /></a></li>
                            </ul>
                        </div>
                        
                     <!--Pie-->                      
                     <footer>
                        Sitio Optimizado: (versiones 2010 o superiores):&nbsp;&nbsp;&nbsp;<img src="Imagenes/nav.png" /><br /><br/>
                     <marquee id="creditos" behavior="scroll" direction="up" scrollamount="2">Hecho en M&eacute;xico, todos los derechos reservados 2011. Esta p&aacute;gina puede ser reproducida con fines no lucrativos, siempre y cuando no se mutile, se cite la fuente completa y su direcci&oacute;n electr&oacute;nica. De otra forma, requiere permiso previo por el autor. <br />Sitio web administrado por: JSM</marquee></div> 
</body>
</html>';
	}
	else
	{
		header('Location: index.php');
	}
?>