#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#define CANTALUMNOS 10

using namespace std;

struct Alumno{
	string nombre;
	double long1;
	double long2;
	double long3;
	double perimetro;
	int tipoTriangulo;
};

double perim (double long1, double long2, double long3, double perimetro){
	
	double perimetroTriangulo;
	
	perimetroTriangulo=((long1 + long2 + long3)/100);
	
	return (perimetroTriangulo);
	
};

int correcto (double long1, double long2, double long3, double tipoTriangulo){
	
	if ((tipoTriangulo==1) && ((long1==long2) && (long2==long3) && (long1==long3))){
		return (1);	
	}
	if ((((tipoTriangulo==2) && (long1==long2 && long1!=long3) || ((tipoTriangulo==2) && (long3==long2 && long1!=long3) || ((tipoTriangulo==2) && (long1==long3 && long1!=long2)))))){
		return (1);
	}
	if ((tipoTriangulo==3) && ((long1!=long2) && (long2!=long3) && (long1!=long3))){
		return (1);
	}
	else{
		return (0);
	}
				
};



int main (void){
	
	Alumno vecAlu[CANTALUMNOS];
	string aprobar;
	int cont, i;
	
	for(i=0; i<CANTALUMNOS; i++){
		
		cout<<"Ingrese el nombre del alumno: "<<endl;
		cin>>vecAlu[i].nombre;
		
		cout<<"Ingrese la longitud del primer lado del triangulo (en centimentros): "<<endl;
		cin>>vecAlu[i].long1;
		
		cout<<"Ingrese la longitud del segundo lado del triangulo (en centimentros): "<<endl;
		cin>>vecAlu[i].long2;
		
		cout<<"Ingrese la longitud del tercer lado del triangulo (en centimentros): "<<endl;
		cin>>vecAlu[i].long3;
		
		cout<<"Ingrese el perimetro del triangulo (en metros): "<<endl;
		cin>>vecAlu[i].perimetro;
		
		cout<<"Ingrese su tipo de triangulo en numero (1: equilatero - 2: isosceles - 3: escaleno): "<<endl;
		cin>>vecAlu[i].tipoTriangulo;	
		
		cont=0;
		if((perim(vecAlu[i].long1, vecAlu[i].long2, vecAlu[i].long3, vecAlu[i].perimetro)==vecAlu[i].perimetro) && (correcto(vecAlu[i].long1, vecAlu[i].long2, vecAlu[i].long3, vecAlu[i].tipoTriangulo)==1)){
			cont++;
			aprobar="aprobo";
		}
		else{
			aprobar="esta insuficiente";
		} 		
	}
	
	//1
	for(i=0; i<CANTALUMNOS; i++){
		cout<<"El alumno: "<<vecAlu[i].nombre<<" "<<aprobar<<endl;
	}
	
	//2
	cout<<"La cantidad de alumnos aprobados fue de: "<<cont<<" y el porcentaje que representa con respecto al total de alumnos es de: "<<((cont/CANTALUMNOS)*100)<<endl;
	
	
	
	
	
}
