#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <vector>
#include <string>
using namespace std;

class Serie : public Video {
private:
    int temporadas;
    vector<Episodio> episodios;
public:
    Serie();
    Serie(int _temporadas, int _id, int _duracion, string _nombre, string _genero, float _calificacion);
    void set_temporadas(int _temporadas);
    int get_temporadas();
    void set_episodios(vector<Episodio> _episodios);
    vector<Episodio> get_episodios();
    void agregar_episodio(const Episodio& episodio);
    float get_calificacion() override;
    void mostrar_info() override;
    void mostrar_episodiosCalificacion();
};

#endif // SERIE_H
