#pragma once
#include<iostream>

enum Boolean{TRUE,FALSE};
struct Triple{int valor,row,col};

class Matrix;

class MatrixNode
{
	friend class Matrix;
	friend istream& operator>> (istream&, Matrix&); //Para leer en una matriz
	 
private:

	MatrixNode *up, *left;
	Boolean head;
	union { //Union anonima
		MatrixNode *next;
		Triple triple;
	};
	MatrixNode(Boolean, Triple*); //Constructor
};

