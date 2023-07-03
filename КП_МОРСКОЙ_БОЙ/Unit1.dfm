object Registration: TRegistration
  Left = 0
  Top = 0
  Caption = #1056#1077#1075#1080#1089#1090#1088#1072#1094#1080#1103
  ClientHeight = 395
  ClientWidth = 697
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Visible = True
  OnCreate = FormCreate
  TextHeight = 15
  object Image1: TImage
    Left = -16
    Top = 0
    Width = 810
    Height = 460
    Center = True
    Proportional = True
  end
  object Label1: TLabel
    Left = 40
    Top = 103
    Width = 24
    Height = 15
    Caption = #1048#1084#1103
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 32
    Top = 143
    Width = 42
    Height = 15
    Caption = '* E-mail'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 336
    Top = 70
    Width = 276
    Height = 48
    Caption = #1052#1086#1088#1089#1082#1086#1081' '#1073#1086#1081
    Font.Charset = ANSI_CHARSET
    Font.Color = clWhite
    Font.Height = -48
    Font.Name = 'Stylo'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 40
    Top = 352
    Width = 205
    Height = 13
    Caption = '* '#1055#1088#1080' '#1086#1090#1089#1091#1090#1089#1090#1074#1080#1080' e-mail '#1087#1086#1089#1090#1072#1074#1090#1077'  " '#8212' "'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 88
    Top = 100
    Width = 161
    Height = 23
    Cursor = crIBeam
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 88
    Top = 140
    Width = 161
    Height = 23
    TabOrder = 1
  end
  object Button1: TButton
    Left = 40
    Top = 184
    Width = 209
    Height = 25
    Caption = #1047#1072#1088#1077#1075#1080#1089#1090#1088#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
end
