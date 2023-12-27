#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void funcionVector (int vecNros[], int n){
	
	int i;
	
	for (i=0; i<n; i++){
		vecNros[i]=rand()%11;
	}
	
};

int main (void){
	
	int n, i;
	
	cout<<"Ingrese la longitud del vector: "<<endl;
	cin>>n;
	
	int vecNros[n];
	
	funcionVector(vecNros, n);
	for (i=0; i<n; i++){
		cout<<"En la posicion "<<i<<" el vector tiene el valor: "<<vecNros[i]<<endl;
	}
	
	getch ();
	return(0);
	
	
}
