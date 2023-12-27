#include <iostream>
#include <conio.h>

using namespace std;

int main (void){
	int nroDia, nroMes;
	
	cout<<"Ingrese numero de dia (1-7)"<<endl;
	cin>>nroDia;
	
	cout<<"Ingrese numero de mes (1-12)"<<endl;
	cin>>nroMes;
	
	switch (nroDia)         /* tipo ordinales (entero o char) */
	{
		case (1): cout<<"Lunes"<<endl; break;
		case (2): cout<<"Martes"<<endl; break;
		case (3): cout<<"Miercoles"<<endl; break;
		case (4): cout<<"Jueves"<<endl; break;
		case (5): cout<<"Viernes"<<endl; break;
		case (6): cout<<"Sabado"<<endl; break;
	}
	
		switch (nroMes)
	{
		case (4): 
		case (6): 
		case (9): 
		case (11): cout<<"El mes tiene 30 dias"<<endl; break;
		
		case (1): 
		case (3): 
		case (5): 
		case (7): 
		case (8): 
		case (10): 
		case (12): cout<<"El mes tiene 31 dias"<<endl; break;
		
		case (2):  cout<<"El mes tiene 28/29 dias"<<endl; break;
		
		default: cout<<"El mes no es valido"<<endl; break;             /* default es optativo */
	}
	
	
	getch();
	return (0);
	
	 
}
