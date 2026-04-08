
//  problemas.cpp  –  Problemas pares 2, 4, 6, 8, 10, 12, 14, 16, 18


#include "problemas.h"
#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
#include <cstring>   // strlen()
#include <climits>   // INT_MAX
using namespace std;


//  PROBLEMA 2
//  Generar 200 letras mayúsculas aleatorias, imprimirlas y
//  mostrar cuántas veces se repite cada letra.
// ============================================================
void problema2()
{
    char letras[TAM_LETRAS];
    int  frecuencia[26] = {0};   // índice 0 = 'A', 25 = 'Z'

    srand((unsigned int)time(NULL));

    // Generar arreglo
    for (int i = 0; i < TAM_LETRAS; i++) {
        letras[i] = (char)('A' + rand() % 26);
        frecuencia[letras[i] - 'A']++;
    }

    // Imprimir arreglo (20 letras por línea para legibilidad)
    cout << "\n  Arreglo generado:\n  ";
    for (int i = 0; i < TAM_LETRAS; i++) {
        cout << letras[i];
        if ((i + 1) % 20 == 0)
            cout << "\n  ";
    }

    // Imprimir frecuencias (sólo letras que aparecen al menos una vez)
    cout << "\n  Frecuencia de cada letra:\n";
    for (int i = 0; i < 26; i++) {
        if (frecuencia[i] > 0)
            cout << "  " << (char)('A' + i) << ": " << frecuencia[i] << "\n";
    }
}

//  PROBLEMA 4
//  Recibir una cadena de caracteres numéricos y convertirla
//  a entero sin usar atoi() ni funciones de biblioteca.
// ============================================================

// Función auxiliar: verifica que todos los caracteres sean dígitos
// (permite un '-' inicial para negativos).
static bool esCadenaNumerica(const char* cad)
{
    int i = 0;
    if (cad[0] == '-') i = 1;          // signo opcional
    if (cad[i] == '\0') return false;   // sólo '-' no es número

    for (; cad[i] != '\0'; i++) {
        if (cad[i] < '0' || cad[i] > '9')
            return false;
    }
    return true;
}

// Convierte cadena numérica a int (implementación manual).
static int cadenaAEntero(const char* cad)
{
    int resultado = 0;
    int signo     = 1;
    int i         = 0;

    if (cad[0] == '-') { signo = -1; i = 1; }

    for (; cad[i] != '\0'; i++) {
        resultado = resultado * 10 + (cad[i] - '0');
    }
    return resultado * signo;
}

void problema4()
{
    char cadena[TAM_CADENA];
    bool valido = false;

    do {
        leerCadena("\n  Ingrese una cadena de caracteres numéricos: ",
                   cadena, TAM_CADENA);

        if (!esCadenaNumerica(cadena)) {
            cout << "  [!] La cadena contiene caracteres no numéricos. "
                    "Intente de nuevo.\n";
        } else {
            valido = true;
        }
    } while (!valido);

    int numero = cadenaAEntero(cadena);
    cout << "  Cadena ingresada : \"" << cadena << "\"\n";
    cout << "  Número convertido: " << numero << "\n";
}


//  PROBLEMA 6
//  Recibir una cadena y convertir las letras minúsculas a
//  mayúsculas; los demás caracteres permanecen igual.
// ============================================================
void problema6()
{
    char original[TAM_CADENA];
    char convertida[TAM_CADENA];

    leerCadena("\n  Ingrese una cadena de texto: ", original, TAM_CADENA);

    int len = (int)strlen(original);
    for (int i = 0; i <= len; i++) {           // <= para copiar '\0'
        if (original[i] >= 'a' && original[i] <= 'z')
            convertida[i] = (char)(original[i] - 32);
        else
            convertida[i] = original[i];
    }

    cout << "  Original     : " << original   << "\n";
    cout << "  En mayúscula : " << convertida << "\n";
}

//  PROBLEMA 8
//  Separar los dígitos del resto de caracteres en una cadena,
//  generando dos cadenas: una sin números y otra sólo con ellos.
// ============================================================
void problema8()
{
    char original[TAM_CADENA];
    char soloTexto[TAM_CADENA];
    char soloNumeros[TAM_CADENA];

    leerCadena("\n  Ingrese una cadena de texto: ", original, TAM_CADENA);

    int it = 0, in = 0;
    for (int i = 0; original[i] != '\0'; i++) {
        if (original[i] >= '0' && original[i] <= '9')
            soloNumeros[in++] = original[i];
        else
            soloTexto[it++]   = original[i];
    }
    soloTexto[it]    = '\0';
    soloNumeros[in]  = '\0';

    cout << "  Original : " << original    << "\n";
    cout << "  Texto    : " << soloTexto   << "\n";
    cout << "  Número   : " << soloNumeros << "\n";
}
void problema10()
{
    char romano[TAM_CADENA];
    bool valido = false;

    do {
        leerCadena("\n  Ingrese un número romano (ej: DCLXVI): ",
                   romano, TAM_CADENA);

        // Convertir a mayúsculas por si el usuario usó minúsculas
        for (int i = 0; romano[i] != '\0'; i++) {
            if (romano[i] >= 'a' && romano[i] <= 'z')
                romano[i] = (char)(romano[i] - 32);
        }

        if (!esRomanoValido(romano)) {
            cout << "  [!] La cadena contiene caracteres romanos inválidos.\n"
                 << "      Caracteres válidos: M D C L X V I\n";
        } else {
            valido = true;
        }
    } while (!valido);

    int resultado = 0;
    int len = (int)strlen(romano);

    for (int i = 0; i < len; i++) {
        int actual   = valorRomano(romano[i]);
        int siguiente = (i + 1 < len) ? valorRomano(romano[i + 1]) : 0;

        if (actual < siguiente)
            resultado -= actual;
        else
            resultado += actual;
    }

    cout << "  El número ingresado fue : " << romano    << "\n";
    cout << "  Que corresponde a       : " << resultado << "\n";
}


