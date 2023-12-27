#include <iostream>
#include <stdio.h>
#include <conio.h>
#define DIM 1

using namespace std;

struct Cuentas{
	int nroCuenta;
	double montoLimiteExt;
	double saldoInicial;
	double saldoActual;
	int clave;
	int extracciones;
};

double promedio (Cuentas [], int );
void imprimir (Cuentas [], int );
int buscoCta(Cuentas [], int , int );
bool validarClave (int , int , Cuentas [], int );
void cantidadCuentas (Cuentas[], int , int&, int&, int&);
bool extraccionesLimites (Cuentas);
void cargaDatosVectorCuentas(Cuentas[], int&, int );
void cargaDatosCuentas(Cuentas[], int&);
			
int main (void){
	
	Cuentas vecCuentas[DIM];
	int dimV, i, contAcreedor, contDeudor, contNulo;
	int contAlcanzanExtracciones=0;
	
	//Cargar vector de cuentas
	cargaDatosVectorCuentas(vecCuentas, dimV, DIM);
	
	imprimir(vecCuentas, dimV);
	
	//Cargar datos de los movimientos de las cuentas
	cargaDatosCuentas(vecCuentas, dimV);
	
	
	// SALIDAS 
	
	cout<<endl<<"********************* SALIDAS *********************************"<<endl;
	//1 - realizado dentro de la función de carga de movimientos
	
	
	//2
	imprimir(vecCuentas,dimV);
	
	/*
	//este sería si paso una a una las cuentas en lugar de todo el vector entero
	for (int i=0; i<dimV; i++)
	{
		imprimirCta(vecCuentas[i]);
	}
	*/
	
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
	
	
} //cierra main

double promedio (Cuentas vecCuentas[], int dimVec){
	
	double sumaSaldo;
	int i;
	
	for (i=0; i<dimVec; i++){
		sumaSaldo+=vecCuentas[i].saldoActual;
	}
	
	return (sumaSaldo/dimVec);
	
}



