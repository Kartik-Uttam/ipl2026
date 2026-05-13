#include <stdio.h>

struct Student {
    int roll;
    char name[30];
    float marks;
};

void storeStudents(FILE *fp, struct Student s[], long pos[]) {
    int i;

    for (i = 0; i < 3; i++) {
        pos[i] = ftell(fp);

        printf("Enter roll, name and marks: ");
        scanf("%d %s %f", &s[i].roll, s[i].name, &s[i].marks);

        fprintf(fp, "%d %s %.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

void displayRecord(FILE *fp, long pos) {
    struct Student s;

    fseek(fp, pos, SEEK_SET);

    fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks);

    printf("\nRecord Details:\n");
    printf("Roll No = %d\n", s.roll);
    printf("Name = %s\n", s.name);
    printf("Marks = %.2f\n", s.marks);
}

int main() {
    struct Student s[3];
    long pos[3];
    FILE *fp;
    int i, choice;

    fp = fopen("student.txt", "w+");

    if (fp == NULL) {
        printf("File not opened");
        return 1;
    }

    storeStudents(fp, s, pos);

    printf("\nSeek Positions:\n");
    for (i = 0; i < 3; i++) {
        printf("Record %d starts at %ld\n", i + 1, pos[i]);
    }

    printf("\nEnter record number to display: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3) {
        displayRecord(fp, pos[choice - 1]);
    } else {
        printf("Invalid record number");
    }

    fclose(fp);

    return 0;
}