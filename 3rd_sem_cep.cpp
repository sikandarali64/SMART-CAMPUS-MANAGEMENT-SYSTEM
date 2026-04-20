#include <iostream>
#include <string>
using namespace std;

// Patient Node
class Patient {
public:
    int id;
    string name;
    string type; // Emergency or Routine
    Patient* next;
    Patient(int i, string n, string t) {
        id=i;
        name=n;
        type=t;
        next=NULL;
    }
};

// Hospital System
class Hospital {
private:
    Patient* head;
    Patient* tail;
    int patientCount;
public:
    Hospital() {
        head=NULL;
        tail=NULL;
        patientCount=0;
    }

    // Add patient (Emergency front, Routine back)
    void addPatient(string name,string type) {
        patientCount++;
        Patient* newPatient=new Patient(patientCount,name,type);
        if(head==NULL) {
            head=tail=newPatient;
        } else {
            if(type=="Emergency") {
                newPatient->next=head;
                head=newPatient;
            } else {
                tail->next=newPatient;
                tail=newPatient;
            }
        }
        cout<<type<<" patient added: "<<name<<" (ID: "<<patientCount<<")\n";
    }

    // Display all patients
    void displayPatients() {
        Patient* temp=head;
        cout<<"\nCurrent Patients in Hospital Queue:\n";
        cout<<"ID\tName\t\tType\n";
        while(temp!=NULL) {
            cout<<temp->id<<"\t"<<temp->name<<"\t\t"<<temp->type<<endl;
            temp=temp->next;
        }
    }

    // Discharge patient
    void dischargePatient(int id) {
        Patient* temp=head;
        Patient* prev=NULL;
        while(temp!=NULL && temp->id!=id) {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL) {
            cout<<"Patient ID not found!\n";
            return;
        }
        if(prev==NULL) head=temp->next;
        else prev->next=temp->next;
        if(temp==tail) tail=prev;
        cout<<"Patient discharged: "<<temp->name<<" (ID: "<<temp->id<<")\n";
        delete temp;
    }
};

int main() {
    Hospital hospital;
    int choice;
    string name,type;
    int id;
    do {
        cout<<"\n--- Smart Hospital Resource System ---\n";
        cout<<"1. Add Patient\n";
        cout<<"2. Display Patients\n";
        cout<<"3. Discharge Patient\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"Enter patient name: ";
                cin>>name;
                cout<<"Enter type (Emergency/Routine): ";
                cin>>type;
                hospital.addPatient(name,type);
                break;
            case 2:
                hospital.displayPatients();
                break;
            case 3:
                cout<<"Enter patient ID to discharge: ";
                cin>>id;
                hospital.dischargePatient(id);
                break;
            case 4:
                cout<<"System Closed.\n";
                break;
            default:
                cout<<"Invalid choice!\n";
        }
    } while(choice!=4);
    return 0;
}
