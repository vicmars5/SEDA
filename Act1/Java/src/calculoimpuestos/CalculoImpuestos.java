package calculoimpuestos;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.text.DecimalFormat;
import java.util.Scanner;
import javax.swing.JFrame;
import javax.swing.JRootPane;

/**
 * @author UnoCuatro
 * Practica 1
 */
public class CalculoImpuestos {

    
    static final int IVA=16; //Valor del porcentaje del IVA
    static final int ISR=11; //Valor del porcentaje del ISR
    static final int RETENCION_ISR=10; //Valor del porcentaje de la retencion del ISR
    static final int RETENCION_IVA=10; //Valor del porcentaje de la rentencion del IVA
    public static void main(String[] args) {
        int eleccion;
        int mesCaptura;
        String meses[]=new String[12];
        meses[0]="Enero";
        meses[1]="Febrero";
        meses[2]="Marzo";
        meses[3]="Abril";
        meses[4]="Mayo";
        meses[5]="Junio";
        meses[6]="Julio";
        meses[7]="Agosto";
        meses[8]="Septiembre";
        meses[9]="Octubre";
        meses[10]="Noviembre";
        meses[11]="Diciembre";
        
        Scanner sc=new Scanner(System.in);
        
        do{
            System.out.println("\t\tCALCULO DE IMPUESTOS ANUAL");
            System.out.println("Menu principal: ");
            System.out.println("1.-Establecer un mes de captura ");
            System.out.println("1.-Establecer un mes de captura ");
            System.out.println("1.-Establecer un mes de captura ");
            System.out.println("1.-Establecer un mes de captura ");
            eleccion=sc.nextInt();
            switch(eleccion){
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                default:
                    System.out.println("Opcion no valida, intentelo de nuevo");
            }
            calcular();
        }while(eleccion!=7);
    }
    
    private static void calcular(){
        //Variables para tabla recibo honorarios
        float ingreso;
        float iva;
        float subtotal;
        float retencionIsr;
        float retencionIva;
        float total;
        
        //Variables para tabla ganancias
        float gasto;
        float gananciaBruta;
        float isr;
        float gananciaNeta;
        
        //Variables para tabla ISR
        float isrPagar;
        
        //Variables para tabla IVA
        float gastoIva;
        float ivaPagar;
        
        Scanner sc=new Scanner(System.in);
        
        DecimalFormat moneda=new DecimalFormat("$#.##");
        System.out.println("\tCálculo de Impuestos");
        System.out.print("Dame el ingreso: ");
        ingreso=sc.nextFloat(); //Entrada de los ingresos
        System.out.print("Dame el gasto: ");
        gasto=sc.nextFloat(); //Entrada de los gastos
        
        //Procesos para tabla recibo de honorarios
        iva=ingreso*IVA/100;
        subtotal=ingreso+iva;
        retencionIsr=ingreso*RETENCION_ISR/100;
        retencionIva=ingreso*RETENCION_IVA/100;
        total=subtotal-retencionIsr-retencionIva;
        //Procesos para tabla ganancias
        gananciaBruta=ingreso-gasto;
        isr=gananciaBruta*ISR/100;
        gananciaNeta=gananciaBruta-isr;
        //Procesos para tabla ISR
        isrPagar=isr-retencionIsr;
        //Tabla IVA
        gastoIva=gasto*IVA/100;
        ivaPagar=iva-gastoIva-retencionIva;
        
        //Salidas que muestra la tabla recibo de honorarios
        System.out.println("\n\n***Tabla de recibo de honorarios***");
        System.out.println("Ingresos\t"+moneda.format(ingreso));
        System.out.println("(+)IVA\t"+moneda.format(iva));
        System.out.println("(=)Subtotal\t"+moneda.format(subtotal));
        System.out.println("(-)Retencion ISR\t"+moneda.format(retencionIsr));
        System.out.println("(-)Retencion IVA\t"+moneda.format(retencionIva));
        System.out.println("(=)Total\t"+moneda.format(total));
        
        //Salidas que muestra la tabla de ganancias
        System.out.println("\n\n***Tabla de ganancias***");
        System.out.println("Ingresos\t"+moneda.format(ingreso));
        System.out.println("(-)Gastos\t"+moneda.format(gasto));
        System.out.println("(=)Ganancia Bruta\t"+moneda.format(gananciaBruta));
        System.out.println("(-)Retencion ISR\t"+moneda.format(isr));
        System.out.println("(=)Ganancia Neta\t"+moneda.format(gananciaNeta));
        
        //Salidas que muestra la tabla de ISR
        System.out.println("\n\n***Tabla de ISR***");
        System.out.println("ISR\t"+moneda.format(isr));
        System.out.println("(-)ISR Retenido\t"+moneda.format(retencionIsr));
        System.out.println("(=)ISR A Pagar\t"+moneda.format(isrPagar));
        
        //Salidas que muestra la tabla de IVA
        System.out.println("\n\n***Tabla de IVA***");
        System.out.println("IVA\t"+moneda.format(iva));
        System.out.println("(-)Gastos IVA\t"+moneda.format(gastoIva));
        System.out.println("(-)Retencion IVA\t"+moneda.format(retencionIva));
        System.out.println("(=)IVA a pagar\t"+moneda.format(ivaPagar));
        
        System.out.println("\n\nPresiona \"Enter\" para salir");
        //Este codigo hace que el programa espere un enter para continuar
        try{
        System.in.read();
        }
        catch(java.io.IOException e) {
        }
        
    }
    
}
