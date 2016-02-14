import java.util.Scanner;

public class TercerEntero {
	private static final int MAXIMO = 100;
	public static void main(String[] args){
		int i;
		int suma=0;
		for (i=2; i < MAXIMO; i+=3) {
			suma+=i;
		}
		System.out.println("\tSuma de cada tercer entero desde el dos");
		System.out.println("Suma: " + suma);
	}
}