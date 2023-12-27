#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#define CANTSUCURSALES 5

using namespace std;

struct DatoProducto{
	int cod;
	char desc[30];
	double precioUni;
	int stockIni;
	int idSuc;
	int cantVen;
};


int main (void)
{
	int dim;
	
	cout<<"Ingrese la cantidad de productos de su negocio: "<<endl;
	cin>>dim;
	
	DatoProducto listaProd[dim];
	DatoProducto listaSuc[CANTSUCURSALES];
	
	int mat[dim][CANTSUCURSALES], i, j, auxIdSuc, auxCod, vecCantVentasXSuc[i], cantVendida, stockActual[dim];
	
	for(i=0;i<CANTSUCURSALES;i++){
		for(j=0;j<dim;j++){
			mat[i][j]=0;
			vecCantVentasXSuc[i];
		}
	}	
	
	
	for (i=0; i<dim; i++){
		cout<<"Ingrese el codigo del producto "<<i+1<<endl;
		cin>>listaProd[i].cod;
		
		cout<<"Ingrese una descripcion breve del producto (una sola palabra): "<<endl;
		cin>>listaProd[i].desc;
		
		cout<<"Ingrese el precio unitario del producto: "<<endl;
		cin>>listaProd[i].precioUni;
		
		cout<<"Ingrese el stock inicial del producto: "<<endl;
		cin>>listaProd[i].stockIni;
	}
	
	for (j=0; j<CANTSUCURSALES; j++){
		cout<<"Ingrese el id de la sucursal: "<<j<<endl;
		cin>>listaSuc[j].idSuc;
		
		cout<<"Ingrese la cantidad de vendedores de esa sucursal: "<<j<<endl;
		cin>>listaSuc[j].cantVen;
	}
	
	cout<<"Ingrese el codigo del produto del que va a realizar la venta (0 para fin de ingreso de datos)"<<endl;
	cin>>auxCod;
	
	while(auxCod!=0){
		
		i=0;
		while (i<dim && listaProd[i].cod!=auxCod){
			i++;
		}
		if(i==dim){
			cout<<endl<<"El codigo del producto ingresado no es valido."<<endl;
	
		}
		else{
			cout<<endl<<"Ingrese el id de la sucursal que vendio: "<<endl;
			cin>>auxIdSuc;			
		}
		
		j=0;
		while (j<CANTSUCURSALES && listaSuc[j].idSuc!=auxIdSuc){
			j++;
		}
		if(j==CANTSUCURSALES){
			cout<<endl<<"El id de la sucursal que vendio no es valido."<<endl;
		}
		else{
			cout<<"Ingrese la cantidad vendida"<<endl;
			cin>>cantVendida;
		}
		
		while(listaProd[i].stockIni<cantVendida){
			cout<<"La cantidad vendida supera el stock actual. Reingrese"<<endl;
			cin>>cantVendida;
		}
		// contador de venta
		mat[i][j]+=cantVendida;
		stockActual[i]=stockActual[i]-(listaProd[i].stockIni-mat[i][j]);
		vecCantVentasXSuc[i]++;
		
		cout<<"Ingrese el codigo del produto del que va a realizar la venta (0 para fin de ingreso de datos)"<<endl;
		cin>>auxCod;
	}
	
	//1
	for(i=0;i<dim;i++){
		for(j=0;j<CANTSUCURSALES;j++){
			if((i==0)&&(j==0)){
				maxVentaSuc=mat[i][j];
				maxPosVentaSuc=k;
				maxVentaVendedores=vecCantVendedores[k];
			}
			else
				if(mat[i][j]>maxVentaSuc){
					maxVentaSuc=mat[i][j];
					maxPosVentaSuc=k;
					maxVentaVendedores=vecCantVendedores[k];
			}
		}
	cout<<endl<<"la sucursal con mayor venta fue la sucursal: "<<maxPosVentaSuc<<" con un total vendido de: "<<maxVentaSuc<<"$, y tiene un total de "<<maxVentaVendedores<<" vendedores."<<endl<<endl;
	}
	
	
	
	
	//2
	
		for(c=0;c<CANTPROCUTOS;c++){
			
			cout<<"el procucto de codigo: "<<listaProd[i].cod<<"tiene un stock actual de: "<<stockActual[i]<<endl;
			
		}
	
	
	//4
	for(i=0;i<dim;i++){
		TotalVendidoSuc=0;
		for(j=0;j<CANTSUCURSALES;j++){
			TotalVendidoSuc+=mat[i][j];
		}
		cout<<"La sucursal "<<j<<" vendio "<<totalVendidoSuc<<endl;
	}
	
	//3
	for(i=0;i<dim;i++){
		for(j=0;j<CANTSUCURSALES;j++){
			cout<<"El total vendido por la sucursal"<<listaSuc[j].idSuc<<" fue de"<<mat[i][j]<<" con una ganancia total de"<<
		}
		cout<<endl<<"La sucursal: "<<listaSuc[j].idSuc<<" realizo un total de "<<vecCantVentasXSuc[i]<<" ventas en un mes"<<endl;
		
		
	}
	
	//5
	for(j=0;j<CANTSUCURSALES;j++){
		
		cout<<"la sucursal "<<listaSuc[j].idSuc<<" con "<<vecCantVendedores[k]<<" vendedores, vendio por cada vendedor un promedio de: "<<(TotalVendidoSuc[j]/vecCantVendedores[k])<<" productos."<<endl;
		
	}
