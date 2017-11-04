#pragma once
#include "Entidad.h"
class PisoFragil :
	public Entidad
{
public:
	PisoFragil(int fila, int columna) : Entidad(",", fila, columna) { habilitado(false); }
	~PisoFragil() {}

	void habilitado(bool a) { estado = (a); }


	bool isHabilitado() { return this->habilitado; }
	string tipo() { return this->tipoEntidad; }
	int fila() { return this->row; }
	int columna() { return this->col; }
private:
	bool estado;
};

