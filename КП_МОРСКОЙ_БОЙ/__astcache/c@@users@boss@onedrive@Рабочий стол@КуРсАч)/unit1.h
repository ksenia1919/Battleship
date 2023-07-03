//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TRegistration : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	void __fastcall butClick(TObject *Sender);
public:		// User declarations
	__fastcall TRegistration(TComponent* Owner);

};

//---------------------------------------------------------------------------
extern PACKAGE TRegistration *Registration;
//---------------------------------------------------------------------------
#endif
