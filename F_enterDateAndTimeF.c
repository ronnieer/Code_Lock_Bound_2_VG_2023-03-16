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


void readDateAndTime(char *readDate, char *readTime);

/*  =================================================================================================================================================
    =========================  GET DATE AND TIME  ===================================================================================================
    =================================================================================================================================================
    */

void readDateAndTime(char *readDate, char *readTime)
{

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(readDate, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    sprintf(readTime, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    return;
}
