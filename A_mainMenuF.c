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
void mainMenu(void);
void blackControllMainMenu(void);
void redControllMainMenu(void);
void yellowControllMainMenu(void);
void greenControllMainMenu(void);
void listCards(void);
void InputNewUser(void);
void setAccess(void);
void fakeTestScanCard(void);
void newUser(void);
void accessManagement(void);


/*  =================================================================================================================================================
    =========================  MAIN MENU LOOP  ======================================================================================================
    =================================================================================================================================================
    */
    void mainMenu(void)
    {
        while(true)
        {
            blackControllMainMenu();
            char prompt[30] = "";
            char menuChoise[7];
            GetInput(prompt, menuChoise, 5 * sizeof(char));

            if(!strcmp(menuChoise, "1"))
            {
                greenControllMainMenu();
            }
            else if(!strcmp(menuChoise, "2"))
            {
                listCards();
            }
            else if(!strcmp(menuChoise, "3"))
            {
                InputNewUser();
            }
            else if(!strcmp(menuChoise, "4"))
            {
                setAccess();
            }
            else if(!strcmp(menuChoise, "5"))
            {
                fakeTestScanCard();
            }        
            else if(!strcmp(menuChoise, "9"))
            {
                while(true)
                {
                    clearScreen();
                    char prompt[60] = "\n\tExit, Are You Sure? [Y/ N] ";
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
                        printf("\n\tBad Choise From Exit Routine");
                        Sleep(2000);
                    }
                }
            }
            else
            {
                printf("\n\tBad Choise From Main Menu");
                Sleep(2000);
            }        
        }
    }

    void blackControllMainMenu(void)
    {
/*  -------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------  BLACK KONTROLLAMP  ---------------------------------------------------------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------
    */
        clearScreen();
        printf("\033[0;37m");
        printf("\n\tAdmin Menu                                                                                                                                          Control Lamp:   \033[0;30m[####]\033[0;37m");
        printf("\n\t==========================================================================================================================================================================");
        printf("\n\t1.   Remote Open Door");
        printf("\n\t2.   List All Cards In System");
        printf("\n\t3.   Add Card");
        printf("\n\t4.   Set Access");
        printf("\n\t5.   Fake Test Scan Card"); //Exit");
        printf("\n\t9.   Exit"); //Fake Test Scan Card"); 
        printf("\n\t==========================================================================================================================================================================");
        printf("\n\n\t");
        return;
    }

    void redControllMainMenu(void)
    {
/*  -------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------  RED KONTROLLAMP  -----------------------------------------------------------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------
    */
        clearScreen();
        printf("\033[0;37m");
        printf("\tAdmin Menu                                                                                                                                          Control Lamp:   \033[0;31m[####]\033[0;37m");
        printf("\n\t==========================================================================================================================================================================");
        printf("\n\t1.   Remote Open Door");
        printf("\n\t2.   List All Cards In System");
        printf("\n\t3.   Add Card");
        printf("\n\t4.   Set Access");
        printf("\n\t5.   Fake Test Scan Card"); //Exit");
        printf("\n\t9.   Exit"); //Fake Test Scan Card"); 
        printf("\n\t==========================================================================================================================================================================");
        printf("\n\n\t");
        Sleep(3000);
        return;
    }

    void yellowControllMainMenu(void)
    {
/*  -------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------  YELLOW KONTROLLAMP  --------------------------------------------------------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------
    */
        clearScreen();
        printf("\033[0;37m");
        printf("\n\tAdmin Menu                                                                                                                                          Control Lamp:   \033[0;33m[####]\033[0;37m");
        printf("\n\t==========================================================================================================================================================================");
        printf("\n\t1.   Remote Open Door");
        printf("\n\t2.   List All Cards In System");
        printf("\n\t3.   Add Card");
        printf("\n\t4.   Set Access");
        printf("\n\t5.   Fake Test Scan Card"); //Exit");
        printf("\n\t9.   Exit"); //Fake Test Scan Card"); 
        printf("\n\t==========================================================================================================================================================================");
        printf("\n\n\t");
        Sleep(3000);
        return;        
    }

    void greenControllMainMenu(void)
    {
/*  -------------------------------------------------------------------------------------------------------------------------------------------------
    -------------------------  GREEN KONTROLLAMP  ---------------------------------------------------------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------
    */
        clearScreen();
        printf("\033[0;37m");
        printf("\n\tAdmin Menu                                                                                                                                          Control Lamp:   \033[0;32m[####]\033[0;37m");
        printf("\n\t==========================================================================================================================================================================");
        printf("\n\t1.   Remote Open Door");
        printf("\n\t2.   List All Cards In System");
        printf("\n\t3.   Add Card");
        printf("\n\t4.   Set Access");
        printf("\n\t5.   Fake Test Scan Card"); //Exit");
        printf("\n\t9.   Exit"); //Fake Test Scan Card"); 
        printf("\n\t==========================================================================================================================================================================");
        printf("\n\n\t");
        Sleep(3000);
        return;        
    }    

