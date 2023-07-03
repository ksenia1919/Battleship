//---------------------------------------------------------------------------

#pragma hdrstop
#include <jpeg.hpp>
#include "Unit3.h"
#include "Unit4.h"
#include <time.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
int Pole::STEP = 0;
int* Pole::get_fieldIndex(TObject* Object)
{
	int arr[2];
	for(int i = 0; i<10; i++)
	{
		for(int j = 0; j<10; j++)
		{
			if(field[i][j] == Object)
			{
			   arr[0] = i;
			   arr[1] = j;
			   break;
			}
		}
	}
	return arr;
}

bool Pole::validate(int i, int j, int size)
{
	//vertic
	if(r_group2->ItemIndex == 0)
	{
		int q,k;
		for( i == 0 ? q = i : q = i-1; q < i + size + 1 && q < 10; q++)
		{
			for( j == 0 ? k = j : k = j-1; k <= j + 1 && k < 10; k++)
			{
				if(ships[q][k]){return false;}
			}
		}
		  return true;
	}
	//gorizont
	else
	{
		int q,k;
		for( i == 0 ? q = i : q = i-1; q <= i + 1 && q < 10; q++)
		{
			for( j == 0 ? k = j : k = j-1; k < j + size + 1 && k < 10; k++)
			{
				if(ships[q][k]){return false;}
			}
		}
		  return true;
	}

}
void __fastcall Pole::SetUPClick(TObject *Sender)
{
	int i = get_fieldIndex(Sender)[0];
	int j = get_fieldIndex(Sender)[1];
	switch(RGroup->ItemIndex)
	{
		case 3:  //4palub
			if(palub_4 < 1)
			{
				if(r_group2->ItemIndex == 0)  //verticalno
				{
					if(i <= 6 && validate(i,j,4))
					{
						for(int k = 0; k<4; k++)
						{
							field[i+k][j]->Color = ShipColor;
							ships[i+k][j] = true;
							koordinat_ships[0][k][0] = i+k;
							koordinat_ships[0][k][1] = j;
						}

						palub_4++;
						count++;
						UnLock();
					}
				}
				else
				{
					if(j <= 6 && validate(i,j,4))
					{
						for(int k = 0; k<4; k++)
						{
							field[i][j+k]->Color = ShipColor;
							ships[i][j+k] = true;
							koordinat_ships[0][k][0] = i;
							koordinat_ships[0][k][1] = j+k;
						}
						palub_4++;
						count++;
						UnLock();
					}

				}
			}
			break;
		case 2:  //3palub

			if(palub_3 < max_3)
			{
				if(r_group2->ItemIndex == 0)  //verticalno
				{
					if(i <= 7 && validate(i,j,3))
					{
						for(int k = 0; k<3; k++)
						{
							field[i+k][j]->Color = ShipColor;
							ships[i+k][j] = true;
							koordinat_ships[palub_3+1][k][0] = i+k;
							koordinat_ships[palub_3+1][k][1] = j;
						}
						palub_3++;
						count++;
						UnLock();
					}
				}
				else
				{
					if(j <= 7 && validate(i,j,3))
					{
						for(int k = 0; k<3; k++)
						{
							field[i][j+k]->Color = ShipColor;
							ships[i][j+k] = true;
							koordinat_ships[palub_3+1][k][0] = i;
							koordinat_ships[palub_3+1][k][1] = j+k;
						}
						palub_3++;
						count++;
						UnLock();
					}
				}
			}
			break;
		case 1:  //2palub
			if(palub_2 < max_2)
			{
				if(r_group2->ItemIndex == 0)  //verticalno
				{
					if(i <= 8 && validate(i,j,2))
					{
						for(int k = 0; k<2; k++)
						{
							field[i+k][j]->Color = ShipColor;
							ships[i+k][j] = true;
							koordinat_ships[palub_2+3][k][0] = i+k;
							koordinat_ships[palub_2+3][k][1] = j;
						}
						palub_2++;
						count++;
						UnLock();
					}
				}
				else
				{
					if(j <=8 && validate(i,j,2) )
					{
						for(int k = 0; k<2; k++)
						{
							field[i][j+k]->Color = ShipColor;
							ships[i][j+k] = true;
							koordinat_ships[palub_2+3][k][0] = i;
							koordinat_ships[palub_2+3][k][1] = j+k;
						}
						palub_2++;
						count++;
						UnLock();
					}
				}
			}
			break;
		case 0:  //1palub
			if(palub_1 < max_1)
			{
				if(r_group2->ItemIndex == 0)  //verticalno
				{
					if(i <= 9 && validate(i,j,1))
					{
						for(int k = 0; k<1; k++)
						{
							field[i+k][j]->Color = ShipColor;
							ships[i+k][j] = true;
							koordinat_ships[palub_1+6][k][0] = i+k;
							koordinat_ships[palub_1+6][k][1] = j;
						}
						palub_1++;
						count++;
						UnLock();
					}
				}
				else
				{
					if(j <= 9 && validate(i,j,1))
					{
						for(int k = 0; k<1; k++)
						{
							field[i][j+k]->Color = ShipColor;
							ships[i][j+k] = true;
							koordinat_ships[palub_1+6][k][0] = i;
							koordinat_ships[palub_1+6][k][1] = j+k;
						}
						palub_1++;
						count++;
						UnLock();
					}
				}
			}
			break;
	}
}

