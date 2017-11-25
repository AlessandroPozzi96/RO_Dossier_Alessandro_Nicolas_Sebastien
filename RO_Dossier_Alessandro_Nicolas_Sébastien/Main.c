#include "Header.h"

void main(void)
{
	//Déclarations de variables
	int fileNormal, fileExpress, nbMinInoccupation, expressNormaleTot, nbPrioritairesAbsolu, minExpress, minNormal, t, nbPersCumExpress, nbPersCumNormale, nbPriorCumAbsolu, DS, nbArriv, iStation1, iStation2, sOptimal;
	int tabExpress[NBSTATION_EXPRESS];
	int tabFileExpress[CAPACITE_FILE_EXPRESS];
	int tabNormale[SMAX];
	ClientNormale tabFileNormale[NBCLIENTSNORMALE]; //File en théorie illimitée...
	int tabCout[SMAX];
	int s = 3;
	s = SMIN;

	while (s <= SMAX)
	{
		//Initialisations
		fileNormal = fileExpress = nbMinInoccupation = expressNormaleTot = nbPrioritairesAbsolu = minExpress = minNormal = nbPersCumExpress = nbPersCumNormale = nbPriorCumAbsolu;
		t = 1;
		initTableaux(tabNormale, tabExpress, tabFileNormale, tabFileExpress);

		while (t <= SMAX)
		{
			nbArriv = GénérerNbArriv();
			placerClientFile(nbArriv, fileExpress, fileNormal, &DS, tabNormale, tabFileNormale, tabExpress, tabFileExpress);
			iStation1 = 0;
			trtStationExpress(iStation1, tabExpress, &fileExpress, tabFileExpress, &nbMinInoccupation, &minExpress);
			iStation2 = 0;
			trtStationNormale(iStation2, tabNormale, &fileNormal, tabFileNormale, &nbPrioritairesAbsolu, &minNormal);
			trtPrioritaire(iStation2, tabNormale, tabFileNormale, &nbPrioritairesAbsolu);

			nbPersCumExpress += fileExpress;
			nbPersCumNormale += fileNormal;
			nbPriorCumAbsolu += nbPrioritairesAbsolu;
			t++;
		}
		calcul(nbPersCumNormale, nbPersCumExpress, nbPriorCumAbsolu, minExpress, minNormal, nbMinInoccupation, expressNormaleTot, tabCout);
		s++;
	}
	sOptimal = rechercheMin(tabCout);

	system("pause");
}

void initTableaux(int *tabNormale, int *tabExpress, ClientNormale *tabFileNormale, int *tabFileExpress)
{
	for (int iNorm = 0; iNorm < SMAX; iNorm++)
	{
		tabNormale[iNorm] = 0;
	}

	for (int iFiN = 0; iFiN < NBCLIENTSNORMALE; iFiN++)
	{
		tabFileNormale[iFiN].DS = 0;
		tabFileNormale[iFiN].estPrioritaire = false;
	}

	for (int iExpr = 0; iExpr < NBSTATION_EXPRESS; iExpr++)
	{
		tabExpress[iExpr] = 0;
	}

	for (int iFiE = 0; iFiE < CAPACITE_FILE_EXPRESS; iFiE++)
	{
		tabFileExpress[iFiE] = 0;
	}
}

void placerClientFile(int nbArrivé, int *fileExpress, int *fileNormale, int *DS, int *tabNormale, ClientNormale *tabFileNormale, int *tabExpress, int *tabFileExpress)
{
	int i = 0;

}

int rand_a_b(int a, int b) 
{
	return rand() % (b - a) + a;
}

int GénérerNbArriv(void)
{
	double l, p, u;
	l = exp(LAMBDA);
	int k = 0;
	p = 1;

	do
	{
		k++;
		u = rand_a_b(0, 1);
		p *= u;
	} while (p > l);

	return k - 1;
}
