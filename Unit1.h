//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *table;
        TImage *rightPaddle;
        TImage *leftPaddle;
        TImage *ball;
        TTimer *UpPaddleLeftTimer;
        TTimer *DownPaddleLeftTimer;
        TTimer *UpPaddleRightTimer;
        TTimer *DownPaddleRightTimer;
        TTimer *BallTimer;
        TButton *Button1;
        TButton *Button3;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label2;
        TButton *Button2;
        void __fastcall UpPaddleLeftTimerTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall DownPaddleLeftTimerTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall UpPaddleRightTimerTimer(TObject *Sender);
        void __fastcall DownPaddleRightTimerTimer(TObject *Sender);
        void __fastcall BallTimerTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
