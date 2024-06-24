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
wstring PrintCookerType(const Cooker type) // �������� ���� ������
{
	switch(type)
	{
		case Cooker::Mousee: return L"����";
		case Cooker::Cat: return L"���";
		case Cooker::Robot: return L"�����";
		case Cooker::WheelchairUser: return L"����������";
		default: return L"����������";
	}
}
//---------------------------------------------------------------------------
wstring PrintRaceCookerType(const RaceCooker race) // �������� ���� ������
{
	switch(race)
	{
		case RaceCooker::African: return L"�������";
		case RaceCooker::European: return L"��������";
		case RaceCooker::Asian: return L"�����";
		default: return L"����������";
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
	nodeData->ColorClothesDB = colorOfClothes == 0 ? L"�����" : L"������";
	nodeData->GlasseesDB = wearingGlasses == 0 ? L"���" : L"����";

	stringTree->EndUpdate();

    Synchronize(MaxProgress);
}
//---------------------------------------------------------------------------
