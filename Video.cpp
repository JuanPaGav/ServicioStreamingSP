#include "Video.h"

Video::Video() {}

Video::Video(int _id, int _duracion, string _nombre, string _genero, float _calificacion) {
    id = _id;
    duracion = _duracion;
    nombre = _nombre;
    genero = _genero;
    this->calificacion = _calificacion;
}

Video::~Video() {}

int Video::get_id() {
    return id;
}

int Video::get_duracion() {
    return duracion;
}

string Video::get_nombre() {
    return nombre;
}

string Video::get_genero() {
    return genero;
}

float Video::get_calificacion() {
    return calificacion;
}

void Video::set_id(int _id) {
    id = _id;
}

void Video::set_duracion(int _duracion) {
    duracion = _duracion;
}

void Video::set_nombre(string _nombre) {
    nombre = _nombre;
}

void Video::set_genero(string _genero) {
    genero = _genero;
}

void Video::set_calificacion(float _calificacion) {
    calificacion = _calificacion;
}
