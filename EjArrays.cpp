#include <iostream>
#include <conio.h>

using namespace std;

int main (void){
	int i, dim, vec1[30], vec2[30];
	
	
	// 1
	for (i=0; i<=30; i++){
		vec1[i]=i+1;
	}
	
	for( i=0; i<dim; i++){
		cout<<"El vector de 30 numeros ascendentes: "<<vec1[i]<<endl;
	}	
	
	// 2
	for (i=30; i>0; i--){
		vec2[i-1];
	}
	
	for( i=0; i<dim; i++){
	
		cout<<"El vector de 30 numeros descendentes: "<<vec2[i]<<endl;
	}
	
	// 3
	cout<<"Ingrese la dimension del vector"<<endl;
	cin>>dim;
	
	int vec3[dim], vec4[dim];
	
	for (i=0; i<dim; i++){
		vec3[i]=i+1;
	}
	
	for( i=0; i<dim; i++){
		cout<<"El vector de N numeros ascendentes: "<<vec3[i]<<endl;
	}

	
	// 4
	for (i=dim; i>=0; i--){
		vec4[i-1]=i;
	}
	
	for( i=0; i<dim; i++){
		cout<<"El vector de N numeros descendentes: "<<vec4[i]<<endl;
	}
	
	getch ();
	return(0);
	

}
