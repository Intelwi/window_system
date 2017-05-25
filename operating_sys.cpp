//Plik zawiera funkcje obslugujace interfejs urzytkownika
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <assert.h>
#include "window.h"
#include "operating_sys.h"


vector <Component*> data; //przechowuje dodane komponenty
vector <Component*>::reverse_iterator iter; //iterator do kontenera

int input_int()
{
    int ans;
    std::cin>>ans;
    while(!std::cin)
        {
            std::cin.clear();
            std::cin.sync();
            std::cin>>ans;
        }
    return ans;
}

void fun_manage()//interfejs użytkownika -> akcja do wykonania
{
    int ans;
    while(1){
        std::cout<<"Wybierz akcję do wykonania:"<<endl<<"1.Dodaj komponent"<<endl<<"2.Usun komponent"<<endl<<"3.Kliknij"<<endl;
        ans = input_int();

        if(ans==1)
        {
            add_comp();//dodanie komponentu
        }

        else if(ans==2)
        {
            delete_comp();//usunięcie komponentu
        }

        else if(ans==3)
        {
            click_comp();//kliknięcie na komponent
        }

        else continue;
    }
}

//-------------DODAWANIE-------------------------------------------------------------

void add_comp()//dodanie komponentu
{
    choose_component();//wybranie komponentu
}

//-------------------------------------------------------------------------------------

void choose_component(){//interfejs użytkownika -> komponent do wybrania
     int ans;
    while(1){
        std::cout<<"Wybierz komponent do edycji:"<<endl<<"1.Pole z tekstem"<<endl<<"2.Przycisk"<<endl<<"3.Checkbox"<<endl;

        ans = input_int();
        if(ans==1)
        {
            create<Text>(ans);//stworzenie komponentu
            break;
        }

        else if(ans==2)
        {
            create<Button>(ans);//stworzenie komponentu
            break;
        }

        else if(ans==3)
        {
            create<Checkbox>(ans);
            break;
        }
        else continue;
    }
}

template<class Typ>//utworzenie komponentu
void create(int ans){
    int x_axe=0, y_axe=0;
   // if (ans==1)//tworzenie tekstu
   // {
        std::cout<<"Podaj wspołrzedna x: "<<endl;//tworzenie każdego obiektu nowego
        x_axe=input_int();
        std::cout<<"Podaj wspołrzedna y: "<<endl;
        y_axe=input_int();
        Component *ptr = new Typ(x_axe,y_axe);
        data.push_back(ptr);
   // }

    /*else if (ans==2)//tworzenie przycisku
    {
        Component *ptr = new Typ;
        data.push_back(ptr);
    }

    else if (ans==3)//tworzenie checkbox
    {
        Component *ptr = new Typ;
        data.push_back(ptr);
    }
*/
}

//------------------------------------------------------------------------
//-------------KLIKANIE_NA_KOMPONENT----------------------------------------

void click_comp()
{
    int x_axe=0, y_axe=0;
    std::cout<<"Podaj wspolrzedna x:"<<endl;
    x_axe=input_int();
    std::cout<<"Podaj wspolrzedna y"<<endl;
    y_axe=input_int();

    for(iter=data.rbegin();iter!=data.rend();++iter)//przeszukanie kontenera od tylu - szukanie najnowszych elementow
    {
        if((*iter)->check(x_axe,y_axe))
        {
            (*iter)->click();
            return;
        }
    }
    std::cout<<endl<<"error: component not found"<<endl<<endl;
}


//--------------------------------------------------------------------------

void delete_comp()
{


}
