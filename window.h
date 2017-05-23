#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
using namespace std;


//-------------KOMPONENT----------------------------------------------------------------------------------

class Component
{
    private:
    int x; //wspolrzedna x komponentu
    int y; //wspolrzedna y komponentu

    public:
        Component(int x_axe=0, int y_axe=0): x(x_axe),y(y_axe){}//konstruktor
        ~Component(){}//destruktor
        virtual void click()=0;
};
//-------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------


//-------------TEKST-------------------------------------------------------------------------------------


class Text :public Component
{
    string text_show; //tekst do wyświetlania
    int length; //długość ramki z tekstem
    int high; //wysokość ramki z tekstem

   public:
        Text (int x_axe=0, int y_axe=0, string text_p = "Hello word!", int length_p=50, int high_p=30):
        Component(x_axe,y_axe), text_show(text_p), length(length_p), high(high_p){}

        ~Text(){}
        virtual void click(){};
};


//-------------PRZYCISK----------------------------------------------------------------------------------


class Button :public Text
{

   public:
        Button (int x_axe=0, int y_axe=0, string tekst_p = "Click Button", int length_p=50, int high_p=30):
        Text(x_axe,y_axe,tekst_p,length_p,high_p){}

        ~Button(){}

        virtual void click()
        {
            cout<<"Button clicked!";
        }
};