void Pole::generate()
{

	srand(time(NULL));
	int i = rand()%7;
	int j = rand()%7;
	//////////4_palub////////////
	r_group2->ItemIndex = rand()%2;
	if(Level == 1){
	if(r_group2->ItemIndex == 0)  //verticalno
	{
		while (!validate(i,j,4))
		{
			i = rand()%7;
			j = rand()%10;
		}

		if(i <= 6 && validate(i,j,4))
		{
			for(int k = 0; k<4; k++)
			{
				field[i+k][j]->Color = ShipColor;
				ships[i+k][j] = true;
				koordinat_ships[0][k][0] = i+k;
				koordinat_ships[0][k][1] = j;
			}
			palub_4++;
			count++;
			UnLock();
		}
	}
	else
	{
		while (!validate(i,j,4))
		{
			i = rand()%10;
			j = rand()%7;
		}

		if(j <= 6 && validate(i,j,4))
		{
			for(int k = 0; k<4; k++)
			{
				field[i][j+k]->Color = ShipColor;
				ships[i][j+k] = true;
				koordinat_ships[0][k][0] = i;
				koordinat_ships[0][k][1] = j+k;
			}
			palub_4++;
			count++;
			UnLock();
		}

	}
	}
	//////////3_palub////////////

	for (int w = 0; w < max_3; w++) {
		r_group2->ItemIndex = rand()%2;
		if(r_group2->ItemIndex == 0)  //verticalno
		{
			while (!validate(i,j,3) )
			{
				i = rand()%8;
				j = rand()%10;
			}

			if(i <= 7 && validate(i,j,3))
			{
				for(int k = 0; k<3; k++)
				{
					field[i+k][j]->Color = ShipColor;
					ships[i+k][j] = true;
					koordinat_ships[palub_3+1][k][0] = i+k;
					koordinat_ships[palub_3+1][k][1] = j;
				}
				palub_3++;
				count++;
				UnLock();
			}
		}
	else
	{
		while (!validate(i,j,3))
		{
			i = rand()%10;
			j = rand()%8;
		}

		if(j <= 7 && validate(i,j,3))
		{
			for(int k = 0; k<3; k++)
			{
				field[i][j+k]->Color = ShipColor;
				ships[i][j+k] = true;
                koordinat_ships[palub_3+1][k][0] = i;
				koordinat_ships[palub_3+1][k][1] = j+k;
			}
			palub_3++;
			count++;
			UnLock();
		}

	}
	}
		///////////2_palub///////////
	for (int w = 0; w < max_2; w++) {
		r_group2->ItemIndex = rand()%2;
		if(r_group2->ItemIndex == 0)  //verticalno
		{
			while (!validate(i,j,2))
			{
				i = rand()%9;
				j = rand()%10;
			}

			if(i <= 8 && validate(i,j,2))
			{
				for(int k = 0; k<2; k++)
				{
					field[i+k][j]->Color = ShipColor;
					ships[i+k][j] = true;
					koordinat_ships[palub_2+3][k][0] = i+k;
					koordinat_ships[palub_2+3][k][1] = j;
				}
				palub_2++;
				count++;
				UnLock();
			}
		}
	else
	{
		while (!validate(i,j,2))
		{
			i = rand()%10;
			j = rand()%9;
		}

		if(j <= 8 && validate(i,j,2))
		{
			for(int k = 0; k<2; k++)
			{
				field[i][j+k]->Color = ShipColor;
				ships[i][j+k] = true;
                koordinat_ships[palub_2+3][k][0] = i;
				koordinat_ships[palub_2+3][k][1] = j+k;
			}
			palub_2++;
			count++;
			UnLock();
		}

	}
	}
	///////////1_palub///////////
	for (int w = 0; w < max_1; w++) {
		r_group2->ItemIndex = rand()%2;
		if(r_group2->ItemIndex == 0)  //verticalno
		{
			while (!validate(i,j,1))
			{
				i = rand()%10;
				j = rand()%10;
			}

			if(i <= 9 && validate(i,j,1))
			{
				for(int k = 0; k<1; k++)
				{
					field[i+k][j]->Color = ShipColor;
					ships[i+k][j] = true;
					koordinat_ships[palub_1+6][k][0] = i+k;
					koordinat_ships[palub_1+6][k][1] = j;
				}
				palub_1++;
				count++;
				UnLock();
			}
		}
		else
		{
			while (!validate(i,j,1)){
				i = rand()%10;
				j = rand()%10;
			}

			if(j <= 9 && validate(i,j,1)){
				for(int k = 0; k<1; k++)
				{
					field[i][j+k]->Color = ShipColor;
					ships[i][j+k] = true;
                    koordinat_ships[palub_1+6][k][0] = i;
					koordinat_ships[palub_1+6][k][1] = j+k;
				}
				palub_1++;
				count++;
				UnLock();
			}

		}
	}
}
Pole::Pole(TForm*form, int lvl)
{
	Level = lvl;
	if(Level == 3) {max_3 = 0; max_2 = 2; max_1 = 4;}
	if(Level == 2) { max_3 = 1; max_2 = 2; max_1 = 3;}
	for (int i = 0; i < 10; i++) {
		if(i == 0){
			koordinat_ships[i] = new int* [4];
			for (int j = 0; j < 4; j++){
				koordinat_ships[i][j] = new int[2];
			}
		}
		if(i > 0 && i < 3){
			koordinat_ships[i] = new int* [3];
			for (int j = 0; j < 3; j++){
				koordinat_ships[i][j] = new int[2];
			}
		}
		if(i >= 3 && i < 6){
			koordinat_ships[i] = new int* [2];
			for (int j = 0; j < 2; j++){
				koordinat_ships[i][j] = new int[2];
			}
		}
		if(i >= 6){
			koordinat_ships[i] = new int* [1];
			for (int j = 0; j < 1; j++){
				koordinat_ships[i][j] = new int[2];
			}
		}
	}

	palub_1 = 0;
	palub_2 = 0;
	palub_3 = 0;
	palub_4 = 0;
	Parent = form;
	Parent->Width = 750;
	form->Caption = "Морской бой";
	width = 25;
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			field[i][j] = new TEdit(Parent);
			field[i][j]->Parent = Parent;
			field[i][j]->Left = j*width+50;
			field[i][j]->Top = i*(width-3)+50;
			field[i][j]->Height = width;
			field[i][j]->Width = width;
			field[i][j]->Cursor = crCross;
			ships[i][j] = false;
			field[i][j]->OnClick = SetUPClick;
		}
	}
	//картинка фона
	image = new TImage(Parent);
	image->Parent = Parent;
	image->Width = 900;
	image->Height = 600;
	image->Top = 0;
	image->Left = 0;
	image->Picture->LoadFromFile("pictures\\bg.jpg");
	image->Center = true;

	//коорддинаты label для поля корабликов
	int left = field[0][0]->Left - 20;
	int wid = 25;
	int numbers = 1;
	for(int i = 0; i<10; i++){
		lable_1[i] = new TLabel(Parent);
		lable_1[i]->Parent = Parent;
		lable_1[i]->Left = left;
		lable_1[i]->Top = i*(wid-2)+50;
		lable_1[i]->Caption = IntToStr(numbers);
		numbers++;
	}
	//наазвание верхней строки букв
	int top = field[0][0]->Top - 20;
	wid = 25;
	char leter = 'А';
	for(int i = 0; i<10; i++){
		lable_1[i] = new TLabel(Parent);
		lable_1[i]->Parent = Parent;
		lable_1[i]->Left =i*(wid)+field[0][0]->Left+7;
		lable_1[i]->Top = top;
		lable_1[i]->Caption = AnsiString(leter);
		if (leter=='И') {
			leter+=2;
		}
		else
			leter++;
	}

	/////////////////////////////////////////////////
	RGroup = new TRadioGroup(Parent);
	RGroup->Parent = Parent;
	RGroup->Caption = "Корабли";
	RGroup->Items->Add("1-palub");
	RGroup->Items->Add("2-palub");
	if (Level == 2 || Level == 1) {
	RGroup->Items->Add("3-palub");
	}
	if (Level == 1) {
	RGroup->Items->Add("4-palub");
	}
	RGroup->Top = 100;
	RGroup->Left = 330;
	RGroup->Visible = false;

	r_group1 = new TRadioGroup(Parent);
	r_group1->Parent = Parent;
	r_group1->Top = 300;
	r_group1->Left = 50;
	r_group1->Height = 60;
	r_group1->Width = 130;
	r_group1->Caption = "Расстановка";
	r_group1->Items->Add("Random");
	r_group1->Items->Add("Ручками");
	r_group1->OnClick = RadioGroup1Click;

	r_group2 = new TRadioGroup(Parent);
	r_group2->Parent = Parent;
	r_group2->Top = 300;
	r_group2->Left = 220;
	r_group2->Height = 60;
	r_group2->Width = 130;
	r_group2->Caption = "Положение";
	r_group2->Items->Add("Вертикально");
	r_group2->Items->Add("Горизонтально");
	r_group2->Visible = false;

	/////////////////
		but = new TButton(Parent);
		but->Parent = Parent;
		but->Caption = "Играть";
		but->Top = 335;
		but->Left = 400;
		but->Enabled = false;
		but->OnClick = PlayButtonClick;
	/////////////////

	top = field[9][9]->Top + 30;
	left = field[0][0]->Left + 98;
	lable_My = new TLabel(Parent);
	lable_My->Parent = Parent;
	lable_My->Caption = "Мое поле";
	lable_My->Left = left;
	lable_My->Top = top;
}

