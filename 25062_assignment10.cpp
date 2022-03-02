*/
Name - Usha sree alekhya siddi

Roll no - 25062

Div - A

Batch - C
*/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Student{
    public:
        int rollNo;
        int n, ch, flag, recordNo;
        char nm[20], name[20], address[20], division;
        void read();
        void display();
        void formatting();
        void insert();
        void displayRecoord();
        void search();
        void modifyRecord();
        void deleteRecord();
        void displaySpecificRecord();
};

void Student::read(){
    cout << "Enter Student's Name: ";
    cin >> name;
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Address: ";
    cin >> address;
}

void Student::display(){
    cout << "\n| \t" << rollNo << "\t\t|\t" << name << "\t\t| \t" << division << "\t\t| \t" << address << "\t\t|";
}

void Student::formatting(){
    cout << "\t\t\t\t\tStudent Directory";
    cout << "\n";
    cout << "\n|\tR.No. \t\t| \tName \t\t| \tDivision \t| \tAddress \t|";
}

void Student::insert(){
    Student t;
    fstream file;
    file.open("Student.dat", ios::app | ios::out);
    cout << "Enter the total number of records you want to enter : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout<<"\n";
        t.read();
        file.write((char *)&t, sizeof(t));
    }
    
    file.close();
}

void Student::displayRecoord(){
    Student t;
    fstream file;
    t.formatting();
    file.open("Student.dat", ios::in | ios::out);

    while (file.read((char *)&t, sizeof(t))){
        t.display();
    }

    file.close();
}

void Student::search(){
    Student t;
    fstream file;
    flag = 0;
    cout << "Enter the name you want to Search : ";
    cin >> nm;
    flag = 0;
    t.formatting();
    file.open("Student.dat", ios::in | ios::out);

    while (file.read((char *)&t, sizeof(t))){
        if (strcmp(t.name, nm) == 0){
            flag = 1;
            t.display();
            break;
        }
    }
    file.close();

    if (flag == 0){
        cout << "\n|\t\tRecord not found\t\t|";
    }
    cout << "\n+==================================================================================+\n";
}

void Student::modifyRecord(){
    Student t;
    fstream file;
    flag = 0;
    cout << "Enter the name whose entry you want to Modify : ";
    cin >> nm;
    flag = 0;
    file.open("Student.dat", ios::in | ios::out);

    while (file.read((char *)&t, sizeof(t))){
        if (strcmp(t.name, nm) == 0){
            flag = 1;
            cout << "Record found\nEnter modified information" << endl;
            Student tp;
            tp.read();
            file.seekp(-1 * (sizeof(t)), ios::cur);
            file.write((char *)&tp, sizeof(t));
            break;
        }
    }

    file.close();

    if (flag == 0){
        cout << "Record not found";
    }
}

void Student::deleteRecord(){
    Student t;
    fstream file;
    flag = 0;
    cout << "Enter the name whose entry you want to Delete : ";
    cin >> nm;
    fstream tfile;
    file.open("Student.dat", ios::in | ios::out);

    while (file.read((char *)&t, sizeof(t))){
        if (strcmp(t.name, nm) == 0){
            flag = 1;
            break;
        }
    }
    file.close();

    if (flag == 0){
        cout << "Record not found\n";
    }else{
        tfile.open("Temp.dat", ios::out);
        file.open("Student.dat", ios::in);

        while (file.read((char *)&t, sizeof(t))){
            if (strcmp(t.name, nm) != 0){
                tfile.write((char *)&t, sizeof(t));
            }
        }

        file.close();
        tfile.close();
        remove("Student.dat");
        rename("Temp.dat", "Student.dat");
        cout << "Record Deleted Successfully\n";
    }
}



int main(){
    int ch;
    bool exit = false;
cout<<"================================================================"<<endl;
    cout<<"********************File Handling********************"<<endl;
cout<<"================================================================"<<endl;
    cout<<"********************Student's Database********************"<<endl;
cout<<"================================================================"<<endl;
    cout << "Options: \n1. Insert Record\n2. Display Record\n3. Search Record\n4. Modify Record\n5. Delete a Record\n6. Exit."<<endl;
    Student t;

    while(!exit){
        cout << "\nEnter your choice: ";
        cin >> ch;
cout<<"================================================================"<<endl;
        switch (ch){
            case 1:
                t.insert();
                break;

            case 2:
                t.displayRecoord();
                break;

            case 3:
                t.search();
                break;

            case 4:
                t.modifyRecord();
                break;

            case 5:
                t.deleteRecord();
                break;

            case 6:
                exit = true;
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid Choice..";
                break;
        }
    } 
    return 0;
}

/*

================================================================
********************File Handling********************
================================================================
********************Student's Database********************
================================================================
Options: 
1. Insert Record
2. Display Record
3. Search Record
4. Modify Record
5. Delete a Record
6. Exit.

Enter your choice: 1
================================================================
Enter the total number of records you want to enter : 3

Enter Student's Name: Aakash     
Enter Roll Number: 2001
Enter Division: A
Enter Address: Pune

Enter Student's Name: Gaurav
Enter Roll Number: 2005
Enter Division: A
Enter Address: Chalisgaon

Enter Student's Name: Tanmay
Enter Roll Number: 2034
Enter Division: A
Enter Address: Nashik

Enter your choice: 2
================================================================
                                        Student Directory

|       R.No.           |       Name            |       Division        |       Address         |
|       2001            |       Aakash          |       A               |       Pune            |
|       2005            |       Gaurav          |       A               |       Chalisgaon              |
|       2034           |       Tanmay          |       A               |       Nashik          |
Enter your choice: 3
================================================================
Enter the name you want to Search : Gaurav
                                        Student Directory

|       R.No.           |       Name            |       Division        |       Address         |
|       2005            |       Gaurav          |       A               |       Chalisgaon              |
+==================================================================================+

Enter your choice: 4
================================================================
Enter the name whose entry you want to Modify : Tanmay
Record found
Enter modified information
Enter Student's Name: Deepak
Enter Roll Number: 2054
Enter Division: A
Enter Address: Ahmednagar

Enter your choice: 5
================================================================
Enter the name whose entry you want to Delete : Aakash
Record Deleted Successfully

Enter your choice: 6
================================================================
Exiting...

*/