//  main.cpp  –  Menú principal y control de flujo
//  Problemas pares: 2, 4, 6, 8, 10, 12, 14, 16, 18


#include "problemas.h"
#include <iostream>
#include <cstring>
using namespace std;

static void mostrarBanner();
static void mostrarMenu();
static void ejecutarOpcion(int opcion);


int main()
{
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("  Seleccione una opcion: ", 0, 11);

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

//  mostrarMenu

static void mostrarMenu()
{
    cout << "  +----------------------------------------------+\n";
    cout << "  |              MENU PRINCIPAL                  |\n";
    cout << "  +----------------------------------------------+\n";
    cout << "  |  1. Problema  1 - Billetes y monedas         |\n";
    cout << "  |  2. Problema  2 - Letras aleatorias          |\n";
    cout << "  |  3. Problema  4 - Cadena numerica a entero   |\n";
    cout << "  |  4. Problema  6 - Convertir a mayusculas     |\n";
    cout << "  |  5. Problema  8 - Separar numeros de texto   |\n";
    cout << "  |  6. Problema 10 - Romano a arabigo           |\n";
    cout << "  |  7. Problema 12 - Cuadrado magico            |\n";
    cout << "  |  8. Problema 14 - Rotacion de matriz 5x5     |\n";
    cout << "  |  9. Problema 16 - Caminos en malla nxn       |\n";
    cout << "  |  10. Problema 17 - Numeros amigables         |\n";
    cout << "  |  11. Problema 18 - Permutacion lexicografica |\n";
    cout << "  |  0. Salir                                    |\n";
    cout << "  +----------------------------------------------+\n";
}

static void ejecutarOpcion(int opcion)
{
    const char* titulos[10] = {
        "",
        "Problema 2  -  Letras mayusculas aleatorias",
        "Problema 4  -  Cadena numerica a entero",
        "Problema 6  -  Convertir minusculas a mayusculas",
        "Problema 8  -  Separar numeros del texto",
        "Problema 10 -  Numero romano a arabigo",
        "Problema 12 -  Verificacion de cuadrado magico",
        "Problema 14 -  Rotacion de matriz 5x5",
        "Problema 16 -  Caminos en malla nxn",
        "Problema 18 -  Permutacion lexicografica de 0-9"
    };

    const char* descripciones[10] = {
        "",
        "Genera 200 letras mayusculas al azar e imprime su frecuencia.",
        "Convierte una cadena de digitos a entero (implementacion manual).",
        "Recibe texto y devuelve letras en mayuscula; otros chars intactos.",
        "Separa los digitos del resto de caracteres en dos cadenas.",
        "Convierte notacion romana a arabigo usando reglas suma/resta.",
        "Verifica si una matriz NxN es cuadrado magico.",
        "Llena la matriz 1-25 y la muestra rotada 90, 180 y 270 grados.",
        "Calcula C(2n,n): rutas posibles en cuadricula moviendose ->v.",
        "Halla la n-esima permutacion lexicografica de los digitos 0-9."
    };

    cout << "\n  +----------------------------------------------+\n";
    cout << "  | " << titulos[opcion];
    int esp = 45 - (int)strlen(titulos[opcion]) - 1;
    for (int i = 0; i < esp; i++) cout << " ";
    cout << "|\n";
    cout << "  +----------------------------------------------+\n";
    cout << "  | " << descripciones[opcion];
    esp = 45 - (int)strlen(descripciones[opcion]) - 1;
    if (esp < 0) esp = 0;
    for (int i = 0; i < esp; i++) cout << " ";
    cout << "|\n";
    cout << "  +----------------------------------------------+\n";

    switch (opcion) {
    case 1: problema1();  break;
    case 2: problema2();  break;
    case 3: problema4();  break;
    case 4: problema6();  break;
    case 5: problema8();  break;
    case 6: problema10(); break;
    case 7: problema12(); break;
    case 8: problema14(); break;
    case 9: problema16(); break;
    case 10: problema17();  break;
    case 11: problema18(); break;
    default: break;
    }
}
