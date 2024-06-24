//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall AnalyseThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall AnalyseThread::AnalyseThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	FreeOnTerminate = true;
	DataReadyEvent = new TEvent(NULL, true, false, "", false);
	DataCopiedEvent = new TEvent(NULL, true, false, "", false);
	CompletedEvent = new TEvent(NULL, true, false, "", false);
}
//---------------------------------------------------------------------------
void __fastcall AnalyseThread::Execute()
{
	CompletedEvent->SetEvent();

	while(!Terminated) // ���� ����� �� ��������
	{
		//�������� ���������� ������ � �������
		if(DataReadyEvent->WaitFor(2000) == wrSignaled)
		{
			//����������� ������ �� ������� � ��������� �����
			Sleep(1);

			// ������������ ������ (����� �����)
			DataReadyEvent->ResetEvent();
			DataCopiedEvent->SetEvent();

			CompletedEvent->ResetEvent(); // ������ ���������

			// ���������� ��������� ������
			Sleep(70);

			CompletedEvent->SetEvent(); // ����� ���������
        }

	}

	delete DataReadyEvent;
	delete DataCopiedEvent;
	delete CompletedEvent;
}
//---------------------------------------------------------------------------
