#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <assert.h>
#include "window.h"
#include "operating_sys.h"

//-------------DODAWANIE-------------------------------------------------------------
vector < Component* > data; //przechowuje dodane komponenty


void add_comp()//dodanie komponentu
{
    choose_component();//wybranie komponentu
}

template<class Typ>//utworzenie komponentu
void create(){
    Component *ptr = new Typ;
    data.push_back(ptr);
}

//------------------------------------------------------------------------

void delete_comp()
{


}

void click_comp()
{



}


void fun_manage()//operownie wskaźnikiem na dowolny komponent
{
    int ans;
    while(1){
        std::cout<<"Wybierz akcję do wykonania:"<<endl<<"1.Dodaj komponent"<<endl<<"2.Usun komponent"<<endl<<"3.Kliknij"<<endl;
        std::cin>>ans;
        while(!std::cin)
        {
            std::cin>>ans;
            std::cin.clear();
            std::cin.sync();
        }

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

void choose_component(){//wybranie komponentu
     int ans;
    while(1){
        std::cout<<"Wybierz komponent do edycji:"<<endl<<"1.Pole z tekstem"<<endl<<"2.Przycisk"<<endl;
        std::cin>>ans;
        while(!std::cin)
        {
            std::cin>>ans;
            std::cin.clear();
            std::cin.sync();
        }

        if(ans==1)
        {
            create<Text>();//stworzenie komponentu
            break;
        }

        else if(ans==2)
        {
            create<Button>();//stworzenie komponentu
            break;
        }
        else continue;
    }
}
