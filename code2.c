#include <stdio.h>

struct Student {
    int enrollment;
    char name[50];
    float marks1, marks2, marks3;
};

struct Student s[50];
int count = 0;

//function for adding student 
void addStudent() {
    if (count >= 50) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter Enrollment Number: ");
    scanf("%d", &s[count].enrollment);

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s[count].name);

    printf("Enter marks in 3 subjects: ");
    scanf("%f %f %f", &s[count].marks1,&s[count].marks2,&s[count].marks3);

    count++;
    printf("Student added successfully!\n");
}

//function for displaying the students name
void displayStudents() {
    int i;

    if (count == 0) {
        printf("No student records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    for (i = 0; i < count; i++) {
        printf("\nEnrollment Number: %d\n", s[i].enrollment);
        printf("Name: %s\n", s[i].name);
        printf("Subject 1: %.2f\n", s[i].marks1);
        printf("Subject 2: %.2f\n", s[i].marks2);
        printf("Subject 3: %.2f\n", s[i].marks3);

        printf("Total Marks: %.2f\n",
               s[i].marks1 + s[i].marks2 + s[i].marks3);

        printf("Percentage: %.2f%%\n",
               (s[i].marks1 + s[i].marks2 + s[i].marks3) / 3);
    }
}

//function for searching student 
void searchStudent() {
    int enrollment, i;

    printf("Enter Enrollment Number to search: ");
    scanf("%d", &enrollment);

    for (i = 0; i < count; i++) {
        if (s[i].enrollment == enrollment) {
            printf("Student Found!\n");
            printf("Name: %s\n", s[i].name);
            printf("Total Marks: %.2f\n",
                   s[i].marks1 + s[i].marks2 + s[i].marks3);
            return;
        }
    }

    printf("Student not found!\n");
}

void updateStudent() {
    int enrollment, i;

    printf("Enter Enrollment Number to update: ");
    scanf("%d", &enrollment);

    for (i = 0; i < count; i++) {
        if (s[i].enrollment == enrollment) {
            printf("Enter New Name: ");
            scanf(" %49[^\n]", s[i].name);

            printf("Enter New Marks in 3 subjects: ");
            scanf("%f %f %f",
                  &s[i].marks1,
                  &s[i].marks2,
                  &s[i].marks3);

            printf("Record updated successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

void deleteStudent() {
    int enrollment, i, j;

    printf("Enter Enrollment Number to delete: ");
    scanf("%d", &enrollment);

    for (i = 0; i < count; i++) {
        if (s[i].enrollment == enrollment) {
            for (j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }

            count--;
            printf("Student deleted successfully!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

void rankStudents() {
    int i, j;
    struct Student temp;

    if (count == 0) {
        printf("No student records found!\n");
        return;
    }

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            float total1 = s[j].marks1 + s[j].marks2 + s[j].marks3;
            float total2 = s[j + 1].marks1 +
                           s[j + 1].marks2 + s[j + 1].marks3;

            if (total1 < total2) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\n--- Student Ranking ---\n");

    for (i = 0; i < count; i++) {
        printf("Rank %d: %s | Total Marks: %.2f\n",
               i + 1, s[i].name,
               s[i].marks1 + s[i].marks2 + s[i].marks3);
    }
}

int main() {
    int choice;

    do {
        printf("\n===== STUDENT RECORD MANAGEMENT =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Rank Students\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: rankStudents(); break;
            case 7: printf("Program ended.\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}