//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Pole::Pole(TForm*form)
{
	Parent = form;
	width = 25;
	for(int i = 0; i<10; i++)
	{
		for(int j = 0; j<10; j++){
			field[i][j] = new TEdit(Parent);
			field[i][j]->Parent = Parent;
			field[i][j]->Left = j*width+50;
			field[i][j]->Top = i*(width-3)+50;
			field[i][j]->Height = width;
			field[i][j]->Width = width;
			ships[i][j] = false;
		}
	}
}
