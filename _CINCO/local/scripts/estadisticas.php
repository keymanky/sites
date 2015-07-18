<?php
    function view_ultimo_anio($iddiv)
    {   
        require('conectar.php');
        include ('transform_month_mes.php');
        date_default_timezone_set('America/Mexico_City');
        $anio = date('Y');
        $sql = "select monthname(fecha_inicial) m,count(id) vm from estadisticas where year(fecha_inicial) ='$anio' group by month(fecha_inicial) order by fecha_inicial";
        $res = $mysqli->query($sql);
        $pantalla .= "
                    <script type=\"text/javascript\">
                         google.load(\"visualization\", \"1\", {packages:[\"corechart\"]});
                         google.setOnLoadCallback(drawChart);
                         function drawChart() {
                           var data = google.visualization.arrayToDataTable([
                             ['Mes', 'Visitas'],";
        while($k = $res->fetch_array())
        {
            $visitas_mes = $k['vm'];
            $mes =  traslate_month($k['m']);
            $pantalla .= "['$mes',$visitas_mes],";
        }
        $pantalla = substr ($pantalla, 0, strlen($pantalla) - 1);
        $pantalla .=       "]);
                
                           var options = {
                            title:'Visitas durante el $anio',
                            colors:['AE34AE'],                           
                            width: 600,
                            height:300,                           
                             hAxis:{title: 'Mes', titleTextStyle: {color: 'black'}}
                           };
                   
                           var chart = new google.visualization.ColumnChart(document.getElementById('$iddiv'));
                           chart.draw(data, options);
                         }
                       </script>
                    ";
        return $pantalla;
    }
    function view_horas_pico($iddiv)
    {
        include 'conectar.php';
        date_default_timezone_set('America/Mexico_City');
        $anio = date('Y');
        $sql = "select count(*) total,case when convert(hour(fecha_inicial),signed) < 12 then 'Manana' when convert(hour(fecha_inicial),signed) < 20 then 'Tarde' else 'Noche' end dia from estadisticas group by dia";
        $res = $mysqli->query($sql);
        $pantalla = "
            <script type=\"text/javascript\">
              google.load('visualization', '1.0', {'packages':['corechart']});
              google.setOnLoadCallback(drawChart);
              function drawChart() {
                var data = new google.visualization.DataTable();
                data.addColumn('string', 'Hora');
                data.addColumn('number', 'Total');
                data.addRows([";
        while($k = $res->fetch_array())
        {
            $visitas = $k['total'];
            $hora =  ($k['dia']);
            $pantalla .= "['$hora',$visitas],";
        }
        $pantalla = substr ($pantalla, 0, strlen($pantalla) - 1);
        $pantalla .= "]);
            var options = {
                           legend:'left',
                           title:'Visitas durante el dia',
                           is3D:true,
                           colors:['#54BB00','#00B3FF','#FF8D00'],                           
                           width:400,
                           height:300};
            var chart = new google.visualization.PieChart(document.getElementById('$iddiv'));
            chart.draw(data, options);
          }
        </script>";
        return $pantalla;
    }
    function view_time_user($iddiv)
    {
        include 'conectar.php';
        date_default_timezone_set('America/Mexico_City');
        $anio = date('Y');
        $sql = "select count(*) total, case when minute(timediff(fecha_final,fecha_inicial)) <0 then 'Permanecio menos de 1 minuto' when minute(timediff(fecha_final,fecha_inicial)) <5  then 'De 1 a 5 minutos' when minute(timediff(fecha_final,fecha_inicial)) >5 then 'Mas de 5 minutos' else 'Solo miro' end tiempo from estadisticas group by tiempo;";        
        $res = $mysqli->query($sql);
        $pantalla = "
            <script type=\"text/javascript\">
              google.load('visualization', '1.0', {'packages':['corechart']});
              google.setOnLoadCallback(drawChart);
              function drawChart() {
                var data = new google.visualization.DataTable();
                data.addColumn('string', 'Tiempo minutos');
                data.addColumn('number', 'Total');                
                data.addRows([";
        while($k = $res->fetch_array())
        {
            $visitas = $k['total'];
            $tiempo =  ($k['tiempo']);
            $pantalla .= "['$tiempo',$visitas],";
        }
        $pantalla = substr ($pantalla, 0, strlen($pantalla) - 1);
        $pantalla .= "]);
            var options = {
                           legend:'left',
                           title:'Minutos que permanecio en la pagina',
                           is3D:true,            
                           width:400,
                           height:300};
            var chart = new google.visualization.PieChart(document.getElementById('$iddiv'));
            chart.draw(data, options);
          }
        </script>";
        return $pantalla;
    }
    function view_recargas($iddiv)
    {
        include 'conectar.php';
        date_default_timezone_set('America/Mexico_City');
        $sql = "select recargas , count(recargas) total from estadisticas group by recargas";        
        $res = $mysqli->query($sql);
        $pantalla = "
                        <script type=\"text/javascript\">
                                google.load(\"visualization\", \"1\", {packages:[\"corechart\"]});
                                google.setOnLoadCallback(drawChart);
                                function drawChart() {
                                  var data = google.visualization.arrayToDataTable([
                                    ['# Paginas', 'Frecuencia'],";

        while($k = $res->fetch_array())
        {
            $total = $k['total'];
            $recargas =  $k['recargas'];
            $pantalla .= "['$recargas',$total],";
        }
        $pantalla = substr ($pantalla, 0, strlen($pantalla) - 1);
        $pantalla  .="]);
                                  var options = {
                                    title: 'Paginas visitadas por usuario',
                                    colors:['#F7FF00'],                           
                                    width: 600,
                                    height:300,                           
                                    hAxis:{title: 'Paginas', titleTextStyle: {color: 'black'}},
                                    vAxis:{title: 'Frecuencia', titleTextStyle: {color: 'black'}}
                                  };
                                  var chart = new google.visualization.LineChart(document.getElementById('$iddiv'));
                                  chart.draw(data, options);
                                }
                        </script>
                    ";
        return $pantalla;
    }        
    function total_visitas()
    {
        include 'conectar.php';        
        $sql = "select count(id) total from estadisticas";
        $res = $mysqli->query($sql);
        $k= $res->fetch_array();
        return $k['total'];
    }
    function total_visitas_semana()
    {
        include 'conectar.php';
        date_default_timezone_set('America/Mexico_City');        
        $dia = date('z');
        $sql = "select count(id) total from estadisticas where dayofyear(fecha_inicial)-7 < $dia and dayofyear(fecha_inicial)+7 > $dia ";
        $res = $mysqli->query($sql);
        $k= $res->fetch_array();
        return $k['total'];
    }
    function total_visitas_dia()
    {
        include 'conectar.php';
        date_default_timezone_set('America/Mexico_City');        
        $dia = date("Y-m-d");
        $sql = "select count(id) total from estadisticas where date_format(fecha_inicial,'%Y-%m-%d') = '$dia'";
        $res = $mysqli->query($sql);
        $k= $res->fetch_array();
        return $k['total'];
    }
?>