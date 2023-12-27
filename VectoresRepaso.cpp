#include <conio.h>
#include <iostream>

using namespace std;

int main (void)
{
	int dim, i, sum, sumImpares, contImpar, contPos, aux, contValor;
	double promedio;
	
	cout<<"Ingrese la dimension del vector"<<endl;
	cin>>dim;
	
	int vec[dim];
	
	// 1
	
	for (i=0, sum=0; i < dim; i++) {
		cout<<"Ingrese el cotenido de la posicion: "<<i<<endl;
		cin>>vec[i];
		
		// 2
		sum=sum+vec[i];
	}
	
	cout<<"La suma de los contenidos del vector es de: "<<sum<<endl;
	
	// 3
	cout<<"El promedio de los elementos del vector es de: "<<((double)sum/dim)<<endl;
	
	// 4
	for (i=1, sumImpares=0; i < dim; i+=2) {
		sumImpares=sumImpares+vec[i];
	}
	
	cout<<"La suma de los elementos que estan en posiciones impares es de: "<<sumImpares<<endl;
	
	// 5
	for (i=0, contImpar=0; i < dim; i++) {
		if (vec[i] % 2 != 0)
		contImpar=contImpar+vec[i];
	}
	
	cout<<"La suma de los elementos de contenidos impares es de: "<<contImpar<<endl;
	
	// 6
	for (i=0, contPos=0; i < dim; i+=2) {
		if (vec[i] > 0)
		contPos=contPos+vec[i];
	}
	
	cout<<"La suma de los elementos de contenido positivos que esten en posiciones pares es de: "<<contPos<<endl;
	
	// 7
	for (i=dim-1; i >= 0; i--) {
		cout<<"Vec["<<i<<"]:"<<vec[i]<<endl;
	}
	
	// 8
	cout<<"Ingrese el valor a buscar en el vector: "<<endl;
	cin>>aux;
	
	for (i=0, contValor=0; i < dim; i++) {
		if (vec[i]==aux)
		contValor=contValor+1;
	}
	
	cout<<"El valor: "<<aux<< " aparece "<<contValor<<" veces en el vector"<<endl;
	
	getch();
	return (0);
}

