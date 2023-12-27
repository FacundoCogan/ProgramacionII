#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int producto (int nroA, int nroB){
	
	int i, acum;
	acum=0;
	
	for (i=0; i<nroA; i++){
		acum+=nroB;
	}
	
	return (acum);
}

int main (){
	int nroA, nroB;
	
	cout<<"Ingrese el primer numero"<<endl;
	cin>>nroA;
	
	cout<<"Ingrese el segundo numero"<<endl;
	cin>>nroB;
	
	cout<<"El producto de los dos numeros es: "<<producto(nroA, nroB)<<endl;
	
	
}