Ship:: Ship(int kolvo,bool vertic)
{
	this->kolvo_palub = kolvo;
	this->vertic = vertic;
}
void Ship::setvertic(bool newvertic)
{
	vertic = newvertic;
}
void Ship::setpalubs(int count)
{
	kolvo_palub = count;
}

int Ship::getpalubs(){return kolvo_palub;}
bool Ship::getvertic(){return vertic;}

void Pole::clear()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ships[i][j]=false;
			field[i][j]->Color = clWhite;
		}
	}
	palub_1 = 0;
	palub_2 = 0;
	palub_3 = 0;
	palub_4 = 0;
	UnLock();
}

void __fastcall Pole::RadioGroup1Click(TObject *Sender)
{
	if(r_group1->ItemIndex == 0){
		RGroup->Visible = false;
		r_group2->Visible = false;
		clear();
		generate();
	}
	else
	{
		RGroup->Visible = true;
		r_group2->Visible = true;
		clear();
	}
}

void Pole::UnLock()
{  if(Level == 1){
   if(palub_1+palub_2+palub_3+palub_4 == 10-Level+1){
		but->Enabled = true;
   }
   else
   {
		but->Enabled = false;
   }
  }
  else{
   if(palub_1+palub_2+palub_3+palub_4 == 6){
		but->Enabled = true;
   }
   else
   {
		but->Enabled = false;
   }
  }
}

