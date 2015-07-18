var x = -300,y=0,derecha = true;
var canvas,contexto,avanzar=false,perdido=false,ganado=false;
var bola,colores=true,teclado = false;
var ooox=1,oox=300,oderecha=true,ooderecha=false;
var x2=0,centrox=0,centroy=-420,xx=0,yy=0;

document.onkeydown = function (event){
var keycode = (window.event||event).keyCode;
	switch(keycode){
	case 13:
		if(!teclado)
			setInterval("dibujar_bola()",20);
		teclado = true;					
		break;
	case 38:
		avanzar =true;
		break;
	}
}

function init(){
		canvas = document.getElementById("canvas");
		if(canvas.getContext){
			contexto = canvas.getContext("2d");
			bola = new Image();
			bola.src = "bola.png";
			bola.onload = function(){
				//setInterval("dibujar_bola()",20);
				bienvenida();
			}
		}
	}
function dibujar_bola(){
	canvas.width = canvas.width;	
	if(!avanzar)
	{
		y = Math.sqrt((1-((x*x)/122500))*22500);
		if(x== 300)
		  derecha=false;
		if(x== -300)
		  derecha = true;
		if(derecha)
		  x+=25;
		else
		  x-=25;	  
		contexto.drawImage(bola,x+300,y+220);		  
	}
	else
	{
		 if(!ganado)
		 	yy-=parseInt(Math.random()*3);
    	 xx=(((yy-centroy)/(y-centroy))*(x-centrox))+centrox;		 
		 if(yy+340<100)
		 {
	      ganado = true;
		  ganaste();
		 }
		 else
		 {
			if((yy+340 <= 310 && yy+340 >= 290))
			{
			  if((xx+300<oox+200 && xx+300>oox+100) || (xx+300<oox+100 && xx+300+50>oox+100) || (xx+300>oox+200 && xx+300-10<oox+200))
			  {   
				ganado=true;
				perdiste();
			  }
			}	
			
			if((yy+340 <= 210 && yy+340 >= 190))
			{
			  if((xx+300<ooox+200 && xx+300>ooox+100) || (xx+300<ooox+100 && xx+300+50>ooox+100) || (xx+300>ooox+200 && xx+300-10<ooox+200))
			  {
				ganado=true;
				perdiste(); 
			  }
			}    	
			if(!ganado)
				contexto.drawImage(bola,xx+300,yy+340);		 
		 }
	}
	if(!ganado)
	{
		bolos(220,45);
		bolos(240,50);
		bolos(260,60);
		bolos(280,50);
		bolos(300,45);
		bolos(320,40);
		bolos(1000,1000); //->Dummy
		obstaculos();
		bolos2(1000,1000); //->Dummy		
		escenario();	
	}
}
function bolos(xx, yy){        
  contexto.moveTo(xx+15,yy+30);
  contexto.lineTo(xx+30,yy+30);
  contexto.strokeStyle = 'red';
  //contexto.lineWidth= 2;	
  contexto.stroke();
  drawEllipse(contexto,xx+10,yy-10,19,59);
  drawEllipse(contexto,xx,yy+30,40,59);      
}
function escenario(){
   if(colores)
   	   contexto.strokeStyle = 'yellow';  
   else
       contexto.strokeStyle = 'rgb(255,247,150)';
   colores = !colores;	   
   contexto.moveTo(0,420);
   contexto.lineTo(220,0);
   contexto.moveTo(380,0);
   contexto.lineTo(600,420);
   contexto.lineWidth= 15;	    
   contexto.stroke();   
}
function obstaculos(){
 //Linea Grande 
  contexto.moveTo(ooox+100,200);
  contexto.lineTo(ooox+200,200);
  contexto.strokeStyle = "#0FFF29";
  contexto.lineWidth = 5;  
  contexto.stroke();
  if(oderecha)
    ooox++;
  else
    ooox--;
  if(ooox == 300)
    oderecha = false;
  if(ooox == 0)
    oderecha = true;
  //Linea chica	
  contexto.moveTo(oox+100,300);
  contexto.lineTo(oox+200,300);
  contexto.stroke();  
  if(ooderecha)
    oox+=parseInt((Math.random()*15)+5);
  else
    oox-=parseInt((Math.random()*10)+3);;
  if(oox >= 300)
    ooderecha = false;
  if(oox <= 0)
    ooderecha = true;	
}	
//-->Dummy, porque, porq parece q el ultimo strokeStyle pinta al inmediato anterior.
function bolos2(xx, yy){        
  contexto.moveTo(xx+15,yy+30);
  contexto.lineTo(xx+30,yy+30);
  contexto.strokeStyle = "#0FFF29";;
  //contexto.lineWidth= 2;	
  contexto.stroke();
  drawEllipse(contexto,xx+10,yy-10,19,59);
  drawEllipse(contexto,xx,yy+30,40,59);      
}
function bienvenida(){
    contexto.fillStyle = 'white';
    contexto.font = '14px Verdana';
    contexto.fillText('BOLOS ACATLAN',250,50); 
    contexto.fillText('Trate de tirar los bolos',245,75);	
    contexto.fillText('Oprima la tecla UP o fecla de arriba',195,150);	
    contexto.fillText('Cuando este seguro de poder hacerlo',190,175);	
    contexto.fillText('Cuidado con los gusanos Verdes',200,200);	
    contexto.fillText('Te pican',290,225);	
    contexto.fillText('Oprima ENTER',270,275);	
    contexto.fillText('La velocidad de la pelota es aleatoria',195,300);						
}
function ganaste(){
    contexto.fillStyle = 'white';
    contexto.font = '14px Verdana';
    contexto.fillText('Felicidades Ganaste !!!',250,300);	
	document.getElementById('musica_inicial').pause();
	document.getElementById('musica_gano').play();							
}
function perdiste(){
    contexto.fillStyle = 'white';
    contexto.font = '14px Verdana';
    contexto.fillText('Perdio suerte para la proxima',180,100); 
	document.getElementById('musica_inicial').pause();
	document.getElementById('musica_perdio').play();
}
//Codigo de la ellipse obtenido de: http://stackoverflow.com/questions/2172798/how-to-draw-an-oval-in-html5-canvas
function drawEllipse(ctx, x, y, w, h) {
  var kappa = .5522848;
      ox = (w / 2) * kappa, // control point offset horizontal
      oy = (h / 2) * kappa, // control point offset vertical
      xe = x + w,           // x-end
      ye = y + h,           // y-end
      xm = x + w / 2,       // x-middle
      ym = y + h / 2;       // y-middle

  ctx.beginPath();       
  ctx.moveTo(x, ym);
  ctx.bezierCurveTo(x, ym - oy, xm - ox, y, xm, y);
  ctx.bezierCurveTo(xm + ox, y, xe, ym - oy, xe, ym);
  ctx.bezierCurveTo(xe, ym + oy, xm + ox, ye, xm, ye);
  ctx.bezierCurveTo(xm - ox, ye, x, ym + oy, x, ym);
  ctx.closePath();
  //ctx.strokeStyle = 'white';  
  // ctx.lineWidth= 2;	  
  ctx.fillStyle = 'white';
  ctx.fill();   
  ctx.stroke();
}