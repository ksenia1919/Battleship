//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <jpeg.hpp>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRegistration *Registration;
User* user;

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
		TStringList* m = new TStringList;
		m->LoadFromFile("Users.txt");
		m->Add(user->toString());
		m->SaveToFile("Users.txt");
		delete m;
		if(Edit1->Text == "Admin" && Edit2->Text == "adminochka@gmail.com")
		{
            Form4->IsAdmin = true;
		}
		Form4->Show();
		//this->Close();
	}
	else {Application->Title="Ошибка входа"; ShowMessage("Пожалуйста, заполните все поля"); }
}
//---------------------------------------------------------------------------

void __fastcall TRegistration::FormCreate(TObject *Sender)
{
	Image1->Picture->LoadFromFile("pictures\\fr.jpg");
	//Image1->AutoSize = true;
}
//---------------------------------------------------------------------------



