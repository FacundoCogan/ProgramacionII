#include <iostream>
#include <conio.h>

using namespace std;

int main (void){
	int dni, legajo, contrato,cantHSNorDisp,cantHSExtraDisp,cantHSNor,cantExtra, sueldoXHS, sueldoXHSExtra, sueldoTotal, HSTotales;
	
	cout<<"Ingrese el DNI"<<endl;
	cin>>dni;
	
	cout<<"Ingrese el numero de legajo"<<endl;
	cin>>legajo;
	
	cout<<"Ingrese su tipo de contrato (1-5-10)"<<endl;
	cin>>contrato;
	
	cout<<"Ingrese la cantidad de horas que tiene disponible"<<endl;
	cin>>cantHSNorDisp;
	
	cout<<"Ingrese la cantidad de horas extras que tiene disponible"<<endl;
	cin>>cantHSExtraDisp;
	
	cout<<"Ingrese la cantidad de horas que trabajo en el mes"<<endl;
	cin>>cantHSNor;
	
	cout<<"Ingrese la cantidad de horas extra que trabajo en el mes"<<endl;
	cin>>cantExtra;
	
	HSTotales=(cantHSNor+cantExtra);
	
	// 1
	switch (contrato)
	{
		case (1): sueldoXHS=1000, sueldoXHSExtra=1500; break;
		case (5): sueldoXHS=700, sueldoXHSExtra=1000; break;
		case (10): sueldoXHS=300, sueldoXHSExtra=400; break;
	}
	
	sueldoTotal=(sueldoXHS*cantHSNor)+(sueldoXHSExtra*cantExtra);
	
	cout<<"El sueldo total del empleado es de: $"<<sueldoTotal<<endl;
	
	// 2
	if (HSTotales>200)
		cout<<"El empleado trabajo mas de 200 horas"<<endl;
	
	getch ();
	
	return(0);
	
	
	 
}
