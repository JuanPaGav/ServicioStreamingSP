//
// Created by jpgav on 27/05/2025.
//

#include "Episodio.h"

Episodio::Episodio() {}

Episodio::Episodio(string _titulo, int _temporada, float _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

string Episodio::get_titulo()
{
    return titulo;
}

int Episodio::get_temporada()
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

void Episodio::set_temporada(int _temporada)
{
    temporada = _temporada;
}

void Episodio::set_calificacion(float _calificacion)
{
    calificacion = _calificacion;
}

void Episodio::mostrar_info()
{
    cout << "Episodio: " << get_titulo() << endl;
    cout << "Temporada: " << get_temporada() << endl;
    cout << "Calificacion: " << get_calificacion() << endl;
}
