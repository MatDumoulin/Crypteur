#include "stdafx.h"
#include "cryptage.h"


CCryptage::CCryptage()
{
	estInitialisee = false;
}

void CCryptage::setInitialisation(bool flag){
	estInitialisee = flag;
}

bool CCryptage::getInitialisation(){
	return estInitialisee;
}

void CCryptage::verifierInitialisation()
{
	if (!getInitialisation())
	{
		throw "Vous n'avez pas initialise l'objet";
	}
}

CCryptage::~CCryptage()
{
}


