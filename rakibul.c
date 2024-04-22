#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_TEACHER_NUMBER_LENGTH 15
#define MAX_EMAIL_LENGTH 50

// Data structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    int credits;
} Course;

typedef struct {
    Course *courses;
    int numCourses;
} Batch;

typedef struct {
    char name[MAX_NAME_LENGTH];
    char teacher[MAX_NAME_LENGTH];
    char teacherNumber[MAX_TEACHER_NUMBER_LENGTH];
    char teacherEmail[MAX_EMAIL_LENGTH];
    char classroom[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];
} CourseRoutine;

// Function prototypes
int signIn();
void addCourse(Batch *batch);
void deleteCourse(Batch *batch);
void modifyCourse(Batch *batch);
void showCourses(Batch *batch);
void addCourseRoutine(Batch *batches, int batchNum);
void showCourseRoutine(Batch *batches, int batchNum);

int main() {
    Batch *batches = NULL;
    int numBatches = 0;
    int choice, batchNum;
    printf("Welcome to our project!!\n");
    printf("Note: [This whole project's source code little bit modified by chatgpt for better visualization and understanding]\n");
    printf("Welcome to our university!\n");
    printf("Please select your status:\n");
    printf("1. Faculty\n");
    printf("2. Student\n");
    printf("3. Visitor\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            if (signIn()) {
                do {
                    printf("\nEnter the batch number or 0 to exit: ");
                    scanf("%d", &batchNum);
                    if (batchNum == 0) {
                        break;
                    }
                    if (batchNum >= 1 && batchNum <= numBatches + 1) {
                        if (batchNum > numBatches) {
                            batches = realloc(batches, (batchNum) * sizeof(Batch));
                            if (batches == NULL) {
                                printf("Memory allocation failed.\n");
                                exit(EXIT_FAILURE);
                            }
                            for (int i = numBatches; i < batchNum; i++) {
                                batches[i].numCourses = 0;
                                batches[i].courses = NULL;
                            }
                            numBatches = batchNum;
                        }
                        batchNum--; // Adjusting for zero-based indexing
                        printf("\nBatch %d selected.\n", batchNum + 1);
                        if (batches[batchNum].numCourses == 0) {
                            printf("No courses added to this batch. Please add courses.\n");
                            addCourse(&batches[batchNum]);
                        } else {
                            showCourses(&batches[batchNum]);
                            printf("\n1. Add Course\n");
                            printf("2. Delete Course\n");
                            printf("3. Modify Course\n");
                            printf("4. Add Course Routine\n");
                            printf("5. Show Course Routine\n");
                            printf("6. Exit\n");
                            printf("Enter your choice: ");
                            scanf("%d", &choice);
                            switch (choice) {
                                case 1:
                                    addCourse(&batches[batchNum]);
                                    break;
                                case 2:
                                    deleteCourse(&batches[batchNum]);
                                    break;
                                case 3:
                                    modifyCourse(&batches[batchNum]);
                                    break;
                                case 4:
                                    addCourseRoutine(batches, batchNum);
                                    break;
                                case 5:
                                    showCourseRoutine(batches, batchNum);
                                    break;
                                case 6:
                                    break;
                                default:
                                    printf("Invalid choice!\n");
                            }
                        }
                    } else {
                        printf("Invalid batch number!\n");
                    }
                } while (1);
            }
            break;
        }
        case 2:
            printf("Welcome, Student!\n");
            // Add student-specific actions here
            break;
        case 3:
            printf("Welcome, Visitor!\n");
            // Add visitor-specific actions here
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

// Function to simulate faculty sign-in
int signIn() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("\nPlease sign in to continue:\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Dummy authentication (replace with actual authentication logic)
    if (strcmp(username, "faculty") == 0 && strcmp(password, "123") == 0) {
        printf("Sign-in successful!\n");
        return 1; // Sign-in successful
    } else {
        printf("Invalid username or password!\n");
        return 0; // Sign-in failed
    }
}

// Function to add a course for a specific batch
void addCourse(Batch *batch) {
    batch->numCourses++;
    batch->courses = realloc(batch->courses, batch->numCourses * sizeof(Course));
    if (batch->courses == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    Course *newCourse = &batch->courses[batch->numCourses - 1];
    printf("\nEnter the name of the course: ");
    scanf("%s", newCourse->name);
    printf("Enter the credits of the course: ");
    scanf("%d", &newCourse->credits);
    printf("Course added successfully.\n");
}

// Function to delete a course for a specific batch
void deleteCourse(Batch *batch) {
    if (batch->numCourses > 0) {
        int courseIndex;
        printf("\nEnter the index of the course to delete (1-%d): ", batch->numCourses);
        scanf("%d", &courseIndex);
        if (courseIndex >= 1 && courseIndex <= batch->numCourses) {
            for (int i = courseIndex - 1; i < batch->numCourses - 1; i++) {
                batch->courses[i] = batch->courses[i + 1];
            }
            batch->numCourses--;
            batch->courses = realloc(batch->courses, batch->numCourses * sizeof(Course));
            printf("Course deleted successfully.\n");
        } else {
            printf("Invalid course index.\n");
        }
    } else {
        printf("No courses to delete.\n");
    }
}

// Function to modify a course for a specific batch
void modifyCourse(Batch *batch) {
    if (batch->numCourses > 0) {
        int courseIndex;
        printf("\nEnter the index of the course to modify (1-%d): ", batch->numCourses);
        scanf("%d", &courseIndex);
        if (courseIndex >= 1 && courseIndex <= batch->numCourses) {
            Course *selectedCourse = &batch->courses[courseIndex - 1];
            printf("Enter the new name of the course: ");
            scanf("%s", selectedCourse->name);
            printf("Enter the new credits of the course: ");
            scanf("%d", &selectedCourse->credits);
            printf("Course modified successfully.\n");
        } else {
            printf("Invalid course index.\n");
        }
    } else {
        printf("No courses to modify.\n");
    }
}

// Function to show courses for a specific batch
void showCourses(Batch *batch) {
    printf("Courses in this batch:\n");
    for (int i = 0; i < batch->numCourses; i++) {
        printf("%d. %s (Credits: %d)\n", i + 1, batch->courses[i].name, batch->courses[i].credits);
    }
}

// Function to add a course routine for a specific batch
void addCourseRoutine(Batch *batches, int batchNum) {
    CourseRoutine routine;
    printf("\nEnter the name of the course: ");
    scanf("%s", routine.name);
    printf("Enter the teacher's name: ");
    scanf("%s", routine.teacher);
    printf("Enter the teacher's number: ");
    scanf("%s", routine.teacherNumber);
    printf("Enter the teacher's email: ");
    scanf("%s", routine.teacherEmail);
    printf("Enter the classroom: ");
    scanf("%s", routine.classroom);
    printf("Enter the time: ");
    scanf("%s", routine.time);
    // You can save this routine to a data structure or print it as per your requirements
    printf("Course routine added successfully.\n");
}

// Function to show course routine for a specific batch
void showCourseRoutine(Batch *batches, int batchNum) {
    printf("Course routine for this batch:\n");
    // Check if routine exists
    if (batches[batchNum].numCourses == 0) {
        printf("No routine found for this batch.\n");
        // Automatically add a routine
        addCourseRoutine(batches, batchNum);
    } else {
        // Show existing routine
        for (int i = 0; i < batches[batchNum].numCourses; i++) {
            Course *course = &batches[batchNum].courses[i];
            printf("Course: %s\n", course->name);
            // You can display the routine here if you have saved it to a data structure
        }
    }
}