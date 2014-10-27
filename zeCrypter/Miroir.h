#pragma once
#include "cryptage.h"
class CMiroir :
	public CCryptage
{
public:
	CMiroir();
	virtual void initialiser(void * param);
	virtual string chiffrer(string decodee);
	virtual string dechiffrer(string codee);
	~CMiroir();
private:
	string mirroiter(string x);
};

