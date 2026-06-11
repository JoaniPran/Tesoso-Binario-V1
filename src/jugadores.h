/*
 * jugadores.h
 *
 *  Created on: 10/09/2023
 *      Author: algo2
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_

#include "tablero.h"

/*
 * crea un nuevo tipo de dato llamado jugador, que es un arreglo de Tableros con un tamaño especificado por la constante CANTIDAD_DE_JUGADORES
 */

typedef Tablero jugador[CANTIDAD_DE_JUGADORES];

/*
 *inicializa a los jugadores dependiendo la cantidad de los mismos,
 *inicializa derivandolos a las demas funciones ej:coloar tesoro, espia, mover tesoro etc...
 */

void inicioJugadores(Tablero Jugadores[CANTIDAD_DE_JUGADORES]);


#endif /* JUGADORES_H_ */
