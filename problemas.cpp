
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
void problema10(){}
void problema12(){}
void problema14(){}
void problema16(){}
void problema18(){}
