#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
using namespace std;

class Video {
private:
    int id;
    string titulo, genero;
    float calificacion;

public:
    Video();
    Video(int _id, string _titulo, string _genero, float _calificacion);
    virtual ~Video();
    int get_id();
    void set_id(int _id);
    string get_titulo();
    void set_titulo(string _titulo);
    string get_genero();
    void set_genero(string _genero);
    virtual float get_calificacion();
    virtual void set_calificacion(float _calificacion);
    virtual void mostrar_info() = 0;
    virtual bool Peli(){ return false;}
};

#endif // VIDEO_H
