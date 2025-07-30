#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aadhar 
{
  char name[50];
  char address[100];
  int aadharNumber;
  struct aadhar* next;
};

struct pan 
{
  char name[50];
  char address[100];
  int panNumber;
  int aadharNumber;
  struct pan* next;
};

struct Bank 
{
  int aadharNumber;  
  char name[50];
  char BankName[50];
  char address[100];
  int panNumber;
  int accountNumber;
  float balance;
  struct Bank* next;
};

struct lpg 
{
  char name[50];
  int aadharNumber;
  int accountNumber;
  char subsidyStatus[4];
  struct lpg* next;
};

int found(struct pan* P, int A)
{
    int ret_val=0;

    struct pan* ptr=P;
    while(ptr != NULL)
    {
        if(ptr->aadharNumber == A)
        {
            ret_val=1;
            break;
        }
        ptr=ptr->next;
    }
    
    return ret_val;
}

void aadharBUtnoPan(struct aadhar* A, struct pan* P)
{
    struct aadhar* ptr = A;
    while(ptr != NULL)
    {
        if(!found(P, ptr->aadharNumber))
        {
            printf("%s\t", ptr->name);
            printf("%s\t", ptr->address);
            printf("%d\n", ptr->aadharNumber);
        }
        ptr = ptr->next;
    }
}

int found_multiple_Bank_acc(struct Bank* B, int P)
{
    int count = 0;
    struct Bank* ptr = B;
    int ret_val = 0;

    while(ptr != NULL)
    {
        if(ptr->panNumber == P)
        {
            count++;
        }
        ptr = ptr->next;
    }

    if(count > 1)
    {
        ret_val = 1;
    }
    return ret_val;
}

