#include <iostream>
#include <stdio.h>
#include <conio.h>
#define DIM 3

using namespace std;

struct Cuentas{
	int nroCuenta;
	double montoLimiteExt;
	double saldoInicial;
	double saldoActual;
	int clave;
	int extracciones;
};

double promedio (Cuentas vecCuentas[], int dimVec){
	
	double promedioSaldo;
	double sumaSaldo;
	int i;
	
	for (i=0; i<dimVec; i++){
		sumaSaldo+=vecCuentas[i].saldoActual;
	}
	
	promedioSaldo=(sumaSaldo/double(dimVec));
	
	return (promedioSaldo);
	
}

void imprimir (Cuentas vecCuentas[], int dimVec){
	int i;
	cout<<"********************* CUENTAS *********************"<<endl;
	for (i=0;i<dimVec;i++){
		
		cout<<"******************************************************"<<endl;
		cout<<"Numero de cuenta: "<<vecCuentas[i].nroCuenta<<endl;
		cout<<"Monto limite diario para extracciones: "<<vecCuentas[i].montoLimiteExt<<endl;
		cout<<"Saldo Inicial: "<<vecCuentas[i].saldoInicial<<endl;
		cout<<"Saldo Actual: "<<vecCuentas[i].saldoActual<<endl;
		cout<<"Clave: "<<vecCuentas[i].clave<<endl;
		cout<<"Cantidad de extracciones hechas: "<<vecCuentas[i].extracciones<<endl;
		cout<<"******************************************************"<<endl;
	}
}


bool validarClave (int clave, int nroCuenta, Cuentas vecCuentas[], int dimVec){
	
	int nroCuentaAux, claveAux, i;
	
	for (i=0; i<dimVec; i++){
		if ((vecCuentas[i].nroCuenta==nroCuentaAux) && (vecCuentas[i].clave==claveAux)){
			return (true);
		}
		else{
			return (false);
		}
	}
}

void cantidadCuentas (Cuentas vecCuentas[], int dimVec, int &contAcreedor, int &contDeudor, int &contNulo){
	
	int i;

	for(i=0; i<dimVec; i++){
		if((vecCuentas[i].saldoActual - vecCuentas[i].saldoInicial)>0){
		contDeudor++;
	}
	else{
		if((vecCuentas[i].saldoActual - vecCuentas[i].saldoInicial)<0){
			contAcreedor++;
		}
		else{
			contNulo++;
			}
		}	
	}	
}

bool extraccionesLimites (Cuentas unaCuenta){
	
	return(unaCuenta.extracciones==3);
	
}

void cargaDatosVectorCuentas(Cuentas vecCuentas[], int &dimVec, int dimMaximaVector){
	
	int i, rpta, clave;
	i=0;	
		
	cout<<"********************* INGRESO DATOS CUENTAS *********************************"<<endl;

	cout<<"Hay cuentas para cargar? (1:SI / 0:NO) "<<endl;
	cin>>rpta;
	while (rpta!=1 && rpta!=0){
		cout<<"Respuesta inválida. Hay cuentas para cargar? (1:SI / 0:NO)"<<endl;
		cin>>rpta;
	} 
	
	while (rpta==1 && i<dimMaximaVector){
		cout<<"Numero de cuenta: "<<endl;
		cin>>vecCuentas[i].nroCuenta;
		cout<<"Monto limite diario para extracciones: "<<endl;
		cin>>vecCuentas[i].montoLimiteExt;
		cout<<"Saldo Inicial: "<<endl;
		cin>>vecCuentas[i].saldoInicial;
		cout<<"Saldo Actual: "<<endl;
		cin>>vecCuentas[i].saldoActual;
		
		cout<<"Clave (hasta 4 digitos): ";
		cin>>clave;
		while (clave>9999){
			cout<<"La clave ingresada tiene mas de 4 digitos. Intentelo nuevamente..."<<endl;
			cin>>clave;
		}
		vecCuentas[i].clave=clave;
		vecCuentas[i].saldoActual=vecCuentas[i].saldoInicial;
		cout<<"******************************************************"<<endl<<endl;	
		i++;
		
		if(i<dimMaximaVector){
			cout<<"Hay mas cuentas para cargar? (1:SI / 0:NO) ";
			cin>>rpta;
			while (rpta!=1 && rpta!=0){
				cout<"Respuesta inválida. Hay cuentas para cargar? (1:SI / 0:NO) ";
				cin>>rpta;
			} 
		}
		else{
			cout<<"Ya no se puede seguir cargando porque superó la cantidad de cuentas permitidas para el ingreso. "<<endl;
		}
		
	}
	dimVec=i;
}	

