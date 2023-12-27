#include <iostream>
#include <conio.h>

using namespace std;

int main (void){
	int i, dim, indVec1Vec2;
	
	cout<<"Ingrese la dimension del vector"<<endl;
	cin>>dim;
	
	int vec1[dim], vec2[dim];
	
	for (i=0; i<dim; i++){
		cout<<"Ingrese los numeros del primer vector en la posicion: "<<i<<endl;
		cin>>vec1[i];	
	}
	
	for (i=0; i<dim; i++){
		cout<<"Ingrese los numeros del segundo vector en la posicion: "<<i<<endl;
		cin>>vec2[i];
	}
	
	int vec3[dim*2];
	
	for(i=0; indVec1Vec2<dim; i++){
		vec3[i]=0;
	}
	
	indVec1Vec2=0;
	for (i=0; i<dim; i++){
		
		vec3[indVec1Vec2]=vec1[i];
		indVec1Vec2++;
		
		vec3[indVec1Vec2]=vec2[i];
		indVec1Vec2++;
		
	}
	
	cout<<"vec3"<<endl;
	for (i=0; i<(dim*2); i++){
		cout<<vec3[i]<<endl;
	}
	
	
	getch();
	
	return(0);
}
