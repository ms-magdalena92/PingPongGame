object Form1: TForm1
  Left = 221
  Top = 114
  Width = 986
  Height = 528
  Caption = 'Ping Pong Game'
  Color = clWindow
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCanResize = FormCanResize
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object table: TShape
    Left = 0
    Top = 0
    Width = 970
    Height = 490
    Align = alClient
    Brush.Color = clTeal
    Pen.Color = clTeal
  end
  object Label1: TLabel
    Left = 344
    Top = 216
    Width = 281
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = 'NUMBER OF BOUNCES: '
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label3: TLabel
    Left = 304
    Top = 64
    Width = 371
    Height = 29
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Caption = '<-  SCORE FOR THE LEFT PLAYER'
    Color = clRed
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -24
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentBiDiMode = False
    ParentColor = False
    ParentFont = False
    Visible = False
  end
  object Label2: TLabel
    Left = 432
    Top = 136
    Width = 113
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Caption = '1:0'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object leftPaddle: TShape
    Left = 8
    Top = 144
    Width = 25
    Height = 200
    Brush.Color = clRed
    Enabled = False
    Pen.Color = clMaroon
    Pen.Width = 3
  end
  object rightPaddle: TShape
    Left = 936
    Top = 136
    Width = 25
    Height = 200
    Brush.Color = clRed
    Enabled = False
    Pen.Color = clMaroon
    Pen.Width = 3
  end
  object ball: TShape
    Left = 456
    Top = 248
    Width = 65
    Height = 45
    Brush.Color = clYellow
    Pen.Color = clOlive
    Pen.Width = 3
    Shape = stCircle
  end
  object Button1: TButton
    Left = 392
    Top = 368
    Width = 193
    Height = 41
    Cursor = crHandPoint
    Caption = 'NEW GAME'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 392
    Top = 296
    Width = 193
    Height = 41
    Cursor = crHandPoint
    Caption = 'NEXT ROUND'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    Visible = False
    OnClick = Button3Click
  end
  object Button2: TButton
    Left = 392
    Top = 368
    Width = 193
    Height = 41
    Cursor = crHandPoint
    Caption = 'NEW GAME'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    Visible = False
    OnClick = Button2Click
  end
  object UpPaddleLeftTimer: TTimer
    Enabled = False
    Interval = 5
    OnTimer = UpPaddleLeftTimerTimer
    Left = 32
    Top = 24
  end
  object DownPaddleLeftTimer: TTimer
    Enabled = False
    Interval = 5
    OnTimer = DownPaddleLeftTimerTimer
    Left = 32
    Top = 432
  end
  object UpPaddleRightTimer: TTimer
    Enabled = False
    Interval = 5
    OnTimer = UpPaddleRightTimerTimer
    Left = 912
    Top = 24
  end
  object DownPaddleRightTimer: TTimer
    Enabled = False
    Interval = 5
    OnTimer = DownPaddleRightTimerTimer
    Left = 912
    Top = 432
  end
  object BallTimer: TTimer
    Enabled = False
    Interval = 1
    OnTimer = BallTimerTimer
    Left = 472
    Top = 432
  end
end
