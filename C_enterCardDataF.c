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


void getCardNumber(char *fullCardNumber, bool fake);
void enterFourDigitGroup(char *strMyFourDigitString, int fourDigitEntryNumber);
void getFullNameAndAdress(char *firstName, char *lastName, char *adress);
void setTabLen(int totalNameLength);
void enterCardDataUCN(char *cardFieldOne, char *cardFieldTwo, char *cardFieldThree, char *cardFieldFour, bool fakeScan);
void enterCardDataUCN2(bool fakeScan);
void nameAndAdressBar(void);
void nameAndAdressBar2(char *firstName, char *lastName, char *adress);

void getCardNumber(char *fullCardNumber, bool fakeScan)
{

    char cardFieldOne[7], cardFieldTwo[7], cardFieldThree[7], cardFieldFour[7], strMyFourDigitString[7];//, arrFullCardNumber[17];

/*  =================================================================================================================================================
    =========================  ENTER SIXTEEN CARD NUMERS IN FOUR GROUPS OF FOUR  ====================================================================
    =================================================================================================================================================
    */
    while(true)
    {
        int fourDigitEntryNumber = 0;
        //clearScreen();
        enterCardDataUCN2(fakeScan);
        enterFourDigitGroup(strMyFourDigitString, fourDigitEntryNumber);
        strcpy(cardFieldOne, strMyFourDigitString);

        fourDigitEntryNumber++;
        enterFourDigitGroup(strMyFourDigitString, fourDigitEntryNumber);
        strcpy(cardFieldTwo, strMyFourDigitString);

        fourDigitEntryNumber++;
        enterFourDigitGroup(strMyFourDigitString, fourDigitEntryNumber);
        strcpy(cardFieldThree, strMyFourDigitString);

        fourDigitEntryNumber++;
        enterFourDigitGroup(strMyFourDigitString, fourDigitEntryNumber);
        strcpy(cardFieldFour, strMyFourDigitString);

        strcpy(fullCardNumber, "");
        strcat(fullCardNumber, cardFieldOne);
        strcat(fullCardNumber, cardFieldTwo);
        strcat(fullCardNumber, cardFieldThree);
        strcat(fullCardNumber, cardFieldFour);

        while(true)
        {
            clearScreen();
            enterCardDataUCN(cardFieldOne, cardFieldTwo, cardFieldThree, cardFieldFour, fakeScan);

            char prompt[100] = "\n\n\tConfirm Input Of Card Number [Y/ N] ";
            char menuChoise[7];
            GetInput(prompt, menuChoise, 5 * sizeof(char));

            if(!strcmp(menuChoise, "Y") || !strcmp(menuChoise, "y"))
            {
                return;
            }
            else if(!strcmp(menuChoise, "N") || !strcmp(menuChoise, "n"))
            {
                break;
            }
            else
            {
                printf("\n\tBad Choise From Card Number Routine");
                Sleep(2000);
            }          
        }
    }
    return;
}

/*  =================================================================================================================================================
    =========================  GET SIXTEEN CARD NUMERS IN FOUR GROUPS OF FOUR  ======================================================================
    =================================================================================================================================================
    */

void enterFourDigitGroup(char *strMyFourDigitString, int fourDigitEntryNumber)
{
    char strMyFourDigitEntryString[10];
    while(true)
    {
        if(fourDigitEntryNumber == 0)
            GetInput("\n\tEnter Card Number Group One: ", strMyFourDigitEntryString, 10 * sizeof(char));
        else if(fourDigitEntryNumber == 1)
            GetInput("\n\tEnter Card Number Group Two: ", strMyFourDigitEntryString, 10 * sizeof(char));
        else if(fourDigitEntryNumber == 2)
            GetInput("\n\tEnter Card Number Group Tree: ", strMyFourDigitEntryString, 10 * sizeof(char));
        else if(fourDigitEntryNumber == 3)
            GetInput("\n\tEnter Card Number Group Four: ", strMyFourDigitEntryString, 10 * sizeof(char));                     

        if(strlen(strMyFourDigitEntryString) == 4)
        {
            for(int i = 0; i < strlen(strMyFourDigitEntryString); i++)
            {
                if(!isdigit(strMyFourDigitString[i]))
                break;
            }
            strcpy(strMyFourDigitString, strMyFourDigitEntryString);
            break;
        }
    }
    return;
}

/*  =================================================================================================================================================
    =========================  GET NAMES AND ADRESS  ================================================================================================
    =================================================================================================================================================
    */

/*  -------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------  GET FIRST NAME  ------------------------------------------------------------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------
    */

