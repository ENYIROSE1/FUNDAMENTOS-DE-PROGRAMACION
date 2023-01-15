
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring> //strcmp
#include <windows.h>
#include <fstream>
#include <ctime>
#define USUARIO "70503384"
#define CLAVE "1015"
#define USUARIO2 "72799093"
#define CLAVE2 "2025"
#define TAMANOU 8
#define TAMANOC 4
using namespace std;
struct registro{
	string nombre;
	int dni;
	string fecha;
	int multiplicador;
	int codigop;
	int codigopar;
	string opcionp;
	int codigoj;
	string partidol;
	string partidov;
	float cuotal;
	float cuotae;
	float cuotav;
	float cuotaf;
	int cuotao;
	int numeros;
	int nrs;
}*regPe=NULL;

void menu();
void login();
void registrarp();
void asis();
void admi();
void mostrarp();
void registrar();
void teapuesto();
void latinka();
void salir();
void escribir();
void escribir2();
void escribir3();
void ordenarporinsercion(int *lista,int tam);

int tam,op,c,op1,i,op2,top,tinka,top1,n,j,r[100],ne[4][6],re=0,dn,np,opa,tt,aux;
char usu[TAMANOU+1];
char clave[TAMANOC+1];
char usu2[TAMANOU+1];
char clave2[TAMANOC+1];
 int temporal[6];
	int ordenado[6];
float total,mul=1,cont=0,totala,gp;


