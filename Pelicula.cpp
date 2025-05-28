//
// Created by jpgav on 27/05/2025.
//

#include "Pelicula.h"

Pelicula::Pelicula() {}

Pelicula::Pelicula(int _anio, int _id, int _duracion, string _nombre, string _genero, float _calificaion) : Video(_id, _duracion, _nombre, _genero, _calificaion), anio(_anio) {}

int Pelicula::get_anio()
{
    return anio;
}

void Pelicula::set_anio(int _anio)
{
    anio = _anio;
}

void Pelicula::mostrar_info()
{
    cout << "Película: " << get_nombre() << endl;
    cout << "Duración: " << get_duracion() << " minutos" << endl;
    cout << "Género: " << get_genero() << endl;
    cout << "Año: " << get_anio() << endl;
    cout << "Calificación: " << get_calificacion() << endl;
}
