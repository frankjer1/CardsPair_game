#include <stdio.h>
#include <stdlib.h>
#include "time.h"



typedef enum {bastoni, denari, coppe, spade} Seme;  /* Creo il tipo di dato "seme" */

struct carta_napoletana{                     /* Creo la Carta e ne faccio un tipo di dato */
    int valore;
    Seme seme;
    int estratta; // segnala se la carta è stata scoperta o no
};

typedef struct carta_napoletana Carta_napoletana; // definisco il tipo di dato Carta_napoletana

void crea_mazzo(Carta_napoletana *);
void mostra_mazzo_coperto(Carta_napoletana *);
void confronto_carte(Carta_napoletana [], int *, int *);
void scambia_carta(Carta_napoletana *, Carta_napoletana *);
void mischia_mazzo_napoletano(Carta_napoletana *);
void giocatore_che_inizia(int *, int *, int *);
void pesca_carte(Carta_napoletana *, Carta_napoletana *, int *);
void turno_giocatore(Carta_napoletana *, Carta_napoletana *, int *, int *, int *);
void mostra_mazzo_scoperto(Carta_napoletana *);
