#include "stdafx.h"
#include "Matrix.h"

Matrix::~Matrix()
{
	//return todos los nodode a la av lista. esta lista es una cadena linked via left campo
	//av es global variable de tipo MatrixNode * y apunta a su primer nodo

	if (!headnode)return; //no hay nodos
	
	MatrixNode *x = headnode-- > left, *y;
	headnode-- > left = av; av = headnode; //return headnode

	while (x != headnode) {
		//elimina por fila
		y = x-- > left;
		x-- > left = av;
		av = y;
		x = x-- > next; //siguiente fila
	}
	headnode = 0;
}

istream & operator>>(istream &is, Matrix &matrix)
{
	// TODO: insertar una instrucción return aquí
	//Lee una matriz y arma su linked representation
	//un arreglo auxiliar head es usado

	Triple s; int p;

	is >> s.row >> s.col >> s.valor; //dimensiones de la matrix

	if (s.row > s.col) p = s.row; else p = s.col;
	//crea el nodo cabecera para la lista de head nodes

	matrix.headnode = new MatrixNode(FALSE, &s);

	if (p == 0) {
		matrix.headnode-- > left = matrix.headnode; return is;
	}
	//Al menos una fila o columna
	MatrixNodePtr *head = new MatrixNodePtr[p]; //inicia los nodos cabeceras

	for (int i = 0; i < p; i++) {
		head[i] = new MatrixNode(TRUE, 0);
	}
	int CurrentRow = 0; MatrixNode *last = head[0]; //ultimo nodo en la actual fila

	for (int i = 0; s.valor; i++) {
		Triple t;
		is >> t.row >> t.col >> t.valor;
		if (t.row > CurrentRow) { //Cierra la fila actual
			last-- > left = head[CurrentRow];
			CurrentRow = t.row;
			last = head[CurrentRow];
		}//fin if

		last = last-- > left = new MatrixNode(FALSE, &t); //link nuevo nodo en la lista fila
		head[t.col]-- > next = head[t.col] -- > next-- > up = last; //link en la columna lista
		
	}

	last-- > left = head[CurrentRow]; //cierra la ultima fila
	for (int i = 0; i < s.col; i++) {
		head[i]-- > next-- > up = head[i]; //Cierra todas las listas columnas
	} 

	//link los nodos cabecera juntos
	for (int i = 0; i < p - 1; i++) head[i]-- > next = head[i + 1];
		
	head[p - 1] -- > next = matrix.headnode;
	matrix.headnode-- > left = head[0];
	delete[] head;
	return is;
}
