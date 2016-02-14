#include <string>
#include <iostream>
#include <cmath>
#define IVA 16
#define ISR 11
#define RETENCION_ISR 10
#define RETENCION_IVA 10
#define CANT_MESES 12

using namespace std;

/**
 * @author UnoCuatro - Díaz Méndez Víctor Agustín
 * Tiempo 0:50
 */

int main (){
    
    //Variables para entrada de datos***************************
    short eleccion;//Variable para indice del menu principal
    short eleccionMes;//Variable para indide del menu meses
    float ingresoMes; //Gasto del mes que se esta trabajando
    float gastoMes; //Gasto del mes que se esta trabajando
    short mes; //Indice del mes seleccionado
    
    //Variables de computo**************************************
    bool valido; //Variable para validaciones
    string meses[12]; //Nombres de los meses
    //Ingresos
    float ingresoAnual;
    float ingresosMeses[12];
    //Gastos
    float gastoAnual;
    float gastosMeses[12];
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
        cout <<"\t\tCALCULO DE IMPUESTOS ANUAL " << endl
            << "Menú principal" << endl
            << "1.-Establecer mes de captura (mes actual es " + meses[mes] +") " << endl
            << "2.-Captura de ingresos " << endl
            << "3.-Captura de gastos " << endl
            << "4.-Mostrar lista de ingresos anual " << endl
            << "5.-Mostrar lista de gastos anual " << endl
            << "6.-Calculo de impuestos anual" << endl
            << "7.-Salir " << endl << endl
            << "Opción: ";
        cin >> eleccion;
        cin.ignore();
        
        cout << endl << endl;

        switch(eleccion){
            case 1:

                do{
                    
                    cout << "Establecer mes de captura" << endl;
                    
                    for(short i=0; i<CANT_MESES; i++){
                        cout << (i+1) << ".-" << meses[i] << endl;
                    }
                    
                    cout << "Elige el mes (1-12): " ;
                    cin >> eleccionMes;
                    cin.ignore();
                    
                    
                    if(!(1<=eleccionMes && eleccionMes<=12)){
                        cout << "ELECCION NO VALIDA, INTENTELO DE NUEVO" << endl;
                        valido=false;
                    }
                    else{
                        valido=true;
                    }
                    
                }while(!valido);
                
                mes=eleccionMes-1;                    
                
                cout << "Se ha establecido el mes de captura en " << meses[mes] << endl
                        << "Presione entrar para continuar ..." << endl;
                cin.get();
                
                break;
            case 2:
                do{
                    cout << "Captura de ingresos" << endl
                        << "Dame el ingreso del mes de " << meses[mes];
                    cin >> ingresoMes;
                    cin.ignore();

                    if(ingresoMes < 0){
                        cout << "VALOR NO VALIDO, INTENTELO DE NUEVO" << endl;
                        valido=false;
                    }
                    else{
                        valido=true;
                    }
                }while(!valido);
                
                ingresosMeses[mes]=ingresoMes;
                
                cout << "Presione entrar para continuar ..." << endl;
                cin.get();

                break;

            case 3:
                do{

                    cout << "Captura de gastos" << endl
                        << "Dame el gasto del mes de " << meses[mes];
                    cin >> gastoMes;
                    cin.ignore();

                    if(gastoMes < 0){
                        cout << "VALOR NO VALIDO, INTENTELO DE NUEVO" << endl;
                        valido=false;
                    }
                    else{
                        valido=true;
                    }

                }while(!valido);
                
                gastosMeses[mes]=gastoMes;
                
                cout << "Presione entrar para continuar ..." << endl;
                cin.get();
                
                break;

            case 4:

                cout << "Mostrar lista de ingresos anual";
                
                for(short i=0; i<CANT_MESES; i++){
                    //Muestra el ingreso del mes en la posición "i"
                    cout << meses[i] << " = " << floorf(ingresosMeses[i]*100)/100;
                }
                
                cout << "Presione entrar para continuar ...";
                cin.get();
                
                break;

            case 5:

                cout << "Mostrar lista de gastos anual";
                
                for(short i=0; i<CANT_MESES; i++){
                    //Muestra el gasto del mes en la posición "i"
                    cout << meses[i] << " = " << floorf(gastosMeses[i]*100)/100;
                }
                
                cout << "Presione entrar para continuar ...";
                cin.get();
                
                break;

            case 6:

                ingresoAnual=0;
                gastoAnual=0;

                for (short i=0; i<CANT_MESES; i++){
                    ingresoAnual+=ingresosMeses[i];
                    gastoAnual+=gastosMeses[i];
                }

                cout << "\t Cálculo de impuestos anual" << endl;

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
                cout << "\n\n***Tabla de recibo de honorarios***" << endl;
                cout << "Ingresos\t$" << floorf((ingresoAnual*100))/100 << endl;
                cout << "(+)IVA<t1></t1>" << floorf((iva*100))/100 << endl;
                cout << "(=)Subtotal\t$" << floorf((subtotal*100))/100 << endl;
                cout << "(-)Retencion ISR\t$" << floorf((retencionIsr*100))/100 << endl;
                cout << "(-)Retencion IVA\t$" << floorf((retencionIva*100))/100 << endl;
                cout << "(=)Total\t$" << floorf((total*100))/100 << endl;

                //Salidas que muestra la tabla de ganancias
                cout << "\n\n***Tabla de ganancias***" << endl;
                cout << "Ingresos\t$" << floorf((ingresoAnual*100))/100 << endl;
                cout << "(-)Gastos\t$" << floorf((gastoAnual*100))/100 << endl;
                cout << "(=)Ganancia Bruta\t$" << floorf((gananciaBruta*100))/100 << endl;
                cout << "(-)Retencion ISR\t$" << floorf((isr*100))/100 << endl;
                cout << "(=)Ganancia Neta\t$" << floorf((gananciaNeta*100))/100 << endl;

                //Salidas que muestra la tabla de ISR
                cout << "\n\n***Tabla de ISR***" << endl;
                cout << "ISR\t$" << floorf((isr*100))/100 << endl;
                cout << "(-)ISR Retenido\t$" << floorf((retencionIsr*100))/100 << endl;
                cout << "(=)ISR A Pagar\t$" << floorf((isrPagar*100))/100 << endl;

                //Salidas que muestra la tabla de IVA
                cout << "\n\n***Tabla de IVA***" << endl;
                cout << "IVA\t$" << floorf((iva*100))/100 << endl;
                cout << "(-)Gastos IVA\t$" << floorf((gastoIva*100))/100 << endl;
                cout << "(-)Retencion IVA\t$" << floorf((retencionIva*100))/100 << endl;
                cout << "(=)IVA a pagar\t$" << floorf((ivaPagar*100))/100 << endl;

                cout << "\n\nPresiona entrar para continuar ..." << endl;
                cin.get();
            case 7:
                break;
            default:
                cout << "OPCIÓN NO VALIDA INTENTELO DE NUEVO" << endl;

        }
    }while(eleccion!=7);

	return 0;
}
