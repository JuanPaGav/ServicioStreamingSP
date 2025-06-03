#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Funciones.h"
#include "Episodio.h"
using namespace std;


int main()
{
    int opcion = -1;
    string nombreArchivo, video_calificar;

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
            cout << "¿Que serie quieres ver?" << endl;
            // mostrar_episodiosCalificacion();
            break;

        case 4:
            float calificacion;
            cout << "Ingrese la calificación a buscar (por ejemplo 4.0): ";
            cin >> calificacion;
            // mostrarCalificacionPeliculas(peliculas, calificacion);
            break;

        case 5:
            cout << "¿Qué video quieres calificar?" << endl;
            cin.ignore();
            getline(cin, video_calificar);
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
