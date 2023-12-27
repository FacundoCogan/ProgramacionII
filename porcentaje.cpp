#include <iostream>
#include <conio.h>

using namespace std;

int main (void)
{
	int cantPreguntas, cantCorrectas;
	double porcentaje;
	
	cout<<"Ingrese la cantidad de preguntas formuladas"<<endl;
	cin>>cantPreguntas;
	
	cout<<"Ingrese la cantidad de respuestas correctas"<<endl;
	cin>>cantCorrectas;
	
	porcentaje=(double)cantCorrectas*100)/(double)cantPreguntas);
	
	
	if (porcentaje>=90)

		cout<<"Nivel superior"<<endl;

		else

			if (porcentaje>=75)

				cout<<"Nivel medio"<<endl;

			else

				if(porcentaje>=50)

					cout<<"Nivel regular"<<endl;

				else

					cout<<"Fuera de nivel"<<endl;


	getch();
	
	return (0);
	
	
}
