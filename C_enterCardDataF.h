#ifndef C_enterCardDataF_h
#define C_enterCardDataF_h

void getCardNumber(char *fullCardNumber, bool fakeScan);
void enterFourDigitGroup(char *strMyFourDigitString, int fourDigitEntryNumber);
void getFullNameAndAdress(char *firstName, char *lastName, char *adress);
void setParenteses(int totalNameLength);
void enterCardDataUCN(char *cardFieldOne, char *cardFieldTwo, char *cardFieldThree, char *cardFieldFour, bool fakeScan);
void enterCardDataUCN2(bool fakeScan);
void nameAndAdressBar(void);
void nameAndAdressBar2(char *firstName, char *lastName, char *adress);

#endif