#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#define CANTAREAS 2
#define CANTMOTIVOS 12
#define MESES 12

using namespace std;

int main (void){
	
	int matCantPermisos[CANTAREAS][CANTMOTIVOS], matCantBiciPermisos[CANTAREAS][MESES], vecNroArea[CANTAREAS], i, j, dni, mes, nroArea, transporte, permisos, codMotivo;
	
	for(i=0; i<CANTAREAS; i++){
		vecNroArea[i]=0;
		for(j=0; j<CANTMOTIVOS; j++){
			matCantPermisos[i][j]=0;
		}
	}
	
	for(i=0; i<CANTAREAS; i++){
		for(j=0; j<CANTMOTIVOS; j++){
			matCantBiciPermisos[i][j]=0;
		}
	}
	
	for(i=0; i<CANTAREAS; i++){
		cout<<"Ingrese el codigo del area: "<<i+1<<" (4000-8000): "<<endl;
		cin>>nroArea;
		
		while((nroArea<4000) || (nroArea>8000)){
			cout<<"El numero de area ingresado no es valido. Vuelva a intentarlo..."<<endl;
			cin>>nroArea;
		}
		
		vecNroArea[i]=nroArea;
	}
	
	cout<<"***************************************"<<endl;
	cout<<"Hay permisos para cargar? (1: si / 0: no)"<<endl;
	cin>>permisos;
	
	while(permisos!=0){
			
		cout<<"Ingrese el DNI del solicitante: "<<endl;
		cin>>dni; //inutil
		
		cout<<"Ingrese el codigo de motivo por el que solicita el permiso (1-12): "<<endl;
		cin>>codMotivo;
				
		while((codMotivo<1) || (codMotivo>12)){
			cout<<"El motivo ingresado no es valido. Intentelo nuevamente..."<<endl;
			cin>>codMotivo;
		}
	
		cout<<"Ingrese el mes en el que solicito el permiso (1-12): "<<endl;
		cin>>mes;
		
		cout<<"Ingrese el transporte por el cual viaja (1: colectivo / 2: tren / 3: bicicleta)"<<endl;
		cin>>transporte;
		
		cout<<"Ingrese el codigo de area (4000-8000): "<<endl;
		cin>>nroArea;
		
		while((nroArea<4000) || (nroArea>8000)){
			cout<<"El numero de area ingresado esta fuera de rango. Vuelva a intentarlo..."<<endl;
			cin>>nroArea;
		}
		
		do{ 
			i=0;
			while((i<CANTAREAS) && vecNroArea[i]!=nroArea){
				i++;
			}
			if(i==CANTAREAS){
				cout<<"El numero de area ingresado no es valido. Vuelva a intentarlo..."<<endl;
				cin>>nroArea;
			}
			else{
				matCantPermisos[i][codMotivo-1]+=1;
			
				if(transporte==3){
					matCantBiciPermisos[i][mes-1]+=1;
				}
			}		
		}while(i==CANTAREAS);
	
		cout<<"Hay permisos para cargar? (1: si / 0: no)"<<endl;
		cin>>permisos;	
			
	}
	

	
	cout<<"***************************************"<<endl;
	//1
	for(j=0; j<CANTMOTIVOS; j++){
		for(i=0; i<CANTAREAS; i++){
			cout<<"Por el motivo: "<<j+1<<" en el area: "<<vecNroArea[i]<<" hubo un total de: "<<matCantPermisos[i][j]<<" permisos solicitados."<<endl;
		}
	}
	
	//2
	for(i=0; i<CANTAREAS; i++){
		for(j=0; j<MESES; j++){
			cout<<"En el area "<<vecNroArea[i]<<" y en el mes "<<j+1<<" hubo un total de: "<<matCantBiciPermisos[i][j]<<" permisos solicitados para viajar en bicicleta."<<endl;
		}
	}
	
	//3
	int suma;
	
	for(j=0; j<CANTMOTIVOS; j++){
		suma=0;
		for(i=0; i<CANTAREAS; i++){
			suma+=matCantPermisos[i][j];
		}
		cout<<"Por el motivo "<<j+1<<", la cantidad total de permisos otorgados fueron de: "<<suma<<endl;
	}
	
	//4
	int cont;
	
	for(i=0; i<CANTAREAS; i++){
		cont=0;
		for(j=0; j<CANTMOTIVOS; j++){
			if(matCantPermisos[i][j]==0){
				cont++;
			}
		}
		
		cout<<"En el area "<<vecNroArea[i]<<" la cantidad de motivos por la que no se han otorgado permisos es de: "<<cont<<endl;
	}
	
	//5
	int areaMax=0;
	int motivoMax=0;
	int valorMax=0;
	
	for(i=0; i<CANTAREAS; i++){
		for(j=0; j<CANTMOTIVOS; j++){
			if ((i==0) && (j==0)){
				valorMax=matCantPermisos[i][j];
				motivoMax=j;
				areaMax=vecNroArea[i];
			}
			else{
				if(matCantPermisos[i][j]>valorMax){
					valorMax=matCantPermisos[i][j];
					motivoMax=j;
					areaMax=vecNroArea[i];
				}
			}
		}
	}
	
	cout<<"La mayor cantidad permisos la tuvo el area "<<areaMax<<" por el motivo "<<motivoMax<<" con un total de "<<valorMax<<" permisos solicitados."<<endl;
	
	
	getch();
	return(0);
}