void Pole::Hide()
{
    for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j]->Color = clWhite;
			field[i][j]->OnClick = BattleClick;
		}
	}
	delete RGroup;
	delete r_group1;
	delete r_group2;
	delete but;
}

void Pole::Show(){
	for(int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			if(ships[i][j])
			{
				field[i][j]->Color = ShipColor;
			}
		}
	}

}

Pole::Pole(TForm* form , int left, int top, int lvl)
{
	Level = lvl;
	if(Level == 3) {max_3 = 0; max_2 = 2; max_1 = 4; }
	if(Level == 2){ max_3 = 1; max_2 = 2; max_1 = 3; }
	for (int i = 0; i < 10; i++) {
		if(i == 0){
			koordinat_ships[i] = new int* [4];
			for (int j = 0; j < 4; j++){
				koordinat_ships[i][j] = new int[2];
			}
		}
		if(i > 0 && i < 3){
			koordinat_ships[i] = new int* [3];
			for (int j = 0; j < 3; j++){
				koordinat_ships[i][j] = new int[2];
			}
		}
		if(i >= 3 && i < 6){
			koordinat_ships[i] = new int* [2];
			for (int j = 0; j < 2; j++){
				koordinat_ships[i][j] = new int[2];
			}
		}
		if(i >= 6){
			koordinat_ships[i] = new int* [1];
			for (int j = 0; j < 1; j++){
				koordinat_ships[i][j] = new int[2];
			}
		}
	}

	palub_1 = 0;
	palub_2 = 0;
	palub_3 = 0;
	palub_4 = 0;
	Parent = form;
	width = 25;
	form->Caption = "Морской бой";
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			field[i][j] = new TEdit(Parent);
			field[i][j]->Parent = Parent;
			field[i][j]->Left = j*width+50+left;
			field[i][j]->Top = i*(width-3)+50+top;
			field[i][j]->Height = width;
			field[i][j]->Width = width;
			field[i][j]->Cursor = crCross;
			ships[i][j] = false;
			field[i][j]->OnClick = SetUPClick;
		}
	}

	//коорддинаты label для поля корабликов
	left = field[0][0]->Left - 20;
	int wid = 25;
	int numbers = 1;
	for(int i = 0; i<10; i++){
		lable_1[i] = new TLabel(Parent);
		lable_1[i]->Parent = Parent;
		lable_1[i]->Left = left;
		lable_1[i]->Top = i*(wid-2)+50;
		lable_1[i]->Caption = IntToStr(numbers);
		numbers++;
	}
	//наазвание верхней строки букв
	top = field[0][0]->Top - 20;
	wid = 25;
	char leter = 'А';
	for(int i = 0; i<10; i++){
		lable_1[i] = new TLabel(Parent);
		lable_1[i]->Parent = Parent;
		lable_1[i]->Left =i*(wid)+field[0][0]->Left+7;
		lable_1[i]->Top = top;
		lable_1[i]->Caption = AnsiString(leter);
		if (leter=='И') {
			leter+=2;
		}
		else
			leter++;
	}

    /////////////////////////////////////////////////
	RGroup = new TRadioGroup(Parent);
	RGroup->Parent = Parent;
	RGroup->Caption = "Корабли";
	RGroup->Items->Add("1-palub");
	RGroup->Items->Add("2-palub");
	if (Level == 2) {
	RGroup->Items->Add("3-palub");
	}
	if (Level == 1) {
	RGroup->Items->Add("4-palub");
	}
	RGroup->Top = 100;
	RGroup->Left = 330;

	r_group1 = new TRadioGroup(Parent);
	r_group1->Parent = Parent;
	r_group1->Top = 300;
	r_group1->Left = 50;
	r_group1->Height = 60;
	r_group1->Width = 130;
	r_group1->Caption = "Расстановка";
	r_group1->Items->Add("Random");
	r_group1->Items->Add("Ручками");
	r_group1->OnClick = RadioGroup1Click;

	r_group2 = new TRadioGroup(Parent);
	r_group2->Parent = Parent;
	r_group2->Top = 300;
	r_group2->Left = 220;
	r_group2->Height = 60;
	r_group2->Width = 130;
	r_group2->Caption = "Положение";
	r_group2->Items->Add("Вертикально");
	r_group2->Items->Add("Горизонтально");

	/////////////////
		but = new TButton(Parent);
		but->Parent = Parent;
		but->Caption = "Играть";
		but->Top = 335;
		but->Left = 400;
		but->Enabled = false;
	/////////////////

	top = field[9][9]->Top + 30;
	left = field[0][0]->Left + 77;
	lable_My = new TLabel(Parent);
	lable_My->Parent = Parent;
	lable_My->Caption = "Поле противника";
    lable_My->Left = left;
	lable_My->Top = top;
}

