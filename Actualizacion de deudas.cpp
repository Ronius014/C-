#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;


void tomadatos(float& deuda1,int& diadeuda1,int& mesdeuda1,int& aniodeuda1,int& diaact1,int& mesact1, char rubro[]){
			cout<<"----------------------------------------------------------------------------"<<endl;
			do{
				cout<<"Ingrese deuda de "<<rubro<<":"<<endl;
				cout<<"                 "<<endl;
				cin>>deuda1;
			}while(deuda1<0);
			cout<<"----------------------------------------------------------------------------"<<endl;
			do{
				cout<<"ingrese dia de la deuda"<<":"<<endl;
				cout<<"                 "<<endl;
				cin>>diadeuda1;
			}while(diadeuda1<=0||diadeuda1>30);
			cout<<"----------------------------------------------------------------------------"<<endl;
			do{
				cout<<"ingrese mes de la deuda"<<":"<<endl;
				cout<<"                 "<<endl;
				cin>>mesdeuda1;
			}while(mesdeuda1<=0 || mesdeuda1>12);
			cout<<"----------------------------------------------------------------------------"<<endl;
			do{
				cout<<"Ingrese el anio de la deuda"<<":"<<endl;
				cout<<"                 "<<endl;
				cin>>aniodeuda1;
			}while(aniodeuda1!=2018 && aniodeuda1!=2019);
			cout<<"----------------------------------------------------------------------------"<<endl;
			do{
				cout<<"Ingrese dia actual"<<":"<<endl;
				cout<<"                 "<<endl;
				cin>>diaact1;
			}while(diaact1<=0 || diaact1>30);
			cout<<"----------------------------------------------------------------------------"<<endl;
			do{
				cout<<"Ingrese mes actual"<<":"<<endl;
				cout<<"                 "<<endl;
				cin>>mesact1;
			}while(mesact1<=0 || mesact1>12);	
			cout<<"----------------------------------------------------------------------------"<<endl;
}

void calculardeuda(float deuda,int diadeuda,int mesdeuda,int aniodeuda,int diaact,int mesact, int anioact,float& total, float& interes3, float& interes4){
	int meses2018=0, dias2018=0,diasa3=0, diasa4=0;
	float tasainteres1=0.1, tasainteres2=0.15, cargainteres3=0, cargainteres4=0; //interes por dia//
	if(aniodeuda<2019){ //if que me separa si es una deuda del 2018 o del 2019//
		meses2018=12-mesdeuda;	
		dias2018=meses2018*30+(30-diadeuda);
		if(mesact<=3)
			diasa3=((mesact-1)*30)+(diaact)+(dias2018);
		else{
			diasa3=90+dias2018;
			diasa4=(((mesact-1)-3)*30)+(diaact);
		}
	}
	
	
	if(aniodeuda>2018){
		if(mesact<3){ // me separa si el mes act es mayor o menor a 3 //
			diasa3=(30-diadeuda)+(diaact)+(mesact-2)*30;
			cout<<"dias 3 "<<diasa3<<endl;
			cout<<"entre al if actual - +="<<endl;
		}
		else{ //si es mayor//
			if(mesdeuda==3){ //tengo que ver si el mes de la deuda es 3 o otra fecha
				if(30-diadeuda==0){ // si es 3 y estoy a fin de mes//
					diasa4=((mesact-4)*30+(diaact));
					cout<<"entre al if 3=0"<<endl;
				}
				else{
					diasa3=(30-diadeuda); // si es 3 y no estoy a fin de mes//
					diasa4=((mesact-4)*30)+diaact; //lo hago -4 porque serian 3 dias del mes que ya pasaron + el dia que esta transcurriendo= 4  meses)
					cout<<"entre al if 3==!0"<<endl;
				}
			}
			else{
				if(mesdeuda<3){ //si la deuda es menor o mayor a 3 //
					if(mesact<=3){ // si es menor tengo que ver si el mes que estoy actualizando es mayor o igual a 3 o menor o igual a 3 //
						diasa3=(mesact*30)-diadeuda-(30-diaact); //mesact*30 serian todos los dias hasta ese mes - los dias que ya habian pasado de la deuda - los dias que le faltan hasta terminar los dias en curso//
						cout<<"entre al if -3 y mes menor a 3"<<endl;
						}
					else{
						diasa3=((mesdeuda+1)*30)+(30-diadeuda); 
						diasa4=((mesact-3)*30)-(30-diaact);//mes actual menos los 3 meses que son a 3% me da los meses que son a 4%  pero le - los dias que no han transcurrido del mes en cuerso//
						cout<<"entre al if -3 y mes mayor a 3"<<endl;
					}
				}
				else{
					diasa4=(30-diadeuda)+(((mesact-mesdeuda)-1)*30)+diaact; //-1 mes en curso y al restarle el mes actual menos el mes transcurrido ya se quita el mes trancurrido//
					cout<<"entre al if +3"<<endl;
				}
			}
		   /* probable solucion poner un if else anidado para detectar si la fecha de deuda es
														mayor a 3 o menos a 3 */
		}
	}
	cargainteres3=diasa3*tasainteres1;
	cargainteres4=diasa4*tasainteres2;
	interes3=(deuda*cargainteres3)/100;
	interes4=(deuda*cargainteres4)/100;
	total=deuda+interes3+interes4;
	cout<<total<<endl;
	
}


