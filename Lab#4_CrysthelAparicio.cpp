#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <string.h>

using namespace std;
char alf[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void fechas();
void agregarFecha();
int stringAInt(string);
void listarFechas(bool);
void listarFechasConsulta();
void listarAnioEspecifico(string);
void listarMesEspecifico(string);
void listarDiaEspecifico(string);
string oracionFecha(string);
int calcularDia(int, int, int);

////////////////////////
void cifrado_playfair();
void descifrado_playfair();
void acomodar_mensaje (char,char);
void llenar_matriz(char,char);
int esta_matriz (char,char);

//////////////////////
void imprimirMatriz(int***, int, int);
void Ruffini();
int*** crearMatriz(int);


const int DOMINGO    = 0;
const int LUNES      = 1;
const int MARTES     = 2;
const int MIERCOLES  = 3;
const int JUEVES     = 4;
const int VIERNES    = 5;
const int SABADO     = 6;

const string ENERO      = "01";
const string FEBRERO    = "02";
const string MARZO      = "03";
const string ABRIL      = "04";
const string MAYO       = "05";
const string JUNIO      = "06";
const string JULIO      = "07";
const string AGOSTO     = "08";
const string SEPTIEMBRE = "09";
const string OCTUBRE    = "10";
const string NOVIEMBRE  = "11";
const string DICIEMBRE  = "12";

vector<string> baseFechas;

int main()
{
	int opc,opc2;
        int opcion = -1;
        int n;
        int* arr = NULL;
        string userInput;
        do
        {
                cout << "\nMENU:\n"
                        << "1) Ejercicio 1\n"
                        << "2) Ejercicio 2\n"
                        << "3) Ejercicio 3\n"
                        << "0) Salir\n"
                        << "Seleccione una opcion: ";
                cin >> opcion;
                switch (opcion)
                {
                        case 1:
                          fechas();
                                break;
                        case 2:
                            Ruffini();
                                break;
                        case 3:
                           do{	
						cout<<"Cifrado"<<endl;
						cout<<"1.- Cifrar"<<endl;
						cout<<"2.- Descrifrar"<<endl;
						cout<<"3.- Salir"<<endl;
						cout<<"Ingrese Opcion:";
						cin>>opc2;
						switch(opc2){
							case 1:  cifrado_playfair();
								break; 
							case 2:  descifrado_playfair();
								break; 
						}
					}while(opc2!=3);
					system("cls");		                               
                                break;
                        case 0:
                                if (arr != NULL)
  			        {
                                        delete[] arr;
                                        arr = NULL;
                                }
                                cout << "Saliendo..." << endl;
                                break;
                        default:
                                cout << "Opcion no valida!" << endl;
                                break;
                }
        }
        while(opcion != 0);
        return 0;
}

/// E J E R C I C I O 1 ///
void fechas()
{
        
        int opcion = -1;
        do
        {
                cout << "\nMENU FECHAS:\n"
                        << "1) Agregar fecha\n"
                        << "2) Ver una Fecha\n"
                        << "3) Ordenar una Fecha\n"
                        << "4) Consultar una fecha\n"
                        << "0) Volver\n"
                        << "Seleccione una opcion: ";
                cin >> opcion;
                switch (opcion)
                {
                        case 1:
                                agregarFecha();
                                break;
                        case 2:
                                listarFechas(false);
                                break;
                        case 3:
                                listarFechas(true);
                                break;
                        case 4:
                                listarFechasConsulta();
                                break;
                        case 0:
                                break;
                        default:
                                cout << "Opcion no valida!" << endl;
                                break;
                }
        }
        while(opcion != 0);
}

void agregarFecha()
{
        string fecha;
        string year;
        string month;
        string day;
        string maximo = "20180209";
        int yearInt;
        int monthInt;
        int dayInt;
        bool bisiesto;
        do
        {
                cout << "Ingrese la fecha en formado YYYYMMDD: ";
                cin >> fecha;

                if (fecha.length() != 8)
                        continue;

                year = fecha.substr(0, 4);
                month = fecha.substr(4, 2);
                day = fecha.substr(6, 2);

                yearInt = stringAInt(year);
                monthInt = stringAInt(month);
                dayInt = stringAInt(day);

                if (monthInt > 12 || monthInt <= 0)
                        continue;

                // comprobar febrero
                bisiesto = yearInt % 4 == 0;
                if (bisiesto && month == FEBRERO && dayInt > 29)
                        continue;
                else if(!bisiesto && month == FEBRERO && dayInt > 28)
                        continue;
                // comprobar todos los otros meses
                else if (month == ENERO && dayInt > 31)
                        continue;
                else if (month == MARZO && dayInt > 31)
                        continue;
                else if (month == ABRIL && dayInt > 30)
                        continue;
                else if (month == MAYO && dayInt > 31)
                        continue;
                else if (month == JUNIO && dayInt > 30)
                        continue;
                else if (month == JULIO && dayInt > 31)
                        continue;
                else if (month == AGOSTO && dayInt > 31)
                        continue;
                else if (month == SEPTIEMBRE && dayInt > 30)
                        continue;
                else if (month == OCTUBRE && dayInt > 31)
                        continue;
                else if (month == NOVIEMBRE && dayInt > 30)
                        continue;
                else if (month == DICIEMBRE && dayInt > 31)
                        continue;

                if (fecha > maximo)
                        continue;

                // fecha es valida
                break;
        }
        while(true);
        baseFechas.push_back(fecha);
}

int stringAInt(string cadena)
{
        int resultado;
        stringstream out(cadena);
        if (!(out >> resultado))
                resultado = 0;
        return resultado;
}

void listarFechas(bool ordenado)
{
        if (ordenado)
        {
                vector<string> tempFechas = baseFechas;
                // ordenar vector tempFechas
                sort(tempFechas.begin(), tempFechas.end());
                for (int i = 0; i < tempFechas.size(); i++)
                        cout << oracionFecha(tempFechas.at(i)) << endl;
        }
        else
        {
                for (int i = 0; i < baseFechas.size(); i++)
                        cout << oracionFecha(baseFechas.at(i)) << endl;
        }
}

string oracionFecha(string fecha)
{
        string year = fecha.substr(0, 4);
        string month = fecha.substr(4, 2);
        string day = fecha.substr(6, 2);

        int yearInt = stringAInt(year);
        int monthInt = stringAInt(month);
        int dayInt = stringAInt(day);
        string resultado;

        // calcular dia de semana
        int diaSemana = calcularDia(yearInt, monthInt, dayInt);
        if (diaSemana == DOMINGO)
                resultado += "Domingo, ";
        else if (diaSemana == LUNES)
                resultado += "Lunes, ";
        else if (diaSemana == MARTES)
                resultado += "Martes, ";
        else if (diaSemana == MIERCOLES)
                resultado += "Miercoles, ";
        else if (diaSemana == JUEVES)
                resultado += "Jueves, ";
        else if (diaSemana == VIERNES)
                resultado += "Viernes, ";
        else if (diaSemana == SABADO)
                resultado += "Sabado, ";

        resultado += day;
        resultado += " de ";
 if (month == ENERO)
                resultado += "enero del ";
        else if (month == FEBRERO)
                resultado += "febrero del ";
        else if (month == MARZO)
                resultado += "marzo del ";
        else if (month == ABRIL)
                resultado += "abril del ";
        else if (month == MAYO)
                resultado += "mayo del ";
        else if (month == JUNIO)
                resultado += "junio del ";
        else if (month == JULIO)
                resultado += "julio del ";
        else if (month == AGOSTO)
                resultado += "agosto del ";
        else if (month == SEPTIEMBRE)
                resultado += "septiembre del ";
        else if (month == OCTUBRE)
                resultado += "octubre del ";
        else if (month == NOVIEMBRE)
                resultado += "noviembre del ";
        else if (month == DICIEMBRE)
                resultado += "diciembre del ";

        resultado += year;
        return resultado;
}

int calcularDia(int year, int month, int day)
{
        int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
        year -= month < 3;
        return (year + year/4 - year/100 + year/400 + t[month - 1] + day) % 7;
}

void listarFechasConsulta()
{
        int opcion = -1;
        string year;
        string month;
        string day;
        do
        {
                cout << "\nMENU CONSULTA DE FECHAS:\n"
                        << "1) Anio especifico\n"
                        << "2) Mes especifico\n"
                        << "3) Dia especifico\n"
                        << "0) Volver\n"
                        << "Seleccione una opcion: ";
                cin >> opcion;
                switch (opcion)
                {
                        case 1:
                                year = "";
                                cout << "Ingrese el anio que desea ver (eg 2012, 1990...): ";
                                cin >> year;
                                listarAnioEspecifico(year);
                                break;
                        case 2:
                                month = "";
                                cout << "[CaSe-SeNsItIvE] Ingrese el mes que desea ver (eg enero, febrero...): ";
                                cin >> month;
                                listarMesEspecifico(month);
                                break;
                        case 3:
                                day = "";
                                cout << "[CaSe-SeNsItIvE] Ingrese el dia que desea ver (eg lunes, viernes): ";
                                cin >> day;
                                listarDiaEspecifico(day);
                                break;
                        case 0:
                                break;
                        default:
                                cout << "Opcion no valida!" << endl;
                                break;
                }
        }
        while(opcion != 0);
}

void listarAnioEspecifico(string year)
{
        string tempYear;
        for (int i = 0; i < baseFechas.size(); i++)
        {
                tempYear = baseFechas.at(i).substr(0, 4);
                if (tempYear == year)
                        cout << oracionFecha(baseFechas.at(i));
                else
                        continue;
                cout << endl;
        }
        cout << endl;
}

void listarMesEspecifico(string month)
{
        string tempMonth;
        if (month == "enero")
                month = ENERO;
        else if (month == "febrero")
                month = FEBRERO;
        else if (month == "marzo")
                month = MARZO;
        else if (month == "abril")
                month = ABRIL;
        else if (month == "mayo")
                month = MAYO;
        else if (month == "junio")
                month = JUNIO;
        else if (month == "julio")
                month = JULIO;
        else if (month == "agosto")
                month = AGOSTO;
        else if (month == "septiembre")
                month = SEPTIEMBRE;
        else if (month == "octubre")
                month = OCTUBRE;
        else if (month == "noviembre")
                month = NOVIEMBRE;
        else if (month == "diciembre")
                month = DICIEMBRE;

        for (int i = 0; i < baseFechas.size(); i++)
        {
                tempMonth = baseFechas.at(i).substr(4, 2);
                if (tempMonth == month)
                        cout << oracionFecha(baseFechas.at(i));
                else
                        continue;
                cout << endl;
        }
        cout << endl;
}

void listarDiaEspecifico(string day)
{
        int tempYear;
        int tempMonth;
        int tempDay;
        int dayInt;

        if (day == "domingo")
                dayInt = DOMINGO;
        else if (day == "lunes")
                dayInt = LUNES;
        else if (day == "martes")
                dayInt = MARTES;
        else if (day == "miercoles")
                dayInt = MIERCOLES;
        else if (day == "jueves")
                dayInt = JUEVES;
        else if (day == "viernes")
                dayInt = VIERNES;
        else if (day == "sabado")
                dayInt = SABADO;

        for (int i = 0; i < baseFechas.size(); i++)
        {
                tempYear = stringAInt(baseFechas.at(i).substr(0, 4));
                tempMonth = stringAInt(baseFechas.at(i).substr(4, 2));
                tempDay = stringAInt(baseFechas.at(i).substr(6, 2));

                if (dayInt == calcularDia(tempYear, tempMonth, tempDay))
                        cout << oracionFecha(baseFechas.at(i));
                else
                        continue;
                cout << endl;
        }
        cout << endl;
}

///// E J E R C I C I O 2 ////

void Ruffini(){

        int grado_alto = 0;
        int a = 0;
        int*** matriz = NULL;
        int values = 0;
        cout<<"Escriba del polinomio el nivel MAS ALTO!: "<<endl;
        cin>>grado_alto;
        int pa = pa+1;
        cout<<"Escriba un valor para a: "<<endl;
        cin>>a;
        matriz = crearMatriz(pa);

        for(int i = 0; i<pa; i++){
                cout<<"Escriba un valor para nuestra casilla X'"<<i<<": "<<endl;
                cin>>values;
                matriz[0][0][i] = values;
                values = 0;
        }
        for(int i = 0; i < pa; i++){
                for(int j = 0; j <pa; j++){
                        matriz[i][0][j] = matriz[0][0][j];
                        matriz[i][2][0] = matriz[0][0][0];
                }
        }
        for(int i = 0; i <pa; i++ ){
                for(int j=0; j<3; j++){
                        for(int k = 0; k<pa; k++){
                                matriz[i][1][k+1] = matriz[i][2][k]*a;
                                matriz[i][2][k+1] = matriz[i][0][k+1]+matriz[i][1][k+1];
                        }

                }
        }
        imprimirMatriz(matriz, pa, a);
}

int*** crearMatriz (int n){
        int*** matriz = new int **[n];
        for(int i = 0; i <n; i++ ){
                matriz[i] = new int*[3];
        }
        for(int i = 0; i < n; i++){
                for(int j =0; j<3; j++){
                        matriz[i][j] = new int [n];
                }
        }
return matriz;
}

void imprimirMatriz(int *** matriz, int a, int poli){
        for(int i = 0; i <poli; i++ ){
                for(int j = 0; j<3; j++){
                                for(int k=0; k<poli; k++){
                                        cout<<"[ "<<matriz[i][j][k]<<" ]";
                                }
                                cout<<"|"<<a<<endl;
                }
                cout<<endl;
        }
}

///// E J E R C I C I O 3 ////
int esta_matriz (char letra,char matriz[5][5]){
    for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
            if(letra == matriz[i][j]){
                  return 1;
            }
       }
    }
    return -1;
}

