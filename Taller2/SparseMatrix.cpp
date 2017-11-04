#include "stdafx.h"
#include "SparseMatrix.h"
#include "NodoMatrix.h"
#include<iostream>

SparseMatrix::SparseMatrix(int filas, int columnas) {

	this->row = new NodoMatrix*[filas];
	this->col = new NodoMatrix*[columnas];
	Triple head;

	head.row = filas;
	head.col = columnas;
	head.value = "";
	this->nodoCabecera = new NodoMatrix(true, &head);

	//por filas
	int i;
	for (i = 0; i <= filas; i++) {

		if (i == 0) {

			this->row[i] = NULL;

		}
		else {

			Triple T;
			T.row = i;
			T.col = 0;
			T.value = "";

			NodoMatrix* nodo = new NodoMatrix(true, &T);
			this->row[i] = nodo;
			//cout << "AROW -> row: " <<this->row[i]->getTriple().row << endl;
			//cout << "AROW -> col: "<<this->row[i]->triple.col << endl;
			//cout << "--------------------------------------------------" << endl;
		}
	}

	//por columnas
	int j;
	for (j = 0; j <= columnas; j++) {

		if (j == 0) {

			this->col[j] = NULL;

		}
		else {

			Triple t;
			t.row = 0;
			t.col = j;
			t.value = "";

			NodoMatrix* nodo = new NodoMatrix(true, &t);
			this->col[j] = nodo;
			//cout << "ACOL -> col : " << this->col[j]->triple.col << endl;
			//cout << "ACOL -> row : " << this->col[j]->triple.row << endl;
			//cout << "--------------------------------------------------" << endl;


		}


	}



}


NodoMatrix* SparseMatrix::getNodoCabecera() {

	return this->nodoCabecera;

}

void SparseMatrix::insertar(string dato, int fil, int col) {

	Triple t;
	t.row = fil;
	t.col = col;
	t.value = dato;

	NodoMatrix* nodo = new NodoMatrix(false, &t);

	NodoMatrix* aux = this->row[fil]->left;

	while (aux->left->triple.col > col) {

		aux = aux->left;

	}

	if (aux->left->triple.col == col) {

		cout << "celda ocupada!!!!" << endl;
		return;
	}
	else {

		aux = this->row[fil];

		while (aux->left->triple.col > col) {

			aux = aux->left;
		}

		nodo->left = aux->left;
		aux->left = nodo;

		aux = this->col[col];

		while (aux->up->triple.row > fil) {

			aux = aux->up;

		}

		nodo->up = aux->up;
		aux->up = nodo;

	}
}

void SparseMatrix::imprimirMatriz() {

	int filas = this->nodoCabecera->triple.row;

	for (int i = 1; i <= filas; i++) {

		NodoMatrix* aux = this->row[i]->left;
		cout << " NODO; FILA:  " << aux->triple.row << "COL : " << aux->triple.col << " VALUE: " << aux->triple.value << endl;

		while (aux->triple.col > 0) {

			aux = aux->left;
			cout << " NODO; FILA:  " << aux->triple.row << "COL : " << aux->triple.col << " VALUE: " << aux->triple.value << endl;

		}


	}

}
string SparseMatrix::operator[](int x) {

	return string();

}

void SparseMatrix::eliminar(int fila, int col) {

	NodoMatrix* aux = this->row[fila];
	NodoMatrix* ant = aux->left;

	while (aux->left->triple.col > col) {

		aux = ant;
		ant = ant->left;

	}

	aux->left = ant->left;

	NodoMatrix* auxCol = this->col[col];
	NodoMatrix* antCol = auxCol->up;

	while (aux->up->triple.row > fila) {

		aux = antCol;
		antCol = antCol->up;
	}

	auxCol->up = antCol->up;



}

void SparseMatrix::mover(int fila1, int col1, int fila2, int col2) {


	NodoMatrix* aux = this->row[fila1];

	while (aux->left->triple.col > col1) {

		aux = aux->left;

	}

	NodoMatrix* aux2 = this->row[fila2];

	while (aux2->left->triple.col > col2) {

		aux2 = aux2->left;

	}

	NodoMatrix* auxiliar = new NodoMatrix();

	auxiliar->triple.value = aux->left->triple.value;
	aux->left->triple.value = aux2->left->triple.value;
	aux2->left->triple.value = auxiliar->triple.value;



}

SparseMatrix::~SparseMatrix() {


}

/*istream& operator>>(istream& is, SparseMatrix& matrix) {

Triple s;
is >> s.row >> s.col >> s.value;
int p;
if (s.col > s.row) { p = s.col; }
if (s.col < s.row) { p = s.row; }
matrix.nodoCabecera = new NodoMatrix(false,&s);

if (p == 0) {

matrix.nodoCabecera->right = matrix.nodoCabecera;
return is;
}
NodoMatrix** head = new NodoMatrix*[p];

for (int i = 0; i < p; i++) {

head[i] = new NodoMatrix(true,0);
}
int filaActual = 0;
NodoMatrix* last = head[0];

for (int i = 0; i < s.value; i++) {

Triple t;
is >> t.row >> t.col >> t.value;
if (t.row > filaActual) {
last->right = head[filaActual];
filaActual = t.row;
last = head[filaActual];
}
last = last->right = new NodoMatrix(false,&t);
head[t.col]->next = head[t.col]->next->down = last;
}

last->right = head[filaActual];
for (int i = 0; i < s.col; i++) {
head[i]->next->down = head[i];
}

for (int i = 0; i < s.col; i++) {

head[i]->next->down = head[i];
}

for (int i = 0; i < p - 1; i++ ) {
head[i]->next = head[i+1];

}
head[p - 1]->next = matrix.nodoCabecera;
matrix.nodoCabecera->right = head[0];
delete[] head;
return is;

}

*/