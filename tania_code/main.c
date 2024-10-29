#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int contar();
void cargarvector(Talumnos alumnos[]);
void buscarMayorNota(Talumnos alumnos[], int num);

int main()
{
    int num=contar();
    Talumnos alumnos[num];
    int i;

    cargarvector(alumnos);

    for(i=0; i<num; i++)
    {
        printf("nombre:%s\nedad:%d\nnota:%d\n",alumnos[i].nombres,alumnos[i].edad,alumnos[i].nota);
    }

    system("pause");
    system("cls");
    buscarMayorNota(alumnos, num);
    system("pause");
}
