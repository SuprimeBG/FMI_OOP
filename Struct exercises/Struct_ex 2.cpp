#include <iostream>

struct Student {
    char name[128];
    char surname[128];
    char EGN[10];
};

struct University {
    char name[128];
    Student students[100];
    unsigned short numStudents;

    bool hasStudent(Student student) {
        for (unsigned short i = 0; i < numStudents; i++) {
            if (strcmp(students[i].EGN, student.EGN) == 0) {
                return true;
            }
        }
        return false;
    }

    void addStudent(Student student) {
        if (!hasStudent(student) && numStudents < 101) {
            students[numStudents] = student;
            numStudents++;
        }
    }
};

int main()
{
    return 0;
}

