#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    char customerID[12];
    char customerFirstName[20];
    char customerLastName[20];
    double customerBalance;
    char *secretPassword;
} CustomerInformation;

typedef struct {
    char sourceTransactionID[11];
    double sentAmount;
    char destTransationID[11];
} Transaction;

typedef struct llnode {
    CustomerInformation item;
    struct llnode *next;
} llnode;

typedef struct {
    llnode *front;
} llist;

llist *list_create(void) {
    llist *list = (llist *)malloc(sizeof(llist));
    list->front = NULL;
    return list;
}

void add_front(CustomerInformation customer, llist *lst) {
    llnode *newnode = (llnode *)malloc(sizeof(llnode));
    newnode->item = customer;
    newnode->next = lst->front;
    lst->front = newnode;
}

void add_back(CustomerInformation customer, llist *lst) {
    llnode *newnode = (llnode *)malloc(sizeof(llnode));
    newnode->item = customer;
    newnode->next = NULL;
    if (lst->front == NULL) {
        lst->front = newnode;
    } else {
        llnode *current = lst->front;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

void free_nodes(llnode *node) {
    if (node) {
        free(node->item.secretPassword);
        free_nodes(node->next);
        free(node);
    }
}

void list_destroy(llist *lst) {
    free_nodes(lst->front);
    free(lst);
}

int node_length(const llnode *node) {
    if (node == NULL)
        return 0;
    return 1 + node_length(node->next);
}

int list_length(const llist *lst) {
    return node_length(lst->front);
}

void encryptPassword(char *password) {
    for (int i = 0; i < strlen(password); i++) {
        password[i] = (((password[i] + 3) * 2) - 1);
    }
}

char* decryptPassword(const char *password) {
    char *decryptedPassword = strdup(password);
    for (int i = 0; i < strlen(decryptedPassword); i++) {
        decryptedPassword[i] = (((decryptedPassword[i] + 1) / 2) - 3);
    }
    return decryptedPassword;
}


CustomerInformation* getByID(llist *customerList, char *customerID) {
    llnode *current = customerList->front;
    while (current != NULL) {
        if (strcmp(current->item.customerID, customerID) == 0) {
            return &current->item;
        }
        current = current->next;
    }
    return NULL;
}

bool authenticate(llist *customerList, char *customerID, char *inputPassword) {
    CustomerInformation *current = getByID(customerList, customerID);
    if (current != NULL) {
        char *storedPassword = current->secretPassword;
        char *decryptedStoredPassword = decryptPassword(storedPassword);
        printf("Stored Password: %s\n", storedPassword); // Debug print
        printf("Decrypted Stored Password: %s\n", decryptedStoredPassword); // Debug print
        printf("Input Password: %s\n", inputPassword); // Debug print
        bool isAuthenticated = (strcmp(decryptedStoredPassword, inputPassword) == 0);
        free(decryptedStoredPassword);
        return isAuthenticated;
    }
    return false;
}

int main() {
    llist *customerList = list_create();
    if (customerList == NULL) {
        fprintf(stderr, "Failed to create customer list\n");
        return 1;
    }
    int option = 0;

    while (option != 5) {
        printf("Bank Menu\n");
        printf("1 - Create new customer\n");
        printf("2 - Delete customer\n");
        printf("3 - Display customer\n");
        printf("4 - Insert transactions\n");
        printf("5 - Exit\n");

        printf("\nPlease select an option: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        while (getchar() != '\n'); // Clear input buffer

        switch(option) {
            case 1: {
                CustomerInformation customer = {0}; // Initialize a new customer
                printf("\nPlease enter the customer Information\n");
                printf("Enter customer first name: ");
                scanf("%19s", customer.customerFirstName);
                while (getchar() != '\n'); // Clear input buffer
                
                printf("Enter customer last name: ");
                scanf("%19s", customer.customerLastName);
                while (getchar() != '\n'); // Clear input buffer

                while (1) {
                    printf("\nSet your Password. Your password must be between 8 to 20 characters\n");
                    char password[22];
                    printf("Enter your password: ");
                    scanf("%21s", password);
                    while (getchar() != '\n'); // Clear input buffer

                    if (strlen(password) > 20 || strlen(password) < 8) {
                        printf("\nPassword must be between 8 to 20 characters\n");
                        continue;
                    }

                    printf("Confirm your password: ");
                    char confirmPassword[22];
                    scanf("%21s", confirmPassword);
                    while (getchar() != '\n'); // Clear input buffer
                    
                    if (strcmp(password, confirmPassword) == 0) {
                        encryptPassword(password);
                        customer.secretPassword = strdup(password);
                        printf("Password set successfully\n");
                        break;
                    } else {
                        printf("Passwords do not match\n");
                    }
                }

                // Generate customer ID
                srand(time(NULL));
                for (int i = 0; i < 5; i++) {
                    customer.customerID[i] = (rand() % 26) + 'A';
                }
                customer.customerID[5] = '-';
                for (int i = 6; i < 11; i++) {
                    customer.customerID[i] = (rand() % 10) + '0';
                }
                customer.customerID[11] = '\0';
                printf("Customer ID: %s\n", customer.customerID);

                customer.customerBalance = 0.0; // Initialize customer balance

                add_back(customer, customerList); // Add customer to list
                break;
            }
            case 2: {
                printf("Please enter the customer ID to delete: ");
                char customerIDCheck[12];
                scanf("%11s", customerIDCheck);
                while (getchar() != '\n'); // Clear input buffer
                CustomerInformation *thisCustomer = getByID(customerList, customerIDCheck);
                
                if (thisCustomer == NULL) {
                    printf("\nCustomer not found\n");
                    break;
                }

                char password[22];
                while (1) {
                    printf("Enter your password: ");
                    scanf("%21s", password);
                    while (getchar() != '\n'); // Clear input buffer
                    authenticate(customerList, customerIDCheck, password);
                        printf("Authenticated\n");
                        // TODO: Implement customer deletion
                        break;
                    //} else {
                    //    printf("Incorrect password\n");
                    //}
                }
                break;
            }
            case 3: {
                printf("Please enter the customer ID to display: ");
                char customerIDCheck[12];
                scanf("%11s", customerIDCheck);
                while (getchar() != '\n'); // Clear input buffer
                CustomerInformation *thisCustomer = getByID(customerList, customerIDCheck);
                
                if (thisCustomer == NULL) {
                    printf("\nCustomer not found\n");
                } else {
                    printf("\nCustomer Information:\n");
                    printf("ID: %s\n", thisCustomer->customerID);
                    printf("Name: %s %s\n", thisCustomer->customerFirstName, thisCustomer->customerLastName);
                    printf("Balance: %.2f\n", thisCustomer->customerBalance);
                }
                break;
            }
            case 4: {
                char sourceID[12];
                printf("Please enter the source customer ID or \"Deposit\": ");
                scanf("%11s", sourceID);
                while (getchar() != '\n'); // Clear input buffer
                
                if (strcmp(sourceID, "Deposit") == 0) {
                    char destID[12];
                    printf("Please enter the customer ID to deposit to: ");
                    scanf("%11s", destID);
                    while (getchar() != '\n'); // Clear input buffer
                    CustomerInformation *destCustomer = getByID(customerList, destID);
                    
                    if (destCustomer == NULL) {
                        printf("\nCustomer not found\n");
                        break;
                    }
                    
                    double depositAmount;
                    printf("Please enter the amount to deposit: ");
                    if (scanf("%lf", &depositAmount) != 1) {
                        printf("Invalid input for deposit amount.\n");
                        while (getchar() != '\n'); // Clear input buffer
                        break;
                    }
                    while (getchar() != '\n'); // Clear input buffer
                    
                    destCustomer->customerBalance += depositAmount;
                    printf("Deposit successful. New balance: %.2f\n", destCustomer->customerBalance);
                } else {
                    CustomerInformation *sourceCustomer = getByID(customerList, sourceID);
                    if (sourceCustomer == NULL) {
                        printf("\nSource customer not found\n");
                        break;
                    }
                    
                    char destID[12];
                    printf("Please enter the destination customer ID: ");
                    scanf("%11s", destID);
                    while (getchar() != '\n'); // Clear input buffer
                    CustomerInformation *destCustomer = getByID(customerList, destID);
                    
                    if (destCustomer == NULL) {
                        printf("\nDestination customer not found\n");
                        break;
                    }
                    
                    double transferAmount;
                    printf("Please enter the amount to transfer: ");
                    if (scanf("%lf", &transferAmount) != 1) {
                        printf("Invalid input for transfer amount.\n");
                        while (getchar() != '\n'); // Clear input buffer
                        break;
                    }
                    while (getchar() != '\n'); // Clear input buffer
                    
                    if (transferAmount > sourceCustomer->customerBalance) {
                        printf("Insufficient funds for transfer.\n");
                    } else {
                        sourceCustomer->customerBalance -= transferAmount;
                        destCustomer->customerBalance += transferAmount;
                        printf("Transfer successful.\n");
                        printf("Source customer new balance: %.2f\n", sourceCustomer->customerBalance);
                        printf("Destination customer new balance: %.2f\n", destCustomer->customerBalance);
                    }
                }
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    
    list_destroy(customerList);
    return 0;
}