void llenar_matriz(char clave[],char matriz[5][5]){
    int fila=0;
    int columna=0;
    int aux;
    for(int i=0;i<strlen(clave);i++){
         aux=esta_matriz(clave[i],matriz);
         if(aux==-1&&clave[i]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
              }
		        matriz[fila][columna]=clave[i];
		        columna++;
         }            
    }
    for(int j=0;j<strlen(alf);j++){
        aux=esta_matriz(alf[j],matriz); 
        if(aux==-1&&alf[j]!=106){
              if(columna==5){
                  fila++;
                  columna=0;
              }
		        matriz[fila][columna]=alf[j];
		        columna++;
         }   
    } 
}

void acomodar_mensaje (char m2[],char m[]){
	int j=0;
	for(int i=0;i<strlen(m);i++){		
		if(m[i]!=32){
		   m2[j]=m[i];
		   j++;
		}
	}
	m2[j]='\0';
	//cout<<m2<<endl;
		
	int i=0;
	j=1;
	while(j<=strlen(m2)){
		if(m2[i]==m2[j]){
			for(int k=strlen(m2)+1;k>j;k--){
				m2[k]=m2[k-1];
			}
			m2[j]='x';
		}
		i=i+2;
		j=j+2;
	}
	
	if(strlen(m2)%2!=0){
		m2[strlen(m2)+1]='\0';
		m2[strlen(m2)]='x';		
	}
	//cout<<m2<<endl;
	//cout<<strlen(m2)<<endl;
}


