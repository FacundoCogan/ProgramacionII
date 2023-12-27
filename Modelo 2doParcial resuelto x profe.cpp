#include <iostream>
#include <stdio.h>
#include <conio.h>


#define DIM 100

using namespace std;

struct Productos{
	int codProducto;
	double precioCompra;
	double precioVenta;
	int stockInicial;
	int stockMinimo;
	int stockActual;
};


/*
Función Ganancia: Dado un vector con los datos de los productos,y su longitud,  
devolver cual sería el margen de ganancia total sobre el stock actual.
*/

double ganancia(Productos vec[],int dimVec){
	double sumaGanancia;
	int i;
	
	sumaGanancia=0;
	
	for(i=0;i<dimVec;i++){
		sumaGanancia=sumaGanancia+((vec[i].precioVenta -vec[i].precioCompra)*vec[i].stockActual);
	}
	
	return (sumaGanancia);
	
}


/*
Función Pedir: Dado un producto, devolver un indicador 
si el stock actual del producto alcanza el stock mínimo.
*/

bool pedir (Productos unProducto){
	return (unProducto.stockActual==unProducto.stockMinimo);
}


/*
Función MaximoyMinimo: Dado un vector con los datos de los productos,  
y su longitud,  devolver el menor precio de Venta y el mayor precio de Venta.
*/

void maximoYMinimo(Productos vec[],int dimVec, double &minPrecio, double &maxPrecio){
	
	int i;
	
	minPrecio=vec[0].precioVenta;
	maxPrecio=vec[0].precioVenta;
	
	for(i=1;i<dimVec;i++){
		if(vec[i].precioVenta<minPrecio){
			minPrecio=vec[i].precioVenta;
		}
		else
			if(vec[i].precioVenta>maxPrecio){
				maxPrecio=vec[i].precioVenta;
			}
	}
}

/*
Función SobreStock: Dado un vector con los datos de los productos  y su longitud,   
devolver otro vector con los productos  y su longitud,  
cuyo stock actual supere en 50 % al stock mínimo.
*/

void sobreStock(Productos vec[],int dimVec, Productos vecSobreStock[], int &dimVecSobreStock){
	
	int i;
	dimVecSobreStock=0;
	
	for(i=0;i<dimVec;i++){
		if(vec[i].stockActual>(vec[i].stockMinimo*1.5)){
			vecSobreStock[dimVecSobreStock]=vec[i];
			dimVecSobreStock++;
		}		
	}
}

/*
Función Imprimir: Dado un vector con los datos de los productos,y su longitud,  
mostrar por pantalla los datos de cada producto.
*/

void imprimir(Productos vec[],int dimVec){
	int i;
	cout<<"********************* PRODUCTOS *********************"<<endl;
	for (i=0;i<dimVec;i++){
		
		cout<<"******************************************************"<<endl;
		cout<<"Producto Código: "<<vec[i].codProducto<<endl;
		cout<<"Precio Compra: "<<vec[i].precioCompra<<endl;
		cout<<"Precio Venta: "<<vec[i].precioVenta<<endl;
		cout<<"Stock Inicial: "<<vec[i].stockInicial<<endl;
		cout<<"Stock Mínimo: "<<vec[i].stockMinimo<<endl;
		cout<<"Stock Actual: "<<vec[i].stockActual<<endl;
		cout<<"******************************************************"<<endl;
	}
}


/*
Función que realiza la carga en el vector de productos.
*/

void cargaDatosVectorProductos(Productos vec[],int &dimVec, int dimMaximaVector){
	
	int i,rpta;
	i=0;	
		
	cout<<"********************* INGRESO DATOS PRODUCTOS *********************************"<<endl;

	cout<<"Hay datos de productos para cargar? (1:SI / 0:NO) ";
	cin>>rpta;
	while (rpta!=1 && rpta!=0){
		cout<"Respuesta inválida. Hay datos para cargar? (1:SI / 0:NO)";
		cin>>rpta;
	} 
	
	while (rpta==1 && i<dimMaximaVector){
		cout<<"Producto Código: ";
		cin>>vec[i].codProducto;
		cout<<"Precio Compra: ";
		cin>>vec[i].precioCompra;
		cout<<"Precio Venta: ";
		cin>>vec[i].precioVenta;
		cout<<"Stock Inicial: ";
		cin>>vec[i].stockInicial;
		cout<<"Stock Mínimo: ";
		cin>>vec[i].stockMinimo;
		vec[i].stockActual=vec[i].stockInicial;
		cout<<"******************************************************"<<endl<<endl;	
		i++;
		
		if(i<dimMaximaVector){
			cout<<"Hay datos de productos para cargar? (1:SI / 0:NO) ";
			cin>>rpta;
			while (rpta!=1 && rpta!=0){
				cout<"Respuesta inválida. Hay datos para cargar? (1:SI / 0:NO) ";
				cin>>rpta;
			} 
		}
		else{
			cout<<"Ya no se puede seguir cargando porque superó la cantidad de productos permitidos para el ingreso. "<<endl;
		}
		
	}
	dimVec=i;
}	
	

