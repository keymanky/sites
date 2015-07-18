<?php

			//variables de conecion
			include("conectar.php");
			//conectamos a la base de datos
			$mysqli = mysqli_connect($servidor , $usuario , $contrasena , $base_datos);
$display_block = "<h1>Categorias</h1>
<p><h2>Seleccione una categoria para ver los productos.</h2><h3></p>";
$get_cats_sql = "SELECT id, cat_title, cat_desc FROM store_categories ORDER BY cat_title";
$get_cats_res =  mysqli_query($mysqli, $get_cats_sql) or die(mysqli_error($mysqli));

if (mysqli_num_rows($get_cats_res) < 1) {
   $display_block = "<p><em>Lo sentimos, por el momento no tenemos disponible.</em></p>";
} else {
   while ($cats = mysqli_fetch_array($get_cats_res)) {
        $cat_id  = $cats['id'];
        $cat_title = strtoupper(stripslashes($cats['cat_title']));
        $cat_desc = stripslashes($cats['cat_desc']);

        $display_block .= "<p><strong><a href=\"".$_SERVER["PHP_SELF"]."?cat_id=".$cat_id."\">".$cat_title."</a></strong><br/>".$cat_desc."</p>";

        if (isset($_GET["cat_id"])) {
			if ($_GET["cat_id"] == $cat_id) {
			   //get items
			   $get_items_sql = "SELECT id, item_title, item_price FROM store_items WHERE cat_id = '".$cat_id."' ORDER BY item_title";
			   $get_items_res = mysqli_query($mysqli, $get_items_sql) or die(mysqli_error($mysqli));

			   if (mysqli_num_rows($get_items_res) < 1) {
					$display_block = "<p><em>Lo sentimos, por el momento no tenemos disponible.</em></p>";
			   } else {
					$display_block .= "<ul>";

					while ($items = mysqli_fetch_array($get_items_res)) {
					   $item_id  = $items['id'];
					   $item_title = stripslashes($items['item_title']);
					   $item_price = $items['item_price'];

					   $display_block .= "<li><a href=\"showitem.php?item_id=".$item_id."\">".$item_title."</a></strong> (\$".$item_price.")</li>";
					}

					$display_block .= "</ul>";
				}

				//free results
				mysqli_free_result($get_items_res);

			}
		}
	}
}
//free results
mysqli_free_result($get_cats_res);

//close connection to MySQL
mysqli_close($mysqli);
?>
<html>
<head>
<title>My Categories</title>
	<link href="estilo1.css" rel="stylesheet" type="text/css" />
</head>
<body>
<?php echo $display_block; ?>
</body>
</html>
