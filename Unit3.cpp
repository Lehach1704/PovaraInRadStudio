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

	while(!Terminated) // пока поток не завершен
	{
		//Ожидание подготовки буфера с данными
		if(DataReadyEvent->WaitFor(2000) == wrSignaled)
		{
			//Копирование данных из объекта в локальный буфер
			Sleep(1);

			// Осфобождение буфера (сброс флага)
			DataReadyEvent->ResetEvent();
			DataCopiedEvent->SetEvent();

			CompletedEvent->ResetEvent(); // начало обработки

			// Выполнение обработки данных
			Sleep(70);

			CompletedEvent->SetEvent(); // конец обработки
        }

	}

	delete DataReadyEvent;
	delete DataCopiedEvent;
	delete CompletedEvent;
}
//---------------------------------------------------------------------------
