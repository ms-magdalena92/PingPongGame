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
        void __fastcall UpPaddleLeftTimerTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall DownPaddleLeftTimerTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall UpPaddleRightTimerTimer(TObject *Sender);
        void __fastcall DownPaddleRightTimerTimer(TObject *Sender);
        void __fastcall BallTimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
