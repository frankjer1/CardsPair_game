#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "Libreria_progetto_carte.h"




void crea_mazzo(Carta_napoletana *mazzo)      // Crea il mazzo di carte mapoletane
{
    int i, j, n = 0, numero_carte = 40;

    for(i=1; i < (numero_carte/4) +1; i++)
    {
        for(j=0; j < 4; j++)
        {
            (mazzo + n) -> valore = i;
            (mazzo + n) -> seme = j;
            (mazzo + n) -> estratta = 0;
            n++;

        }
    }
}


void mostra_mazzo_coperto(Carta_napoletana *mazzo)   // Mostra le carte coperte
{
    int i;
    int numero_carte = 40;

    for(i=0; i < numero_carte ; i++)
    {
        if((mazzo+i)->estratta == 0)
        {
            printf(" \n Valore: %d ; Seme: %d \n\n", (mazzo + i) -> valore, (mazzo + i) ->seme);
        }

    }
}

void mostra_mazzo_scoperto(Carta_napoletana *mazzo)   //  Mostra le carte scoperte
{
    int i;
    int numero_carte = 40;

    for(i=0; i < numero_carte ; i++)
    {
        if((mazzo+i)->estratta == 1)
        {
            printf(" \n Valore:  %d ; Seme: %d \n\n", (mazzo + i) -> valore, (mazzo + i) ->seme);
        }

    }
}

void confronto_carte(Carta_napoletana *giocatore, int *punteggio, int *controllo) // Confronta due carte: se hanno lo stesso
{                                                                                 // valore aggiunge un punto al punteggio giocatore

    if((giocatore -> valore) == ((giocatore + 1) -> valore))
        {
           (*punteggio)++;
        }
    else
        {
           *controllo = 0;      // serve a segnalare al di fuori della procedura che le carte non sono uguali
        }
}


void mischia_mazzo_napoletano(Carta_napoletana *mazzo) // Mischia il mazzo
{
    int i = 1, n, a, b;

    printf("Quante volte vuoi mischiare?   "); // L'utente inserisce il numero di scambi da effettuare
    scanf("\n %d \n", &n);

    srand(time(NULL));

    while(i <= n) // Garantisce che siano effettuati n scambi
    {
        a = rand()%40;
        b = rand()%40;
        scambia_carta((mazzo+a), (mazzo + b)); //scambia la posizione di due carte scelte in maniera casuale
        i++;
    }
}

void scambia_carta(Carta_napoletana *carta_1, Carta_napoletana *carta_2) // Scambia due carte
{
    Carta_napoletana temp;

    temp = *carta_1;
    *carta_1 = *carta_2;
    *carta_2 = temp;
}

void giocatore_che_inizia(int *gioc_1, int *gioc_2, int *primo) // Sceglie in maniera casuale il giocatore che inizia
{
    int moneta;

    srand(time(NULL));

    moneta = rand()%2;

    if(moneta == *gioc_1)
    {
        printf("\n Il giocatore 1 inizia \n");
        *primo = *gioc_1; // serve a segnalare il giocatore che inizia al di fuori della procedura
    }
    else
    {
        printf("\n Il giocatore 2 inizia \n");
        *primo = *gioc_2;  // serve a segnalare il giocatore che inizia al di fuori della procedura
    }
}

void pesca_carte(Carta_napoletana *mazzo, Carta_napoletana *giocatore, int *n_carte_scoperte) // Pesca due carte dal mazzo e le assegna al giocatore
{
    int i, n = 0;

    for(i=0;(n < 2); i++)
    {
        if((mazzo+i) -> estratta == 0) // Pesca le carte solo se sono coperte
        {
            (giocatore + n) -> valore = (mazzo + i) -> valore;
            (giocatore + n) -> seme = (mazzo + i) -> seme;
            ((mazzo+i) -> estratta) = 1; // Scopre le carte pescate
            n++;
            (*n_carte_scoperte)++; // segnala al di fuori della procedura il numero totale di carte scoperte
        }
    }



}


void turno_giocatore(Carta_napoletana *mazzo, Carta_napoletana *giocatore, int *punteggio, int *controllo, int *n_carte_scoperte) // turno giocatore
{
    *controllo = 1; // riporta il controllo a 1

    if((*n_carte_scoperte) == 40)
        {
            *controllo = 0; // Impedisce l'esecuzione del turno se le carte sono finite
        }


    while(*controllo)
    {
        printf("Ecco le carte scoperte: \n");               // Mostra il mazzo coperto e quello scoperto, pesca e confronta le carte
        mostra_mazzo_scoperto(mazzo);                       // e incrementa il punteggio e continua se le carte sono uguali.
        printf("Ecco le carte coperte: \n");                // Il ciclo continua finchè il giocatore non pesca due carte diverse;a quel punto il
        mostra_mazzo_coperto(mazzo);                        // turno finisce.
        pesca_carte(mazzo, giocatore, n_carte_scoperte);
        confronto_carte(giocatore, punteggio, controllo);
        if((*n_carte_scoperte) == 40) // Impedisce la riesecuzione del ciclo se le carte sono finite
        {
            *controllo = 0;
        }

    }
}













