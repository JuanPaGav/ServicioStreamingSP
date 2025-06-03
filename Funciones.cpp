#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
using namespace std;

vector<Video*> todosLosVideos;  // Vector global

vector<Video*> leerVideosDesdeArchivos(const string& nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout<<"No se pudo abrir el archivo"<<endl;
        return todosLosVideos;
    }

    string tipoVideo, etiqueta, valor;

    while (archivo >> tipoVideo) {
    if (tipoVideo == "Pelicula") {
        string  nombre, genero;
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
        int id, duracion, anio, temporadas;
        string nombre, genero;
        float calificacion;


        archivo >> etiqueta >> etiqueta >> valor; id = stoi(valor);
        archivo >> etiqueta >> etiqueta >> nombre;
        archivo >> etiqueta >> etiqueta >> valor; duracion = stoi(valor);
        archivo >> etiqueta >> etiqueta >> genero;
        archivo >> etiqueta >> etiqueta >> valor; calificacion = stof(valor);
        archivo >> etiqueta >> etiqueta >> valor; anio = stoi(valor);
        archivo >> etiqueta >> etiqueta >> valor; temporadas = stoi(valor);


        Serie* s = new Serie(temporadas, id, duracion, nombre, genero, calificacion);
        todosLosVideos.push_back(s);
    }
}
    archivo.close();
    return todosLosVideos;
}


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

void calificarVideo(string video_calificar){
    bool encontrado = false;

    for (Video* v : todosLosVideos) {
        if (v->get_titulo() == video_calificar) {
            float calificacion;
            cout << "Ingresa la calificación del 1-10:" << endl;
            cin >> calificacion;
            v->set_calificacion(calificacion);
            cout << "Se ha actualizado la calificación." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No tenemos ese título en nuestro catálogo. ¿Quieres agregarlo? (Sí/No)" << endl;
        string decide_agregar;
        cin >> decide_agregar;

        if (decide_agregar == "No" || decide_agregar == "no") {
            cout << "Regresando al menú..." << endl;
        } else {
            // Pregunta si es película o serie para crear un nuevo objeto
            cout << "¿Es una Película o una Serie? (p/s): ";
            char tipo;
            cin >> tipo;

            // Capturar atributos comunes
            int id, duracion;
            string titulo, genero;
            float calificacion;

            cout << "Título: ";
            cin.ignore(); // importante para limpiar el salto de línea
            getline(cin, titulo);

            cout << "ID: ";
            cin >> id;
            cout << "Duración: ";
            cin >> duracion;
            cin.ignore();

            cout << "Género: ";
            getline(cin, genero);

            cout << "Calificación inicial: ";
            cin >> calificacion;

            if (tipo == 'p') {
                todosLosVideos.push_back(new Pelicula(2024, id, duracion, titulo, genero, calificacion));
            } else if (tipo == 's') {
                int temporadas;
                cout << "Número de temporadas: ";
                cin >> temporadas;
                todosLosVideos.push_back(new Serie(temporadas, id, duracion, titulo, genero, calificacion));
            }

            cout << "Se ha agregado el video al catálogo." << endl;
        }
    }
}


