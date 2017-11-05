#pragma once
#include "NodoMatrix.h"
#include <istream>

class SparseMatrix {

public:
	SparseMatrix(int filas, int columnas);
	//SparseMatrix(int MaxRow,int MaxCol);

	NodoMatrix* getNodoCabecera();

	void insertar(string dato, int fil, int col);
	void imprimirMatriz();
	string operator[](int x);
	void eliminar(int fila, int col);
	void mover(int fila1, int col1, int fila2, int col2);
	NodoMatrix**row;
	NodoMatrix**col;


	~SparseMatrix();

private:


	NodoMatrix* nodoCabecera;


};


