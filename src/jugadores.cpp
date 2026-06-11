/*
 * jugadores.cpp
 *
 *  Created on: 10/09/2023
 *      Author: algo2
 */

#include "jugadores.h"
#include "interacciones.h"
#include "juego.h"

void inicioJugadores(Tablero Jugadores[CANTIDAD_DE_JUGADORES]){

	int juegoTerminado=1;



    for (int jugador = 0; jugador < CANTIDAD_DE_JUGADORES; jugador++) {
        InicialJuego(Jugadores[jugador]);

    }

  while (juegoTerminado !=0 ) {
        for (int jugador = 0; jugador < CANTIDAD_DE_JUGADORES; jugador++) {
          	cout << "--------------------------------------------------"<< endl;
          	cout << endl <<"Jugador:" << jugador + 1 << endl << endl;
        	mostrarTablero(Jugadores[jugador]);
        	if (jugador==0){
        		interacciones(Jugadores[jugador], Jugadores[1]);
        	}else{
        		interacciones(Jugadores[jugador], Jugadores[0]);
        	}
        	 if ((Jugadores[0].turno>=2 && Jugadores[1].turno>=2) && (jugador==0)){
        	     juegoTerminado=(juego(Jugadores[jugador], Jugadores[1], jugador));
        	     }else
        	    	 if ((Jugadores[0].turno>=1 && Jugadores[1].turno>=1) && (jugador==1)){
        	    		 juegoTerminado=(juego(Jugadores[jugador], Jugadores[0], jugador));
        	    	 }

            if (jugador==0){
            	escrbirTablero(Jugadores[jugador], jugador+1 ,"Tablero_Jugador1.txt");
            }else
            	if (jugador==1){
            		escrbirTablero(Jugadores[jugador], jugador+1 ,"Tablero_Jugador2.txt");
            	}

        }
  	 }
 }