void cargaDatosCuentas(Cuentas vecCuentas[], int &dimVec){
	
	int i, rpta, cantVendida, nroCuenta, clave;
	int intentos=0;
	int contExtracciones=0;
	char tipoMovimiento[1];
	double monto;
		
	cout<<"********************* INGRESO DATOS CUENTAS *********************************"<<endl;

	cout<<"Ingrese numero de cuenta (0 para finalizar): "<<endl;
	cin>>nroCuenta;
	do{ 
		i=0;
		while (nroCuenta!=0 && i<dimVec && nroCuenta!=vecCuentas[i].nroCuenta){
			i++;
		}
		if(i==dimVec){
			cout<<"El numero de cuenta no existe"<<endl;
			cout<<"*********Ingrese numero de cuenta (0 Para finalizar): "<<endl;
			cin>>nroCuenta;	
		}
	}while (i==dimVec && nroCuenta!=0);	
		
	cout<<"Ingrese la clave: "<<endl;
	cin>>clave;
	
	if(validarClave(clave, nroCuenta, vecCuentas, dimVec)){
		
		cout<<"Ingrese el tipo de movimiento (E: extraccion - D: deposito - C: consulta de saldos): "<<endl;
		cin>>tipoMovimiento;
				
			while ((tipoMovimiento!="E") && (tipoMovimiento!="D") && (tipoMovimiento!="C")){
					cout<<"El tipo de movimiento ingresado no existe. Intentelo nuevamente..."<<endl;
					cin>>tipoMovimiento;
				}
				
				if ((tipoMovimiento=="E") || (tipoMovimiento=="D")){
					cout<<"Ingrese el monto: "<<endl;
					cin>>monto;
				}	
				else{
					cout<<"Su saldo es de: $"<<vecCuentas[i].saldoActual<<endl;
				}				
				if (tipoMovimiento=="E"){
					contExtracciones++;
				}		
				vecCuentas[i].extracciones=contExtracciones;	
				if (contExtracciones>3){
					cout<<"No se pueden realizar mas de 3 extracciones por dia."<<endl;
				}		
				if (monto>vecCuentas[i].montoLimiteExt){
					cout<<"El monto solicitado es mayor al monto limite diario de extracciones de su cuenta."<<endl;
					cin>>monto;
				}
			}
			else{
				cout<<"La clave ingresada no es correcta. Vuelva a intentarlo..."<<endl;
				cin>>clave;
				intentos++;
				if (intentos>3){
					cout<<"Supero los 3 intentos erroneos, vuelva a intentarlo dentro de 24 hs."<<endl;
					}
			}
					
		cout<<"Ingrese numero de cuenta (0 para finalizar): "<<endl;
		cin>>nroCuenta;
			do{
			i=0;
			while (nroCuenta!=0 && i<dimVec && nroCuenta!=vecCuentas[i].nroCuenta){
				i++;
			}
			if(i==dimVec){
				cout<<"El numero de cuenta no existe"<<endl;;
				cout<<"*********Ingrese numero de cuenta (0 Para finalizar):  ";
				cin>>nroCuenta;
			}
			
		}while (i==dimVec && nroCuenta!=0);
}
			
int main (void){
	
	Cuentas vecCuentas[DIM];
	int dimV, i, contAcreedor, contDeudor, contNulo;
	int contAlcanzanExtracciones=0;
	
	//Cargar vector de cuentas
	cargaDatosVectorCuentas(vecCuentas, dimV, DIM);
	
	imprimir(vecCuentas, dimV);
	
	//Cargar datos de cuentas
	cargaDatosCuentas(vecCuentas, dimV);
	
	
	// SALIDAS 
	
	cout<<endl<<"********************* SALIDAS *********************************"<<endl;
	//1
	
	
	//2
	imprimir(vecCuentas,dimV);
	
	
	//3
	cout<<"El promedio de todos los saldos actuales es de: "<<promedio(vecCuentas, dimV)<<endl;
	
	//4 
	cantidadCuentas(vecCuentas, dimV, contAcreedor, contDeudor, contAcreedor);
	cout<<"La cantidad de cuentas con saldo acreedor fue de: "<<contAcreedor<<endl;;
	cout<<"La cantidad de cuentas con saldo deudor fue de: "<<contDeudor<<endl;;
	cout<<"La cantidad de cuentas con saldo nulo fue de: "<<contNulo<<endl;
	
	//5
	for(i=0;i<dimV;i++){
		if(extraccionesLimites(vecCuentas[i])){
			contAlcanzanExtracciones++;
		}			
	}
	
	cout<<"La cantidad de cuentas que alcanzan las 3 extracciones son: "<<contAlcanzanExtracciones<<endl;
	
	getch();
	return(0);
	
	
}	
