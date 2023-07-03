//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
TForm* field;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
		field = new TForm(this);
		int a = RadioGroup2->ItemIndex;
		Pole* pole = new Pole(field,RadioGroup2->ItemIndex+1);
		switch(RadioGroup3->ItemIndex)
		{
			case 0:
				pole->SetColor(clGray);
				break;
			case 1:
				pole->SetColor(clYellow);
				break;
			case 2:
				pole->SetColor(clLime);
				break;
			case 3:
				pole->SetColor(clPurple);
				break;
			case 4:
				pole->SetColor(clFuchsia);
				break;
		}
		field->Show();
		this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormActivate(TObject *Sender)
{
	Button2->Visible = IsAdmin;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
	TStringList* sl = new TStringList;
	sl->LoadFromFile("Users.txt");

	TForm* form = new TForm(this);
	form->Width = 400;
	form->Height = 350;

	TLabel* lbl = new TLabel(form);
	lbl->Parent = form;
	lbl->Width = form->Width-50;
	lbl->Height = form->Height-20;
	lbl->Left = form->Width/2-lbl->Width/2;
	lbl->Top = form->Height/2-lbl->Height/2;
	lbl->Font->Size = 14;
	lbl->Caption = "Пользователи";

	TListBox* lb = new TListBox(form);
	lb->Parent = form;
	lb->Items = sl;
	lb->Width = form->Width-50;
	lb->Height = form->Height-100;
	lb->Left = form->Width/2-lb->Width/2;
	lb->Top = form->Height/2-lb->Height/2;
	form->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::RadioGroup1Click(TObject *Sender)
{
	if (RadioGroup1->ItemIndex != -1 && RadioGroup2->ItemIndex != -1 && RadioGroup3->ItemIndex != -1) {
		Button1->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioGroup2Click(TObject *Sender)
{
	if (RadioGroup1->ItemIndex != -1 && RadioGroup2->ItemIndex != -1 && RadioGroup3->ItemIndex != -1) {
		Button1->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioGroup3Click(TObject *Sender)
{
	if (RadioGroup1->ItemIndex != -1 && RadioGroup2->ItemIndex != -1 && RadioGroup3->ItemIndex != -1) {
		Button1->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
	Application->Title="Помощь";
	ShowMessage("При попадании по кораблю появится символ - Х\nПри промахе - 0\n\nУровень легкий:\n1 - четырехпалубник\n2 - трехпалубника\n3 - двухпалубника\n4 - онопалубника\n\nУровень средний:\n1 - трехпалубник\n2 - двухпалубника\n3 - онопалубника\n\nУровень сложный:\n2 - двухпалубника\n4 - онопалубника");
}
//---------------------------------------------------------------------------

