/*
Jakub Karwacki, WME23BX1S1
Data utworzenia: 2024.12.07, rozliczono: 2024.12.07
Zadanie 1: Kolejka Pacjentów - FIFO
*/

// Files
    #include "main.h"

// Functions
    int loadData(char *filename, GenerationData **head) {
        GenerationData *generationNode = (GenerationData *) malloc(sizeof(GenerationData));
        char temp[21];

        FILE *file = fopen(filename, "r");
        if(file == NULL)
        {
            printf("Error!\n");
            return 1;
        }
        
        while (fscanf(file, "%s", &temp) != EOF){
            for (int i = 0; i < sizeof(temp); i++)
            {
                generationNode->value[i] = temp[i];
            }
            generationNode->previouse = *head;
            *head = generationNode;
        }
        fclose(file);

        *head = NULL;

        return 0;
    }

    int addPatient(Patient **head) {
        Patient *patientNode = (Patient *) malloc(sizeof(Patient));

        r_year = (rand() % 120 + (t.wYear - 120)) / 100;
        r_month = rand() % 12 + 1;

        if (r_month < 10) {
            char xd[sizeof(r_month % 10)] = r_month % 10;
            printf("%s", xd[0]);
            patientNode->PESEL[PESEL_index++] = '0';
            patientNode->PESEL[3] = (char)(r_month % 10);
        }

        switch (r_year) {
            case 18:
                temp = 80 + r_month;
                break;
            case 19:
                temp = 0 + r_month;
                break;
            case 20:
                temp = 20 + r_month;
                break;
            case 21:
                temp = 40 + r_month;
                break;
            case 22:
                temp = 60 + r_month;
                break;
        }

        printf("Year: %d; Month: %d\n", temp, r_month);

        patientNode->PESEL[PESEL_index++] = (char)(temp / 10);
        patientNode->PESEL[PESEL_index++] = (char)(temp % 10);

        //printf("Pesel: %s\n", patientNode->PESEL);

        patientNode->previouse = *head;
        *head = patientNode;

        return 0;
    }

    int mainMenu() {
        printf("%s %s %s %s %s %s",
                "Menu:\n",
                "1. Dodaj pacjenta\n",
                "2. Usun pacjenta\n",
                "3. Wyswietl kolejke pacjentow\n",
                "4. Przyjeto pacjenta\n",
                "0. Wyjdz\n"
            );

        return 0;
    }

    int main() {
        GetLocalTime(&t);

        // Data loading
        loadData("data/M_names.txt", &generationHead);
        //loadData("data/M_surnames.csv", &generationHead);
        //loadData("data/F_names.csv", &generationHead);
        //loadData("data/F_surnames.csv", &generationHead;

        // Menu - initialization
        mainMenu();

        // Menu - user choice loop
        do
        {
            printf("\n:> ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    addPatient(&patientHead);
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
                    printf(": Kolejka przesunela sie do przodu, pacjent zostal przyjety!\n");
                    break;
                default:
                    printf(": Wybierz jeszcze raz!\n");
                    break;
                }
        }
        while (choice != 0);
        
        return 0;
    }