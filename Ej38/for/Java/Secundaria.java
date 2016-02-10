import java.util.Scanner;

public class Secundaria {

	public static void main(String[] args) {
		int cantAlumnos, edad;
		int cantMayor15=0, cant15=0, cant14=0, cant13=0, cant12=0;
		int cantMuj=0, cantHom=0;
		char sexo;
		boolean	 formValido;
		Scanner sc=new Scanner(System.in);
		System.out.println("Puede indicarme la cantidad de alumnos que ingresara? ");
		cantAlumnos = sc.nextInt();

		for (int i=0; i < cantAlumnos; i++) {
			System.out.println("\tAlumno " + (i+1));
			do{
				System.out.print("Edad: ");
				edad=sc.nextInt();
				if(edad > 0) {
					formValido=true;
				}
				else {
					formValido=false;
				}
			} while(!formValido);
			do{
				System.out.print("Sexo (H/M): ");
				sexo=sc.next().toUpperCase().charAt(0);
				//sexo=toupper(sexo);
				if(sexo == 'H' || sexo == 'M') {
					formValido=true;
				}
				else {
					formValido=false;
				}
			} while(!formValido);
			if(sexo == 'H'){
				cantHom++;
			} else {
				if(sexo == 'M'){
					cantMuj++;
				}
			}

			if(edad > 15) {
				cantMayor15++;
			}
			else {
				if(edad == 15) {
					cant15++;
				}
				else {
					if(edad == 14) {
						cant14++;
					}
					else {
						if(edad == 13) {
							cant13++;
						}
						else {
							if (edad == 12) {
								cant12++;
							}
						}
					}
				}
			}
		}

		System.out.println("\t ESTADISTICAS: \n");
		System.out.println("Sexo");
		System.out.println("Hombres: \t" + cantHom + "\n"
				+ "Mujeres: \t" + cantMuj + "\n");
		System.out.println("Edad" + "\n");
		System.out.println("Doce \t\t" + cant12 + "\n"
				+ "Trece \t\t" + cant13 + "\n"
				+ "Catorce \t" + cant14 + "\n"
				+ "Quince \t\t" + cant15 + "\n"
				+ "Mayor quince \t" + cantMayor15); 
	}	
}