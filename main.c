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

/*  =================================================================================================================================================
    =================================================================================================================================================
    =========================  FILE ENCODING ISO 8959-1  ============================================================================================
    =================================================================================================================================================
    =================================================================================================================================================
    */

// 2023-03-16 ALL FILES SHOULD HAVE ISO 8959-1 ENCODING




void clearScreen(void);

void clearScreen(void)
{
    system("cls");
}

int main()
{
    mainMenu();
    return 0;
}  
