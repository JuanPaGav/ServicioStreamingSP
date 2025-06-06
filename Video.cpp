#include "Video.h"

Video::Video() {}

Video::Video(int _id, string _titulo, string _genero, float _calificacion)
{
    id = _id;
    titulo = _titulo;
    genero = _genero;
    this->calificacion = _calificacion;
}

Video::~Video(){}

int Video::get_id()
{
    return id;
}

string Video::get_titulo()
{
    return titulo;
}

string Video::get_genero()
{
    return genero;
}

float Video::get_calificacion()
{
    return calificacion;
}

void Video::set_id(int _id)
{
    id = _id;
}

void Video::set_titulo(string _titulo)
{
    titulo = _titulo;
}

void Video::set_genero(string _genero)
{
    genero = _genero;
}

void Video::set_calificacion(float _calificacion)
{
    calificacion = _calificacion;
}
