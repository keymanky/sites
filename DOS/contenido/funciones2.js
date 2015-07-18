function muestraReloj()
 {
 		// Compruebo si se puede ejecutar el script en el navegador del usuario
		if (!document.layers && !document.all && !document.getElementById) return;
		// Obtengo la hora actual y la divido en sus partes
 		var fechacompleta = new Date();
 		var horas = fechacompleta.getHours();
 		var minutos = fechacompleta.getMinutes();
 		var segundos = fechacompleta.getSeconds();
 		var mt = "AM";
 		// Pongo el formato 12 horas
 		if (horas > 12) 
		{
 			mt = "PM";
 			horas = horas - 12;
 		}
 		if (horas == 0) 
			horas = 12;
 		// Pongo minutos y segundos con dos dígitos
 		if (minutos <= 9) 
			minutos = "0" + minutos;
 		if (segundos <= 9) 
			segundos = "0" + segundos;
 		// En la variable 'cadenareloj' puedes cambiar los colores y el tipo de fuente
 		cadenareloj = "<br />" + horas + ":" + minutos + ":" + segundos + " " + mt;
 		// Escribo el reloj de una manera u otra, según el navegador del usuario
 		if (document.layers) 
		{
 			document.layers.spanreloj.document.write(cadenareloj);
 			document.layers.spanreloj.document.close();
 		}
 		else if 
			(document.all) spanreloj.innerHTML = cadenareloj;
 		else if 
 			(document.getElementById) document.getElementById("spanreloj").innerHTML = cadenareloj;
 // Ejecuto la función con un intervalo de un segundo
 setTimeout("muestraReloj()", 1000);
 }
 
 function cambia(num){
	switch(num)
	{
		case 1:
			{
			document.getElementById('contenido').style.backgroundImage = "url(a_2/1.jpg)";
			document.getElementById('flotante').innerHTML = "<br />En esta secci&oacute;n encontraras codigos, manuales, y cosas relacionadas con los lenguajes de programaci&oacute;n dominantes.";
			document.getElementById('contenido').innerHTML = " ";
			break;
			}
		case 2:
			document.getElementById('contenido').style.backgroundImage = "url(a_2/2.jpg)";
			document.getElementById('flotante').innerHTML = "<br />En esta otra encontraras manuales y libros de matem&aacute;ticas relacionados directamente con la Lic. de Matem&aacute;ticas Aplicadas y Computaci&oacute;n";	
			document.getElementById('contenido').innerHTML = " ";					
			break;
		case 3:
			document.getElementById('contenido').style.backgroundImage = "url(a_2/3.jpg)";
			document.getElementById('flotante').innerHTML ="Veras en esta seccion links de p&aacute;ginas web que valen la pena darles un vistazo, referencias u otras de inter&eacute;s<br /> Para acceder da clik sobre el enlace del sitio";
			var link1 ="<a href='http://geslava.netfirms.com/' target='_TOP'>Geslava</a>";
			var link2 ="<a href='https://sites.google.com/site/mariosanchezdominguezpj/' target='_TOP'>Lic Mario</a>";
			var link3 ="<a href='http://www.mslatam.com/latam/msdn/comunidad/dce2005/' target='_TOP'> Comunidad Msdn</a>";
			var link4 ="<a href='http://www.maplesoft.com/' target='_TOP'> Sitio Maple</a>";
			var link5 ="<a href='http://www.facebook.com/programacioncompetitiva' target='_TOP'>Algoritmia Avanzada </a>";						
			var link6 ="<a href='http://la-web-de-ego.netau.net/main.html' target='_TOP'> La web de ego </a>";			
			var link7 ="<a href=' http://www.mac.acatlan.unam.mx/contenido/' target='_TOP'>Sitio Oficial de Mac </a>";	
			var link8 ="<a href=' '> </a>";					
			var link9 ="<a href=' '> </a>";			
			document.getElementById('contenido').innerHTML = "<ul style='background-color:#FFF'>"+ "<li>" + link7 + "</li>" + "<li>" + link1 + "</li>" + "<li>" + link2+ "</li>"+ "<li>" + link3+ "</li>"+ "<li>" + link4+ "</li>"+ "<li>" + link5+ "</li>"+ "<li>" + link6+ "</li>" +"</ul>";
			
			break;
		case 4:
			document.getElementById('contenido').style.backgroundImage = "url(a_2/4.png)";
			document.getElementById('flotante').innerHTML = "<br /><br />Proyecto de BD";			
			document.getElementById('contenido').innerHTML = " ";
			break;
		case 5:
			document.getElementById('contenido').style.backgroundImage = "url(a_2/4.jpg)";
			document.getElementById('flotante').innerHTML = "<br /><br />Dentro de poco estara disponible !!!";			
			document.getElementById('contenido').innerHTML = " ";
			break;
	}
}