#include <iostream>
#include <locale>
#include <iomanip>
#include "menu.h"

using namespace std;

 void Menu(){
    cout << "EMBAUCADO" << endl;
    cout << "-------------------------------" << endl ;
    cout << "1 - JUGAR " << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CRÉDITOS" << endl;
    cout << "-------------------------------" << endl ;
    cout << "0 - SALIR" << endl;
 }


  void Nombres(string &jugador1, string &jugador2){
     system("cls");
     char confirmacion;
    cout << "EMBAUCADO" << endl;
    cout << "-------------------------------" << endl ;
    cout << "Antes de comenzar deben registrar sus nombres: ";
    cout << endl << endl;
    cout << "¿Nombre del Jugador 1? : ";
    cin  >> jugador1;
    cout << "¿Nombre del Jugador 2? : ";
    cin >> jugador2;
    cout << endl;
    cout << "¿Confirmar nombres? (S/N): ";
    cin >> confirmacion;
    cout << endl;

    while(confirmacion!='S'&& confirmacion!='s'){
        system("cls");
        cout << "EMBAUCADO" << endl;
        cout << "-------------------------------" << endl ;
        cout << "Antes de comenzar deben registrar sus nombres: ";
        cout << endl << endl;
        cout << "¿Nombre del Jugador 1? : ";
        cin  >> jugador1;
        cout << "¿Nombre del Jugador 2? : ";
        cin >> jugador2;
        cout << endl;
        cout << "¿Confirmar nombres? (S/N): ";
        cin >> confirmacion;
        cout << endl;
    }


 }

void MostrarResultadoFinal(int ronda, int puntajeTotalJugador1, int puntajeTotalJugador2, string &jugador1, string &jugador2, int resultadosJug1[3], int resultadosJug2[3]){

    system("cls");
   cout << "EMBAUCADO" << endl;
   cout << "-----------------------------------------------------" << endl;
   cout << "\t RONDA " << left << setw(11)<< jugador1 << "\t"<< left << setw(11) << jugador2 << endl;
   cout << "-----------------------------------------------------" << endl;
   cout << "\t 1 \t" << left << setw(11) << resultadosJug1[0] << "\t" << left << setw(11) << resultadosJug2[0] << endl;
   cout << "\t 2 \t" << left << setw(11) << resultadosJug1[1] << "\t" << left << setw(11)<< resultadosJug2[1] << endl;
   cout << "\t 3 \t" << left << setw(11) << resultadosJug1[2] << "\t" << left << setw(11)<< resultadosJug2[2] << endl;
   cout << "-----------------------------------------------------" << endl;
   cout << "\t TOTAL \t" << left << setw(11)<< puntajeTotalJugador1 << "\t" << left << setw(11)<< puntajeTotalJugador2 << endl;
   if(puntajeTotalJugador1>puntajeTotalJugador2){
        cout << "-----------------------------------------------------" << endl;
      cout << "\t GANADOR " << jugador1 << " CON " << puntajeTotalJugador1 << " PUNTOS." << endl ;
   cout << "-----------------------------------------------------" << endl;

   } else if(puntajeTotalJugador2>puntajeTotalJugador1){
       cout << "-----------------------------------------------------" << endl;
      cout << "\t GANADOR " << jugador2 << " CON " << puntajeTotalJugador2 << " PUNTOS."  << endl;
      cout << "-----------------------------------------------------" << endl;
   }  else{
            Desempatar(jugador1, jugador2, resultadosJug1, resultadosJug2);
   }
      system("pause");
}

void Desempatar(string &jugador1, string &jugador2, int resultadosJug1[3], int resultadosJug2[3]){
    int vueltaMaxJug1=0,vueltaMaxJug2=0, i;
    string ganador;
    //int vueltaMaxTotal;

    for(i=0; i<3; i++){
       if(resultadosJug1[i]>vueltaMaxJug1){
        vueltaMaxJug1=resultadosJug1[i];
       }
        if(resultadosJug2[i]>vueltaMaxJug2){
        vueltaMaxJug2=resultadosJug2[i];
       }
    }

    cout << endl << "Al igualar el puntaje total se procede a un desempate" << endl;
    cout << endl << "Resulta ganador el jugador con mas puntos en una sola ronda." << endl;

    if(vueltaMaxJug1>vueltaMaxJug2){
      cout << "-----------------------------------------------------" << endl;
      cout << "\t GANADOR " << jugador1 << " CON " << vueltaMaxJug1 << " PUNTOS."  << endl;
      cout << "-----------------------------------------------------" << endl;
    }else if(vueltaMaxJug2>vueltaMaxJug1){
      cout << "-----------------------------------------------------" << endl;
      cout << "\t GANADOR " << jugador2 << " CON " << vueltaMaxJug2 << " PUNTOS."  << endl;
      cout << "-----------------------------------------------------" << endl;
    }else{
       cout << "-----------------------------------------------------" << endl;
      cout << "\t SE DETERMINA EMPATE POR IGUALAR EN MAYOR CANTIDAD DE PUNTOS EN UNA SOLA RONDA "  << endl;
      cout << "-----------------------------------------------------" << endl;
    }
}

void Estadisticas(int &puntajeRecord, string &jugadorRecord){
    system("cls");
      cout << "EMBAUCADO" << endl;
      cout << "-------------------------------" << endl ;
      cout << "PUNTAJE RECORD: " << puntajeRecord << "  " << jugadorRecord << endl;
      cout << "-------------------------------" << endl;
      system("pause");
}


void Creditos(){
    system("cls");
    cout << "EMBAUCADO" << endl;
    cout << "-------------------------------" << endl ;
    cout << "CRÉDITOS" << endl;
    cout << "-------------------------------" << endl ;
    cout << "IDEA ORIGINAL: \t ÁNGEL SIMÓN" << endl ;
    cout << endl ;
    cout << "DESARROLLADO POR: GRUPO N°50 PROGRAMACIÓN I - UTN FRGP" << endl ;
    cout << endl ;
    cout << "MC CORMACH, FLORENCIA AGUSTINA \t Legajo: 31041" << endl ;
    cout << "CELIS, EMANUEL ALEJANDRO \t Legajo: 30284" << endl ;
    cout << "ZABALA, NICOLAS LEANDRO \t Legajo: 30655" << endl ;
    cout << "CAMPOS POLO, ANA PAOLA  \t Legajo: 25837" << endl ;
    cout << "-------------------------------" << endl ;


    system("pause");
}


 void MostrarPuntajeRonda(string &jugador, int &puntajeJugador, int vecManoJugador[5], string embaucadora){
    int i, codigo, puntajeNaipe;
    string valor, figura;

    cout  << "Puntaje " << left << setw(11) <<jugador << ": ";
    for(i=0;i<5;i++){
            vecManoJugador[i];
            codigo = vecManoJugador[i];
            Naipes(codigo, valor, figura);  // transforma el valor en una carta

            puntajeNaipe=CalcularPuntaje(valor, figura, embaucadora);

            cout  <<  puntajeNaipe ;   //muestra la carta
            if(i<4){
              cout << " + ";
            }

         }
         cout << " = " << puntajeJugador;
       }

