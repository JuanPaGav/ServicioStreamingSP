#ifndef PELICULA_H
#define PELICULA_H
#include <string>
#include "Video.h"
using namespace std;

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

#endif // PELICULA_H
