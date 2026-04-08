// ============================================================
//  main.cpp  –  Menú principal y control de flujo
//  Problemas pares: 2, 4, 6, 8, 10, 12, 14, 16, 18
// ============================================================

#include "practica2.h"
#include <iostream>
#include <cstring>
using namespace std;

// ── Prototipos locales (sólo usados aquí) ───────────────────
static void mostrarBanner();
static void mostrarMenu();
static void ejecutarOpcion(int opcion);


int main()
{
    int opcion;

    mostrarBanner();

    do {
        mostrarMenu();
        opcion = leerEntero("  Seleccione una opción: ", 0, 9);

        if (opcion != 0) {
            limpiarPantalla();
            ejecutarOpcion(opcion);
            pausar();
            limpiarPantalla();
        }

    } while (opcion != 0);

    cout << "\n  ¡Hasta luego!\n\n";
    return 0;
}



// ============================================================
//  mostrarMenu
// ============================================================
static void mostrarMenu()
{
    cout << "  ┌──────────────────────────────────────────────┐\n";
    cout << "  │                   MENÚ PRINCIPAL             │\n";
    cout << "  ├──────────────────────────────────────────────┤\n";
    cout << "  │  1. Problema  2 – Letras aleatorias          │\n";
    cout << "  │  2. Problema  4 – Cadena numérica a entero   │\n";
    cout << "  │  3. Problema  6 – Convertir a mayúsculas     │\n";
    cout << "  │  4. Problema  8 – Separar números de texto   │\n";
    cout << "  │  5. Problema 10 – Romano a arábigo           │\n";
    cout << "  │  6. Problema 12 – Cuadrado mágico            │\n";
    cout << "  │  7. Problema 14 – Rotación de matriz 5×5     │\n";
    cout << "  │  8. Problema 16 – Caminos en malla n×n       │\n";
    cout << "  │  9. Problema 18 – Permutación lexicográfica  │\n";
    cout << "  │  0. Salir                                    │\n";
    cout << "  └──────────────────────────────────────────────┘\n";
}

// ============================================================
//  ejecutarOpcion
//  Muestra encabezado del problema seleccionado y lo lanza.
// ============================================================
static void ejecutarOpcion(int opcion)
{
    // Títulos y descripciones breves de cada problema
    const char* titulos[10] = {
        "",   // índice 0 no se usa
        "Problema 2  –  Letras mayúsculas aleatorias",
        "Problema 4  –  Cadena numérica a entero",
        "Problema 6  –  Convertir minúsculas a mayúsculas",
        "Problema 8  –  Separar números del texto",
        "Problema 10 –  Número romano a arábigo",
        "Problema 12 –  Verificación de cuadrado mágico",
        "Problema 14 –  Rotación de matriz 5×5",
        "Problema 16 –  Caminos en malla n×n",
        "Problema 18 –  Permutación lexicográfica de 0-9"
    };

    const char* descripciones[10] = {
        "",
        "Genera 200 letras mayúsculas al azar e imprime la frecuencia de cada una.",
        "Convierte una cadena de dígitos a número entero (implementación manual).",
        "Recibe un texto y devuelve las letras en mayúscula; otros chars intactos.",
        "Separa los dígitos del resto de caracteres en dos cadenas.",
        "Convierte notación romana a arábigo usando las reglas de suma/resta.",
        "Verifica si una matriz NxN es un cuadrado mágico (filas, cols, diagonales).",
        "Llena la matriz 1-25 y la muestra rotada 90°, 180° y 270°.",
        "Calcula C(2n,n): rutas posibles en una cuadrícula moviéndose →↓.",
        "Halla la n-ésima permutación lexicográfica de los dígitos 0 al 9."
    };

    // Encabezado del problema
    cout << "\n  ╔══════════════════════════════════════════════╗\n";
    cout << "  ║  " << titulos[opcion];
    // Rellenar con espacios hasta el borde del cuadro
    int espacios = 44 - (int)strlen(titulos[opcion]) - 2;
    for (int i = 0; i < espacios; i++) cout << " ";
    cout << "║\n";
    cout << "  ╠══════════════════════════════════════════════╣\n";
    cout << "  ║  " << descripciones[opcion];
    espacios = 44 - (int)strlen(descripciones[opcion]) - 2;
    // Si la descripción es muy larga la cortamos al borde
    if (espacios < 0) espacios = 0;
    for (int i = 0; i < espacios; i++) cout << " ";
    cout << "║\n";
    cout << "  ╚══════════════════════════════════════════════╝\n";

    // Despachar al problema correspondiente
    switch (opcion) {
    case 1: problema2();  break;
    case 2: problema4();  break;
    case 3: problema6();  break;
    case 4: problema8();  break;
    case 5: problema10(); break;
    case 6: problema12(); break;
    case 7: problema14(); break;
    case 8: problema16(); break;
    case 9: problema18(); break;
    default: break;
    }
}