void multiplePanNumbers(struct pan* head)
{
    struct pan* temp1 = head;
    struct pan* temp2;

    while(temp1 != NULL)
    {
        temp2 = head;
        int flag = 0;
        while(temp2 != NULL)
        {
            if(temp1 != temp2 && strcmp(temp1->name, temp2->name) == 0)
            {
                flag++;
                printf("Details of person with multiple PAN numbers is: \n");
                printf("Name of person: %s\n", temp1->name);
                printf("Address of %s is %s\n", temp1->name, temp1->address);
                printf("Aadhar number: %d\n", temp1->aadharNumber);
                printf("All multiple PAN numbers of %s are: \n", temp1->name);
                printf("%d %d\n", temp1->panNumber, temp2->panNumber);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void ThirdQuestion(struct pan* P, struct Bank* B)
{
    struct pan* ptr = P;

    while(ptr != NULL)
    {
        if(found_multiple_Bank_acc(B, ptr->panNumber))
        {
            printf("name : %s\n", ptr->name);
            printf("address : %s\n", ptr->address);
            printf("aadhar number : %d\n", ptr->aadharNumber);
        }
        ptr = ptr->next;
    }
}

float TotalAmount(struct Bank* ptr, struct Bank* Banklist)
{
    struct Bank* temp = Banklist;
    float amount = 0;

    while(temp != NULL)
    {
        if(ptr->aadharNumber == temp->aadharNumber)
        {
            amount += temp->balance;
        }
        temp = temp->next;
    }
    return amount;
}

int LPGstatus(struct lpg* lpg, struct Bank* Bank)
{
    struct lpg* ptrlpg = lpg;
    int ret_val = 0;

    while(ptrlpg != NULL)
    {
        if(ptrlpg->aadharNumber == Bank->aadharNumber)
        {
            ret_val = 1;
            break;
        }
        ptrlpg = ptrlpg->next;
    }
    return ret_val;
}

void lpg_subsidy(struct lpg* head1, struct pan* head2, struct Bank* head3)
{
    struct lpg* lpg_temp = head1;
    struct pan* pan_temp;
    struct Bank* bc_temp;

    while(lpg_temp != NULL)
    {
        if(strcmp(lpg_temp->subsidyStatus, "YES") == 0)
        {
            printf("Details of %s are: \n", lpg_temp->name);

            pan_temp = head2;
            while(pan_temp != NULL && strcmp(pan_temp->name, lpg_temp->name) != 0)
            {
                pan_temp = pan_temp->next;
            }

            if(pan_temp != NULL)
            {
                printf("aadhar number: %d\n", pan_temp->aadharNumber);
                printf("pan number: %d\n", pan_temp->panNumber);

                bc_temp = head3;
                while(bc_temp != NULL && strcmp(bc_temp->name, lpg_temp->name) != 0)
                {
                    bc_temp = bc_temp->next;
                }

                if(bc_temp != NULL)
                {
                    printf("Bank name: %s\n", bc_temp->BankName);
                    printf("Bank account number: %d\n", bc_temp->accountNumber);
                    printf("Bank balance: %.2f\n", bc_temp->balance);
                }
            }
        }
        else 
        {
            printf("%s has not availed any subsidy\n", lpg_temp->name);
        }
        lpg_temp = lpg_temp->next;
    }
}

void localSavingandLPG(int amount, struct Bank* Banklist, struct lpg* lpglist)
{
    struct Bank* ptr = Banklist;
    float temp;

    while(ptr != NULL)
    {
        temp = TotalAmount(ptr, Banklist);

        if(temp > amount && LPGstatus(lpglist, ptr))
        {
            printf("name : %s\n", ptr->name);
            printf("address : %s\n", ptr->address);
            printf("aadhar number : %d\n", ptr->aadharNumber);   
        }
        ptr = ptr->next;
    }
}

void deleteNode(struct Bank** head_ref, struct Bank* node)
{
    if (*head_ref == NULL || node == NULL)
        return;

    if (*head_ref == node)
        *head_ref = node->next;

    struct Bank* temp = *head_ref;
    while (temp != NULL && temp->next != node)
    {
        temp = temp->next;
    }

    if (temp != NULL && temp->next == node)
    {
        temp->next = node->next;
    }

    free(node);
}

void inconsistentData(struct aadhar* head1, struct pan* head2, struct Bank* head3, struct lpg* head4)
{
    struct aadhar* temp1 = head1;
    struct aadhar* temp2;

    while(temp1 != NULL)
    {
        temp2 = head1;
        while(temp2 != NULL)
        {
            if(temp1 != temp2 && strcmp(temp1->name, temp2->name) == 0)
            {
                printf("Inconsistency found in aadhar: %s\n", temp1->name);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    struct pan* temp3 = head2;
    struct pan* temp4;

    while(temp3 != NULL)
    {
        temp4 = head2;
        while(temp4 != NULL)
        {
            if(temp3 != temp4 && strcmp(temp3->name, temp4->name) == 0)
            {
                printf("Inconsistency found in pan: %s\n", temp3->name);
            }
            temp4 = temp4->next;
        }
        temp3 = temp3->next;
    }

    struct Bank* temp5 = head3;
    struct Bank* temp6;

    while(temp5 != NULL)
    {
        temp6 = head3;
        while(temp6 != NULL)
        {
            if(temp5 != temp6 && strcmp(temp5->name, temp6->name) == 0)
            {
                printf("Inconsistency found in Bank: %s\n", temp5->name);
            }
            temp6 = temp6->next;
        }
        temp5 = temp5->next;
    }

    struct lpg* temp7 = head4;
    struct lpg* temp8;

    while(temp7 != NULL)
    {
        temp8 = head4;
        while(temp8 != NULL)
        {
            if(temp7 != temp8 && strcmp(temp7->name, temp8->name) == 0)
            {
                printf("Inconsistency found in lpg: %s\n", temp7->name);
            }
            temp8 = temp8->next;
        }
        temp7 = temp7->next;
    }
}

void mergeList(struct aadhar* head1, struct pan* head2, struct Bank* head3)
{
    struct aadhar* aadhar_temp = head1;
    struct pan* pan_temp = head2;
    struct Bank* bank_temp = head3;

    while(aadhar_temp != NULL)
    {
        while(pan_temp != NULL)
        {
            if(aadhar_temp->aadharNumber == pan_temp->aadharNumber)
            {
                while(bank_temp != NULL)
                {
                    if(bank_temp->aadharNumber == aadhar_temp->aadharNumber)
                    {
                        printf("Aadhar number: %d\n", aadhar_temp->aadharNumber);
                        printf("PAN number: %d\n", pan_temp->panNumber);
                        printf("Bank account number: %d\n", bank_temp->accountNumber);
                        printf("Balance: %.2f\n", bank_temp->balance);
                    }
                    bank_temp = bank_temp->next;
                }
            }
            pan_temp = pan_temp->next;
        }
        aadhar_temp = aadhar_temp->next;
    }
}

void displayMenu() {
    printf("Choose an option:\n");
    printf("1. Display Aadhar details but no PAN\n");
    printf("2. Display multiple PAN numbers\n");
    printf("3. Display multiple bank accounts with same PAN number\n");
    printf("4. Display people with local savings more than given amount and LPG connection\n");
    printf("5. Display LPG subsidy details\n");
    printf("6. Display inconsistent data\n");
    printf("7. Merge and display linked lists\n");
    printf("0. Exit\n");
}

int main()
{
    struct aadhar* head1 = NULL;
    struct pan* head2 = NULL;
    struct Bank* head3 = NULL;
    struct lpg* head4 = NULL;

    // Hardcode data for Aadhar
    struct aadhar* a1 = (struct aadhar*)malloc(sizeof(struct aadhar));
    strcpy(a1->name, "John Doe");
    strcpy(a1->address, "123 Elm Street");
    a1->aadharNumber = 1111;
    a1->next = NULL;
    head1 = a1;

    struct aadhar* a2 = (struct aadhar*)malloc(sizeof(struct aadhar));
    strcpy(a2->name, "Jane Doe");
    strcpy(a2->address, "456 Oak Street");
    a2->aadharNumber = 2222;
    a2->next = NULL;
    a1->next = a2;

    // Hardcode data for PAN
    struct pan* p1 = (struct pan*)malloc(sizeof(struct pan));
    strcpy(p1->name, "John Doe");
    strcpy(p1->address, "123 Elm Street");
    p1->panNumber = 5555;
    p1->aadharNumber = 1111;
    p1->next = NULL;
    head2 = p1;

    struct pan* p2 = (struct pan*)malloc(sizeof(struct pan));
    strcpy(p2->name, "Jane Doe");
    strcpy(p2->address, "456 Oak Street");
    p2->panNumber = 6666;
    p2->aadharNumber = 2222;
    p2->next = NULL;
    p1->next = p2;

    // Hardcode data for Bank
    struct Bank* b1 = (struct Bank*)malloc(sizeof(struct Bank));
    strcpy(b1->name, "John Doe");
    strcpy(b1->BankName, "Bank A");
    strcpy(b1->address, "123 Elm Street");
    b1->panNumber = 5555;
    b1->accountNumber = 12345;
    b1->balance = 15000.00;
    b1->aadharNumber = 1111;
    b1->next = NULL;
    head3 = b1;

    struct Bank* b2 = (struct Bank*)malloc(sizeof(struct Bank));
    strcpy(b2->name, "Jane Doe");
    strcpy(b2->BankName, "Bank B");
    strcpy(b2->address, "456 Oak Street");
    b2->panNumber = 6666;
    b2->accountNumber = 67890;
    b2->balance = 25000.00;
    b2->aadharNumber = 2222;
    b2->next = NULL;
    b1->next = b2;

    // Hardcode data for LPG
    struct lpg* l1 = (struct lpg*)malloc(sizeof(struct lpg));
    strcpy(l1->name, "John Doe");
    l1->aadharNumber = 1111;
    l1->accountNumber = 12345;
    strcpy(l1->subsidyStatus, "YES");
    l1->next = NULL;
    head4 = l1;

    struct lpg* l2 = (struct lpg*)malloc(sizeof(struct lpg));
    strcpy(l2->name, "Jane Doe");
    l2->aadharNumber = 2222;
    l2->accountNumber = 67890;
    strcpy(l2->subsidyStatus, "NO");
    l2->next = NULL;
    l1->next = l2;

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                aadharBUtnoPan(head1, head2);
                break;
            case 2:
                multiplePanNumbers(head2);
                break;
            case 3:
                ThirdQuestion(head2, head3);
                break;
            case 4:
                localSavingandLPG(10000, head3, head4);
                break;
            case 5:
                lpg_subsidy(head4, head2, head3);
                break;
            case 6:
                inconsistentData(head1, head2, head3, head4);
                break;
            case 7:
                mergeList(head1, head2, head3);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    } while(choice != 0);

    return 0;
}
