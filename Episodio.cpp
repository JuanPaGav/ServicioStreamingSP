//
// Created by jpgav on 27/05/2025.
//

#include "Episodio.h"

Episodio::Episodio() {}

Episodio::Episodio(string _titulo, string _temporada, float _calificacion) {}

string Episodio::get_titulo()
{
    return titulo;
}

string Episodio::get_temporada()
{
    return temporada;
}

float Episodio::get_calificacion()
{
    return calificacion;
}

void Episodio::set_titulo(string _titulo)
{
    titulo = _titulo;
}

void Episodio::set_temporada(string _temporada)
{
    temporada = _temporada;
}

void Episodio::set_calificacion(float _calificacion)
{
    calificacion = _calificacion;
}

void Episodio::mostrar_info()
{
        cout << "Episodio: " << titulo << endl;
        cout << "Temporada: " << temporada << endl;
        cout << "Calificación: " << calificacion << endl;
}
