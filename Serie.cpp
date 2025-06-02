#include "Serie.h"
#include <iostream>
using namespace std;

Serie::Serie() : Video() {
    temporadas = 0;
}

Serie::Serie(int _temporadas, int _id, int _duracion, string _nombre, string _genero, float _calificacion)
    : Video(_id, _duracion, _nombre, _genero, _calificacion), temporadas(_temporadas) {}

void Serie::set_temporadas(int _temporadas) {
    temporadas = _temporadas;
}

int Serie::get_temporadas() {
    return temporadas;
}

void Serie::set_episodios(vector<Episodio> _episodios) {
    episodios = _episodios;
}

vector<Episodio> Serie::get_episodios() {
    return episodios;
}

void Serie::agregar_episodio(const Episodio& episodio) {
    episodios.push_back(episodio);
}

float Serie::get_calificacion() {

    if (episodios.empty()) return 0.0f;

    float suma = 0.0f;
    for (Episodio& ep: episodios)
        suma += ep.get_calificacion();

    return suma / episodios.size();

}

void Serie::mostrar_info() {
    cout << "Serie: " << get_nombre() << endl;
    cout << "Temporadas: " << temporadas << endl;
    cout << "Genero: " << get_genero() << endl;
    cout << "Duracion: " << get_duracion() << " minutos" << endl;
    cout << "Calificacion promedio: " << get_calificacion() << endl;
    cout << "Episodios:\n";
    cout << "\n" << endl;

    for (Episodio& ep : episodios) {
        ep.mostrar_info();
        cout << "-----\n";
    }
}
