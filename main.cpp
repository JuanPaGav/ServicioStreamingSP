#include <iostream>
#include <fstream>
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Funciones.h"
#include "Episodio.h"
using namespace std;


int main()
{
    int opcion = -1;
    string nombreArchivo;

    while (opcion != 0) {
        cout << "\n--- MENU DE OPCIONES ---\n";
        cout << "1. Cargar archivo de datos\n"; //  Listo
        cout << "2. Mostrar videos\n"; //  Checar con la miss
        cout << "3. Mostrar episodios de una serie con calificacion\n"; //  Mayra
        cout << "4. Mostrar peliculas con cierta calificacion\n";   // Miguel
        cout << "5. Calificar un video\n";
        cout << "0. Salir\n";   //  Listo
        cout << "Ingrese una opcion: \n";
        cin >> opcion;

        switch(opcion) {
        case 1:
            nombreArchivo = "../Datos.txt";
            cout << "Cargando archivo desde '" << nombreArchivo << "'...\n";
            leerVideosDesdeArchivos(nombreArchivo);
            cout << "Se cargaron " << todosLosVideos.size() << " videos.\n";
            cout << "\n" << endl;
            //mostrarTodosLosVideos();
            break;
        case 2:
            cout << "Buscando contenido...\n";
            mostrarTodosLosVideos();
            break;

        case 3:
            cout << "Mostrando episodios de una serie...\n";
            break;

        case 4:
            cout << "Mostrando peliculas...\n";
            break;

        case 5:
            cout << "Ingrese titulo y calificación...\n";
            break;

        case 0:
            cout << "Saliendo del programa.\n";
            exit(0);

        default:
            cout << "Opción invalida. Intente de nuevo.\n";
        }
    }
    return 0;
}