void cifrado_playfair(){
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a cifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	char matriz[5][5];
	for(int i=0;i<5;i++)
	 for(int j=0;j<5;j++)
	   matriz[i][j]='\0';
	
	llenar_matriz(clave,matriz);
////
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<matriz[i][j];
			if(j==4){
				cout<<endl;
			}
		}
	}
////
	fflush(stdin);
	char m2[100];
	acomodar_mensaje(m2,m);
		
	int i=0;
	int j=1;
	while(j<=strlen(m2)){	
		int fila1,fila2,columna1,columna2;
		if(m2[i]=='j'){
			m2[i]='i';
		}
		if(m2[j]=='j'){
			m2[j]='i';
		}
		for(int x=0;x<5;x++){
			for(int y=0;y<5;y++){
				if(m2[i]==matriz[x][y]){
					fila1=x;
					columna1=y;
				}
				if(m2[j]==matriz[x][y]){
					fila2=x;
					columna2=y;
				}
			}
		}
		if(fila1==fila2){
			m2[i]=matriz[fila1][(columna1+1)%5];
			m2[j]=matriz[fila1][(columna2+1)%5];
		}
		else if(columna1==columna2){
			m2[i]=matriz[(fila1+1)%5][columna1];
			m2[j]=matriz[(fila2+1)%5][columna1];
		}
		else{
			m2[i]=matriz[fila1][columna2];
			m2[j]=matriz[fila2][columna1];
		}
		i=i+2;
		j=j+2;
	}
	cout<<"El mensaje cifrado es:";
	for(int i=0;i<strlen(m2);i++){
		cout<<m2[i];
		if(i%2!=0){
			cout<<" ";
		}
	}
	cout<<endl<<endl;

}

