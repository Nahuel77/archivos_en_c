#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct alumnos
{
    char nombres[40];
    int edad;
    int nota;
} Talumnos;

int contar()
{
    FILE *arch;
    Talumnos r;
    int i=0;

    arch=fopen("curso.txt","r");
    if(arch!=NULL)
    {
        do
        {
            fscanf(arch,"%s\t%d\t%d\n",r.nombres,&r.edad,&r.nota);
            i++;
        }
        while(!feof(arch));
    }
    else
    {
        printf("archivo no encontrado");
    }
    fclose(arch);
    return i;
}
void cargarvector(Talumnos alumnos[])
{
    FILE *arch;
    int i=0;
    Talumnos r;
    arch=fopen("curso.txt","r");
    if(arch!=NULL)
    {
        do
        {
            fscanf(arch,"%s\t%d\t%d\n",r.nombres,&r.edad,&r.nota);
            alumnos[i]=r;
            i++;
        }
        while(!feof(arch));
    }
    else
    {
        printf("archivo no encontrado");
    }
    fclose(arch);
}

void buscarMayorNota(Talumnos alumnos[], int num){
    int i, j=0, top;
    int tier[num];
    top=alumnos[0].nota;//11
    tier[0]=0;
    for(i=1; i<num; i++){
        if(alumnos[i].nota==top){
            j++;//2
            tier[j]=i;// 0=1, 1=4, 2=6
        }
        if(alumnos[i].nota>top){
            top=alumnos[i].nota;
            j=0;
            tier[j]=i;// 0=1, 1=4,
        }
    }
    if(j==0){
        printf("La nota mas alta es un %d y es del alumno %s.\n", top, alumnos[tier[0]].nombres);
    }else{
        printf("La nota mas alta es un %d y pertenece a los alumnos:\n", top);
        for(i=0; i<j+1; i++){
            printf("%s\t", alumnos[tier[i]].nombres);
        }
        printf("\n");
    }

}

#endif // HEADER_H_INCLUDED
