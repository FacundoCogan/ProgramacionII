#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;


int main (void){
	
	string registro, nombre;
	int cont, notaUno, notaDos, notaTres, notaCuatro;
	
	cout<<"Hay registros para cargar? (s/n)"<<endl;
	cin>>registro;
	
	while (registro=="s"){
		
		cout<<"Ingrese el nombre del alumno: "<<endl;
		cin>>nombre;
		
		cout<<"Ingrese su primera nota: "<<endl;
		cin>>notaUno
		
		cout<<"Ingrese su segunda nota: "<<endl;
		cin>>notaDos
		
		cout<<"Ingrese su tercera nota: "<<endl;
		cin>>notaTres
		
		cout<<"Ingrese su cuarta nota: "<<endl;
		cin>>notaCuatro
		
		//1
		if (notaUno>notaDos && notaUno>notaTres && notaUno>notaCuatro){
			cout<<"La mayor nota es la nota uno con el puntaje: "<<notaUno<<endl;
		}
		else{
			if (notaDos>notaTres && notaDos>notaCuatro){
				cout<<"La mayor nota es la nota dos con el puntaje: "<<notaDos<<endl;
			}
			else{
				if(notaTres>notaCuatro){
					cout<<"La mayor nota es la nota tres con el puntaje: "<<notaTres<<endl;
				}
				else{
					cout<<"La mayor nota es la nota cuatro con el puntaje: "<<notaCuatro<<endl;
				}
			}
		}
		
		if (notaUno<notaDos && notaUno<notaTres && notaUno<notaCuatro){
			cout<<"La peor nota es la nota uno con el puntaje: "<<notaUno<<endl;
		}
		else{
			if (notaDos<notaTres && notaDos<notaCuatro){
				cout<<"La peor nota es la nota dos con el puntaje: "<<notaDos<<endl;
			}
			else{
				if(notaTres<notaCuatro){
					cout<<"La peor nota es la nota tres con el puntaje: "<<notaTres<<endl;
				}
				else{
					cout<<"La peor nota es la nota cuatro con el puntaje: "<<notaCuatro<<endl;
				}
			}
		}
		
		
		//2
		if ((notaUno>=4) && (notaDos>=4) && (notaTres>=4) && (notaCuatro>=4)){
			cont++;
		}
		
	}
}
