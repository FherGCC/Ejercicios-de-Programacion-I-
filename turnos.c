#include <stdio.h>
#include <string.h>

#define N 100

struct fecha {
    int anio;
    int mes;
    int dia;
};

struct turno {
    struct fecha fecha_turno;
    int hora;
    int legajo;
    char obra_social[21];
};

int buscar(struct turno [], int, int);
int cuenta_turnos(struct turno [], int, int);
void mostrar_resumen_legajo(struct turno [], int);

int main()
{
    struct turno v_turnos[N];
    mostrar_resumen_legajo(v_turnos, N);
}

// Función de búsqueda
int buscar(struct turno v_turnos[], int legajo_busqueda, int n) {
    for (int i = 0; i < n; i++) {
        if (v_turnos[i].legajo == legajo_busqueda) {
            return i;
        }
    }
    return -1;
}

// Función para contar turnos
int cuenta_turnos(struct turno v_turnos[], int legajo_a_contar, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v_turnos[i].legajo == legajo_a_contar) {
            count++;
        }
    }
    return count;
}

// Función para mostrar resumen de legajos
void mostrar_resumen_legajo(struct turno v_turnos[], int n) {
    int legajos_unicos[N]; // Asumimos un máximo de 100 legajos únicos para simplificar
    int cantidad_legajos_unicos = 0;

    for (int i = 0; i < n; i++) {
        int legajo_actual = v_turnos[i].legajo;
        if (buscar((struct turno*)legajos_unicos, legajo_actual, cantidad_legajos_unicos) == -1) {
            legajos_unicos[cantidad_legajos_unicos] = legajo_actual;
            cantidad_legajos_unicos++;
        }
    }

    printf("Legajo\t\tCantidad de Turnos\n");
    for (int i = 0; i < cantidad_legajos_unicos; i++) {
        int legajo = legajos_unicos[i];
        int cantidad_turnos = cuenta_turnos(v_turnos, legajo, n);
        printf("%d\t\t%d\n", legajo, cantidad_turnos);
    }
}
