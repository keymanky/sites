<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml 1-Transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
	<head><title> </title>
    <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
    <link href="../Css/capas.css" rel="stylesheet" type="text/css" />    
    </head>
    <body>
		<form action="espera.php" method="post">
                <fieldset><legend>Gracias</legend>
                <label for="user">Nombre: </label>
                <input type="text" size="9" maxlength="9" name="user"  title="Su nombre"/>
                <label for="email">Email (opcional) :</label>
                <input type="text" size="10" name="pass"  title="Su correo"/><br /><br />
               	<label for="comentario">Su comentario :   </label>
                
                <textarea name="comentario" rows="4" cols="20" title="Introdusca su texto" wrap="virtual">
                </textarea><br/>
                
                <input type="submit" name="login" value="Enviar" />
                <input type="hidden" value="true" name="send" />
                </fieldset>
         </form>
            <?php
				include ('../Privado/conectar.php');
				$conecta = mysqli_connect( SERVERBD, USERBD, CONTRABD, BD);	
				$sql = "SELECT NOMBRE, FECHA, COMENTARIO from sugerencias order by FECHA desc";
				$r = mysqli_query($conecta, $sql);
					if (mysqli_num_rows($r) >0)
					{
						print '<hr /><h3 class="titulo">Estos son los comentarios:</h3><hr  />';
						print '<table>';
						$color =1;
						while($k = mysqli_fetch_array($r))
						{
							if($color == 7)
								$color = $color - 6;
								
							switch($color)
							{
								case 1:
									{
									$fondo = "#FFFF99"; 
									break;
									}
								case 2:
									$fondo = "#66FF99";
									break;
								case 3:
									$fondo = "#9999FF";
									break;
								case 4:
									$fondo = "#99FFFF";
									break;
								case 5:
									$fondo = "#CCFFFF";
									break;
								case 6;
									$fondo = "#FF99FF";
									break;
							}
							$color++;
							print "<tr bgcolor=\"{$fondo}\"";
							print '><td width="200" align="left">';
							print "{$k['FECHA']}";
							print '</td>';
							print '<td align="right">';							
							print "{$k['NOMBRE']}";
							print '</td></tr>';							
							print "<tr bgcolor=\"{$fondo}\"><td colspan=\"2\" width=\"500\" align=\"justify\">";
							print "Dice:<br />{$k['COMENTARIO']}";
							print '</td></tr>';							
						}
						print '</table>';						
						mysqli_free_result($r);
						mysqli_close($conecta);
					}
					else
					{
						print 'No hay comentarios';
					}
			?>          
    </body>
</html>