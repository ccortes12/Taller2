#include "stdafx.h"
#include "MatrixNode.h"

MatrixNode::MatrixNode(Boolean b, Triple *t) { //Constructor

	head = b;
		if (b) {
		left = next = up = this; // row/column head nodo
	}
	else triple = *t; //head nodo para la lista de nodos cabecera o elemento de nodo
}

