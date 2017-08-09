object FormExample: TFormExample
  Left = 223
  Top = 137
  Width = 349
  Height = 147
  Caption = 'FormExample'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 152
    Top = 24
    Width = 33
    Height = 13
    Caption = 'Result:'
  end
  object EdtInp: TEdit
    Left = 16
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object btnMake: TButton
    Left = 128
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Make'
    TabOrder = 1
    OnClick = btnMakeClick
  end
  object EdtOut: TEdit
    Left = 192
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 2
  end
end
