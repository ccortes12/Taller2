#pragma once
#include<string>

using namespace std;

class Entidad
{
public:
	Entidad() {} //Constructor vacio
	Entidad(string tipo, int fila, int columna) : tipoEntidad(tipo), row(fila), col(columna) {} //Constructor con parametrox
	virtual ~Entidad() {} //Destructor virtualx

	//Funcion pure virtual (se define en clases hijas)
	virtual string tipo() = 0;
	virtual int fila() = 0;
	virtual int columna() = 0;

protected:
	string tipoEntidad; //Parametro
	int row;
	int col;
};


