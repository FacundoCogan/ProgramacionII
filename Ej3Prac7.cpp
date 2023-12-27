#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct Alumno{
	string nombre;
	int notaUno;
	int notaDos;
	int notaTres;
	int notaFinal;
	string observaciones;
};

int main (void)
{
	int cont, n, i, totalFinal;
	
	cout<<"Ingrese la cantidad de alumnos a ingresar su nota: "<<endl;
	cin>>n;
	
	Alumno vAlumnos[n];
	
	totalFinal=0;
	cont=0;
	
	for(i=0; i<n; i++){
		
		cout<<"Ingrese el nombre del alumno: "<<endl;
		cin>>vAlumnos[i].nombre;
	
		cout<<"Ingrese la nota del alumno en el primer parcial: "<<endl;
		cin>>vAlumnos[i].notaUno;
	
		cout<<"Ingrese la nota del alumno en el segundo parcial: "<<endl;
		cin>>vAlumnos[i].notaDos;
	
		cout<<"Ingrese la nota del alumno en el tercer parcial: "<<endl;
		cin>>vAlumnos[i].notaTres;
	
		cout<<"Ingrese la nota del final: "<<endl;
		cin>>vAlumnos[i].notaFinal;
		
		totalFinal+=vAlumnos[i].notaFinal;
		
		if (vAlumnos[i].notaFinal >= 4){
			cont++;
		}
	
		cout<<"Ingrese observaciones: "<<endl;
		cin>>vAlumnos[i].observaciones;
		
	}
	
	//1
	for(i=0; i<n; i++){
		cout<<"************************"<<endl;
		cout<<"El alumno: "<<vAlumnos[i].nombre<<" tuvo un promedio de: "<<((vAlumnos[i].notaUno + vAlumnos[i].notaDos + vAlumnos[i].notaTres)/3);
	}
	
	//2
	cout<<"La cantidad de alumnos que tuvieron como nota del final un 4 o mas fue de "<<cont<<" alumnos."<<endl;
	
	//3
	cout<<"El promedio de las notas en los finales es de: "<<(totalFinal/n)<<endl;
		
		
	
	
	
	
}
