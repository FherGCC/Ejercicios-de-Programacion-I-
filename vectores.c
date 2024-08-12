#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

struct sala {
    int codigo;
    int butaca[4][6];
    char peli[30];
};

int mas_vista(struct sala[]);

int buscar_peli(struct sala[], char[]);

void ingreso(struct sala[], int);

void mostrar(struct sala[], int);


int main ()
{
    struct sala vec[N];
    char pelicula[30];
    int sala;
    srand(time(0));

    ingreso(vec, N);
    mostrar(vec, N);

    printf("\n\n\t lA PELICULA MAS VISTA ES: Sala %d", mas_vista(vec));

    printf("\n\n\t Ingrese el nombre de una pelicula para buscar: ");
    gets(pelicula);
    sala = buscar_peli(vec, pelicula);
    if (sala == -1)
    {
        printf("\n\n\t\t La pelicula no se ha encontrado");
    }
    else
    {
        printf("\n\n\t\t La pelicula %s esta siendo reproducida en la sala %d", vec[sala-1].peli, sala);
    }


}

void ingreso(struct sala v[], int n)
{
    int i, f, c;

    char peli[][30] = {"UP","DOOM","LALALAND","AVENGERS"};

    for (i=0; i < n ; i++)
    {
        v[i].codigo = i+1;

        for (f=0; f < 4; f++)
            for (c = 0; c < 6; c++)
                v[i].butaca[f][c] = rand() % 2;
        strcpy(v[i].peli, peli[i]);
    }

}

void mostrar(struct sala v[], int n)
{
    int i, f, c;

    for (i=0; i < n ; i++)
    {
        printf("\n\n\n\n\t\t  SALA %d: %s", v[i].codigo, v[i].peli);
        for (f=0; f < 4; f++)
            {
                printf("\n\n\t\t");
                for (c = 0; c < 6; c++)
                    printf("%3d", v[i].butaca[f][c]);
            }
    }
}



// Parte 1

int mas_vista(struct sala v[])
{
    int cant = 0, cantmax = 0, i, f, c, masvis;

    for (i=0; i < N; i++)
    {
        cant = 0;
        for (f=0; f<4; f++)
            for (c=0; c<6; c++)
                if (v[i].butaca[f][c])
                    cant ++;

        if (cant > cantmax)
        {
            cantmax = cant;
            masvis = i;
        }
    }
    return v[masvis].codigo;
}

// Parte 2

int buscar_peli(struct sala v[4], char peli[30])
{
    int i;

    for (i = 0; i < N; i++)
    {
        if( strcmpi(peli, v[i].peli) == 0)
            return v[i].codigo;
    }
    return -1;
}
