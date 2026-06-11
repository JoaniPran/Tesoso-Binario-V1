/*
 * interacciones.cpp
 *
 *  Created on: 09/09/2023
 *      Author: algo2
 */


#include "interacciones.h"
#include "tablero.h"

#include <iostream>


using namespace std;


void mostrarTablero(Tablero &Jugadores) {

    for (int i = 0; i < MAXIMAS_FILAS; i++) {
        for (int j = 0; j < MAXIMAS_COLUMNAS; j++) {
            if (Jugadores.matriz[i][j] == VACIO) {
                cout << "[ ]";
            } else if (Jugadores.matriz[i][j] == CONESPIA) {
                cout << "[S]";
            } else if (Jugadores.matriz[i][j] == CONTESORO) {
                cout << "[T]";
            } else if (Jugadores.matriz[i][j] == ENPROCESO) {
                cout << "[X]";
            }
        }
        cout << endl;
    }
    cout << endl << "Tesoros Recuperados:" << Jugadores.tesorosRecuperados << endl;
 	cout << endl << "Turno:" << Jugadores.turno << endl << endl;
}

void ingresoDeDatos(int &fila,int  &columna){

	cout << "Ingrese una FILA:";
		cin >> fila;

		cout << "Ingrese una COLUMNA:";
			cin >> columna;


		cout << endl;
}


void moverTesoro(Tablero &Jugadores,Tablero &jugadorComparar){

	int fila, columnas, nuevaFila, nuevaColumna, pregunta;

	if (Jugadores.tesoros>0){

	cout << "¿DESEA MOVER ALGUN TESORO? (Elija 1(SI) o 2(NO) para indicar si desea mover el tesoro):";
	cin >> pregunta;

	if(pregunta == 1){
		cout << "Ingrese la coordenada del tesoro que desea mover:" << endl;
		ingresoDeDatos(fila, columnas);

		while ((Jugadores.matriz[fila-1][columnas-1] != CONTESORO)){
					cout << "COORDENADAS INVALIDAS (no se encuentra ningún tesoro en esa posición)" << endl;
							ingresoDeDatos(fila, columnas);
							}


		if ((Jugadores.matriz[fila-1][columnas-1]==CONTESORO) && jugadorComparar.matriz[fila-1][columnas-1]==ENPROCESO){
				cout << "TU TESORO ESTA SIENDO CAPTURADO POR EL OTRO JUGADOR :( NO ES POSIBLE MOVERLO" << endl;
				}	/*else
				if (Jugadores.tesoros>1){
							cout << "Ingrese la coordenada de otro tesoro que desea mover:" << endl;
								IngresoDeDatos(FILA, COLUMNAS);
							}*/else{
								cout << "Tesoro de coordenadas: FILA:" << fila << " COLUMNA:" << columnas << endl;
									cout << "Ingrese la coordenada donde desea mover el tesoro:" << endl;
										ingresoDeDatos(nuevaFila, nuevaColumna);

						while (jugadorComparar.matriz[nuevaFila-1][nuevaColumna-1]==CONTESORO){
							cout << "¡Encontraste UN TESORO ENEMIGO! en la FILA: "<< nuevaFila << " y en la COLUMNA: " << nuevaColumna <<" No podes colocar un tesoro en esa posicion, PERO SI PODES COLOCAR OTRA COSA 0.0" << endl;
							cout << "Ingrese la coordenada donde desea mover el tesoro:" << endl;
							ingresoDeDatos(nuevaFila, nuevaColumna);
							}

						while ((!((nuevaFila-1 <= fila) && (nuevaFila-1 >= fila-2) && (nuevaColumna-1 <= columnas) && (nuevaColumna-1 >= columnas-2))
							&& !((nuevaFila-1 ==-1) || (nuevaFila-1==MAXIMAS_FILAS+1)) && !((nuevaColumna-1 ==-1) || (nuevaColumna-1==MAXIMAS_COLUMNAS+1))) || (Jugadores.matriz[nuevaFila-1][nuevaColumna-1] == CONTESORO)) {

							cout << "CORDENADAS INVALIDAS" << endl;
							ingresoDeDatos(nuevaFila, nuevaColumna);

								}
								Jugadores.matriz[fila-1][columnas-1] = VACIO;
								Jugadores.matriz[nuevaFila-1][nuevaColumna-1] = CONTESORO;
								mostrarTablero(Jugadores);
							}

						}
					}
				}





void ingresoTesoros(Tablero &Jugadores, Tablero &jugadorComparar){

	int FILA, COLUMNAS;

		cout << endl << "Ingrese tesoros al juego:" << endl;

		ingresoDeDatos(FILA, COLUMNAS);
			while ((Jugadores.matriz[FILA-1][COLUMNAS-1] == CONTESORO) || jugadorComparar.matriz[FILA-1][COLUMNAS-1] == CONTESORO){
				cout << "Ya hay un tesoro Propio en esa posicion o un tesoro enemigo ojo" << endl;
				ingresoDeDatos(FILA, COLUMNAS);
			}
			Jugadores.matriz[FILA-1][COLUMNAS-1]=CONTESORO;
			mostrarTablero(Jugadores);
			Jugadores.tesoros++;


}


void ingresoEspias(Tablero &Jugadores){

	int fila=0, columna=0;

	cout << endl << "ENVIE UN ESPIA(Âª) al juego" << endl;
			ingresoDeDatos(fila, columna);
			while ((Jugadores.matriz[fila-1][columna-1]==ENPROCESO) || (Jugadores.matriz[fila-1][columna-1]==CONTESORO) || (Jugadores.matriz[fila-1][columna-1]==CONESPIA)){
				cout << "no se puede INGRESA UN ESPIA EN ESA POSICION LA CASILLA ESTA INACTIVA o CONTIENE UN TESORO SUYO" << endl;
				cout << "Por favor Ingrese una POSICION VALIDA:" << endl;
				ingresoDeDatos(fila, columna);
			}
			Jugadores.matriz[fila-1][columna-1]=CONESPIA;
			mostrarTablero(Jugadores);
			Jugadores.turno++;

}

void interacciones(Tablero &Jugadores, Tablero &jugadorComparar) {

	if (Jugadores.turno==1){
		for (int i=0 ; i<TESOROS ; i++){
			ingresoTesoros(Jugadores, jugadorComparar);
		}
		cout << "Cantidad de tesoros:" << Jugadores.tesoros <<endl;
	}
	if (Jugadores.tesoros !=0)
	{
	ingresoEspias(Jugadores);
	moverTesoro(Jugadores, jugadorComparar);
	}
}


