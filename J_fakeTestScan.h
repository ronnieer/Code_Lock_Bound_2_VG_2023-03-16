#ifndef J_fakeTestScan_h
#define J_fakeTestScan_h


void ClearScreen(void);
void setAccessBar1(void);
void getCardNumber(char *fullCardNumber, bool fakeScan);
void fakeTestScanCard(void);
void blackControllMainMenu(void);
void greenControllMainMenu(void);
void redControllMainMenu(void);
void fakeScanBar(char *cardNumber, char *firstName, char *lastName, char *adress, int fakeScanColor);


#endif