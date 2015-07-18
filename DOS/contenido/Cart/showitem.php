<?php
session_start();

			//variables de conecion
			include("conectar.php");
			//conectamos a la base de datos
			$mysqli = mysqli_connect($servidor , $usuario , $contrasena , $base_datos);

$display_block = "<h1>My Store - Item Detail</h1>";

//validate item
$get_item_sql = "SELECT c.id as cat_id, c.cat_title, si.item_title, si.item_price, si.item_desc, si.item_image FROM store_items AS si LEFT JOIN store_categories AS c on c.id = si.cat_id WHERE si.id = '".$_GET["item_id"]."'";
$get_item_res = mysqli_query($mysqli, $get_item_sql) or die(mysqli_error($mysqli));

if (mysqli_num_rows($get_item_res) < 1) {
   //invalid item
   $display_block .= "<p><em>Invalid item selection.</em></p>";
} else {
   //valid item, get info
   while ($item_info = mysqli_fetch_array($get_item_res)) {
	   $cat_id = $item_info['cat_id'];
	   $cat_title = strtoupper(stripslashes($item_info['cat_title']));
	   $item_title = stripslashes($item_info['item_title']);
	   $item_price = $item_info['item_price'];
	   $item_desc = stripslashes($item_info['item_desc']);
	   $item_image = $item_info['item_image'];
	}

   //make breadcrumb trail
   $display_block .= "<p><strong><em>You are viewing:</em><br/>
   <a href=\"seestore.php?cat_id=".$cat_id."\">".$cat_title."</a> &gt; ".$item_title."</strong></p>
   
   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
   <table  class=\"estilotabla\" cellpadding=\"3\" cellspacing=\"3\">
   <tr>
   <td valign=\"middle\" align=\"center\"><img src=\"".$item_image."\"/></td>
   </tr>
   <tr>
   <td valign=\"middle\"><p><strong>Description:</strong><br/>".$item_desc."</p>
   <p><strong>Price:</strong> \$".$item_price."</p>
   <form method=\"post\" action=\"addtocart.php\">";

   //free result
   mysqli_free_result($get_item_res);

   //get colors
   $get_colors_sql = "SELECT item_color FROM store_item_color WHERE item_id = '".$_GET["item_id"]."' ORDER BY item_color";
   $get_colors_res = mysqli_query($mysqli, $get_colors_sql) or die(mysqli_error($mysqli));

   if (mysqli_num_rows($get_colors_res) > 0) {                   //cuenta las duplas q solicitamos
        $display_block .= "<p><strong>Available Colors:</strong><br/>
        <select name=\"sel_item_color\">";

        while ($colors = mysqli_fetch_array($get_colors_res)) {
           $item_color = $colors['item_color'];
           $display_block .= "<option value=\"".$item_color."\">".$item_color."</option>";
       }
       $display_block .= "</select>";
   }

   //free result
   mysqli_free_result($get_colors_res);

   //get sizes
   $get_sizes_sql = "SELECT item_size FROM store_item_size WHERE item_id = ".$_GET["item_id"]." ORDER BY item_size";
   $get_sizes_res = mysqli_query($mysqli, $get_sizes_sql) or die(mysqli_error($mysqli));

   if (mysqli_num_rows($get_sizes_res) > 0) {
       $display_block .= "<p><strong>Available Sizes:</strong><br/>
       <select name=\"sel_item_size\">";

       while ($sizes = mysqli_fetch_array($get_sizes_res)) {
          $item_size = $sizes['item_size'];
          $display_block .= "<option value=\"".$item_size."\">".$item_size."</option>";
       }
   }

   $display_block .= "</select>";

   //free result
   mysqli_free_result($get_sizes_res);

   $display_block .= "
   <p><strong>Select Quantity:</strong>
   <select name=\"sel_item_qty\">";

   for($i=1; $i<11; $i++) {
       $display_block .= "<option value=\"".$i."\">".$i."</option>";
   }

   $display_block .= "
   </select>
   <input type=\"hidden\" name=\"sel_item_id\" value=\"".$_GET["item_id"]."\"/>
   <p><img src=\"cart.jpg\"  width=\"25\" height=\"18\" border=\"0\"><input type=\"submit\" name=\"submit\" value=\"Add to Cart\"/></p>
   </form>
   </td>
   </tr>
   </table>";
    
   $display_block .= "
   
   <table class=\"estilotabla1\" border=\"1\">
<tr>
<th>CLIENTE - USUARIO</font></th>
<th>ADMINISTRADOR</font></th>
</tr>
	</table>";
   
}



//close connection to MySQL
mysqli_close($mysqli);
?>
<html>
<head>
<title>My Store</title>
<link href="estilo2.css" rel="stylesheet" type="text/css" />
</head>
<body>
<?php echo $display_block; ?>
</body>
</html>