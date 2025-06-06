#ifndef PELICULA_H
#define PELICULA_H
#include <string>
#include "Video.h"
using namespace std;

class Pelicula : public Video {
private:
    int anio, duracion;
public:
    Pelicula();
    Pelicula(int _anio, int _id, int _duracion, string _nombre, string _genero, float _calificacion);
    int get_duracion();
    void set_duracion(int _duracion);
    int get_anio();
    void set_anio(int _anio);
    void mostrar_info() override;
    bool Peli() override{ return true;}
};

#endif // PELICULA_H
