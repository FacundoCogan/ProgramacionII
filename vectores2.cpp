#include <iostream>
#include <conio.h>

using namespace std;

int main (void){
	int aux, k, i, pasada, juntar, dim;
	
	cout<<"Ingrese la longitud del vector"<<endl;
	cin>>dim;
	
	int vec1[dim], vec2[dim];
	
	int vec3[dim*2];
	
	for(i=0;i<dim;i++){
		cout<<"Ingrese el valor de vec1"<<endl;
		cin>>vec1[i];
		cout<<"Ingrese el valor de vec2"<<endl;
		cin>>vec2[i];
	}
	
	cout<<"Ingrese el numero por el cual desea juntar, debe ser multiplo de N"<<endl;
	cin>>juntar;
	
	while ((dim%juntar)!=0){
		cout<<"El numero ingresado no es multiplo de N, ingrese un numero valido"<<endl;
		cin>>juntar;
	}
	
	aux=0;
	k=0;
	pasada=0;
	while ((k<dim*2) && (i<dim))
	{
		pasada++;
		
		cout<<endl<<endl<<"Estoy en la pasada: "<<pasada;
		cout<<endl<<"aux= "<<aux<<"      juntar*pasada= "<<(juntar*pasada);
		for (i=aux; (i<juntar*pasada); i++)
		{
			vec3[k]=vec1[i];
			vec3[k+juntar]=vec2[i]; cout<<endl<<" k= "<<k<<" i= "<<i<<" k+juntar= "<<(k+juntar);
			k++;
		}
	}
	k+=juntar;
	cout<<endl<<endl<<"El valor de i es: "<<i<<"     el valor de k es: "<<k;
	aux=i;
	
	for (k=0;k<dim*2;k++){
		cout<<vec3[k]<<endl;
	}
	
	getch();
	return(0);
}
