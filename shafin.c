#include<stdio.h>
#include<stdlib.h>

typedef struct result {
    int id;
    char name[30];
    float math_mark;
    float physics_mark;
    float chemistry_mark;
    int teacher_evaluation;
    struct result *next;
} result;

result *head = NULL, *temp = NULL, *newnode = NULL;
int password = 161122;

void create_node() {
    int pass;
    printf("Enter the password: ");
    scanf("%d", &pass);
    if (pass != password) {
        printf("SORRY! Not accessible for you\n");
        return;
    }
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        newnode = (result*)malloc(sizeof(result));
        printf("Enter student's ID: ");
        scanf("%d", &newnode->id);
        getchar();
        printf("Enter student's name: ");
        gets(newnode->name);
        printf("Enter student's math's number: ");
        scanf("%f", &newnode->math_mark);
        printf("Enter student's physics's number: ");
        scanf("%f", &newnode->physics_mark);
        printf("Enter student's chemistry's number: ");
        scanf("%f", &newnode->chemistry_mark);
        printf("Confirmation of teacher evaluation: ");
        scanf("%d", &newnode->teacher_evaluation);
        if (head == NULL)
            temp = head = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void add_node() {
    int pass;
    printf("Enter the password: ");
    scanf("%d", &pass);
    if (pass != password) {
        printf("SORRY! Not accessible for you\n");
        return;
    }
    newnode = (result*)malloc(sizeof(result));
    printf("Enter student's ID: ");
    scanf("%d", &newnode->id);
    getchar();
    printf("Enter student's name: ");
    gets(newnode->name);
    printf("Enter student's math's number: ");
    scanf("%f", &newnode->math_mark);
    printf("Enter student's physics's number: ");
    scanf("%f", &newnode->physics_mark);
    printf("Enter student's chemistry's number: ");
    scanf("%f", &newnode->chemistry_mark);
    printf("Confirmation of teacher evaluation: ");
    scanf("%d", &newnode->teacher_evaluation);
    newnode->next = head;
    head = newnode;
}

void delete_node() {
    if (head == NULL) {
        printf("There is no data of students\n");
        return;
    }
    int pass;
    printf("Enter the password: ");
    scanf("%d", &pass);
    if (pass != password) {
        printf("SORRY! Not accessible for you\n");
        return;
    }
    int student_id;
    printf("Enter the student's ID: ");
    scanf("%d", &student_id);
    temp = head;
    result* ptr;
    int c = 0;
    while (temp != NULL) {
        ptr = temp;
        if (temp->id == student_id) {
            c++;
            break;
        }
        temp = temp->next;
    }
    if (c == 0)
        printf("This student's ID is not found\n");
    ptr->next = temp->next;
    free(temp);
    temp = NULL;
}

void display_result() {
    if (head == NULL) {
        printf("There is no data of students\n");
        return;
    }
    int student_id;
    printf("Enter the student's ID: ");
    scanf("%d", &student_id);
    temp = head;
    int c = 0;
    while (temp != NULL) {
        if (temp->id == student_id) {
            c++;
            break;
        }
        temp = temp->next;
    }
    if (c == 0)
        printf("This student's ID is not found\n");
    if (temp->teacher_evaluation != 1) {
        printf("Sorry! Firstly, you have to complete teacher evaluation to see your result:\n");
        return;
    }
    printf("Student's name: %s\n", temp->name);
    printf("Math marks: %.2f\n", temp->math_mark);
    printf("Physics marks: %.2f\n", temp->physics_mark);
    printf("Chemistry marks: %.2f\n", temp->chemistry_mark);
}

int main() {
    printf("What you want to do:\n");
    printf("1. Create node of student's result\n");
    printf("2. Add new student's result\n");
    printf("3. Delete any student's result\n");
    printf("4. Gradesheet of a student\n");
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == -1)
            break;
        else if (choice == 1)
            create_node();
        else if (choice == 2)
            add_node();
        else if (choice == 3)
            delete_node();
        else if (choice == 4)
            display_result();
        else
            printf("Wrong input\n");
    }
    return 0;
}
