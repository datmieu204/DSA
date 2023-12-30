#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

struct Student
{
    int id;
    string name;
    string studentClass;

    Student()
    {
        id = 0;
        name = "";
        studentClass = "";
    }
};

unordered_map<int, Student> list_students;

void insertStudent(Student &student)
{
    list_students[student.id] = student;
}

void deleteStudent(Student &student)
{
    list_students.erase(student.id);
}

void informationStudent(int id)
{
    if (list_students.find(id) != list_students.end())
    {
        cout << list_students[id].name << ","
             << list_students[id].studentClass
             << endl;
    }
    else
    {
        cout << "NA, NA";
    }
}

int main()
{
    string q;

    while (getline(cin, q))
    {
        int len = q.size();
        string check_1 = q.substr(0, 6);
        string check_2 = q.substr(0, 5);
        Student student;
        if (check_1 == "Insert")
        {
            string ans = q.substr(7, len - 8);
            stringstream ss(ans);

            int id;
            string res;
            string name, studentClass;

            string new_q = "";
            while (getline(ss, res, ','))
            {
                new_q += " " + res;
            }

            stringstream ss_2(new_q);
            ss_2 >> id >> name >> studentClass;

            student.id = id;
            student.name = name;
            student.studentClass = studentClass;

            insertStudent(student);
        }

        if (check_1 == "Delete")
        {
            string ans = q.substr(7, len - 8);
            stringstream ss(ans);
            int id;
            ss >> id;
            student.id = id;
            deleteStudent(student);
        }

        if (check_2 == "Infor")
        {
            string ans = q.substr(6, len - 7);
            stringstream ss(ans);
            int id;
            ss >> id;
            informationStudent(id);
        }
    }
    return 0;
}
