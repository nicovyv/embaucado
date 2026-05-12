#include <iostream>
#include <iomanip>
#include <locale>
#include <cstdlib>
#include <ctime>
#include "menu.h"

using namespace std;

void MenuPrincipal(int puntajeRecord, string jugadorRecord){
    int opcion;
    bool opc=true; // variable para el inicio del bucle
    string jugador1, jugador2;

    while (opc){    // inicio del bucle

        system("cls");
        Menu();   // muestra el menu principal
        opcion=SeleccionarOpcion();   // retorna un valor int como opción para ser evaluada en el switch

        switch(opcion){    // se evalua la opción
        case 1:         // desarrollo del juego
               Nombres(jugador1, jugador2);
               Ronda(jugador1, jugador2, puntajeRecord, jugadorRecord );
            break;
        case 2:      // estadisticas
            Estadisticas(puntajeRecord, jugadorRecord);
            break;
        case 3:
                Creditos();
            break;
        case 0:     // fin del bucle
            char salir;
            while(salir != 'S' && salir != 's' && salir != 'N' && salir != 'n'){

                system("cls");
                cout << "EMBAUCADO" << endl;
                cout << "-------------------------------" << endl ;
                cout << endl <<  " ¿Desea salir del juego? S/N" << endl ;
                cout << "-------------------------------" << endl ;
                cin >> salir;
            }

        if(salir=='S'||salir=='s'){
            system("cls");
            cout << "EMBAUCADO" << endl;
            cout << "-------------------------------" << endl ;
            cout << endl <<  " Gracias por jugar al Embaucado!" << endl ;
            cout << "-------------------------------" << endl << endl ;
            system("pause");
            opc=false;
            }else if(salir=='N'||salir=='n'){
                MenuPrincipal(puntajeRecord,jugadorRecord);
                }
            break;
        default:
            cout << endl;
            cout << "EMBAUCADO"<< endl;
            cout << "-------------------------------" << endl ;
            cout << endl <<  " Opción Incorrecta " << endl << endl;
         system ("pause");

            break;
        }

    }
}

    void Ronda(string &jugador1, string &jugador2, int &puntajeRecord, string &jugadorRecord){

        int ronda=1, i;
        int puntajeTotalJug1=0, puntajeTotalJug2=0;  // acumuladores

        int resultadosJug1[3];   // resultados de las tres rondas
        int resultadosJug2[3];


        for(i=0; i<3; i++){      // tres rondas
           system("cls");
            cout << "EMBAUCADO" << endl ;
             cout << "-------------------------------" << endl ;
            cout << " \t " << "RONDA #" << ronda << endl << endl;      // numero de ronda
            cout  << " \t "  << jugador1 << " Vs. " <<  jugador2  << endl;
            cout << endl ;
            Mano(ronda, puntajeTotalJug1, puntajeTotalJug2, jugador1, jugador2, resultadosJug1, resultadosJug2); //

            ronda++;

            system("pause");


        }

        if(puntajeTotalJug1>puntajeRecord){     // estadisticas
                puntajeRecord=puntajeTotalJug1;
                jugadorRecord=jugador1;
            }
             if(puntajeTotalJug2>puntajeRecord){
                puntajeRecord=puntajeTotalJug2;
                jugadorRecord=jugador2;
            }


        MostrarResultadoFinal(ronda, puntajeTotalJug1, puntajeTotalJug2, jugador1, jugador2, resultadosJug1, resultadosJug2);
        cout << endl << endl << endl;
    }



