//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpPaddleLeftTimerTimer(TObject *Sender)
{
    if(leftPaddle -> Top > table -> Top + 30)
        leftPaddle -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 'A')
        UpPaddleLeftTimer -> Enabled = true;
    if(Key == 'Z')
        DownPaddleLeftTimer -> Enabled = true;
    if(Key == VK_UP)
        UpPaddleRightTimer -> Enabled = true;
    if(Key == VK_DOWN)
        DownPaddleRightTimer -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DownPaddleLeftTimerTimer(TObject *Sender)
{
    if(leftPaddle -> Top + leftPaddle -> Height <
       table -> Top + table -> Height - 30)
        leftPaddle -> Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 'A')
        UpPaddleLeftTimer -> Enabled = false;
    if(Key == 'Z')
        DownPaddleLeftTimer -> Enabled = false;
    if(Key == VK_UP)
        UpPaddleRightTimer -> Enabled = false;
    if(Key == VK_DOWN)
        DownPaddleRightTimer -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpPaddleRightTimerTimer(TObject *Sender)
{
    if(rightPaddle -> Top > table -> Top + 30)
        rightPaddle -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DownPaddleRightTimerTimer(TObject *Sender)
{
    if(rightPaddle -> Top + rightPaddle -> Height <
       table -> Top + table -> Height - 30)
        rightPaddle -> Top += 10;
}
//---------------------------------------------------------------------------

