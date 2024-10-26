#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct alumno
{
    char nombre[50];
    int edad;
} talumno;

talumno ingresarAlu()
{
    talumno alu;
    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(alu.nombre);
    do
    {
        printf("Ingrese la edad: \n");
        fflush(stdin);
        scanf("%d", &alu.edad);
        if(alu.edad<=0)
        {
            printf("La edad ingresada no es valida.\nIngrese otra edad:\n");
        }
    }
    while(alu.edad<=0);
    return alu;
}

void mostrarAlu(talumno alumnos[], int num)
{
    int i;
    for(i=0; i<num; i++)
    {
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
    }
}

void guardarTXT(talumno alumnos[], int num)
{
    FILE *alus;
    int i;
    alus=fopen("alumnos.txt", "a");
    for(i=0; i<num; i++)
    {
        fprintf(alus, "%s\t%d\n", alumnos[i].nombre, alumnos[i].edad);
    }
    fclose(alus);
}

void leerTXT()
{
    FILE *alus;
    char nombres[50];
    int edades;
    alus=fopen("alumnos.txt", "r");
    if(alus!=NULL)
    {
        fscanf(alus, "%s%d", &nombres, &edades);
        do
        {
            printf("%s\t%d\n", nombres, edades);
            fscanf(alus, "%s%d", &nombres, &edades);
        }
        while(!feof(alus));
    }
    else
    {
        printf("Archivo no encontrado");
    }
    fclose(alus);
}

int contarTXT()
{
    FILE *alus;
    int i=0;
    talumno r;
    alus=fopen("alumnos.txt", "r");
    if(alus!=NULL)
    {
        do
        {
            fscanf(alus, "%s%d", &r.nombre, &r.edad);
            i++;
        }
        while(!feof(alus));
    }
    else
    {
        printf("Archivo no encontrado");
    }
    fclose(alus);
    return i;
}

void cargarTXT(talumno alusTXT[])
{
    FILE *alus;
    int i=0;
    talumno r;
    alus=fopen("alumnos.txt", "r");
    if(alus!=NULL)
    {
        do
        {
            fscanf(alus, "%s%d", &r.nombre, &r.edad);
            alusTXT[i]=r;
            i++;
        }
        while(!feof(alus));
    }
    else
    {
        printf("Archivo no encontrado");
    }
    fclose(alus);
}

#endif // HEADER_H_INCLUDED
