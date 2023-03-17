PROG=main.exe
CC=gcc
CFLAGS=-g -Wall -Werror -std=c99
DEPS = A_mainMenuF.h C_enterCardDataF.h D_setAccessF.h E_listCardDataF.h F_enterDateAndTimeF.h G_InputNewUserF.h H_SafeInput.h J_fakeTestScan.h I_user.h
OBJ = A_mainMenuF.o C_enterCardDataF.o D_setAccessF.o E_listCardDataF.o F_enterDateAndTimeF.o G_InputNewUserF.o H_SafeInput.o J_fakeTestScan.o main.o
 
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
 
$(PROG): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)