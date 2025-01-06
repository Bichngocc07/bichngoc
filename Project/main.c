#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
    int choice, choice1, role;

    while (1) {
        displayStartMenu();
        printf("Your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 0) {
            printf("Exiting the program...\n");
            break;
        }

        role = displayLogin();
        if (role == 1) {
            do {
                displayAdminMenu();
                printf("Enter Your Choice: ");
        		scanf("%d", &choice1);

        		switch (choice1) {
            		case 1:
                		addUser();
                		break;
            		case 2:
                		displayUserList();
                		break;
            		case 3:
                		displayUserDetails();
                		break;
            		case 4:
                		lockUnlockUser();
                		break;
                    case 5:
                    	sortedUses();
                        break;
                    case 6:
                    	searchUserByName();
                        break;
                    case 0:
                    	saveUsersToFile(filename);
                        printf("Logging out...\n");
                        break;
                    default:
                        printf("Invalid selection. Please try again.\n");
                        break;
                }
            } while (adminchoice != 0);
        } else if (role == 2) {
            printf("Logged in as User.\n");
        } else {
            printf("Login failed.\n");
        }
    } while (choice !=0);

    return 0;
}

