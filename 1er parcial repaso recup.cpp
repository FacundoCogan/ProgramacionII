#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#define CANTAREAS 2
#define CANTMOTIVOS 2
#define MESES 12

using namespace std;

int main (void){
	
	int matCantPermisos[CANTAREAS][CANTMOTIVOS], matCantBiciPermisos[CANTAREAS][MESES], vecNroArea[CANTAREAS], dni, nroArea, codMotivo, mes, transporte, datos, i, j, cantAreasSinPermisos, motivoMaximo;
	
	
	for(i=0; i<CANTAREAS; i++){
		for(j=0; j<CANTMOTIVOS; j++){
			matCantPermisos[i][j]=0;
		}
	}
	
	for(i=0; i<CANTAREAS; i++){
		vecNroArea[i]=0;
		for(j=0; j<MESES; j++){
			matCantBiciPermisos[i][j]=0;
		}
	}
	
	cout<<"Hay datos para cargar? (1: si / 0: no): "<<endl;
	cin>>datos;
	
	while ((datos!=1) && (datos!=0)){
		cout<<"El numero ingresado no es valido. Vuelva a intentarlo..."<<endl;
		cin>>datos;
	}
	
	while (datos==1){
		i=0;
		cout<<"Ingrese el dni: "<<endl;
		cin>>dni;
		
		cout<<"Ingrese el numero de area (4000-8000): "<<endl;
		cin>>nroArea;
		
		while ((nroArea<4000) || (nroArea>8000)){
			cout<<"El numero de area ingresado no es valido. Intentelo nuevamente..."<<endl;
			cin>>nroArea;
		}
		
		vecNroArea[i]=nroArea;
		i++;
		
		cout<<"Ingrese el codigo del motivo por el cual solicita el permiso (1-12): "<<endl;
		cin>>codMotivo;
		
		while ((codMotivo<1) || (codMotivo>12)){
			cout<<"El codigo del motivo ingresado no es valido. Intentelo nuevamente..."<<endl;
			cin>>codMotivo;
		}
		
		cout<<"Ingrese el mes en el que solicito el permiso (1-12): "<<endl;
		cin>>mes;
		
		cout<<"Ingrese el transporte por el cual viaja (1: Colectivo - 2: Tren - 3: Bicicleta): "<<endl;
		cin>>transporte;
		
	
		cout<<"Hay datos para cargar? (1: si / 0: no): "<<endl;
		cin>>datos;
		
	}
	
	cout<<"Ingrese el numero de area a buscar: "<<endl;
	cin>>nroArea;
	

	while ((nroArea>4000) && (nroArea<8000)){
		i=0;
		while (i<CANTAREAS && vecNroArea[i]!=nroArea){
			i++;
		}
		if(i==CANTAREAS){
			cout<<"El numero de area ingresado no es valido. Intentelo nuevamente..."<<endl;
			cin>>nroArea;
		}
		else{
			matCantPermisos[nroArea][codMotivo-1]+=1;
			
			if (transporte==3){
				matCantBiciPermisos[nroArea][mes-1]+=1;
			}	
		}
	}		
	
	
	// 1
	cout<<endl<<endl<<"                          	Motivos"<<endl;
	cout<<"0     1     2     3     4     5     6     7     8     9     10     11"<<endl;
	cout<<"Areas"<<endl<<endl;
	for (i=0; i<CANTAREAS; i++){
		cout<<setw(5)<<vecNroArea[i];
		for (j=0; j<CANTMOTIVOS; j++){
			cout<<setw(5)<<matCantPermisos[i][j];
		}
		cout<<endl;
	}	
	
	// 2
	for (i=0; i<CANTAREAS; i++){
		for (j=0; j<MESES; j++){
			cout<<"En el area "<<i<<" en el mes "<<j<<" hubo un total de: "<<matCantBiciPermisos[i][j]<<" permisos para viajar en bicicleta."<<endl;
		}
	}
	
	// 3
	int suma=0;
	
	for (j=0; j<CANTMOTIVOS; j++){
		suma=0;
		for (i=0; i<CANTAREAS; i++){
			suma+=matCantPermisos[i][j];
		}
		
		cout<<"La cantidad de permisos otorgados del motivo "<<j<<" es de: "<<suma<<endl;
	}
	
	// 4
	int cont;
	for (i=0; i<CANTAREAS; i++){
		cont=0;
		for (j=0; j<CANTMOTIVOS; j++){
			if(matCantPermisos[i][j]==0){
				cont++;
			}
			cout<<"En el area "<<i<<" la cantidad de motivos por los cuales no se han otorgado permisos es de: "<<cont<<endl;
		}
	}
	
	cout << "Un total de " << cantAreasSinPermisos << " zonas no entregaron permisos." << endl;
	
	int valorMaximo = 0;
	int diaMaximo = 0;
	int areaMaxima = 0;
	
	for (i=1; i<CANTAREAS; i++) {
		for (j=1; j<CANTMOTIVOS; j++) {
			if(matCantPermisos[i][j] > valorMaximo){
				
				valorMaximo	= matCantPermisos[i][j];
				motivoMaximo = j;
				areaMaxima = i;
				
			}	
		}
	}
	
	cout << "El motivo con mayor cantidad de permisos entregados fue " << motivoMaximo << " en el area " << areaMaxima << " Con un total de " << valorMaximo << " permisos entregados. " <<endl;
	
}
