import java.util.Scanner;

/*
 *Autor UnoCuatro
 */

class Matrices {
	private static Scanner sc;

	private static final int TAM_MATRIZ = 3;
	private static final  int MATRICES = 3;
	private static int cantCeldas;
	
	private static int[][][] matrices= new int[MATRICES][TAM_MATRIZ][TAM_MATRIZ]; //Definicion de las tres matrices

	public static void main(String [] args){
		sc=new Scanner(System.in);
		int inicio;
		cantCeldas = (TAM_MATRIZ*TAM_MATRIZ);

		System.out.println("\tMultiplicación matricial \n"
				+"Valor inicial: ");
		inicio=sc.nextInt();
		System.out.print("\n\n");

		inicializa(inicio);
		multiplicarMatrices();
		mostrarMatrices();
	}

	private static void inicializa(int inicio) {
		int valor = inicio;
		int i, j;

		for (i = 0; i < TAM_MATRIZ; i++){
			for (j = 0; j < TAM_MATRIZ; j++){
				matrices[0][i][j]=valor;
				matrices[1][i][j]=valor+cantCeldas;
				valor++;
			}
		}
	}

	private static void mostrarMatrices() {
	    int i, j, mat;
	    for (mat = 0; mat < MATRICES; mat++){
	        System.out.println("\tMatriz " + (mat+1) + ":");
	        for (i=0; i < TAM_MATRIZ; i++){
	            System.out.print("\t");
	            for(j=0; j < TAM_MATRIZ; j++){
	                System.out.print(matrices[mat][i][j] + " ");
	            }
	            System.out.print("\n");
	        }
	        if(mat==0)        {
	            System.out.print("\n\t    *\n");
	        }
	        else
	        {
	            if(mat==1)
	            {
		            System.out.print("\n\t    =\n");
	            }
	        }
	        System.out.print("\n");
	    }
	}

	private static void multiplicarMatrices() {
		int i, j, k, mat=0;
		int suma=0;
		for (i=0; i < TAM_MATRIZ; i++)
		{
		    for(j=0; j < TAM_MATRIZ; j++)
		    {
		        for(k=0; k < TAM_MATRIZ; k++)
		        {
		            suma+=matrices[0][j][k]*matrices[1][k][i];
		        }
		        matrices[2][j][i]=suma;
		        suma=0;
		    }
		}
		mat++;
	}
}