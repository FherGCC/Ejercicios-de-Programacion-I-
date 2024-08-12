#include <stdio.h>
#define N 4

struct jugador {
    char nombre [40];
    char s;
    int handicap;
};

void ingreso ( struct jugador [N]);
void mostrar ( struct jugador [N]);

int main ()
{

    struct jugador vec[N];

    ingreso(vec);
    mostrar(vec);

}

void ingreso (struct jugador vec [N])
{
    int i;

    for (i=0; i<N;i++)
    {
        fflush(stdin);
        gets(vec[i].nombre);
        fflush(stdin);
        scanf("%c", &vec[i].s);
        scanf("%d", &vec[i].handicap);
    }

}

void mostrar (struct jugador vec [N])
{
    int i;

    for (i=0; i<N;i++)
    {
        printf("\n %20s %15c\t\n %5d", vec[i].nombre, vec[i].s, vec[i].handicap);
    }
}
