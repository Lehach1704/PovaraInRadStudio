//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "sqlite3.h"
#include "povara.h"
#include "Patterns.h"
#include "BDBDBD.h"
#include "Unit1.h"
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall Test::Test(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	FreeOnTerminate = true;
}
//---------------------------------------------------------------------------
void __fastcall Test::UpdateProgress()
{
	Form1->ProgressBar1->Position += 1;
}
//---------------------------------------------------------------------------
void __fastcall Test::MaxProgress()
{
	Form1->ProgressBar1->Position = Form1->ProgressBar1->Max;
}
//---------------------------------------------------------------------------
wstring PrintCookerType(const Cooker type) // описание типа повара
{
	switch(type)
	{
		case Cooker::Mousee: return L"Мышь";
		case Cooker::Cat: return L"Кот";
		case Cooker::Robot: return L"Робот";
		case Cooker::WheelchairUser: return L"Колясочник";
		default: return L"Неизвестно";
	}
}
//---------------------------------------------------------------------------
wstring PrintRaceCookerType(const RaceCooker race) // описание расы повара
{
	switch(race)
	{
		case RaceCooker::African: return L"Негроид";
		case RaceCooker::European: return L"Европеец";
		case RaceCooker::Asian: return L"Азиат";
		default: return L"Неизвестно";
	}
}
//---------------------------------------------------------------------------
void __fastcall Test::Execute()
{
	const CookerPtr outCook = iter->CurrentItem();

    stringTree->BeginUpdate();

	PVirtualNode entryNode = stringTree->AddChild(stringTree->RootNode);

	NodeStruct *nodeData = (NodeStruct*)stringTree->GetNodeData(entryNode);

	nodeData->IDCookerDB = PrintCookerType(type);
	nodeData->RaceCookerDB = PrintRaceCookerType(race);
	nodeData->ColorClothesDB = colorOfClothes == 0 ? L"Белый" : L"Черный";
	nodeData->GlasseesDB = wearingGlasses == 0 ? L"Нет" : L"Есть";

	stringTree->EndUpdate();

    Synchronize(MaxProgress);
}
//---------------------------------------------------------------------------
