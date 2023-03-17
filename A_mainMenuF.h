#ifndef A_mainMenuF_h
#define A_mainMenuF_h

// typedef struct
// {
//     int lampControl;
// } programParameters;

void clearScreen(void);
void mainMenu(void);
bool GetInputChar(char* prompt, char* value);
bool GetInputChar(char* prompt, char* value);
void blackControllMainMenu(void);
void redControllMainMenu(void);
void yellowControllMainMenu(void);
void greenControllMainMenu(void);
void printfMenuBar(void);
void listCards(void);
void InputNewUser(void);
void setAccess(void);
void newUser(void);
void accessManagement(void);

#endif