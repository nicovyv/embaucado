#include <iostream>
#include <locale>
#include "menu.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "Spanish");
    srand(time(0));  // semilla random
    int puntajeRecord=0;
    string jugadorRecord;
    MenuPrincipal(puntajeRecord, jugadorRecord);

    return 0;
}
