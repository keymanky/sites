import java.applet.Applet;
import java.awt.*;

public class Figura extends Applet 
	{ 
   int r1,r2,r3,r4,r5,r6,r7,r8,rfin;
   Button boton;
   Button boton2;
   Button boton3;
   Button boton4;
   Button boton5;
   Button boton6;
   Button boton7;
   Button boton8;
   Button boton9;
	

public void paint(Graphics g) 
	{    
int x, y, ancho, alto;
    int appletAlto = getSize().height;
    int appletAncho = getSize().width; 
	
    g.setColor(Color.pink);
    g.fillRoundRect(0,190,50,50,10,10);
    g.setColor(Color.blue);
    g.fillRoundRect(50,130,50,50,10,10);  
    g.setColor(Color.yellow);
    g.fillRoundRect(50,250,50,50,10,10);
    g.setColor(Color.green);
    g.fillRoundRect(100,190,50,50,10,10);
    
}

public void init(){
	boton = new Button("Blanco");
	boton2 = new Button("Cafe");
	boton3 = new Button("Rojo");
	boton4 = new Button("Naranja");
	boton5 = new Button("Violeta");
	boton6 = new Button("Negro");
	boton7 = new Button("Amarillo");
	boton8 = new Button("Gris");
	boton9 = new Button("Resultado");
	
	add(boton);
	add(boton2);
	add(boton3);
	add(boton4);
	add(boton5);
	add(boton6);
	add(boton7);
	add(boton8);
	add(boton9);
	
   }

public boolean action(Event evt, Object obj){
	Object quien = evt.target; //Sobre quien ocurrio el evento.
	if (quien == boton){
	   boton.setLabel("Inactivo");
	   boton.enable();
	   boton.setLabel("Inactivo");
	   boton.disable();
		r1=500;
	   return true;
	}
	if (quien == boton2){
	   boton2.setLabel("Inactivo");
	   boton2.enable();
	   boton2.setLabel("Inactivo");
	   boton2.disable();
		r2=-500;
	   return true;
	}	

	if (quien == boton3){
	   boton3.setLabel("Inactivo");
	   boton3.enable();
	   boton3.setLabel("Inactivo");
	   boton3.disable();
		r3=-500;
	   return true;
	}
	if (quien == boton4){
	   boton4.setLabel("Inactivo");
	   boton4.enable();
	   boton4.setLabel("Inactivo");
	   boton4.disable();
		r4=500;
	  }
	if (quien == boton5){
	   boton5.setLabel("Inactivo");
	   boton5.enable();
	   boton5.setLabel("Inactivo");
	   boton5.disable();
		r5=500;
	  }
	if (quien == boton6){
	   boton6.setLabel("Inactivo");
	   boton6.enable();
	   boton6.setLabel("Inactivo");
	   boton6.disable();
		r6=-500;
	  }
	if (quien == boton7){
	   boton7.setLabel("Inactivo");
	   boton7.enable();
	   boton7.setLabel("Inactivo");
	   boton7.disable();
		r7=-500;
	  }
	if (quien == boton8){
	   boton8.setLabel("Inactivo");
	   boton8.enable();
	   boton8.setLabel("Inactivo");
	   boton8.disable();
		r8=500;
	  }
	if (quien == boton9){
	   boton9.setLabel("Resultado");
	   boton9.enable();
	   rfin = r1+r2+r3+r4+r5+r6+r7+r8;
	   //System.out.println(" " + rfin );
	   boton9.setLabel(String.valueOf(rfin));
		  }
	return true;
	}//Fin del método action.
}