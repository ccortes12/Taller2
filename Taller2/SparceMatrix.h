#pragma once
class SparceMatrix
{
public:
	SparceMatrix();//Constructor vacio
	SparceMatrix(int filas, int columnas);//SparseMatrix(int maxRow, int maxCol)
	~SparceMatrix();

	NodoMatrix* getNodoCabecera();

	void insertar(string dato, int fila, int col);
	void imprimirMatriz();
	string operator[](int x);
	void eliminar(int fila, int col);
	void mover(int fila1, int col1, int fila2, int col2);

	NodoMatrix**row;
	NodoMatrix**col;

private:

	NodoMatrix* nodoCabecera;
	
};

