/*
 * juego.h
 *
 *  Created on: 10/09/2023
 *      Author: algo2
 */

#ifndef JUEGO_H_
#define JUEGO_H_


#include "tablero.h"
#include "jugadores.h"


/*
 *LA funcion se encarga de comparar los ingresos de ambos jugadores
 *e ira mostrando los avisos segun las reglas establecidas, tambien se encarga de quitar o añadir tesoros en caso de ser o no capturados
 *e dependiendo el turno el cual tambien se encargade regular.
 */

int juego(Tablero &JugadorUno, Tablero &JugadorDos, int jugador);

/*
 * inicia todo el tablero de los jugadores en vacio
 */

void InicialJuego(Tablero &Jugadores);




#endif /* JUEGO_H_ */