void __fastcall Pole::PlayButtonClick(TObject *Sender)
{
	this->Hide();
	this->Show();
	p2 = new Pole(Parent, 350, 0, Level);
	p2->generate();
	p2->Hide();
	p2->p2 = this;
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			field[i][j]->Enabled = false;
		}
	}
}

bool Pole::IsShipKilled(int m)
{
	if (m == 0) {
		for (int w = 0; w < 4; w++) {
			if (koordinat_ships[m][w][0] != -1) {
				return false;
			}
		}
		count--;
		return true;
	}
	if (m > 0 && m <3) {
		for (int w = 0; w < 3; w++) {
			if (koordinat_ships[m][w][0] != -1) {
				return false;
			}
		}
		count--;
		return true;
	}
	if (m >= 3 && m < 6) {
		for (int w = 0; w < 2; w++) {
			if (koordinat_ships[m][w][0] != -1) {
				return false;
			}
		}
		count--;
		return true;
	}
	if (m>=6) {
		for (int w = 0; w < 1; w++) {
			if (koordinat_ships[m][w][0] != -1) {
				return false;
			}
		}
		count--;
		return true;
	}
}

bool Pole::IsVertic(int i, int j)
{
	if(i == 0 && ships[i+1][j]){
	return true;
	}
	if (i == 9 && ships[i-1][j]){
	return true;
	}
	if (ships[i-1][j] || ships[i+1][j]){
	return true;
	}
	return false;
}

