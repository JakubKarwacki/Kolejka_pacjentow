/*
Jakub Karwacki, WME23BX1S1
Data utworzenia: 2024.12.07, rozliczono: 2024.12.07
Zadanie 1: Kolejka Pacjentów - FIFO
*/

// Libraries
    #include <stdio.h>
    #include <stdlib.h>
    #include <windows.h>
    #include <time.h>

// Variables
int choice = 0;
int PESEL_index = 0;
int r_year, r_month;
int temp;

SYSTEMTIME t;

// Structures
    typedef struct GenerationData
    {
        char value[21];
        struct GenerationData *previouse;
    } GenerationData;

    typedef struct Patient
    {
        char name[20];
        char surname[20];
        char PESEL[11];
        struct Patient *previouse;
    } Patient;

    // Structure variables
    GenerationData *generationHead = NULL;
    Patient *patientHead = NULL;


// Functions
    int loadData(char filename[11], GenerationData **head); 
    int addPatient(Patient **head);
    int mainMenu();