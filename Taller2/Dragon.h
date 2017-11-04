#pragma once
#include "Entidad.h"
class Dragon :
	public Entidad
{
public:
	Dragon(int fila, int columna) : Entidad("B", fila, columna) {};
	~Dragon();
	//Sobreescribe el metodo de la clase animal
	string tipo() { return this->tipoEntidad; }
	int fila() { return this->row; }
	int columna() { return this->col; }
};

