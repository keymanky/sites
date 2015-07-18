<?php
    ob_start();
    session_start();
    //Valida el usuario
    switch (inicia_sesion($_POST['Usuario'],$_POST['Password']))
    {
        case -1 :  //Error de autentificacion
        case 0  :  //No existan o se la primera vez
            {
                if(inicia_sesion($_POST['Usuario'],$_POST['Password']) == 0)
                    pantalla();
                else
                    pantalla(" Error de Autentificacion");
                break;
            }
        case 1://Exito
            {
                $_SESSION['Usuario'] = $_POST['Usuario'];
                $_SESSION['Password'] = $_POST['Password'];
                header('Location: view-estadisticas.php');
            }
    }
    
    
    //Verifica en la base
    function inicia_sesion($user,$pass)
    {
        include('scripts/conectar.php');
        if($user && $pass){
        $sql = "select * from usuarios where nombre = '$user' and Password = '$pass'";
        $res = $mysqli->query($sql);
        if($res->num_rows == 1)
            return 1;
        else
            return -1;
        }
        else
            return 0;
    }
    //Muestra el formulario
    function pantalla($mensaje=" ")
    {
        echo '
        <!DOCTYPE html>
            <html lang="en">
              <head>
                <meta charset="utf-8">
                <title>Sign in &middot; Twitter Bootstrap</title>
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <meta name="description" content="">
                <meta name="author" content="">
            
                <link href="librery/bootstrap/css/bootstrap.min.css" rel="stylesheet">
                <style type="text/css">
                  body {
                    padding-top: 40px;
                    padding-bottom: 40px;
                    background-color: #f5f5f5;
                  }

                .form-signin {
                  max-width: 300px;
                  padding: 19px 29px 29px;
                  margin: 0 auto 20px;
                  background-color: #fff;
                  border: 1px solid #e5e5e5;
                  -webkit-border-radius: 5px;
                     -moz-border-radius: 5px;
                          border-radius: 5px;
                  -webkit-box-shadow: 0 1px 2px rgba(0,0,0,.05);
                     -moz-box-shadow: 0 1px 2px rgba(0,0,0,.05);
                          box-shadow: 0 1px 2px rgba(0,0,0,.05);
                }
                .form-signin .form-signin-heading,
                .form-signin .checkbox {
                  margin-bottom: 10px;
                }
                .form-signin input[type="text"],
                .form-signin input[type="password"] {
                  font-size: 16px;
                  height: auto;
                  margin-bottom: 15px;
                  padding: 7px 9px;
                }
              </style>
              <link href="librery/bootstrap/css/bootstrap-responsive.css" rel="stylesheet">
              <!-- HTML5 shim, for IE6-8 support of HTML5 elements -->
              <!--[if lt IE 9]>
                <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
              <![endif]-->
              
            </head>

            <body>
              <div class="container" style="text-align: center">
                      <form class="form-signin" action="login.php" method="post">
                        <h2 class="form-signin-heading">Iniciar Sesi&oacute;n</h2>
                        <input type="text" class="input-block-level" placeholder="Usuario" name="Usuario"/>
                        <input type="password" class="input-block-level" placeholder="Password" name="Password"/>            
                        <button class="btn btn-large btn-primary" type="submit">Iniciar</button>' . $mensaje .
                      '</form>
              </div>
          
          
            </body>
        </html>';
    }
?>