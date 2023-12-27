#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

bool esPar (bool flag){
	
	int i, nro;
	bool valor;
	
	if ((nro % 2)==0){
		valor=true;
	}
	else
		{
			valor=false;
		}
		
	return valor;
}

int main (void){
	
	int n, cont, i, acum;
	bool flag;
	
	cout<<"Ingrese la cantidad de numeros enteros que va a ingresar: "<<endl;
	cin>>n;
	
	int vNum[n];
	
	for (i=0; i<n; i++){
		cout<<"Ingrese los numeros enteros: "<<endl;
		cin>>vNum[n];
	}
	
	cont=0;
	for (i=0; i<n; i++){
		
		if (esPar(flag)==true){
			cont++;
		}
		else{ 
			acum+=vNum[i];
		}
	}
	
	cout<<"La cantidad de numeros pares ingresados es de: "<<cont<<" y la suma de los impares es de: "<<acum<<endl;
	
}
