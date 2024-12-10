/*
Jakub Karwacki, WME23BX1S1
Data utworzenia: 2024.12.07, rozliczono: 2024.12.07
Zadanie 1: Kolejka Pacjentów - FIFO
*/

// Libraries
    #include <stdio.h>
    #include <stdlib.h>

// Variables
int choice = 0;

// Structures
    typedef struct GenerationData
    {
        char value[21];
        struct GenerationData *previouse;
    } GenerationData;

    typedef struct FIFO
    {
        char name[20];
        char surname[20];
        char PESEL[11];
        struct FIFO *prev;
    } FIFO;

    // Structure variables
    GenerationData *head = NULL;


// Functions
    int loadData(char filename[11], GenerationData **head); 
    int addPatient();
    int mainMenu();