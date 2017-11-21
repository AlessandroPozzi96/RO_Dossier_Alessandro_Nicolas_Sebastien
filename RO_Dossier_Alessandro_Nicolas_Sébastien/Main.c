#include "Header.h"

void main(void)
{
	//Déclarations de variables
	int fileNormal, fileExpress, nbMinInoccupation, expressNormaleTot, nbPrioritairesAbsolu, minExpress, minNormal, t, nbPersCumExpress, nbPersCumNormale, nbPriorCumAbsolu, DS, nbArriv, iStation1, iStation2, sOptimal;
	int tabExpress[NBSTATION_EXPRESS];
	int tabFileExpress[CAPACITE_FILE_EXPRESS];
	int tabNormale[SMAX];
	int tabFileNormale[1000];
	int tabCout[SMAX];
	int s = 3;
	s = SMIN;

	while (s <= SMAX)
	{
		//Initialisations
		fileNormal = fileExpress = nbMinInoccupation = expressNormaleTot = nbPrioritairesAbsolu = minExpress = minNormal = nbPersCumExpress = nbPersCumNormale = nbPriorCumAbsolu;
		t = 1;
		initTabStation(tabNormale, tabExpress, tabFileNormale, tabFileExpress);

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
