#include <string>
#include <iostream>
#define IVA 16
#define ISR 11
#define RETENCION_ISR 10
#define RETENCION_IVA 10

using namespace std;

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
    cout << "Ingresos\t" << ingreso << endl;
    cout << "(+)IVA\t" << iva << endl;
    cout << "(=)Subtotal\t" << subtotal << endl;
    cout << "(-)Retencion ISR\t" << retencionIsr << endl;
    cout << "(-)Retencion IVA\t" << retencionIva << endl;
    cout << "(=)Total\t" << total << endl;
    
    //Salidas que muestra la tabla de ganancias
    cout << "\n\n***Tabla de ganancias***" << endl;
    cout << "Ingresos\t" << ingreso << endl;
    cout << "(-)Gastos\t" << gasto << endl;
    cout << "(=)Ganancia Bruta\t" << gananciaBruta << endl;
    cout << "(-)Retencion ISR\t" << isr << endl;
    cout << "(=)Ganancia Neta\t" << gananciaNeta << endl;
    
    //Salidas que muestra la tabla de ISR
    cout << "\n\n***Tabla de ISR***" << endl;
    cout << "ISR\t" << isr << endl;
    cout << "(-)ISR Retenido\t" << retencionIsr << endl;
    cout << "(=)ISR A Pagar\t" << isrPagar << endl;
    
    //Salidas que muestra la tabla de IVA
    cout << "\n\n***Tabla de IVA***" << endl;
    cout << "IVA\t" << iva << endl;
    cout << "(-)Gastos IVA\t" << gastoIva << endl;
    cout << "(-)Retencion IVA\t" << retencionIva << endl;
    cout << "(=)IVA a pagar\t" << ivaPagar << endl;
    
    cout << "\n\nPresiona \"Enter\" para salir" << endl;
    cin.get();
	return 0;
}
