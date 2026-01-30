#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class Student {
private:
    int rollNo;
    char name[50];
    char city[50];
    float cgpa;

public:
    
	Student(int r = 0, string n = "", string c = "", float g = 0.0) {
        rollNo = r;
        strcpy(name, n.c_str());
        strcpy(city, c.c_str());
        cgpa = g;
    }

    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Enter City: ";
        cin.getline(city, 50);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void display() {
        cout << "Roll No: " << rollNo
             << ", Name: " << name
             << ", City: " << city
             << ", CGPA: " << cgpa << endl;
    }

    int getRollNo() { return rollNo; }
    float getCgpa() { return cgpa; }
    string getCity() { return string(city); }
	string getName() { return string(name); }
};

void addStudent() {
    ofstream out("students.dat", ios::binary | ios::app);
    ofstream indexFile("index.dat", ios::binary | ios::app);
    if (!out || !indexFile) {
        cout << "File could not be opened!" << endl;
        return;
    }
    Student s;
    s.input();

    streampos pos = out.tellp();
    out.write((char*)&s, sizeof(s));

    int roll = s.getRollNo();
    long offset = pos;
    indexFile.write((char*)&roll, sizeof(roll));
    indexFile.write((char*)&offset, sizeof(offset));

    out.close();
    indexFile.close();
    cout << "Student record added successfully!\n";
}

void displayStudents() {
    ifstream in("students.dat", ios::binary);
    if (!in) {
        cout << "File could not be opened!" << endl;
        return;
    }
    Student s;
    cout << "\n--- Student Records ---\n";
	
    while (in.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        s.display();
    }
    in.close();
}

void searchByRollNo() {
    ifstream in("students.dat", ios::binary);
    if (!in) {
        cout << "File could not be opened!" << endl;
        return;
    }
    int r;
    cout << "Enter Roll No to search: ";
    cin >> r;
    Student s;
    bool found = false;
    while (in.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getRollNo() == r) {
            cout << "Record found:\n";
            s.display();
            found = true;
            break;
        }
    }
    if (!found) cout << "Record not found.\n";
    in.close();
}

void searchByFilter() {
    ifstream in("students.dat", ios::binary);
    if (!in) {
        cout << "File could not be opened!" << endl;
        return;
    }
    int choice;
    cout << "Search by:\n1. CGPA >= X\n2. City\nChoice: ";
    cin >> choice;

    Student s;
    if (choice == 1) {
        float x;
        cout << "Enter CGPA: ";
        cin >> x;
        while (in.read(reinterpret_cast<char*>(&s), sizeof(s))) {
            if (s.getCgpa() >= x) s.display();
        }
    } else if (choice == 2) {
        string city;
        cin.ignore();
        cout << "Enter City: ";
        getline(cin, city);
        while (in.read(reinterpret_cast<char*>(&s), sizeof(s))) {
            if (s.getCity() == city) s.display();
        }
    }
    in.close();
}

void deleteStudent() {
    ifstream in("students.dat", ios::binary);
    ofstream out("temp.dat", ios::binary);
    if (!in || !out) {
        cout << "File could not be opened!" << endl;
        return;
    }
    int r;
    cout << "Enter Roll No to delete: ";
    cin >> r;
    Student s;
    bool found = false;
    while (in.read(reinterpret_cast<char*>&s, sizeof(s))) {
        if (s.getRollNo() == r) {
            found = true;
            continue; 
        }
        out.write((reinterpret_cast<char*>(&s), sizeof(s)));
    }
    in.close();
    out.close();
    if (found) {cout << "Record deleted.\n";    remove("students.dat");
    rename("temp.dat", "students.dat");
}
    else{ cout << "Record not found.\n"; remove("temp.dat");
    }
}

void updateStudent() {
    fstream file("students.dat", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "File could not be opened!" << endl;
        return;
    }
    int r;
    cout << "Enter Roll No to update: ";
    cin >> r;
    Student s;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getRollNo() == r) {
            cout << "Record found. Enter new details:\n";
            s.input();
            file.seekp(-sizeof(s), ios::cur);
            file.write((reinterpret_cast<char*>(&s), sizeof(s)));
            cout << "Record updated.\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Record not found.\n";
    file.close();
}

void showFilePosition() {
    fstream file("students.dat", ios::binary | ios::in);
    if (!file) {
        cout << "File could not be opened!" << endl;
        return;
    }
    cout << "Current position (tellg): " << file.tellg() << endl;
    file.seekg(0, ios::end);
    cout << "Position at end: " << file.tellg() << endl;
    file.close();
}

void reverseDisplay() {
    ifstream in("students.dat", ios::binary);
    if (!in) {
        cout << "File could not be opened!" << endl;
        return;
    }
    in.seekg(0, ios::end);
    long fileSize = in.tellg();
    int recordSize = sizeof(Student);
    int totalRecords = fileSize / recordSize;

    Student s;
    cout << "\n--- Reverse Order Records ---\n";
    for (int i = totalRecords - 1; i >= 0; i--) {
        in.seekg(i * recordSize, ios::beg);
        in.read((reinterpret_cast<char*>(&s), sizeof(s)));
        s.display();
    }
    in.close();
}

void searchUsingIndex() {
    ifstream indexFile("index.dat", ios::binary);
    ifstream dataFile("students.dat", ios::binary);
    if (!indexFile || !dataFile) {
        cout << "File could not be opened!" << endl;
        return;
    }
    int r;
    cout << "Enter Roll No to search (using index): ";
    cin >> r;

    int roll;
    long offset;
    bool found = false;

    while (indexFile.read(reinterpret_cast<char*>(&roll), sizeof(roll))) {
        indexFile.read(reinterpret_cast<char*>(&offset), sizeof(offset));
        if (roll == r) {
            dataFile.seekg(offset, ios::beg);
            Student s;
            dataFile.read(reinterpret_cast<char*>(&s), sizeof(s));
            cout << "Record found (via index):\n";
            s.display();
            found = true;
            break;
        }
    }
    if (!found) cout << "Record not found in index.\n";

    indexFile.close();
    dataFile.close();
}

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:" << endl
             << "1. Add Student" << endl
             << "2. Display Students" << endl
             << "3. Search by Roll No" << endl
             << "4. Search by CGPA or City" << endl
             << "5. Delete by Roll No" << endl
             << "6. Update by Roll No" << endl
             << "7. Show File Position" << endl
             << "8. Reverse Display" << endl
             << "9. Search Using Index (Bonus)" << endl
             << "10. Exit" << endl
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); 
			       break;
            case 2: displayStudents(); 
			       break;
            case 3: searchByRollNo(); 
			       break;
            case 4: searchByFilter(); 
			       break;
            case 5: deleteStudent(); 
			       break;
            case 6: updateStudent(); 
			       break;
            case 7: showFilePosition(); 
			       break;
            case 8: reverseDisplay(); 
			       break;
            case 9: searchUsingIndex(); 
			       break;
            case 10: cout << "Goodbye!\n"; 
			        return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
