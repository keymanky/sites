<?php
    ob_start();
    session_start();
    if($_SESSION['Usuario'] && $_SESSION['Password']){
        //Usuario legitimo
    }
    else
        header('Location: login.php');
?>

<!DOCTYPE HTML>
<html>
<head>
  <meta charset="UTF-8">
  <script type="text/javascript" src="https://www.google.com/jsapi"></script>
  <?php
    include 'scripts/estadisticas.php';
    echo view_ultimo_anio('graphics_anio');
    echo view_horas_pico('hora_pico');
    echo view_time_user('tiempo');
    echo view_recargas('recargas');
  ?>
    <style type="text/css">
        body {
            padding: 40px;
            background-color: #f5f5f5;
            font-family: sans-serif, Arial, Helvetica;
            }
        .redondo{           
            border: 10px solid #e5e5e5;
            -webkit-border-radius: 15px;
            -moz-border-radius: 15px;
            border-radius: 15px;
            -webkit-box-shadow: 0 1px 2px rgba(0,0,0,.05);
            -moz-box-shadow: 0 1px 2px rgba(0,0,0,.05);
            box-shadow: 0 1px 2px rgba(0,0,0,.05);
        }
    </style>
</head>
<body>
            <div id='graphics_anio' class="redondo" style="display: inline-block;"></div>
                <div style="width: 40px; display: inline-block"></div>
            <div id='hora_pico' class="redondo" style="display: inline-block;"></div>
                <div style="width: 40px; display: inline-block"></div>
            <div id='tiempo' class="redondo" style="display: inline-block;"></div>
                <div style="width: 40px; display: inline-block"></div>
            <div id='recargas' class="redondo" style="display: inline-block;"></div>                
            <br/>
            <div style="display: inline-block; text-align: center;" class="redondo">
            <p>
                <?php
                echo "Visitas totales: " . total_visitas() . "<br/>";
                echo "Visitas en la semana: " . total_visitas_semana() . "<br/>";
                echo "Visitas de hoy: " . total_visitas_dia() . "<br/>";                
                ?>
            </p>
            </div>
    </div>
</body>
</html>