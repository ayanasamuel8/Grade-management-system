#include <iostream>
#include <string>
#include <fstream>
/*

 ///------------------------------------------------------------------------------///
 DOCUMENTATION
 Program description: This application helps both teacher and students. By using this application, the teachers
 can easily register students' name and ID as well as their assessment, then this application calculate their grade.
 In addition, this application also helps students to access their information through their ID number.
 ********************** USER MANUAL *********************
 For teacher: press 1, sign up or register him or herself by inputting him
 name later our application allow him to assign him password.
 press 2, the teacher login by inserting him name and password that he registered at login ,
 in order TO ADD students name and ID NUMBER will their assessment.
 N.B login is successfully if and only the name and password match correctly.
 after successfully login he will have two option
#press 1 add on new page by deleting the existing one
#press 2 add on on existing data with out deleting the former one

 FOR student
 press 2 after insert him ID NUMBER that assigned during login correctly!!!
 then he or she can easily  accesses him or her or assessment result and grade perfectly.

       #-------------------------------------------------------------------------------#
       *                                CONTENT USED IN APP                            *
       *  !1   We use File handling to store both teachers data and students data on   *
       *       Microsoft excel (file.CSV) and it save by teacher name as file name.    *
       *  !2   This APP does not allow user to input wrong ID NUMBER ,password and     *
       *       choice number.so our APP send message them as to correctly input.       *
       *  !3  To obey the content that we have learned we have used different ADT like *
       *     linked list                                                               *
       #--------------------THANK YOU!!!!----------------------------------------------#
 */
using namespace std;

struct student
{
    string name;
    string department;
    int year;
    string id_number;
    float assessment;
    float final;
    double sum;
    string grade;
    student *next;
};
void signup()
{
    string x, p, s;
    cout << "Enter your name:  ";
    cin.ignore();
    getline(cin, x);
    cout << "Enter your password:  ";
    getline(cin, p);
    cout << "Enter a subject:  ";
    getline(cin, s);
    fstream pass;
    pass.open("sign.csv", ios::app);
    if (pass.is_open())
    {
        pass << x << "," << p << "," << s << endl;
        cout << "signed up successfully\n";
        pass.close();
    }
    else
    {
        cout << "Failed to open the file for writing\n";
    }
}

void addStudent(student *&head)
{
    student *current = head;
    int num;
    cout << "Enter the number of students: ";
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        student *s = new student;
        cin.ignore();
        cout << "Enter the " << i + 1 << " student name: ";
        getline(cin, s->name);
        cout << "Enter Department of " << s->name << ": ";
        cin >> s->department;
        cout << "Enter Year of " << s->name << ": ";
        cin >> s->year;
        cout << "Enter ID Number of " << s->name << ": ";
        cin >> s->id_number;
        cout << "Enter Assessment of " << s->name << ": ";
        cin >> s->assessment;
        cout << "Enter Final " << s->name << ": ";
        cin >> s->final;

        s->sum = s->assessment + s->final;
        if (s->sum >= 90)
            s->grade = "A+";
        else if (s->sum >= 85)
            s->grade = "A";
        else if (s->sum >= 80)
            s->grade = "A-";
        else if (s->sum >= 75)
            s->grade = "B+";
        else if (s->sum >= 70)
            s->grade = "B";
        else if (s->sum >= 65)
            s->grade = "B-";
        else if (s->sum >= 60)
            s->grade = "C+";
        else if (s->sum >= 50)
            s->grade = "C";
        else if (s->sum >= 45)
            s->grade = "C-";
        else if (s->sum >= 40)
            s->grade = "D";
        else
            s->grade = "F";

        s->next = nullptr;

        if (head == nullptr)
        {
            head = s;
            current = head;
        }
        else
        {
            current->next = s;
            current = s;
        }
    }
}

bool validateLogin(string namee, string sear)
{
    string password, name, sub;
    fstream pass;
    bool f = false;
    pass.open("sign.csv", ios::in);
    while (getline(pass, name, ','))
    {
        getline(pass, password, ',');
        getline(pass, sub, '\n');

        if (name == namee && password == sear)
        {
            f = true;
            break;
        }
    }
    pass.close();
    return f;
}

