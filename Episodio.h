#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include <string>
using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;
    float calificacion;
public:
    Episodio();
    Episodio(string _titulo, int _temporada, float _calificacion);
    string get_titulo();
    int get_temporada();
    float get_calificacion();
    void set_titulo(string _titulo);
    void set_temporada(int _temporada);
    void set_calificacion(float _calificacion);
    void mostrar_info();
};

#endif // EPISODIO_H
