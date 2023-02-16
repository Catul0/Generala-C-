#include <conio.h>
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
using namespace std;
void DadosHumano(int&, int&, int&, int&, int&);
void DadosJarvis(int&, int&, int&, int&, int&);
int Escalera(int d1, int d2, int d3, int d4, int d5,int contadorEs[]);
int Generala(int da1, int da2, int da3, int da4, int da5,int contadorGen[]);
int Poker (int dd1, int dd2, int dd3, int dd4, int dd5,int contadorPoker[]);
int Full (int dda1, int dda2, int dda3, int dda4, int dda5,int contadorFul[]);
int ValNumH (int daa1, int daa2, int daa3, int daa4, int daa5,int contadorVN[] );
int ValNumJ (int daad1, int daad2, int daad3, int daad4, int daad5,int contadorV[] );
void VolverATirar(int& ,int& , int& , int& , int&);
void lectura();
int main(int argc, char *argv[]) {
	int dado1,dado2,dado3,dado4,dado5;  //dados humano
	int dad1,dad2,dad3,dad4,dad5;		//dados de la maquina 
	int auxh=0,auxm=0; //variables para arrojar dados para ver que inicia...
	int comenzar=0;		//variable auxiliar para iniciar el juego..
	int volver_tirar; //variable para preguntar si quiere volver a tirar algun dado..
	int puntos_hum=0,puntos_jarvis=0;  //variables para llevar puntaje
	int Repite_O_No=0; // variable para controlar si es un juego servido o armado
	int escalera=0,generala=0,poker=0,full=0,valnumh=0,valnum=0; //variables donde se guarda lo que devuelven las funciones
	int contadoresValNumH[16]; //contador para verificar que no se repitan los valores numericos..
	int contadoresVNJ[16]; //contador para corrovorar que no se repintan valores numericos de la maquina..
	int contadorG[6]; // contador para que no se repitan las generalas
	int contadorE[2];//contador para que no se repitan las escaleras
	int contadorP[6]; //contador para que no se repitan los poker
	int contadorF[15]; //contadores para los valores disponibles de ful
	srand(time(NULL));
	system ("color 0A" );
	lectura();
	cout<<endl<<endl;system("pause");
	system("cls");
	cout<<"\n\n\n\tGENERALA"<<endl<<endl;
	cout<<"GENERALA CONSISTE EN UN JUEGO EN DONDE SE TIRAN 5 DADOS Y DEPENDE DE LA COMBINACION QUE SALGA SUMARA MAS O MENOS PUNTOS"<<endl;
	cout<<"TAMBIEN SE PUEDEN CAMBIAR LOS DADOS QUE CONVENGAN EN UN SEGUNDO INTENTO, PERO SUMARA MENOS PUNTOS"<<endl;
	cout<<"RECORDAR QUE NO SE PUEDE VOLVER A SACAR DOS VECES EL MISMO TIPO DE PUNTAJE"<<endl;
	cout<<"TIPOS DE PUNTAJE: GENERALA (5 dados iguales), ESCALERA(una escalera de menor a mayor),FULL (2 dados iguales y otro 3 iguales)"<<endl;
	cout<<"POKER (4 dados iguales) Y POR ULTIMO VALORES NUMERICOS (cuando se repiten 2 o 3 dados, en el caso de que salga por ejemplo"<<endl;
	cout<<"una secunecia de 22445, siempre suma primero los menores, por lo cual sumara 4 pts, y luego el valor 4 pts se bloqueara)"<<endl<<endl;
	cout<<"PRESIONE 1 PARA COMENZAR";
	comenzar=getch()-48;
	system ("cls");
	while(comenzar==1){
		system ("color 0A" );
		for(int i=0; i<15; i++){
			contadorF[i]=0;
		}
		for(int i=0; i<16; i++){
			contadoresValNumH[i]=0;
			contadoresVNJ[i]=0;
		}
		for(int i=0; i<2; i++){  //aca los contadores de los diferentes tipos de tiros empiezan en cero
			contadorE[i]=0;
		}
		for(int i=0; i<6; i++){
			contadorP[i]=0;
			contadorG[i]=0;
		}
	while(auxh==auxm){
		cout<<endl<<endl<<"PRESIONE UNA TECLA PARA TIRAR LOS DADOS Y VER QUIEN COMIENZA: ";
		getch()-48;
		auxh=1+rand()%6;
		auxm=1+rand()%6;
		cout<<"\nDADO DE JARVIS: "<<auxm<<endl;
		cout<<"TU DADO: "<<auxh<<endl;
	}
	if(auxm>auxh){
		cout<<"ARRANCA JARVIS "<<endl<<endl<<endl;
	}
	if(auxh>auxm){
		cout<<"ARRANCA USTED "<<endl<<endl<<endl;
	}
	for(int i=0; i<10; i++){
	Repite_O_No=0;
	cout<<"TIRADA NUMERO: "<<i+1<<endl<<endl;
	DadosHumano(dado1, dado2 ,  dado3, dado4, dado5);
	DadosJarvis( dad1, dad2,  dad3, dad4, dad5);
	cout<<"SUS DADOS: "<<dado1<<" - "<<dado2<<" - "<<dado3<<" - "<<dado4<<" - "<<dado5<<endl;
	cout<<"DESEA VOLVER A TIRAR ALGUN DADO? (presione 1 para confirmar)"<<endl;
	volver_tirar=getch()-48;
	if(volver_tirar==1){
		VolverATirar(dado1, dado2 ,  dado3, dado4, dado5 );
		cout<<"\nSUS DADOS: "<<dado1<<" - "<<dado2<<" - "<<dado3<<" - "<<dado4<<" - "<<dado5<<endl;
		Repite_O_No=1;
	}
	escalera= Escalera(dado1,dado2,dado3,dado4,dado5,contadorE);
	generala= Generala(dado1,dado2,dado3,dado4,dado5,contadorG);
	poker= Poker (dado1,dado2,dado3,dado4,dado5,contadorP);
	full= Full (dado1,dado2,dado3,dado4,dado5,contadorF);
	valnumh=ValNumH (dado1,dado2,dado3,dado4,dado5,contadoresValNumH);
	if(escalera==1){
		if(Repite_O_No==0){
		cout<<"ESCALERA SERVIDA!	25 PUNTOS PARA GRIFINDOR"<<endl<<endl;
		puntos_hum+=25;
		}
		if(Repite_O_No==1){
			cout<<"ESCALERA ARMADA!		20 PUNTOS PARA GRIFINDOR"<<endl<<endl;
			puntos_hum+=20;
		}
	}else if(generala==1){
		if(Repite_O_No==0){
		cout<<"GENERALA SERVIDA!	55 PUNTOS PARA GRIFINDOR"<<endl<<endl;
		puntos_hum+=55;
		}
		if(Repite_O_No==1){
			cout<<"GENERALA ARMADA!	50 PUNTOS PARA GRIFINDOR"<<endl<<endl;
			puntos_hum+=50;
		}
	}else if(poker==1){
		if(Repite_O_No==0){
		cout<<"POKER SERVIDO! 	45 PUNTOS PARA GRIFINDOR"<<endl<<endl;
		puntos_hum+=45;
		}
		if(Repite_O_No==1){
			cout<<"POKER ARMADO! 	40 PUNTOS PARA GRIFINDOR"<<endl<<endl;
			puntos_hum+=40;
		}
	}else if(full==1){
		if(Repite_O_No==0){
		cout<<"FULL SERVIDO!	35 PUNTOS PARA GRIFINDOR"<<endl<<endl;
		puntos_hum+=35;
		}
		if(Repite_O_No==1){
			cout<<"FULL ARMADO!	30 PUNTOS PARA GRIFINDOR"<<endl<<endl;
			puntos_hum+=30;
		}
	}else if(valnumh!=0){
		cout<<valnumh<<" PUNTOS PARA GRIFNIDOR"<<endl<<endl;
		puntos_hum+=valnumh;
	}else{
		cout<<"NO HAY VALORES DISCONIBLES PARA USTED"<<endl<<endl;
	}
	cout<<"DADOS DEL BUEN JARIVS: "<<dad1<<" - "<<dad2<<" - "<<dad3<<" - "<<dad4<<" - "<<dad5<<endl;
	escalera= Escalera(dad1,dad2,dad3,dad4,dad5,contadorE);
	generala= Generala(dad1,dad2,dad3,dad4,dad5,contadorG);
	poker= Poker (dad1,dad2,dad3,dad4,dad5,contadorP);
	full= Full (dad1,dad2,dad3,dad4,dad5,contadorF);
	valnum=ValNumJ (dad1,dad2,dad3,dad4,dad5,contadoresVNJ);
	puntos_jarvis+=valnum;
	if(escalera==1){
		cout<<"ESCALERA!	25 PUNTOS PARA SLYTHERIN"<<endl;
		puntos_jarvis+=25;
		cout<<"_____________________________________________________________"<<endl<<endl;
	}else if(generala==1){
		cout<<"GENERALA!	55 PUNTOS PARA SLYTHERIN"<<endl;
		puntos_jarvis+=55;
		cout<<"_____________________________________________________________"<<endl<<endl;
	}else if(poker==1){
		cout<<"POKER!	45 PUNTOS PARA SLYTHERIN"<<endl;
		puntos_jarvis+=45;
		cout<<"_____________________________________________________________"<<endl<<endl;	
	}else if(full==1){
		cout<<"FULL!	35 PUNTOS PARA SLYTHERIN"<<endl;
		puntos_jarvis+=35;
		cout<<"_____________________________________________________________"<<endl<<endl;
	}else if(valnum!=0){
		cout<<valnum<<" PUNTOS PARA SLYTHERIN"<<endl;
		cout<<"_____________________________________________________________"<<endl<<endl;
	}else{
		cout<<"NO HAY PUNTOS DISPONIBLES PARA SLYTHERIN"<<endl;
		cout<<"_____________________________________________________________"<<endl<<endl;
	}
	cout<<"PRESIONE UNA TECLA PARA CONTINUAR ";
	getch()-48;
	cout<<endl<<endl;
	system("cls");
	}  //aca cierra el for de los 10 tiros
	cout<<"TU PUNTAJE: "<<puntos_hum<<endl;
	cout<<"PUNTAJE DE JARVIS: "<<puntos_jarvis<<endl;
	if(puntos_hum>puntos_jarvis){
	system ("color 1A" );
	cout<<"\n\n\n\t\t\tYOU WIN!"<<endl<<endl<<endl;
	}else if(puntos_hum<puntos_jarvis){
		system ("color 4E" );
		cout<<"\n\n\n\t\t\tYOU LOSE!"<<endl<<endl<<endl;
	} else{
		cout<<"\n\n\n\t\t\tEMPATE!! "<<endl<<endl<<endl;
	}
	auxh=auxm;  //esas son las variables aux de los dados para ver quien comiennza, ahi los igualo asi tira de nuevo los dados
	puntos_hum=0; puntos_jarvis=0; //aca se ponen en cero los puntajes
	cout<<"SI DESEA VOLVER A JUGAR PRESIONE 1"<<endl;comenzar=getch()-48;
	system("cls");
	} //llave que cierra el while general..
	return 0;
}
void DadosHumano(int& dado1,int& dado2 , int& dado3, int& dado4, int& dado5){
	int dadoshum[5],aux;//este auxiliar es para el burbuja de ordenamiento de los dado
	dado1=1+rand()%6;
	dado2=1+rand()%6;
	dado3=1+rand()%6;
	dado4=1+rand()%6;
	dado5=1+rand()%6;
	dadoshum[0]=dado1;
	dadoshum[1]=dado2;  //aca paso los dados a un vector para acomodarlos
	dadoshum[2]=dado3;
	dadoshum[3]=dado4;
	dadoshum[4]=dado5;
	for(int i=1; i<5; i++){
		for(int j=0; j<5-1; j++){
			if(dadoshum[j]>dadoshum[j+1]){
				aux=dadoshum[j];
				dadoshum[j]=dadoshum[j+1];
				dadoshum[j+1]=aux;
			}
		}
	}
	dado1=dadoshum[0];
	dado2=dadoshum[1];  //aca los devuelvo a las variables
	dado3=dadoshum[2];
	dado4=dadoshum[3];
	dado5=dadoshum[4];
}
void DadosJarvis(int& dad1,int& dad2 , int& dad3, int& dad4, int& dad5){
	int dadosjarvis[5],aux1=0;  //ese arregloy ese aux sirve para el burbuja y poder ordenarlos
	dad1=1+rand()%6;
	dad2=1+rand()%6;
	dad3=1+rand()%6;
	dad4=1+rand()%6;
	dad5=1+rand()%6;
	dadosjarvis[0]=dad1;
	dadosjarvis[1]=dad2;  //aca paso los dados a un vector para acomodarlos
	dadosjarvis[2]=dad3;
	dadosjarvis[3]=dad4;
	dadosjarvis[4]=dad5;
	for(int i=1; i<5; i++){
		for(int j=0; j<5-1; j++){
			if(dadosjarvis[j]>dadosjarvis[j+1]){
				aux1=dadosjarvis[j];
				dadosjarvis[j]=dadosjarvis[j+1];
				dadosjarvis[j+1]=aux1;
			}
		}
	}
	dad1=dadosjarvis[0];
	dad2=dadosjarvis[1];  //aca los devuelvo a las variables
	dad3=dadosjarvis[2];
	dad4=dadosjarvis[3];
	dad5=dadosjarvis[4];
}
int Escalera(int d1, int d2, int d3, int d4, int d5,int contadorEs[]){
	int escaleraa=0;
	if(d5==(d4+1) && d5 == (d3+2) && d5==(d2+3) && d5 ==(d1+4)){
		if(d1==1 && contadorEs[0]==0){
			escaleraa=1;
			contadorEs[0]++;
		}else if(d1==2 && contadorEs[1]==0){
			escaleraa=1;
			contadorEs[1]++;
		}
	}
	return escaleraa;
}
int Generala(int da1, int da2, int da3, int da4, int da5,int contadorGen[]){
	int generalaa=0;
	if(da1==da2 && da1==da3 && da1==da4 && da1==da5){
		if(da1==1 && contadorGen[0]==0){
			generalaa=1;
			contadorGen[0]++;
		}else if(da1==2 && contadorGen[1]==0){
			generalaa=1;
			contadorGen[1]++;
		}else if(da1==3 && contadorGen[2]==0){
			generalaa=1;
			contadorGen[2]++;
		}else if(da1==4 && contadorGen[3]==0){
			generalaa=1;
			contadorGen[3]++;
		}else if(da1==5 && contadorGen[4]==0){
			generalaa=1;
			contadorGen[4]++;
		}else if(da1==6 &&contadorGen[5]==0){
			generalaa=1;
			contadorGen[5]++;
		}
	}
	return generalaa;
}
int Poker (int dd1, int dd2, int dd3, int dd4, int dd5,int contadorPoker[]){
	int pokerr=0;
	if((dd1==dd2 && dd1==dd3 && dd1==dd4 && dd1!=dd5) || (dd1!=dd2 && dd2==dd3 && dd2==dd4 && dd2==dd5)){
		if(dd3==1 && contadorPoker[0]==0){
		pokerr=1;
		contadorPoker[0]++;
		}else if(dd3==2 && contadorPoker[1]==0){
			pokerr=1;
			contadorPoker[1]++;
		}else if(dd3==3 && contadorPoker[2]==0){
			pokerr=1;
			contadorPoker[2]++;
		}else if(dd3==4 && contadorPoker[3]==0){
			pokerr=1;
			contadorPoker[3]++;
		}else if(dd3==5 && contadorPoker[4]==0){
			pokerr=1;
			contadorPoker[4]++;
		}else if(dd3==6 && contadorPoker[5]==0){
			pokerr=1;
			contadorPoker[5]++;
		}
	}
	return pokerr;
}
int Full (int dda1, int dda2, int dda3, int dda4, int dda5, int contadorFul[]){
	int fulll=0;
	if((dda1== dda2 && dda3==dda4 && dda3==dda5) || (dda1==dda2 && dda1==dda3 && dda4==dda5)){
		if(dda1==1 && dda5==2 && contadorFul[0]==0){
			contadorFul[0]++;
		fulll=1;
		}else if(dda1==1 && dda5==3 && contadorFul[1]==0){
			contadorFul[1]++;
				fulll=1;
		}else if(dda1==1 && dda5==4 && contadorFul[2]==0){
			contadorFul[2]++;
				fulll=1;
		}else if(dda1==1 && dda5==5 && contadorFul[3]==0){
			contadorFul[3]++;
				fulll=1;
		}else if(dda1==1 && dda5==6 && contadorFul[4]==0){
			contadorFul[4]++;
				fulll=1;
		}else if(dda1==2 && dda5==3 && contadorFul[5]==0){
			contadorFul[5]++;
				fulll=1;
		}else if(dda1==2 && dda5==4 && contadorFul[6]==0){
			contadorFul[6]++;
				fulll=1;
		}else if(dda1==2 && dda5==5 && contadorFul[7]==0){
			contadorFul[7]++;
				fulll=1;
		}else if(dda1==2 && dda5==6 && contadorFul[8]==0){
			contadorFul[8]++;
				fulll=1;
		}else if(dda1==3 && dda5==4 && contadorFul[9]==0){
			contadorFul[9]++;
				fulll=1;
		}else if(dda1==3 && dda5==5 && contadorFul[10]==0){
			contadorFul[10]++;
				fulll=1;
		}else if(dda1==3 && dda5==6 && contadorFul[11]==0){
			contadorFul[11]++;
				fulll=1;
		}else if(dda1==4 && dda5==5 && contadorFul[12]==0){
			contadorFul[12]++;
				fulll=1;
		}else if(dda1==4 && dda5==6 && contadorFul[13]==0){
			contadorFul[13]++;
				fulll=1;
		}else if(dda1==5 && dda5==6 && contadorFul[14]==0){
			contadorFul[14]++;
			fulll=1;
		}
	}
	return fulll;
}
int ValNumH (int daa1, int daa2, int daa3, int daa4, int daa5, int contadorVN[]){
	int valnumh=0;
		if(daa1==daa2 && daa1==daa3 && daa1==1 && contadorVN[0]==0){
				valnumh= daa1*3;
				contadorVN[0]++;
		}else if(daa1==daa2 && daa1==daa3 && daa1==2 && contadorVN[1]==0){
				valnumh= daa1*3;
				contadorVN[1]++;
		}else if(daa1==daa2 && daa1==daa3 && daa1==3 && contadorVN[2]==0){
				valnumh= daa1*3;
				contadorVN[2]++;
		}else if(daa1==daa2 && daa1==daa3 && daa1==4 && contadorVN[3]==0){
				valnumh= daa1*3;
				contadorVN[3]++;
		}else if(daa1==daa2 && daa1==daa3 && daa1==5 && contadorVN[4]==0){
				valnumh= daa1*3;
				contadorVN[4]++;
		}else if(daa1==daa2 && daa1==daa3 && daa1==6 && contadorVN[5]==0){
				valnumh= daa1*3;
				contadorVN[5]++;
		}else if(daa2==daa3 && daa2==daa4 && daa2==1 && contadorVN[0]==0){
				valnumh= daa2*3;
				contadorVN[0]++;
		}else if(daa2==daa3 && daa2==daa4 && daa2==2 && contadorVN[1]==0){
				valnumh= daa2*3;
				contadorVN[1]++;
		}else if(daa2==daa3 && daa2==daa4 && daa2==3 && contadorVN[2]==0){
				valnumh= daa2*3;
				contadorVN[2]++;
		}else if(daa2==daa3 && daa2==daa4 && daa2==4 && contadorVN[3]==0){
				valnumh= daa2*3;
				contadorVN[3]++;
		}else if(daa2==daa3 && daa2==daa4 && daa2==5 && contadorVN[4]==0){
				valnumh= daa2*3;
				contadorVN[4]++;
		}else if(daa2==daa3 && daa2==daa4 && daa2==6 && contadorVN[5]==0){
				valnumh= daa2*3;
				contadorVN[5]++;
		}else if(daa3==daa4 && daa3==daa5 && daa3==1 && contadorVN[0]==0){
				valnumh= daa3*3;
				contadorVN[0]++;
		}else if(daa3==daa4 && daa3==daa5 && daa3==2 && contadorVN[1]==0){
				valnumh= daa3*3;
				contadorVN[1]++;
		}else if(daa3==daa4 && daa3==daa5 && daa3==3 && contadorVN[2]==0){
				valnumh= daa3*3;
				contadorVN[2]++;
		}else if(daa3==daa4 && daa3==daa5 && daa3==4 && contadorVN[3]==0){
				valnumh= daa3*3;
				contadorVN[3]++;
		}else if(daa3==daa4 && daa3==daa5 && daa3==5 && contadorVN[4]==0){
				valnumh= daa3*3;
				contadorVN[4]++;
		}else if(daa3==daa4 && daa3==daa5 && daa3==6 && contadorVN[5]==0){
				valnumh= daa3*3;
				contadorVN[5]++;
		}else if(daa1==daa2 && daa1==1 && contadorVN[6]==0){
				valnumh= daa1*2;
				contadorVN[6]++;
		}else if(daa1==daa2 && daa1==2 && contadorVN[7]==0){
				valnumh= daa1*2;
				contadorVN[7]++;
		}else if(daa1==daa2 && daa1==3 && contadorVN[8]==0){
				valnumh= daa1*2;
				contadorVN[8]++;
		}else if(daa1==daa2 && daa1==4 && contadorVN[9]==0){
				valnumh= daa1*2;
				contadorVN[9]++;
		}else if(daa1==daa2 && daa1==5 && contadorVN[10]==0){
				valnumh= daa1*2;
				contadorVN[10]++;
		}else if(daa1==daa2 && daa1==6 && contadorVN[11]==0){
				valnumh= daa1*2;
				contadorVN[11]++;
		}else if(daa2==daa3 && daa2==1 && contadorVN[6]==0){
				valnumh= daa2*2;
				contadorVN[6]++;
		}else if(daa2==daa3 && daa2==2 && contadorVN[7]==0){
				valnumh= daa2*2;
				contadorVN[7]++;
		}else if(daa2==daa3 && daa2==3 && contadorVN[8]==0){
				valnumh= daa2*2;
				contadorVN[8]++;
		}else if(daa2==daa3 && daa2==4 && contadorVN[9]==0){
				valnumh= daa2*2;
				contadorVN[9]++;
		}else if(daa2==daa3 && daa2==5 && contadorVN[10]==0){
				valnumh= daa2*2;
				contadorVN[10]++;
		}else if(daa2==daa3 && daa2==6 && contadorVN[11]==0){
				valnumh= daa2*2;
				contadorVN[11]++;
		}else if(daa3==daa4 && daa3==1 && contadorVN[6]==0){
				valnumh= daa3*2;
				contadorVN[6]++;
		}else if(daa3==daa4 && daa3==2 && contadorVN[7]==0){
				valnumh= daa3*2;
				contadorVN[7]++;
		}else if(daa3==daa4 && daa3==3 && contadorVN[8]==0){
				valnumh= daa3*2;
				contadorVN[8]++;
		}else if(daa3==daa4 && daa3==4 && contadorVN[9]==0){
				valnumh= daa3*2;
				contadorVN[9]++;
		}else if(daa3==daa4 && daa3==5 && contadorVN[10]==0){
				valnumh= daa3*2;
				contadorVN[10]++;
		}else if(daa3==daa4 && daa3==6 && contadorVN[11]==0){
				valnumh= daa3*2;
				contadorVN[11]++;
		}else if(daa4==daa5 && daa4==1 && contadorVN[6]==0){
				valnumh= daa4*2;
				contadorVN[6]++;
		}else if(daa4==daa5 && daa4==2 && contadorVN[7]==0){
				valnumh= daa4*2;
				contadorVN[7]++;
		}else if(daa4==daa5 && daa4==3 && contadorVN[8]==0){
				valnumh= daa4*2;
				contadorVN[8]++;
		}else if(daa4==daa5 && daa4==4 && contadorVN[9]==0){
				valnumh= daa4*2;
				contadorVN[9]++;
		}else if(daa4==daa5 && daa4==5 && contadorVN[10]==0){
				valnumh= daa4*2;
				contadorVN[10]++;
		}else if(daa4==daa5 && daa4==6 && contadorVN[11]==0){
				valnumh= daa4*2;
				contadorVN[11]++;
			}
	
	return valnumh;
}
int ValNumJ(int daad1, int daad2, int daad3, int daad4, int daad5,int contadorV[] ){
	int valnumj=0;
		if(daad1==daad2 && daad1==daad3 && daad1==1 && contadorV[0]==0){
			valnumj= daad1*3;
			contadorV[0]++;
		}else if(daad1==daad2 && daad1==daad3 && daad1==2 && contadorV[1]==0){
			valnumj= daad1*3;
			contadorV[1]++;
		}else if(daad1==daad2 && daad1==daad3 && daad1==3 && contadorV[2]==0){
			valnumj= daad1*3;
			contadorV[2]++;
		}else if(daad1==daad2 && daad1==daad3 && daad1==4 && contadorV[3]==0){
			valnumj= daad1*3;
			contadorV[3]++;
		}else if(daad1==daad2 && daad1==daad3 && daad1==5 && contadorV[4]==0){
			valnumj= daad1*3;
			contadorV[4]++;
		}else if(daad1==daad2 && daad1==daad3 && daad1==6 && contadorV[5]==0){
			valnumj= daad1*3;
			contadorV[5]++;
		}else if(daad2==daad3 && daad2==daad4 && daad2==1 && contadorV[0]==0){
			valnumj= daad2*3;
			contadorV[0]++;
		}else if(daad2==daad3 && daad2==daad4 && daad2==2 && contadorV[1]==0){
			valnumj= daad2*3;
			contadorV[1]++;
		}else if(daad2==daad3 && daad2==daad4 && daad2==3 && contadorV[2]==0){
			valnumj= daad2*3;
			contadorV[2]++;
		}else if(daad2==daad3 && daad2==daad4 && daad2==4 && contadorV[3]==0){
			valnumj= daad2*3;
			contadorV[3]++;
		}else if(daad2==daad3 && daad2==daad4 && daad2==5 && contadorV[4]==0){
			valnumj= daad2*3;
			contadorV[4]++;
		}else if(daad2==daad3 && daad2==daad4 && daad2==6 && contadorV[5]==0){
			valnumj= daad2*3;
			contadorV[5]++;
		}else if(daad3==daad4 && daad3==daad5 && daad3==1 && contadorV[0]==0){
			valnumj= daad3*3;
			contadorV[0]++;
		}else if(daad3==daad4 && daad3==daad5 && daad3==2 && contadorV[1]==0){
			valnumj= daad3*3;
			contadorV[1]++;
		}else if(daad3==daad4 && daad3==daad5 && daad3==3 && contadorV[2]==0){
			valnumj= daad3*3;
			contadorV[2]++;
		}else if(daad3==daad4 && daad3==daad5 && daad3==4 && contadorV[3]==0){
			valnumj= daad3*3;
			contadorV[3]++;
		}else if(daad3==daad4 && daad3==daad5 && daad3==5 && contadorV[4]==0){
			valnumj= daad3*3;
			contadorV[4]++;
		}else if(daad3==daad4 && daad3==daad5 && daad3==6 && contadorV[5]==0){
			valnumj= daad3*3;
			contadorV[5]++;
		}else if(daad1==daad2 && daad1==1 && contadorV[6]==0){
			valnumj= daad1*2;
			contadorV[6]++;
		}else if(daad1==daad2 && daad1==2 && contadorV[7]==0){
			valnumj= daad1*2;
			contadorV[7]++;
		}else if(daad1==daad2 && daad1==3 && contadorV[8]==0){
			valnumj= daad1*2;
			contadorV[8]++;
		}else if(daad1==daad2 && daad1==4 && contadorV[9]==0){
			valnumj= daad1*2;
			contadorV[9]++;
		}else if(daad1==daad2 && daad1==5 && contadorV[10]==0){
			valnumj= daad1*2;
			contadorV[10]++;
		}else if(daad1==daad2 && daad1==6 && contadorV[11]==0){
			valnumj= daad1*2;
			contadorV[11]++;
		}else if(daad2==daad3 && daad2==1 && contadorV[6]==0){
			valnumj= daad2*2;
			contadorV[6]++;
		}else if(daad2==daad3 && daad2==2 && contadorV[7]==0){
			valnumj= daad2*2;
			contadorV[7]++;
		}else if(daad2==daad3 && daad2==3 && contadorV[8]==0){
			valnumj= daad2*2;
			contadorV[8]++;
		}else if(daad2==daad3 && daad2==4 && contadorV[9]==0){
			valnumj= daad2*2;
			contadorV[9]++;
		}else if(daad2==daad3 && daad2==5 && contadorV[10]==0){
			valnumj= daad2*2;
			contadorV[10]++;
		}else if(daad2==daad3 && daad2==6 && contadorV[11]==0){
			valnumj= daad2*2;
			contadorV[11]++;
		}else if(daad3==daad4 && daad3==1 && contadorV[6]==0){
			valnumj= daad3*2;
			contadorV[6]++;
		}else if(daad3==daad4 && daad3==2 && contadorV[7]==0){
			valnumj= daad3*2;
			contadorV[7]++;
		}else if(daad3==daad4 && daad3==3 && contadorV[8]==0){
			valnumj= daad3*2;
			contadorV[8]++;
		}else if(daad3==daad4 && daad3==4 && contadorV[9]==0){
			valnumj= daad3*2;
			contadorV[9]++;
		}else if(daad3==daad4 && daad3==5 && contadorV[10]==0){
			valnumj= daad3*2;
			contadorV[10]++;
		}else if(daad3==daad4 && daad3==6 && contadorV[11]==0){
			valnumj= daad3*2;
			contadorV[11]++;
		}else if(daad4==daad5 && daad4==1 && contadorV[6]==0){
			valnumj= daad4*2;
			contadorV[6]++;
		}else if(daad4==daad5 && daad4==2 && contadorV[7]==0){
			valnumj= daad4*2;
			contadorV[7]++;
		}else if(daad4==daad5 && daad4==3 && contadorV[8]==0){
			valnumj= daad4*2;
			contadorV[8]++;
		}else if(daad4==daad5 && daad4==4 && contadorV[9]==0){
			valnumj= daad4*2;
			contadorV[9]++;
		}else if(daad4==daad5 && daad4==5 && contadorV[10]==0){
			valnumj= daad4*2;
			contadorV[10]++;
		}else if(daad4==daad5 && daad4==6 && contadorV[11]==0){
			valnumj= daad4*2;
			contadorV[11]++;
		}
	
	return valnumj;
}
void VolverATirar(int& dado1,int& dado2, int& dado3, int& dado4, int& dado5 ){
	int dadoshum[5],aux; //ese aux es para el burbuja
	int cantidad_de_dados=0; //variable para preguntar cuantos dados quiere repetir
	int que_dados[5]={0,0,0,0,0}; //vector donde se modifican los dados que se desean.
	cout<<"\nINGRESE LA CANTIDAD DE DADOS QUE DESEA REPETIR: ";
	cin>>cantidad_de_dados;
	while(cantidad_de_dados>5 || cantidad_de_dados<0){
		cout<<"ESE NUMERO ESTA FUERA DE LO PERMITIDO, POR FAVOR INGRESE UN NUMERO DEL 1 AL 5: ";cin>>cantidad_de_dados;
	}
	cout<<"POR FAVOR INGRESE LA POSICION EXACTA DE LOS DADOS QUE QUIERE VOLVER A TIRAR"<<endl;
	for(int i=0; i<cantidad_de_dados; i++){
		cin>>que_dados[i];
		while(que_dados[i] > 5 || que_dados[i]<1){
			cout<<"ESE NUMERO NO ESTA DISPONIBLE, POR FAVOR INGRESE EL NUMERO DE LA POSICION QUE DESEA VOLVER A TIRAR 1 AL 5: ";
			cin>>que_dados[i];
		}
	}
	for(int i=0; i<cantidad_de_dados; i++){
		if(que_dados[i]==1){
			dado1=1+rand()%5;
		}else if(que_dados[i]==2){
			dado2=1+rand()%5;
		}else if(que_dados[i]==3){
			dado3=1+rand()%5;
		}else if(que_dados[i]==4){
			dado4=1+rand()%5;
		}else if(que_dados[i]==5){
			dado5=1+rand()%5;
		}}
	dadoshum[0]=dado1;
	dadoshum[1]=dado2;  //aca paso los dados a un vector para acomodarlos
	dadoshum[2]=dado3;
	dadoshum[3]=dado4;
	dadoshum[4]=dado5;
	for(int i=1; i<5; i++){
		for(int j=0; j<5-1; j++){
			if(dadoshum[j]>dadoshum[j+1]){
				aux=dadoshum[j];
				dadoshum[j]=dadoshum[j+1];
				dadoshum[j+1]=aux;
			}
		}
	}
	dado1=dadoshum[0];
	dado2=dadoshum[1];  //aca los devuelvo a las variables
	dado3=dadoshum[2];
	dado4=dadoshum[3];
	dado5=dadoshum[4];
}
void lectura(){
	ifstream archivo;
	string texto;
	
	archivo.open("GENERALA.txt",ios::in);//Abrimos el archivo
	if(archivo.fail()){
		exit(1);
	}
	
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
}
