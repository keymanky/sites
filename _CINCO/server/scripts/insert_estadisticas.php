<?php
    include('conectar.php');
    include('get_ip.php');      
    date_default_timezone_set('America/Mexico_City');
    $fecha = date('Y-m-d H:i:s');    
    $ip= getIP();
    //Verifica si el usuario ya visto la pagina el mismo dia, si es asi actualiza su fecha y su recarga
    //Si no lo inserta
    $sql = "select * from estadisticas where ip='$ip' and date(fecha_inicial) = date(now())";
    $res = $mysqli->query($sql);
    if($res->num_rows <= 0){
        $sql = "insert into estadisticas (IP, FECHA_INICIAL,RECARGAS) values ('$ip', '$fecha',1)";
        $res = $mysqli->query($sql);
    }
    else{
        //Lo actualiza
        $sql = "update estadisticas set fecha_final=now(),recargas=recargas+1 where ip='$ip' and date(fecha_inicial) = date(now())";
        $res = $mysqli->query($sql);
    }
?>