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
    int numEpisodios;
    vector<Episodio> episodios;
public:
    Serie();
    Serie(int _temporadas, int _id, string _titulo, string _genero, float _calificacion, int num_episodios, vector<Episodio> _episodios);
    void set_temporadas(int _temporadas);
    int get_temporadas();
    void set_numEpisodios(int _numEpisodios);
    int get_numEpisodios();
    void set_episodios(vector<Episodio> _episodios);
    vector<Episodio> get_episodios();
    void agregar_episodio(const Episodio& episodio);
    void mostrar_info() override;
    void mostrar_episodiosCalificacion();
};

#endif // SERIE_H
