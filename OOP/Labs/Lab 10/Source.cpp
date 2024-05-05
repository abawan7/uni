#include<iostream>
#include<string.h>
using namespace std;
class undergaguate;
class graguate;
class faculty;
class person
{
    string firstname;
    string lastname;
protected:
    int age;
public:
    person()
    {
        age = 0;
        firstname = "";
        lastname = "";
    }
    void setage()
    {
        cout << "Enter the age" << endl;
        cin >> age;
    }
    void setfirstname()
    {
        cout << "Enter the first name" << endl;
        cin >> firstname;
    }
    void setlastname()
    {
        cout << "Enter the last name" << endl;
        cin >> lastname;
    }
    string getfirstname()
    {
        return firstname;
    }
    string getlastname()
    {
        return lastname;
    }
};
class undergaguate : public person
{
public:
    undergaguate()
    {
        fyp_name = "";
        supervisorname = "";
        cgpa = 0.0;
        roll_no = 0;
    }
    ~undergaguate();
    void setcgpa()
    {
        cout << "Enter the cgpa" << endl;
        cin >> cgpa;
    }
    double getcgpa()
    {
        return cgpa;
    }
    void setsupervisors()
    {
        cout << "Enter the name of supervisor" << endl;
        cin >> supervisorname;
    }
    string getsupervisors()
    {
        return supervisorname;
    }
    void setrollno()
    {
        cout << "Enter the roll no" << endl;
        cin >> roll_no;
    }
    int getrollno()
    {
        return roll_no;
    }
    void setfypname()
    {
        cout << "Enter the name of fyp" << endl;
        cin >> fyp_name;
    }
    string getfypname()
    {
        return fyp_name;
    }
    int getage()
    {
        return age;
    }
private:
    string fyp_name;
    string supervisorname;
    double cgpa;
    int roll_no;
};
undergaguate::~undergaguate()
{}
class graguate :public undergaguate
{

public:
    graguate()
    {
        thesistopic = "";
    }
    ~graguate();
    void setcgpa()
    {
        undergaguate::setcgpa();
    }
    double getcgpa()
    {
        return undergaguate::getcgpa();
    }
    void setsupervisors()
    {
        undergaguate::setsupervisors();
    }
    string getsupervisors()
    {
        return undergaguate::getsupervisors();
    }
    void setrollno()
    {
        undergaguate::setrollno();
    }
    int getrollno()
    {
        return undergaguate::getrollno();
    }
    void setthesisname()
    {
        cout << "Enter the name of the thesis" << endl;
        cin >> thesistopic;
    }
    string getthesisname()
    {
        return thesistopic;
    }

    int getage()
    {
        return age;
    }

private:
    string thesistopic;
};

graguate::~graguate()
{
}
class faculty :public person
{
public:
    faculty()
    {
        cours_count = 0;
        ext = 0;
    }
    ~faculty();
    int getage()
    {
        return age;
    }
    int getcoursecount()
    {
        return cours_count;
    }
    int getextension()
    {
        return ext;
    }
    void setextension()
    {
        cout << "Enter the extensions" << endl;
        cin >> ext;
    }
    void setcoursecount()
    {
        cout << "Enter the number of the course" << endl;
        cin >> cours_count;
    }
private:
    int cours_count;
    int ext;
};
faculty::~faculty()
{

}
int main()
{
    person p;
    p.setage();
    p.setfirstname();
    p.setlastname();
    cout << p.getfirstname() << " " << p.getlastname() << endl;
    undergaguate a;
    a.setcgpa();
    cout << a.getcgpa() << endl;
    a.setsupervisors();
    cout << a.getsupervisors() << endl;
    a.setage();
    cout << a.getage() << endl;
    a.setfypname();
    cout << a.getfypname() << endl;
    a.setrollno();
    cout << a.getrollno() << endl;
    graguate b;
    b.setthesisname();
    cout << b.getthesisname() << endl;
    b.setrollno();
    cout << b.getrollno();
    b.setsupervisors();
    cout << b.getsupervisors() << endl;
    b.setage();
    cout << b.getage() << endl;
    faculty teacher;
    teacher.setextension();
    cout << teacher.getextension() << endl;
    teacher.setcoursecount();
    cout << teacher.getcoursecount() << endl;
    teacher.setage();
    cout << teacher.getage();
    return 0;
}
