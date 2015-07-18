<?php
session_start();

			//variables de conecion
			include("conectar.php");
			//conectamos a la base de datos
			$mysqli = mysqli_connect($servidor , $usuario , $contrasena , $base_datos);

$display_block = "<br><h1>Your Shopping Cart</h1><br>";

//check for cart items based on user session id
$get_cart_sql = "SELECT st.id, si.item_title, si.item_price, st.sel_item_qty, st.sel_item_size, st.sel_item_color FROM store_shoppertrack AS st LEFT JOIN store_items AS si ON si.id = st.sel_item_id WHERE session_id = '".$_COOKIE["PHPSESSID"]."'";
$get_cart_res = mysqli_query($mysqli, $get_cart_sql) or die(mysqli_error($mysqli));

if (mysqli_num_rows($get_cart_res) < 1) {
    //print message
    $display_block .= "<p>You have no items in your cart.
    Please <a href=\"seestore.php\">continue to shop</a>!</p>";
} else {
    //get info and build cart display
    $display_block .= "

    <table cellpadding=\"3\" cellspacing=\"2\" border=\"1\" width=\"98%\">
	
    <tr>
    <th>Title</th>
    <th>Size</th>
    <th>Color</th>
    <th>Price</th>
    <th>Qty</th>
    <th>Total Price</th>
    <th>Action</th>

    </tr>";

    while ($cart_info = mysqli_fetch_array($get_cart_res)) {
   	    $id = $cart_info['id'];
   	    $item_title = stripslashes($cart_info['item_title']);
   	    $item_price = $cart_info['item_price'];
   	    $item_qty = $cart_info['sel_item_qty'];
   	    $item_color = $cart_info['sel_item_color'];
   	    $item_size = $cart_info['sel_item_size'];
	    $total_price = sprintf("%.02f", $item_price * $item_qty);

	if($total_price > 0){
		
		$total_shopping= sprintf("%.02f",$total_shopping+$total_price);
						}
			
						


   	    $display_block .= "
   	    <tr>
   	    <td align=\"center\">$item_title <br></td>
   	    <td align=\"center\">$item_size <br></td>
   	    <td align=\"center\">$item_color <br></td>
   	    <td align=\"center\">\$ $item_price <br></td>
   	    <td align=\"center\">$item_qty <br></td>
   	    <td align=\"center\"  bgcolor=\"#00CC00\">\$ $total_price</td>
   	    <td align=\"center\"><a href=\"removefromcart.php?id=".$id."\">remove</a></td>
		
   	    </tr>";
	
		
    }

    $display_block .= "</table>";
	
	$display_block .= "
		<br><table class=\"estilotabla1\" celpadding=\"3\" cellspacing=\"2\" border=\"0\">
    		<tr>
				<th class=\"estilocelda\" >El costo total de su compra es de $ $total_shopping</th>
    		</tr>";
	 $display_block .= "</table>";
	
	 $display_block .= 
	 "
	 <br />
	 <br/ >
	 <br/ >
	 <form method=\"\" action=\"seestore.php\"> 
	 <div align=\"center\"> <input type=\"submit\" name=\"regresar\" value=\"Hacer otra compra pulse el bot&oacute;n\"></center>
	 </form> 
	 ";	  
	  
		 $display_block .= 
	 "
	    <br />
	 <br/ >
	  <br />
	 <br/ >
<div><b><font color=\"#FFFFFF\">Si desea confirmar la compra. Llene el formulario con sus datos por favor..</font></b></div>
<form action=\"mailto:aldo_morales0001@hotmail.com\" method=\"post\" enctype=\"text\/plain\" id=\"\">


<br />

<div class=\"marco\">
<p class=\"texto\">DATOS PERSONALES</p>
<span class=\"label\">Nombre</span><input type=\"text\" name=\"Nombre\" id=\"inputs\" />
<br />
<span class=\"label\">Apellido</span><input type=\"text\" name=\"Apellido\" id=\"inputs\" />
<br />
<span class=\"label\">Direcci&oacute;n</span>
<input type=\"text\" name=\"DirecciOn\" id=\"inputs\" />
<br />
<span class=\"label\">Poblaci&oacute;n</span>
<input type=\"text\" name=\"PoblaciOn\" id=\"inputs\" />
<br />
<span class=\"label\">Provincia</span>
<input type=\"text\" name=\"Provincia\" id=\"inputs\" />
<br />
<span class=\"label\">Tel&eacute;fono</span>
<input type=\"text\" name=\"TelEfono\" id=\"inputs\" />
<br />
<br />


		
<span class=\"label1\"></span>
<br/>
<input type=\"text\" name=\"$item_title:  $item_qty\" id=\"inputs1\" />


<span class=\"label1\"></span>
<br/>
<input type=\"text\" name=\"El monto total de su compra es de $ $total_shopping con el iva incluido\" id=\"inputs1\" />

<br />

<div align=\"center\" class=\"marco2\">
<input type=\"submit\" value=\"Enviar\" id=\"boton\" />
<input type=\"reset\" value=\"Borrar\" id=\"boton\" />
<p><font color=\"white\">El pedido ser&aacute; colocado en la bandeja de salida de su
programa de correo para ser enviado a un e-mail existente llamado aldo_morales0001@hotmail.com
</font></p>
</div></div>
</form>
";
	  
	  }
?>


<html>
<head>
<title>My Store</title>
<link href="estilo3.css" rel="stylesheet" type="text/css" />
</head>
<body>
<?php echo $display_block; ?>
</body>
</html>
