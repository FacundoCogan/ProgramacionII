#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#define CANTVENDEDORES 10
#define CANTARTICULOS 8

using namespace std; 

int main ()
{
	int matVentas[CANTVENDEDORES][CANTARTICULOS], vecPreciosArt[CANTARTICULOS], indArticulos, indVendedores, numVendedor, codArtVendido, cantVendida;
	
	for (indArticulos=0; indArticulos<CANTARTICULOS; indArticulos++)
	{
		cout<<"Ingrese el precio del articulo con codigo: "<<indArticulos+1<<endl;
		cin>>vecPreciosArt[indArticulos];
	}
	
	cout<<"Ingrese el numero de vendedor: "<<endl;
	cin>>numVendedor;
	
	while ((numVendedor>1) && (numVendedor<10)){
		
		cout<<"Ingrese el codigo del articulo vendido: "<<endl;
		cin>>codArtVendido;
		
		cout<<"Ingrese la cantidad de unidades vendidas del articulo "<<codArtVendido<<": "<<endl;
		cin>>cantVendida;
		
		cout<<"Ingrese el numero de otro vendedor (para fin de ingreso, ingrese un numero menor a 1 o mayor a 10): "<<endl;
		cin>>numVendedor;
	}
	
		
	
	
	
}
