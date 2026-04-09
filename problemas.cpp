#include "problemas.h"
#include <iostream>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()
#include <cstring>   // strlen()
#include <climits>   // INT_MAX
using namespace std;

// ── Prototipos de funciones auxiliares (static)
static bool esCadenaNumerica(const char* cad);
static int  cadenaAEntero(const char* cad);
static int  valorRomano(char c);
static bool esRomanoValido(const char* cad);
static void imprimirMatriz5x5(int mat[FILAS_MAT][COLS_MAT]);
static void rotar90(int src[FILAS_MAT][COLS_MAT],
                    int dst[FILAS_MAT][COLS_MAT]);




//  PROBLEMA 1: Combinación de billetes y monedas

void problema1() {
    int denominaciones[NUM_DENOM] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int cantidad = leerEntero("\n  Ingrese la cantidad de dinero: ", 0, INT_MAX);
    int faltante = cantidad;

    cout << "  Desglose de la cantidad " << cantidad << ":\n";
    for(int i = 0; i < NUM_DENOM; i++) {
        int unidades = faltante / denominaciones[i];
        cout << "  " << denominaciones[i] << " : " << unidades << "\n";
        faltante %= denominaciones[i];
    }
    cout << "  Faltante: " << faltante << "\n";
}

//  PROBLEMA 2
//  Generar 200 letras mayusculas aleatorias, imprimirlas y
//  mostrar cuantas veces se repite cada letra.

void problema2()
{
    char letras[TAM_LETRAS];
    int  frecuencia[26] = {0};   // indice 0 = 'A', 25 = 'Z'

    srand((unsigned int)time(NULL));

    // Generar arreglo
    for (int i = 0; i < TAM_LETRAS; i++) {
        letras[i] = (char)('A' + rand() % 26);
        frecuencia[letras[i] - 'A']++;
    }

    // Imprimir arreglo (20 letras por linea para legibilidad)
    cout << "\n  Arreglo generado:\n  ";
    for (int i = 0; i < TAM_LETRAS; i++) {
        cout << letras[i];
        if ((i + 1) % 20 == 0)
            cout << "\n  ";
    }

    // Imprimir frecuencias (solo letras que aparecen al menos una vez)
    cout << "\n  Frecuencia de cada letra:\n";
    for (int i = 0; i < 26; i++) {
        if (frecuencia[i] > 0)
            cout << "  " << (char)('A' + i) << ": " << frecuencia[i] << "\n";
    }
}


//  PROBLEMA 4
//  Recibir una cadena de caracteres numericos y convertirla
//  a entero sin usar atoi() ni funciones de biblioteca.


// Funcion auxiliar: verifica que todos los caracteres sean digitos
// (permite un '-' inicial para negativos).
static bool esCadenaNumerica(const char* cad)
{
    int i = 0;
    if (cad[0] == '-') i = 1;          // signo opcional
    if (cad[i] == '\0') return false;   // solo '-' no es numero

    for (; cad[i] != '\0'; i++) {
        if (cad[i] < '0' || cad[i] > '9')
            return false;
    }
    return true;
}

// Convierte cadena numerica a int (implementacion manual).
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
        leerCadena("\n  Ingrese una cadena de caracteres numericos: ",
                   cadena, TAM_CADENA);

        if (!esCadenaNumerica(cadena)) {
            cout << "  [!] La cadena contiene caracteres no numericos. "
                    "Intente de nuevo.\n";
        } else {
            valido = true;
        }
    } while (!valido);

    int numero = cadenaAEntero(cadena);
    cout << "  Cadena ingresada : \"" << cadena << "\"\n";
    cout << "  Numero convertido: " << numero << "\n";
}


//  PROBLEMA 6
//  Recibir una cadena y convertir las letras minusculas a
//  mayusculas; los demas caracteres permanecen igual.

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
    cout << "  En mayuscula : " << convertida << "\n";
}


//  PROBLEMA 8
//  Separar los digitos del resto de caracteres en una cadena,
//  generando dos cadenas: una sin numeros y otra solo con ellos.

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
    cout << "  Numero   : " << soloNumeros << "\n";
}


//  PROBLEMA 10
//  Convertir un numero en notacion romana a su equivalente
//  arabigo.
//  Reglas:
//    - Si un caracter es seguido por uno de MAYOR valor → resta.
//    - En cualquier otro caso → suma.


// Devuelve el valor arabigo de un caracter romano (0 si invalido).
static int valorRomano(char c)
{
    switch (c) {
    case 'M': return 1000;
    case 'D': return  500;
    case 'C': return  100;
    case 'L': return   50;
    case 'X': return   10;
    case 'V': return    5;
    case 'I': return    1;
    default:  return    0;
    }
}

