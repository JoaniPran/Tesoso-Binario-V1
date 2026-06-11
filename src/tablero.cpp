/*
 * tablero.cpp
 *
 *  Created on: 10/09/2023
 *      Author: algo2
 */



#include "tablero.h"

using namespace std;

void escrbirTablero(Tablero &Jugadores, int jugador, string ruta_tablero){

	ofstream salida;

	salida.open(ruta_tablero.c_str());

    for (int i = 0; i < MAXIMAS_FILAS; i++) {
        for (int j = 0; j < MAXIMAS_COLUMNAS; j++) {
            if (Jugadores.matriz[i][j] == VACIO) {
            	salida << "[ ]";
            } else if (Jugadores.matriz[i][j] == CONESPIA) {
            	salida << "[S]";
            } else if (Jugadores.matriz[i][j] == CONTESORO) {
            	salida << "[T]";
            } else if (Jugadores.matriz[i][j] == ENPROCESO) {
            	salida << "[X]";
            }
        }
        salida << endl;
    }

    salida << endl << "Turno:" << Jugadores.turno << endl;
    salida << "Jugador:" << jugador << endl;
    salida << "Tesoros:" << Jugadores.tesoros << endl << endl;
    salida << "Tesoros recuperados:" << Jugadores.tesorosRecuperados << endl << endl;

}