void descifrado_playfair(){
	char m[100];
	char clave[100];
	fflush(stdin);
	cout<<"Ingrese mensaje a descifrar:";
	cin.getline(m,100);
	fflush(stdin);
	cout<<"Ingrese clave:";
	cin.getline(clave,100);
	char matriz[5][5];
	for(int i=0;i<5;i++)
	 for(int j=0;j<5;j++)
	   matriz[i][j]='\0';
	
	llenar_matriz(clave,matriz);
	
	fflush(stdin);
	char m2[100];
	
	int p=0;
	for(int q=0;q<strlen(m);q++){		
		if(m[q]!=32){
		   m2[p]=m[q];
		   p++;
		}
	}
	m2[p]='\0';
	
	int i=0;
	int j=1;
	while(j<=strlen(m2)){	
		int fila1,fila2,columna1,columna2;
		if(m2[i]=='j'){
			m2[i]='i';
		}
		if(m2[j]=='j'){
			m2[j]='i';
		}
		for(int x=0;x<5;x++){
			for(int y=0;y<5;y++){
				if(m2[i]==matriz[x][y]){
					fila1=x;
					columna1=y;
				}
				if(m2[j]==matriz[x][y]){
					fila2=x;
					columna2=y;
				}
			}
		}
		if(fila1==fila2){
			if((columna1-1)<0){
				m2[i]=matriz[fila1][4];
			}
			else{
				m2[i]=matriz[fila1][columna1-1];
			}
			if((columna2-1)<0){
				m2[j]=matriz[fila1][4];
			}
			else{
				m2[j]=matriz[fila1][columna2-1];
			}		
		}
		else if(columna1==columna2){
			if((fila1-1)<0){
				m2[i]=matriz[4][columna1];
			}
			else{
				m2[i]=matriz[fila1-1][columna1];	
			}
			if((fila2-1)<0){
				m2[j]=matriz[4][columna2];
			}
			else{
				m2[j]=matriz[fila2-1][columna2];	
			}
		}
		else{
			m2[i]=matriz[fila1][columna2];
			m2[j]=matriz[fila2][columna1];
		}
		i=i+2;
		j=j+2;
	}
	cout<<"El mensaje descifrado es:";
	for(int i=0;i<strlen(m2);i++){
		cout<<m2[i];
		if(i%2!=0){
			cout<<" ";
		}
	}
	cout<<endl<<endl;
}
