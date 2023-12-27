#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#define CANTVENDEDORES 3
#define CANTMODELOS 2

using namespace std;

int main (void)
{
	int matVentasMes[CANTVENDEDORES][CANTMODELOS], vecLegajos[CANTVENDEDORES], vecIndMaxVendedores[CANTVENDEDORES], i, j, auxLegajo, unidades, f, c, maxPosVenta, suma, sumaVentasVendedor, iMax, maxVendedor;
	double vecPrecios[CANTMODELOS], monto, auxPrecio, maxVenta;
	
	for (i=0; i<CANTVENDEDORES; i++){
		for (j=0; j<CANTMODELOS; j++){
			matVentasMes[i][j]=0;
		}
	}
	
	
	for (i=0; i<CANTVENDEDORES; i++){
		cout<<"Ingrese el numero de legajo del vendedor "<<i+1<<". (Entre 1000 y 2000)"<<endl;
		cin>>auxLegajo;
		
		while ((auxLegajo<1000) || (auxLegajo>2000)){
			cout<<"El numero de legajo ingresado no es valido. Intentelo nuevamente..."<<endl;
			cin>>auxLegajo;
		}
		
		vecLegajos[i]=auxLegajo;
	}
	
	for (j=0; j<CANTMODELOS; j++){
		cout<<"Ingrese el precio del modelo de auto con el codigo: "<<j<<endl;
		cin>>auxPrecio;
		
		while (vecPrecios[j]<=0){
			cout<<"El precio ingresano es valido. Ingreselo nuevamente"<<endl;
			cin>>auxPrecio;
		}
		
		vecPrecios[i]=auxPrecio;
	}
	
	cout<<"Ingrese el legajo del vendedor que va a ingresar una venta (0 para fin de ingreso de datos)"<<endl;
	cin>>auxLegajo;
	
	while (((auxLegajo<1000) || (auxLegajo>2000)) && (auxLegajo!=0)){
			cout<<"El numero de legajo ingresado no es valido. Intentelo nuevamente..."<<endl;
		}
	
	while(auxLegajo!=0){
		
		i=0;
		while (i<CANTVENDEDORES && vecLegajos[i]!=auxLegajo){
			i++;
		}
		if(i==CANTVENDEDORES){
			cout<<endl<<"El legajo del vendedor ingresado no es valido"<<endl;
	
		}
		else{
			cout<<endl<<"Ingrese el codigo del auto vendido: (0 a 9) "<<endl;
			cin>>j;	
			
			while ((j<0) || (j>9)){
				cout<<"El codigo del auto ingresado no es valido. Intentelo nuevamente..."<<endl;
				cin>>j;
			}
			
			matVentasMes[i][j]++;
			
		}
	
		cout<<"Ingrese el legajo del vendedor que va a ingresar una venta (0 para fin de ingreso de datos)"<<endl;
		cin>>auxLegajo;
	
	}	
	
	// 1
	cout<<setw(10)<<" Modelos: ";
	for (j=0; j<CANTMODELOS; j++){
		cout<<setw(5)<<j;
	}
	cout<<endl<<endl;
	for (i=0; i<CANTVENDEDORES; i++){
		cout<<setw(5)<<vecLegajos[i];
		for (j=0; j<CANTMODELOS; j++){
			cout<<setw(5)<<matVentasMes[i][j];
		}	
		cout<<endl;
	}
	
	// 2
	for (j=0; j<CANTMODELOS; j++){
		suma=0;
		for (i=0; i<CANTVENDEDORES; i++){
			suma+=matVentasMes[i][j];
		}
		
		cout<<"La cantidad de autos vendidos del modelo "<<j<<" es de "<<suma<<endl;
	}	
	
	if (j==0){
		maxVenta=suma;
		maxPosVenta=c;
	}
	else
		if(suma>maxVenta){
			maxVenta=suma;
			maxPosVenta=c;
		}
	
	
	// 3
	monto=0;
	for (i=0; i<CANTVENDEDORES; i++){
		for (j=0; j<CANTMODELOS; j++){
			monto+=(matVentasMes[i][j]*vecPrecios[j]);
		}
	}
	
	
	cout<<"El monto total vendido por la agencia durante el mes es de: "<<monto<<endl;
	
	
	// 4
	cout<<"El modelo del cual se vendieron mas unidades es: "<<maxPosVenta<<" con un total de: "<<maxVenta<<endl;
	
	
	// 5
	for (i=0; i<CANTVENDEDORES; i++)
		cout<<"El vendedor con legajo "<<vecLegajos[i]<<" vendio "<<matVentasMes[i][maxPosVenta]<<" unidades del auto mas vendido"<<endl;
	
	
	// 
	for (i=0; i<CANTVENDEDORES; i++){
		sumaVentasVendedor=0;
		for (j=0; j<CANTMODELOS; j++){
			sumaVentasVendedor+=matVentasMes[i][j];
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
	
	
	getch ();
	return(0);
}
