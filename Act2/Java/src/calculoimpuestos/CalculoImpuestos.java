package calculoimpuestos;

import java.text.DecimalFormat;

/**
 * @author UnoCuatro - Díaz Méndez Víctor Agustín
 * Tiempo 2:36
 */
public class CalculoImpuestos {

    
    static final int IVA=16; //Valor del porcentaje del IVA
    static final int ISR=11; //Valor del porcentaje del ISR
    static final int RETENCION_ISR=10; //Valor del porcentaje de la retencion del ISR
    static final int RETENCION_IVA=10; //Valor del porcentaje de la rentencion del IVA
    static final short CANT_MESES=12; //Cantidad de meses del año
    
    public static void main(String[] args) {
        DecimalFormat moneda=new DecimalFormat("$#.##");
        
        //Variables para entrada de datos***************************
        short eleccion;//Variable para indice del menu principal
        short eleccionMes;//Variable para indide del menu meses
        float ingresoMes; //Gasto del mes que se esta trabajando
        float gastoMes; //Gasto del mes que se esta trabajando
        short mes; //Indice del mes seleccionado
        
        //Variables de computo**************************************
        boolean valido; //Variable para validaciones
        String[] meses=new String[12]; //Nombres de los meses
        //Ingresos
        float ingresoAnual;
        float ingresosMeses[]=new float[12];
        //Gastos
        float gastoAnual;
        float gastosMeses[]=new float[12];
        //Variables para tabla recibo honorarios
        float iva;
        float subtotal;
        float retencionIsr;
        float retencionIva;
        float total;
        //Variables para tabla ganancias
        float gananciaBruta;
        float isr;
        float gananciaNeta;
        //Variables para tabla ISR
        float isrPagar;
        //Variables para tabla IVA
        float gastoIva;
        float ivaPagar;
        //Definicion de meses
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
        
        mes=0; //Enero, mes seleccionado por defecto
        
        do{
            
            System.out.println("\t\tCÁLCULO DE IMPUESTOS ANUAL\n" //Muestra acentos
                    +"Menú principal: \n"
                    +"1.-Establecer mes de captura (mes actual es " + meses[mes] +")\n"
                    +"2.-Captura de ingresos\n"
                    +"3.-Captura de gastos\n"
                    +"4.-Mostrar lista de ingresos anual\n"
                    +"5.-Mostrar lista de gastos anual\n"
                    +"6.-Cálculo de impuestos anual\n"
                    +"7.-Salir\n\n"
                    +"Opción: ");
            eleccion=(short) ScanF.leeInt(); //Opcion ingresada por el usuario
            System.out.println("\n\n");
            switch(eleccion){
                case 1:
                    do{
                        
                        System.out.println("Establecer mes de captura");
                        
                        for(short i=0; i<CANT_MESES; i++){
                            System.out.println((i+1)+".-"+meses[i]);
                        }
                        
                        System.out.print("Elige el mes (1-12): ");
                        eleccionMes=(short) ScanF.leeInt();
                        
                        
                        if(!(1<=eleccionMes && eleccionMes<=12)){
                            System.out.println("ELECCIÓN NO VALIDA, INTENTELO DE NUEVO");
                            valido=false;
                        }
                        else{
                            valido=true;
                        }
                        
                    }while(!valido);
                    
                    mes=(short) (eleccionMes-1);                    
                    
                    System.out.println("Se ha establecido el mes de captura en " + meses[mes] +"\n"
                            + "Presione entrar para continuar ...");
                    ScanF.get();
                    
                    break;
                case 2:
                    do{
                        System.out.println("Captura de ingresos");
                        System.out.println("Dame el ingreso del mes de " + meses[mes]);
                        ingresoMes=ScanF.leeFloat(); //Entrada, ingreso del mes seleccionado
                        
                        if(ingresoMes<0){
                            System.out.println("VALOR NO VALIDO, INTENTELO DE NUEVO");
                            valido=false;
                        }
                        else{
                            valido=true;
                        }
                        
                    }while(!valido);
                    
                    ingresosMeses[mes]=ingresoMes;
                    
                    System.out.println("Presione entrar para continuar ...");
                    ScanF.get();
                    break;
                case 3:
                    do{
                        
                        System.out.println("Captura de gastos");
                        System.out.println("Dame el gasto del mes de " + meses[mes]);
                        gastoMes=ScanF.leeFloat();//Entrada, gasto del mes seleccionado
                        
                        if(gastoMes<0){
                            System.out.println("VALOR NO VALIDO, INTENTELO DE NUEVO");
                            valido=false;
                        }
                        else{
                            valido=true;
                        }
                        
                    }while(!valido);
                    
                    gastosMeses[mes]=gastoMes;
                    
                    System.out.println("Presione entrar para continuar ...");
                    ScanF.get();
                    
                    break;
                    
                    case 4:

                        System.out.println("Mostrar lista de ingresos anual");

                        for(int i=0; i<CANT_MESES; i++){
                            //Muestra el ingreso del mes en la posición "i"
                            System.out.println(meses[i]+" = " + moneda.format(ingresosMeses[i]));
                        }

                        System.out.println("Presione entrar para continuar ...");
                        ScanF.get();

                        break;
                case 5:
                    
                    System.out.println("Mostrar lista de gastos anual");
                    
                    for(int i=0; i<CANT_MESES; i++){
                        //Muestra el gasto del mes en la posición "i"
                        System.out.println(meses[i]+" = " + moneda.format(gastosMeses[i]));
                    }
                    
                    System.out.println("Presione entrar para continuar ...");
                    ScanF.get();
                    
                    break;
                case 6:
                    
                    ingresoAnual=0;
                    gastoAnual=0;
                    
                    for (short i=0; i<CANT_MESES; i++){
                        ingresoAnual+=ingresosMeses[i];
                        gastoAnual+=gastosMeses[i];
                    }
                    
                    System.out.println("\tCálculo de impuestos anual");

                    //Procesos para tabla recibo de honorarios
                    iva=ingresoAnual*IVA/100;
                    subtotal=ingresoAnual+iva;
                    retencionIsr=ingresoAnual*RETENCION_ISR/100;
                    retencionIva=ingresoAnual*RETENCION_IVA/100;
                    total=subtotal-retencionIsr-retencionIva;
                    
                    //Procesos para tabla ganancias
                    gananciaBruta=ingresoAnual-gastoAnual;
                    isr=gananciaBruta*ISR/100;
                    gananciaNeta=gananciaBruta-isr;
                    
                    //Procesos para tabla ISR
                    isrPagar=isr-retencionIsr;
                    
                    //Tabla IVA
                    gastoIva=gastoAnual*IVA/100;
                    ivaPagar=iva-gastoIva-retencionIva;
                    
                    //Salidas*********
                    
                    //Salidas que muestra la tabla recibo de honorarios
                    System.out.println("\n\n***Tabla de recibo de honorarios***");
                    System.out.println("Ingresos\t"+moneda.format(ingresoAnual));
                    System.out.println("(+)IVA\t"+moneda.format(iva));
                    System.out.println("(=)Subtotal\t"+moneda.format(subtotal));
                    System.out.println("(-)Retención ISR\t"+moneda.format(retencionIsr));
                    System.out.println("(-)Retención IVA\t"+moneda.format(retencionIva));
                    System.out.println("(=)Total\t"+moneda.format(total));

                    //Salidas que muestra la tabla de ganancias
                    System.out.println("\n\n***Tabla de ganancias***");
                    System.out.println("Ingresos\t"+moneda.format(ingresoAnual));
                    System.out.println("(-)Gastos\t"+moneda.format(gastoAnual));
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

                    System.out.println("\n\nPresione entrar para continuar ...");
                    ScanF.get();
                    
                    break;
                case 7:
                    break;
                default:
                    System.out.println("\t OPCIÓN NO VALIDA, INTENTELO DE NUEVO");
            }
        }while(eleccion!=7);
    }
    
}
