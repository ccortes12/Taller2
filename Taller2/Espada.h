#pragma once
#include "Entidad.h"
class Espada :
	public Entidad
{
public:
	Espada(int fila, int columna) : Entidad("S", fila, columna) {};
	~Espada();
	//Sobreescribe el metodo de la clase animal
	string tipo() { return this->tipoEntidad; }
	int fila() { return this->row; }
	int columna() { return this->col; }
};

