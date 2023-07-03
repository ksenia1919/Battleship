//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRegistration *Registration;
User* user;
TForm* field;
//---------------------------------------------------------------------------
__fastcall TRegistration::TRegistration(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRegistration::Button1Click(TObject *Sender)
{
	if(Edit1->Text != "" && Edit2->Text != ""){
		user=new User(Edit1->Text, Edit2->Text);
		//TStringList* m = new TStringList;
		//m->Add(user->toString());
		//m->SaveToFile("Users.txt");
		//delete m;

		field = new TForm(this);
		field->Parent=this;
		/////////////////
		TButton* but = new TButton(field);
		but->Parent = field;
		but->Caption = "Кнопка";
		but->Top = 200;
		but->Left = 100;
		//but->OnClick = butClick;
		/////////////////
		field->Show();
		this->Visible = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall  TRegistration::butClick(TObject *Sender)
{
   field->Close();
   Registration->Visible = true;
}