import javax.swing.*;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.*;
class Matriz extends JApplet
{

	private double [][]matriz;
	private int n,m,cuadrada;
	public int i,j;
    public Matriz(int nn, int mm)
    {
    	n=nn;
    	m=mm;
    	i=j=0;
    	if(n==m)
    		cuadrada=1;
    	else
    		cuadrada=0;
    	matriz= new double[n][m];
    	for(i=0;i<n;i++)
    		for(j=0;j<m;j++)
    			matriz[i][j]=0;
    }
    public Matriz(int cc)
    {
    	m=n=cc;
    	i=j=0;    	
    	cuadrada=1;
    	matriz= new double[n][m];
    	for(i=0;i<n;i++)
    		for(j=0;j<m;j++)
    			matriz[i][j]=0;
    }
    public void Lee_Matriz()
    {
    	for(i=0;i<n;i++)
    		for(j=0;j<m;j++)
    		{
    			matriz[i][j]=Double.parseDouble(JOptionPane.showInputDialog("Dame el elemento ["+i+"]["+j+"]:  "));
    		}
	}
    public String Imprime()
    {
    	String aux=new String();
    	String aux2= new String();
 		for(i=0;i<n;i++)
 		{
 			for(j=0;j<m;j++)
 			{
 				aux2=matriz[i][j]+"\t\t";
 				aux=aux+aux2;
 			}
 			aux=aux+"\n";
 		}
		if(i==0 || j==0)
			return ("NO VALIDO");
		else
			return aux;
    }
    public Matriz suma(Matriz x)
    {
    	Matriz sum;
    	if(m!=x.m || n!=x.n)
	{
		sum=new Matriz(0);
    		return (Matriz)sum;
	}
    	else
    	{
		sum=new Matriz(n,m);
    		for(i=0;i<n;i++)
    			for(j=0;j<m;j++)
    				sum.matriz[i][j]=matriz[i][j]+x.matriz[i][j];
    		return (Matriz)sum;
    	}
    }
    public Matriz resta(Matriz x)
    {
	Matriz sum;
    	if(m!=x.m || n!=x.n)
	{
		sum= new Matriz(0);
   		return (Matriz)sum;
	}
    	else
    	{
		sum= new Matriz(n,m);
    		for(i=0;i<n;i++)
    			for(j=0;j<m;j++)
    				sum.matriz[i][j]=matriz[i][j]-x.matriz[i][j];
    		return (Matriz)sum;
    	}
    }
    public Matriz multi_escalar(double escalar)
    {
		Matriz res=new Matriz(n,m);
    		for(i=0;i<n;i++)
    			for(j=0;j<m;j++)
    				res.matriz[i][j]=matriz[i][j]*escalar;
    		return (Matriz)res;
    }
    public Matriz multiplicacion(Matriz x)
    {
    	int k,sumas=0;
    	if(m==x.n)
    	{
    		Matriz res=new Matriz (n,x.m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<x.m;j++)
				{
					for(k=0;k<x.n;k++)
					   res.matriz[i][j]=res.matriz[i][j]+(matriz[i][k]*x.matriz[k][j]);
				}	
		}
    			
		return (Matriz)res;    	
	}
    	else
    	{
    		Matriz res= new Matriz(0);
		return (Matriz)res;
    	}
    }
    public Matriz transpuesta()
    {
    	Matriz res=new Matriz(m,n);
    	for(i=0;i<m;i++)
    		for(j=0;j<n;j++)
    			res.matriz[i][j]=matriz[j][i];
	return (Matriz)res;
    }    	    	
}


