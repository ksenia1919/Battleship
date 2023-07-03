object Form4: TForm4
  Left = 0
  Top = 0
  ClientHeight = 365
  ClientWidth = 462
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnActivate = FormActivate
  TextHeight = 15
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 93
    Height = 25
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 152
    Top = 296
    Width = 161
    Height = 33
    Caption = #1042' '#1073#1086#1081'!'
    Enabled = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Sylfaen'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object RadioGroup1: TRadioGroup
    Left = 24
    Top = 56
    Width = 185
    Height = 49
    Caption = #1042#1074#1086#1076' '#1082#1086#1086#1088#1076#1080#1085#1072#1090
    Items.Strings = (
      #1056#1091#1095#1085#1086#1081)
    TabOrder = 1
    OnClick = RadioGroup1Click
  end
  object RadioGroup2: TRadioGroup
    Left = 24
    Top = 136
    Width = 185
    Height = 121
    Caption = #1059#1088#1086#1074#1077#1085#1100' '#1089#1083#1086#1078#1085#1086#1089#1090#1080
    Items.Strings = (
      #1051#1077#1075#1082#1080#1081
      #1057#1088#1077#1076#1085#1080#1081
      #1057#1083#1086#1078#1085#1099#1081)
    TabOrder = 2
    OnClick = RadioGroup2Click
  end
  object RadioGroup3: TRadioGroup
    Left = 280
    Top = 56
    Width = 121
    Height = 201
    Caption = #1062#1074#1077#1090' '#1082#1086#1088#1072#1073#1083#1103
    Items.Strings = (
      #1057#1077#1088#1099#1081
      #1046#1105#1083#1090#1099#1081
      #1047#1077#1083#1105#1085#1099#1081
      #1060#1080#1086#1083#1077#1090#1086#1074#1099#1081
      #1056#1086#1079#1086#1074#1099#1081)
    TabOrder = 3
    OnClick = RadioGroup3Click
  end
  object Button2: TButton
    Left = 24
    Top = 296
    Width = 93
    Height = 33
    Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 429
    Top = 8
    Width = 25
    Height = 25
    Caption = '?'
    TabOrder = 5
    OnClick = Button3Click
  end
end
