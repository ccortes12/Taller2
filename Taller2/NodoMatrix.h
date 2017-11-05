#pragma once
#include<istream>
#include <string>
using namespace std;


struct Triple {
	int row;
	int col;
	string value;
};

class NodoMatrix {

	friend class SparseMatrix;

public:
	NodoMatrix();
	NodoMatrix(bool b, Triple* t);

	NodoMatrix* getLeft();
	Triple getTriple();
	NodoMatrix* getUp();
	int getCol();
	int getRow();
	string getValue();
	void setUp(NodoMatrix* down);
	void setLeft(NodoMatrix* right);
	NodoMatrix& operator=(const NodoMatrix& nodo);

	~NodoMatrix();

private:

	NodoMatrix * up, *left;
	bool head;
	union { Triple triple; };

};
