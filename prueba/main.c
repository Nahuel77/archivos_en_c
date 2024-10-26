#include <stdio.h>
#include <stdlib.h>
#include "header.h"

talumno ingresarAlu();
void mostrarAlu(talumno alumnos[], int num);
void guardarTXT(talumno alumnos[], int num);
void leerTXT();
int contarTXT();
void cargarTXT(talumno alusTXT[]);

int main()
{
    int num, i, num2;
    printf("Ingrese la cantidad de alumnos: \n");
    scanf("%d", &num);

    talumno alumnos[num];

    for(i=0; i<num; i++){
        printf("ingrese alumno %d:\n", i+1);
        alumnos[i]=ingresarAlu();
    }

    //mostrarAlu(alumnos, num);

    guardarTXT(alumnos, num);

    //leerTXT();

    num2=contarTXT();
    talumno alusTXT[num2];

    cargarTXT(alusTXT);

    for(i=0; i<num2; i++){
        printf("Nombre: %s\nEdad: %d\n", alusTXT[i].nombre, alusTXT[i].edad);
    }

    return 0;
}
