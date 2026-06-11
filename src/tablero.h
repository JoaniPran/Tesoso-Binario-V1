/*
 * tablero.h
 *
 *  Created on: 09/09/2023
 *      Author: algo2
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casilleros.h"
#include "constantes.h"

#include <iostream>
#include <fstream>

using namespace std;

/*
 * en la estructura Tablero, hay una matriz llamada matriz que contiene elementos del tipo enumerado Casilleros, y
 * tambien guarda los turnos y la cantidad de tesoros de cada jugador
 * ahora acabo de agregar una struct para que guarde la posicion del tesoro encontrado, un iterador para cada jugardor, tambien encontrar que funciona como iterador
 */

typedef struct{
	int fila;
	int columna;
}Posiciones;

typedef struct {
	int encontrar;
	int iterador;
	int turno;
	int tesoros;
	int tesorosRecuperados;
	int turnoEncontrado[TESOROS];
	Posiciones posicionesDeTesoros[TESOROS];
	Casilleros matriz[MAXIMAS_FILAS][MAXIMAS_COLUMNAS];
}Tablero;

/*
 * esta funcion es la encargada de guarda un .txt con la infomracion del estado del tablero, luego de los ingresos corrspondientes para cada jugador.
 */

void escrbirTablero(Tablero &Jugadores, int jugador, string ruta_tablero);


#endif /* TABLERO_H_ */