void getFullNameAndAdress(char *firstName, char *lastName, char *adress)
{
    while(true)
    {
        clearScreen();
        nameAndAdressBar();
        bool isFirstNameOk = false;
        while(!isFirstNameOk)
        {    
            GetInput("\n\tEnter First Name With Max Length 20: ", firstName, 25 * sizeof(char));
            for(int index = 0; index < strlen(firstName); index++)
            {
                if(!isalpha(firstName[index]))
                {
                    isFirstNameOk = false;
                    break;
                }
            }    
            if(strchr(firstName, '\n'))  
            {

            }
            else if(strlen(firstName) <= 20)
            {
                isFirstNameOk = true;
            }
        }

/*  -------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------  GET LAST NAME  -------------------------------------------------------------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------
    */    

        bool isLastNameOk = false;
        while(!isLastNameOk)
        {    
            GetInput("\n\tEnter Last Name With Max Length 20: ", lastName, 25 * sizeof(char));
            for(int index = 0; index < strlen(lastName); index++)
            {
                if(!isalpha(lastName[index]))
                {
                    isLastNameOk = false;
                    break;
                }
            }
            if(strchr(lastName, '\n'))  
            {
                
            }          
            else if(strlen(lastName) <= 20)
            {
                isLastNameOk = true;
            }        
        }    

/*  -------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------  GET ADRESS  ----------------------------------------------------------------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------
    */
        bool isAdressOk = false;
        while(!isAdressOk)
        {    
            GetInput("\n\tEnter Adress With Max Length 40: ", adress, 45 * sizeof(char));
            for(int index = 0; index < strlen(adress); index++)
            {
                if(!isalpha(adress[index]))
                {
                    isAdressOk = false;
                    break;
                }
            }
            if(strchr(adress, '\n'))  
            {
                
            }       
            else if(strlen(adress) <= 40)
            {
                isAdressOk = true;
            }        
        }
        while(true)
        {
            clearScreen();
            nameAndAdressBar2(firstName, lastName, adress);
            char prompt[100] = "\n\n\tConfirm Input Of Name And Adress [Y/ N] ";
            char menuChoise[7];
            GetInput(prompt, menuChoise, 5 * sizeof(char));

            if(!strcmp(menuChoise, "Y") || !strcmp(menuChoise, "y"))
            {
                return;
            }
            else if(!strcmp(menuChoise, "N") || !strcmp(menuChoise, "n"))
            {
                break;
            }
            else
            {
                printf("\n\tBad Choise From Name And Adress Routine");
                Sleep(2000);
            }   
        }     
    }
    return;
}

void setTabLen(int totalNameLength)
{
    if(totalNameLength < 7)
        printf("\t\t\t\t\t\t");
    else if(totalNameLength < 15)
        printf("\t\t\t\t\t");    
    else if(totalNameLength < 23)
        printf("\t\t\t\t"); 
    else if(totalNameLength < 31)
        printf("\t\t\t");
    else if(totalNameLength < 39)
        printf("\t\t");           
    else
        printf("\t");
    return;
}

void enterCardDataUCN(char *cardFieldOne, char *cardFieldTwo, char *cardFieldThree, char *cardFieldFour, bool fakeScan)
{
    if(!fakeScan)
        printf("\n\tEnter Users Card Number, Four Times Four Digits                                                                                                     Control Lamp:   \033[0;30m[####]\033[0;37m");
    else
        printf("\n\tEnter Users Card Number, Four Times Four Digits                                                                                                     Control Lamp:   \033[0;33m[####]\033[0;37m");
    printf("\n\t==========================================================================================================================================================================\n");            
    printf("\tCard Number First Group: %s\n\n\tCard Number Second Group: %s\n\n\tCard Number Third Group: %s\n\n\tCard Number Fourth Group: %s", cardFieldOne, cardFieldTwo, cardFieldThree, cardFieldFour);
    return;
}

void enterCardDataUCN2(bool fakeScan)
{
    if(!fakeScan)
        printf("\n\tEnter Users Card Number, Four Times Four Digits                                                                                                     Control Lamp:   \033[0;30m[####]\033[0;37m");
    else
        printf("\n\tEnter Users Card Number, Four Times Four Digits                                                                                                     Control Lamp:   \033[0;33m[####]\033[0;37m");
    printf("\n\t==========================================================================================================================================================================\n");    
    return;
}

void nameAndAdressBar(void)
{
    printf("\n\tEnter New Users Name And Adress                                                                                                                     Control Lamp:   \033[0;30m[####]\033[0;37m");
    printf("\n\t==========================================================================================================================================================================\n");        
}

void nameAndAdressBar2(char *firstName, char *lastName, char *adress)
{
    printf("\n\tEnter New Users Name And Adress                                                                                                                     Control Lamp:   \033[0;30m[####]\033[0;37m");
    printf("\n\t==========================================================================================================================================================================\n");            
    printf("\n\tFirst Name: %s\n\n\tLast Name: %s\n\n\tAdress: %s", firstName, lastName, adress);
}