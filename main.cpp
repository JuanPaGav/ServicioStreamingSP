#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Funciones.h"
#include "Episodio.h"
#include "exception"
using namespace std;


int main()
{
    int opcion = -1;
    string nombreArchivo, video_calificar, _titulo;
    float calificacion;

    vector<Episodio> ep_serie1;
    ep_serie1.emplace_back("Metamorfosis", 1, 8.2); //Se usa emplace_back porque el objeto se crea directamente en el vector
    ep_serie1.emplace_back("Fiesta en la piscina", 1, 9.0);
    ep_serie1.emplace_back("Pesca del dia", 1, 9.5);

    Serie* Serie1 = new Serie(1, 12, 20, "H2O sirenas del mar", "drama", 9.5,3, ep_serie1);

    todosLosVideos.push_back(Serie1);

    while (opcion != 0) {
        cout << "\n--- MENU DE OPCIONES ---\n";
        cout << "1. Cargar archivo de datos\n"; //  Listo
        cout << "2. Mostrar videos\n"; //  Listo
        cout << "3. Mostrar episodios de una serie con calificacion\n"; //  En proceso...
        cout << "4. Mostrar peliculas con cierta calificacion\n";   // Listo
        cout << "5. Calificar un video\n";  //  En proceso...
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
            cout << endl;
            mostrarTodosLosVideos();
            break;

        case 3:
            // mostrar_episodiosCalificacion();
            cout << "¿Que serie quieres ver?" << endl;
            getline(cin, _titulo);
            if (todosLosVideos.empty()){
                cout<<"No hay contenido..."<<endl;
            }
            for (Video* v : todosLosVideos) {
                if (v->get_titulo() == _titulo) {
                    // Intentar convertir v a Serie*
                    Serie* s = dynamic_cast<Serie*>(v);
                    if (s != nullptr) {
                        s->mostrar_episodiosCalificacion();
                    } else {
                        cout << "Ese título no corresponde a una serie con episodios." << endl;
                    }
                }
            }
            break;

        case 4:
            //  Hace falta añadir quizá película que tengan una calificación cercana a lo que introduzca el usurario.  //
            cout << "Ingrese la calificacion a buscar (por ejemplo 4.0): " << endl;
            cin >> calificacion;
            mostrarCalificacionPeliculas(calificacion);
            break;

        case 5:
            cout << "Que video quieres calificar?" << endl;
            cin.ignore();
            getline(cin, video_calificar);
            calificarVideo(video_calificar);
            break;

        case 0:
            cout << "Saliendo del programa.\n";
            exit(0);

        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
    return 0;
}
