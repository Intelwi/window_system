#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <assert.h>
#include "window.h"
#include "operating_sys.h"


vector < Component* > data; //przechowuje dodane komponenty

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
            break;
        }

        else if(ans==2)
        {
            delete_comp();//usunięcie komponentu
            break;
        }

        else if(ans==3)
        {
            click_comp();//kliknięcie na komponent
            break;
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
    int x_1=0, y_1=0;
   // if (ans==1)//tworzenie tekstu
   // {
        std::cout<<"Podaj wspołrzedna x: "<<endl;//tworzenie każdego obiektu nowego
        x_1=input_int();
        std::cout<<"Podaj wspołrzedna y: "<<endl;
        y_1=input_int();
        Component *ptr = new Typ(x_1,y_1);
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
//-------------KLIKANIE_KOMPONENTU----------------------------------------

void click_comp()
{



}











//--------------------------------------------------------------------------

void delete_comp()
{


}
