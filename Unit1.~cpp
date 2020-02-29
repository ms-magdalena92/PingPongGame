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
int numbOfBounces = 0;
int rightPlayerScore = 0;
int leftPlayerScore = 0;
int ballTimerInterval = 25;

void startGame (TImage* ball, TImage* rightPaddle, TImage* leftPaddle, TTimer* BallTimer)
{
    numbOfBounces = 0;
    ballTimerInterval = 25;
    BallTimer -> Interval = ballTimerInterval;

    xBallMove = -10;
    yBallMove = -10;
    ball -> Left = 465;
    ball -> Top = 315;

    leftPaddle -> Left = 30;
    rightPaddle -> Left = 915;
    leftPaddle -> Top = 180;
    rightPaddle -> Top = 180;

    ball -> Visible = true;
    BallTimer -> Enabled = true;
    rightPaddle -> Enabled = true;
    leftPaddle -> Enabled = true;
}
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
    if(ball -> Top + ball -> Height >= rightPaddle -> Top
       && ball  -> Top <= rightPaddle -> Top + rightPaddle -> Height
       && ball -> Left + ball -> Width >= rightPaddle -> Left
       && ball -> Left > table -> Left + table -> Width/2)
       {
           if(ballTimerInterval > 2)
               ballTimerInterval -= 2;

           BallTimer -> Interval = ballTimerInterval;
           xBallMove = -xBallMove;
           numbOfBounces++;
       }
    if(ball -> Top + ball -> Height >= leftPaddle -> Top
       && ball  -> Top <= leftPaddle -> Top + leftPaddle -> Height
       && ball -> Left <= leftPaddle -> Left + leftPaddle -> Width
       && ball -> Left + ball -> Width < table -> Left + table -> Width/2)
       {
           if(ballTimerInterval > 2)
               ballTimerInterval -= 2;

           BallTimer -> Interval = ballTimerInterval;
           xBallMove = -xBallMove;
           numbOfBounces++;
       }
    if(ball -> Left < leftPaddle -> Left + leftPaddle -> Width - 10
            && ball -> Left + ball -> Width < table -> Left + table -> Width/2)
       {
            ball -> Visible = false;
            BallTimer -> Enabled = false;

            rightPlayerScore++;

            rightPaddle -> Enabled = false;
            leftPaddle -> Enabled = false;

            Button2 -> Visible = true;
            Button3 -> Visible = true;

            Label1 -> Visible = true;
            Label1 -> Caption = "Number of bounces: " + IntToStr(numbOfBounces);

            Label2 -> Visible = true;
            Label2 -> Caption = IntToStr(leftPlayerScore) + ":" + IntToStr(rightPlayerScore);
            Label3 -> Visible = true;
            Label3 -> Caption = "POINT FOR THE RIGHT PLAYER ->";
       }
    if(ball -> Left + ball -> Width > rightPaddle -> Left + 10
            && ball -> Left > table -> Left + table -> Width/2)
       {
            ball -> Visible = false;
            BallTimer -> Enabled = false;

            leftPlayerScore++;

            rightPaddle -> Enabled = false;
            leftPaddle -> Enabled = false;

            Button2 -> Visible = true;
            Button3 -> Visible = true;

            Label1 -> Visible = true;
            Label1 -> Caption = "Number of bounces: " + IntToStr(numbOfBounces);

            Label2 -> Visible = true;
            Label2 -> Caption = IntToStr(leftPlayerScore) + ":" + IntToStr(rightPlayerScore);
            Label3 -> Visible = true;
            Label3 -> Caption = "<- POINT FOR THE LEFT PLAYER";
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    rightPlayerScore = 0;
    leftPlayerScore = 0;
    Button3Click(Form1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if(Application -> MessageBox("Do you really want to start a new game?",
       "Confirm", MB_YESNO | MB_ICONQUESTION) == ID_YES)
    {
       Button2 -> Visible = False;
       Button1Click(Form1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Label1 -> Visible = false;
    Label2 -> Visible = false;
    Label3 -> Visible = false;

    Button1 -> Visible = false;
    Button2 -> Visible = false;
    Button3 -> Visible = false;

    startGame(ball,rightPaddle, leftPaddle, BallTimer);
}
//---------------------------------------------------------------------------

