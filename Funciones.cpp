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

//void def mostrarEpisodios():


