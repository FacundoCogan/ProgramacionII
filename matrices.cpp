#include <iostream>
#include <conio.h>
#include <stdio.h>
#define CANTFILAS 10
#define CANTCOLUMNAS 15


using namespace std;

int main (void){
	int f, c;
	
	int mat[CANTFILAS][CANTALUMNOS];
	
	// RECORRIDO POR FILAS
	
	for (f=0; f<CANTFILAS; f++)
		for (c=0;c<CANTCOLUMNAS;c++)
			cin<<mat[f][c];
			
	// RECORRIDO POR COLUMNAS
	
	for (c=0; c<CANTCOLUMNAS; c++)
		for (f=0; f<CANTFILAS; f++)
			cin<<mat[f][c];		
}
