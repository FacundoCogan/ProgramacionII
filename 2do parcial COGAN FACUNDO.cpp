#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct Vuelos{
	int nroVuelo;
	double cantHorasVuelo;
	int capacidadPasajeros;
	int pasajeros;
	bool internacional;
};

int vuelosInternacionalesMas10 (Vuelos vecVuelos[], int dimVec){
	
	int cont=0;
	int i;
	
	for(i=0; i<dimVec; i++){
		if ((vecVuelos[i].internacional==true) && (vecVuelos[i].cantHorasVuelo>10)){
			cont++;
		}
	}
	
	return (cont);
}

void horasVuelos (Vuelos vecVuelos[], int dimVec, int &maxCantHoras, int &minCantHoras, int &nroMinHoras, int &nroMaxHoras){
	
	int i;
	
	maxCantHoras=vecVuelos[0].cantHorasVuelo;
	minCantHoras=vecVuelos[0].cantHorasVuelo;
	nroMinHoras=vecVuelos[0].nroVuelo;
	nroMaxHoras=vecVuelos[0].nroVuelo;
	
	for(i=1;i<dimVec;i++){
		if(vecVuelos[i].cantHorasVuelo<minCantHoras){
			minCantHoras=vecVuelos[i].cantHorasVuelo;
			nroMinHoras=vecVuelos[i].nroVuelo;
		}
		else
			if(vecVuelos[i].cantHorasVuelo>maxCantHoras){
				maxCantHoras=vecVuelos[i].cantHorasVuelo;
				nroMaxHoras=vecVuelos[i].nroVuelo;
			}
	}	
}

void totalidadVuelos (Vuelos vecVuelos[], int dimVec){
	
	int i;
	cout<<"********************* VUELOS *********************"<<endl;
	for (i=0;i<dimVec;i++){
		
		cout<<"******************************************************"<<endl;
		cout<<"Numero de vuelo: "<<vecVuelos[i].nroVuelo<<endl;
		cout<<"Cantidad de horas de vuelo: "<<vecVuelos[i].cantHorasVuelo<<endl;
		cout<<"Capacidad de pasajeros en el avion: "<<vecVuelos[i].capacidadPasajeros<<endl;
		cout<<"Total de pasajeros que viajaron: "<<vecVuelos[i].pasajeros<<endl;
		if (vecVuelos[i].internacional==true){
			cout<<"El tipo de vuelo fue internacional"<<endl;
		}
		else{
			cout<<"El tipo de vuelo fue cabotaje"<<endl;
		}

	}	
}

double porcentaje (int p, int t){
	
	return ((p*100)/t);
}

bool capacidad (Vuelos unVuelo){
	
	int i, n;
	
	for (i=0; i<n; i++){
		
		if(porcentaje(unVuelo.capacidadPasajeros, unVuelo.pasajeros)>50){
			return (true);
		}
		else{
			return (false);
		}	
	}
}

int main (void){

	
	cout<<"********************* INGRESO DATOS VUELOS *********************************"<<endl;
	
	int n, vueloInt, i, maxCantHoras, minCantHoras, nroMaxHoras, nroMinHoras, vuelosInternacionesMas10, contSuperanCincuenta;
	
	contSuperanCincuenta=0;
	char tipoVuelo;
	
	cout<<"Ingrese la cantidad de vuelos del dia de hoy: "<<endl;
	cin>>n;
	
	Vuelos vecVuelos[n];
	
	for (i=0; i<n; i++){
		cout<<"Ingrese el numero de vuelo: "<<endl;
		cin>>vecVuelos[i].nroVuelo;
		
		cout<<"Ingrese la cantidad de horas de vuelo: "<<endl;
		cin>>vecVuelos[i].cantHorasVuelo;
		
		cout<<"Ingrese la capacidad de pasajeros del avion: "<<endl;
		cin>>vecVuelos[i].capacidadPasajeros;
		
		cout<<"Ingrese la cantidad de pasajeros que viajaron: "<<endl;
		cin>>vecVuelos[i].pasajeros;
		
		cout<<"El vuelo es internacional? (1: si / 2: no): "<<endl;
		cin>>vueloInt;
		
		while (vueloInt!=1 && vueloInt!=2){
			cout<<"El numero ingresado no es correcto. Vuelva a intentarlo..."<<endl;
			cin>>vueloInt;
		}
		
		if (vueloInt==1){
			vecVuelos[i].internacional=true;
		}
		else{
			vecVuelos[i].internacional=false;
			
		}
	}	
	
	// SALIDAS
	cout<<"********************* SALIDAS *********************************"<<endl;
	
	//1 Muestra por pantalla los datos de cada vuelo
	totalidadVuelos (vecVuelos, n);
	
	
	
	//2 Numero de vuelo con mayor y menor cant de horas
	horasVuelos(vecVuelos, n, maxCantHoras, minCantHoras, nroMinHoras, nroMaxHoras);
	cout<<"El vuelo con mayor cantidad de horas fue el numero: "<<nroMaxHoras<<" con un total de: "<<maxCantHoras<<endl;
	cout<<"El vuelo con menor cantidad de horas fue el numero: "<<nroMinHoras<<" con un total de: "<<minCantHoras<<endl;
	
	//3 Cantidad de vuelos internacionales con una duracion mayor a 10 hs
	cout<<"La cantidad de vuelos internacionales con una duracion mayor a 10 horas fue de: "<<vuelosInternacionalesMas10(vecVuelos, n)<<endl;
	
	//4
	for(i=0;i<n;i++){
		if(capacidad(vecVuelos[i])==true)
			contSuperanCincuenta++;		
	}
	
	cout<<"La cantidad de vuelos que registran mas del 50% de ocupacion de asientos con respecto al total de asientos en el avion es de: "<<contSuperanCincuenta<<endl;
	
} 



	
	



