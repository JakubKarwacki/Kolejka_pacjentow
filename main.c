/*
Jakub Karwacki, WME23BX1S1
Data utworzenia: 2024.12.07, rozliczono: 2024.12.07
Zadanie 1: Kolejka Pacjentów - FIFO
*/

// Files
    #include "main.h"

// Functions
    int loadData(char *filename, GenerationData **head) {
        GenerationData *node = (GenerationData *) malloc(sizeof(GenerationData));
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
                node->value[i] = temp[i];
            }
            node->previouse = *head;
            *head = node;

            printf("%s\n", node->value);
        }
        fclose(file);

        *head = NULL;
        return 0;
    }

    int addPatient() {

        return 0;
    }

    int mainMenu() {
        printf("%s %s %s %s %s %s",
                "Menu:\n",
                "1. Dodaj pacjenta\n",
                "2. Usun pacjenta\n",
                "3. Wyswietl kolejke pacjentow\n",
                "4. Przyjęto pacjenta\n",
                "0. Wyjdz\n"
            );

        return 0;
    }

    int main() {
        // Data loading
        loadData("data/M_names.txt", &head);
        loadData("data/M_surnames.csv", &head);
        loadData("data/F_names.csv", &head);
        loadData("data/F_surnames.csv", &head);

        // Menu - initialization
        mainMenu();

        // Menu - user choice loop
        do
        {
            printf("\n:> ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    //addPatient();
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