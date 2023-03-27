//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int liczby[1000];
bool gra_rozpoczeta = false;
int ile=0;
int licznik=0;

void sekwencja()
{
    Application->ProcessMessages(); Sleep(1000);

    Form1->z1->Picture->LoadFromFile("img/p1.bmp");
    Form1->z2->Picture->LoadFromFile("img/p2.bmp");
    Form1->z3->Picture->LoadFromFile("img/p3.bmp");
    Form1->z4->Picture->LoadFromFile("img/p4.bmp");
    Form1->z5->Picture->LoadFromFile("img/p5.bmp");

    Form1->z1->Enabled = false;
    Form1->z2->Enabled = false;
    Form1->z3->Enabled = false;
    Form1->z4->Enabled = false;
    Form1->z5->Enabled = false;

    Form1->Label1->Caption = "Nastêpna runda za: 2";
    Application->ProcessMessages(); Sleep(1000);
    Form1->Label1->Caption = "Nastêpna runda za: 1";
    Application->ProcessMessages(); Sleep(1000);

    Form1->Label1->Caption = "Zapamiêtaj sekwencjê";
    Application->ProcessMessages(); Sleep(1000);

    ile++;
    for (int i=0; i<ile; i++)
    {
       switch(liczby[i])
       {
          case 1:
          {
          sndPlaySound("snd/d1.wav",SND_ASYNC);
          Form1->z1a->Visible = true;
          } break;

          case 2:
          {
          sndPlaySound("snd/d2.wav",SND_ASYNC);
          Form1->z2a->Visible = true;
          } break;

          case 3:
          {
          sndPlaySound("snd/d3.wav",SND_ASYNC);
          Form1->z3a->Visible = true;
          } break;

          case 4:
          {
          sndPlaySound("snd/d4.wav",SND_ASYNC);
          Form1->z4a->Visible = true;
          } break;

          case 5:
          {
          sndPlaySound("snd/d5.wav",SND_ASYNC);
          Form1->z5a->Visible = true;
          } break;

       }//switch
       Application->ProcessMessages(); Sleep(1200);
       Form1->z1a->Visible = false;
       Form1->z2a->Visible = false;
       Form1->z3a->Visible = false;
       Form1->z4a->Visible = false;
       Form1->z5a->Visible = false;
       Application->ProcessMessages(); Sleep(100);
    }//for

    Form1->z1->Enabled = true;
    Form1->z2->Enabled = true;
    Form1->z3->Enabled = true;
    Form1->z4->Enabled = true;
    Form1->z5->Enabled = true;
    Form1->Label1->Caption = "Powtórz sekwencjê";
    licznik=0;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   randomize();
   for(int i=0; i<1000; i++)
   {
      liczby[i] = random(5)+1;
   }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
   if(gra_rozpoczeta == false)
   {
     gra_rozpoczeta = true;
     sndPlaySound("snd/start.wav",SND_ASYNC);
     sekwencja();
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z1Click(TObject *Sender)
{
   if(gra_rozpoczeta == true)
   {
      licznik++;
      if(liczby[licznik-1]!=1)
      {
         ile--;
         Label1->Caption = "Skucha! twój wynik: "+IntToStr(ile);
         sndPlaySound("snd/koniec.wav",SND_ASYNC);
         gra_rozpoczeta = false;
      }
      if(licznik == ile)
      {
         Label1->Caption = "Doskonale!";
         sekwencja();
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z2Click(TObject *Sender)
{
   if(gra_rozpoczeta == true)
   {
      licznik++;
      if(liczby[licznik-1]!=2)
      {
         ile--;
         Label1->Caption = "Skucha! twój wynik: "+IntToStr(ile);
         sndPlaySound("snd/koniec.wav",SND_ASYNC);
         gra_rozpoczeta = false;
      }
      if(licznik == ile)
      {
         Label1->Caption = "Doskonale!";
         sekwencja();
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z3Click(TObject *Sender)
{
   if(gra_rozpoczeta == true)
   {
      licznik++;
      if(liczby[licznik-1]!=3)
      {
         ile--;
         Label1->Caption = "Skucha! twój wynik: "+IntToStr(ile);
         sndPlaySound("snd/koniec.wav",SND_ASYNC);
         gra_rozpoczeta = false;
      }
      if(licznik == ile)
      {
         Label1->Caption = "Doskonale!";
         sekwencja();
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z4Click(TObject *Sender)
{
   if(gra_rozpoczeta == true)
   {
      licznik++;
      if(liczby[licznik-1]!=4)
      {
         ile--;
         Label1->Caption = "Skucha! twój wynik: "+IntToStr(ile);
         sndPlaySound("snd/koniec.wav",SND_ASYNC);
         gra_rozpoczeta = false;
      }
      if(licznik == ile)
      {
         Label1->Caption = "Doskonale!";
         sekwencja();
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z5Click(TObject *Sender)
{
   if(gra_rozpoczeta == true)
   {
      licznik++;
      if(liczby[licznik-1]!=5)
      {
         ile--;
         Label1->Caption = "Skucha! twój wynik: "+IntToStr(ile);
         sndPlaySound("snd/koniec.wav",SND_ASYNC);
         gra_rozpoczeta = false;
      }
      if(licznik == ile)
      {
         Label1->Caption = "Doskonale!";
         sekwencja();
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z1MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z1->Picture->LoadFromFile("img/p1a.bmp");
    sndPlaySound("snd/d1.wav",SND_ASYNC);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::z1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z1->Picture->LoadFromFile("img/p1.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z2MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z2->Picture->LoadFromFile("img/p2a.bmp");
    sndPlaySound("snd/d2.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z2->Picture->LoadFromFile("img/p2.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z3MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z3->Picture->LoadFromFile("img/p3a.bmp");
    sndPlaySound("snd/d3.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z3->Picture->LoadFromFile("img/p3.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z4MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z4->Picture->LoadFromFile("img/p4a.bmp");
    sndPlaySound("snd/d4.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z4MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z4->Picture->LoadFromFile("img/p4.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z5MouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z5->Picture->LoadFromFile("img/p5a.bmp");
    sndPlaySound("snd/d5.wav",SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::z5MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    z5->Picture->LoadFromFile("img/p5.bmp");
}
//---------------------------------------------------------------------------
