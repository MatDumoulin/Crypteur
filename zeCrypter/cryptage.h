#pragma once
#include <string>
using namespace std;
class CCryptage
{
public:
	CCryptage();
	virtual void initialiser(void * param = "default") =0;
	virtual string chiffrer(string decodee)= 0;
	virtual string dechiffrer(string codee)= 0;
	~CCryptage();
protected:
	void setInitialisation(bool flag);
	bool getInitialisation();
	void verifierInitialisation();
private:
	bool estInitialisee;
};

