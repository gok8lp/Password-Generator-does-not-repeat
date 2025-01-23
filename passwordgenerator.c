#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// *** Random Password Generator ***

void generator(int lenght, bool onlynumbers, bool onlyletters, bool numbersandletters, bool numberslettersandspecialcharacters);

int main() {
    bool continuepassword = false;
    int choice;
    bool onlynumbers = false;
    bool onlyletters = false;
    bool numbersandletters = false;
    bool numberslettersandspecialcharacters = false;

    do {

        int Lenghtpassword;

        printf("*** Random Password Generator ***\nMade by: @gokalpgoksu\n\n");
        printf("**Maximum length 8-16 of password**\n");
        printf("Enter the length of the password?: ");
        scanf("%d", &Lenghtpassword);

        if (Lenghtpassword < 8 || Lenghtpassword > 16) {
            printf("Please enter a value between 8 and 16\n ");
            return 0;
        }

        char specialcharacters;

        printf("Should the password contain special characters? (y/n): ");
        scanf(" %c", &specialcharacters);

        if (specialcharacters == 'y' || specialcharacters == 'n') {
            if (specialcharacters == 'y') {
                printf("Special characters will be included in the password\n\n");

                printf("Which special characters should be included in the password?\n(1) Only numbers\n(2) Only letters\n(3) Numbers and letters\n(4) Numbers, letters and special characters\n");


                scanf("%d", &choice);
                if (choice == 1) {
                    onlynumbers = true;
                } else if (choice == 2) {
                    onlyletters = true;
                } else if (choice == 3) {
                    numbersandletters = true;
                } else if (choice == 4) {
                    numberslettersandspecialcharacters = true;
                } else {
                    do {
                        printf("Please enter a valid value\n");
                        printf("Which special characters should be included in the password?\n(1) Only numbers\n(2) Only letters\n(3) Numbers and letters\n(4) Numbers, letters and special characters\n");
                        scanf("%d", &choice);
                    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
                }

            } else if (specialcharacters == 'n') {
                printf("Special characters will not be included in the password\n");
                printf("Which special characters should be included in the password?\n(1) Only numbers\n(2) Only letters\n(3) Numbers and letters\n");
                scanf("%d", &choice);

                if(choice < 1 || choice > 3) {
                    do {
                        printf("Please enter a valid value\n");
                        printf("Which special characters should be included in the password?\n(1) Only numbers\n(2) Only letters\n(3) Numbers and letters\n");
                        scanf("%d", &choice);
                    } while (choice < 1 || choice > 3);
                }

                if(choice == 1) {
                    onlynumbers = true;
                }else if(choice == 2) {
                    onlyletters = true;
                }else if(choice == 3) {
                    numbersandletters = true;
                }

            }

            if(Lenghtpassword >= 8 && Lenghtpassword <= 16) {
            generator(Lenghtpassword, onlynumbers, onlyletters, numbersandletters, numberslettersandspecialcharacters);
            }


        } else {
            do {
                printf("Please enter a valid value\n");
                printf("Should the password contain special characters? (y/n): ");
                scanf(" %c", &specialcharacters);
            } while (specialcharacters != 'y' && specialcharacters != 'n');
        }




        printf("Do you want to generate a new password? (y/n): ");
        char newpassword;
        scanf(" %c", &newpassword);
        if (newpassword == 'y') {
            continuepassword = true;
        } else if (newpassword == 'n') {
            continuepassword = false;
        } else {
            do {
                printf("Please enter a valid value\n");
                printf("Do you want to generate a new password? (y/n): ");
                scanf(" %c", &newpassword);
            } while (newpassword != 'y' && newpassword != 'n');
        }
    } while (continuepassword == true);

    printf("*******************************\n\nTHANKS FOR USED\n\n");

    return 0;
}

void generator(int lenght, bool onlynumbers, bool onlyletters, bool numbersandletters, bool numberslettersandspecialcharacters) {
    int size = lenght;
    char letter[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+[]{}|;:,.<>?";
    int count = 0;

    srand(time(NULL));

    // Only numbers

    if (onlynumbers == true) {
        int size = strlen(digits);

        if(lenght > size) {
            printf("ERROR: Not enough digits to generate the password\n");
            return;
        }

        char *newPassword = (char*)malloc((lenght + 1) * sizeof(char));

        for(int i = 0; i < lenght; i++) {
            int randomIndex = rand() % size;
            newPassword[i] = digits[randomIndex];
        }

        newPassword[lenght] = '\0';
        printf("*******************************\nYour password is: %s\n", newPassword);
        free(newPassword);

        //only letters

    } else if (onlyletters == true) {
        int avaibleLetters[26];

        for(int i = 0; i < 26; i++) {
            avaibleLetters[i] = letter[i];
        }

        if(lenght > 26) {
            printf("ERROR: Not enough letters to generate the password\n");
            return;
        }

        char *newPassword = (char*)malloc((lenght + 1) * sizeof(char));

        for(int i = 0; i < lenght; i++) {
            int randomIndex = rand() % 26;
            newPassword[i] = avaibleLetters[randomIndex];
        }

        newPassword[lenght] = '\0';
        printf("*******************************\nYour password is: %s\n", newPassword);
        free(newPassword);

        //numbers and letters

    } else if (numbersandletters == true) {
        int size = strlen(digits) + strlen(letter);
        char *list = (char*)malloc(size * sizeof(char));
        strcpy(list, digits);
        strcat(list, letter);

        if(lenght > size) {
            printf("ERROR: Not enough digits and letters to generate the password\n");
            free(list);
            return;
        }

        char *newPassword = (char*)malloc((lenght + 1) * sizeof(char));

        for(int i = 0; i < lenght; i++) {
            int randomIndex = rand() % size;
            newPassword[i] = list[randomIndex];
        }

        newPassword[lenght] = '\0';
        printf("*******************************\nYour password is: %s\n", newPassword);
        free(newPassword);
        free(list);

        //numbers, letters and special characters

    } else if (numberslettersandspecialcharacters == true) {
        int size = strlen(digits) + strlen(letter) + strlen(symbols);
        char *list = (char*)malloc(size * sizeof(char));
        strcpy(list, digits);
        strcat(list, letter);
        strcat(list, symbols);

        if(lenght > size) {
            printf("ERROR: Not enough digits, letters and special characters to generate the password\n");
            free(list);
            return;
        }

        char *newPassword = (char*)malloc((lenght + 1) * sizeof(char));

        for(int i = 0; i < lenght; i++) {
            int randomIndex = rand() % size;
            newPassword[i] = list[randomIndex];
        }

        newPassword[lenght] = '\0';
        printf("*******************************\nYour password is: %s\n", newPassword);
        free(newPassword);


    }

    printf("*******************************\n\nTHANKS FOR USED\n\n");
}