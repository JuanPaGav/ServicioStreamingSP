//
// Created by jpgav on 27/05/2025.
//

#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"


class Pelicula : public Video {
private:
    int anio;
public:
    Pelicula();
    Pelicula(int _anio, int _id, int _duracion, string _nombre, string _genero, float _calificacion);
    int get_anio();
    void set_anio(int _anio);
    void mostrar_info() override;
};



#endif //PELICULA_H
