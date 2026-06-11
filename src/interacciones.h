/*
 * interacciones.h
 *
 *  Created on: 09/09/2023
 *      Author: algo2
 */

#ifndef INTERACCIONES_H_
#define INTERACCIONES_H_

#include "tablero.h"



/*
 * se encarga de mostrar el tablero en tiempo real
 */
void mostrarTablero(Tablero &Jugadores);

/*
 * esta funcion es la encargada de la interaccion entre el jugador y el juego.
 * ya que dependiendo el turno esta misma habilitara el ingreso de tesoros, espias, o mover el tesoro
 */
void interacciones(Tablero &Jugadores, Tablero &jugadorComparar);

/*
 *se utiliza en diversas partes del codigo para el ingreso de distintos datos,
 *como en donde mover el tesoro, donde colocar los espias, y deonde colocar el tesoro
 */
void ingresoDeDatos(int &fila,int  &columna);

/*
 * ingresa los espias al juego, verficando que se hayan colocando en una posicion valida,
 * osea donde no haya un tesoro propio o un espia propio y la celda no este en proceso
 */

void ingresoEspias(Tablero &Jugadores);

/*
 * ingresa los tensoros en los lugares correspondientes validando que no se ingrese un tesoro encima de otro y tampoco otro encima de otro jugador.
 */

void ingresoTesoros(Tablero &Jugadores, Tablero &jugadorComparar);

/*
 * el usurario puede optar por mover el tesoro o no, en caso de moverlo esta funcion es la encargada de desplazarlo
 * y verificar si hay o no un tesoro enemigo en la posicion que el usuario decio correrlo,
 * tambien verifica que el movimiento del mismo sea dentro de las reglas establecidas en el manual de usuario(de a un casillero, horizontal, vertical, diagonal)
 */

void moverTesoro(Tablero &Jugadores,Tablero &jugadorComparar);


#endif /* INTERACCIONES_H_ */
