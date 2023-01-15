#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include <fstream>
#include <ctime>

#define NUM_ADM 3
#define NUM_CLI 3
#define NUM_EQU 6
#define TIPO_ADM 0
#define TIPO_CLI 1
using namespace std;
/**
YA SE COMO SE HACE DOCUMENTACION!!!!!!!!
*/

/**
Cosas por hacer

    -Cambiar el arr del inicio por un struct que sea
    struct cuenta
    {
        string usuario;
        string clave;
    }
    -crear un strunct
    administradores{
    cuenta* cuentas;
    }
    en el que almacenar las cuentas de administrador, igualmente con los clientes y solo pasar ese objeto por referencia *** creo que los struct solo se pasan
    por referencia
*/
/**
REGISTRO ESTA MAL ECHO , STRUCT DEMACIADO GRANDE
*/
struct cuenta
{
    int tipo;
    string usuario;
    string clave;
};

struct equipo
{
    string nombre;
    int probabilidad;
};
struct equipos
{
    equipo* equipos;
};

struct partido
{
    int codigo;

    equipo local;
    equipo visitante;
    float couta_l;
    float cuota_v;
    float cuota_e;

    int resultado;
};
struct partidos_hoy
{
    partido* partidos;
};
struct casa
{
    float inicial;
    float ganancia;
    float perdida;
    float total;
};


struct apuesta
{
    int codigo;
    partido partido;
    int resultado;
    int monto;
};

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
}
*regPe=NULL;
    cuenta cuenta_actual = {-1,"" , ""};
    partidos_hoy Partidos_hoy = {NULL};
    equipos Equipos = {NULL};

/**
Una espera de 1 segundo*/
void espera(){
    double t0 = clock();
    while( (clock() - t0)/CLOCKS_PER_SEC < 1 );
}
void lector_inicio(string ruta,string arr[10][2])
{
    string linea;
    ifstream archivo(ruta.c_str());
    for (int i = 0 ; getline(archivo, linea) ;  i++)
    {
        arr[i/2][i%2] = linea;
    }

    archivo.close();
}
bool busqueda_inicio(string usuario,string clave,string arr[10][2])
{
    for (int i = 0 ; i < NUM_ADM ;  i++)
    {
        if (arr[i][0] == usuario && arr[i][1] == clave)
        return true;
    }
    return false;
}

void menu();
void Login();
void Registrar_Partidos();
void asis();
bool Inicio(string ruta,string denominacion);
void mostrarp();
void registrar();
void teapuesto();
void latinka();
void salir();
void escribir();
void escribir2();
void escribir3();
void ordenarporinsercion(int *lista,int tam);

int tam,op,c,op1,i,op2,top,tinka,top1,n,j,r[100],ne[4][6],re=0,dn,numero_partidos,opa,tt,aux;

 int temporal[6];
	int ordenado[6];
float total,mul=1,cont=0,totala,gp;
void Generar_Dia()
{
    //Cargar equipos en arrat
    string arr_equ [NUM_EQU][2];
    lector_inicio("Equipos.txt",arr_equ);
    //cargar array en equipos
    Equipos.equipos = new equipo[NUM_EQU];
    for (int i = 0 ; i < NUM_EQU ; i++)
    {
        equipo p = {arr_equ[i][0],atof(arr_equ[i][0].c_str())};
        Equipos.equipos[i] = p;
    }
    int num_part = rand()%(NUM_EQU);
    Partidos_hoy.partidos = new partido[num_part] ;
    for (int i = 0 ; i < num_part ; i++)
    {
        int iesimo = rand() % NUM_EQU;
        int jesimo = iesimo;
        while (iesimo == jesimo)
            jesimo = rand() % NUM_EQU;

        partido q = {
            rand()%100 + 100*i,
            Equipos.equipos[iesimo],
            Equipos.equipos[jesimo],
            (float(rand()%300))/((float) 100),
            (float(rand()%300))/((float) 100),
            (float(rand()%300))/((float) 100),
        };
        Partidos_hoy.partidos[i] = q;
    }




}


int main()
{

    Generar_Dia();


	system("color 70");
	regPe=new registro[100];
	srand(time(NULL));
	Login();
	delete[] regPe;
	return 0;
}
//Estado 0
void Login()
{
	system("cls");
	int opcion;
	cout<<"\t\t\t ***Casa de apuestas*** \t\t\t"<<endl<<endl;
	cout<<"\t\t Inicio de sesion \t\t"<<endl<<endl;
	cout<<"\t 1.- Administrador"<<endl;
	cout<<"\t 2.- Asistente"<<endl<<endl;
	cout<<"\t Ingrese una opcion: ";
	cin>>opcion;
	opa = opcion;
	switch(opa)
	{
		case 1: system("cls");
            cuenta_actual.tipo = TIPO_ADM;
            if (Inicio("Administrador.txt","administrador"));
                Registrar_Partidos();
            break;
		case 2: system("cls");
            cuenta_actual.tipo = TIPO_CLI;
            if (Inicio("Cliente.txt","cliente"));
                mostrarp();
            break;
		default:
			system("cls");
			cout<<"\n\n\n\t\t\t Ingrese una opcion valida por favor!";
			espera();
			Login();
			break;
	}
}

