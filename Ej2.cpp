#include <iostream>
#include <conio.h>

using namespace std;

int main (void){
	int dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8, dig9, dig10, dig11, valor1, valor2, valor3, digCor;
	
	cout<<"Ingrese CUIT (un numero abajo del otro)"<<endl;
	cin>>dig1;
	cin>>dig2;
	cin>>dig3;
	cin>>dig4;
	cin>>dig5;
	cin>>dig6;
	cin>>dig7;
	cin>>dig8;
	cin>>dig9;
	cin>>dig10;
	cin>>dig11;
	
	valor1=(dig1*5)+(dig2*4)+(dig3*3)+(dig4*2)+(dig5*7)+(dig6*6)+(dig7*5)+(dig8*4)+(dig9*3)+(dig10*2);
	
	valor2=(valor1%11);
	
	valor3=(11-valor2);
	
	if (valor3==11)
		digCor=0;
			else
				if (valor3==10)
					digCor=9;
					else
						digCor=valor3;
						
	if (digCor==11)
		cout<<"El codigo es correcto"<<endl;
		else
			cout<<"El codigo es incorrecto, ingrese nuevamente"<<endl;
								
							
	getch();
	
	return (0);
   	
	
}
	

