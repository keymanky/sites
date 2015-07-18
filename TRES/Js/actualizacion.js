function initArray() 
{
  this.length = initArray.arguments.length
  for (var i = 0; i < this.length; i++)
  this[i+1] = initArray.arguments[i]
}

function actualiza()
{
var vDias = new initArray("Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado");
var vMeses = new initArray("Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre");
var LastModDate = new Date(document.lastModified);
var cadena =  "Esta pagina fue actualizada por ultima vez, el ";
cadena += vDias[(LastModDate.getDay()+1)];
cadena += " ";
cadena += LastModDate.getDate();
cadena += " de ";
cadena += vMeses[(LastModDate.getMonth()+1)];
cadena += " de ";
cadena += LastModDate.getFullYear();
 		if (document.layers) 
		{
 			document.layers.modificacion.document.write(cadena);
 			document.layers.modificacion.document.close();
 		}
 		else if 
			(document.all) modificacion.innerHTML = cadena;
 		else if 
 			(document.getElementById) document.getElementById("modificacion").innerHTML = cadena;
}
