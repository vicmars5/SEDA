#include <iostream>
#include <cstdlib>

#include "materia.h"

#ifdef __unix__
    #define CLEAR "clear"
#else
    #define CLEAR "cls"
#endif
//Porcentaje a considerar para evaluacion del curso
#define VAL_TAREAS 7
#define VAL_ACTIVIDADES 63
#define VAL_EXA_PARCIALES 30

//Total de los evaluandos y asistencias
#define TTL_ASISTENCIAS 34
#define TTL_TAREAS 10
#define TTL_ACTIVIDADES 9
#define TTL_EXA_PARCIALES 3

#define RETARDOS_POR_FALTA 3 //Cada tres retardos es un falta
#define ASISTENCIA_MIN 80 //Porcentaje minimo de asistencia para aprovar
#define CAL_MAX 100 //Calificiones van del 0 al 100
#define CAL_MIN_APROV 60 //Calificacion minima aprovatoria

#define ESCALA_EVALUACION 100 //Se evalua hasta el cien


using namespace std;

/*
 *Autor UnoCuatro
 */
int main()
{
    //Entrada de datos
    float   faltas, //Faltas a clase
            retardos, //Retardos a clase
            tareas; //Tareas realizadas
    float   calsActividades[TTL_ACTIVIDADES], //Calificaciones de actividades
            calsExaParciales[TTL_EXA_PARCIALES]; //Calificaciones de examenes parciales

    //Salida de datos
    //Puntajes
    float   ptsFlsTareas,
            ptsFlsActividades,
            ptsFlsExamenes,
            calFinal;
    //Asistencias
    float   asistencias, //Cantidad de asistencias
            porcAsistencias; //Porcentaje de asistencias
    //Afirmaciones
    bool    derechoOrdinario, //Derecho a ordinario
            calAprobatoria,
            aprobado;

    Materia materia;

    //Varibles de computo
    char salir;
    bool valido=false; //Validacion de formularios
    int i; //Contador para ciclos

    int tam;
    string entrada;

    cout << "Evaluador del Curso v1.0"  << endl;

    cout << "Nombre de materia: ";
    getline(cin, entrada);

    tam=sizeof(materia.nombreMateria);
    for(i = 0; i < entrada.length() and i < tam; i++){

        materia.nombreMateria[i] = entrada.at(i);
    }

    cout << "Acronimo: ";
    getline(cin, entrada);
    tam=sizeof(materia.acronimo);
    for(i = 0; i < entrada.length() and i < tam; i++) {
        materia.acronimo[i] = entrada.at(i);
    }

    do{
        cout << "Primer dia(L,M,I,J,V,S):";
        cin >> materia.horario[0];
        cin.ignore();

        materia.horario[0] = toupper(materia.horario[0]);
        if(materia.horario[0] == 'L' or materia.horario[0] == 'M' or materia.horario[0] == 'I'
                or materia.horario[0] == 'J' or materia.horario[0] == 'V'
                or materia.horario[0] == 'S'){
                valido = true;
        } else {
            valido = false;
            cout << "Dia no valido" << endl;
        }
    } while (!valido);

    do{
        cout << "Segundo dia(L,M,I,J,V,S):";
        cin >> materia.horario[1];
        cin.ignore();

        materia.horario[1] = toupper(materia.horario[1]);
        if(materia.horario[1] == 'L' or materia.horario[1] == 'M' or materia.horario[1] == 'I'
                or materia.horario[1] == 'J' or materia.horario[1] == 'V'
                or materia.horario[1] == 'S'){
                valido = true;
        } else {
            valido = false;
            cout << "Dia no valido" << endl;
        }
    } while(!valido);

    materia.horario[2] = ' ';

    do{
        cout << "Hora inicio (dos digitos, 24 horas)";
        cin >> materia.horario[3] >> materia.horario[4];

        if((materia.horario[3] >= '0' and materia.horario[3] <= '2')
                and (materia.horario[4] >= '0' and materia.horario[4] <= '9')){
            valido = true;
        } else {
            valido = false;
            cout << "Hora no valida" << endl;
        }
    } while (!valido);
    materia.horario[5] = 'a';

    do{
        cout << "Hora fin (dos digitos, 24 horas)";
        cin >> materia.horario[6] >> materia.horario[7];

        if((materia.horario[6] >= '0' and materia.horario[6] <= '2')
                and (materia.horario[7] >= '0' and materia.horario[7] <= '9')){
            valido = true;
        } else {
            valido = false;
            cout << "Hora no valida" << endl;
        }
    } while (!valido);

    system(CLEAR);

    //--------->Entrada de datos<-----------
    cout << "Evaluador del Curso v1.0 – " << materia.nombreMateria <<" ("
            << materia.acronimo << ") " << materia.horario  << endl << endl;

    cout << "Cuantas faltas acumulaste? ";
    cin >> faltas;
    cin.ignore();

    cout << "Cuantos retardos acumulastes? ";
    cin >> retardos;
    cin.ignore();

    cout << "Cuantas tareas realizaste? ";
    cin >> tareas;
    cin.ignore();

    for(i = 0; i < TTL_ACTIVIDADES; i++){
        cout << "Cuanto obtuviste en la actividad #" << (i + 1)  << "? ";
        cin >> calsActividades[i];
        cin.ignore();
    }

    cout << "Cuanto obtuviste en el primer examen parcial? ";
    cin >> calsExaParciales[0];
    cin.ignore();

    cout << "Cuanto obtuviste en el segundo examen parcial? ";
    cin >> calsExaParciales[1];
    cin.ignore();

    cout << "Cuanto obtuviste en el tercer examen parcial? ";
    cin >> calsExaParciales[2];
    cin.ignore();


    //------------->Computo<-------------

    ptsFlsTareas =  tareas / TTL_TAREAS * ESCALA_EVALUACION * VAL_TAREAS / CAL_MAX; //Tareas

    //Examenes parciales
    ptsFlsExamenes = 0;
    for (i = 0; i < TTL_EXA_PARCIALES; i++){
        ptsFlsExamenes += calsExaParciales[i];
    }
    ptsFlsExamenes = ptsFlsExamenes / TTL_EXA_PARCIALES * VAL_EXA_PARCIALES / CAL_MAX;

    //Actividades
    ptsFlsActividades = 0;
    for (i = 0; i < TTL_ACTIVIDADES; i++){
        ptsFlsActividades += calsActividades[i];
    }
    ptsFlsActividades = ptsFlsActividades / TTL_ACTIVIDADES * VAL_ACTIVIDADES / CAL_MAX;

    calFinal = (ptsFlsTareas
                        + ptsFlsActividades
                        + ptsFlsExamenes * VAL_EXA_PARCIALES)
                        / ESCALA_EVALUACION;

    asistencias = TTL_ASISTENCIAS - faltas - (retardos/RETARDOS_POR_FALTA); //Asistencias totales
    porcAsistencias = asistencias / TTL_ASISTENCIAS * ESCALA_EVALUACION; //Porcentaje de asistencias

    //Derecho a ordinario
    if(porcAsistencias >= ASISTENCIA_MIN) {
        derechoOrdinario = true;
    } else {
        derechoOrdinario = false;
    }
    //Calificacion aprobatoria
    calAprobatoria = calFinal >= CAL_MIN_APROV ? true : false;
    //Aprobado
    aprobado = derechoOrdinario and calAprobatoria;


    //------------->Salida<-------------
    cout << "Tareas\tActividades\tExamenes" << endl;
    cout << ptsFlsTareas << "\t" << ptsFlsActividades << "\t\t" << ptsFlsExamenes << endl;
    cout << "Total de asistencias=\t\t" << asistencias << endl;
    cout << "Porcentaje de asistencias=\t" << porcAsistencias << "\t";
    if(derechoOrdinario){
        cout << "Tiene derecho";
    } else {
        cout << "No tiene derecho";
    }
    cout << endl;
    cout << "Calificacion final=\t\t" << calFinal << "\t";
    if(calAprobatoria){
        cout << "Calificacion aprobatoria";
    } else {
        cout << "Calificacion no aprobatoria";
    }
    cout << endl;
    cout << "Alumn@ ";
    if(!aprobado){
        cout << "no ";
    }
    cout << "aprobado" << endl;

    return 0;
}
