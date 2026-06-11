/*
 * juego.cpp
 *
 *  Created on: 10/09/2023
 *      Author: algo2
 */


#include "juego.h"

using namespace std;

void InicialJuego(Tablero &Jugadores){

	Jugadores.turno=1;
	Jugadores.tesoros=0;
	Jugadores.encontrar=0;
	Jugadores.iterador=0;
	Jugadores.tesorosRecuperados=0;

	for (int k=0; k<=TESOROS ;k++){
		Jugadores.turnoEncontrado[k]=0;
	}

	for (int t=0; t<=TESOROS ;t++){
			Jugadores.posicionesDeTesoros[t].fila=0;
			Jugadores.posicionesDeTesoros[t].columna=0;
		}


	for (int i=0 ; i<MAXIMAS_FILAS ; i++){
		for (int j=0 ; j<MAXIMAS_COLUMNAS ; j++){
			Jugadores.matriz[i][j]=VACIO;
		}
	}

}

int juego(Tablero &JugadorUno, Tablero &JugadorDos, int jugador) {


    for (int i = 0; i < MAXIMAS_FILAS; i++) {
        for (int j = 0; j < MAXIMAS_COLUMNAS; j++) {
            if ((JugadorUno.matriz[i][j] == CONESPIA) && (JugadorDos.matriz[i][j] == CONTESORO)) {
                cout << endl << "¡ENCONTRASTE UN TESORO! JUGADOR " << jugador+1 << endl;
                JugadorUno.matriz[i][j]=ENPROCESO;
                JugadorUno.turnoEncontrado[JugadorUno.encontrar]=JugadorUno.turno-1;
                JugadorUno.posicionesDeTesoros[JugadorUno.encontrar].fila=i;
                JugadorUno.posicionesDeTesoros[JugadorUno.encontrar].columna=j;
                JugadorUno.encontrar++;
            	}else
            		if (JugadorUno.matriz[i][j] == CONESPIA && JugadorDos.matriz[i][j] == CONESPIA) {
            		cout << "(ESPIA VS ESPIA) SE ELIMINA AMBOS ESPIAS" << endl;
            		JugadorUno.matriz[i][j]=VACIO;
            		JugadorDos.matriz[i][j]=VACIO;
            	}
    		}
        }


   	if ((((JugadorUno.turnoEncontrado[JugadorUno.iterador])+TURNOS_DE_RECUPERACION) == JugadorUno.turno) && (JugadorUno.encontrar>=1))
    	{
    		cout << endl << "¡RECUPERAS UN TESORO! JUGADOR " << jugador+1 << endl;
    		JugadorUno.matriz[JugadorUno.posicionesDeTesoros[JugadorUno.iterador].fila][JugadorUno.posicionesDeTesoros[JugadorUno.iterador].columna]=VACIO;
    		JugadorDos.matriz[JugadorUno.posicionesDeTesoros[JugadorUno.iterador].fila][JugadorUno.posicionesDeTesoros[JugadorUno.iterador].columna]=VACIO;
    		JugadorUno.tesorosRecuperados++;
    		JugadorDos.tesoros--;
    		JugadorUno.iterador++;
    	}

   	if ((JugadorUno.tesoros > 0) && (JugadorDos.tesoros == 0) && (JugadorUno.turno > 0) && (JugadorDos.turno > 0)) {
   	            cout << endl << "¡GANASTE EL JUEGO! JUGADOR "<< jugador+1 <<"FELICIDADES! JUGADOR " << jugador+1 << endl;
   	              return(0);
   	         }

	}

