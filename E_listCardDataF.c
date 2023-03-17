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
void listCards(void);
void printUsers(void);
void setTabLen(int totalNameLength);
void listCardDataBar1(void);
void listCardDataBar2(char *menuChoise);
void listUsers(void);


/*  =================================================================================================================================================
    =========================  LIST CARDS IN DATABASE  ==============================================================================================
    =================================================================================================================================================
    */

void listCards(void)
{
    while(true)
    {
        char menuChoise[7];
        clearScreen();
        listCardDataBar1();
        listUsers();
        listCardDataBar2(menuChoise);
        if(!strcmp(menuChoise, "9"))
        {
            return;
        }
    }
}

void listUsers(void)
{
    char buffer[250] = "";
    FILE *file1 = fopen("Keys.dat", "r");
    if(file1 == NULL)
    {
        printf("\n\tFile \"Keys.dat\" Does Not Exist Or Is Opened In Another Application\n");
        fclose(file1);
    }
    else
    {
        char *tokenDate;
        char *tokenTime;
        char *tokenCardNo;
        char *tokenAccess;
        char *tokenFirstName;
        char *tokenLastName;
        char *tokenAdress;

        while(fgets(buffer, 250, file1))
        {
            printf("\t");
            tokenDate = strtok(buffer, ",");
            printf("%s\t", tokenDate);

            tokenTime = strtok(NULL, ",");
            printf("%s\t", tokenTime);
            
            tokenCardNo = strtok(NULL, ",");
            printf("%s\t", tokenCardNo);
            
            tokenAccess = strtok(NULL, ",");
            printf("%s\t\t", tokenAccess);
            
            tokenFirstName = strtok(NULL, " ");
            printf("%s ", tokenFirstName);
            
            tokenLastName = strtok(NULL, ",");
            printf("%s", tokenLastName);

            setTabLen(strlen(tokenFirstName) + strlen(tokenLastName));   
                
            tokenAdress = strtok(NULL, ",");
            printf("%s", tokenAdress);
        }
    }
    fclose(file1);
    return;
}

void listCardDataBar1(void)
{
    printf("\n\tDate\t\tTime\t\tCard Number\t\tAccess\t\tName\t\t\t\t\t\tAdress                      Control Lamp:   \033[0;30m[####]\033[0;37m\n");
    printf("\t==========================================================================================================================================================================\n");
    return;
}

void listCardDataBar2(char *menuChoise)
{
    printf("\t==========================================================================================================================================================================\n");
    GetInput("\tEnter 9.  To Exit \n\t", menuChoise, 5 * sizeof(char));
    return;
}