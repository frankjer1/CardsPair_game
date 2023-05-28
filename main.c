#include <stdio.h>
#include <stdlib.h>
#include "Libreria_progetto_carte.h"
#include "time.h"


int main()
{
    Carta_napoletana mazzo[40], giocatore_1[2], giocatore_2[2];
    int punteggio_gioc_1 = 0, punteggio_gioc_2 = 0, n_carte_scoperte = 0, gioc_1 = 0, gioc_2 = 1, primo, controllo = 1;

    printf("\n BENVENUTI NEL GIOCO DELLE DUE CARTE: \n");
    /* Il gioco è per due giocatori. Il giocatore che inizia pesca due carte, e se queste sono uguali il suo punteggio aumenta di uno.
    Il giocatore continua a pescare finchè il valore delle carte pescate è diverso, e a quel punto il turno passa al secondo giocatore.
    Ad ogni turno ogni giocatore ha a disposizione la lista di carte coperte e scoperte.
    La partita finisce quando le carte vengono esaurite, e a quel punto si confronta il punteggio.
    Il giocatore con il punteggio più alto vince. */

    crea_mazzo(mazzo);                              // Crea il mazzo, lo mischia e sceglie casualmente il giocatore che inizia
    mischia_mazzo_napoletano(mazzo);
    giocatore_che_inizia(&gioc_1,&gioc_2, &primo);



    while(n_carte_scoperte < 40) // La partita continua finchè tutte le carte non sono scoperte
    {
        if(primo == gioc_1) // Se inizia il giocatore 1
        {
            printf("\n Turno giocatore 1: \n");
            turno_giocatore(mazzo, giocatore_1, &punteggio_gioc_1, &controllo, &n_carte_scoperte);
            printf("\n Turno giocatore 2: \n");
            turno_giocatore(mazzo, giocatore_2, &punteggio_gioc_2, &controllo, &n_carte_scoperte);
        }
        else // Se inizia il giocatore 2
        {
            printf("\n Turno giocatore 2: \n");
            turno_giocatore(mazzo, giocatore_2, &punteggio_gioc_2, &controllo, &n_carte_scoperte);
            printf("\n Turno giocatore 1: \n");
            turno_giocatore(mazzo, giocatore_1, &punteggio_gioc_1, &controllo, &n_carte_scoperte);
        }

    }

    printf("Carte terminate! Partita finita. Rullo di tamburi........."); // Confronto punteggio e scelta vincitore.

    if(punteggio_gioc_1 > punteggio_gioc_2)
    {
        printf("\n Il giocatore 1 vince con %d punti contro i %d punti del giocatore 2 \n", punteggio_gioc_1, punteggio_gioc_2);
    }
    else if(punteggio_gioc_2 > punteggio_gioc_1)
    {
        printf("\n Il giocatore 2 vince con %d punti contro i %d punti del giocatore 1 \n", punteggio_gioc_2, punteggio_gioc_1);
    }
    else
    {
        printf("\n Pareggio! entrambi i giocatori hanno totalizzato %d punti \n", punteggio_gioc_1);
    }



   return 0;

}
