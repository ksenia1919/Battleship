//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TLabel *Label1;
	TRadioGroup *RadioGroup1;
	TRadioGroup *RadioGroup2;
	TRadioGroup *RadioGroup3;
	TButton *Button2;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall RadioGroup2Click(TObject *Sender);
	void __fastcall RadioGroup3Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
    bool IsAdmin = false;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