void Pole::Fill(int i, int j, int n, int size)
{
//vertic
	if(IsVertic(i,j))
	{
		int q,k;
		i-=n;
		for( i == 0 ? q = i : q = i-1; q < i + size + 1 && q < 10; q++)
		{
			for( j == 0 ? k = j : k = j-1; k <= j + 1 && k < 10; k++)
			{
				if((k == j && (q == i-1 || q == i+size)) || k != j){
				field[q][k]->Text = "0";
				field[q][k]->Color = clBlue;
				}
			}
		}
	}
//gorizont
	else
	{
		int q,k;
		j-=n;
		for( i == 0 ? q = i : q = i-1; q <= i + 1 && q < 10; q++)
		{
			for( j == 0 ? k = j : k = j-1; k < j + size + 1 && k < 10; k++)
			{
				if((q == i && (k == j-1 || k == j+size)) || q != i)
				{
				field[q][k]->Text = "0";
				field[q][k]->Color = clBlue;
				}
			}
		}
	}
}

void Pole::Step(int i, int j)
{
	if (field[i][j]->Text == "") {
		if (ships[i][j]) {
			field[i][j]->Text = "X";
			field[i][j]->Color = clRed;
			for (int q = 0; q < 10; q++) {
				if (q == 0) {
					for (int w = 0; w < 4; w++) {
						if (koordinat_ships[q][w][0] == i && koordinat_ships[q][w][1] == j) {
							koordinat_ships[q][w][0] = -1;
							koordinat_ships[q][w][1] = -1;
							if (IsShipKilled(q)) {
								Fill(i,j,w, 4);
							}
						}
					}
				}
				if (q > 0 && q <3) {
					for (int w = 0; w < 3; w++) {
                        if (koordinat_ships[q][w][0] == i && koordinat_ships[q][w][1] == j) {
							koordinat_ships[q][w][0] = -1;
							koordinat_ships[q][w][1] = -1;
                            if (IsShipKilled(q)) {
								Fill(i,j,w, 3);
							}
						}
					}
				}
				if (q >= 3 && q < 6) {
					for (int w = 0; w < 2; w++) {
                        if (koordinat_ships[q][w][0] == i && koordinat_ships[q][w][1] == j) {
							koordinat_ships[q][w][0] = -1;
							koordinat_ships[q][w][1] = -1;
                            if (IsShipKilled(q)) {
								Fill(i,j,w, 2);
							}
						}
					}
				}
				if (q>=6) {
					for (int w = 0; w < 1; w++) {
						if (koordinat_ships[q][w][0] == i && koordinat_ships[q][w][1] == j) {
							koordinat_ships[q][w][0] = -1;
							koordinat_ships[q][w][1] = -1;
							if (IsShipKilled(q)) {
								Fill(i,j,w, 1);
							}
						}
					}
				}
			}
			if (count == 0) {
				if (STEP%2 == 0) {
				   TForm* form = new TForm(Parent);
				   form->Color = clSkyBlue;
				   form->Width = 355;
				   form->Height = 200;
				   TLabel* lab = new TLabel(form);
				   lab->Parent = form;
				   lab->Caption = "Вы победили!";
				   lab->Left = 90;
				   lab->Top = 50;
				   lab->Font->Size = 20;
				   lab->Font->Name = "Stylo";
				   TButton* button = new TButton(form);
				   button->Parent = form;
				   button->Caption = "OK";
				   button->Left = 130;
				   button->Top = 95;
				   button->OnClick = OK_ButtonClick;
				   Parent->Enabled = false;
				   form->Show();
				}
				else
				{
				   TForm* form = new TForm(Parent);
				   form->Color = clSkyBlue;
				   form->Width = 355;
				   form->Height = 200;
				   TLabel* lab = new TLabel(form);
				   lab->Parent = form;
				   lab->Caption = "Вы проиграли";
				   lab->Left = 90;
				   lab->Top = 50;
				   lab->Font->Size = 20;
				   lab->Font->Name = "Stylo";
				   TButton* button = new TButton(form);
				   button->Parent = form;
				   button->Caption = "OK";
				   button->Left = 130;
				   button->Top = 95;
				   button->OnClick = OK_ButtonClick;
				   Parent->Enabled = false;
				   form->Show();
				}
			}
		}
		else
		{
			field[i][j]->Text = "0";
			field[i][j]->Color = clBlue;
			STEP++;
		}

	}
}

void __fastcall Pole::OK_ButtonClick(TObject *Sender)
{

	TButton* b = (TButton*)(Sender);
	TForm* f1 = (TForm*)(b->Parent);
	TForm* f2 = (TForm*)(f1->Parent);
	f1->Close();
	delete f2;
	this->Parent->Close();
	Form4->Show();
}

void __fastcall Pole::BattleClick(TObject *Sender){
	int i = get_fieldIndex(Sender)[0];
	int j = get_fieldIndex(Sender)[1];
	Step(i, j);
	Sleep(300);
	while (STEP%2)
	{
		i = rand()%10;
		j = rand()%10;
		p2->Step(i,j);
	}
}

void Pole::SetColor(TColor c)
{
	ShipColor = c;
}
