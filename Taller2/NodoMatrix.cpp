#include "stdafx.h"
#include "NodoMatrix.h"


NodoMatrix::NodoMatrix()
{
}

NodoMatrix::NodoMatrix(bool b, Triple * t)
{
	this->head = b;
	if (b) {
		this->left = this;
		this->up = this;
		this->triple = *t;
	}
	else {
		this->triple = *t;
	}
}

NodoMatrix * NodoMatrix::getLeft()
{
	return this->getLeft;
}

Triple NodoMatrix::getTriple()
{
	return this->triple;
}

NodoMatrix * NodoMatrix::getUp()
{
	return this->up;
}

int NodoMatrix::getCol()
{
	return this->triple.col;
}

int NodoMatrix::getRow()
{
	return this->triple.row;
}

string NodoMatrix::getValue()
{
	return this->triple.value;
}

void NodoMatrix::setUp(NodoMatrix * down)
{
	this->up = down;
}

void NodoMatrix::setLeft(NodoMatrix * right)
{
	this->left = right;
}

NodoMatrix & NodoMatrix::operator=(const NodoMatrix & nodo)
{
	// TODO: insertar una instrucción return aquí
	this->head = nodo.head;
	this->left = nodo.left;
	this->up = nodo.up;
	this->triple = nodo.triple;
	return *this;
}


NodoMatrix::~NodoMatrix()
{
	delete up;
	delete left;

}
