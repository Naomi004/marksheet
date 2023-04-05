#include <stdio.h>
#include <string.h>

  typedef struct student{
    char reg[20];
    int marks[5];
}Student;
  
int main() {
    char password[20];
    int attempts = 3;
    
    Student students[100]; 
    int num_students;
    
    while (attempts > 0) {
        printf("Enter password: ");
        scanf("%s", password);
        if (strcmp(password, "Admin123") == 0) {
            printf("Login successful!\n");
            break;
        } else {
            attempts--;
            printf("Incorrect password. %d attempts remaining.\n", attempts);
        }
    }
    if (attempts == 0) {
        printf("Maximum login attempts reached. Exiting...\n");
        return 0;
    }

    int option;
    do {
        printf("\nCUK MARKSHEET SYSTEM\n");
        printf("----------------------\n");
        printf("1. Add marks\n");
        printf("2. View marks\n");
        printf("3. Quit\n");
        printf("Choose your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                

                printf("Enter the number of students: ");
                scanf("%d", &num_students);

                for (int i = 0; i < num_students; i++) {
                   
                    printf("Enter Registration number for student %d: ",i+1);
                    scanf("%s",students[i].reg);

                    for (int j = 0; j < 5; j++) {
                        int mark;
                        printf("Enter mark for unit %d: ", j+1);
                        scanf("%d", &students[i].marks[j]);
                        
                    }
            printf("Marks added successfully!!\n");
                }
            printf("\n");
                break;
            }
            case 2:
                // View marks
            printf("StudentNo\t\tUnit1\tUnit2\tUnit3\tUnit4\tUnit5\tTotal\tAverage\tGrade\n");
               for(int i = 0; i < num_students; i++){
                int total_marks = 0;
                float average_marks;
                char grade;
            
                   printf("%s\t",students[i].reg);
               
                   for(int j = 0; j < 5; j++){
                       printf("%d\t",students[i].marks[j]);
                      total_marks += students[i].marks[j];
                   }
            average_marks = (float) total_marks / 5;
            printf("%d\t%.2f\t", total_marks, average_marks);
            if(average_marks >= 70){
             printf("A");}
            else if(average_marks >= 60){
            printf("B");}
            else if(average_marks >= 50){
            printf("C");}
            else if(average_marks >= 40){
            printf("D");}
            else {
            printf("E");}
          printf("\n");
               }
                break;
            case 3:
                // Quit
               printf("Exiting...");
               exit(0);
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 3);
    return 0;
}

 
