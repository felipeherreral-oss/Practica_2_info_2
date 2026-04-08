// ============================================================
//  utils.cpp  -  Funciones de utilidad reutilizables
//  Informatica II - Universidad de Antioquia
// ============================================================

#include "problemas.h"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>
using namespace std;

int leerEntero(const char* mensaje, int min, int max)
{
    int  valor;
    bool valido = false;

    do {
        cout << mensaje;

        if (!(cin >> valor)) {
            cin.clear();
            string basura;
            getline(cin, basura);
            cout << "  [!] Entrada invalida. Ingrese un numero entero";
            if (min != INT_MIN && max != INT_MAX)
                cout << " entre " << min << " y " << max;
            cout << ".\n";
        } else {
            string basura;
            getline(cin, basura);
            if (valor < min || valor > max) {
                cout << "  [!] Valor fuera de rango. Debe estar entre "
                     << min << " y " << max << ".\n";
            } else {
                valido = true;
            }
        }
    } while (!valido);

    return valor;
}

void leerCadena(const char* mensaje, char* destino, int tamMax)
{
    cout << mensaje;
    // Limpia cualquier residuo en el buffer antes de leer la cadena
    if (cin.peek() == '\n') cin.ignore();

    string linea;
    getline(cin, linea);

    int n = (int)linea.size();
    if (n > tamMax - 1) n = tamMax - 1;

    for (int i = 0; i < n; i++) {
        destino[i] = linea[i];
    }
    destino[n] = '\0'; // Aseguramos siempre el fin de cadena
}

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar()
{
    cout << "\n  Presione Enter para continuar...";
    string basura;
    getline(cin, basura);
}
