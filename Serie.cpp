#include "Serie.h"
#include <iostream>
using namespace std;

Serie::Serie() : Video() {
    temporadas = 0;
}

Serie::Serie(int _temporadas, int _id, int _duracion, string _titulo, string _genero, float _calificacion, int _numEpisodios,vector<Episodio> _episodios)
    :Video(_id, _duracion, _titulo, _genero, _calificacion), temporadas(_temporadas), numEpisodios(_numEpisodios),episodios(_episodios) {}

void Serie::set_temporadas(int _temporadas) {
    temporadas = _temporadas;
}

int Serie::get_temporadas() {
    return temporadas;
}

void Serie::set_numEpisodios(int _numEpisodios)
{
    numEpisodios = _numEpisodios;
}

int Serie::get_numEpisodios()
{
    return numEpisodios;
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

void Serie::mostrar_info() {
    cout << "Serie: " << get_titulo() << endl;
    cout << "Temporadas: " << get_temporadas() << endl;
    cout << "Genero: " << get_genero() << endl;
    cout << "Duracion: " << get_duracion() << " minutos" << endl;
    cout << "Calificacion promedio: " << get_calificacion() << endl;
    cout << "Numero de episodios: " << get_numEpisodios() << endl;;
    cout << "-----" << endl;
    for (Episodio& ep : episodios) {
        ep.mostrar_info();
        cout << "-----\n";
    }
    cout << endl;
}

void Serie::mostrar_episodiosCalificacion(){
    if (get_episodios().size()==0){
        cout<<"Esta serie aan no tiene episodios"<<endl;
    }
    cout << "--------------------------" << get_titulo() << "--------------------------" << endl;
    for (int i= 1; i <= get_temporadas(); i++)
    {
        cout<< "Temporada "<<i<<endl;
        for (Episodio& ep : episodios) {
            if (ep.get_temporada() == i){
                cout << "  " << ep.get_titulo()
                << " | Calificación: " << ep.get_calificacion() << endl;
            }
        }
        cout << "\n";
    }
}