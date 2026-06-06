// Demonstrate color.
import java.awt.*;
import java.applet.*;
/*
<applet code="ColorDemo" width=300 height=200>
</applet>
*/
public class ColorDemo extends Applet {
// draw lines
public void paint(Graphics g) {
Color c1 = new Color(255, 100, 100);
Color c2 = new Color(100, 255, 100);
Color c3 = new Color(100, 100, 255);
g.setColor(c1);
g.drawLine(20, 10, 20, 50);
g.setColor(c2);
g.drawLine(40, 10, 40, 50);
g.setColor(c3);
g.drawLine(60,10, 60, 50);
g.setColor(Color.red);
g.drawOval(30, 90, 40, 40);
g.fillOval(80, 90, 40, 40);
g.setColor(Color.blue);
g.drawRect(130, 90, 40, 40);
g.fillRect(190, 90, 40, 40);
g.setColor(Color.cyan);
g.drawRoundRect(100, 150, 50, 50, 15, 15);
g.fillRoundRect(170, 150, 50, 50, 15, 15);
}
}