int main()
{
	system("color 2e");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);


	regPe=new registro[100];
	srand(time(NULL));
	login();
	delete[] regPe;
	return 0;
}
void login()
{
	system("cls");
	cout<<"\t\t\t ***INTRALOT*** \t\t\t"<<endl<<endl;
	cout<<"\t\t Inicio de Sesión \t\t"<<endl<<endl;
	cout<<"\t 1.- Administrador"<<endl;
	cout<<"\t 2.- Asistente"<<endl<<endl;
	cout<<"\t Ingrese una opción: ";cin>>opa;
	switch(opa)
	{
		case 1: system("cls");admi();break;
		case 2: system("cls");asis();break;
		default:
			system("cls");
			cout<<"Ingrese una opción valida por favor!";
			getch();
			login();
	}
}
void admi()
{
	int ingresa=0,intento=0, i=0,j=0;
	char cla,usua;
	
	do
	{
		i=0;
		j=0;
		system("cls");
		cout<<"\t\t\t ***INTRALOT*** \t\t\t"<<endl<<endl;
		cout<<"\t\t Inicio de Sesión del Administrado \t\t"<<endl<<endl;
		cout<<"\t 1.- Usuario: ";
		while(usua=getch())
		{
				if(usua==13)
				{
					usu[i]= '\0';break;
				}
				else if(usua==8)
				{
					if(i>0)
					{
						i--;
						cout<<"\b \b";
					}
				}
				else
				{
					if(i<TAMANOU)
					{
						cout<<usua;
						usu[i]=usua;
						i++;
					}
				}
		}
		cout<<endl;
		
		cout<<"\t 2.- Clave: ";fflush(stdin);
		while(cla=getch())
		{
			if(cla==13)
			{
				clave[j]= '\0';break;
			}
			else if(cla==8)
			{
				if(j>0)
				{
					j--;
					cout<<"\b \b";
				}
			}
			else
			{
				if(j<TAMANOC)
				{
					cout<<"*";
					clave[j]=cla;
					j++;
				}
			}
		}
		if(strcmp(usu, USUARIO)==0 && strcmp(clave,CLAVE)==0)
		{
			ingresa=1;
		}
		else
		{
			cout<<endl;
			cout<<"\t Usuario y/o claves son incorrectos"<<endl<<endl;
			intento++;
			getch();
		}
		
	}while(intento<3 && ingresa==0);
	cout<<endl;
	if(ingresa==1)
	{
		cout<<endl<<endl;;
		cout<<"\t Bienvenido al sistema"<<endl<<endl;
		getch();
		registrarp();
	}
	else
	{
		cout<<endl;
		cout<<"\t Ha excedido el número máximo de intentos"<<endl<<endl;
	}
}
void registrarp()
{
	system("cls");
	cout<<endl;
	cout<<"\t Bienvenido Sr. Carlos"<<endl<<endl;
	cout<<"\t Escriba la cantidad de partido a registrar: ";cin>>np;
	cout<<endl;
	for(i=0;i<np;i++)
	{
		cout<<"\t Partido Nro: "<<i+1<<endl;
		cout<<"\t Código: ";cin>>(regPe+i)->codigop;
		cout<<"\t Equipo Local: ";fflush(stdin);getline(cin,(regPe+i)->partidol);
		cout<<"\t Equipo Visita: ";fflush(stdin);getline(cin,(regPe+i)->partidov);
		do
		{
			cout<<"\t Cuota Local: ";cin>>(regPe+i)->cuotal;
			if((regPe+i)->cuotal<1.05)
			{
				cout<<"\t Ingrese una cuota mayor a 1.05"<<endl;
			}
			
		}while((regPe+i)->cuotal<1.05);
		
		do
		{
			cout<<"\t Cuota Empate: ";cin>>(regPe+i)->cuotae;
			if((regPe+i)->cuotae<1.05)
			{
				cout<<"\t Ingrese una cuota mayor a 1.05"<<endl;
			}
			
		}while((regPe+i)->cuotae<1.05);
		
		do
		{
			cout<<"\t Cuota Visita: ";cin>>(regPe+i)->cuotav;
			if((regPe+i)->cuotav<1.05)
			{
				cout<<"\t Ingrese una cuota mayor a 1.05"<<endl;
			}
			
		}while((regPe+i)->cuotav<1.05);
		
		cout<<endl<<endl;
	}
	getch();
	
	cout<<endl<<endl<<endl;
	cout<<"\t Recaudación de apuestas mayor a 499 soles por día -> Televisor para el local"<<endl;
	cout<<"\t Recaudación de apuestas entre 400 y 499 soles por día -> Decoración del local"<<endl; 
	getch();
	login();
}
void asis()
{
	int ingresa2=0,intento2=0, i=0,j=0;
	char cla2,usua2;
	
	do
	{
		i=0;
		j=0;
		system("cls");
		cout<<"\t\t\t ***INTRALOT*** \t\t\t"<<endl<<endl;
		cout<<"\t\t Inicio de Sesión del Administrado \t\t"<<endl<<endl;
		cout<<"\t 1.- Usuario: ";
		while(usua2=getch())
		{
				if(usua2==13)
				{
					usu2[i]= '\0';break;
				}
				else if(usua2==8)
				{
					if(i>0)
					{
						i--;
						cout<<"\b \b";
					}
				}
				else
				{
					if(i<TAMANOU)
					{
						cout<<usua2;
						usu2[i]=usua2;
						i++;
					}
				}
		}
		cout<<endl;
		
		cout<<"\t 2.- Clave: ";fflush(stdin);
		while(cla2=getch())
		{
			if(cla2==13)
			{
				clave2[j]= '\0';break;
			}
			else if(cla2==8)
			{
				if(j>0)
				{
					j--;
					cout<<"\b \b";
				}
			}
			else
			{
				if(j<TAMANOC)
				{
					cout<<"*";
					clave2[j]=cla2;
					j++;
				}
			}
		}
		if(strcmp(usu2, USUARIO2)==0 && strcmp(clave2,CLAVE2)==0)
		{
			ingresa2=1;
		}
		else
		{
			cout<<endl;
			cout<<"\t Usuario y/o claves son incorrectos"<<endl<<endl;
			intento2++;
			getch();
		}
		
	}while(intento2<3 && ingresa2==0);
	
	if(ingresa2==1)
	{
		cout<<endl;
		cout<<"\t Bienvenido al sistema"<<endl<<endl;
		getch();
		mostrarp();
	}
	else
	{
		cout<<endl;
		cout<<"\t Ha excedido el número máximo de intentos"<<endl<<endl;
	}
}
void mostrarp()
{
	system("cls");
	cout<<"\t\t\t\t ***Tabla de partidos para apostar*** \t\t"<<endl<<endl;
	cout<<"Cod. Partido"<<"\t\t\t"<<"Partido"<<"\t\t\t"<<"Local"<<"\t"<<"Empate"<<"\t"<<"Visita"<<endl<<endl;
	for(i=0;i<np;i++)
	{
		cout<<(regPe+i)->codigop<<"\t\t\t"<<(regPe+i)->partidol<<" vs "<<(regPe+i)->partidov<<"\t"<<(regPe+i)->cuotal<<"\t"<<(regPe+i)->cuotae<<"\t"<<(regPe+i)->cuotav<<endl;
	}
	getch();
	cout<<"Presione cualquier tecla para ir al menú";
	getch();
	menu();
}
void menu()
{
	system("cls");
	cout<<"\t\t Casa de Apuestas \t\t"<<endl<<endl;
	cout<<"1) Registrar Persona"<<endl;
	cout<<"2) Te Apuesto"<<endl;
	cout<<"3) La Tinka"<<endl;
	cout<<"4) Salir"<<endl<<endl;
	cout<<"Ingrese una opción: ";cin>>op;
	switch(op)
	{
		case 1: system("cls");
		registrar();break;
		case 2: system("cls");
		teapuesto();break;
		case 3: system("cls");
		latinka();break;
		case 4: system("cls");
		salir();break;
		default:
			system("cls");
			cout<<"Opción incorrecta, ingrese una opción valida por favor¡";
			getch();
			menu();
	}
}
void registrar()
{
	regPe->codigoj=5+rand()%1250;
	regPe->fecha="11-12-19";
	cout<<"\t\t Casa de Apuestas \t\t"<<endl<<endl;Beep(15000,100);
	cout<<"Datos de la persona"<<endl<<endl;Beep(1500,100);
	cout<<"Código de la jugada: "<<regPe->codigoj<<endl;Beep(1500,100);
	cout<<"Nombre: ";fflush(stdin);getline(cin,regPe->nombre);Beep(1500,100);
	cout<<"DNI: ";cin>>regPe->dni;Beep(1500,100);
	cout<<"Fecha: "<<regPe->fecha<<endl;Beep(1500,100);
	getch();
	menu();
}
void teapuesto()
{
	cout<<"\t\t\t Casa de Apuestas \t\t\t"<<endl<<endl;
	cout<<"\t\t Te apuesto \t\t"<<endl;
	cout<<"\t\t\t\t ***Tabla de partidos para apostar*** \t\t"<<endl<<endl;
	cout<<"Cod. Partido"<<"\t\t\t"<<"Partido"<<"\t\t\t"<<"Local"<<"\t"<<"Empate"<<"\t"<<"Visita"<<endl<<endl;
	for(i=0;i<np;i++)
	{
		cout<<(regPe+i)->codigop<<"\t\t\t"<<(regPe+i)->partidol<<" vs "<<(regPe+i)->partidov<<"\t"<<(regPe+i)->cuotal<<"\t"<<(regPe+i)->cuotae<<"\t"<<(regPe+i)->cuotav<<endl;
	}
	cout<<endl<<endl;
	cout<<"Señor "<<regPe->nombre<<" ingrese la cantidad de partidos a apostar: ";cin>>tam;Beep(1500,100);
	cout<<endl;
	for(i=0;i<tam;i++)
	{
		do
		{
		cout<<endl;
		cout<<"Ingrese el código del partido: ";cin>>(regPe+i)->codigopar;Beep(1500,100);
		cout<<endl;
		if((regPe+i)->codigopar==(regPe+i)->codigop)
		{
			cout<<"El Partido es: "<<"\t\t\t"<<(regPe+i)->partidol<<" vs "<<(regPe+i)->partidov<<endl;
			cout<<"Seleccione una opción: "<<endl;
			cout<<"1) Local"<<endl;
			cout<<"2) Empate"<<endl;
			cout<<"3) Visita"<<endl<<endl;
			do
			{
				cout<<"Opcion: ";cin>>(regPe+i)->cuotao;
				switch((regPe+i)->cuotao)
				{
					case 1: (regPe+i)->opcionp="Local";(regPe+i)->cuotaf=(regPe+i)->cuotal;mul=mul*(regPe+i)->cuotal;Beep(1500,100);break;
					case 2: (regPe+i)->opcionp="Empate";(regPe+i)->cuotaf=(regPe+i)->cuotae;mul=mul*(regPe+i)->cuotae;Beep(1500,100);break;
					case 3: (regPe+i)->opcionp="Visita";(regPe+i)->cuotaf=(regPe+i)->cuotav;mul=mul*(regPe+i)->cuotav;Beep(1500,100);break;
					default:
						cout<<"Ingrese una opción valida";
						getch();
				}
			}while((regPe+i)->cuotao!=1 && (regPe+i)->cuotao!=2 && (regPe+i)->cuotao!=3);
		}
		else
		{
			cout<<"El código ingresado no existe"<<endl;
		}
		}while((regPe+i)->codigopar != (regPe+i)->codigop);
	}
	do
	{
		cout<<"Monto a apostar: ";cin>>regPe->multiplicador;
		if((regPe)->multiplicador<2)
		{
			cout<<endl;
			cout<<"La apuesta mínima es de 2 soles."<<endl;
		}
	}while((regPe)->multiplicador<2);
	getch();
	escribir();
	menu();
}
void latinka()
{  
	
	system("cls");
	cout<<"\t\t\t Casa de Apuestas \t\t\t"<<endl<<endl;
	cout<<"\t\t La Tinka \t\t"<<endl;
	cout<<"1) Ver numeros"<<endl;
	cout<<"2) Jugada "<<endl;
	cout<<"3) salir"<<endl;
	cin>>top;
	
	switch(top)
	{
		case 1: system("cls");
		cout<<" Los numeros son los siquientes "<<endl;
		cout<<" 1 "<<" "<<"2"<<" "<<" 3"<<" "<<" 4"<<" "<<" 5"<<endl;
		cout<<" 6 "<<" "<<"7"<<" "<<" 8"<<" "<<" 9"<<" "<<"10"<<endl;
		cout<<"11"<<" "<<"12"<<" "<<"13"<<" "<<"14"<<" "<<"15"<<endl;
		cout<<"16"<<" "<<"17"<<" "<<"18"<<" "<<"19"<<" "<<"20"<<endl;
		cout<<"21"<<" "<<"22"<<" "<<"23"<<" "<<"24"<<" "<<"25"<<endl;
		cout<<"26"<<" "<<"27"<<" "<<"28"<<" "<<"29"<<" "<<"30"<<endl;
		cout<<"31"<<" "<<"32"<<" "<<"33"<<" "<<"34"<<" "<<"35"<<endl;
		cout<<"36"<<" "<<"37"<<" "<<"38"<<" "<<"39"<<" "<<"40"<<endl;
		cout<<"41"<<" "<<"42"<<" "<<"43"<<" "<<"44"<<" "<<"45"<<endl<<endl<<endl;
		cout<<"Los premios son:"<<endl<<endl;
		cout<<"Con tres numeros acertados s/1500"<<endl;
		cout<<"Con cuatro numeros acertados s/2000"<<endl;
		cout<<"Con cinco numeros hacertados s/25000"<<endl;
		cout<<"Con los seis numeros acertados ganas el premio mayor que es de s/10000"<<endl;
		getch();latinka();break;
		
		case 2: system("cls");
		cout<<"\t\t\t La Tinka \t\t\t"<<endl<<endl;
		cout<<"*OJO* el precio de cada jugada es de s/4.00 y puedes escoger 6 numeros"<<endl<<endl;
		cout<<"1) Escoger numeros"<<endl;
		cout<<"2) Escoger numeros al azar"<<endl;
		cin>>top1;
		switch(top1)
		{
			case 1:system("cls");
			cout<<"\t\t Escoger numeros\t\t"<<endl<<endl;
			cout<<"Señor: "<<regPe->nombre<<endl;
			do
			{
				cout<<"Ingrese la cantidad de jugadas que desea realizar:";cin>>tinka;
			if(tinka>4)
			{
				cout<<endl;
				cout<<"Solamente se pueden hacer hasta 4 jugadas"<<endl;
			}
			}while(tinka>4);
			for(i=0;i<tinka;i++)
			{
				cout<<"Jugada:"<<i+1<<endl;
				for(int j=0;j<6;j++)
				{
					cout<<"Número "<<j+1<<" es: ";cin>>temporal[j];
					while(temporal[j]<1||temporal[j]>45){
						cout<<"Ingrese numero correcto"<<endl;
						cout<<"Número "<<j+1<<" es: ";cin>>temporal[j];
					}	
				}
				ordenarporinsercion(temporal,6);
				for(int k=0;k<6;k++){
					ne[i][k]=temporal[k];
				}
				cout<<endl<<endl;
			}
			cout<<ne[i][j]<<" ";
			getch();latinka();escribir2();break;
			
			case 2:system("cls");
			cout<<"Señor: "<<regPe->nombre<<endl;
			do
			{
				cout<<"Ingrese la cantidad de jugadas que desea realizar:";cin>>tinka;
			if(tinka>4)
			{
				cout<<endl;
				cout<<"Solamente se pueden hacer hasta 4 jugadas"<<endl;
			}
			}while(tinka>4);
			for(i=0;i<tinka;i++)
			{
				cout<<"Jugada Nro: "<<i+1<<endl;
				for(j=0;j<6;j++)
				{
				temporal[j]=1+rand()%(46-1);
				cout<<"Numero"<<j+1<<" es:"<<temporal[j]<<endl;
				cout<<endl;
				}
				ordenarporinsercion(temporal,6);
				for(int k=0;k<6;k++){
					ne[i][k]=temporal[k];
				}
				cout<<endl<<endl;
			}
			getch();latinka();escribir2();break;		
		}
		case 3: 
		getch();menu();break;
		default:
			system("cls");
			cout<<"Opción incorrecta, ingrese una opción valida por favor";getch();latinka();
	}
	if(totala>=500)
	{
		cout<<"Usted ha ganado un Televisor para su local";
	}
	else if(totala>400)
	{
		cout<<"Usted ha ganado un decorado para su local";
	}
	else
	{
		cout<<"Por el momento no hay premio";
	}
	gp=total*015+tt*025;
	cout<<"Las ganancia obtenida es: "<<gp;
	getch();
	menu();
}
void salir()
{
	cout<<"El programa ha terminado correctamente"<<endl;
	escribir3();
}
void escribir()
{
	ofstream jugadasalida;
	jugadasalida.open("Te Apuesto.txt",ios::out|ios::trunc);
	jugadasalida<<"\t\t Casa de Apuestas \t\t"<<endl<<endl;
	jugadasalida<<"Datos de la Persona"<<endl;
	jugadasalida<<"Codigo: "<<regPe->codigoj<<"\t\t"<<"Fecha: "<<regPe->fecha<<endl;
	jugadasalida<<"Nombre: "<<regPe->nombre<<"\t\t"<<"DNI: "<<regPe->dni<<endl<<endl<<endl;
	jugadasalida<<"\t\t\t **Jugada realizada** \t"<<endl;
	jugadasalida<<"Cod. Partido"<<"\t\t\t"<<"Partido"<<"\t\t\t\t"<<"Opcion"<<"\t\t"<<"Cuota"<<endl;
	for(i=0;i<tam;i++)
	{
		jugadasalida<<(regPe+i)->codigop<<"\t\t\t"<<(regPe+i)->partidol<<" vs "<<(regPe+i)->partidov<<"\t\t"<<(regPe+i)->opcionp<<"\t\t"<<(regPe+i)->cuotaf<<endl;
	}
	cout<<endl<<endl;
	jugadasalida<<"Monto apostado: "<<regPe->multiplicador<<endl;
	total=mul*regPe->multiplicador;
	jugadasalida<<"Total: "<<total;
	
	jugadasalida.close();
}
void escribir2()
{
	ofstream numersalida;
	numersalida.open("Tinka.txt",ios::out|ios::trunc);
	numersalida<<"\t\t Casa de Apuestas \t\t"<<endl<<endl;
	numersalida<<"Datos de la Persona"<<endl;
	numersalida<<"Codigo: "<<regPe->codigoj<<"\t\t"<<"Fecha: "<<regPe->fecha<<endl;
	numersalida<<"Nombre: "<<regPe->nombre<<"\t\t"<<"DNI: "<<regPe->dni<<endl<<endl<<endl;
	for(i=0;i<tinka;i++){
	numersalida<<"\t **Jugada realizada Numero "<<i+1<< "**\t"<<endl;
	numersalida<<"Numeros escogidos: "<<endl;
	for (int j=0;j<6;j++){
		numersalida<<"Numero "<<j+1<<" es:"<<ne[i][j]<<endl;
		}
	}
	srand(time(NULL));
	numersalida<<"Estos son los números ganadores: "<<endl;
	for(int a=0;a<6;a++){
			r[a]=1+rand()%(46-1);
			
	}
			ordenarporinsercion(r,6);
	for	(int a=0;a<6;a++){
		numersalida<<"Numero "<<a+1<<" es: "<<r[a]<<endl;
	}
		
		for(int a=0;a<tinka;a++){
			for(int j=0;j<6;j++){
				for(int z=0;z<6;z++){
					if(ne[a][j]==r[z]){
						cont++;
					}
				}

		}	cout<<endl;
			numersalida<<"Numeros acertados en la jugada "<<a+1<<" son: ";
			numersalida<<cont<<" "<<endl;
			cont=0;	
	}	
	if(cont<=2){
		numersalida<<"PERDIO"<<endl;
	}
	if(cont==3){
		numersalida<<"GANO!!"<<endl;
		numersalida<<"Usted gano s/1500"<<endl;
	}
	else if(cont==4){
		numersalida<<"GANO!!"<<endl;
		numersalida<<"Usted gano s/2000"<<endl;
	}
	else if(cont==5){
		numersalida<<"GANO!!"<<endl;
		numersalida<<"Usted gano s/25000"<<endl;
	}
	else if(cont==6){
		numersalida<<"GANO!!"<<endl;
		numersalida<<"Usted gano el premio mayor de s/10000"<<endl;
	}
	numersalida.close();
}
void escribir3()
{
	ofstream resumen;
	resumen.open("Resumen de Ventas.txt",ios::out|ios::trunc);
	resumen<<"\t\t Casa de Apuestas \t\t"<<endl<<endl;
	resumen<<"Este es el resumen de ventas del día"<<endl<<endl;
	resumen<<"\t Te Apuesto: \t"<<endl<<endl;
	if(total!=0)
	{
		resumen<<"\t La cantidad total apostada en TE APUESTO es: "<<total<<endl;
		resumen<<endl;
	}
	else
	{
		resumen<<"\t No se realizaron apuestas en TE APUESTO"<<endl;
		resumen<<endl;
	}
	tt=tinka*4;
	resumen<<"\t La Tinka: \t"<<endl<<endl;
	if(tt!=0)
	{
		resumen<<"\t La cantidad total apostada en LA TINKA es: "<<tt;
	}
	else
	{
		resumen<<"\t No se realizaron apuestas en LA TINKA"<<endl;
	}
	totala=total+tt;
	resumen<<endl<<endl;
	resumen<<"\t La cantidad total apostada es: "<<totala<<endl;
	resumen<<endl<<endl;
	resumen.close();
	
}
void ordenarporinsercion(int *lista,int tam)
{
	int i,j,aux;
	for(i=1;i<tam;i++)
	{
		aux=lista[i];
		j=i-1;
		while(lista[j]>aux&&j>=0)
		{
			lista[j+1]=lista[j];
			j--;
		}
		lista[j+1]=aux;
	}
}
