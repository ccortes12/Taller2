#include "stdafx.h"
#include "Util.h"
#include<iostream>

int menuPrincipal()
{
	int opcion;
	do {
		cout << "1. Nuevo juego\n2.Configuracion\n3.Salir" << endl;
		cin >> opcion;
	} while ((opcion < 1 || opcion >3));
	return opcion;
}

int menuConfiguracion()
{
	int opcion;
	do {
		cout << "1. Tama�o de mapa\n2.Cantidad de entidades\n3.Tama�o pasos" << endl;
		cin >> opcion;
	} while (opcion < 1 || opcion < 3);
	return opcion;
}


