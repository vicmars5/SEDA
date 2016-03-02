import java.util.Scanner;
/*
 *
 *Autor:  UnoCuatro
*/

class MultiplosYSumas {
	public static void main(String[] args){
	 	int i,j,k;
	 	int suma, producto;
	 	String lineaS, lineaP;

	 	Scanner sc=new Scanner(System.in);
	 	System.out.print("Dame un numero");
	 	k=sc.nextInt();
	 	System.out.println("");

	 	for(i = 1; i <= k; i++){
	 		suma=0;
                        lineaS = "";
                        lineaP = "";
	 		
	 		lineaS=lineaS + " " + i + " ";
	 		lineaP=lineaP + " " + i + " ";
			suma+=i;
	 		producto=i;
	 		
	 		for(j = 2; j <= i; j++){
		 		lineaS=lineaS + "+ " + i + " ";
		 		lineaP=lineaP + "* " + i + " ";
		 		suma+=i;
		 		producto*=i;
	 		}
	 		lineaS=lineaS + "= " + suma + ", ";
	 		lineaP=lineaP + "= " + producto;
                        System.out.println(lineaS + lineaP);
	 	}
	}
}