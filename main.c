/*
Jakub Karwacki, WME23BX1S1
Data utworzenia: 2024.12.07, rozliczono: 2024.12.07
Zadanie 1: Kolejka Pacjentów - FIFO
*/

// Files
    #include "main.h"

// Functions
    int addPatient() {

        return 0;
    }

    int main() {
        int choice = 0;

        printf("%s %s %s %s %s %s",
                "Menu:\n",
                "1. Dodaj pacjenta\n",
                "2. Usun pacjenta\n",
                "3. Wyswietl kolejke pacjentow\n",
                "4. Przyjęto pacjenta\n",
                "0. Wyjdz\n"
            );

        do
        {
            printf("\n:> ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    addPatient();
                    printf(": Dodano pacjenta!\n");
                    break;
                case 2:
                    // removePatient();
                    printf(": Usunieto pacjenta!\n");
                    break;
                case 3:
                    // showPatients();
                    printf(": Wyswietlono kolejke pacjentow!\n");
                    break;
                case 4:
                    // savePatients();
                    printf(": Kolejka przesunela sie do przodu, pacjent został przyjęty!\n");
                    break;
                default:
                    printf(": Wybierz jeszcze raz!\n");
                    break;
                }
        }
        while (choice != 0);
        
        return 0;
    }