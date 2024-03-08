#include <iostream>
#include <fstream> 
#include <vector> 

using namespace std;

// Structure to store student details
struct Student {
    string admissionNumber;
    string name;
    float marks[5];
};

// Function to input student details
void inputStudentDetails(Student& student) {
    cout << "Enter Admission Number: ";
    cin >> student.admissionNumber;
    cout << "Enter Name: ";
    cin.ignore(); 
    getline(cin, student.name);

    cout << "Enter Marks for 5 Subjects:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Subject " << i + 1 << ": ";
        cin >> student.marks[i];
    }
}

// Function to save student details to a file
void saveStudentToFile(const Student& student) {
    ofstream outFile("studentMarks.txt", ios::app); // Append mode
    if (outFile.is_open()) {
        outFile << student.admissionNumber << " "
                << student.name << " ";
        for (int i = 0; i < 5; ++i) {
            outFile << student.marks[i] << " ";
        }
        outFile << endl;
        outFile.close();
        cout << "Student details saved successfully!\n\n";
    } else {
        cout << "Error opening file for writing.\n\n";
    }
}

// Function to display all student details from the file
void displayAllStudentDetails() {
    ifstream inFile("studentMarks.txt");
    if (inFile.is_open()) {
        cout << "\nAll Student Details:\n";
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Error opening file for reading.\n";
    }
}

// Function to display details for a specific student
void displaySpecificStudentDetails(const string& admissionNumber) {
    ifstream inFile("studentMarks.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (line.find(admissionNumber) != string::npos) {
                cout << "Student Details:\n" << line << endl;
                inFile.close();
                return;
            }
        }
        cout << "Student with admission number " << admissionNumber << " not found.\n";
        inFile.close();
    } else {
        cout << "Error opening file for reading.\n";
    }
}

// Function to modify student details
void modifyStudentDetails() {
    string admissionNumber;
    cout << "Enter Admission Number to modify: ";
    cin >> admissionNumber;

    vector<Student> students;
    ifstream inFile("studentMarks.txt");
    if (inFile.is_open()) {
        Student student;
        while (inFile >> student.admissionNumber >> student.name) {
            for (int i = 0; i < 5; ++i) {
                inFile >> student.marks[i];
            }
            students.push_back(student);
        }
        inFile.close();
				for (size_t i = 0; i < students.size(); ++i) {
			    Student& s = students[i];
			    if (s.admissionNumber == admissionNumber) {
			        cout << "Enter new Name: ";
			        cin.ignore();
			        getline(cin, s.name);
			        cout << "Enter new Marks for 5 Subjects:\n";
			        for (int j = 0; j < 5; ++j) {
			            cout << "Subject " << j + 1 << ": ";
			            cin >> s.marks[j];
			        }
			        break;
			    }
			   	   	}
			        ofstream outFile("studentMarks.txt");
		    	if (outFile.is_open()) {
			    for (std::vector<Student>::const_iterator it = students.begin(); it != students.end(); ++it) {
			    const Student& s = *it;
			      outFile << s.admissionNumber << " " << s.name << " ";
			    for (int i = 0; i < 5; ++i) {
			        outFile << s.marks[i] << " ";
			    }
			    outFile << std::endl;
			}
            outFile.close();
            cout << "Student details modified successfully!\n\n";
        } else {
            cout << "Error opening file for writing.\n";
        }
    } else {
        cout << "Error opening file for reading.\n";
    }
}

int main() {
    int choice;
    do{
    cout << "1. Add Student Details\n";
    cout << "2. Display All Student Details\n";
    cout << "3. Display Specific Student Details\n";
    cout << "4. Modify Student Details\n";
    cout << "5. Exit Program\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            Student student;
            inputStudentDetails(student);
            saveStudentToFile(student);
            cout<<endl;
            break;
        }
        case 2:
            displayAllStudentDetails();
            cout<<endl;
            break;
        case 3: {
            string admissionNumber;
            cout << "Enter Admission Number to search: ";
            cin >> admissionNumber;
            displaySpecificStudentDetails(admissionNumber);
            cout<<endl;
            break;
        }
        case 4:
            modifyStudentDetails();
            cout<<endl;
            break;
        case 5:
            cout << "Exiting program. Have a great day!\n";
            break;
        default:
            cout << "Invalid choice. Please select a valid option.\n";
    }
} while(choice != 5);
    return 0;
}
