import java.util.Scanner;

class NumerosDiferentes {
	public static void main(String [] args){
		int tam = 10;
		int[] vect=new int[tam];

		Scanner sc=new Scanner(System.in);
		System.out.println("Valores del arreglo");
		
		for (int i = 0; i < tam; i++) {
			System.out.print("Valor [" + (i+1) + "]:");
			vect[i] = sc.nextInt();
		}

		System.out.print("\n");
		if(numerosDiferentes(vect, tam)){
			System.out.println("Todos los numeros son diferentes.");
		} else {
			System.out.println("Hay numeros repetidos en el arreglo.");
		}
	}

	public static boolean numerosDiferentes(int vect[], int tam){
		for (int i = 0; i < tam; i++){
			for (int j = i+1; j < tam; j++){
				if (vect[i] == vect[j]){
					return false;
				}
			}
		}
		return true;
	}
}