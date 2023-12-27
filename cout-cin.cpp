#include <iostream>
#include <conio.h>

using namespace std;

int main (void){
	
	float codigo, precio, cantVendida;
	
	cout<<"Ingrese el código del producto"<<endl;
	cin>>codigo;
	
	cout<<"Ingrese el precio del producto"<<endl;
	cin>>precio;
	
	cout<<"Ingrese la cantidad vendida"<<endl;
	cin>>cantVendida;

	cout<<"**************"<<endl;
	
	cout<<"Código del producto: " << codigo <<endl;
	cout<<"Precio del producto: " << precio <<endl;
	cout<<"Cantidad vendida: " << cantVendida <<endl;
	cout<<"Precio a pagar: "<< precio*cantVendida <<endl;
	cout<<"Precio total con IVA: "<< precio*cantVendida*1.21 <<endl;
	
	

	getch();
	
	return (0);
	
}

