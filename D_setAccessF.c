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
void getCardNumber(char *fullCardNumber, bool fake);
void setTabLen(int totalNameLength);
void setAccessBar1(void);
void setAccessBar2(char *menuChoise);
void listUsers(void);

/*  =================================================================================================================================================
    =========================  SET ACCESS  ==========================================================================================================
    =================================================================================================================================================
    */

void setAccess(void)
{
    
    //void InputNewUser(void);
    //void InputNewUserData(char *fullCardNumber, users *data);
    //void readDateAndTime(char *readDate, char *readTime);
    //void getCardNumber(char *fullCardNumber, bool fakeScan);
    //void getFullNameAndAdress(char *firstName, char *lastName, char *adress);

/* =================================================================================================================================================
   =========================  SET ACCESS  ==========================================================================================================
   =================================================================================================================================================
   */

/* -------------------------------------------------------------------------------------------------------------------------------------------------
   -------------------------  CHECK IF CARD NUMBER IS ALLREADY ASSIGNED TO KEYS.TXT FILE  ----------------------------------------------------------
   -------------------------------------------------------------------------------------------------------------------------------------------------
   */

    bool fakeScan = false;
    char fullCardNumber[17];
    clearScreen();
    //setAccessBar1();
    //listUsers();
    getCardNumber(fullCardNumber, fakeScan);

    char *tokenDate;
    char *tokenTime;
    char *tokenCardNo;
    char *tokenAccess;
    char *tokenFirstName;
    char *tokenLastName;
    char *tokenAdress;

    int index = 0;

    char buffer[250];
    FILE *file1 = fopen("Keys.dat", "r");
    FILE *file2 = fopen("KeysShadow.dat", "w");
    if(file1 == NULL || file2 == NULL)
    {
        printf("\n\tAn Error Has Occured While Opening Keys Files");
        fclose(file1);
        fclose(file2);
    }
    else
    {   
        while(fgets(buffer, 250, file1))
        {
            tokenDate = strtok(buffer, ",");
            tokenTime = strtok(NULL, ",");
            tokenCardNo = strtok(NULL, ",");
            tokenAccess = strtok(NULL, ",");
            tokenFirstName = strtok(NULL, " ");
            tokenLastName = strtok(NULL, ",");
            tokenAdress = strtok(NULL, ",");
            
            if(!strcmp(fullCardNumber, tokenCardNo))
            {
                while(true)
                {
                    clearScreen();
                    setAccessBar1();
                    printf("\t%s\t", tokenDate);
                    printf("%s\t", tokenTime);
                    printf("%s\t", tokenCardNo);
                    printf("%s\t\t", tokenAccess);
                    printf("%s", tokenFirstName);
                    printf(" %s", tokenLastName);

                    setTabLen(strlen(tokenFirstName) + strlen(tokenLastName));    

                    printf("%s", tokenAdress);

                    char menuChoise[7];
                    setAccessBar2(menuChoise);
                    if(!strcmp(menuChoise, "1"))
                    {
                        strcpy(tokenAccess, "YES");
                    }
                    else if(!strcmp(menuChoise, "2"))
                    {
                        strcpy(tokenAccess, "NO");
                    }
                    if(!strcmp(menuChoise, "9"))
                    {
                        fprintf(file2, tokenDate);
                        fprintf(file2, ",");

                        fprintf(file2, tokenTime);
                        fprintf(file2, ",");

                        fprintf(file2, tokenCardNo);
                        fprintf(file2, ",");

                        fprintf(file2, tokenAccess);
                        fprintf(file2, ",");

                        fprintf(file2, tokenFirstName);
                        fprintf(file2, " ");

                        fprintf(file2, tokenLastName);
                        fprintf(file2, ",");

                        fprintf(file2, tokenAdress);

                        break;
                    }       
                }
            }
            else
            {
                fprintf(file2, tokenDate);
                fprintf(file2, ",");

                fprintf(file2, tokenTime);
                fprintf(file2, ",");

                fprintf(file2, tokenCardNo);
                fprintf(file2, ",");

                fprintf(file2, tokenAccess);
                fprintf(file2, ",");

                fprintf(file2, tokenFirstName);
                fprintf(file2, " ");

                fprintf(file2, tokenLastName);
                fprintf(file2, ",");

                fprintf(file2, tokenAdress);
            }
            index++;
        }
    }
    fclose(file1);
    fclose(file2);
    remove("Keys.dat");
    rename("KeysShadow.dat", "Keys.dat");
    return;
}

void setAccessBar1(void)
{
    printf("\n\tDate\t\tTime\t\tCard Number\t\tAccess\t\tName\t\t\t\t\t\tAdress                      Control Lamp:   \033[0;30m[####]\033[0;37m");
    printf("\n\t==========================================================================================================================================================================\n");   
    return;             
}

void setAccessBar2(char *menuChoise)
{
    printf("\n\n\tSet Access");
    printf("\n\t==========================================================================================================================================================================\n");
    GetInput("\tEnter 1.  To Provide Access\n\tEnter 2.  To Reject Access\n\tEnter 9.  To Exit \n\t", menuChoise, 5 * sizeof(char));
}