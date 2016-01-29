#include <string>
#include <iostream>
#include <cmath>
#define IVA 16
#define ISR 11
#define RETENCION_ISR 10
#define RETENCION_IVA 10

using namespace std;

/**
 * @author UnoCuatro
 * Practica 1
 */

int main (){
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

    cout << "\tCálculo de Impuestos" << endl;
    cout << "Dame el ingreso: " << endl;
    cin >> ingreso; //Entrada de los ingresos
    cin.ignore();
    cout << "Dame el gasto: " << endl;
    cin >> gasto; //Entrada de los gastos
    cin.ignore();

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
    cout << "\n\n***Tabla de recibo de honorarios***" << endl;
    cout << "Ingresos\t$" << floorf((ingreso*100))/100 << endl;
    cout << "(+)IVA\<t1></t1>" << floorf((iva*100))/100 << endl;
    cout << "(=)Subtotal\t$" << floorf((subtotal*100))/100 << endl;
    cout << "(-)Retencion ISR\t$" << floorf((retencionIsr*100))/100 << endl;
    cout << "(-)Retencion IVA\t$" << floorf((retencionIva*100))/100 << endl;
    cout << "(=)Total\t$" << floorf((total*100))/100 << endl;
    
    //Salidas que muestra la tabla de ganancias
    cout << "\n\n***Tabla de ganancias***" << endl;
    cout << "Ingresos\t$" << floorf((ingreso*100))/100 << endl;
    cout << "(-)Gastos\t$" << floorf((gasto*100))/100 << endl;
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
    
    cout << "\n\nPresiona \"Enter\" para salir" << endl;
    cin.get();
	return 0;
}
