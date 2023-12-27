#include <iostream>
#include <conio.h>

using namespace std;

int main(void){
	
	int idSuc[7], creacion[7], i;
	char nombre[7][20], direc[7][50];
	
	// carga de los datos de las sucursales
	
	for (i=0; i<7; i++) {
		cout<<"Ingrese el id de la sucursal "<<i<<endl;
		cin>>idSuc[i];
		cout<<"Ingrese el nombre de  la sucursal "<<i<<endl;
		cin>>nombre[i];
		cout<<"Ingrese la fecha de creacion de la sucursal "<<i<<" (AAAAMMDD): "<<endl;
		cin>>creacion[i];
		cout<<"Ingrese la direccion de la sucursal "<<i<<endl;
		cin>>direc[i];
	}
	
}
