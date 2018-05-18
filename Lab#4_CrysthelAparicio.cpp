#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

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
                          
                                break;
                        case 2:
                              
                                break;
                        case 3:
                                fechas();                               
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
        // validas que no ingrese dias que no han pasado aun
        // validar bisiestosa
        // listar como oracion
        int opcion = -1;
        do
        {
                cout << "\nMENU FECHAS:\n"
                        << "1) Agregar fecha\n"
                        << "2) Listar todo\n"
                        << "3) Listar ordenado\n"
                        << "4) Listar por consulta\n"
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



///// E J E R C I C I O 3 ////


