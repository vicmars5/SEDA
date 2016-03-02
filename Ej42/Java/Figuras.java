import java.util.Scanner;
import java.lang.Math;

/*
 *Autor:  UnoCuatro
 */
class Figuras {
	private static double areaCirculo() {
		double r;
		Scanner sc=new Scanner(System.in);
		System.out.println("\tCirculo \n"
				+ "Radio: ");
		r=sc.nextDouble();
		
		return Math.PI * Math.pow(r, 2);
	}

	private static double areaCuadrado() {
		double l;

		Scanner sc=new Scanner(System.in);
		
		System.out.print("\tCuadrado\n"
				+ "Lado: ");
		l=sc.nextDouble();
		
		return Math.pow(l, 2);
	}

	private static double areaRectangulo() {
		double b,h;

		Scanner sc=new Scanner(System.in);
		
		System.out.print("\tRectangulo \n"
				+ "Base: ");
		b=sc.nextDouble();
		System.out.print("Altura: ");
		h=sc.nextDouble();
		
		return b * h;
	}

	private static double areaTriangulo() {
		double b,h;

		Scanner sc=new Scanner(System.in);
		
		System.out.print("\tTriangulo \n"
				+ "Base: ");
		b=sc.nextDouble();
		System.out.print("Altura: ");
		h=sc.nextDouble();

		return (b * h) / 2;
	}

	private static void menu(){
		short op;
		double area=0;
		boolean repetir=true;

		Scanner sc=new Scanner(System.in);
		
		do{
			System.out.println("\tCALCULAR AREA DE:\n"
					+ "1.-Circulo\n"
					+ "2.-Cuadrado\n"
					+ "3.-Rectangolo\n"
					+ "4.-Triangulo\n"
					+ "0.-Salir");
			op = sc.nextShort();

			System.out.println("");
			
			switch(op){
				case 1:
					area = areaCirculo();
					break;
				case 2:
					area = areaCuadrado();
					break;
				case 3:
					area = areaRectangulo();
					break;
				case 4:
					area = areaTriangulo();
					break;
			}

			if(op!=0){
				System.out.println("Area: " + area + "\n");
			} else {
				System.out.println("Fin");
				repetir = false;
			};

		}while(repetir);
	}

	public static void main (String[] args){
		menu();
	}
}