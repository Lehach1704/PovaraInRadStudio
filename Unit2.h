//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Test : public TThread
{
private:
	TVirtualStringTree *stringTree;
	Iterator<CookerPtr> *iter;
    Cooker type;
	RaceCooker race;
	bool colorOfClothes;
  	bool wearingGlasses;
protected:
	void __fastcall Execute();
	void __fastcall UpdateProgress();
	void __fastcall MaxProgress();
public:
	__fastcall Test(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
