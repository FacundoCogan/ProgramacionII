#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main(void)
{
	int i, nroCliente, tipoCliente, abonoServicioInternet, abonoServicioTv, antiguedad, tarifaBase, valAbonoInternet, minCod, maxCod, maxCodCom, cont0, cont1, cont2, cont3, mayorCantClientes, contFamiliar, contJubilado, contComercial; 
	double minLlamLocLib, minLlamIntLib, minLlamExtLib, minLlamLocRea, minLlamIntRea, minLlamExtRea, pagoExcedenteLoc, pagoExcedenteInt, pagoExcedenteExt, valorFinal, descuento5pc, descuento7pc, descuentoAnt, minTotales, maxMin, minMin, maxImpCom, sum;
	bool flag, flagCom;
	string masClientes;
	
	flag=true;
	flagCom=true;
	cont0=0;
	cont1=0;
	cont2=0;
	cont3=0;
	contFamiliar=0;
	contJubilado=0;
	contComercial=0;
	sum=0;
	
	cout<<"Ingrese numero del cliente (para no ingresar mas datos, ingrese 0)"<<endl;
	cin>>nroCliente;
	
	// Ingreso de datos
	
	while (nroCliente!=0){
		cout<<"Ingrese los minutos de llamadas locales libres"<<endl;
		cin>>minLlamLocLib;
		
		cout<<"Ingrese los minutos de llamadas del interior libres"<<endl;
		cin>>minLlamIntLib;
		
		cout<<"Ingrese los minutos de llamadas del exterior libres"<<endl;
		cin>>minLlamExtLib;
		
		cout<<"Ingrese los minutos de llamadas locales realizadas"<<endl;
		cin>>minLlamLocRea;
		
		cout<<"Ingrese los minutos de llamadas del interior realizadas"<<endl;
		cin>>minLlamIntRea;
		
		cout<<"Ingrese los minutos de llamadas del exterior realizadas"<<endl;
		cin>>minLlamExtRea;
		
		cout<<"Ingrese el tipo de cliente (10: FAMILIAR - 15: JUBILADO - 20: COMERCIAL)"<<endl;
		cin>>tipoCliente;
		
		// Validacion del tipo cliente
		
		while (tipoCliente !=10 && tipoCliente !=15 && tipoCliente !=20){
			cout<<"El tipo de cliente ingresado no es valido. Ingreselo nuevamente"<<endl;
			cin>>tipoCliente;
		}
		
		if (tipoCliente=10)
			contFamiliar=contFamiliar+1;
		else
			if (tipoCliente=15)
				contJubilado=contJubilado+1;
			else
				contComercial=contComercial+1;	
		
		
		cout<<"Ingrese el abono servicio de internet (0: NO POSEE - 1: 50 MEGAS - 2: 100 MEGAS - 3: 300 MEGAS)"<<endl;
		cin>>abonoServicioInternet;
		
		// Validacion del abono de servicio de internet
		
		while (abonoServicioInternet !=0 && abonoServicioInternet !=1 && abonoServicioInternet !=2 && abonoServicioInternet !=3){
			cout<<"El abono de servicio internet ingresado no es valido. Ingreselo nuevamente"<<endl; 
			cin>>abonoServicioInternet;
		}
		
		cout<<"Ingrese el abono servicio de television por cable (0: NO POSEE - 5: PACK COMUN - 7: PACK ESPECIAL)"<<endl;
		cin>>abonoServicioTv;
		
		// Validacion del abono de servicio de tv
		
		while (abonoServicioTv != 0 && abonoServicioTv != 5 && abonoServicioTv != 7){
			cout<<"El abono de servicio por tv ingresado no es valido. Ingreselo nuevamente"<<endl;
			cin>>abonoServicioTv;
		}
	
		cout<<"Ingrese la antiguedad de años"<<endl;
		cin>>antiguedad;
	
	
		
		switch (tipoCliente)
		{
			case (10): tarifaBase=2500; break;
			case (15): tarifaBase=1000; break;
			case (20): tarifaBase=5000; break;
		}
	
		// Excedentes locales
		
			
		if (minLlamLocRea > minLlamLocLib)
			pagoExcedenteLoc = (minLlamLocRea - minLlamLocLib)*5;
		else
			pagoExcedenteLoc = 0;
					
			
		// Excedentes interior
		
		if (minLlamIntRea > minLlamIntLib)
			pagoExcedenteInt = (minLlamIntRea - minLlamIntLib)*10.5;
		else
			pagoExcedenteInt = 0;
		
		// Excedentes exterior
		
		if (minLlamExtRea > minLlamExtLib)
			pagoExcedenteExt = (minLlamExtRea - minLlamExtLib)*20;
		else
			pagoExcedenteExt = 0;
			
			
		switch (abonoServicioInternet)
		{
			case (1): valAbonoInternet=100; break;
			case (2): valAbonoInternet=1300; break;
			case (3): valAbonoInternet=1700; break;
		}
		
		// Valor final
		
		valorFinal=(tarifaBase + pagoExcedenteLoc + pagoExcedenteInt + pagoExcedenteExt + valAbonoInternet);
		
		// Descuento 5%
		
		if (tipoCliente == 15 && pagoExcedenteLoc == 0 && pagoExcedenteInt == 0 && pagoExcedenteExt == 0)
			descuento5pc = (valorFinal*5/100);
		else
			descuento5pc = 0;
			
		// Descuento 7%
		
		if (abonoServicioTv !=0 && abonoServicioInternet !=0)
			descuento7pc = (valorFinal*7/100);
		else
			descuento7pc = 0;
			
		
		// Descuento antiguedad
		
		if (antiguedad > 15) 
			descuentoAnt=(valorFinal*((antiguedad - 15 )*0.5))/100;
		 else 
			descuentoAnt = 0;
			
		// Valor final menos descuentos
		
		valorFinal=(valorFinal - descuento5pc - descuento7pc - descuentoAnt);
		
		// Maximo y minimo de minutos totales
		
		minTotales=(minLlamLocRea + minLlamIntRea + minLlamExtRea);
		
		if (flag=true) 
		{
			minMin=minTotales;
			maxMin=minTotales;
			maxCod=nroCliente;
			minCod=nroCliente;
			flag=false;
		}
		else
			if (minTotales<minMin)
			{
				minMin=minTotales;
				minCod=nroCliente;
			}
			else
				if (minTotales>maxMin)
				{
					maxMin=minTotales;
					maxCod=nroCliente;
				}
		
		if (tipoCliente=20 && flagCom)
		{
			maxImpCom=valorFinal;	
			maxCodCom=nroCliente;
			flagCom=false;
		}
		else
			if (valorFinal>maxImpCom)
			{
				maxImpCom=valorFinal;
				maxCodCom=nroCliente;
			}
		
		if (abonoServicioInternet=0)
			cont0=cont0+1;
		else
			if (abonoServicioInternet=1)
				cont1=cont1+1;
			else
				if (abonoServicioInternet=2)
					cont2=cont2+1;
				else
					cont3=cont3+1;		
		
		masClientes="Familiar";
		mayorCantClientes=contFamiliar;
		
		if (contJubilado>mayorCantClientes)
		{
			masClientes="Jubilado";
			mayorCantClientes=contJubilado;
		}
		
		if (contComercial>mayorCantClientes)
		{
			masClientes="Comercial";
			mayorCantClientes=contComercial;
		}
		
		sum=sum+valorFinal;
		
		
		cout<<"Ingrese el numero de cliente (para no ingresar mas datos, ingrese 0)"<<endl;
		cin>>nroCliente;
		
		cout<<"--------------"<<endl;
		cout<<"Datos del cliente: "<<endl;
		cout<<"El codigo del cliente es: "<<nroCliente<<" y el importe total es de: $"<<valorFinal<<endl;
		cout<<"--------------"<<endl;	
	}
	
	cout<<"El cliente que registra menor cantidad de minutos totales entre todas sus llamadas, tiene el numero "<<minCod<<" con un total de "<<minMin<<" minutos totales"<<endl;
	cout<<"El cliente que registra mayor cantidad de minutos totales entre todas sus llamadas, tiene el numero "<<maxCod<<" con un total de "<<maxMin<<" minutos totales"<<endl;		
	cout<<"El cliente del tipo comercial que registra mayor importe a abonar esta registrado con el numero "<<maxCodCom<<" con un total de $"<<maxImpCom<<endl;		
	cout<<"La cantidad de gente que no posee abono servicio de internet es: "<<cont0<<endl;
	cout<<"La cantidad de gente que posee 50 megas es de: "<<cont1<<endl;
	cout<<"La cantidad de gente que posee 100 megas es de: "<<cont2<<endl;	
	cout<<"La cantidad de gente que posee 300 megas es de: "<<cont3<<endl;
	cout<<"El tipo de cliente del cual se registra mayor cantidad es el de: "<<masClientes<<" con un total de "<<mayorCantClientes<<" clientes"<<endl;
	cout<<"El monto total facturado entre todos los clientes es de $"<<sum<<endl;
			
			
			
			
			
			
			
			
			
	getch ();
			
	return(0);
			
			
}


