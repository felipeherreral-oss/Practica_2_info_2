#ifndef PRACTICA2_H
#define PRACTICA2_H

//  problemas.h  –  Declaraciones globales


// ── Constantes globales
#define TAM_LETRAS   200
#define TAM_CADENA   256
#define FILAS_MAT      5
#define COLS_MAT       5
#define NUM_DENOM     10   // billetes y monedas (no usado en pares, pero disponible)

// validaciones
// Leer un entero con validación; muestra 'mensaje', repite si
// el valor queda fuera de [min, max].
int  leerEntero(const char* mensaje, int min, int max);

// Leer una cadena de texto limpiando el buffer antes.
void leerCadena(const char* mensaje, char* destino, int tamMax);

// Limpiar la pantalla de forma portable.
void limpiarPantalla();

// Pausar hasta que el usuario presione Enter.
void pausar();

// ── problemas.cpp

void problema2();
void problema4();
void problema6();
void problema10();
void problema12();
void problema14();
void problema16();
void problema18();

#endif // PRACTICA2_H
