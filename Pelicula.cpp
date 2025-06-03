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
    cout << "Pelicula: " << get_titulo() << endl;
    cout << "Duracion: " << get_duracion() << " minutos" << endl;
    cout << "Genero: " << get_genero() << endl;
    cout << "Ano: " << get_anio() << endl;
    cout << "Calificacion: " << get_calificacion() << endl;
    cout << "\n" << endl;
}
