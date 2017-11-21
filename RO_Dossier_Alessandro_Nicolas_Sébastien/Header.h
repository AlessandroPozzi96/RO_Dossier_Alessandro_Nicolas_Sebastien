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

//Prototypes de fonctions

int GénérerNbArriv(void);
int GénérerDS(void);
void initTabStation(int *tabNormale, int *tabExpress, int *tabFileNormale, int *tabFileExpress);
void placerClientFile(int nbArrivé, int *fileExpress, int *fileNormale, int *DS, int *tabNormale, int *tabFileNormale, int *tabExpress, int *tabFileExpress);
void trtStationExpress(int iStation, int *tabStation, int *fileExpress, int *tabFileExpress, int *nbMinInoccupation, int *minExpress);
void trtStationNormale(int iStation, int *tabStation, int *fileNormale, int tabFileNormale, int *nbPrioritairesAbsolu, int *minNormale);
void trtPrioritaire(int iStation, int *tabStation, int *tabFileNormale, int *nbPrioritairesAbsolu);
void calcul(int nbPersCumNormale, int nbPersCumExpress, int nbPriorCumAbsolu, int minExpress, int minNormale, int minInoccupation, int expressNormaleTot, int *tabCout);
int rechercheMin(int *tabCout);

