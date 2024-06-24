//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#pragma hdrstop

using namespace std;

#include "sqlite3.h"
#include "povara.h"
#include "Patterns.h"
#include "BDBDBD.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma link "VirtualTrees.AncestorVCL"
#pragma link "VirtualTrees.BaseAncestorVCL"
#pragma link "VirtualTrees.BaseTree"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	StructureDB->NodeDataSize = sizeof(NodeStruct);
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
void FillST(TVirtualStringTree *stringTree, Cooker type, RaceCooker race, bool colorOfClothes, bool wearingGlasses)
{
	stringTree->BeginUpdate();

	PVirtualNode entryNode = stringTree->AddChild(stringTree->RootNode);

	NodeStruct *nodeData = (NodeStruct*)stringTree->GetNodeData(entryNode);

	nodeData->IDCookerDB = PrintCookerType(type);
	nodeData->RaceCookerDB = PrintRaceCookerType(race);
	nodeData->ColorClothesDB = colorOfClothes == 0 ? L"Белый" : L"Черный";
	nodeData->GlasseesDB = wearingGlasses == 0 ? L"Нет" : L"Есть";

	stringTree->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StructureDBGetText(TBaseVirtualTree *Sender, PVirtualNode Node,
		  TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
    NodeStruct *nodeData = (NodeStruct*)Sender->GetNodeData(Node);
	switch(Column)
	{
		case 0: CellText = nodeData->IDCookerDB; break;
		case 1: CellText = nodeData->RaceCookerDB; break;
		case 2: CellText = nodeData->ColorClothesDB; break;
		case 3: CellText = nodeData->GlasseesDB; break;
	}
}
//---------------------------------------------------------------------------
 ActionOfCooker::ActionOfCooker()
{
	WearingGlasses = bool (rand() % 2);
	ColorOfClothes = bool (rand() % 2);
	Race = RaceCooker(rand() % 3);

    bool Vacation;
    bool Cooking;
    int Skill;
    string Sex;
    string Post;
}
//---------------------------------------------------------------------------
CookerContainer::CookerContainer(int maxSize) // конструктор контейнера с поварами (1)
{
	CookerBox = new CookerPtr[maxSize];
	for(int i = 0; i < maxSize; i++)
	{
		CookerBox[i] = NULL;
	}
	CookerCount = 0;
	MaxSize = maxSize;
}
//---------------------------------------------------------------------------
CookerContainer::~CookerContainer() // деструктор контейнера с поварами (1)
{
	for(int i=0; i<MaxSize; i++)
	{
		if(CookerBox[i] != NULL)
		{
			delete CookerBox[i];
			CookerBox[i] = NULL;
		}
	}
	delete[] CookerBox;
}
//---------------------------------------------------------------------------
void ActionOfCooker::CookOff() // описание функции окончания готовки
{
    wcout << L"Дело сделано!" << endl;
    Cooking = false;
    if (Skill >= 100)
    {
        Skill = 100;
    }
    else
    {
		Skill +=10;
    }
}
//---------------------------------------------------------------------------
void CookerContainer::AddCooker(CookerPtr newCooker) // создание нового повара
{
	CookerBox[CookerCount++] = newCooker;
}
//---------------------------------------------------------------------------
void OutPut_iterator(Iterator<CookerPtr> *iter) // функция для вывода всех поваров через итератор
{
    for(iter->First(); !iter->IsDone(); iter->Next())
    {
        const CookerPtr outCook = iter->CurrentItem();
        wcout << L" (" << PrintCookerType(outCook->GetCooker()) << L")" << endl;
    }
}
//---------------------------------------------------------------------------
void HaveGlasses(Iterator<CookerPtr> *iter)
{
    for(iter->First(); !iter->IsDone(); iter->Next())
    {
		const CookerPtr outCook = iter->CurrentItem();
	}
}
//---------------------------------------------------------------------------
void ColorCloth(Iterator<CookerPtr> *iter)
{
    for(iter->First(); !iter->IsDone(); iter->Next())
    {
		const CookerPtr outCook = iter->CurrentItem();
	}
}
//---------------------------------------------------------------------------
ActionOfCooker *CreateCookerType(const Cooker type, RaceCooker Race, bool ColorOfClothes, bool WearingGlasses) //фабричный метод
{
    switch(type)
    {
		case Cooker::Mousee: return new Mousee;
        case Cooker::Cat: return new Cat;
        case Cooker::Robot: return new Robot;
        case Cooker::WheelchairUser: return new WheelchairUser;
        default: return NULL;
    }
}
//---------------------------------------------------------------------------
ActionOfCooker *ActionOfCooker::CreateCooker(Cooker type, RaceCooker Race, bool ColorOfClothes, bool WearingGlasses)
{
    return CreateCookerType(type, Race, ColorOfClothes, WearingGlasses);
}
//---------------------------------------------------------------------------
void ClearVST(TVirtualStringTree *stringTree)
{
	stringTree->Clear(); // очистка таблицы
}
//---------------------------------------------------------------------------
void RCooker(Iterator<CookerPtr> *iter, TVirtualStringTree *stringTree)
{
	for(iter->First(); !iter->IsDone(); iter->Next())
	{
		const CookerPtr outCook = iter->CurrentItem();
		FillST(stringTree, outCook->GetCooker(), outCook->GetRace(), outCook->ColClothes(),outCook->WearGlasses());
	}

	Form1->ProgressBar1->Position = Form1->ProgressBar1->Max;
}
//---------------------------------------------------------------------------
void AddCont(int a)
{
	ContPtr cookerBox;
	switch(a)
	{
		case(0):
			cookerBox = new CookerContainer(StrToInt(Form1->EditA->Text));
			break;
		case(1):
			cookerBox = new CookerContainerV2;
			break;
		case(2):
			cookerBox = new CookerBD;
			break;
		default: NULL;
	}

	//CookerContainer cookerBox(StrToInt(Form1->EditA->Text));
	//CookerContainerV2 cookerBox;
	//CookerBD cookerBox;

	Form1->ProgressBar1->Max = StrToInt(Form1->EditA->Text);
	Form1->ProgressBar1->Position = 0;

	ClearVST(Form1->StructureDB);

	for(int i=0; i<StrToInt(Form1->EditA->Text); i++)
	{
		cookerBox->AddCooker(CreateCookerType(Cooker(rand() % 4), RaceCooker(rand() % 3), bool(), bool()));
		Form1->ProgressBar1->Position = i;
	}

	Iterator<CookerPtr> *iter = new ThirdDecorator(new FirstDecorator(cookerBox->GetIterator(), true), RaceCooker::European);
	RCooker(iter, Form1->StructureDB);

	delete iter;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FirstContButtonClick(TObject *Sender)
{
	AddCont(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SecondContButtonClick(TObject *Sender)
{
	AddCont(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ThirdContButtonClick(TObject *Sender)
{
	AddCont(2);
}
//---------------------------------------------------------------------------
