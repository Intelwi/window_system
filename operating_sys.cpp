//Plik zawiera funkcje obslugujace interfejs urzytkownika
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <assert.h>
#include "window.h"
#include "operating_sys.h"

//dodac pole dowpisywania tekstu
//dodac przesuwanie komponentu po np podwojnym kliknieciu

vector <Component*> data; //przechowuje dodane komponenty
vector <Component*>::iterator iter; //iterator do kontenera do usuwania

void input_int_ex(int* ans)//wprowadzenie liczby
{
    std::cin>>*ans;
    if(!std::cin) throw char('t');

    //sprawdzenie czy nie wychodzi poza okno
    if (*ans>2000 || *ans<0) throw ans;
}

int input_int()//obsługa wprowadzania z wyjatkami
{
    int ans=0;
    try
    {
        input_int_ex(&ans);//proba wczytania
    }
    catch (int *ans)//gdy wczytano zla wspolrzedna
    {
        std::cout<<"error: variable exceeded accessible range"<<endl<<"Prosze wpisac ponownie:"<<endl;
        input_int_ex(ans);
    }
    catch (...)
    {
         std::cin.clear();
         std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
         std::cout<<"error: variable not correct"<<endl<<"Prosze wpisac ponownie:"<<endl;
         input_int_ex(&ans);
    }
    return ans;
}

void fun_manage()//interfejs użytkownika -> akcja do wykonania
{
    int ans;
    while(1){
        std::cout<<"Wybierz akcję do wykonania:"<<endl<<"1.Dodaj komponent"<<endl<<"2.Usun komponent"<<endl<<"3.Kliknij"<<endl<<"4.Zakoncz"<<endl;
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

        else if(ans==4)
        {
            delete_all();
            return;
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
        std::cout<<"Wybierz komponent do edycji:"<<endl<<"1.Pole z tekstem"<<endl<<"2.Przycisk"<<endl<<"3.Checkbox"<<endl<<"4.Input label"<<endl;

        ans = input_int();

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

        else if(ans==3)
        {
            create<Checkbox>();
            break;
        }

        else if(ans==4)
        {
            create<Input_table>();
            break;
        }
        else continue;
    }
}

template<class Typ>//utworzenie komponentu
void create(){
    int x_axe=0, y_axe=0;

        std::cout<<"Podaj wspołrzedna x: "<<endl;//tworzenie każdego obiektu nowego
        x_axe=input_int();
        std::cout<<"Podaj wspołrzedna y: "<<endl;
        y_axe=input_int();
        Component *ptr = new Typ(x_axe,y_axe);
        data.push_back(ptr);
}

//------------------------------------------------------------------------
//-------------KLIKANIE_NA_KOMPONENT----------------------------------------

void click_comp()
{
    iter = data.end();
    int x_axe=0, y_axe=0;
    try
    {
        std::cout<<"Podaj wspolrzedna x:"<<endl;
        x_axe=input_int();
        std::cout<<"Podaj wspolrzedna y:"<<endl;
        y_axe=input_int();

        while (iter != data.begin())//przeszukanie kontenera od tylu - szukanie najnowszych elementow
        {
            --iter;
            Component *sign;
            if((*iter)->check(x_axe,y_axe))
            {
                (*iter)->click();
                sign = *iter;
                data.erase(iter);
                data.push_back(sign);//zamieszczenie klikniętego elementu na wierzch stosu

                return;
            }
        }
        throw string("error: component not found");
    }
    catch (string k)//obsluga wyjatkow
        {
            std::cout<<endl<<k<<endl<<endl;
        }
}


//--------------------------------------------------------------------------

void delete_comp()
{

    iter = data.end();
    int x_axe=0, y_axe=0;
    try
    {
        if(data.empty()) throw string("Brak komponentow.");//gdy nie ma komponentow

        std::cout<<"Podaj wspolrzedna x:"<<endl;
        x_axe=input_int();
        std::cout<<"Podaj wspolrzedna y"<<endl;
        y_axe=input_int();

        while (iter != data.begin())//przeszukanie kontenera od tylu - szukanie najnowszych elementow
        {
            --iter;
            if((*iter)->check(x_axe,y_axe))
            {
                delete (*iter);
                data.erase(iter);
                std::cout<<endl<<"Component erased succesfully!"<<endl<<endl;
                return;
            }
        }

        throw string("error: component not found");//gdy nie znaleziono
    }
        catch (string k)//obsluga wyjatkow
        {
            std::cout<<endl<<k<<endl<<endl;
        }
}

void delete_all()
{
    iter = data.end();
    while (iter != data.begin())//przeszukanie kontenera od tylu - szukanie najnowszych elementow
    {
        --iter;
        delete (*iter);//dealokacja wszystkich komponentów
    }

    data.clear();
    std::cout<<endl<<"Kreator zamknieto pomyslnie."<<endl;
}
