#pragma once
#include "Entidad.h"
class Piso :
	public Entidad
{
public:
	Piso(int fila, int columna) : Entidad(".", fila, columna) {} //Llama al constructor clase padre
	~Piso() {}
	string tipo() { return this->tipoEntidad; }
	int fila() { return this->row; }
	int columna() { return this->col; }
};

