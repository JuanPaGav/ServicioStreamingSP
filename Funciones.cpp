#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
using namespace std;

vector<Video*> todosLosVideos;  // Vector global
vector<Episodio> episodios; // Vector global

//  OP #1 | METODO DE LECTURA Y CONSTRUCCION DE OBJETOS //
vector<Video*> leerVideosDesdeArchivos(const string& nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return todosLosVideos;
    }

    string tipoVideo, etiqueta, valor;

    while (archivo >> tipoVideo) {
        if (tipoVideo == "Pelicula") {
            string nombre, genero;
            int id, duracion, anio;
            float calificacion;

            archivo >> etiqueta >> etiqueta >> valor; id = stoi(valor);
            archivo >> etiqueta >> etiqueta >> nombre;
            archivo >> etiqueta >> etiqueta >> valor; duracion = stoi(valor);
            archivo >> etiqueta >> etiqueta >> genero;
            archivo >> etiqueta >> etiqueta >> valor; calificacion = stof(valor);
            archivo >> etiqueta >> etiqueta >> valor; anio = stoi(valor);

            Pelicula* p = new Pelicula(anio, id, duracion, nombre, genero, calificacion);
            todosLosVideos.push_back(p);
        }

        else if (tipoVideo == "Serie") {
            int id, duracion, temporadas, numEpisodios;
            string nombre, genero;
            float calificacion;

            archivo >> etiqueta >> etiqueta >> valor; id = stoi(valor);
            archivo >> etiqueta >> etiqueta >> nombre;
            archivo >> etiqueta >> etiqueta >> valor; duracion = stoi(valor);
            archivo >> etiqueta >> etiqueta >> genero;
            archivo >> etiqueta >> etiqueta >> valor; calificacion = stof(valor);
            archivo >> etiqueta >> etiqueta >> valor; temporadas = stoi(valor);
            archivo >> etiqueta >> etiqueta >> valor; numEpisodios = stoi(valor);

            for (int i = 0; i < numEpisodios; ++i) {
                string tituloEpi;
                int temporadaEpi;
                float calificacionEpi;

                archivo >> etiqueta >> etiqueta >> tituloEpi;
                archivo >> etiqueta >> etiqueta >> valor; temporadaEpi = stoi(valor);
                archivo >> etiqueta >> etiqueta >> valor; calificacionEpi = stof(valor);

                Episodio ep(tituloEpi, temporadaEpi, calificacionEpi);
                episodios.push_back(ep);
            }

            Serie* s = new Serie(temporadas, id, duracion, nombre, genero, calificacion, numEpisodios, episodios);
            todosLosVideos.push_back(s);
        }
    }

    archivo.close();
    return todosLosVideos;
}


//  OP #2 | METODO PARA ACCEDER A LA INFROMACION DE CADA OBJETO DEL VECTOR VIDEOS  //
void mostrarTodosLosVideos()
{
    if (todosLosVideos.empty())
    {
        cout<<"No hay contenido..."<<endl;
        return;
    }
    for (Video* v: todosLosVideos)
    {
        v->mostrar_info();
    }
}


// OP #4 | METODO PARA MOSTRAR PALICULAS POR CALIFICACION   //
void mostrarCalificacionPeliculas(float calificacion) {
    bool hayCoincidencias = false;

    for (int i = 0; i < todosLosVideos.size(); i++) {
        if (todosLosVideos[i]->get_calificacion() == calificacion) {
            todosLosVideos[i]->mostrar_info();
            hayCoincidencias = true;
        }
    }

    if (!hayCoincidencias) {
        cout << "No se encontraron peliculas con calificación " << calificacion << "." << endl;
    }
}


//  OP #5 | METODO PARA CALIFICAR UN VIDEO POR NOMBRE   //
void calificarVideo(string video_calificar){
    bool encontrado = false;

    for (Video* v : todosLosVideos) {
        if (v->get_titulo() == video_calificar) {
            float calificacion;
            cout << "Ingresa la calificacion del 1-10:" << endl;
            cin >> calificacion;
            v->set_calificacion(calificacion);
            cout << "Se ha actualizado la calificacion." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No tenemos ese titulo en nuestro catalogo. Quieres agregarlo? (Si | No)" << endl;
        string decide_agregar;
        cin >> decide_agregar;

        if (decide_agregar == "No" || decide_agregar == "no") {
            cout << "Regresando al menu..." << endl;
        } else {
            // Pregunta si es película o serie para crear un nuevo objeto
            cout << "Es una Pelicula o una Serie? (p | s): ";
            char tipo;
            cin >> tipo;

            // Capturar atributos comunes
            int id, duracion;
            string titulo, genero;
            float calificacion;

            cout << "Titulo: ";
            cin.ignore(); // importante para limpiar el salto de línea
            getline(cin, titulo);

            cout << "ID: ";
            cin >> id;
            cout << "Duracion: ";
            cin >> duracion;
            cin.ignore();

            cout << "Genero: ";
            getline(cin, genero);

            cout << "Calificacion inicial: ";
            cin >> calificacion;

            if (tipo == 'p') {
                todosLosVideos.push_back(new Pelicula(2024, id, duracion, titulo, genero, calificacion));
            } else if (tipo == 's') {
                int temporadas, num_episodios;
                cout << "Numero de temporadas: ";
                cin >> temporadas;
                cout << "Numero de episodios: ";
                cin >> num_episodios;
                todosLosVideos.push_back(new Serie(temporadas, id, duracion, titulo, genero, calificacion, num_episodios, episodios));
            }

            cout << "Se ha agregado el video al catalogo." << endl;
        }
    }
}