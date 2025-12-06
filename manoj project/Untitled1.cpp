#include <stdio.h>
#include <string.h>

#define MAX 50

// Student Structure
typedef struct {
    int id;
    char name[50];
    int age;
    float marks;
} Student;

Student S[MAX];
int total = 0;

//------------------------------------------------------
// UI HEADER PRINT
//------------------------------------------------------
void title(const char *text) {
    printf("\n================== %s ==================\n", text);
}

//------------------------------------------------------
// ADMIN FUNCTIONS
//------------------------------------------------------
void admin_add() {
    title("ADD STUDENT");
    printf("ID     : "); scanf("%d", &S[total].id);
    printf("Name   : "); scanf("%s", S[total].name);
    printf("Age    : "); scanf("%d", &S[total].age);
    printf("Marks  : "); scanf("%f", &S[total].marks);
    total++;
    printf("? Student Added Successfully!\n");
}

void admin_show() {
    title("ALL STUDENTS");
    if(total == 0) {
        printf("No records found.\n");
        return;
    }
    for(int i = 0; i < total; i++) {
        printf("[%d] %s  | Age: %d | Marks: %.2f\n",
               S[i].id, S[i].name, S[i].age, S[i].marks);
    }
}

void admin_edit() {
    title("UPDATE STUDENT");
    int id, found = -1;
    printf("Enter ID: "); 
    scanf("%d", &id);

    for(int i = 0; i < total; i++)
        if(S[i].id == id) found = i;

    if(found == -1) {
        printf("? Student Not Found!\n");
        return;
    }

    printf("New Name  : "); scanf("%s", S[found].name);
    printf("New Age   : "); scanf("%d", &S[found].age);
    printf("New Marks : "); scanf("%f", &S[found].marks);

    printf("? Updated Successfully!\n");
}

void admin_delete() {
    title("DELETE STUDENT");
    int id, index = -1;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < total; i++)
        if(S[i].id == id) index = i;

    if(index == -1) {
        printf("? Student Not Found!\n");
        return;
    }

    for(int i = index; i < total - 1; i++)
        S[i] = S[i + 1];

    total--;
    printf("? Deleted Successfully!\n");
}

void admin_search() {
    title("SEARCH STUDENT");
    int id, found = -1;

    printf("Enter ID: ");
    scanf("%d", &id);

    for(int i = 0; i < total; i++)
        if(S[i].id == id) found = i;

    if(found == -1) {
        printf("? No Student Found!\n");
        return;
    }

    printf("FOUND ? %d | %s | Age %d | Marks %.2f\n",
           S[found].id, S[found].name, S[found].age, S[found].marks);
}

//------------------------------------------------------
// STAFF MENU (Limited Access)
//------------------------------------------------------
void staff_menu() {
    int c;
    do {
        title("STAFF MENU");
        printf("1. Display Students\n");
        printf("2. Update Student\n");
        printf("3. Search Student\n");
        printf("0. Return to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &c);

        switch(c) {
            case 1: admin_show(); break;
            case 2: admin_edit(); break;
            case 3: admin_search(); break;
            case 0: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid Option!\n");
        }

    } while(c != 0);
}

//------------------------------------------------------
// GUEST MENU (View Only)
//------------------------------------------------------
void guest_menu() {
    int c;
    do {
        title("GUEST MENU");
        printf("1. Display Students\n");
        printf("2. Search Student\n");
        printf("0. Return to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &c);

        switch(c) {
            case 1: admin_show(); break;
            case 2: admin_search(); break;
            case 0: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid Option!\n");
        }

    } while(c != 0);
}

//------------------------------------------------------
// USER PROFILE (Static Info)
//------------------------------------------------------
void user_menu() {
    title("USER PROFILE");
    printf("Name : GuestUser\n");
    printf("Role : Student\n");
    printf("Access : Display Only\n");
    printf("Returning to Main Menu...\n");
}

//------------------------------------------------------
// ADMIN MENU (Full CRUD)
//------------------------------------------------------
void admin_menu() {
    int c;
    do {
        title("ADMIN MENU");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Search Student\n");
        printf("0. Return to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &c);

        switch(c) {
            case 1: admin_add(); break;
            case 2: admin_show(); break;
            case 3: admin_edit(); break;
            case 4: admin_delete(); break;
            case 5: admin_search(); break;
            case 0: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid Option!\n");
        }

    } while(c != 0);
}

//------------------------------------------------------
// 7.10 MAIN MENU  (ADDED AS REQUESTED)
//------------------------------------------------------
void main_menu() {
    int role;

    do {
        title("MAIN MENU - ROLE SELECTION");
        printf("1. Admin\n");
        printf("2. Staff\n");
        printf("3. Guest\n");
        printf("4. User Profile\n");
        printf("0. Exit Application\n");
        printf("Enter role: ");
        scanf("%d", &role);

        switch(role) {
            case 1: admin_menu(); break;
            case 2: staff_menu(); break;
            case 3: guest_menu(); break;
            case 4: user_menu(); break;
            case 0: printf("Exiting Program...\n"); break;
            default: printf("Invalid Role Selected!\n");
        }

    } while(role != 0);
}

//------------------------------------------------------
// MAIN FUNCTION (Login + redirect to MAIN MENU)
//------------------------------------------------------
int main() {
    char user[20], pass[20];

    title("LOGIN");
    printf("Username: "); scanf("%s", user);
    printf("Password: "); scanf("%s", pass);

    main_menu();   // Now everything runs from here

    return 0;
}
