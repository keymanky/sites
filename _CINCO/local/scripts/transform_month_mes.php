<?
    function traslate_month($month)
    {
        switch ($month){
            case 'January':
                $r = 'Enero';
                break;
            case 'February':
                $r = 'Febrero';
                break;
            case 'March':
                $r = 'Marzo';
                break;
            case 'April':
                $r = 'Abril';
                break;
            case 'May':
                $r = 'Mayo';
                break;
            case 'June':
                $r = 'Junio';
                break;
            case 'July':
                $r = 'Julio';
                break;
            case 'August':
                $r = 'Agosto';
                break;
            case 'September':
                $r = 'Septiembre';
                break;
            case 'October':
                $r = 'Octubre';
                break;
            case 'November':
                $r = 'Noviembre';
                break;
            case 'December':
                $r = 'Diciembre';                
        }
        return $r;
    }
?>