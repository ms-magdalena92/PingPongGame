//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int xBallMove = -10;
int yBallMove = -10;
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

void __fastcall TForm1::BallTimerTimer(TObject *Sender)
{
    ball -> Left += xBallMove;
    ball -> Top += yBallMove;

    if(ball -> Top - 5 < table -> Top + 25)
        yBallMove = -yBallMove;
    if(ball -> Top + ball -> Height + 5 > table -> Top + table -> Height - 25)
        yBallMove = -yBallMove;
    if(ball -> Top + ball -> Height < rightPaddle -> Top + rightPaddle -> Height
       && ball -> Top > rightPaddle -> Top
       && ball -> Left + ball -> Width < rightPaddle -> Left)
        {
            if(yBallMove > 0)
                xBallMove = -xBallMove;
        }
    if(ball -> Top + ball -> Height < leftPaddle -> Top + leftPaddle -> Height
       && ball -> Top > leftPaddle -> Top
       && ball -> Left > leftPaddle -> Left + leftPaddle -> Width)
        {
            if(yBallMove > 0)
                xBallMove = -xBallMove;
        }
}
//---------------------------------------------------------------------------

