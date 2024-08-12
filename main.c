#include <stdio.h>
#include <stdlib.h>

#define MAX 10000
main()
{
    /* Ejercicio 1:

    int num, acum;
    acum = 0;

    do {
    printf("\n\n\t Por favor ingrese un numero entero: ");
    scanf("%d", &num);

    if (num >= 0)
        if ( !(num%2) && num != 0)
            acum += 1;

    } while (num >= 0);

    printf("\n\n\t La cantidad de numeros pares ingresados fue de: %d", acum);
    */
        /* ejercicio 2

    int CONT, NUM, SUMI = 0, SUMP = 0;

    for(CONT = 1; CONT <=10; CONT++)
        {
        printf("\n\n\t %d Por favor ingrese un numero: ", CONT);
        scanf("%d", &NUM);

        if (CONT%2)
            SUMI += NUM;
        else
            SUMP += NUM;
        }

        if (SUMI > SUMP)
            printf("\n\t Los numeros de orden impar son los que dan la mayor suma");
        else
            printf("\n\t Los numeros de orden par son los que dan la mayor suma");*/

            //ejercicio de la moneda

/*
    int moneda, cara, seca;
    float porcara, porseca;
    srand(time(0));

    printf("\n\n\t Se va a lanzar una moneda un numero determinado de veces, y se mostrara el porcentaje de ocurrencia de cara y seca");

    for(int i = 1; i <= MAX; i *= 10)
    {
        printf("\n\n\t El numero de tiradas es de: %d", i);
        cara = 0;
        seca = 0;
        for(int j = 1; j <= i; j++)
        {
            moneda = rand() % 2;
            if(moneda)
                cara += 1;
            else
                seca += 1;
        }
        printf("\n\t cara: %d \t seca: %d", cara, seca);
        porcara = ((float)cara/i)*100;
        porseca = ((float)seca/i)*100;
        printf("\n\t El porcentaje de caras es: %.2f%c \n\t El porcentaje de secas es: %.2f%c", porcara, 37, porseca, 37);
    } */

    int NUM1 = 0, NUM2 = 0, NUM3 = 0, NUM4 = 0, NUM5 = 0, NUM6 = 0;

    printf("Ingrese 6 numeros: ");
    scanf("%d %d %d %d %d %d", &NUM1, &NUM2, &NUM3, &NUM4, &NUM5, &NUM6);

    if (NUM2>NUM1)
    {
        if(NUM6>NUM5 && NUM5>NUM4 && NUM4>NUM3 && NUM3>NUM2)
            printf("\nLA cadena de numeros es creciente");
        else("\nNo es ni creciente ni decreciente");
    }
    else
    {
        if(NUM6<NUM5 && NUM5<NUM4 && NUM4<NUM3 && NUM3<NUM2)
            printf("\nLa cadena de numeros es decreciente");
        else
            printf("\nNo es ni creciente ni decreciente");
    }
}
