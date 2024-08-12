#include<stdio.h>
#include<string.h>
#define MAX 20
#define NUM 5

void INGRESO(char[][MAX], int);
void ORDENAR(char[][MAX], int);
void IMPRESION(char[][MAX], int);
int BUSQUEDA_SECUENCIAL(char[][MAX], char [MAX], int);
int BUSQUEDA_BINARIA(char[][MAX], char[MAX], int);

int main(){
    char MAT[NUM][MAX], PALABRA[MAX];
    int POS=0, BAND=0;

    INGRESO(MAT, NUM);
    ORDENAR(MAT, NUM);
    IMPRESION(MAT, NUM);

    printf("\n\n Ingrese palabra a buscar: ");
    gets(PALABRA);

    printf("\n Busqueda secuencial");
    POS=BUSQUEDA_SECUENCIAL(MAT,  PALABRA, NUM);
    if(POS == -1){
        printf("\n %s no se encuentra", PALABRA);
    }else{
        printf("\n %s esta en la posicion %d\n", PALABRA, POS);
    }

    printf("\n Busqueda binaria");
    BAND=BUSQUEDA_BINARIA(MAT, PALABRA, NUM);
    if(BAND == -1){
        printf("\n %s no se encuentra", PALABRA);
    }else{
        printf("\n %s esta en la posicion: %d", PALABRA, BAND);
    }

    printf("\n\n Fin del programa");

    return 0;
}
void INGRESO(char MAT[][MAX], int L){
    int i;
    printf("\n Ingrese %d palabras: \n\n", L);
    for(i=0; i<L; i++){
        printf(" Palabra %3d : ", i);
        fflush(stdin);
        gets(MAT[i]);
    }
}
void ORDENAR(char MAT[][MAX], int L){
    int i, j;
    char AUX[MAX];
    for(i=0; i<L-1; i++){
        for(j=0; j<L-i-1; j++){
            if(strcmp(MAT[j], MAT[j+1]) > 0){
                strcpy(AUX, MAT[j]);
                strcpy(MAT[j], MAT[j+1]);
                strcpy(MAT[j+1], AUX);
            }
        }
    }
}
void IMPRESION(char MAT[][MAX], int L){
    int i;
    printf("\n\n Impresion: \n");
    for(i=0; i<L; i++){
        printf("\n%10d\t%s", i, MAT[i]);
    }
}
int BUSQUEDA_SECUENCIAL(char MAT[][MAX], char PALABRA[MAX], int L){
    int i, POS=-1;
    for(i=0; i<L; i++){
        if(!(strcmp(MAT[i], PALABRA))){
            POS=i;
        }
    }
    return POS;
}
int BUSQUEDA_BINARIA(char MAT[][MAX], char PALABRA[MAX], int L){
    int BAJO=0, ALTO=L-1, MED=0, COMPARACION=0;
    while(BAJO <= ALTO){
        MED=(BAJO+ALTO)/2;
        COMPARACION=strcmp(MAT[MED], PALABRA);
        if(COMPARACION==0){
            return MED; // lo encontramos
        }else if(COMPARACION<0){
            ALTO=MED-1;
        }else{
            BAJO=MED+1;
        }
    }
    return -1;
}
