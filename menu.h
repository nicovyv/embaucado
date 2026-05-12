#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

using namespace std;


   void Menu();
   void Nombres(string &jugador1, string &jugador2);
   int SeleccionarOpcion();
   void Ronda(string &jugador1, string &jugador2, int &puntajeRecord, string &jugadorRecord);
   void Mano(int ronda, int &puntajeTotalJug1, int &puntajeTotalJug2, string jugador1, string jugador2, int resultadosJug1[3], int resultadosJug2[3]);
   void Naipes(int codigo, string &valor, string &figura);
   void mezclar(int vecMazo[20]);
   string CartaEmbaucadora();
   bool CambiarCartaEmbaucadora(string &jugador, int puntaje);
   int CalcularPuntaje(string valor, string figura, string embaucadora);
   void RecalcularPuntos(int vecManoJugador1[5], int vecManoJugador2[5],string valor, string figura, string embaucadora, int &puntajeJugador1, int &puntajeJugador2);
   void MostrarResultadoFinal(int ronda, int puntajeTotalJugador1, int puntajeTotalJugador2, string &jugador1, string &jugador2, int resultadosJug1[3], int resultadosJug2[3]);
   void Desempatar(string &jugador1, string &jugador2, int resultadosJug1[3], int resultadosJug2[3]);
   void Estadisticas(int &puntajeRecord, string &jugadorRecord);
   int MostrarPuntajeNaipe(string valor, string figura);
   void Creditos();
   void MostrarPuntajeRonda(string &jugador, int &puntajeJugador, int vecManoJugador[5], string embaucadora);
   void MenuPrincipal(int puntajeRecord, string jugadorRecord);
   void borrarUltimasLineas(int cantidadDeLineas);
#endif // MENU_H_INCLUDED
