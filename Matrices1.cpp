#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main (void)
{
	int n, m, i, j;
	
	cout<<"Ingrese cantidad de filas de la matriz: "<<endl;
	cin>>n;
	
	cout<<"Ingrese la cantidad de columnas de la matriz: "<<endl;
	cin>>m;
	
	int mat[n][m];
	
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			mat[i][j]=0;
		}
	}
	
	for (j=0; j<1; j++){
		for (i=0; i<n; i++){		
			cout<<"Ingrese los numeros para la primera columna: "<<endl;
			cin>>mat[i][j];
		}
	}
		
	for (j=1; j<m; j++){
		for (i=0; i<n; i++){
			mat[i][j]=mat[i][j-1]+1;
		}
	}
	
	
	for (i=0; i<n; i++)
	{
		cout<<" Fila "<<i<<":";
		for (j=0; j<m; j++)
		{
			cout<<setw(5)<<mat[i][j];
		}
		cout<<endl;
	}
	
	
	getch ();
	return(0);
}
