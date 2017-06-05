//Plik zawiera metody klas z pliku window.h
#include <iostream>
#include <vector>
#include <limits>
#include "window.h"

//--------------Component-------------------------------------------------------
int Component::check(int x_axe, int y_axe)//funkcja sprawdzajaca na co kliknal uzytkownik, jako parametry dostaje wspolrzedne ktore nalezy sprawdzic
{
    if (x_axe>=(this->x) && x_axe<=(this->x)+(this->length))
    {
        if(y_axe>=(this->y) && y_axe<=(this->y)+(this->high)) return 1;
        else return 0;
    }
    else return 0;
}

//------------Text--------------------------------------------------------------------
void Text::click()
{
    std::cout<<endl<<text_show<<endl;
}

string Text::return_value()//zwraca przechowywaną zawartość - potrzebne do listy
{
    return text_show;
}
//-----------Button--------------------------------------------------------------------
void Button::click()//funkcja klikajaca na obiekt
{
    std::cout<<endl<<"Button clicked!"<<endl<<endl;

}

//-----------Checkbox------------------------------------------------------------------
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

//----------Input_table-----------------------------------------------------------------
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

//----------List------------------------------------------------------------------------
void List::click()
{
    for(int i=0; i<3; i++)
    {
        Text* button_1 = new Text(this->x,(this->y)+8 , 20, 8, "Option ");//tworzenie rozwijanej listy
        lista[i] = button_1;
    }
    choose();//wybór elementu
    for(int i=0; i<3; i++)
    {
        delete lista[i];//zwijanie listy
    }
}

void List::choose()
{
    int ans;
    std::cout<<"Current choice: "<<text_show<<endl<<"Choose option from the list:"<<endl;
    for(int i=0; i<3; i++)
    {
        lista[i]->click();
    }

    while(1)
    {
        cin>>ans;
        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        else if (ans>2 || ans<0) continue;
        else break;
    }

    if(ans==0) text_show = lista[0]->return_value();
    else if (ans==1) text_show = return_value();
    else text_show = lista[2]->return_value();

}
