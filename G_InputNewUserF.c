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


void clearScreen(void);
void InputNewUser(void);
void InputNewUserData(char *fullCardNumber, users *data);
void readDateAndTime(char *readDate, char *readTime);
void getCardNumber(char *fullCardNumber, bool fakeScan);
void getFullNameAndAdress(char *firstName, char *lastName, char *adress);
void inputNewUserBar(void);

/* =================================================================================================================================================
   =========================  ENTER NEW USER IN FILE "KEYS:TXT"  ===================================================================================
   =================================================================================================================================================
   */

/* -------------------------------------------------------------------------------------------------------------------------------------------------
   -------------------------  CHECK IF CARD NUMBER IS ALLREADY ASSIGNED TO KEYS.TXT FILE  ----------------------------------------------------------
   -------------------------------------------------------------------------------------------------------------------------------------------------
   */

void InputNewUser(void)
{
    bool fakeScan = false;
    char fullCardNumber[17], readDate[11], readTime[9], firstName[25], lastName[25], adress[50];

    readDateAndTime(readDate, readTime);
    clearScreen();
    getCardNumber(fullCardNumber, fakeScan);

    bool isCardExist = false;
    char buffer[250];
    FILE *file1 = fopen("Keys.dat", "r");
    if(file1 == NULL)
    {
        printf("\n\tAn Error Has Occured While Opening \"Keys.txt\" For Read");
        fclose(file1);
    }
    else
    {
        char *token;
        while(fgets(buffer, 250, file1))
        {
            token = strtok(buffer, ",");
            token = strtok(NULL, ",");
            token = strtok(NULL, ",");
            if(!strcmp(fullCardNumber, token))
                isCardExist = true;
        }
    }
    fclose(file1);

/*  -------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------  IF CARD NUMBER IS NOT ALLREADY ASSIGNED TO KEYS.TXT FILE APPEND IT ---------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------
    */    

    if(!isCardExist)
    {   
        getFullNameAndAdress(firstName, lastName, adress);
        FILE *f1 = fopen("Keys.dat", "a");
        if(f1 == NULL)
        {
            printf("\n\tAn Error Has Occured While Opening \"Keys.txt\"For Append");
            fclose(f1);
        }
        else
        {
            fprintf(f1, readDate);
            fprintf(f1, ",");
            fprintf(f1, readTime);
            fprintf(f1, ",");
            fprintf(f1, fullCardNumber);
            fprintf(f1, ",");
            fprintf(f1, "YES");
            fprintf(f1, ",");
            fprintf(f1, firstName);
            fprintf(f1, " ");
            fprintf(f1, lastName);
            fprintf(f1, ",");
            fprintf(f1, adress);
            fprintf(f1, "\n");
        }   
        fclose(f1);   
    }

/*  -------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------  IF CARD ALLREADY REGITRED WARNIG  ------------------------------------------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------
    */

    else
    {
        clearScreen();
        inputNewUserBar();
        Sleep(800);
        clearScreen();
        Sleep(200);
        inputNewUserBar();
        Sleep(800);
        clearScreen();
        Sleep(200);
        inputNewUserBar();
        Sleep(800);      
    }
    return;
}

void inputNewUserBar(void)
{
    printf("\n\tCard Number Is Allready Assigned To Database ");
    printf("\n\t==========================================================================================================================================================================\n");
    return;
}