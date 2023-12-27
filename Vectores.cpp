#include <iostream>
#include <conio.h>

using namespace std;

int main (void){
	int dim, i, sum, aux;
	double promedio;
	
	// 1
	cout <<"Ingrese la dimension del vector: "<<endl;
	cin >>dim;
	
	int vec[dim];
	
	for( i=0; i<dim; i++) {
		cout <<"Ingrese el contenido de la posición: "<<(i+1) <<" del vector:... "<<endl;
		cin >>vec[i];
	}

	// 2
	sum=0;
	for( i=0; i<dim; i++) {
		sum += vec[i];
		cout <<" ";
	}

	// 3
	cout<<"El promedio de todos los elementos del vector es: "<<((double)sum/dim)<<endl;
	
	// 4
	sum=0;
	for( i=1; i<dim; i+=2)
		sum += vec[i];

	// 5
	sum=0;
	for (i=0; i<dim; i++)
		if (vec[i] % 2 != 0)
			sum += vec[i];
	
	// 6
	sum=0;
	for (i=0; i<dim; i+=2)
		if (vec[i]>0)
			sum += vec[i];
			
	// 7
	for( i=dim-1; i>=0; i--)
	{
		cout<<"Vec["<< i <<"]:..."<<vec[i]<<endl;
	}
	
	// 8
	cout<<endl<<"Ingrese el valor a buscar en el vector: "<<endl;
	cin>>aux;
	for (i=0, sum=0; i<dim; i++)
	{
		if (vec[i]==aux)
			sum ++;
	}
	cout<<endl;

	getch();
	
	return(0);
	
	
}
