#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"
typedef struct {
    char id[20];
    char name[50];
    char email[50];
    char phone[20];
    int gender;
    int birthDay, birthMonth, birthYear;
    bool isLocked;
} User;
// khong co address
void display_admin_menu() {
}

void addUser() {
}

void show_users() {

}

void search_user_by_name() {

}
User users[100];
int userCount = 0;

//////
void sortedUsers() {
	int choice;
	printf("\nChoose how to sort the user list:\n");
	printj("[1] Sort by Name\n");
	printf("[2] Sort by Status (Locked/Unlocked)\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	
	if (choice == 1) {
		//
        for (int i = 0; i < userCount - 1; i++) {
            for (int j = i + 1; j < userCount; j++) {
                if (strcmp(users[i].name, users[j].name) > 0) {
                    User temp = users[i];
                    users[i] = users[j];
                    users[j] = temp;
                }
            }
        }
        printf("\nUser list has been sorted by Name.\n");
    } else if (choice == 2) {
        // 
        for (int i = 0; i < userCount - 1; i++) {
            for (int j = i + 1; j < userCount; j++) {
                if (users[i].isLocked > users[j].isLocked) {
                    User temp = users[i];
                    users[i] = users[j];
                    users[j] = temp;
                }
            }
        }
        printf("\nUser list has been sorted by Status.\n");
    } else {
        // 
        printf("\nInvalid choice. Please try again.\n");
        return;
    }
    //
    displayUserList();
}
 //
void displayStartMenu() {
    printf("\n*** Bank Management System Using C ***\n\n");
    printf("               CHOOSE YOUR ROLE            \n");
    printf("===========================================\n");
    printf("[1] Admin.\n");
    printf("[2] User.\n");
    printf("[0] Exit the Program.\n");
    printf("===========================================\n");
}

int displayLogin() {
	system("cls");
    char email[50], password[50];
    printf("\n*** Bank Management System Using C ***\n");
    printf("\n                  LOGIN               \n");
    printf("==========================================\n");
    printf("Email: admin@gmail.com\n");
    printf("Password : ******\n");
    printf("==========================================\n");
    printf("Enter your email: ");
    scanf("%s", email);
    printf("Enter your password: ");
    scanf("%s", password);
    
    if (strcmp(email, "admin@gmail.com") == 0 && strcmp(password, "123456") == 0) {
        printf("\nLogin successful!\n");
        return 1;
    } else {
        printf("\nInvalid credentials.\n");
        exit(0);
    }
}

void addUser() {
	system("cls");
    User newUser;
    printf("\n*** Add a new user ***\n");

    do {
        printf("Enter the ID (must be at least 10 characters): ");
        scanf("%s", newUser.id);
        if (strlen(newUser.id) < 10) {
            printf("Error: ID cannot be less than 10 characters.\n");
        }
    } while (strlen(newUser.id) < 10);
    printf("Enter the name: ");
    scanf(" %[^\n]s", newUser.name);
    printf("Enter the email: ");
    scanf(" %[^\n]s", newUser.email);
    printf("Enter the phone: ");
    scanf(" %[^\n]s", newUser.phone);

    do {
        printf("Enter the gender (0 for Male, 1 for Female): ");
        scanf("%d", &newUser.gender);
        if (newUser.gender != 0 && newUser.gender != 1) {
            printf("Invalid input. Please enter 0 for Male or 1 for Female.\n");
        }
    } while (newUser.gender != 0 && newUser.gender != 1);

    printf("Enter the date of birth:\n");
    printf("     Enter the day: ");
    scanf("%d", &newUser.birthDay);
    printf("     Enter the month: ");
    scanf("%d", &newUser.birthMonth);
    printf("     Enter the year: ");
    scanf("%d", &newUser.birthYear);

    newUser.isLocked = false;
	
    users[userCount++] = newUser;
	
    printf("\nUser added successfully!\n");
}

void displayUserList() {
	system("cls");
    printf("|================================================================================================|\n");
    printf("                                       User Information\n");
    printf("|================================================================================================|\n");
    printf("+------------+----------------------+------------+------------+----------------------+-----------+\n");
    printf("| User ID    | Name                 | Gender     | Phone      | Email                | Status    |\n");
    printf("+------------+----------------------+------------+------------+----------------------------------+\n");

    for (int i = 0; i < userCount; i++) {
        printf("| %-10s | %-20s | %-10d | %-10s | %-20s | %-9s |\n",
			users[i].id,
			users[i].name,
			users[i].gender,
			users[i].phone, users[i].email,
			users[i].isLocked ? "Lock" : "Unlock");
    }
    printf("|================================================================================================|\n");
    // o cai ham nay thuc thi
}

/////////////////////////////
void sortUses(int choice){
	for (int i = 0; i < userCount - 1; i++){
		for (int j = i +1; j < userCount; j++){
			if ((choice == 1 && strcmp(users[i].name, users[j].name) > 0) ||
                (choice == 2 && users[i].isLocked > users[j].isLocked)) {
                Us? temp = users[i];
                users[i] = users[j];
                users[j] = temp;
		}
	}
 }
 printf("\nUsers sorted successfully!\n");
}
void searchUserByName() {
    system("cls");
    char name[50];
    printf("\nEnter Name to Search: ");
    scanf(" %[^\n]s", name);

    printf("\nSearch Results:\n");
    for (int i = 0; i < userCount; i++) {
        if (strstr(users[i].name, name)) {
            printf("ID: %s | Name: %s | Status: %s\n", users[i].id, users[i].name,
                   users[i].isLocked ? "Locked" : "Active");
        }
    }
}
////////////////////////////
void displayUserDetails() {
	system("cls");
    char id[20];
    int found = 0;
    printf("\nEnter the ID of the user to view details: ");
    scanf("%s", id);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, id) == 0) {
            printf("\n*** User Details ***\n");
            printf("ID: %s\n", users[i].id);
            printf("Name: %s\n", users[i].name);
            printf("Email: %s\n", users[i].email);
            printf("Phone: %s\n", users[i].phone);
            printf("Gender: %s\n", users[i].gender == 0 ? "Male" : "Female");
            printf("Date of Birth: %02d/%02d/%d\n", users[i].birthDay, users[i].birthMonth, users[i].birthYear);
            printf("Status: %s\n", users[i].isLocked ? "Locked" : "Open");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nError: User with ID %s not found.\n", id);
    }
}
//////////////////////////////////////////////////////////////// chua xem
void findUserByID(User users[], int userCount, int searchID) {
    int found = 0;
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == searchID) {
            printf("\nUser Found:\n");
            printf("ID: %s\n", users[i].id);
            printf("Name: %s\n", users[i].name);
            printf("Email: %s\n", users[i].email);
            printf("Phone: %s\n", users[i].phone);
            printf("Gender: %s\n", users[i].gender == 0 ? "Male" : "Female");
            printf("Date of Birth: %02d/%02d/%d\n", users[i].birthDay, users[i].birthMonth, users[i].birthYear);
            printf("Gender: %s\n", users[i].gender);
            printf("Status: %s\n", users[i].isLocked ? "Locked" : "Open");
            found = 1;
            break;
        }
    }
    if (!found) {
            printf("\nError: User with name %s not found.\n", searchID);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void displayUserID(User users[], int userCount, int searchID) {
	system("cls");
    int found = 0;
    printf("+-----------+-------------------+-----------+----------------+\n");
    printf("| User ID   | Name              | Gender    | Phone          |\n");
    printf("+-----------+-------------------+-----------+----------------+\n");

    for (int i = 0; i < userCount; i++) {
        if (users[i].id == searchID) {
            printf("| %-9d | %-18s  | %-9s | %-14s | %-17s | %-8s |\n",
                users[i].id, users[i].name, users[i].gender,
                users[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("User with ID %d not found.\n", searchID);
    }


    printf("+-----------+--------------------+------------+-----------+----------------+-------------------+----------+\n");
    char choice;
            printf("Go back (b)? or Exit (0)? ");
            scanf(" %c", &choice);
            getchar();
            if (choice == 'b' || choice == 'B') {
                system("cls");
                return;
            } else if (choice == '0') {
                exit(0);
            }
}
///////////////////////////////////////////////////////////// cham cham
// Ham khoa / mo khoa nguoi dung
void lockUnlockUser() {
	system("cls");
    char id[20];
    int found = 0;
    printf("\nEnter the ID of the user to lock/unlock: ");
    scanf("%s", id);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, id) == 0) {
            if (users[i].isLocked == 0) {
                printf("User is open, confirming to lock...\n");
                users[i].isLocked = 1;
                printf("User has been locked successfully.\n");
            } else {
                printf("User is locked, confirming to unlock...\n");
                users[i].isLocked = 0;
                printf("User has been unlocked successfully.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nError: User with ID %s not found.\n", id);
    }
}
/////////////////////////
void displayUserName(){
	system("cls");
	char name[20];
	int found = 0;
	printf("\nEnter the Name of the user to view details: ");
	scanf("%s", name);
	
	 for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("\n*** User Details ***\n");
            printf("ID: %s\n", users[i].id);
            printf("Name: %s\n", users[i].name);
            printf("Email: %s\n", users[i].email);
            printf("Phone: %s\n", users[i].phone);
            printf("Gender: %s\n", users[i].gender == 0 ? "Male" : "Female");
            printf("Date of Birth: %02d/%02d/%d\n", users[i].birthDay, users[i].birthMonth, users[i].birthYear);
            printf("Status: %s\n", users[i].isLocked ? "Locked" : "Open");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nError: User with name %s not found.\n", name);
    }
}
/////////////////////////////
void displayAdminMenu(){
        printf("\n*** Bank Management System Using C ***\n");
        printf("                    MENU                 \n");
        printf("===========================================\n");
        printf("[1] Add A New user.\n");
        printf("[2] Show All users.\n");
        printf("[3] Show detail of a user.\n");
        printf("[4] Lock (Unlock) a user.\n");
        printf("[5] Sort the user list\n");
        printf("[6] Search for users by name\n");
        printf("[0] Exit the Program.\n");
        printf("===========================================\n");
}


