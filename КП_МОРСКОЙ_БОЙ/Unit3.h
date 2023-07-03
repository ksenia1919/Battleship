//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#endif
class Ship
 {
	int kolvo_palub;
	bool vertic;
	public:
	Ship(int kolvo_palub = 1, bool vertic = true);
	void setvertic(bool newvertic);   //
	void setpalubs(int count);        //
	bool getvertic();                 //
	int getpalubs();                  //
 };
 class Pole
{
	TEdit* field[10][10];
	int width;
	bool ships[10][10];
	TForm* Parent;
	TRadioGroup* RGroup;
	TRadioGroup* r_group1;
	TRadioGroup* r_group2;
	TImage* image;
	TLabel* lable_1[10];
	TLabel* lable_2[10];
	TLabel* lable_My;
	int* get_fieldIndex(TObject* Object);  //
	bool validate(int i, int j, int size);  //
    int palub_1;
	int palub_2;
	int palub_3;
	int palub_4;
	TButton* but;
	Pole* p2;
	int** koordinat_ships[10];
	int count{0};
	int Level{1};
	int max_3{2};
    int max_2{3};
	int max_1{4};
	TColor ShipColor;

	public:
	static int STEP;
	Pole(TForm*, int left, int top, int lvl);
	Pole(TForm*, int lvl);
	//~Pole();
	void SetShip(Ship ship);
	void __fastcall SetUPClick(TObject *Sender);
	void generate();
	void __fastcall RadioGroup1Click(TObject *Sender);
	void clear();
	void UnLock();
	void Hide();
	void Show();
	void SetColor(TColor);
	void __fastcall PlayButtonClick(TObject *Sender);
	void Step(int i, int j);
	void __fastcall BattleClick(TObject *Sender);
	bool IsShipKilled(int m);
	void Fill(int i, int j, int n, int size);
	bool IsVertic(int i, int j);
	void __fastcall OK_ButtonClick(TObject *Sender);
};

