#include <Data.h>

// Function to save admin data to file
void saveAdmin(Admin* admin, int numAdmin) {
    FILE* file = fopen(ADMIN_FILE, "wb"); // Open file for writing in binary mode

    if (file == NULL) {
        printf("Error opening file %s for writing.\n", ADMIN_FILE);
        exit(1);
    }

    fwrite(&numAdmin, sizeof(int), 1, file); // Write the number of students

    fwrite(admin, sizeof(Admin), numAdmin, file); // Write student data

    fclose(file);
}

 
// Function to save student data to file
void saveStudents(Student* students, int numStudents) {
    FILE* file = fopen(STUDENT_FILE, "wb"); // Open file for writing in binary mode

    if (file == NULL) {
        printf("Error opening file %s for writing.\n", STUDENT_FILE);
        exit(1);
    }

    fwrite(&numStudents, sizeof(int), 1, file); // Write the number of students

    fwrite(students, sizeof(Student), numStudents, file); // Write student data

    fclose(file);
}


// Function to save student data to file
void saveFaculty(Faculty* faculty, int numFaculty) {
    FILE* file = fopen(FACULTY_FILE, "wb"); // Open file for writing in binary mode

    if (file == NULL) {
        printf("Error opening file %s for writing.\n", FACULTY_FILE);
        exit(1);
    }

    fwrite(&numFaculty, sizeof(int), 1, file); // Write the number of students

    fwrite(faculty, sizeof(Faculty), numFaculty, file); // Write student data

    fclose(file);
}



// Function to save student data to file
void saveCourse(Course* course, int numCourse) {
    FILE* file = fopen(COURSE_FILE, "wb"); // Open file for writing in binary mode

    if (file == NULL) {
        printf("Error opening file %s for writing.\n", COURSE_FILE);
        exit(1);
    }

    fwrite(&numCourse, sizeof(int), 1, file); // Write the number of students

    fwrite(course, sizeof(Course), numCourse, file); // Write student data

    fclose(file);
}