//
// Created by jpgav on 27/05/2025.
//

#include "Pelicula.h"

Pelicula::Pelicula() {}

Pelicula::Pelicula(int _anio, int _id, int _duracion, string _nombre, string _genero, float _calificaion) : Video(_id, _nombre, _genero, _calificaion), anio(_anio), duracion(_duracion) {}

int Pelicula::get_anio()
{
    return anio;
}

void Pelicula::set_anio(int _anio)
{
    anio = _anio;
}

int Pelicula::get_duracion()
{
    return duracion;
}

void Pelicula::set_duracion(int _duracion)
{
    duracion = _duracion;
}

void Pelicula::mostrar_info()
{
    cout << "****************************************" << endl;
    cout << "Tipo: Pelicula" << endl;
    cout << "Titulo: " << get_titulo() << endl;
    cout << "Duracion: " << get_duracion() << " minutos" << endl;
    cout << "Genero: " << get_genero() << endl;
    cout << "Anio: " << get_anio() << endl;
    cout << "Calificacion: " << get_calificacion() << endl;
    cout << "****************************************\n" << endl;
}
