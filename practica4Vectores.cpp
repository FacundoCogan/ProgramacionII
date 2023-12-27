#include <iostream>


using namespace std;

int main(){
	
	int cantVacas,i,id,raza,respuesta,auxCod,maxId,minId,auxProd;
	double litros,totalLitros,maxLitros,minLitros;
	
	totalLitros=0;
	
	cout << "ingrese la cantidad de vacas que dispone "<<endl;
	cin >> cantVacas;
	
	int vecId[cantVacas],vecRaza[cantVacas],vecIdProd[cantVacas];
	double vecLitrosProm[cantVacas],vecLitrosObt[cantVacas];
	
	for(i=0;i<cantVacas;i++){
		vecIdProd[i]=0;
	}
	

	for(i=0;i<cantVacas;i++){
		
		cout << "ingrese el id de la vaca: "<< i+1 <<"  (no par) "<<endl;
		cin >> id;
			
	while (id%2==0){
		
		cout << "el valor ingresado es invalido por favor reingrese"<<endl;
		cin >> id;
		
	}
	
	vecId[i]=id;
	
		
	cout << "ingrese la raza de la vaca " << i+1 << endl;	
	cin >> raza;
		
	while ( raza !=10 && raza != 20 && raza != 30 && raza != 40){
		
		cout << "el valor ingresado es invalido reingrese (10-20-30-40)"<<endl;
		cin >> raza;
		
	}	
		
	vecRaza[i]=raza;	
		
	cout << "ingrese la cantidad de litros promedio mensuales de la " << i+1 << " vaca" <<endl;
	cin >> vecLitrosProm[i];		
		
	}
	
	
	cout << "hay datos para ingresar (1-si/0-no)"<<endl;
	cin >> respuesta;
	//validar
	while(respuesta == 1){
			
		cout << "ingrese el id de produccion"<<endl;	
		cin >> auxProd;
			
			
			
		do{
			cout << "ingrese el id de la vaca"<<endl;	
			cin >> id;
		
			i=0;
				
			while((i<cantVacas)&&(id!=vecId[i])){
				i++;
			}
			if(i==cantVacas)
				cout << "el id ingresado no corresponde a ningun id, reingrese"<<endl;

		
		}while(i==cantVacas);
			
		vecIdProd[i]++;
		
		cout << "ingrese la cantidad de litros de leches obtenidos  " << endl;
		cin >>  litros;
		
		while(litros <= 0){
			
			cout << "la cantidad de litros de leche es invalido, reingrese"<<endl;
			cin >> litros;
			
		}
		
		vecLitrosObt[i]+=litros;
	
		cout << "hay datos para ingresar (1-si/0-no)"<<endl;
	cin >> respuesta;
	
	
	
	
		
	}
	cout<<endl<<endl;
	cout<<"********************************"<<endl;
	cout<<endl<<endl;
	cout << "la cantidad total de vacas es igual a: " <<cantVacas<<endl;
	
	
	for(i=0;i<cantVacas;i++){
		
		cout << " la vaca " << vecId[i]<<" produjo " << vecLitrosObt[i]<<" litros"<<endl;
		totalLitros+=vecLitrosObt[i];
		
	}
	
	maxLitros=vecLitrosObt[0];
	maxId=0;
	minLitros=vecLitrosObt[0];
	minId=0;
	for(i=1;i<cantVacas;i++){
		
		if(maxLitros<vecLitrosObt[i]){
			maxLitros=vecLitrosObt[i];
			maxId=i;
		}else
			if(minLitros>vecLitrosObt[i]){
				minLitros=vecLitrosObt[i];
				minId=i;
			}
		
	}
	cout<<endl<<endl;
	
	cout << "la cantidad de litros obtenidos entre todas las vacas es de: " << totalLitros<<" litros "<<endl;
	
	cout << "la vaca que mas leche dio es la vaca " << vecId[maxId] << " con un total de " << maxLitros<< " litros"<<endl;
	
	cout << "la vaca que menos leche dio es la vaca " << vecId[minId] << " con un total de " << minLitros<< " litros"<<endl;
	
	
	for(i=0;i<cantVacas;i++){
		cout << "la vaca "<<vecId[i]<< " produjo " << vecIdProd[i] << " veces"<<endl;
	}
	
	for(i=0;i<cantVacas;i++){
	
		if(vecLitrosProm[i]<vecLitrosObt[i]){
			cout << "la vaca " << vecId[i] << " supero su promedio"<<endl;
		}	
	
	}
	
		
	return 0;
}
