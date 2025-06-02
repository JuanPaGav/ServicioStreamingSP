#include <iostream>
#include <fstream>
#include <string>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
using namespace std;

extern vector<Video*> todosLosVideos;
vector<Video*> leerVideosDesdeArchivos(const string& nombreArchivo);
void mostrarTodosLosVideos();

int main()
{
    int opcion = -1;
    string nombreArchivo;

    while (opcion != 0) {
        cout << "\n--- MENU DE OPCIONES ---\n";
        cout << "1. Cargar archivo de datos\n";
        cout << "2. Mostrar videos por calificacion\n";
        cout << "3. Mostrar episodios de una serie con calificacion\n";
        cout << "4. Mostrar peliculas con cierta calificacion\n";
        cout << "5. Calificar un video\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: \n";
        cin >> opcion;

        switch(opcion) {
        case 1:
            nombreArchivo = "../Datos.txt";
            cout << "Cargando archivo desde '" << nombreArchivo << "'...\n";
            leerVideosDesdeArchivos(nombreArchivo);
            cout << "Se cargaron " << todosLosVideos.size() << " videos.\n";
            mostrarTodosLosVideos();
            break;
        case 2:
            cout << "Mostrando videos filtrados...\n";
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
