#pragma once
#include "Entidad.h"

class Jugador :
	public Entidad
{
public:
	Jugador() : Entidad("@", 0, 0) { flagEspada(false); }//Llama al constructor clase padre
	~Jugador() {}
	void flagEspada(bool a) { espada=a; }
	bool isEspada() { return this->espada; }
	//Sobreescribe el metodo de la clase animal
	string tipo() { return this->tipoEntidad;}
	int fila() { return this->row; }
	int columna() { return this->col; }

private:
	bool espada;
};