int SeleccionarOpcion(){
    int opcion;
    cout << endl << "ingrese opción: ";
    cin >> opcion;
    return opcion;
}


  void Mano(int ronda,int &puntajeTotalJug1, int &puntajeTotalJug2, string jugador1, string jugador2, int resultadosJug1[3], int resultadosJug2[3]){
     int vecManoJugador1[5]={};   // se guardan las cartas de  jugador 1
     int vecManoJugador2[5]={};  // se guardan las cartas de  jugador 2
    string valor;  // variable que guardará el valor de la carta (Q, J, K, etc,)
    string figura;  // variable que guardara la figura de la carta (corazones, picas, etc)
    int vecMazo[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; //vector del mazo
    int codigo, puntajeJugador1=0, puntajeJugador2=0;
    int i;
    string embaucadora;
    int puntajeNaipe;


    mezclar(vecMazo); //mezcla el mazo {4,5,1,9,15,20,6,9,12,2...

    embaucadora=CartaEmbaucadora();   //CORAZON         // saca la carta embaucadora

    cout << "+----------------------------------+" << endl;
    cout << "|"<< setw(2) << left << setw(35) << right <<"|" << endl;
    cout << "|"<< setw(2) << left <<  "\t"   << setw(11) << left << jugador1   <<" (" <<  setw(3) << right << puntajeTotalJug1 << ")" << setw(10) << right <<"|"  << endl;
    cout << "|"<< setw(2) << left << setw(35) << right <<"|" << endl;

       for(i=0;i<5;i++){    // reparte 5 cartas a cada jugador
            vecManoJugador1[i]=vecMazo[i];
            codigo = vecManoJugador1[i];  // guarda el valor del indice del la mano
            Naipes(codigo, valor, figura);  // transforma el valor en una carta
            puntajeJugador1+=CalcularPuntaje(valor, figura, embaucadora);  // calcula el puntaje
            puntajeNaipe=MostrarPuntajeNaipe(valor, figura);  // calcula el puntaje

            cout << setw(5) << left<< "|" << left << setw(3) << valor << " de " << left <<setw(8) <<  figura  << " ("<<  setw(2) << right << puntajeNaipe << ")" << setw(11) << right <<"|"   << endl;   //muestra la carta

            if(ronda==1){
            resultadosJug1[0]=puntajeJugador1;    // guarda  resultado de la ronda
         }
       }
    cout << "|"<< setw(2) << left << setw(35) << right <<"|" << endl;
    cout << "+----------------------------------+" << endl;
    cout << "|"<< setw(2) << left << setw(35) << right <<"|" << endl;
    cout << "|"<< setw(2) << left << "\t" << setw(11) << left  << jugador2 << " (" <<  setw(3) << right <<  puntajeTotalJug2 << ")" << setw(10) << right <<"|"  << endl;     // jugador 2
    cout << "|"<< setw(2) << left << setw(35) << right <<"|" << endl;
       for(i=5;i<10;i++){
          vecManoJugador2[i-5]=vecMazo[i];
            codigo = vecManoJugador2[i-5];
            Naipes(codigo, valor, figura);
            puntajeJugador2+=CalcularPuntaje(valor, figura, embaucadora);
            puntajeNaipe=MostrarPuntajeNaipe(valor, figura);

            cout << setw(5) << left<< "|" <<  left << setw(3) << valor << " de " << left << setw(8) << figura << " ("<<  setw(2) << right << puntajeNaipe << ")" << setw(11) << right <<"|"   << endl;

                if(ronda==1){
                    resultadosJug2[0]=puntajeJugador2;
                }
       }

       cout << "|"<< setw(2) << left << setw(35) << right <<"|" << endl;
    cout << "+----------------------------------+" << endl;

    cout << endl << "La carta embaucadora es: " << embaucadora << endl << endl;

        if(ronda==2){                         // solo  en la segunda ronda
            if(CambiarCartaEmbaucadora(jugador1, puntajeTotalJug1)){       // pregunta al jugador 1 si cambia la embaucadora
                embaucadora=CartaEmbaucadora();                           // por el Verdadero saca una nueva carta embaucadora
                puntajeTotalJug1-=20;                                      // resta 20 puntos
                cout << endl << "La carta embaucadora ahora es: " << embaucadora << endl << endl;  // muestra carta embaucadora
                RecalcularPuntos(vecManoJugador1, vecManoJugador2, valor, figura, embaucadora, puntajeJugador1,puntajeJugador2); // recalcula los puntos

            }else if(CambiarCartaEmbaucadora(jugador2, puntajeTotalJug2)){     // por el falso pregunta al jugador 2
                embaucadora=CartaEmbaucadora();                                // idem jugador 1
                puntajeTotalJug2-=20;
                cout << endl << "La carta embaucadora ahora es: " << embaucadora << endl << endl;
                RecalcularPuntos(vecManoJugador1, vecManoJugador2,valor, figura, embaucadora, puntajeJugador1,puntajeJugador2);
            }

            resultadosJug1[1]=puntajeJugador1;   // guarda los resultados de las rondas
            resultadosJug2[1]=puntajeJugador2;

        }

         if(ronda==3){                    // idem ronda 2
              if(CambiarCartaEmbaucadora(jugador2, puntajeTotalJug2)){
                embaucadora=CartaEmbaucadora();
                puntajeTotalJug2-=20;
                cout << endl << "La carta embaucadora ahora es: " << embaucadora << endl;
                RecalcularPuntos(vecManoJugador1, vecManoJugador2,valor, figura, embaucadora, puntajeJugador1,puntajeJugador2);


            }else if(CambiarCartaEmbaucadora(jugador1, puntajeTotalJug1))
            {
                embaucadora=CartaEmbaucadora();
                puntajeTotalJug1-=20;
                cout << endl << "La carta embaucadora ahora es: " << embaucadora << endl;
                RecalcularPuntos(vecManoJugador1, vecManoJugador2,valor, figura, embaucadora, puntajeJugador1,puntajeJugador2);


            }

             resultadosJug1[2]=puntajeJugador1;     // guarda los resultados de las rondas
             resultadosJug2[2]=puntajeJugador2;
        }
        cout << endl;
        MostrarPuntajeRonda(jugador1, puntajeJugador1, vecManoJugador1, embaucadora);
        cout << endl;
        MostrarPuntajeRonda(jugador2, puntajeJugador2, vecManoJugador2, embaucadora);

       // cout << endl <<  "Puntaje " << jugador1 << ": "<< puntajeJugador1 << endl;  //  muestra el puntaje
       // cout << endl <<  "Puntaje " << jugador2 << ": "<< puntajeJugador2 << endl;
        cout << endl << endl;

        puntajeTotalJug1+=puntajeJugador1;     // acumula los puntajes
        puntajeTotalJug2+=puntajeJugador2;



  }


  void mezclar(int vecMazo[20]){
     int aux, i, indiceRandom;

        for( i = 0; i < 20; i++){
        indiceRandom=rand()% 20;
        aux=vecMazo[i];
        vecMazo[i]=vecMazo[indiceRandom];
        vecMazo[indiceRandom]=aux;

        }
  }




 void Naipes(int codigo, string &valor, string &figura)
 {
    if(codigo<6){
        figura="Pica";
    }else if(codigo<11){
        figura="Corazon";
        codigo-=5;
    }else if(codigo<16){
         figura="Trebol";
         codigo-=10;
    }else{
        figura="Diamante";
        codigo-=15;
    }
    switch(codigo){
    case 1:
        valor="10";
        break;
    case 2:
        valor="J";
        break;
    case 3:
        valor="Q";
        break;
    case 4:
        valor="K";
        break;
    case 5:
        valor="A";
        break;
    default:
        break;
    }
 }

 string CartaEmbaucadora(){

    int indiceEmbaucadora;
    string embaucadora;

    indiceEmbaucadora= rand()%4;

    switch(indiceEmbaucadora){
    case 0:
        embaucadora="Corazon";
        break;
        case 1:
        embaucadora="Pica";
        break;
        case 2:
        embaucadora="Diamante";
        break;
        case 3:
        embaucadora="Trebol";
        break;
        default:
            break;
    }
    return embaucadora;

 }



 bool CambiarCartaEmbaucadora(string &jugador, int puntaje){
    string cambio = "";
    bool cambiaCarta = false;

    if(puntaje>=20){

        while ( cambio != "s" && cambio != "S" && cambio != "n" && cambio != "N") {
            cout << jugador << " ¿Desea cambiar la carta embaucadora a cambio de 20 puntos? S/N" << endl;
            cin >> cambio;
            if(cambio =="S"||cambio =="s"){
                cambiaCarta = true;
                break;
            } else if (cambio== "n"|| cambio == "N") {
                cambiaCarta = false;
                break;
            }
            borrarUltimasLineas(2);
        }

    } else{
         cout << endl << jugador << " No tiene permitido cambiar la carta Embaucadora por falta de puntos" << endl << endl;
        return false;
    }

    return cambiaCarta;
}

void borrarUltimasLineas(int cantidadDeLineas) {
    // Mover el cursor hacia arriba `num_lines` líneas
    cout << "\033[" << cantidadDeLineas << "A";
    // Borrar las líneas desde la posición actual del cursor hacia abajo
    cout << "\033[0J";
}




int CalcularPuntaje(string valor, string figura, string embaucadora){
    int puntajeJugador=0;
    const int PUNTOS_10=10;  //puntajes
    const int PUNTOS_J=11;
    const int PUNTOS_Q=12;
    const int PUNTOS_K=15;
    const int PUNTOS_A=20;

    if(valor=="10" && figura!=embaucadora){           // calcula el puntaje
            puntajeJugador+=PUNTOS_10;
         }  else if(valor=="J"&& figura!=embaucadora){
            puntajeJugador+=PUNTOS_J;
         } else if(valor=="Q"&& figura!=embaucadora){
            puntajeJugador+=PUNTOS_Q;
         }else if(valor=="K"&& figura!=embaucadora){
            puntajeJugador+=PUNTOS_K;
         }else if(valor=="A"&& figura!=embaucadora){
            puntajeJugador+=PUNTOS_A;
         }

        return puntajeJugador;
}

void RecalcularPuntos(int vecManoJugador1[5], int vecManoJugador2[5],string valor, string figura, string embaucadora, int &puntajeJugador1, int &puntajeJugador2){
  int codigo;

  puntajeJugador1 =0;
  puntajeJugador2 = 0;

  for (int i = 0; i < 5; i++){
    codigo = vecManoJugador1[i];
    Naipes(codigo, valor, figura);
    puntajeJugador1 += CalcularPuntaje(valor, figura, embaucadora);
  }
  for (int i = 0; i < 5; i++){
    codigo = vecManoJugador2[i];
    Naipes(codigo, valor, figura);
    puntajeJugador2 += CalcularPuntaje(valor, figura, embaucadora);
  }

}



int MostrarPuntajeNaipe(string valor, string figura){
    int puntajeJugador=0;
    const int PUNTOS_10=10;  //puntajes
    const int PUNTOS_J=11;
    const int PUNTOS_Q=12;
    const int PUNTOS_K=15;
    const int PUNTOS_A=20;

    if(valor=="10" ){           // calcula el puntaje
            puntajeJugador+=PUNTOS_10;
         }  else if(valor=="J"){
            puntajeJugador+=PUNTOS_J;
         } else if(valor=="Q"){
            puntajeJugador+=PUNTOS_Q;
         }else if(valor=="K"){
            puntajeJugador+=PUNTOS_K;
         }else if(valor=="A"){
            puntajeJugador+=PUNTOS_A;
         }

        return puntajeJugador;
}
