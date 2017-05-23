#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <assert.h>
#include "window.h"

vector < Component* > Data; //przechowuje dodane komponenty

void fun_manage_iter(Component *wsk){//operownie wskaźnikiem na dowolny komponent


}

void add_comp()
{


}

void delete_comp()
{


}

void click_comp()
{



}

















/*
//-----------------------ZAPRZYJAZNIONE_WEJŚCIE_WYJSCIE-------------------------------------------

ostream & operator<< (ostream &wyjscie, const Bufor &s) {
    #if DEBUG
        return wyjscie <<"Zawartosć obiektu to: "<<endl<<s.tab<<endl;//wypisanie zawartosci bufora
    #endif
    #if NDEBUG
        return wyjscie <<s.tab<<endl;//wypisanie zawartosci bufora
    #endif

   }

istream & operator>> (istream &wejscie, Bufor &s) {
    unsigned char line[50]={0};
    string tmp;

    #if DEBUG
        std::cout<<"Wprowadz dane do obiektu(49 znk max):"<<endl;
    #endif

    wejscie>>tmp;
    assert(wejscie.good());//sprawdzenie czy wszystko ok
    strncpy((char*)line, tmp.c_str(), sizeof(line)-1);//skopiowanie stringa do chara
    s.wpisywanie(line);//wpisanie do bufora
    return wejscie;
}

//---------------------ZAPRZYJAŹNIONA_TEST--------------------------------------------------------------------

bool compare(const Bufor &pom, const unsigned char pom_ch[]){
    bool check=false;

    for(int i=0;i<pom.MAX;i++){
        if(pom.tab[i]==pom_ch[i]) check=true;
        else {
            check=false;
            break;
            }
    }
    return check;
}
*/