bool Inicio(string ruta,string denominacion)
{
	int intentos = 3;
	string musuario,mclave;
	string arr[NUM_ADM][2];
	lector_inicio(ruta,arr);
	for (int i = 0; i < intentos ; i++)
    {
        system("cls");
		cout<<"\t\t\t ***INTRALOT*** \t\t\t"<<endl<<endl;
		cout<<"\t\t Inicio de Sesion del " + denominacion + " \t\t"<<endl<<endl;
		cout<<"\t 1.- Usuario: ";
		cin>>musuario;
		cout<<endl;
        cout<<"\t 2.- Clave: ";
        cin>>mclave;
        if (busqueda_inicio(musuario,mclave,arr))
            {
                cout<<"\t Bienvenido al sistema " + denominacion<<endl<<endl;
                cuenta_actual.usuario = musuario;
                cuenta_actual.clave = mclave;
                espera();
                return true;
            }
        cout<<"\t Usuario y/o claves son incorrectos"<<endl<<endl;
        espera();
    }
    cout<<"\t Ha excedido el numero maximo de intentos"<<endl<<endl;
    espera();
    Login();
    return false;

}
void Registrar_Partidos()
{
	system("cls");
	cout<<endl;
	int opcion;
	cout<<"\t Bienvenido " + cuenta_actual.usuario + "\n\t¿Que desea hacer?"<<endl<<endl;
    cout<<"\t 1.- Ver estadisticas de equipos"<<endl;
	cout<<"\t 2.- Ver resumen de ganancias"<<endl;
	cout<<"\t 3.- Ajustar valores de apuestas"<<endl;
	cout<<"\t 4.- Salir"<<endl;
	cin>>numero_partidos;
	cout<<endl;
	for(i=0;i<numero_partidos;i++)
	{
		cout<<"\t Partido Nro: "<<i+1<<endl;
		cout<<"\t Codigo: ";cin>>(regPe+i)->codigop;
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
	cout<<"\t Recaudaci�n de apuestas mayor a 499 soles por d�a -> Televisor para el local"<<endl;
	cout<<"\t Recaudaci�n de apuestas entre 400 y 499 soles por d�a -> Decoraci�n del local"<<endl;
	getch();
	Login();
}

void mostrarp()
{
	system("cls");
	cout<<"\t\t\t\t ***Tabla de partidos para apostar*** \t\t"<<endl<<endl;
	cout<<"Cod. Partido"<<"\t\t\t"<<"Partido"<<"\t\t\t"<<"Local"<<"\t"<<"Empate"<<"\t"<<"Visita"<<endl<<endl;
	for(i=0;i<numero_partidos;i++)
	{
		cout<<(regPe+i)->codigop<<"\t\t\t"<<(regPe+i)->partidol<<" vs "<<(regPe+i)->partidov<<"\t"<<(regPe+i)->cuotal<<"\t"<<(regPe+i)->cuotae<<"\t"<<(regPe+i)->cuotav<<endl;
	}
	getch();
	cout<<"Presione cualquier tecla para ir al men�";
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
	cout<<"Ingrese una opci�n: ";cin>>op;
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
			cout<<"Opci�n incorrecta, ingrese una opci�n valida por favor�";
			getch();
			menu();
	}
}
void registrar()
{
	regPe->codigoj=5+rand()%1250;
	regPe->fecha="11-12-19";
	cout<<"\t\t Casa de Apuestas \t\t"<<endl<<endl;;
	cout<<"Datos de la persona"<<endl<<endl;
	cout<<"C�digo de la jugada: "<<regPe->codigoj<<endl;
	cout<<"Nombre: ";fflush(stdin);getline(cin,regPe->nombre);
	cout<<"DNI: ";cin>>regPe->dni;
	cout<<"Fecha: "<<regPe->fecha<<endl;
	getch();
	menu();
}
void teapuesto()
{
	cout<<"\t\t\t Casa de Apuestas \t\t\t"<<endl<<endl;
	cout<<"\t\t Te apuesto \t\t"<<endl;
	cout<<"\t\t\t\t ***Tabla de partidos para apostar*** \t\t"<<endl<<endl;
	cout<<"Cod. Partido"<<"\t\t\t"<<"Partido"<<"\t\t\t"<<"Local"<<"\t"<<"Empate"<<"\t"<<"Visita"<<endl<<endl;
	for(i=0;i<numero_partidos;i++)
	{
		cout<<(regPe+i)->codigop<<"\t\t\t"<<(regPe+i)->partidol<<" vs "<<(regPe+i)->partidov<<"\t"<<(regPe+i)->cuotal<<"\t"<<(regPe+i)->cuotae<<"\t"<<(regPe+i)->cuotav<<endl;
	}
	cout<<endl<<endl;
	cout<<"Se�or "<<regPe->nombre<<" ingrese la cantidad de partidos a apostar: ";cin>>tam;
	cout<<endl;
	for(i=0;i<tam;i++)
	{
		do
		{
		cout<<endl;
		cout<<"Ingrese el c�digo del partido: ";cin>>(regPe+i)->codigopar;
		cout<<endl;
		if((regPe+i)->codigopar==(regPe+i)->codigop)
		{
			cout<<"El Partido es: "<<"\t\t\t"<<(regPe+i)->partidol<<" vs "<<(regPe+i)->partidov<<endl;
			cout<<"Seleccione una opci�n: "<<endl;
			cout<<"1) Local"<<endl;
			cout<<"2) Empate"<<endl;
			cout<<"3) Visita"<<endl<<endl;
			do
			{
				cout<<"Opcion: ";cin>>(regPe+i)->cuotao;
				switch((regPe+i)->cuotao)
				{
					case 1: (regPe+i)->opcionp="Local";(regPe+i)->cuotaf=(regPe+i)->cuotal;mul=mul*(regPe+i)->cuotal;break;
					case 2: (regPe+i)->opcionp="Empate";(regPe+i)->cuotaf=(regPe+i)->cuotae;mul=mul*(regPe+i)->cuotae;break;
					case 3: (regPe+i)->opcionp="Visita";(regPe+i)->cuotaf=(regPe+i)->cuotav;mul=mul*(regPe+i)->cuotav;break;
					default:
						cout<<"Ingrese una opci�n valida";
						getch();
				}
			}while((regPe+i)->cuotao!=1 && (regPe+i)->cuotao!=2 && (regPe+i)->cuotao!=3);
		}
		else
		{
			cout<<"El c�digo ingresado no existe"<<endl;
		}
		}while((regPe+i)->codigopar != (regPe+i)->codigop);
	}
	do
	{
		cout<<"Monto a apostar: ";cin>>regPe->multiplicador;
		if((regPe)->multiplicador<2)
		{
			cout<<endl;
			cout<<"La apuesta m�nima es de 2 soles."<<endl;
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
			cout<<"Se�or: "<<regPe->nombre<<endl;
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
					cout<<"N�mero "<<j+1<<" es: ";cin>>temporal[j];
					while(temporal[j]<0||temporal[j]>45){
						cout<<"Ingrese numero correcto"<<endl;
						cout<<"N�mero "<<j+1<<" es: ";cin>>temporal[j];
					}
				}
				ordenarporinsercion(temporal,6);
				for(int k=0;k<6;k++){
					ne[i][k]=temporal[k];
				}
				cout<<endl<<endl;
			}
			cout<<ne[i][j]<<" ";
			getch();latinka();break;

			case 2:system("cls");
			cout<<"Se�or: "<<regPe->nombre<<endl;
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
			getch();latinka();break;
		}
		case 3:
		getch();menu();break;
		default:
			system("cls");
			cout<<"Opci�n incorrecta, ingrese una opci�n valida por favor";getch();latinka();
	}
	getch();
	escribir2();
	menu();
}
void salir()
{
	cout<<"El programa ha terminado correctamente"<<endl;
	escribir();
	escribir2();
	escribir3();
	exit(0);
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
void escribir2( )
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
	numersalida<<"Estos son los n�meros ganadores: "<<endl;
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
	if(cont==1&&cont==2){
		numersalida<<"PERDIO"<<endl;
	}
	if(cont==3){
		cout<<"GANO!!"<<endl;
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
	resumen<<"Este es el resumen de ventas del d�a"<<endl<<endl;
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
	if(totala>=500)
	{
		resumen<<"Usted ha ganado un Televisor para su local";
	}
	else if(totala>400)
	{
		resumen<<"Usted ha ganado un decorado para su local";
	}
	else
	{
		resumen<<"Por el momento no hay premio";
	}
	gp=total*015+tt*025;
	resumen<<"Las ganancia obtenida es: "<<gp;

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
