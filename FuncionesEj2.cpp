#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

void nroFactorial(int nro){
	
	
	int nros=1, i;
	for (i=1; i<=nro; i++){
		nros*=i;	
	}
	
	cout<<nros<<endl;
}

int main (){
	
	int x, i, k;
	nroFactorial(3);
	
	cout<<"Ingrese la cantidad de numeros que va a ingresar: "<<endl;
	cin>>x;
	
	for (i=0; i<x; i++){
		cout<<"Ingrese un numero: "<<endl;
		cin>>k;
		cout<<"El factorial de "<<k<<" es: ";nroFactorial(k);
	}
	
};
