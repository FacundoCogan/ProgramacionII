#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#define CANTCAMIONETAS 10
#define CANTETAPAS 5


using namespace std;

int main (void){
	
	int matTiempos[CANTCAMIONETAS][CANTETAPAS], vecNumId[CANTCAMIONETAS], vecTiempoPrevisto[CANTETAPAS], i, j, numId;
	
	for(i=0; i<CANTCAMIONETAS; i++){
		vecNumId[i]=0;
		for(j=0; j<CANTETAPAS; j++){
			matTiempos[i][j]=0;
		}
	}
	
	for(j=0; j<CANTETAPAS; j++){
		vecTiempoPrevisto[j]=0;
	}
	
	for(i=0; i<CANTCAMIONETAS; i++){
		cout<<"Ingrese el numero identificatorio de la camioneta "<<i+1<<" (500-1200): "<<endl;
		cin>>numId;
		
		while ((numId<500) || (numId>1200)){
			cout<<"El numero identificatorio ingresado esta fuera de rango. Intentelo nuevamente..."<<endl;
			cin>>numId; //valido los numeros identificatorios
		}
		
		vecNumId[i]=numId;
	}
	
	for(j=0; j<CANTETAPAS; j++){
		cout<<"Ingrese el tiempo (en minutos) previsto para la camioneta: "<<i+1<<endl;
		cin>>vecTiempoPrevisto[j]; //no hay que validar nada
	}
	
	cout<<"Ingrese el numero identificatorio de la camioneta de la que se va a registrar un tiempo (0 para fin de ingreso de datos): "<<endl;
	cin>>numId;
	
	while(numId!=0){
		
		do{
			i=0;
			while((i<CANTCAMIONETAS) && (vecNumId[i]!=numId)){
				i++;
			}
			if (i==CANTCAMIONETAS){
				cout<<"El numero identificatorio de la camioneta no fue encontrado. Intentelo nuevamente..."<<endl;
				cin>>numId;
			}
			else{
				cout<<"Ingrese el tiempo de la camioneta (en minutos): "<<endl;
				cin>>matTiempos[i][j];
			}
		}while(i==CANTCAMIONETAS);
		
		cout<<"Ingrese el numero identificatorio de la camioneta de la que se va a registrar un tiempo (0 para fin de ingreso de datos): "<<endl;
		cin>>numId;
		
	}
	
	//1
	for(i=0; i<CANTCAMIONETAS; i++){
		for(j=0; j<CANTETAPAS; j++){
			cout<<"La camioneta "<<vecNumId[i]<<" en la etapa "<<j<<" tardo: "<<matTiempos[i][j]<<endl;
		}
	}
	
	//2
	for(i=0; i<CANTCAMIONETAS; i++){
		for(j=0; j<CANTETAPAS; j++){
			if(matTiempos[i][j]>vecTiempoPrevisto[i]){
				cout<<"La camioneta "<<vecNumId[i]<<" en la etapa "<<j<<" tardo mas del tiempo previsto."<<endl;
			}
			else{
				if(matTiempos[i][j]<vecTiempoPrevisto[i]){
					cout<<"La camioneta "<<vecNumId[i]<<" en la etapa "<<j<<" tardo menos del tiempo previsto."<<endl;
				}
				else{
					cout<<"La camioneta "<<vecNumId[i]<<" en la etapa "<<j<<" tardo lo mismo que su tiempo previsto."<<endl;
				}
			}
		}
	}
	
	//3.1
	int cont;
	int max;
	int min;
	
	
	for(i=0; i<CANTCAMIONETAS; i++){
		cont=0;
		for(j=0; j<CANTETAPAS; j++){
			if(matTiempos[i][j]>0){
				cont++;
			}
		}
		
		cout<<"La camioneta "<<vecNumId[i]<<" finalizo "<<cont<<" etapas."<<endl;

		//3.2
	
		if(i==0){
			max=cont;
			min=cont;
		}
		else{
			if(cont>max){
				max=cont;
			}
			else{
				if(cont<min){
					min=cont;
				}
			}
		}
	}
	
	cout<<"La cantidad maxima de etapas finalizadas es de: "<<max<<endl;
	cout<<"La cantidad minima de etapas finalizadas es de: "<<min<<endl;
	
	//4
	int contFinalizaron;
	int suma;
	
	for(j=0; j<CANTETAPAS; j++){
		
		contFinalizaron=0;
		suma=0;
		
		for(i=0; i<CANTCAMIONETAS; i++){
			if(matTiempos[i]>0){
				suma+=matTiempos[i][j];
				contFinalizaron++;
			}
		}
		
		cout<<"En la etapa "<<j<<" el promedio de tiempos es de: "<<(suma/contFinalizaron)<<endl;
		
	}
	
	//5
	int maxTiempo;
	
	for(j=0; j<CANTETAPAS; j++){
		maxTiempo=0;
		for(i=0; i<CANTCAMIONETAS; i++){
			if ((i==0) && (j==0)){
				maxTiempo=matTiempos[i][j];	
			}
			else{
				if(matTiempos[i][j]>maxTiempo){
					maxTiempo=matTiempos[i][j];
				}
			}
		}
		
		cout<<"En la etapa "<<j<<" el mayor tiempo fue: "<<maxTiempo<<endl;
	}
	
	//6
	for(i=0; i<CANTCAMIONETAS; i++){
		for(j=0; j<CANTETAPAS; j++){
			if (matTiempos[i][j]==0){
				cout<<"La camioneta "<<vecNumId[i]<<" no finalizo la etapa: "<<j<<endl;
			}
		}
	}
	
	
}
