#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#define CANTVENDEDORES 2
#define CANTMODELOS 2

using namespace std;

int main (void){
	
	int matCantVendida[CANTVENDEDORES][CANTMODELOS], i, j, vecLegajos[CANTVENDEDORES], auxLegajo, maxModeloVenta, maxPosVenta, sumaVentasVendedor, iMax, vecIndMaxVendedores[CANTVENDEDORES], maxVendedor;
	double vecPrecios[CANTMODELOS], auxPrecio;
	
	for(i=0; i<CANTVENDEDORES; i++){
		vecLegajos[i]=0;
		for(j=0; j<CANTMODELOS; j++){
			matCantVendida[i][j]=0;
			vecPrecios[j]=0;
		}
	}
	
	//Llenamos vectores
	for(i=0; i<CANTVENDEDORES; i++){
		cout<<"Ingrese el numero de legajo del vendedor: "<<i+1<<" (entre 1000 y 2000)"<<endl;
		cin>>auxLegajo;
		
		while((auxLegajo<1000) || (auxLegajo>2000)){
			cout<<"El numero de legajo ingresado no es valido. Intentelo nuevamente..."<<endl;
			cin>>auxLegajo;
		}
		vecLegajos[i]=auxLegajo;
	}
	
	for(j=0; j<CANTMODELOS; j++){
		cout<<"Ingrese el precio del modelo de auto con codigo: "<<j<<endl;
		cin>>auxPrecio;
		
		while(auxPrecio<0){
			cout<<"El precio ingresado es negativo, por lo tanto no es valido. Intentelo nuevamente..."<<endl;
			cin>>auxPrecio;
		}
		
		vecPrecios[j]=auxPrecio;
	}
	
	// Comienza validacion del legajo
	
	cout<<"Ingrese el legajo del vendedor que realizo una venta (0 para fin de ingreso de datos): "<<endl;
	cin>>auxLegajo;
	
	while (((auxLegajo<1000) || (auxLegajo>2000) && (auxLegajo!=0))){
		cout<<"El legajo ingresado no es valido. Vuelva a intentarlo..."<<endl;
		cin>>auxLegajo;
	}
	
	while (auxLegajo!=0){
		
		i=0;
		while((i<CANTVENDEDORES) && (vecLegajos[i]!=auxLegajo)){
			i++;
		}	if(i==CANTVENDEDORES){
			cout<<"El legajo ingresado no es valido. Intentelo nuevamente..."<<endl;
			cin>>auxLegajo;
			}
			else{
			cout<<"Ingrese el codigo del modelo vendido (0-9): "<<endl;
			cin>>j;
			
			while((j<0) || (j>9)){
				cout<<"El codigo ingresado no es valido. Intentelo nuevamente..."<<endl;
				cin>>j;
			}
			
			matCantVendida[i][j]++;
		}
		
		cout<<"Ingrese el legajo del vendedor que realizo una venta (0 para fin de ingreso de datos): "<<endl;
		cin>>auxLegajo;
	}
	
	//1
	for(i=0; i<CANTVENDEDORES; i++){
		for(j=0; j<CANTMODELOS; j++){
			cout<<"El vendedor con legajo "<<vecLegajos[i]<<" vendio "<<matCantVendida[i][j]<<" unidades del modelo: "<<j<<endl;
		}	
	}
	
	//2
	int suma;
	for(j=0; j<CANTMODELOS; j++){
		suma=0;
		for(i=0; i<CANTVENDEDORES; i++){
			suma+=matCantVendida[i][j];
		}
		
		cout<<"Del modelo "<<j<<" se vendieron "<<suma<<" unidades"<<endl;
	}

	//3
	double monto=0;
	for(i=0; i<CANTVENDEDORES; i++){
		for(j=0; j<CANTMODELOS; j++){
			monto+=(matCantVendida[i][j]*vecPrecios[i]);
		}
	}
	
	cout<<"El monto total vendido por la agencia fue de: "<<monto<<endl;
		
	//4
	if(j==0){
		maxModeloVenta=suma;
		maxPosVenta=j;
	}
	else{
		if(suma>maxModeloVenta){
			maxModeloVenta=suma;
			maxPosVenta=j;
		}
	}

	cout<<"El numero de modelo con mayor cantidad de ventas fue el modelo: "<<maxModeloVenta<<endl;
	
	//5
	for (i=0; i<CANTVENDEDORES; i++){
		cout<<"El vendedor con legajo "<<vecLegajos[i]<<" vendio "<<matCantVendida[i][maxPosVenta]<<" unidades del modelo mas vendido."<<endl;
	}
	
	//6
	for (i=0; i<CANTVENDEDORES; i++){
	sumaVentasVendedor=0;
		for (j=0; j<CANTMODELOS; j++){
		sumaVentasVendedor+=matCantVendida[i][j];
	}
	if (j==0){
		maxVendedor=sumaVentasVendedor;
		iMax=0;
		vecIndMaxVendedores[iMax]=i;	
	}
	else
		if (sumaVentasVendedor>maxVendedor){
		maxVendedor=sumaVentasVendedor;
		iMax=0;
		vecIndMaxVendedores[iMax]=i;
		}
		else
			if (sumaVentasVendedor==maxVendedor){
				iMax++;
				vecIndMaxVendedores[iMax]=i;
			}
	}
	cout<<"La mayor cantidad de ventas entre los vendedores es: "<<maxVendedor<<" y los vendedores fueron: "<<endl;
	for (i=0; i<=iMax; i++){
		cout<<vecLegajos[vecIndMaxVendedores[i]]<<endl;	
	}

}
