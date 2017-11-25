#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Defines

#define RACINNE
#define SMIN 11
#define SMAX 42
#define TEMPSSIMULE 960
#define CAPACITE_FILE_EXPRESS 8
#define NBSTATION_EXPRESS 2
#define NBCLIENTSNORMALE 1000
#define LAMBDA 2.2
#define COUT_CLIENT_EXPRESS 37.5
#define COUT_CLIENT_NORMALE 25.5
#define COUT_CLIENT_PRIORITAIRE	42.5
#define COUT_1HEURE_EXPRESS 30
#define COUT_1HEURE_NORMALE 35
#define COUT_INOCCUPATION 18
#define EXPRESS_VERS_NORMALE 5

//Structures

typedef struct clientNormale ClientNormale;
struct clientNormale
{
	int DS;
	bool estPrioritaire;
};

//Prototypes de fonctions

int GénérerNbArriv(void);
int rand_a_b(int a, int b);
int GénérerDS(void);
void initTableaux(int *tabNormale, int *tabExpress, ClientNormale *tabFileNormale, int *tabFileExpress);
void placerClientFile(int nbArrivé, int *fileExpress, int *fileNormale, int *DS, int *tabNormale, ClientNormale *tabFileNormale, int *tabExpress, int *tabFileExpress, int nbPrioritairesAbsolu, int *expressNormaleTot);
void trtStationExpress(int iStation, int *tabStation, int *fileExpress, int *tabFileExpress, int *nbMinInoccupation, int *minExpress);
void trtStationNormale(int iStation, int *tabStation, int *fileNormale, ClientNormale *tabFileNormale, int *nbPrioritairesAbsolu, int *minNormale, int *s);
void trtPrioritaire(int iStation, int *tabStation, ClientNormale *tabFileNormale, int *nbPrioritairesAbsolu);
void calcul(int nbPersCumNormale, int nbPersCumExpress, int nbPriorCumAbsolu, int minExpress, int minNormale, int minInoccupation, int expressNormaleTot, int *tabCout);
int rechercheMin(int *tabCout);
void reculerFileNormale(ClientNormale *tabFile, int file, int i_File);
void reculerFileExpress(int *tabFile, int file, int i_File);
void avancerFile(int *tabFile, int file, int i_File);
