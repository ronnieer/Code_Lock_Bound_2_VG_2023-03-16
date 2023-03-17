#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include "I_user.h"
#include "H_SafeInput.h"
#include "C_enterCardDataF.h"
#include "F_enterDateAndTimeF.h"
#include "G_InputNewUserF.h"
#include "A_mainMenuF.h"
#include "E_listCardDataF.h"
#include "D_setAccessF.h"
#include "J_fakeTestScan.h"

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33


void ClearScreen(void);
void setAccessBar1(void);
void getCardNumber(char *fullCardNumber, bool fakeScan);
void fakeTestScanCard(void);
void blackControllMainMenu(void);
void greenControllMainMenu(void);
void redControllMainMenu(void);
void fakeScanBar(char *cardNumber, char *firstName, char *lastName, char *adress, int fakeScanColor);


/*  =================================================================================================================================================
    =========================  USERS CARD FAKE SCAN  ================================================================================================
    =================================================================================================================================================
    */

void fakeTestScanCard(void)
{
    char  fullCardNumber[17];
    bool fakeScan = true;
    char *tokenCardNo;
    char *tokenAccess;
    char *tokenFirstName;
    char *tokenLastName;
    char *tokenAdress;

    bool isCardRegitred = false;
    clearScreen();
    //setAccessBar1();
    //listUsers();
    getCardNumber(fullCardNumber, fakeScan);

    char buffer[250];
    FILE *file1 = fopen("Keys.dat", "r");
    if(file1 == NULL)
    {
        printf("\n\tAn Error Has Occured While Opening \"Keys.dat\" And/ Or \"KeysShadow.dat\" Files");
        fclose(file1);
    }
    else
    {   
        while(fgets(buffer, 250, file1))
        {
            tokenCardNo = strtok(buffer, ",");
            tokenCardNo = strtok(NULL, ",");
            tokenCardNo = strtok(NULL, ",");
            tokenAccess = strtok(NULL, ",");
            tokenFirstName = strtok(NULL, " ");
            tokenLastName = strtok(NULL, ",");
            tokenAdress = strtok(NULL, ",");

            if((!strcmp(fullCardNumber, tokenCardNo)) && (!strcmp(tokenAccess, "YES")))
            {
                fakeScanBar(tokenCardNo, tokenFirstName, tokenLastName, tokenAdress, GREEN);
                Sleep(3000);
                isCardRegitred = true;
            }
            else if((!strcmp(fullCardNumber, tokenCardNo)) && (!strcmp(tokenAccess, "NO")))
            {
                fakeScanBar(tokenCardNo, tokenFirstName, tokenLastName, tokenAdress, RED);
                Sleep(3000);
                isCardRegitred = true;     
            }
        }
        if(!isCardRegitred)
        {
            fakeScanBar("", "", "", "", YELLOW);
            Sleep(3000);
        }
    }
    fclose(file1);
    return;
}


void fakeScanBar(char *cardNumber, char *firstName, char *lastName, char *adress, int fakeScanColor)
{
    char cardG1[10] = "";
    char cardG2[10] = "";
    char cardG3[10] = "";
    char cardG4[10] = "";
    char cardTot[20] = "";
    char adressTot[60] = "";
    strcpy(cardTot, cardNumber);
    strcpy(adressTot, adress);

    clearScreen();
    printf("\033[0;37m");
    printf("\n\tFake Scan                                                                                                                                           Control Lamp:   \033[0;%dm[####]\033[0;37m", fakeScanColor);
    printf("\n\t==========================================================================================================================================================================");
    for(int indexCardNo = 0; indexCardNo < 16; indexCardNo++)
    {
        if(indexCardNo < 4)
        {
            cardG1[indexCardNo] = cardTot[indexCardNo];    
        }
        else if(indexCardNo < 8)
        {
            cardG2[indexCardNo - 4] = cardTot[indexCardNo];  
        }
        else if(indexCardNo < 12)
        {
            cardG3[indexCardNo - 8] = cardTot[indexCardNo];  
        }
        else if(indexCardNo < 16)
        {
            cardG4[indexCardNo - 12] = cardTot[indexCardNo];   
        }
    }   

    cardG1[4] ='\0';
    cardG2[4] ='\0';
    cardG3[4] ='\0';
    cardG4[4] ='\0';

    adressTot[strcspn(adress, "\n")] = '\0';

    printf("\n\tUser: %s-%s-%s-%s %s %s %s Has Tried To Access The Door ", cardG1, cardG2, cardG3, cardG4, firstName, lastName, adressTot);
    if(fakeScanColor == BLACK)
        printf("\n\n\tCard Is Not Regiterd\n\t");
    else if(fakeScanColor == YELLOW)
        printf("\n\n\tCard Is Not Regiterd\n\t");        
    else if(fakeScanColor == RED)
        printf("\n\n\tAccess Denied\n\t");
    else if(fakeScanColor == GREEN)
    printf("\n\n\tAcces Granted\n\t");
    return;  
}