// Verifica que la cadena solo contenga caracteres romanos validos.
static bool esRomanoValido(const char* cad)
{
    if (cad[0] == '\0') return false;
    for (int i = 0; cad[i] != '\0'; i++) {
        if (valorRomano(cad[i]) == 0)
            return false;
    }
    return true;
}

void problema10()
{
    char romano[TAM_CADENA];
    bool valido = false;

    do {
        leerCadena("\n  Ingrese un numero romano (ej: DCLXVI): ",
                   romano, TAM_CADENA);

        // Convertir a mayusculas por si el usuario uso minusculas
        for (int i = 0; romano[i] != '\0'; i++) {
            if (romano[i] >= 'a' && romano[i] <= 'z')
                romano[i] = (char)(romano[i] - 32);
        }

        if (!esRomanoValido(romano)) {
            cout << "  [!] La cadena contiene caracteres romanos invalidos.\n"
                 << "      Caracteres validos: M D C L X V I\n";
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

    cout << "  El numero ingresado fue : " << romano    << "\n";
    cout << "  Que corresponde a       : " << resultado << "\n";
}


//  PROBLEMA 12
//  El usuario ingresa una matriz cuadrada NxN; el programa
//  verifica si es un cuadrado magico:
//    1. Todos los numeros son distintos.
//    2. La suma de cada fila, columna y las dos diagonales
//       es la misma constante.


#define MAX_N 10

void problema12()
{
    int n = leerEntero("\n  Tamano de la matriz NxN (N entre 2 y 10): ", 2, MAX_N);

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
        cout << "  [✗] No es un cuadrado magico: hay valores repetidos.\n";
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
        cout << "  [✓] ¡Es un cuadrado magico! Constante magica = " << sumaRef << "\n";
    else
        cout << "  [✗] No es un cuadrado magico: las sumas no coinciden.\n";
}

//  PROBLEMA 14
//  Llenar una matriz 5×5 con los numeros del 1 al 25,
//  imprimirla y luego imprimirla rotada 90°, 180° y 270°
//  en sentido horario.
//  Formula de rotacion 90° horario:
//    rot[j][n-1-i] = orig[i][j]



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


//  PROBLEMA 16
//  Numero de caminos posibles en una malla n×n moviendose
//  unicamente hacia la derecha o hacia abajo.


void problema16()
{
    int n = leerEntero("\n  Tamano de la malla n×n (n entre 1 y 12): ", 1, 12);

    // Calculo iterativo de C(2n, n) usando long long para evitar overflow
    long long caminos = 1;
    for (int i = 1; i <= n; i++) {
        caminos = caminos * (n + i) / i;
    }

    cout << "  Para una malla de " << n << "x" << n
         << " puntos hay " << caminos << " caminos.\n";
}


//  PROBLEMA 17: Números amigables

// Función auxiliar para sumar divisores propios
static int sumaDivisores(int n) {
    int suma = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) suma += i;
    }
    return suma;
}

void problema17() {
    int n = leerEntero("\n  Ingrese un numero para hallar amigables menores a el: ", 2, INT_MAX);
    long long sumaTotalAmigables = 0;

    for (int a = 2; a < n; a++) {
        int b = sumaDivisores(a);
        // Un par (a, b) es amigable si sumaDiv(a)==b y sumaDiv(b)==a, con a != b
        // Evitamos contar dos veces verificando a < b
        if (b > a && b < n) {
            if (sumaDivisores(b) == a) {
                sumaTotalAmigables += (a + b);
            }
        }
    }
    cout << "  El resultado de la suma es: " << sumaTotalAmigables << ".\n";
}


//  PROBLEMA 18
//  Hallar la n-esima permutacion lexicografica de los
//  digitos 0-9 (indexada desde 1).

void problema18()
{
    // Numero maximo de permutaciones de 10 digitos = 10! = 3628800
    long long nMax = 3628800LL;

    long long n = (long long)leerEntero(
        "\n  Ingrese n (entre 1 y 3628800): ", 1, (int)nMax);

    // Precalcular factoriales 0! .. 9!
    long long fact[10];
    fact[0] = 1;
    for (int i = 1; i < 10; i++)
        fact[i] = fact[i - 1] * i;

    // Digitos disponibles
    int disponibles[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int resultado[10];

    n--;  // pasar a indexacion base-0

    for (int i = 9; i >= 0; i--) {
        long long idx = n / fact[i];
        n %= fact[i];

        resultado[9 - i] = disponibles[idx];

        // Eliminar el digito usado desplazando el arreglo
        for (long long j = idx; j < i; j++)
            disponibles[j] = disponibles[j + 1];
    }

    // Calcular el n original para mostrar en el mensaje
    // (ya fue modificado, asi que usamos una variable auxiliar)
    cout << "  La permutacion numero ";
    // Re-leer desde la entrada no es posible aqui; se imprime
    // el arreglo resultado directamente.
    for (int i = 0; i < 10; i++)
        cout << resultado[i];
    cout << "\n";
}