int main()
{
    student *head = new student;
    while (true)
    {
        cout << "-------------------------" << endl;
        cout << "Pre-Engineering Grade Management System" << endl;
        cout << "1. Teacher" << endl;
        cout << "2. student" << endl;
        cout << "3. Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            while (true)
            {
                cout << "-------------------------" << endl;
                cout << "1. Sign Up" << endl;
                cout << "2. Login" << endl;
                cout << "3. Exit" << endl;
                cout << "-------------------------" << endl;
                cout << "Enter your choice: ";
                int choose;
                cin >> choose;

                switch (choose)
                {
                case 1:
                {
                    signup();
                    break;
                }
                case 2:
                {
                    cout << "-------------------------" << endl;
                    cout << "Login Page" << endl;
                    string subject, password;
                    cout << "name: ";
                    cin.ignore();
                    getline(cin, subject);
                    cout << "Password: ";
                    getline(cin, password);
                    if (validateLogin(subject, password))
                    {
                        cout << "Login successful!" << endl;

                        while (true)
                        {
                            cout << "-------------------------" << endl;
                            cout << "Pre-Engineering Grade Management System" << endl;
                            cout << "1. Add Student" << endl;
                            cout << "2. Add new student to exsisting one" << endl;
                            cout << "3. exit" << endl;
                            cout << "-------------------------" << endl;
                            cout << "Enter your choice: ";

                            int choicee;
                            cin >> choicee;

                            switch (choicee)
                            {
                            case 1:
                            {
                                cout << "WARNING!!!\n";
                                cout << "If you have existing data ; your data will be erased\n";
                                cout << "If you want to continue press 1\n";
                                cout << "Press any key to cancel\n";

                                char numb;
                                cin >> numb;
                                switch (numb)
                                {
                                case '1':
                                {
                                    addStudent(head);
                                    ofstream file;
                                    string filename = "";
                                    for (char x : subject)
                                    {
                                        filename += tolower(x);
                                    }

                                    filename += ".csv";
                                    file.open(filename, ios::out);
                                    if (file.is_open())
                                    {
                                        student *current = head;
                                        file << "Name: " << ",Department: " << ",Year: " << ",ID Number: " << ",Assessment: " << ",Final: " << ",Grade: " << endl;
                                        while (current != NULL)
                                        {
                                            file << current->name << "," << current->department << "," << current->year << "," << current->id_number << "," << current->assessment << "," << current->final << "," << current->grade << endl;
                                            current = current->next;
                                        }
                                        file.close();
                                        cout << "Gradesystem saved to file." << endl;
                                    }
                                    else
                                    {
                                        cout << "Error creating the file." << endl;
                                    }
                                    break;
                                }
                                default:
                                {
                                    return 0;
                                }
                                }
                                break;
                            }
                            case 2:
                            {

                                addStudent(head);

                                ofstream file;
                                string filename = "";
                                for (char x : subject)
                                {
                                    filename += tolower(x);
                                }

                                filename += ".csv";
                                file.open(filename, ios::app);
                                if (file.is_open())
                                {

                                    student *current = head;
                                    while (current != NULL)
                                    {
                                        file << current->name << "," << current->department << "," << current->year << "," << current->id_number << "," << current->assessment << "," << current->final << "," << current->grade << endl;
                                        current = current->next;
                                    }

                                    file.close();
                                    cout << "Gradesystem saved to file." << endl;
                                }
                                else
                                {
                                    cout << "Error creating the file." << endl;
                                }
                                break;
                            }
                            case 3:
                            {
                                exit(0);
                                break;
                            }
                            default:
                                cout << "Invalid choice." << endl;
                            }
                        }
                    }

                    else
                    {
                        cout << "Invalid password. Login failed." << endl;
                    }
                    break;
                }
                case 3:
                    exit(0);
                    break;
                }
            }
        }

        case 2:
        {

            string name, password, sub, namee;
            string searchId;
            cout << "Enter your id number to get the grade: ";
            cin >> searchId;
            ifstream input("sign.csv");
            while (getline(input, name, ','))
            {
                getline(input, password, ',');
                getline(input, sub, '\n');

                string filename = name;
                for (char &x : filename)
                {
                    x = tolower(x);
                }
                filename += ".csv";
                ifstream inputFile(filename);
                if (!inputFile.is_open())
                {
                    cout << "error opening file\n";
                }

                string id, namee, grade, department, year, assessment, final;

                bool found = false;
                while (getline(inputFile, namee, ','))
                {
                    getline(inputFile, department, ',');
                    getline(inputFile, year, ',');
                    getline(inputFile, id, ',');
                    getline(inputFile, assessment, ',');
                    getline(inputFile, final, ',');
                    getline(inputFile, grade, '\n');

                    if (id == searchId)
                    {
                        found = true;
                        cout << " Subject: " << sub << endl;
                        cout << " Assesment: " << assessment << endl;
                        cout << " final: " << final << endl;
                        cout << " Grade: " << grade << endl;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "ID not found" << endl;
                }

                inputFile.close();
                cout << " Name: " << namee << endl;
            }
        }
        }
    }

    return 0;
}