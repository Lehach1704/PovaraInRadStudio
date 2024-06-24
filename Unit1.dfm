object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Povara'
  ClientHeight = 445
  ClientWidth = 555
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object FirstContButton: TButton
    Left = 24
    Top = 384
    Width = 129
    Height = 41
    Caption = #1050#1086#1085#1090#1077#1081#1085#1077#1088' 1'
    TabOrder = 0
    OnClick = FirstContButtonClick
  end
  object SecondContButton: TButton
    Left = 216
    Top = 384
    Width = 129
    Height = 41
    Caption = #1050#1086#1085#1090#1077#1081#1085#1077#1088' 2'
    TabOrder = 1
    OnClick = SecondContButtonClick
  end
  object ThirdContButton: TButton
    Left = 408
    Top = 384
    Width = 129
    Height = 42
    Caption = #1050#1086#1085#1090#1077#1081#1085#1077#1088' 3'
    TabOrder = 2
    OnClick = ThirdContButtonClick
  end
  object EditA: TEdit
    Left = 24
    Top = 16
    Width = 513
    Height = 23
    TabOrder = 3
    TextHint = #1042#1074#1077#1076#1080#1090#1077' '#1095#1080#1089#1083#1086' '#1087#1086#1074#1072#1088#1086#1074
  end
  object StructureDB: TVirtualStringTree
    Left = 24
    Top = 45
    Width = 513
    Height = 292
    DefaultNodeHeight = 19
    Header.AutoSizeIndex = 0
    Header.Options = [hoColumnResize, hoDrag, hoShowImages, hoShowSortGlyphs, hoVisible]
    TabOrder = 4
    OnGetText = StructureDBGetText
    Touch.InteractiveGestures = [igPan, igPressAndTap]
    Touch.InteractiveGestureOptions = [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical, igoPanInertia, igoPanGutter, igoParentPassthrough]
    Columns = <
      item
        Position = 0
        Text = 'Cooker'
        Width = 100
      end
      item
        Position = 1
        Text = 'Race'
        Width = 100
      end
      item
        Position = 2
        Text = 'ColorClothes'
        Width = 99
      end
      item
        Position = 3
        Text = 'Glasses'
        Width = 71
      end>
  end
  object ProgressBar1: TProgressBar
    Left = 24
    Top = 341
    Width = 513
    Height = 21
    TabOrder = 5
  end
  object OpenDBDialog: TOpenDialog
    Left = 168
    Top = 384
  end
end
