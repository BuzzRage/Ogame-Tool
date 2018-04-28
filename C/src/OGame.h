#include <math.h>

#define PREZ system("cls");\
             printf("OGame Stats\n");
#define CONV PREZ\
             printf("Conversion\n\n");
#define ATT  PREZ\
             printf("Calcul du temps avant construction\n\n");
#define input getchar();

#define HEURE 1
#define MINUTE 60
#define SECONDE 3600
#define vit_uni 2

typedef struct carac carac;
struct carac
{
    int mine;
    int stock;
    int cache;
};

typedef struct ressource ressource;
struct ressource
{
    float prod;
    float dispo;
    float cache;
    float stockmax;
    float conso;
    carac niveau;
};

typedef struct planeteINFO planeteINFO;
struct planeteINFO
{
    ressource Metal;
    ressource Cristal;
    ressource Deuterium;
    ressource Energie;
    int Tmini;
    int Tmaxi;
};



int presentation();
void conv();
void attente(int mode);
void attentemultiple(int mode);
planeteINFO initialiserCONFIG(int mode,planeteINFO Troglodyte);
planeteINFO lectureFichier(int mode,planeteINFO planete); // 0 LIRE   1 ECRIRE
