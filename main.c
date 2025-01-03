/*
Jakub Karwacki, WME23BX1S1
Data utworzenia: 2024.12.07, rozliczono: 2024.12.07
Zadanie 1: Kolejka Pacjentów - FIFO
*/

// Libraries
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
    
// Structures
    typedef struct GenerationData {
        char value[51];
        struct GenerationData* previous;
    } GenerationData;

    typedef struct Patient {
        char name[20];
        char surname[20];
        char documentNumber[10];
        char disease[50];
        struct Patient* next;
    } Patient;

// Prototypes
    // Functions
        int loadData(const char* filename, GenerationData** head, int maxLength);
        void clearGenerationData(GenerationData** head);

        int generateDN(char* documentNumber);
        int generateData(char* tmpValue, GenerationData* tmpValues, int maxLength);

        int isEmpty(Patient* head);
        int addPatient(Patient** head, Patient** tail, GenerationData* names, GenerationData* surnames, GenerationData* diseases);
        int dequeuePatient(Patient** head, Patient** tail);
        int displayQueue(Patient* head);
        int displayFirst(Patient* head);
        void clearQueue(Patient** head, Patient** tail);

        int menu();

    // Main
        int main();

// Functions
    // Data
        int loadData(const char* filename, GenerationData** head, int maxLength) {
            FILE* file = NULL;
            fopen_s(&file, filename, "r");

            file != NULL ? ({
                char temp[51];

                while (fgets(temp, sizeof(temp), file)) {
                    int len = 0;
                    while(temp[len] != '\0' && temp[len] != '\n') { len++; };

                    GenerationData* newNode = (GenerationData*)malloc(sizeof(GenerationData));

                    newNode ? ({
                        for(int i = 0; i < len && i < maxLength; i++) { newNode->value[i] = temp[i]; }
                        newNode->value[len < maxLength ? len : maxLength] = '\0';
                        newNode->previous = *head;
                        *head = newNode;
                    }) : ({ fclose(file); return 0; });
                }

                fclose(file);
                return 1;
            }) : ({ printf("Blad: Nie mozna otworzyc pliku %s\n", filename); return 0; });
            }

        void clearGenerationData(GenerationData** head) {
            while (*head) {
                GenerationData* temp = *head;
                *head = (*head)->previous;
                free(temp);
            }
            }
    // Patient
        int generateDN(char *documentNumber) {
            for (int i = 0; i < 3; i++) {
                documentNumber[i] = 'A' + rand() % 26;
            }
            for (int i = 3; i < 9; i++) {
                documentNumber[i] = '0' + rand() % 10;
            }
            documentNumber[9] = '\0';
            }

        int generateData(char *tmpValue, GenerationData *tmpValues, int maxLength) {
            int tmpValuesCount = 0;
            GenerationData *temp = tmpValues;

            while(temp) { tmpValuesCount++; temp = temp->previous; }
            int nameIndex = rand() % tmpValuesCount;
            for (int i = 0; i < nameIndex && temp; i++) { temp = temp->previous; }
            for (int i = 0; i < maxLength && (temp && temp->value[i] != '\0'); i++) { tmpValue[i] = temp->value[i]; }
            tmpValue[sizeof(tmpValue)+1] = '\0';
            }

    // Menu
        int isEmpty(Patient* head) {
            !head ? ({ printf("Kolejka jest pusta.\n"); return 1; }) : ({ return 0; });
            }

        int addPatient(Patient** head, Patient** tail, GenerationData* names, GenerationData* surnames, GenerationData* diseases) {
            Patient* patientNode = (Patient*)malloc(sizeof(Patient));

            patientNode ? ({
                generateDN(patientNode->documentNumber);

                generateData(patientNode->name, names, 20);
                generateData(patientNode->surname, surnames, 20);
                generateData(patientNode->disease, diseases, 50);

                patientNode->next = NULL;
                *tail ? ({ (*tail)->next = patientNode; }) : ({ *head = patientNode; });
                *tail = patientNode;

                printf("Dodano pacjenta: %s %s, Nr Dokumentu: %s, Choroba: %s\n", patientNode->name, patientNode->surname, patientNode->documentNumber, patientNode->disease);

                return 1;
            }) : ({ return 0; });
            }

        int dequeuePatient(Patient** head, Patient** tail) {
            !isEmpty(*head) ? ({
                Patient* temp = *head;
                *head = (*head)->next;
                !*head ? *tail = NULL : 0;

                printf("Usunieto pacjenta: %s %s, Nr Dokumentu: %s\n", temp->name, temp->surname, temp->documentNumber);
                free(temp);
                return 1;
            }) : ({ return 0; });
            }

        int displayQueue(Patient* head) {
            !isEmpty(head) ? ({
                while (head) {
                    printf("Pacjent: %s %s, Nr Dokumentu: %s, Choroba: %s\n", head->name, head->surname, head->documentNumber, head->disease);
                    head = head->next;
                }
                return 1;
            }) : ({ return 0; });
            }
        int displayFirst(Patient* head) {
            !isEmpty(head) ? ({ printf("Pierwszy pacjent: %s %s, Nr Dokumentu: %s, Choroba: %s\n", head->name, head->surname, head->documentNumber, head->disease); return 1; }) : ({ return 0; });
            }

        void clearQueue(Patient** head, Patient** tail) {
            while(*head) { dequeuePatient(head, tail); }
            }

        int menu() {
            printf("%s %s %s %s %s %s",
                    "Menu:\n",
                    "1. Dodaj pacjenta\n",
                    "2. Usun pacjenta\n",
                    "3. Wyswietl kolejke pacjentow\n",
                    "4. Wyswietl pierwszego pacjenta\n",
                    "5. Wyczysc kolejke\n",
                    "0. Wyjdz\n"
                );

            return 0;
            }
    // Main
        int main() {
            srand(time(NULL));

            GenerationData *maleNames = NULL, *maleSurnames = NULL, *femaleNames = NULL, *femaleSurnames = NULL, *diseases = NULL;

            loadData("data/M_names.csv", &maleNames, 20);
            loadData("data/W_names.csv", &femaleNames, 20);
            loadData("data/M_surnames.csv", &maleSurnames, 20);
            loadData("data/W_surnames.csv", &femaleSurnames, 20);
            loadData("data/ICD10_lvl_1_names.csv", &diseases, 50);

            Patient *patientHead = NULL, *patientTail = NULL;
            int choice = 0;

            do {
                menu();
                scanf_s("%d", &choice);

                switch (choice) {
                    case 0: { break; }
                    case 1: { (rand() % 2) == 0 ? addPatient(&patientHead, &patientTail, femaleNames, femaleSurnames, diseases) : addPatient(&patientHead, &patientTail, maleNames, maleSurnames, diseases); break; }
                    case 2: { dequeuePatient(&patientHead, &patientTail); break; }
                    case 3: { displayQueue(patientHead); break; }
                    case 4: { displayFirst(patientHead); break; }
                    case 5: { clearQueue(&patientHead, &patientTail); break; }
                    default: { printf("Nieprawidlowa opcja.\n"); }
                }
            } while (choice != 0);

            clearGenerationData(&maleNames);
            clearGenerationData(&femaleNames);
            clearGenerationData(&maleSurnames);
            clearGenerationData(&femaleSurnames);
            clearGenerationData(&diseases);
            
            return 0;
        }