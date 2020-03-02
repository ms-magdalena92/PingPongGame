//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int xBallMove = -10;
int yBallMove = -10;
int numbOfBounces = 0;
int rightPlayerScore = 0;
int leftPlayerScore = 0;
int ballTimerInterval = 20;
bool speededUp = false;
bool angleChanged = false;

void startGame (TShape* ball, TShape* rightPaddle, TShape* leftPaddle, TTimer* BallTimer, TShape* table)
{
    if(xBallMove < 0)
       xBallMove = -10;
    if(xBallMove > 0)
       xBallMove = 10;
    if(yBallMove < 0)
       yBallMove = -10;
    if(yBallMove > 0)
       yBallMove = 10;

    sndPlaySound("snd/start.wav", SND_ASYNC);
    numbOfBounces = 0;
    speededUp = false;
    angleChanged = false;
    ballTimerInterval = 20;
    BallTimer -> Interval = ballTimerInterval;

    ball -> Left = table -> Left + table -> Width/2 - ball -> Width/2;
    ball -> Top = table -> Top + table -> Height/2 - ball -> Height/2;

    leftPaddle -> Left = table -> Left + 20;
    rightPaddle -> Left = table -> Left + table -> Width - 20 - rightPaddle -> Width;
    leftPaddle -> Top = table -> Top + table -> Height/2 - leftPaddle -> Height/2;
    rightPaddle -> Top = table -> Top + table -> Height/2 - rightPaddle -> Height/2;

    ball -> Visible = true;
    BallTimer -> Enabled = true;
    rightPaddle -> Enabled = true;
    leftPaddle -> Enabled = true;
    Application -> ProcessMessages();
    Sleep(1000);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpPaddleLeftTimerTimer(TObject *Sender)
{
    if(leftPaddle -> Top > table -> Top)
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
            table -> Top + table -> Height)
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
    if(rightPaddle -> Top > table -> Top)
        rightPaddle -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DownPaddleRightTimerTimer(TObject *Sender)
{
    if(rightPaddle -> Top + rightPaddle -> Height <
            table -> Top + table -> Height)
        rightPaddle -> Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BallTimerTimer(TObject *Sender)
{
    ball -> Left += xBallMove;
    ball -> Top -= yBallMove;

    if(ball -> Top < table -> Top)
        yBallMove = -yBallMove;
    if(ball -> Top + ball -> Height > table -> Top + table -> Height)
        yBallMove = -yBallMove;
    if(ball -> Top + ball -> Height >= rightPaddle -> Top
       && ball -> Top <= rightPaddle -> Top + rightPaddle -> Height
       && ball -> Left + ball -> Width >= rightPaddle -> Left
       && ball -> Left > table -> Left + table -> Width/2)
    {
        if (speededUp == true && angleChanged == true)
        {
             ballTimerInterval +=8;
             yBallMove *= 1.5;
             speededUp = false;
             angleChanged = false;
        }
        if(ball -> Top + ball -> Height/2 > rightPaddle -> Top + rightPaddle -> Height/2 - 30
           && ball -> Top + ball -> Height/2 < rightPaddle -> Top + rightPaddle -> Height/2 + 30)
        {
            ballTimerInterval -=8;
            yBallMove /= 1.5;
            speededUp = true;
            angleChanged = true;
        }
        else
        {
        if(xBallMove > -25 && xBallMove < 25)
           xBallMove *= 1.2;
        if(yBallMove > -25 && yBallMove < 25)
           yBallMove *=1.2;
        }

        BallTimer -> Interval = ballTimerInterval;
        sndPlaySound("snd/ball.wav", SND_ASYNC);
        xBallMove = -xBallMove;
        numbOfBounces++;
    }
    else if(ball -> Top + ball -> Height >= leftPaddle -> Top
       && ball -> Top <= leftPaddle -> Top + leftPaddle -> Height
       && ball -> Left <= leftPaddle -> Left + leftPaddle -> Width
       && ball -> Left + ball -> Width < table -> Left + table -> Width/2)
    {
        if (speededUp == true && angleChanged == true)
        {
             ballTimerInterval +=8;
             yBallMove *= 1.5;
             speededUp = false;
             angleChanged = false;
        }
        if(ball -> Top + ball -> Height/2 > leftPaddle -> Top + leftPaddle -> Height/2 - 30
                && ball -> Top + ball -> Height/2 < leftPaddle -> Top + leftPaddle -> Height/2 + 30)
        {
            ballTimerInterval -=8;
            yBallMove /= 1.5;
            speededUp = true;
            angleChanged = true;
        }
        else
        {
        if(xBallMove > -25 && xBallMove < 25)
           xBallMove *= 1.2;
        if(yBallMove > -25 && yBallMove < 25)
           yBallMove *=1.2;
        }

        BallTimer -> Interval = ballTimerInterval;
        sndPlaySound("snd/ball.wav", SND_ASYNC);
        xBallMove = -xBallMove;
        numbOfBounces++;
    }
    else if(ball -> Left < leftPaddle -> Left + leftPaddle -> Width
       && ball -> Left + ball -> Width < table -> Left + table -> Width/2)
    {
        sndPlaySound("snd/loss.wav", SND_ASYNC);
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
    else if(ball -> Left + ball -> Width > rightPaddle -> Left
       && ball -> Left > table -> Left + table -> Width/2)
    {
        sndPlaySound("snd/loss.wav", SND_ASYNC);
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

    startGame(ball,rightPaddle, leftPaddle, BallTimer, table);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
     MessageDlg("Welcome To PingPong Game!\n\n"
     "The left player moves the paddle by pressing the A or Z keys.\n"
     "The right player moves the paddle by pressing the up or down arrow keys.\n\n"
     "While bouncing the ball in center of the paddle it accelerates and moves"
     " with a different angle.\n"
     "The longer you bounce the ball, the faster the ball moves.\n"
     "You can freely change the playing field.\n\nHave fun!",
     mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
    Button2 -> Left = table -> Left + table -> Width/2 - Button2 -> Width/2;
    Button3 -> Left = table -> Left + table -> Width/2 - Button3 -> Width/2;

    Label1 -> Left = table -> Left + table -> Width/2 - Label1 -> Width/2;
    Label2 -> Left = table -> Left + table -> Width/2 - Label2 -> Width/2;
    Label3 -> Left = table -> Left + table -> Width/2 - Label3 -> Width/2;
}
//---------------------------------------------------------------------------