main(){
	float deuda=0, total=0,interes3=0, interes4=0,totalmostrar[5],interesa3[5],interesa4[5], totaldeuda=0;
	int diadeuda=0,mesdeuda=0,aniodeuda=0,diaact=0,mesact=0,anioact=0, opcionprincipal, bandera,i;
	char rubro[30];
	char nombrerubro[6][31]={"Obra Social", "Fondo de Convenio", "Seguro de Vida", "Cuota Sindical", "Contribuciones extraordinarias", "Asistencia Sindical" };
	anioact=2019;
	do{
	cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<"                       Estudio Juridico Ortega del Campillo                 "<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<" "<<endl;
	cout<<"1- Para calcular Rubros"<<endl;
	cout<<" "<<endl;
	cout<<"2- Para mostrar total, rubros actualozados y sus interes"<<endl;
	cout<<" "<<endl;
	cout<<"3- Salir..."<<endl;
	cout<<" "<<endl;
	cin>>opcionprincipal;
	cout<<"----------------------------------------------------------------------------"<<endl;
	switch(opcionprincipal){
		case 1:
			//--------------------------------------------------------------------------//
			strcpy (rubro,"Obra Social");
			tomadatos(deuda,diadeuda, mesdeuda,aniodeuda, diaact, mesact, rubro);
			calculardeuda(deuda,diadeuda,mesdeuda,aniodeuda,diaact,mesact,anioact,total,interes3,interes4);
			totalmostrar[0]=total;
			interesa3[0]=interes3;
			interesa4[0]=interes4;
			//--------------------------------------------------------------------------//
			strcpy (rubro,"Fondo de Convenio");
			tomadatos(deuda,diadeuda, mesdeuda,aniodeuda, diaact, mesact, rubro);
			calculardeuda(deuda,diadeuda,mesdeuda,aniodeuda,diaact,mesact,anioact,total,interes3,interes4);
			totalmostrar[1]=total;
			interesa3[1]=interes3;
			interesa4[1]=interes4;
			//---------------------------------------------------------------------------//
			strcpy (rubro,"Seguro de Vida");
			tomadatos(deuda,diadeuda, mesdeuda,aniodeuda, diaact, mesact, rubro);
			calculardeuda(deuda,diadeuda,mesdeuda,aniodeuda,diaact,mesact,anioact,total,interes3,interes4);
			totalmostrar[2]=total;
			interesa3[2]=interes3;
			interesa4[2]=interes4;
			//---------------------------------------------------------------------------//
			strcpy (rubro,"Cuota Sindical");
			tomadatos(deuda,diadeuda, mesdeuda,aniodeuda, diaact, mesact, rubro);
			calculardeuda(deuda,diadeuda,mesdeuda,aniodeuda,diaact,mesact,anioact,total,interes3,interes4);
			totalmostrar[3]=total;
			interesa3[3]=interes3;
			interesa4[3]=interes4;
			//---------------------------------------------------------------------------//
			strcpy (rubro,"Contribuciones extraordinarias");
			tomadatos(deuda,diadeuda, mesdeuda,aniodeuda, diaact, mesact, rubro);
			calculardeuda(deuda,diadeuda,mesdeuda,aniodeuda,diaact,mesact,anioact,total,interes3,interes4);
			totalmostrar[4]=total;
			interesa3[4]=interes3;
			interesa4[4]=interes4;
			//---------------------------------------------------------------------------//
			strcpy (rubro,"Asistencia Sindical");
			tomadatos(deuda,diadeuda, mesdeuda,aniodeuda, diaact, mesact, rubro);
			calculardeuda(deuda,diadeuda,mesdeuda,aniodeuda,diaact,mesact,anioact,total,interes3,interes4);
			totalmostrar[5]=total;
			interesa3[5]=interes3;
			interesa4[5]=interes4;
			//---------------------------------------------------------------------------//
			bandera=1;
			break;
		case 2:
		
			if(bandera==1){
				for(i=0;i<=5;i++){
					totaldeuda=totaldeuda+totalmostrar[i];
				}
				
				cout<<"----------------------------------------------------------------------------"<<endl;
				for(i=0;i<=5;i++){
					cout<<"Total Nombre del rubro: "<<nombrerubro[i]<<" "<<totalmostrar[i]<<endl;
					cout<<"Intereses a 3% "<<interesa3[i]<<endl;
					cout<<"Intereses a 4,5% "<<interesa4[i]<<endl;
					cout<<"----------------------------------------------------------------------------"<<endl;
				}
				cout<<"----------------------------------------------------------------------------"<<endl;
				cout<<"El total de la deuda es: "<<"   "<<totaldeuda<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
				}
			else{
				cout<<"----------------------------------------------------------------------------"<<endl;
				cout<<"Primero debe cargar los rubros."<<endl;
				cout<<"----------------------------------------------------------------------------"<<endl;
			}
			break;
		case 3:
			break;
		default:
			cout<<"----------------------------------------------------------------------------"<<endl;
			cout<<"Ingrese una opcion valida"<<endl;
			cout<<"----------------------------------------------------------------------------"<<endl;
			break;
	}
}while (opcionprincipal!=3);	
}


