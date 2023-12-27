#include <iostream>
#include <conio.h>

using namespace std;

int main (void)
{
	int a, b, cont=0;
	
	cout <<"Ingrese el valor de a: "<<endl;
	cin >>a;
	
	cout <<"Ingrese el valor de b: "<<endl;
	cin >>b;
	
	cout <<"Usando ciclo WHILE ... (MIENTRAS)"<<endl;
	while (cont<=b)
	{
		cout <<"Muestro el valor de a " << a << " - es la " <<cont<< " vez que lo muestro" <<endl;
		cont ++;
	}

	cout <<endl<<endl<<"Usando ciclo DO ... WHILE (repetir) "<<endl;
	cont = 1;
	do
	{
		cout <<"Muestro el valor de a " << a << " - es la " <<cont<< " vez que lo muestro" <<endl;
		cont ++;
	}
	while (cont <=b);
	
	cout <<endl<<endl<<"Usando ciclo FOR ... (para) "<<endl;

	for (cont=0; cont < b; cont++)
		cout <<"Muestro el valor de a " << a << " - es la " <<cont<< " vez que lo muestro" <<endl;
		
		cout <<endl<<endl<<"Usando IF ... (si) "<<endl;
		
		if (a > b)
				cout<<"El valor de a es mayor que b"<<endl;
			else
				if (a<b)
				{
					cout<<"El valor de b es mayor que a"<<endl;
					cout<<"******************"<<endl;
					
				}
				else cout<<"Ambos son iguales"<<endl;

	getch();
	
	return (0);
	
	} // cierra main
