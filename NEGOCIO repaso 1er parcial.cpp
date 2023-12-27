#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#define CANTSUCURSALES 5

using namespace std;

struct Producto{
	int cod;
	char desc[30];
	double precioUni;
	int stockIni;
	int idSuc;
	int cantVendedores;
};


int main (void){
	
	int n, auxCodProd, auxIdSuc, cantVendida;
	
	cout<<"Ingrese la cantidad de productos de su negocio: "<<endl;
	cin>>n;
	
	Producto vecProd[n];
	Producto vecSuc[CANTSUCURSALES];
	
	int matCantProdVendida[n][CANTSUCURSALES], i, j, vecCantVentasXSuc[n], stockActual[n];
	
	for (i=0; i<n; i++){
		cout<<"Ingrese el codigo del producto "<<i+1<<endl;
		cin>>vecProd[i].cod;
		
		cout<<"Ingrese una breve descripcion del producto "<<i+1<<endl;
		cin>>vecProd[i].desc;
		
		cout<<"Ingrese el precio unitario del producto "<<i+1<<endl;
		cin>>vecProd[i].precioUni;
		
		cout<<"Ingrese el stock inicial del producto "<<i+1<<endl;
		cin>>vecProd[i].stockIni;
	}
	
	for (j=0; j<CANTSUCURSALES; j++){
		cout<<"Ingrese el id de la sucursal "<<j+1<<endl;
		cin>>vecSuc[j].idSuc;
		
		cout<<"Ingrese la cantidad de vendedores de la sucursal "<<j+1<<endl;
		cin>>vecSuc[j].cantVendedores;
	}
	
	cout<<"Ingrese el codigo del producto del que se va a registrar una venta (0 para fin de ingreso de datos): "<<endl;
	cin>>auxCodProd;
	
	while(auxCodProd!=0){
		i=0;
		while((i<n) && (vecProd[i].cod!=auxCodProd)){
			i++;
		}
		if(i==n){
			cout<<"El codigo de producto ingresado no es valido. Intentelo nuevamente..."<<endl;
			cin>>auxCodProd;
		}
		else{
			cout<<"Ingrese la sucursal en la que se realizo la venta del producto: "<<endl;
			cin>>auxIdSuc;
		}
		j=0;
		while((j<CANTSUCURSALES) && (vecSuc[j].idSuc!=auxIdSuc)){
			j++;
		}
		if(j==CANTSUCURSALES){
			cout<<"La sucursal ingresada no es valida. Intentelo nuevamente..."<<endl;
			cin>>auxIdSuc;
		}
		else{
			cout<<"Ingrese las cantidada vendida: "<<endl;
			cin>>cantVendida;
		}
		
		while(vecSuc[j].stockIni<cantVendida){
			cout<<"La cantidad vendida no puede superar al stock. Intentelo nuevamente..."<<endl;
			cin>>cantVendida;
		}
		
		matCantProdVendida[i][j]+=cantVendida;
		stockActual[i]+=(vecProd[i].stockIni-matCantProdVendida[i][j]);
		vecCantVentasXSuc[j]++;
		
		cout<<"Ingrese el codigo del producto del que se va a registrar una venta (0 para fin de ingreso de datos): "<<endl;
		cin>>auxCodProd;
		
	}
	
	//1
	int maxSucVendida=0;
	int maxIdSuc=0;
	int maxCantVendedores=0;
	
	for(i=0; i<n; i++){
		for(j=0; j<CANTSUCURSALES; j++){
			if ((i==0) && (j==0)){
				maxSucVendida=matCantProdVendida[i][j];
				maxIdSuc=j;
				maxCantVendedores=vecSuc[j].cantVendedores;
			}
			else{
				if(matCantProdVendida[i][j]>maxSucVendida){
					maxSucVendida=matCantProdVendida[i][j];
					maxIdSuc=j;
					maxCantVendedores=vecSuc[j].cantVendedores;
				}
			}
		}
		
		cout<<"Del producto "<<vecProd[i].cod<<" la sucursal que mas vendio fue la "<<maxIdSuc<<" con un total vendido de $"<<maxSucVendida<<", y tiene un total de "<<maxCantVendedores<<" vendedores."<<endl;
	}
	
	//2
	for(i=0; i<n; i++){
		cout<<"El producto "<<vecProd[i].cod<<" tiene un stock actual de "<<stockActual[i]<<endl;
	}
	
	//3
	double totalVendido;
	
	for(j=0; j<CANTSUCURSALES; j++){
		totalVendido=0;
		for(i=0; i<n; i++){
			totalVendido+=(matCantProdVendida[i][j]*vecProd[i].precioUni);
		}
		
		cout<<"La sucursal "<<vecSuc[j].idSuc<<" vendio un total de $"<<totalVendido<<endl;
	}
	
	//4
	for(j=0; j<CANTSUCURSALES; j++){
		cout<<"La sucursal "<<vecSuc[j].idSuc<<" realizo un total de "<<vecCantVentasXSuc[j]<<" ventas."<<endl;
	}
	
	//5
	for(j=0; j<CANTSUCURSALES; j++){
		
		cout<<"La sucursal "<<vecSuc[j].idSuc<<" con una cantidad de "<<vecSuc[j].cantVendedores<<" vendedores, la cantidad promedio de productos vendidos por vendedor es de "<<(totalVendido/vecSuc[j].cantVendedores)<<endl;
	}
	
	
	
	
}
