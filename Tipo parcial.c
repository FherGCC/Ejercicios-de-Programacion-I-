#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ZONA(int , int);
float puntaje(int,int);

int main()
{
	int codigoCompetidor, coordenadax, coordenaday, penal, area, ganador;
	float puntos,puntajemax=-1;

	printf("\n Ingrese el codigo de competidor: ");
	scanf("%d", &codigoCompetidor);

	while(codigoCompetidor>0)
	{
		printf("\n Ingrese sus coordenadas de aterrizaje X: ");
		scanf("%d", &coordenadax);
		printf("\n Ingrese sus coordenadas de aterrizaje Y: ");
		scanf("%d", &coordenaday);

		printf("\n Ingrese la cantidad de penalizaciones (entre 0 y 2 inclusive): ");
		scanf("%d", &penal);

		area=ZONA(coordenadax, coordenaday);
		puntos=puntaje(area,penal);


		if (puntos>puntajemax){

			puntajemax=puntos;
			ganador=codigoCompetidor;
		}
		printf("\n Ingrese el codigo de competidor: ");
		scanf("%d", &codigoCompetidor);
	}



	printf("\n\tEl competidor ganador es: %d con: %.2f de puntaje", ganador, puntajemax);
}


int ZONA (int x , int y)
{
	float distancia;
	int area;
	distancia=sqrt(( x * x )+( y * y ));
	if (distancia<=5)
		area=0;
		if (distancia > 5 && distancia <= 7.5 )
			area=1;
			if (distancia > 7.5 && puntaje <= 15 )
				area=2;
				if (distancia > 15)
					area=3;


	return area;
}

float puntaje(int area, int penalizaciones)
{
	float calculo, descuento;
	if (area==0)
	{
		calculo=50;
		}else if (area==1){
			calculo=40;
		}else if (area==2){
			calculo=30;
		}else if (area==3){
			calculo=0;
		}


	if (penalizaciones==1){

		descuento=(calculo*25)/100;
		calculo-=descuento;
	}

	if (penalizaciones==2){

		descuento=(calculo*50)/100;
		calculo-=descuento;
	}

return calculo;
}

    /*1. Construir la funcion PRIMO, que reciba un numero entero positivo y retorne 1 si este es primo, y 0 en caso contrario
    2. Contruir la funcion PERFECTO, que reciba un numero entero positivo y retorne 1 si este es perfecto, y un 0 si no lo es.
    3.Construir la funcion POTENCIA, que recibe un numero entero P y retorne 2^P (2 elevado a la p).
    4.Contruir la funcion EUCLIDES, ( que utilice la del punto anterior), tal que reciba un numero P y retorne un valor M, siendo M= [2 ^ (P-1)]. ([2^P] -1 )
    5. Crear un programa que utilice las funciones anteriores y compruebe para los valores de P correspondientes a los
    numeros primos menores que 100, si M es un numero perfecto o no.

int PRIMO(int);
int PERFECTO (int);
int POTENCIA (int);
int Euclides (int);

int main()
{
    int Num = 29, Cont;

    for (Cont=1; Cont<=Num; Cont++)
    {
        if (PRIMO(Cont))
            printf("\n\t El numero %d es Primo",Cont);
        else
            printf("\n\t El numero %d no es Primo",Cont);

    }

    return 0;
}

int PRIMO (int NUM)
{
    int ESPRIMO = 1; //tomamos todos los numeros como primos y verificamos si es cierto o falso

    for(int i = 3; i < NUM; i += 2)
        if ( !(NUM%i) || !(NUM%2))
            ESPRIMO = 0; //Si es divisible entonces no es primo, marcamos como falso

    if(ESPRIMO && NUM!=1)
        return 1;
    return 0;
}*/