void imprimirCta(Cuentas unaCta)
{
		cout<<"******************************************************"<<endl;
		cout<<"Numero de cuenta: "<<unaCta.nroCuenta<<endl;
		cout<<"Monto limite diario para extracciones: "<<unaCta.montoLimiteExt<<endl;
		cout<<"Saldo Inicial: "<<unaCta.saldoInicial<<endl;
		cout<<"Saldo Actual: "<<unaCta.saldoActual<<endl;
		cout<<"Clave: "<<unaCta.clave<<endl;
		cout<<"Cantidad de extracciones hechas: "<<unaCta.extracciones<<endl;
		cout<<"******************************************************"<<endl;
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

int buscoCta(Cuentas vC[], int dim, int nCuenta){
	int i=0;
	
	while ((i<dim) && (vC[i].nroCuenta != nCuenta))
	    i++;
	    
	if (i == dim)
	return (-1);
	else return (i);
	
}

bool validarClave (int clave, int nroCuenta, Cuentas vecCuentas[], int dimVec){
	
	int  i;
	
	//busco el nro de cuenta
	i = buscoCta(vecCuentas, dimVec,nroCuenta);
	cout<<endl<<"ESTOY EN LA FUNCION VALIDAR CLAVE. I VALE: "<<i<<endl;
    //veo si coincide la clave o si no está la cuenta 
	if (i != -1)
	        {//significa que encontré la cuenta
	        cout<<endl<<"ENCONTRE LA CUENTA"<<endl;
               if (clave == vecCuentas[i].clave)
			                return (true);
					else
					        return (false);		        
			}
	   else
	       return (false);
	       
}

void cantidadCuentas (Cuentas vecCuentas[], int dimVec, int &contAcreedor, int &contDeudor, int &contNulo){
	
	int i;

	for(i=0; i<dimVec; i++){
		if((vecCuentas[i].saldoActual)<0){
		contDeudor++;
	}
	else{
		if((vecCuentas[i].saldoActual)>0){
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
	//carga inicial de los valores de cada cuenta
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
		vecCuentas[i].extracciones=0;
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
	
	int i, rpta, nroCuenta, clave;
	int intentos=0;
	
	char tipoMovimiento;
	double monto;
	bool exito=false;
		
	cout<<"********************* INGRESO DATOS CUENTAS *********************************"<<endl;

	cout<<"Ingrese numero de cuenta (0 para finalizar): "<<endl;
	cin>>nroCuenta;
	
	while (nroCuenta != 0)
	{
	        //ver que la cuenta existe 
			do{ 
				i=buscoCta(vecCuentas, dimVec, nroCuenta);
				if (i == -1){
					cout<<"El numero de cuenta no existe"<<endl;
					cout<<"*********Ingrese numero de cuenta (0 Para finalizar): "<<endl;
					cin>>nroCuenta;	
				}
			}while (i==-1 && nroCuenta !=0);
				
			if (nroCuenta != 0 && i != -1)
			{
					//si llego a esta línea significa que existe la cuenta y voy a verificar si la clave es correcta.
				do{				
					cout<<"Ingrese la clave: "<<endl;
					cin>>clave;
					
					if(validarClave(clave, nroCuenta, vecCuentas, dimVec)){
						//significa clave correcta para la cuenta ingresada
						cout<<"Ingrese el tipo de movimiento (E: extraccion - D: deposito - C: consulta de saldos): "<<endl;
						cin>>tipoMovimiento;
						
						//valida el tipo de moviento ingresado		
						while ((tipoMovimiento!='E') && (tipoMovimiento!='D') && (tipoMovimiento!='C'))
						    {
									cout<<"El tipo de movimiento ingresado no existe. Intentelo nuevamente..."<<endl;
									cin>>tipoMovimiento;
						    }//cierra mientras de validación de tipo de movimiento
						
						if (tipoMovimiento == 'C')
							{
                                  cout<<"Su saldo es de: $"<<vecCuentas[i].saldoActual<<endl;
                                  exito=true;
							}
						 else
						    {
						      cout<<"Ingrese el monto: "<<endl;
							  cin>>monto;
							  if (tipoMovimiento=='E')
							      {
								    if (vecCuentas[i].extracciones <3){
						        
								         vecCuentas[i].extracciones++;
							         	 while (monto>vecCuentas[i].montoLimiteExt){
													cout<<"El monto solicitado es mayor al monto limite diario de extracciones de su cuenta. Límite permitido: "<<vecCuentas[i].montoLimiteExt<<endl;
													cout<<"Ingrese nuevamente el monto a extraer: "<<endl;
													cin>>monto;
								                }   	 
								         vecCuentas[i].saldoActual -= monto;
										 exito=true;    
										 cout<<"Extracción realizada con éxito, su saldo actual es: "<<  vecCuentas[i].saldoActual<<endl; 
								      }	 
								    else
								  		cout<<"No se pueden realizar mas de 3 extracciones por dia."<<endl;
							      }
                               else //hago lo que corressponde si el movimiento es depósito							      
							       {
								      vecCuentas[i].saldoActual += monto; 
									  exito=true;     
							          cout<<"Depósito realizado con éxito, su saldo actual es: "<<  vecCuentas[i].saldoActual<<endl;
								   }
							       
							} //cierra el else de movimiento depósito o extracción
						
						
						 }//cierra el verdadero del if (validarClave(clave, nroCuenta, vecCuentas, dimVec))
						
						else{
								cout<<"La clave ingresada no es correcta. Vuelva a intentarlo..."<<endl;
								cin>>clave;
								intentos++;
								if (intentos>3){
									cout<<"Supero los 3 intentos erroneos, vuelva a intentarlo dentro de 24 hs."<<endl;
									}
							} //cierra el falso del if (validarClave(clave, nroCuenta, vecCuentas, dimVec))
							
					}while(intentos<3 && exito==false && vecCuentas[i].extracciones<3 );
			   }//cierra el if en caso que la cuenta existe y no indicó fin de ingreso de datos
			   
				cout<<"Ingrese numero de cuenta (0 para finalizar): "<<endl;
				cin>>nroCuenta;
				exito=false;
		}//cierra while de nroCuenta igual a cero para fin de ingreso de datos
}
				

	


