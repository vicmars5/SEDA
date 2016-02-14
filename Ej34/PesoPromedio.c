#include <stdio.h>

/*
 * UnoCuatro
 * 60 minutos
*/

int main()
{
    int i;

    //Variables para entrada de datos
    int cantPacientes;
    int edadPaciente;
    float alturaPaciente;
    float pesoPaciente;

    //Variables para computo
    int cantNinos=0, cantAdolescentes=0, cantJovenes=0, cantAdultosJov=0, cantAdultosMay=0;
    float pesoNinos=0, pesoAdolescentes=0, pesoJovenes=0, pesoAdultosJov=0, pesoAdultosMay=0;
    float alturaNinos=0, alturaAdolescentes=0, alturaJovenes=0, alturaAdultosJov=0, alturaAdultosMay=0;

    printf("\tPromedio de peso de pacientes por edad\n"
            "Cantidad de pacientes que ingresara: ");
    scanf("%d", &cantPacientes);

    printf("\n\n");

    printf("Ingresa los pacientes... \n");
    i=0;
    while(i<cantPacientes){

        //Entrada de datos
        printf("\nPeso(kilogramos) del paciente %i: ", (i+1));
        scanf("%f", &pesoPaciente);
        printf("Altura(metros) del paciente %i: ", (i+1));
        scanf("%f", &alturaPaciente);
        printf("Edad(en años) del paciente %i: ", (i+1));
        scanf("%d", &edadPaciente);

        //Computo
        if(edadPaciente>0){
            if(edadPaciente>=60){
                alturaAdultosMay+=alturaPaciente;
                pesoAdultosMay+=pesoPaciente;
                cantAdultosMay++;
            }
            else{
                if(edadPaciente>=30){
                    alturaAdultosJov+=alturaPaciente;
                    pesoAdultosJov+=pesoPaciente;
                    cantAdultosJov++;
                }
                else{
                    if(edadPaciente>=18){
                        alturaJovenes+=alturaPaciente;
                        pesoJovenes+=pesoPaciente;
                        cantJovenes++;
                    }
                    else{
                        if(edadPaciente>13){
                            alturaAdolescentes+=alturaPaciente;
                            pesoAdolescentes+=pesoPaciente;
                            cantAdolescentes++;
                        }
                        else{
                            alturaNinos+=alturaPaciente;
                            pesoNinos+=pesoPaciente;
                            cantNinos++;
                        }
                    }
                }
            }
        }
        else{
            printf("Edad no valida, vuelvala a ingresar\n");
            i--;
        }
        i++;
    }
    
    //Computo obtencion de promedios
    alturaAdultosMay=alturaAdultosMay/cantAdultosMay;
    alturaAdultosJov=alturaAdultosJov/cantAdultosJov;
    alturaJovenes=alturaJovenes/cantJovenes;
    alturaAdolescentes=alturaAdolescentes/cantAdolescentes;
    alturaNinos=alturaNinos/cantNinos;

    pesoAdultosMay=pesoAdultosMay/cantAdultosMay;
    pesoAdultosJov=pesoAdultosJov/cantAdultosJov;
    pesoJovenes=pesoJovenes/cantJovenes;
    pesoAdolescentes=pesoAdolescentes/cantAdolescentes;
    pesoNinos=pesoNinos/cantNinos;

    //Salida de datos
    printf("\n\nEdad\tPeso\tAltura\n");
    printf("A mayor\t\t%f\t%f\n",pesoAdultosMay,alturaAdultosMay);
    printf("A joven\t\t%f\t%f\n",pesoAdultosJov,alturaAdultosJov);
    printf("Joven\t\t%f\t%f\n",pesoJovenes,alturaJovenes);
    printf("Adolescente\t\t%f\t%f\n",pesoAdolescentes,alturaAdolescentes);
    printf("Niño\t\t%f\t%f\n",pesoNinos,alturaNinos);

    return 0;
}
