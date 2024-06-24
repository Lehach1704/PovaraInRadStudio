//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "VirtualTrees.AncestorVCL.hpp"
#include "VirtualTrees.BaseAncestorVCL.hpp"
#include "VirtualTrees.BaseTree.hpp"
#include "VirtualTrees.hpp"
#include <Vcl.Dialogs.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
typedef struct
 {
	 UnicodeString IDCookerDB;
	 UnicodeString RaceCookerDB;
	 UnicodeString ColorClothesDB;
	 UnicodeString GlasseesDB;
 } NodeStruct;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *FirstContButton;
	TButton *SecondContButton;
	TButton *ThirdContButton;
	TEdit *EditA;
	TVirtualStringTree *StructureDB;
	TOpenDialog *OpenDBDialog;
	TProgressBar *ProgressBar1;
	void __fastcall FirstContButtonClick(TObject *Sender);
	void __fastcall SecondContButtonClick(TObject *Sender);
	void __fastcall ThirdContButtonClick(TObject *Sender);
	void __fastcall StructureDBGetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);

private:
	sqlite3 *Database;
public:
	__fastcall TForm1(TComponent* Owner);
    NodeStruct *ÑNodeData;
	PVirtualNode CNode;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
