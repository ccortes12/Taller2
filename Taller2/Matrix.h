#pragma once
#include"MatrixNode.h"

typedef MatrixNode *MatrixNodePtr; //Permite la subsecuente creacion del arreglo de punteros

class Matrix
{
	friend istream& operator>>(istream&, Matrix&);
public:
	~Matrix();
private:
	MatrixNode *headnode;
};

