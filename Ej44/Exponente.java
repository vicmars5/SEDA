import java.util.Scanner;

class Exponente {
	public static double potencia(double numero, int exponente){
		double potencia=1;
		if(exponente<0) {
			for(int i = 0; i > exponente; i--){
				potencia = potencia / numero;
			}
		}
		else {
			if(exponente != 0){
				for(int i = 0; i < exponente; i++){
					potencia *= numero;
				}
			}
		}
		return potencia;
	}
	public static void main(String[] args) {
		double numero;
		int exponente;
		Scanner sc = new Scanner(System.in);
		System.out.print("\tCalculo de exponente\n"
				+ "Numero entero: ");
		numero=sc.nextDouble();
		System.out.print("Exponente: ");
		exponente=sc.nextInt();

		System.out.println("\nPotencia: " + potencia(numero, exponente));
	}
}