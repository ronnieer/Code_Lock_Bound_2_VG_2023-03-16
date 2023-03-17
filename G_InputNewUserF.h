#ifndef G_InputNewUserF_h
#define G_InputNewUserF_h


void clearScreen(void);
void InputNewUser(void);
void InputNewUserData(char *fullCardNumber, users *data);
void readDateAndTime(char *readDate, char *readTime);
void getCardNumber(char *fullCardNumber, bool fakeScan);
//void getFullName(char *firstName, char *lastName);
//void getAdrass(char *adress);
void getFullNameAndAdress(char *firstName, char *lastName, char *adress);
INPUT_RESULT GetInput(char* prompt, char* buff, int maxSize);
void inputNewUserBar(void);

#endif