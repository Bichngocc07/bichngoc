#include <stdio.h>
#include <stdbool.h>
#include "datatypes.h"

struct Date {
    int month;
    int day;
    int year;
};
struct Transaction {
    char transferId[10];
    char receivingId[10];
    double amount;
    char type[10];
    char message[50];
    struct Date transactionDate;
};
struct AccountInfo {
    char userId[20];
    float balance;
    bool status; 
    struct Transaction transactionHistory[100];
};
struct user {
    char name[50];
    char email[50];
    char phone[15];
    int is_locked;
    char userId[20];
    int gender;
    struct Date dateOfBirth;
    char username[20];
    float balance;
};




