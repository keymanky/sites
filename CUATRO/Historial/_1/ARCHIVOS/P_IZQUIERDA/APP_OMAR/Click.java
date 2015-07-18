import java.applet.*;
import java.awt.Graphics;
import java.awt.event.*;

public class Click extends Applet
{ public void init()
     {	addMouseListener(new ClickHandler(this)); }

public void doClick()
	{
	n++;
	repaint();
	}
public void paint (Graphics g)
{    g.drawRect (0, 0, getSize().width-1,getSize().height-1);
	 g.drawString(" CLICK AQUI: "+ n, 5,30);
	}

	private int n=0;
}
class ClickHandler extends MouseAdapter
{  	 ClickHandler (Click ap)
	{   app = ap; }
	public void mouseClicked(MouseEvent e)
	{   app.doClick(); }

	private Click app;
}	

