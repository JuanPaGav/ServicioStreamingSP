#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
using namespace std;

vector<Video*> todosLosVideos;  // Vector global
vector<Episodio> episodios; // Vector global

//  OP #1 | METODO DE LECTURA Y CONSTRUCCION DE OBJETOS //
vector<Video*> leerVideosDesdeArchivos(const string& nombreArchivo)
{
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return todosLosVideos;
    }

    string tipoVideo, etiqueta, valor;

    while (archivo >> tipoVideo) {
        if (tipoVideo == "Pelicula") {
            string nombre, genero;
            int id, duracion, anio;
            float calificacion;

            archivo >> etiqueta >> etiqueta >> valor; id = stoi(valor);
            archivo >> etiqueta >> etiqueta; getline(archivo, nombre); nombre = nombre.substr(1);
            archivo >> etiqueta >> etiqueta >> valor; duracion = stoi(valor);
            archivo >> etiqueta >> etiqueta; getline(archivo, genero); genero = genero.substr(1);
            archivo >> etiqueta >> etiqueta >> valor; calificacion = stof(valor);
            archivo >> etiqueta >> etiqueta >> valor; anio = stoi(valor);

            Pelicula* p = new Pelicula(anio, id, duracion, nombre, genero, calificacion);
            todosLosVideos.push_back(p);
        }

        else if (tipoVideo == "Serie") {
            int id, duracion, temporadas, numEpisodios;
            string nombre, genero;
            float calificacion;

            archivo >> etiqueta >> etiqueta >> valor; id = stoi(valor);
            archivo >> etiqueta >> etiqueta; getline(archivo,nombre); nombre = nombre.substr(1);
            archivo >> etiqueta >> etiqueta; getline(archivo, genero); genero = genero.substr(1);
            archivo >> etiqueta >> etiqueta >> valor; calificacion = stof(valor);
            archivo >> etiqueta >> etiqueta >> valor; temporadas = stoi(valor);
            archivo >> etiqueta >> etiqueta >> valor; numEpisodios = stoi(valor);

            for (int i = 0; i < numEpisodios; ++i) {
                string tituloEpi;
                int temporadaEpi;
                float calificacionEpi;

                archivo >> etiqueta >> etiqueta; getline(archivo, tituloEpi); tituloEpi = tituloEpi.substr(1);
                archivo >> etiqueta >> etiqueta >> valor; temporadaEpi = stoi(valor);
                archivo >> etiqueta >> etiqueta >> valor; calificacionEpi = stof(valor);

                Episodio ep(tituloEpi, temporadaEpi, calificacionEpi);
                episodios.push_back(ep);
            }

            Serie* s = new Serie(temporadas, id, nombre, genero, calificacion, numEpisodios, episodios);
            todosLosVideos.push_back(s);
        }
    }
    archivo.close();
    return todosLosVideos;
}


//  OP #2 | METODO PARA ACCEDER A LA INFROMACION DE CADA OBJETO DEL VECTOR VIDEOS  //
void mostrarTodosLosVideos()
{
    if (todosLosVideos.empty())
    {
        cout<<"No hay contenido..."<<endl;
        return;
    }
    for (Video* v: todosLosVideos)
    {
        v->mostrar_info();
    }
}


// OP #4 | METODO PARA MOSTRAR PALICULAS POR CALIFICACION   //
void mostrarCalificacionPeliculas(float calificacion) {
    bool hayCoincidencias = false;

    for (int i = 0; i < todosLosVideos.size(); i++) {
        if (todosLosVideos[i]->Peli())
        {
            float calif = todosLosVideos[i]->get_calificacion();
            if (calif >= (calificacion - 0.5) && calif <= (calificacion + 1.0)) {
                todosLosVideos[i]->mostrar_info();
                hayCoincidencias = true;
            }
        }
    }

    if (!hayCoincidencias) {
        cout << "No se encontraron peliculas con calificacion " << calificacion << "." << endl;
    }
}


