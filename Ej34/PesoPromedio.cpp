#include <stdio.h>
#include <stdlib.h>

/*
 * UnoCuatro
 * 11-38 am ->
*/

int main()
{
    int i;

    //Entrada de datos
    int cantPacientes;
    int edadPaciente;
    float alturaPaciente;
    float pesoPaciente;

    //Computo
    int cantNinos=0, cantAdolescentes=0, cantJovenes=0, cantAdultosJov=0, cantAdultosMay=0;
    float pesoNino=0, pesoAdolescentes=0, pesoJovenes=0, pesoAdultosJov=0, pesoAdultosMay=0;
    float alturaNino=0, alturaAdolescentes=0, alturaJovenes=0, alturaAdultosJov=0, alturaAdultosMay=0;

    printf("\tPromedio de peso de pacientes por edad\n"
            "Cantidad de pacientes que ingresara: \n");
    scanf("%d", &cantPacientes);

    printf("\n\n");

    for(i=0; i<cantPacientes; i++){

        //Entrada de datos
        printf("Peso(kilogramos) del paciente %i: ", (i+1));
        scanf("%f", &pesoPaciente);
        printf("Altura(metros) del paciente %i: ", (i+1));
        scanf("%f", &alturaPaciente);
        printf("Edad(en años) del paciente %i: ", (i+1));
        scanf("%d", &edadPaciente);

        //Computo
        if(edadPaciente>0){

        }
        else{

        }

    }


    return 0;
}
