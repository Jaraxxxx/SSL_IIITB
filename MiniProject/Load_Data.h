#include <Data.h>

// Function to load admin data from file
void loadAdmin(Admin** admin, int* numAdmin) {
    FILE* file = fopen(ADMIN_FILE, "rb"); // Open file for reading in binary mode

    if (file == NULL) {
        printf("Error opening file %s for reading.\n", ADMIN_FILE);
        exit(1);
    }

    fread(numAdmin, sizeof(int), 1, file); // Read the number of students

    *admin = (Admin*)malloc(*numAdmin * sizeof(Admin)); // Allocate memory for students

    if (*admin == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    fread(*admin, sizeof(Admin), *numAdmin, file); // Read student data

    fclose(file);
}


// Function to load student data from file
void loadStudents(Student** students, int* numStudents) {
    FILE* file = fopen(STUDENT_FILE, "rb"); // Open file for reading in binary mode

    if (file == NULL) {
        printf("Error opening file %s for reading.\n", STUDENT_FILE);
        exit(1);
    }

    fread(numStudents, sizeof(int), 1, file); // Read the number of students

    *students = (Student*)malloc(*numStudents * sizeof(Student)); // Allocate memory for students

    if (*students == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    fread(*students, sizeof(Student), *numStudents, file); // Read student data

    fclose(file);
}

// Function to load student data from file
void loadFaculty(Faculty** faculty, int* numFaculty) {
    FILE* file = fopen(FACULTY_FILE, "rb"); // Open file for reading in binary mode

    if (file == NULL) {
        printf("Error opening file %s for reading.\n", FACULTY_FILE);
        exit(1);
    }

    fread(numStudents, sizeof(int), 1, file); // Read the number of students

    *faculty = (Faculty*)malloc(*numFaculty * sizeof(Faculty)); // Allocate memory for students

    if (*faculty == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    fread(*faculty, sizeof(Faculty), *numFaculty, file); // Read student data

    fclose(file);
}

// Function to load student data from file
void loadCourse(Course** course, int* numCourse) {
    FILE* file = fopen(COURSE_FILE, "rb"); // Open file for reading in binary mode

    if (file == NULL) {
        printf("Error opening file %s for reading.\n", COURSE_FILE);
        exit(1);
    }

    fread(numStudents, sizeof(int), 1, file); // Read the number of students

    *course = (Course*)malloc(*numCourse * sizeof(Course)); // Allocate memory for students

    if (*course == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    fread(*course, sizeof(Course), *numCourse, file); // Read student data

    fclose(file);
}