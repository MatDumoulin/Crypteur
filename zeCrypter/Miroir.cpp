#include "stdafx.h"
#include "Miroir.h"


CMiroir::CMiroir()
{
}


CMiroir::~CMiroir()
{
}

string CMiroir::chiffrer(string decodee)
{
	verifierInitialisation();
	return mirroiter(decodee);
	
}
string CMiroir::dechiffrer(string codee)
{
	verifierInitialisation();
	return mirroiter(codee);
}

string CMiroir::mirroiter(string x){
	int taille = x.length();
	int pivot;				// Représente le point central de la reflexion
	if (taille % 2 == 1)	// Si c'est impair
	{
		pivot = taille / 2;	// On place le pivot au centre de la chaine
	}
	else
	{
		pivot = (taille / 2) - 1;	// On soustrait un pour éviter qu'il coupe la derniere lettre lors de l'effet miroire
	}
	string temp = x;
	char swap = ' ';
	for (int i = 1; i <= pivot; ++i)
	{
		swap = temp[pivot + i];
		temp[pivot + i] = temp[pivot - i];
		temp[pivot - i] = swap;
	}
	return temp;
}

void CMiroir::initialiser(void * param)
{
	setInitialisation(true);
}