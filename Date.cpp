//
// Created by Radu Ursu on 17/11/23.
//
#include <iostream>
#include "Date.h"
using namespace std;


Date:: Date (int g, int m, int a){
    if (val(g,m,a)){
        this->g=g;
        this->m=m;
        this->a=a;
    }
    else{
        this->g=0;
        this->m=0;
        this->a=0;
    }

}

bool Date :: val(int g, int m, int a){
    if ((g>31) || (m>12)) return 0;                                               //controllo il giorno e il mese
    else if ((m==11 || m==4 || m==6 || m==9) && (g>30)) return 0;                 //controllo che i mesi rispettivi non abbiano più di 30g
    else if (a/4 != 0 && m==2 && g>28) return 0;                                  //nell'anno bisestile febbraio non deve avere più di 28g
    else return 1;
}

void Date :: out(){
    if(g==0) cout << "Data non valida" << endl;
    cout << g << "/" << m << "/" << a << endl;
}
