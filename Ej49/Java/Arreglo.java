import java.util.Scanner;
import java.util.Random;

class Arreglo {
	public static void main(String [] args){
		int tam = 4;
		int[] vect = new int[tam];
		Random rnd = new Random();
		System.out.println("Valores de arreglo: ");

		for (int i = 0; i < tam; i++){
			vect[i] = rnd.nextInt(101);
			System.out.println("Valor " + i + ": " + vect[i]);
		}

		System.out.print("\n");

		System.out.println("Valor menor: " + encontrarMenor(vect, tam));
	}

	public static int encontrarMenor(int vect[], int tam){
		int menor = vect[0];
		for (int i = 1; i < tam; i++){
			if (vect[i] < menor){
				menor = vect[i];
			}
		}
		return menor;
	}
}