//  OP #5 | METODO PARA CALIFICAR UN VIDEO POR NOMBRE   //
void calificarVideo(string video_calificar)
{
    bool encontrado = false;

    for (Video* v : todosLosVideos) {
        if (v->get_titulo() == video_calificar) {
            float calificacion;
            cout << "Ingresa la calificacion del 1-10:" << endl;
            cin >> calificacion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Entrada invalida. Debe ser un numero." << endl;
                return;
            }

            if (calificacion < 1 || calificacion > 10) {
                cout << "Error: La calificacion debe estar entre 1 y 10." << endl;
                return;
            }

            v->set_calificacion(calificacion);
            cout << "Se ha actualizado la calificacion." << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        try {
            cout << "No tenemos ese titulo en nuestro catalogo. Quieres agregarlo? (Si | No)" << endl;
            string decide_agregar;
            cin >> decide_agregar;

            if (decide_agregar != "Si" && decide_agregar != "si" && decide_agregar != "No" && decide_agregar != "no") {
                throw invalid_argument("Respuesta invalida. Escribe 'Si' o 'No'.");
            }

            if (decide_agregar == "No" || decide_agregar == "no") {
                cout << "Regresando al menu..." << endl;
                return;
            }

            cout << "Es una Pelicula o una Serie? (p | s): " << endl;
            char tipo;
            cin >> tipo;
            if (tipo != 'p' && tipo != 's') {
                throw invalid_argument("Tipo invalido. Escribe 'p' para película o 's' para serie.");
            }

            int id, duracion;
            string titulo, genero;
            float calificacion;

            cout << "Titulo: ";
            cin.ignore();
            getline(cin, titulo);
            if (cin.fail()) {
                cin.clear();
                throw invalid_argument("Titulo invalido. Debe ser texto.");
            }

            cout << "ID: ";
            cin >> id;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("ID invalido. Debe ser un numero entero.");
            }

            cout << "Duracion: ";
            cin >> duracion;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Duracion invalida. Debe ser un numero entero.");
            }
            cin.ignore();

            cout << "Genero: ";
            getline(cin, genero);

            cout << "Calificacion inicial: ";
            cin >> calificacion;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Calificacion invalida. Debe ser un numero.");
            }

            if (tipo == 'p') {
                int anio;
                cout << "Anio: ";
                cin >> anio;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Anio invalido. Debe ser un numero entero.");
                }
                todosLosVideos.push_back(new Pelicula(anio, id, duracion, titulo, genero, calificacion));
            } else if (tipo == 's') {
                int temporadas, num_episodios;
                cout << "Numero de temporadas: ";
                cin >> temporadas;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Numero de temporadas invalido. Debe ser un numero entero.");
                }

                cout << "Desea agregar episodios ahora? (Si | No): ";
                string respuesta_epi;
                cin >> respuesta_epi;
                if (cin.fail()) {
                    cin.clear();
                    throw invalid_argument("Respuesta invalida. Debe ser texto.");
                }

                vector<Episodio> nuevos_episodios;
                num_episodios = 0;

                if (respuesta_epi == "Si" || respuesta_epi == "si") {
                    cout << "Cuantos episodios deseas agregar? ";
                    cin >> num_episodios;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw invalid_argument("Numero de episodios invalido. Debe ser un numero entero.");
                    }
                    cin.ignore();

                    for (int i = 0; i < num_episodios; ++i) {
                        string titulo_ep;
                        int temporada_ep;
                        float calificacion_ep;

                        cout << "Titulo: ";
                        getline(cin, titulo_ep);
                        cin.ignore();

                        cout << "Temporada: ";
                        cin >> temporada_ep;

                        cout << "Calificacion: ";
                        cin >> calificacion_ep;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            throw invalid_argument("Calificacion invalida. Debe ser un numero.");
                        }
                        cin.ignore();

                        nuevos_episodios.emplace_back(titulo_ep, temporada_ep, calificacion_ep);
                    }
                }

                todosLosVideos.push_back(new Serie(temporadas, id, titulo, genero, calificacion, num_episodios, nuevos_episodios));
            }

            cout << "Se ha agregado el video al catalogo." << endl;

        } catch (invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        } catch (out_of_range& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}
