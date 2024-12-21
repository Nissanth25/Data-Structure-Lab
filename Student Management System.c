
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[25];
    int id;
    char grade;
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int count;
} StudentGradeManagementSystem;

void initialize_list(StudentGradeManagementSystem *system) {
    system->count = 0;
}

// Add a new student to the list
void add_student(StudentGradeManagementSystem *system, char *name, int id, char grade) {
    if (system->count < MAX_STUDENTS) {
        strcpy(system->students[system->count].name, name);
        system->students[system->count].id = id;
        system->students[system->count].grade = grade;
        system->count++;
    } else {
        printf("Error: The list is full.\n");
    }
}

// Remove a student from the list by their Student ID
void remove_student(StudentGradeManagementSystem *system, int id) {
    int found = 0;
    for (int i = 0; i < system->count; i++) {
        if (system->students[i].id == id) {
            found = 1;
            for (int j = i; j < system->count - 1; j++) {
                system->students[j] = system->students[j + 1];
            }
            system->count--;
            break;
        }
    }
    if (!found) {
        printf("Student ID %d not found in the list.\n", id);
    }
}

// Update the grade of a student by their Student ID
void update_grade(StudentGradeManagementSystem *system, int id, char grade) {
    int found = 0;
    for (int i = 0; i < system->count; i++) {
        if (system->students[i].id == id) {
            system->students[i].grade = grade;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student ID %d not found in the list.\n", id);
    }
}

// Display all students in the list
void display_all_students(StudentGradeManagementSystem *system) {
    printf("List of Students:\n");
    printf("Name\tStudent ID\tGrade\n");
    for (int i = 0; i < system->count; i++) {
        printf("%s\t%d\t\t%c\n", system->students[i].name, system->students[i].id, system->students[i].grade);
    }
}

// Main function to demonstrate the operations
int main() {
    StudentGradeManagementSystem system;
    initialize_list(&system);

    int option;
    char name[25];
    int id;
    char grade;

    while (1) {
        printf("\nStudent Grade Management System\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Update Grade\n");
        printf("4. Display All Students\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter student ID: ");
                scanf("%d", &id);
                printf("Enter grade: ");
                scanf(" %c", &grade);
                add_student(&system, name, id, grade);
                break;
            case 2:
                printf("Enter student ID to remove: ");
                scanf("%d", &id);
                remove_student(&system, id);
                break;
            case 3:
                printf("Enter student ID to update grade: ");
                scanf("%d", &id);
                printf("Enter new grade: ");
                scanf(" %c", &grade);
                update_grade(&system, id, grade);
                break;
            case 4:
                display_all_students(&system);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}



OUTPUT:
      Student Grade Management System
1. Add Student
2. Remove Student
3. Update Grade
4. Display All Students
5. Quit
Enter your choice: 1
Enter student name: Alice
Enter student ID: 102
Enter grade: B


Student Grade Management System
1. Add Student
2. Remove Student
3. Update Grade
4. Display All Students
5. Quit
Enter your choice: 3
Enter student ID to update grade: 101
Enter new grade: A+


Student Grade Management System
1. Add Student
2. Remove Student
3. Update Grade
4. Display All Students
5. Quit
Enter your choice: 2
Enter student ID to remove: 102

Student Grade Management System
1. Add Student
2. Remove Student
3. Update Grade
4. Display All Students
5. Quit
Enter your choice: 4
List of Students:
Name    Student ID  Grade
John    101         A+

Student Grade Management System
1. Add Student
2. Remove Student
3. Update Grade
4. Display All Students
5. Quit
Enter your choice: 5