//  PROBLEMA 12
//  El usuario ingresa una matriz cuadrada NxN; el programa
//  verifica si es un cuadrado mágico:
//    1. Todos los números son distintos (sin repetidos).
//    2. La suma de cada fila, columna y las dos diagonales
//       es la misma constante.
//  Restricción: N máximo = 10 para simplicidad.
// ============================================================
#define MAX_N 10

void problema12()
{
    int n = leerEntero("\n  Tamaño de la matriz NxN (N entre 2 y 10): ", 2, MAX_N);

    int mat[MAX_N][MAX_N];

    cout << "  Ingrese los " << n * n << " elementos (fila por fila):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "  mat[" << i << "][" << j << "] = ";
            mat[i][j] = leerEntero("", INT_MIN, INT_MAX);
        }
    }

    // ── Imprimir la matriz ───────────────────────────────────
    cout << "\n  Matriz ingresada:\n";
    for (int i = 0; i < n; i++) {
        cout << "  ";
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << "\t";
        cout << "\n";
    }

    // ── Verificar que no haya repetidos ─────────────────────
    bool hayRepetidos = false;
    for (int i = 0; i < n && !hayRepetidos; i++)
        for (int j = 0; j < n && !hayRepetidos; j++)
            for (int k = i; k < n && !hayRepetidos; k++)
                for (int l = (k == i ? j + 1 : 0); l < n && !hayRepetidos; l++)
                    if (mat[i][j] == mat[k][l])
                        hayRepetidos = true;

    if (hayRepetidos) {
        cout << "  [✗] No es un cuadrado mágico: hay valores repetidos.\n";
        return;
    }

    // ── Calcular suma de referencia (primera fila) ───────────
    int sumaRef = 0;
    for (int j = 0; j < n; j++) sumaRef += mat[0][j];

    bool esMagico = true;

    // Verificar filas
    for (int i = 1; i < n && esMagico; i++) {
        int suma = 0;
        for (int j = 0; j < n; j++) suma += mat[i][j];
        if (suma != sumaRef) esMagico = false;
    }

    // Verificar columnas
    for (int j = 0; j < n && esMagico; j++) {
        int suma = 0;
        for (int i = 0; i < n; i++) suma += mat[i][j];
        if (suma != sumaRef) esMagico = false;
    }

    // Verificar diagonal principal
    if (esMagico) {
        int suma = 0;
        for (int i = 0; i < n; i++) suma += mat[i][i];
        if (suma != sumaRef) esMagico = false;
    }

    // Verificar diagonal secundaria
    if (esMagico) {
        int suma = 0;
        for (int i = 0; i < n; i++) suma += mat[i][n - 1 - i];
        if (suma != sumaRef) esMagico = false;
    }

    if (esMagico)
        cout << "  [✓] ¡Es un cuadrado mágico! Constante mágica = " << sumaRef << "\n";
    else
        cout << "  [✗] No es un cuadrado mágico: las sumas no coinciden.\n";
}

//  PROBLEMA 14
//  Llenar una matriz 5×5 con los números del 1 al 25,
//  imprimirla y luego imprimirla rotada 90°, 180° y 270°
//  en sentido horario.
//
//  Fórmula de rotación 90° horario:
//    rot[j][n-1-i] = orig[i][j]
//  Aplicando la misma transformación sobre el resultado se
//  obtienen 180° y 270°.
// ============================================================

// Imprime una matriz 5×5 con formato alineado.
static void imprimirMatriz5x5(int mat[FILAS_MAT][COLS_MAT])
{
    for (int i = 0; i < FILAS_MAT; i++) {
        cout << "  ";
        for (int j = 0; j < COLS_MAT; j++)
            cout << (mat[i][j] < 10 ? " " : "") << mat[i][j] << "  ";
        cout << "\n";
    }
}

// Rota la matriz src 90° en sentido horario y guarda en dst.
static void rotar90(int src[FILAS_MAT][COLS_MAT],
                    int dst[FILAS_MAT][COLS_MAT])
{
    for (int i = 0; i < FILAS_MAT; i++)
        for (int j = 0; j < COLS_MAT; j++)
            dst[j][FILAS_MAT - 1 - i] = src[i][j];
}

void problema14()
{
    int original[FILAS_MAT][COLS_MAT];
    int rot90[FILAS_MAT][COLS_MAT];
    int rot180[FILAS_MAT][COLS_MAT];
    int rot270[FILAS_MAT][COLS_MAT];

    // Llenar con 1..25
    int val = 1;
    for (int i = 0; i < FILAS_MAT; i++)
        for (int j = 0; j < COLS_MAT; j++)
            original[i][j] = val++;

    // Calcular rotaciones encadenadas
    rotar90(original, rot90);
    rotar90(rot90,    rot180);
    rotar90(rot180,   rot270);

    cout << "\n  Matriz original:\n";
    imprimirMatriz5x5(original);

    cout << "\n  Rotada 90° (horario):\n";
    imprimirMatriz5x5(rot90);

    cout << "\n  Rotada 180°:\n";
    imprimirMatriz5x5(rot180);

    cout << "\n  Rotada 270° (horario):\n";
    imprimirMatriz5x5(rot270);
}

void problema16(){}
void problema18(){}
