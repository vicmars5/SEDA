package calculoimpuestos;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Scanner;
import javax.swing.JFrame;
import javax.swing.JRootPane;

/**
 * @author vic
 */
public class CalculoImpuestos {

    
    static final int IVA=16; //Valor del porcentaje del IVA
    static final int ISR=11; //Valor del porcentaje del ISR
    static final int RETENCION_ISR=10; //Valor del porcentaje de la retencion del ISR
    static final int RETENCION_IVA=10; //Valor del porcentaje de la rentencion del IVA

    public static void main(String[] args) {
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
        System.out.println("Ingresos\t"+ingreso);
        System.out.println("(+)IVA\t"+iva);
        System.out.println("(=)Subtotal\t"+subtotal);
        System.out.println("(-)Retencion ISR\t"+retencionIsr);
        System.out.println("(-)Retencion IVA\t"+retencionIva);
        System.out.println("(=)Total\t"+total);
        
        //Salidas que muestra la tabla de ganancias
        System.out.println("\n\n***Tabla de ganancias***");
        System.out.println("Ingresos\t"+ingreso);
        System.out.println("(-)Gastos\t"+gasto);
        System.out.println("(=)Ganancia Bruta\t"+gananciaBruta);
        System.out.println("(-)Retencion ISR\t"+isr);
        System.out.println("(=)Ganancia Neta\t"+gananciaNeta);
        
        //Salidas que muestra la tabla de ISR
        System.out.println("\n\n***Tabla de ISR***");
        System.out.println("ISR\t"+isr);
        System.out.println("(-)ISR Retenido\t"+retencionIsr);
        System.out.println("(=)ISR A Pagar\t"+isrPagar);
        
        //Salidas que muestra la tabla de IVA
        System.out.println("\n\n***Tabla de IVA***");
        System.out.println("IVA\t"+iva);
        System.out.println("(-)Gastos IVA\t"+gastoIva);
        System.out.println("(-)Retencion IVA\t"+retencionIva);
        System.out.println("(=)IVA a pagar\t"+ivaPagar);
        
        System.out.println("\n\nPresiona \"Enter\" para salir");
        //Este codigo hace que el programa espere un enter para continuar
        try{
        System.in.read();
        }
        catch(java.io.IOException e) {}
    }
    
}
