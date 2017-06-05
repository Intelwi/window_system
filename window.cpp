//Plik zawiera metody klas z pliku window.h
#include <iostream>
#include <vector>
#include "window.h"


int Component::check(int x_axe, int y_axe)//funkcja sprawdzajaca na co kliknal uzytkownik, jako parametry dostaje wspolrzedne ktore nalezy sprawdzic
{
    if (x_axe>=(this->x) && x_axe<=(this->x)+(this->length))
    {
        if(y_axe>=(this->y) && y_axe<=(this->y)+(this->high)) return 1;
        else return 0;
    }
    else return 0;
}

void Text::click(){};

void Button::click()//funkcja klikajaca na obiekt
{
    std::cout<<endl<<"Button clicked!"<<endl<<endl;

}

void Checkbox::click()//funkcja klikajaca na obiekt
{
    if (if_ticked)
    {
        if_ticked=false;
        std::cout<<endl<<"Checkbox unticked!"<<endl<<endl;
    }
    else
    {
        if_ticked=true;
        std::cout<<endl<<"Checkbox ticked!"<<endl<<endl;
    }
}

void Input_table::click()//funkcja klikajaca na obiekt
{
    std::cout<<"Current sentence: "<<endl<<text_show<<endl<<"Type new sentence:"<<endl;
    type_in();
}

void Input_table::type_in()
{
    std::cin>>text_show;
    std::cout<<endl;
}
