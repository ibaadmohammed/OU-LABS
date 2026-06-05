import java.util.StringTokenizer;
import java.util.Scanner; 
public class Lineofint
{ 
public static void main(String args[])
{ 
Scanner scan = new Scanner(System.in);
String s = scan.next();
 StringTokenizer st = new StringTokenizer(s," "); 
 while (st.hasMoreTokens()) 
{ 
 System.out.println(st.nextToken()); 
 } } } 
