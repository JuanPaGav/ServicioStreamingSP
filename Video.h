#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
using namespace std;

class Video {
private:
    int id, duracion;
    string nombre, genero;
    float calificacion;

public:
    Video();
    Video(int _id, int _duracion, string _nombre, string _genero, float _calificacion);
    virtual ~Video();
    int get_id();
    int get_duracion();
    string get_nombre();
    string get_genero();
    virtual float get_calificacion();
    void set_id(int _id);
    void set_duracion(int _duracion);
    void set_nombre(string _nombre);
    void set_genero(string _genero);
    void set_calificacion(float _calificacion);
    virtual void mostrar_info() = 0;
};

#endif // VIDEO_H