public class Applet_Matriz extends Applet  implements ActionListener
{
	Matriz M1,M2,M3;
	CheckboxGroup num = new CheckboxGroup ();
	Checkbox una,dos;
	Button b1,sumar,restar,multiplicar,escalar,transponer;
	TextArea hoja,hoja2,resultado;
	public void init()
	{
		una=new Checkbox ("  OPERACIONES CON 1 MATRIZ  ",num,true);
		dos=new Checkbox ("  OPERACIONES CON 2 MATRICES  ",num, false);
		
		b1=new Button("ok");
		b1.addActionListener(this);
		b1.setLocation(500,150);
		
		add(una);
		add(dos);
		add(b1);
		
		
		sumar=new Button("SUMA");
		sumar.addActionListener(this);
		sumar.setLocation(500,100);
		add(sumar);
		
		restar=new Button("RESTA");
		restar.addActionListener(this);
		restar.setLocation(500,150);
		add(restar);
		
		multiplicar=new Button("MULTIPLICA");
		multiplicar.addActionListener(this);
		multiplicar.setLocation(50,200);
		add(multiplicar);
		
		escalar=new Button("MUTIPLICA POR ESCALAR");
		escalar.addActionListener(this);
		escalar.setLocation(50,250);
		add(escalar);
		
		transponer=new Button("TRANSPONE");
		transponer.addActionListener(this);
		transponer.setLocation(50,300);
		add(transponer);
		
		sumar.setEnabled(false);
		transponer.setEnabled(false);
		restar.setEnabled(false);
		multiplicar.setEnabled(false);
		escalar.setEnabled(false);
		hoja= new TextArea();
		add(hoja);
		hoja2= new TextArea();
		add(hoja2);
		resultado= new TextArea();
		add(resultado);
	}

	public void actionPerformed(ActionEvent z)	//z contiene el objeto sobre el evento . En este caso el boton b1
	{
		int n,m;
		double x;
		if(z.getSource()==b1)					//z es sobre el cual susedio el evento
		{
			if (una.equals (num.getSelectedCheckbox ()))
			{
				n=Integer.parseInt(JOptionPane.showInputDialog("Dame filas de la primera matriz"));
				m=Integer.parseInt(JOptionPane.showInputDialog("Dame columnas de la primera matriz"));	
				M1=new Matriz(n,m);
				JOptionPane.showMessageDialog(null,"VA INGRESAR DATOS DE LA PRIMERA MATRIZ");
				M1.Lee_Matriz();
				escalar.setEnabled(true);
				transponer.setEnabled(true);
				sumar.setEnabled(false);
				restar.setEnabled(false);
				multiplicar.setEnabled(false);	
				hoja.insert("\n\n",0);	
				hoja.insert(M1.Imprime(),0);		
			}
			if (dos.equals (num.getSelectedCheckbox ()))
			{
				n=Integer.parseInt(JOptionPane.showInputDialog("Dame filas de la primera matriz"));
				m=Integer.parseInt(JOptionPane.showInputDialog("Dame columnas de la primera matriz"));	
				M1=new Matriz(n,m);
				JOptionPane.showMessageDialog(null,"VA INGRESAR DATOS DE LA PRIMERA MATRIZ");
				M1.Lee_Matriz();
				hoja.insert("\n\n",0);
				hoja.insert(M1.Imprime(),0);
				n=Integer.parseInt(JOptionPane.showInputDialog("Dame filas de la segunda matriz"));
				m=Integer.parseInt(JOptionPane.showInputDialog("Dame columnas de la segunda matriz"));	
				M2=new Matriz(n,m);	
				JOptionPane.showMessageDialog(null,"VA INGRESAR DATOS DE LA SEGUNDA MATRIZ");
				M2.Lee_Matriz();
				escalar.setEnabled(false);
				transponer.setEnabled(false);
				sumar.setEnabled(true);
				restar.setEnabled(true);
				multiplicar.setEnabled(true);
				hoja2.insert("\n\n",0);	
				hoja2.insert(M2.Imprime(),0);				
			}
		}
		if(z.getSource()== sumar)
		{
			M3=M1.suma(M2);
			resultado.insert("\n\n",0);	
			resultado.insert(M3.Imprime(),0);
		}
		if(z.getSource()== restar)
		{
			M3=M1.resta(M2);
			resultado.insert("\n\n",0);	
			resultado.insert(M3.Imprime(),0);
		}
		if(z.getSource()== multiplicar)
		{
			M3=M1.multiplicacion(M2);
			resultado.insert("\n\n",0);	
			resultado.insert(M3.Imprime(),0);
		}
		if(z.getSource()== escalar)
		{
			x=Double.parseDouble(JOptionPane.showInputDialog("Dame el escalar"));
			M3=M1.multi_escalar(x);
			resultado.insert("\n\n",0);	
			resultado.insert(M3.Imprime(),0);
		}
		if(z.getSource()== transponer)
		{
			M3=M1.transpuesta();
			resultado.insert("\n\n",0);	
			resultado.insert(M3.Imprime(),0);
		}						
	}
}








  