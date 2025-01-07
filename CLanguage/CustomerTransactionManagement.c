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
    char destTransactionID[11];
} Transaction;

typedef struct TransactionBlock {
    Transaction item[5];
    int transactionCount;
    struct TransactionBlock *next;
} TransactionBlock;

typedef struct {
    TransactionBlock *front;
} TransactionList;

TransactionList *transaction_list_create(void) {
    TransactionList *list = (TransactionList *)malloc(sizeof(TransactionList));
    list->front = NULL;
    return list;
}

void add_transaction_front(Transaction transaction, TransactionList *lst) {
    if (lst->front !=NULL && lst->front->transactionCount < 5) {
        lst->front->item[lst->front->transactionCount] = transaction;
        lst->front->transactionCount += 1;
    }
    else {
        TransactionBlock *newnode = (TransactionBlock *)malloc(sizeof(TransactionBlock));
        newnode->item[0] = transaction; // Assuming we add only one transaction per block for now
        newnode->transactionCount = 1; // Initialize the transaction count to 1
        newnode->next = lst->front;
        lst->front = newnode;
    }
}

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

void removeCustomer(llist *lst, char *customerID) {
    llnode *current = lst->front;
    llnode *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->item.customerID, customerID) == 0) {
            if (previous == NULL) {
                lst->front = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->item.secretPassword);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
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
        char *password = current->secretPassword;
        encryptPassword(inputPassword);
        if (strcmp(password, inputPassword) == 0) {
            return true;
        }
    }
    return false;
}
bool isUniqueID(llist *customerList, const char *id) {
    llnode *current = customerList->front;
    while (current != NULL) {
        if (strcmp(current->item.customerID, id) == 0) {
            return false;
        }
        current = current->next;
    }
    return true;
}

void generate_customer_id(llist *customerList, CustomerInformation *customer) {
    do {
        srand(time(NULL));
        for (int i = 0; i < 5; i++) {
            customer->customerID[i] = (rand() % 26) + 'A';
        }
        customer->customerID[5] = '-';
        for (int i = 6; i < 11; i++) {
            customer->customerID[i] = (rand() % 10) + '0';
        }
        customer->customerID[11] = '\0';

        printf("Customer ID: %s\n", customer->customerID);
    } while (!isUniqueID(customerList, customer->customerID));
}

void printBlock(TransactionBlock *block) {
    for (int i = 0; i < block->transactionCount; i++) {
        printf("Transaction %d\n", i + 1);
        printf("Source ID: %s\n", block->item[i].sourceTransactionID);
        printf("Destination ID: %s\n", block->item[i].destTransactionID);
        printf("Amount: %.2f\n", block->item[i].sentAmount);
    }
    printf("\n");
}

void printTransactionList(TransactionList *list) {
    TransactionBlock *current = list->front;
    int blockCount = 0;
    while (current != NULL) {
        printBlock(current);
        blockCount++;
        printf("Block %d\n", blockCount);
        current = current->next;
    }
}

int main() {
    llist *customerList = list_create();
    TransactionList *transactionList = transaction_list_create();

    int option = 0;

    while (option != 5) {
        printf("\nBank Menu\n\n");
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

                generate_customer_id(customerList, &customer);

                customer.customerBalance = 0.0; // Initialize customer balance

                add_back(customer, customerList); // Add transaction to list
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

                if (thisCustomer->customerBalance != 0) {
                    printf("Customer has a balance of %.2f. Cannot delete customer with a balance.\n", thisCustomer->customerBalance);
                    break;
                }

                char password[22];
                while (1) {
                    printf("Enter your password: ");
                    scanf("%21s", password);
                    while (getchar() != '\n'); // Clear input buffer
                    if(authenticate(customerList, customerIDCheck, password)){
                        printf("Customer successfully deleted\n");
                        removeCustomer(customerList, thisCustomer->customerID);
                        break;
                    } else {
                        printf("Incorrect password\n");
                        continue;
                    }
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
                Transaction transaction = {0};
                int transactionOption = 0;
                double depositAmount;
                printf("Choose the transaction type:\n\n 1 - Deposit\n 2 - Transfer\n");
                scanf("%d", &transactionOption);
                while (getchar() != '\n'); // Clear input buffer
                char destinationID[12];

                //Deposit

                if(transactionOption == 1){
                    printf("Please enter the customer ID to deposit to: ");
                    scanf("%11s", destinationID);
                    while (getchar() != '\n'); // Clear input buffer
                    CustomerInformation *destinationCustomer = getByID(customerList, destinationID);
                    
                    if (destinationCustomer == NULL) {
                        printf("\nCustomer not found\n");
                        break;
                    }

                    printf("Please enter the amount to deposit: ");
                    if (scanf("%lf", &depositAmount) != 1) {
                        printf("Invalid input for deposit amount.\n");
                        while (getchar() != '\n'); // Clear input buffer
                        break;
                    }

                    //Update balance and confirm transaction
                    destinationCustomer->customerBalance += depositAmount;
                    printf("Deposit successful. New balance: %.2f\n", destinationCustomer->customerBalance);

                    //Record transaction
                    strcpy(transaction.sourceTransactionID, "Deposit");
                    strcpy(transaction.destTransactionID, destinationCustomer->customerID);
                    transaction.sentAmount = depositAmount;
                    add_transaction_front(transaction, transactionList);
                }

                //Transfer

                if(transactionOption == 2){
                    char sourceID[12];
                    printf("Please enter the source customer ID or \"Sender\": ");
                    scanf("%11s", sourceID);
                    while (getchar() != '\n'); // Clear input buffer
                    CustomerInformation *sourceCustomer = getByID(customerList, sourceID);

                    if (sourceCustomer == NULL) {
                        printf("\nCustomer not found\n");
                        break;
                    }

                    printf("Please enter the customer ID to deposit to: ");
                    scanf("%11s", destinationID);
                    while (getchar() != '\n'); // Clear input buffer
                    CustomerInformation *destinationCustomer = getByID(customerList, destinationID);
                    
                    if (destinationCustomer == NULL) {
                        printf("\nCustomer not found\n");
                        break;
                    }

                    printf("Please enter the amount being sent: ");
                    if (scanf("%lf", &depositAmount) != 1) {
                        printf("Invalid input for deposit amount.\n");
                        while (getchar() != '\n'); // Clear input buffer
                        break;
                    }

                    //Update balances and confirm transaction
                    sourceCustomer->customerBalance -= depositAmount;
                    destinationCustomer->customerBalance += depositAmount;
                    printf("Transfer successful.\n");
                    printf("Source customer new balance: %.2f\n", sourceCustomer->customerBalance);
                    printf("Destination customer new balance: %.2f\n", destinationCustomer->customerBalance);

                    //Record transaction
                    strcpy(transaction.sourceTransactionID, sourceCustomer->customerID);
                    strcpy(transaction.destTransactionID, destinationCustomer->customerID);
                    transaction.sentAmount = depositAmount;
                    add_transaction_front(transaction, transactionList);
                }
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            case 6:
                printTransactionList(transactionList);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
       
    list_destroy(customerList);
    return 0;
}