void cargaDatosVentas(Productos vec[],int &dimVec){
	int i,rpta,cantVendida,codP;
	
		
		
	cout<<endl<<"********************* INGRESO DATOS VENTAS *********************************"<<endl;

	cout<<"Ingrese código de producto 0 para finalizar: ";
	cin>>codP;
	do{
		i=0;
		while (codP!=0 && i<dimVec && codP!=vec[i].codProducto){
			i++;
		}
		if(i==dimVec){
			cout<<"El codigo no existe";
			cout<<"*********Ingrese código de producto. 0 Para finalizar:  ";
			cin>>codP;
		}
		
		
	}while (i==dimVec && codP!=0);
	
	while (codP!=0){
	
		
		if (codP!=0){
			do{
				cout<<"Ingrese cantidad vendida: ";
				cin>>cantVendida;
				if (cantVendida<=0){
					cout<<"La cantidad debe ser mayor que 0 "<<endl;
				}		
				else
					if(cantVendida>vec[i].stockActual){
						cout<<"El stock actual es: "<< vec[i].stockActual <<" La cantidad vendida no puede superar el stock "<<endl;	
					}
			}while(cantVendida<=0 || cantVendida>vec[i].stockActual);		
			
			vec[i].stockActual=vec[i].stockActual-cantVendida;
		}
		cout<<"Ingrese código de producto 0 para finalizar: ";
		cin>>codP;
		do{
			i=0;
			while (codP!=0 && i<dimVec && codP!=vec[i].codProducto){
				i++;
			}
			if(i==dimVec){
				cout<<"El codigo no existe";
				cout<<"*********Ingrese código de producto. 0 Para finalizar:  ";
				cin>>codP;
			}
			
			
		}while (i==dimVec && codP!=0);
	}
}

int main (void){
	
	Productos vecProductos[DIM];
	Productos vecSobreStock[DIM];
	int dimV,contAlcanzanMinimo, dimVecSobreStock,i;
	double minPrecio, maxPrecio;
	contAlcanzanMinimo=0;

	//CARGAR VECTOR DE PRODUCTOS
	cargaDatosVectorProductos(vecProductos,dimV,DIM);
	
	
	imprimir(vecProductos,dimV);
	
	//CARGAR VENTAS
	cargaDatosVentas(vecProductos,dimV);
	
	
	
	//SALIDAS
	
	
	cout<<endl<<"********************* SALIDAS *********************************"<<endl;
	imprimir(vecProductos,dimV);
	
	cout<<"El margen de ganancia total sobre el stock actual al finalizar el mes $: "<<ganancia(vecProductos,dimV)<<endl;
		
	for(i=0;i<dimV;i++){
		if(pedir(vecProductos[i]))
			contAlcanzanMinimo++;		
	}
	
	cout<<"Cantidad de productos que alcanzan el stock mínimo actual al finalizar el mes: "<<contAlcanzanMinimo<<endl;

	maximoYMinimo(vecProductos,dimV, minPrecio, maxPrecio);
	cout<<"El menor precio de Venta: "<<minPrecio<<" El mayor precio de Venta: "<<maxPrecio<<endl;
	
	
	sobreStock(vecProductos,dimV, vecSobreStock,dimVecSobreStock);
	cout<<"Cantidad de productos cuyo stock actual supere en 50 % al stock mínimo actual al finalizar el mes: "<<dimVecSobreStock<<endl;

	imprimir(vecSobreStock,dimVecSobreStock);
	
	getch();
	return (0);

}
