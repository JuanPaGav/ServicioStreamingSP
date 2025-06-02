//
// Created by mayra miranda moreno on 31/05/25.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Video.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;
extern vector<Video*> todosLosVideos;
vector<Video*> leerVideosDesdeArchivos(const string& nombreArchivo);
void mostrarTodosLosVideos();

#endif //FUNCIONES_H
