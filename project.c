#include <stdio.h>
#include <stdlib.h>  // Required for exit()
#include <string.h>

struct patient {
    char name[100];
    int age;
    char gender[10];
};

struct doctor {
    int id;
    char name[50];
    char specialization[50];
    char contact[15];
    char availability[20];
};

// Function to add a patient
void addpatient() {
    struct patient p1;
    
    printf("\t\t\t\t\t************************************************\n");
    printf("\t\t\t\t\t**          HOSPITAL MANAGEMENT SYSTEM       **\n");
    printf("\t\t\t\t\t************************************************\n");
    
    printf("Enter your name: ");
    scanf(" %[^\n]", p1.name); 
    
    printf("Enter your age: ");
    scanf("%d", &p1.age); 

    printf("Enter gender (male/female): ");
    scanf("%s", p1.gender);
    
    if (p1.gender[0] == 'm' || p1.gender[0] == 'M')
        printf("Welcome Mr. %s\n", p1.name);
    else if (p1.gender[0] == 'f' || p1.gender[0] == 'F')
        printf("Welcome Miss. %s\n", p1.name);
    else
        printf("Invalid Key press (m for male, f for female)\n");
    
    printf("\n**************************\n");
}

// Placeholder functions (implement these as needed)
void viewPatients() {
	
    printf("Function to view patients (Not implemented yet).\n");
}

void addDoctor() {
    printf("Function to add doctor (Not implemented yet).\n");
}

void viewDoctors() {
    printf("Function to view doctors (Not implemented yet).\n");
}

void scheduleAppointment() {
    printf("Function to schedule appointment (Not implemented yet).\n");
}

void generateBill() {
    printf("Function to generate bill (Not implemented yet).\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Add Doctor\n");
        printf("4. View Doctors\n");
        printf("5. Schedule Appointment\n");
        printf("6. Generate Bill\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addpatient();
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                addDoctor();
                break;
            case 4:
                viewDoctors();
                break;
            case 5:
                scheduleAppointment();
                break;
            case 6:
                generateBill();
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

