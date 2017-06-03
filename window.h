//Plik zawiera klasy komponentow
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;


//-------------KOMPONENT----------------------------------------------------------------------------------

class Component
{
    private:
    int x; //wspolrzedna x komponentu (dolny lewy rog)
    int y; //wspolrzedna y komponentu (dolny lewy rog)
    int length; //długość komponentu
    int high; //wysokość komponentu

    public:
        Component(int x_axe=0, int y_axe=0, int length_p=50, int high_p=30):
        x(x_axe),y(y_axe),length(length_p),high(high_p){}//konstruktor
        virtual ~Component(){}//destruktor
        virtual void click()=0;
        int check(int x_axe, int y_axe);//sprawdzenie gdzie kliknieto
};




//-------------TEKST-------------------------------------------------------------------------------------


class Text :public Component
{
    string text_show; //tekst do wyświetlania

   public:
        Text (int x_axe=0, int y_axe=0, int length_p=50, int high_p=30, string text_p = "Hello word!"):
        Component(x_axe,y_axe,length_p,high_p), text_show(text_p){}

        virtual ~Text(){}
        virtual void click();
};


//-------------PRZYCISK----------------------------------------------------------------------------------


class Button :public Text
{

   public:
        Button (int x_axe=0, int y_axe=0, int length_p=20, int high_p=15,string tekst_p = "Click Button"):
        Text(x_axe,y_axe,length_p,high_p,tekst_p){}

        ~Button(){}

        virtual void click();
};

//-------------CHECKBOX----------------------------------------------------------------------------------

class Checkbox :public Text// a moze moze dziedziczyc po przycisku?
{
    bool if_ticked; //info czy jest zaznaczony
   public:
        Checkbox (int x_axe=0, int y_axe=0, int length_p=8, int high_p=8,string tekst_p = "Tick Checkbox",bool if_ticked_par = false):
        Text(x_axe,y_axe,length_p,high_p,tekst_p), if_ticked(if_ticked_par){}

        ~Checkbox(){}

        virtual void click();
};


//----------------INPUT_TABLE-------------------------------------------------------------------------------

class Input_table :public Text
{
    string input_txt;

   public:
        Input_table (int x_axe=0, int y_axe=0, int length_p=30, int high_p=10,string tekst_p = "Type sentence"):
        Text(x_axe,y_axe,length_p,high_p,tekst_p){}

        ~Input_table(){}

        virtual void click();
        void type_in();
};
