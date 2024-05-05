#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <random>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

const string CREDENTIALS_FILE = "user_credentials.txt";  // Path to the credentials file
const string COMPLAINTS_FILE = "complaints.txt";         // Path to the complaints file
const string DEPTMANAGER_FILE = "deptmanager.txt";         // Path to the Department Manager file
const string DEPTEMPLOYEE_FILE = "deptemployees.txt";         // Path to the Department Employee file
const string EMPLOYEETASK_FILE = "EmployeeTask.txt";         // Path to the Employee Assigned Job file

class Teacher;
class Manager;
class Employee;
class Complaint;

// Function to generate a random date within a specified range
string generateRandomDate(int yearStart, int yearEnd) {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> disYear(yearStart, yearEnd);
    uniform_int_distribution<> disMonth(1, 12);
    uniform_int_distribution<> disDay(1, 28); // Simplified to handle all months

    int year = disYear(gen);
    int month = disMonth(gen);
    int day = disDay(gen);

    stringstream dateStream;
    dateStream << setfill('0') << setw(2) << day << "/"
               << setfill('0') << setw(2) << month << "/"
               << year;

    return dateStream.str();
}

// Class representing a department in the organization
class Department {
public:
    string name;
    Manager *manager;
    vector<Employee *> employees;
    vector<Complaint *> complaints;

    Department();
    void printEmployee();
    int getNewComplaint();
    void printComplaint();
    void getComplaintByTeacher(string);
    string getManager();
    string getManagerByDept();
    string getEmployeeDept(string);
    void updateComplaint(string,string, int);
    void getResolvedComplaintByTeacher(string);
    void sendBackResolvedComplaint(string, int);

    void giveResolvedComplaintFeedback(string, int , string);
    Department(string n, Manager *m) : name(n), manager(m) {}
    void addEmployee(Employee* emp) {
        employees.push_back(emp);
    }
    void addComplaint(Complaint *cmp){
        complaints.push_back(cmp);
    }
    string getName(){ return name; }
    ~Department() {
        delete manager;
    }
    vector<Employee*> getEmployees() const {
        return employees;
    }

    vector<Complaint*> getComplaint() const {
        return complaints;
    }

    void setManager(Manager* newManager) {
        manager = newManager;
    }

};

// Interface for defining user roles and their associated tasks
class UserRoleInterface {
public:
    virtual void performTask(vector <Department*> &department, vector <Teacher*> &teacher) = 0; // Pure virtual function for performing tasks
    virtual ~UserRoleInterface() {} // Virtual destructor
};

// Class to manage the status of complaints
class ComplaintStatus {
private:
    static ComplaintStatus* instance;
    string status;
public:
    ComplaintStatus() {}
    static ComplaintStatus* getInstance() {
        if (!instance)
            instance = new ComplaintStatus;
        return instance;
    }

    string getStatus() const {
        return status;
    }

    void setStatus(const string& newStatus) {
        status = newStatus;
    }
};

class Complaint {
    string description;
    ComplaintStatus* status;
    string assignmentDate;
    string resolutionDate;
    string feedback;
    string teacher;
    vector<Employee*> employees;
public:
    Complaint(string desc, ComplaintStatus* stat, string t, const string& assignDate = "", const string& resDate = "", const string& fb = ""): description(desc), status(stat), teacher(t), assignmentDate(assignDate), resolutionDate(resDate), feedback(fb) {}
    void printCmpEmp();
    void printComplainByEmployee(string);
    void assignToEmployees(const vector<Employee*>& assignedEmployees);
    bool getComplainByEmployee(string);
    void resolve(string, string);
    void close(string, string);
    void assignAgain(){
        assignmentDate = generateRandomDate(2020, 2022);
        resolutionDate = "";
        status->setStatus("Assigned");
    }

    string getTeachername() const {return teacher;}
    string getDescription() const { return description; }
    ComplaintStatus* getStatus() const { return status; }
    string getAssignmentDate() const { return assignmentDate; }
    string getResolutionDate() const { return resolutionDate; }
    string getFeedback() const { return feedback; }
    void setEmployee(Employee *emp){
            employees.push_back(emp);
    }
    void setDescription(const string& desc) { description = desc; }
    void setStatus(ComplaintStatus* stat) { status = stat; }
    void setAssignmentDate(const string& assignDate) { assignmentDate = assignDate; }
    void setResolutionDate(const string& resDate) { resolutionDate = resDate; }
    void setFeedback(const string& fb) { feedback = fb; }
    void setTeacher(const string& t) { teacher = t; }
    const vector<Employee*>& getEmployees() const {
        return employees;
    }
};
// Static instance for Singleton pattern
ComplaintStatus* ComplaintStatus::instance = nullptr;


// Base class for all user types
class User {
protected:
    string username;
    string password;
    string fullname;
    string address;
    string phone_no;

public:
    User(string username, string password)
            : username(username), password(password) {}

    User(string username, string password, string fullname, string address, string phone_no)
            : username(username), password(password), fullname(fullname), address(address), phone_no(phone_no) {}


    string getFullName() const { return fullname; }
    string getAddress() const { return address; }
    string getPhoneNo() const { return phone_no; }
    string getUsername() const { return username; }
    string getPassword() const { return password; }
};


// Derived class from User for Employee role
class Employee : public User, public UserRoleInterface {
public:
    Employee(string username, string password, string fullname, string address, string phone_no): User(username, password, fullname, address, phone_no) {}
    void performTask(vector<Department*>& departments, vector<Teacher*>& teachers) override {
        while (true) {
            cout << "Employee's Dashboard\n";
            cout << "\nWelcome, " << this->getFullName() << ".\n";
            cout << "1. Check Job\n";
            cout << "2. Update The Job\n";
            cout << "3. Logout\n";
            cout << "Please select a task (1-3): ";

            int task;
            cin >> task;
            cin.ignore();  // To handle the newline character after the input

            if (task < 1 || task > 3) {
                cout << "Invalid option, please try again.\n";
                continue;
            }

            string deptName;
            vector<Complaint*> allComplaints;
            for (const auto& d : departments) {
                if (d->getEmployeeDept(this->getFullName()) != "") {
                    deptName = d->getName();
                    allComplaints = d->getComplaint();
                    break;
                }
            }

            if (deptName.empty()) {
                cout << "No department found for your profile.\n";
                continue;
            }

            if (task == 1 || task == 2) {
                int complaintIndex = 1;
                for (const auto& complaint : allComplaints) {
                    if (complaint->getStatus()->getStatus() == "Assigned" &&
                        complaint->getComplainByEmployee(this->getFullName())) {
                        cout << complaintIndex << ": " << complaint->getDescription() << endl;
                        complaintIndex++;
                    }
                }

                if (complaintIndex == 1) {
                    cout << "No jobs found.\n";
                    continue;
                }

                if (task == 2) {
                    cout << "Select the job number you want to update, or press 0 to cancel: ";
                    int jobNum;
                    cin >> jobNum;
                    cin.ignore();

                    if (jobNum > 0 && jobNum < complaintIndex) {
                        for (const auto& d : departments) {
                            if (d->getName() == deptName) {
                                d->updateComplaint(this->getFullName(), deptName, jobNum);
                                cout << "Job updated successfully.\n";
                                break;
                            }
                        }
                    } else if (jobNum == 0) {
                        cout << "Update cancelled.\n";
                    } else {
                        cout << "Invalid job number.\n";
                    }
                }
            } else if (task == 3) {
                cout << "Logging out...\n";
                break;
            }
        }
    }

};

void Complaint::printCmpEmp() {
    for (auto *employee: employees) {
        cout << employee->getFullName() << ", ";
    }
    cout << endl;
}
bool Complaint::getComplainByEmployee(string employee_name){
    int i = 0;
    for(auto emp: employees){
        if (emp->getFullName() == employee_name){
            return true;
        }
    }
    return false;
}
void Complaint::printComplainByEmployee(string employee_name){
    for(auto emp: employees){
        if (emp->getFullName() == employee_name){
            cout << description << endl;
        }
    }
}
void Complaint::assignToEmployees(const vector<Employee*>& assignedEmployees) {
    for (auto emp : assignedEmployees) {
        employees.push_back(emp);
    }
    assignmentDate = generateRandomDate(2020,2022);
    status->setStatus("Assigned");
}
void Complaint::resolve(string date, string dptname) {
    resolutionDate = generateRandomDate(2022,2023);
    status->setStatus("Resolved");
}
void Complaint::close(string userFeedback, string dptname) {
    status->setStatus("Closed");
    feedback = userFeedback;
    employees.clear();
}

class Manager : public User, public UserRoleInterface {
public:
    Manager(string username, string password, string fullname, string address, string phone_no): User(username, password, fullname, address, phone_no) {}

    void performTask(vector<Department*>& departments, vector<Teacher*>& teachers) override {
        while (true) {
            cout << "Manager's Dashboard\n";
            cout << "\nWelcome, " << this->getFullName() << ".\n";
            cout << "1. Check The List of Employees\n";
            cout << "2. Check Your Complaints Being Handled by Employees\n";
            cout << "3. Assign Unassigned Complaints\n";
            cout << "4. Logout\n";
            cout << "Please select a task (1-4): ";

            int task;
            cin >> task;
            cin.ignore();  // To handle the newline character after the input

            if (task == 1) {
                bool found = false;
                for (const auto& dept : departments) {
                    if (dept->getManagerByDept() == this->getFullName()) {
                        dept->printEmployee();
                        found = true;
                    }
                }
                if (!found) {
                    cout << "No employees found under your management.\n";
                }
            } else if (task == 2) {
                bool found = false;
                for (const auto& dept : departments) {
                    if (dept->getManagerByDept() == this->getFullName()) {
                        dept->printComplaint();
                        found = true;
                    }
                }
                if (!found) {
                    cout << "No complaints being handled by employees found.\n";
                }
            } else if (task == 3) {
                // Task 3: Assign unassigned complaints
                for (const auto& dept : departments) {
                    if (dept->getManagerByDept() == this->getFullName()) {
                        dept->getNewComplaint();
                        cout << "Enter the Complaint number to assign it to an Employee, or press 0 to skip: ";
                        int comNum;
                        cin >> comNum;
                        cin.ignore();  // To handle the newline character after the input

                        if (comNum != 0) {
                            vector<Employee*> allEmployees = dept->getEmployees();
                            if (!allEmployees.empty()) {
                                int index=1;
                                for (const auto& emp : allEmployees) {
                                    cout << index << ". " << emp->getFullName() <<endl;
                                    index++;
                                }
                                cout << "\nHow many employees do you want to assign this complaint to? ";
                                int numEmployees;
                                cin >> numEmployees;
                                cin.ignore();

                                vector<Employee*> assignedEmployees;
                                for (int i = 0; i < numEmployees; ++i) {
                                    cout << "Enter Employee ID to assign: ";
                                    int empId;
                                    cin >> empId;
                                    cin.ignore();

                                    if (empId > 0 && empId <= allEmployees.size()) {
                                        assignedEmployees.push_back(allEmployees[empId - 1]);
                                    }
                                }
                                int i = 1;
                                    for(const auto &complaint : dept->complaints){
                                        ComplaintStatus* status = complaint->getStatus();
                                        if (status->getStatus() == "New"){
                                            if(i == comNum){
                                               complaint->assignToEmployees(assignedEmployees);
                                            }
                                        }
                                        i++;
                                    }
                                }

                            } else {
                                cout << "No employees available to assign.\n";
                            }
                        }
                    }
                }
            else if (task == 4) {
                cout << "Logging out...\n";
                break;
            } else {
                cout << "Invalid option, please try again.\n";
            }
        }
    }
};

void Department::printEmployee() {
    int i = 1;
    cout << "Employees Are: " << endl;
    for(const auto &employee : employees){
        cout<< i <<": "<<employee->getFullName() << endl;
        i++;
    }
}
void Department::printComplaint() {
    int i = 1;
    cout << "Complaints Are: " << endl;
    for(const auto &complaint : complaints){
        cout << i << ": [" << complaint->getDescription() << "] ";
        ComplaintStatus* status = complaint->getStatus();
        if (status->getStatus() == "Resolved" || status->getStatus() == "New"){
            cout << status->getStatus();
        }else if (status->getStatus() == "Assigned"){
            cout << status->getStatus() << " To ";
        }
        complaint->printCmpEmp();
        i++;
    }
}
int Department::getNewComplaint(){
    int i = 1;
    cout << "Complaints Are: " << endl;
    for(const auto &complaint : complaints){
        ComplaintStatus* status = complaint->getStatus();
        if (status->getStatus() == "New"){
            cout << i << ": [" << complaint->getDescription() << "] " << endl;
        }
        i++;
    }
}
string Department::getManager(){
    return manager->getFullName();
}
void Department::getComplaintByTeacher(string tchname){
    for (const auto com: complaints){
        if(com->getTeachername() == tchname){
            ComplaintStatus * status = com->getStatus();
            cout << "Description: " <<com->getDescription() << "    Status: " << status->getStatus() << "    Dept: " << this->getName() << endl;
        }
    }
}
void Department::getResolvedComplaintByTeacher(string tchname){
    for (const auto com: complaints){
        int i = 1;
        if(com->getTeachername() == tchname){
            ComplaintStatus * status = com->getStatus();
            if(status->getStatus() == "Resolved") {
                cout << i << ". Description: " << com->getDescription() << "    Status: " << status->getStatus()
                     << "    Dept: " << this->getName() << endl;
                i++;
            }
        }
    }
}
void Department::giveResolvedComplaintFeedback(string tchname, int rcid, string feedback){
    int i = 1;
    for (const auto com: complaints){
        if(com->getTeachername() == tchname){
            ComplaintStatus * status = com->getStatus();
            if(status->getStatus() == "Resolved") {
                if(i = rcid){
                    com->close(feedback, this->getName());
                }
                i++;
            }
        }
    }
}
void Department::sendBackResolvedComplaint(string tchname, int rcid){
    int i = 1;
    for (const auto com: complaints){
        if(com->getTeachername() == tchname){
            ComplaintStatus * status = com->getStatus();
            if(status->getStatus() == "Resolved") {
                if(i = rcid){
                    com->assignAgain();
                }
                i++;
            }
        }
    }
}
string Department::getManagerByDept(){
    return manager->getFullName();
}
string Department::getEmployeeDept(string emp_name){
    for(auto employee: employees){
        if (employee->getFullName() == emp_name){
            return this->name;
        }
    }
    return "";
}
void Department::updateComplaint(string emp_name, string deptname, int cmp_id){
    int i = 1;
    for(auto allcom:complaints){
        ComplaintStatus *Status = new ComplaintStatus;
        Status = allcom->getStatus();
        if(Status->getStatus() == "Assigned") {
            if(allcom->getComplainByEmployee(emp_name)){
               if(i == cmp_id){
                    allcom->resolve(emp_name,deptname);
               }
               i++;
            }
        }
    }
}


class Teacher : public User, public UserRoleInterface {
public:
    Teacher(string username, string password, string fullname, string address, string phone_no): User(username, password, fullname, address, phone_no) {}
    Complaint * fileComplaint(string desc, string dept , string status = "New"){
        cout << "Complaint filed: " << desc << std::endl;
        ComplaintStatus* comStatus = new ComplaintStatus();
        comStatus->setStatus(status);
        Complaint* complaint = new Complaint(desc, comStatus, this->getFullName());
        return complaint;
    }

    void performTask(vector<Department*>& departments, vector<Teacher*>& teachers) override {
        while (true) {
            cout << "Teacher's Dashboard\n";
            cout << "Welcome, " << this->getFullName() << ".\n";
            cout << "1. File a Complaint\n";
            cout << "2. Check Your Complaints\n";
            cout << "3. Check Resolved Complaints\n";
            cout << "4. Logout\n";
            cout << "Please choose a task (1-4): ";

            int task;
            cin >> task;

            if (task == 1) {
                string description, departmentName;
                cout << "Enter Department Name: ";
                cin.ignore();
                getline(cin, departmentName);
                cout << "Enter Description of the Complaint: ";
                getline(cin, description);

                Complaint* newComplaint = fileComplaint(description, departmentName);
                bool departmentFound = false;
                for (const auto& dept : departments) {
                    if (dept->getName() == departmentName) {
                        dept->addComplaint(newComplaint);
                        departmentFound = true;
                        cout << "Complaint filed successfully.\n";
                        break;
                    }
                }
                if (!departmentFound) {
                    cout << "Department not found.\n";
                }
            }
            else if (task == 2) {
                for (const auto& dept : departments) {
                    dept->getComplaintByTeacher(this->getFullName());
                }
            }
            else if (task == 3) {
                for (const auto& dept : departments) {
                    dept->getResolvedComplaintByTeacher(this->getFullName());
                }

                cout << "Enter the ID of the complaint for feedback or sending back, or enter 0 to skip: ";
                int complaintId;
                cin >> complaintId;

                if (complaintId != 0) {
                    cout << "1. Provide Feedback\n";
                    cout << "2. Send Back\n";
                    cout << "Choose an option: ";
                    int choice;
                    cin >> choice;
                    cin.ignore();

                    if (choice == 1) {
                        string feedback;
                        cout << "Enter your feedback: ";
                        getline(cin, feedback);
                        for (const auto& dept : departments) {
                            dept->giveResolvedComplaintFeedback(this->getFullName(), complaintId, feedback);
                        }
                        cout << "Feedback submitted successfully.\n";
                    } else if (choice == 2) {
                        for (const auto& dept : departments) {
                            dept->sendBackResolvedComplaint(this->getFullName(),complaintId);
                        }
                    }
                }
            }
            else if (task == 4) {
                cout << "Logging out...\n";
                break;
            }
            else {
                cout << "Invalid option, please try again.\n";
            }
        }
    }
};


class Administrator : public User, public UserRoleInterface {
public:
    Administrator(string username, string password, string fullname, string address, string phone_no): User(username, password, fullname, address, phone_no) {}
    void performTask(vector <Department*> &depts, vector <Teacher*> &teachers) override {
        while (true) {
            cout << "Administrator's Dashboard\n";
            cout << "\nWelcome " << this->getFullName() << ".\n";
            cout << "1. Add User\n";
            cout << "2. Remove User\n";
            cout << "3. Logout\n\n";
            cout << "Please choose a task (1-3): ";

            int task;
            cin >> task;
            cin.ignore();

            if (task < 1 || task > 3) {
                cout << "Invalid option, please try again.\n";
                continue;
            }

            if (task == 1) {
                int role;
                string uname, pword, fname, address, phone;

                cout << "\nEnter role (1 for Teacher, 2 for Employee, 3 for Manager): ";
                cin >> role;
                cin.ignore();  // Make sure to ignore the newline after the integer input

                cout << "Enter username: ";
                getline(cin, uname);

                cout << "Enter password: ";
                getline(cin, pword);

                cout << "Enter full name: ";
                getline(cin, fname);

                cout << "Enter address: ";
                getline(cin, address);

                cout << "Enter phone number: ";
                getline(cin, phone);

                if(role == 1) {
                    teachers.push_back(new Teacher(uname, pword, fname, address, phone));
                }
                else if(role == 2){
                    cout << "Enter Department In Which you want to Add Employee: ";
                    int i = 1;
                    for(auto dept: depts){
                        cout << i << ": " << dept->name << "\n";
                        i++;
                    }
                    int dpt_id;
                    cout << "Enter Department ID: ";
                    cin >> dpt_id;
                    cin.ignore();  // Ignore the newline after the integer input

                    if (dpt_id >= 1 && dpt_id <= depts.size()) {
                        depts[dpt_id - 1]->employees.push_back(new Employee(uname, pword, fname, address, phone));
                    } else {
                        cout << "Invalid Department ID entered.\n";
                    }
                }
                else if (role == 3){
                    cout << "Enter Department In Which you want to Add Manager: ";
                    int i = 1;
                    for(auto dept: depts){
                        cout << i << ": " << dept->name << "\n";
                        i++;
                    }
                    int dpt_id;
                    cout << "Enter Department ID: ";
                    cin >> dpt_id;
                    cin.ignore();  // Ignore the newline after the integer input

                    if (dpt_id >= 1 && dpt_id <= depts.size()) {
                        delete depts[dpt_id - 1]->manager;  // Delete existing manager
                        depts[dpt_id - 1]->manager = new Manager(uname, pword, fname, address, phone);  // Set new manager
                    } else {
                        cout << "Invalid Department ID entered.\n";
                    }
                }
            }
            else if (task == 2) {
                string name;
                cout << "Enter Name of User you want to remove: ";
                getline(cin, name);

                // Remove a teacher
                for (auto it = teachers.begin(); it != teachers.end(); ) {
                    if ((*it)->getFullName() == name) {
                        for (auto& dept : depts) {
                            for (auto cp = dept->complaints.begin(); cp != dept->complaints.end(); ) {
                                if ((*cp)->getTeachername() == name) {
                                    delete *cp;  // Delete the complaint
                                    cp = dept->complaints.erase(cp);
                                } else {
                                    ++cp;
                                }
                            }
                        }
                        delete *it;
                        it = teachers.erase(it);
                        cout << "Teacher removed successfully." << endl;
                        break;
                    } else {
                        ++it;
                    }
                }

                for (auto& dept : depts) {
                    // Remove an employee
                    for (auto it = dept->employees.begin(); it != dept->employees.end(); ) {
                        if ((*it)->getFullName() == name) {
                            delete *it;
                            it = dept->employees.erase(it);
                            cout << "Employee removed successfully from department." << endl;
                        } else {
                            ++it;
                        }
                    }

                    // Remove the manager
                    if (dept->manager != nullptr && dept->manager->getFullName() == name) {
                        delete dept->manager;
                        dept->manager = nullptr;
                        cout << "Manager removed successfully from department." << endl;
                        // Remove break if managers can be shared across departments
                    }
                }
            }else if (task == 3){
                break;
            }
        }
    }
};

class Director : public User, public UserRoleInterface{
public:
    Director(string username, string password, string fullname, string address, string phone_no): User(username, password, fullname, address, phone_no) {}
    void performTask(vector<Department*>& departments, vector<Teacher*>& teachers) override {
        while (true) {
            cout << "Director's Dashboard\n";
            cout << "\nWelcome, " << this->getFullName() << ".\n";
            cout << "1. View Summary of Complaints\n";
            cout << "2. View Detailed Complaint Information\n";
            cout << "3. Logout\n";
            cout << "Select an option: ";

            int choice;
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                // Option 1: View summary of complaints
                for (const auto& dept : departments) {
                    cout << "Department: " << dept->getName() << endl;
                    int index = 1; // Starting index for complaint IDs
                    for (const auto& complaint : dept->complaints) {
                        ComplaintStatus *stat = new ComplaintStatus();
                        stat=complaint->getStatus();
                        cout << "Complaint ID: " << index
                             << ", Status: " << stat->getStatus()
                             << ", Description: " << complaint->getDescription().substr(0, 50) << "...\n";
                        index++;
                    }
                }
            }
            else if (choice == 2) {
                // Option 2: View detailed complaint information
                cout << "Enter the Complaint ID: ";
                int complaintId;
                cin >> complaintId;

                bool found = false;
                for (const auto& dept : departments) {
                    int index = 1; // Starting index for complaint IDs
                    for (const auto& complaint : dept->complaints) {
                        if (index == complaintId) {
                            cout << "Detailed Information for Complaint ID " << index << ":\n";
                            cout << "Description: " << complaint->getDescription() << endl;
                            // Include other details as needed
                            found = true;
                            break;
                        }
                        index++;
                    }
                    if (found) break;
                }

                if (!found) {
                    cout << "No complaint found with ID " << complaintId << ".\n";
                }
            }
            else if (choice == 3) {
                cout << "Logging out...\n";
                break;
            } else {
                cout << "Invalid option, please try again.\n";
            }
        }
    }
};


// Functions for loading and saving data
// These functions should have comments explaining the data handling process
void loadUsers(vector<Teacher*>& teachers, vector<Manager*>& managers, vector<Employee*>& employees, vector<Administrator*>& admin, vector<Director*> &director){
    ifstream file(CREDENTIALS_FILE);
    string line;
    while (getline(file, line)) {

        size_t firstSep = line.find(':');
        size_t secondSep = line.find(':', firstSep + 1);
        size_t thirdSep = line.find(':', secondSep + 1);
        size_t fourthSep = line.find(':', thirdSep + 1);
        size_t fifthSep = line.find(':', fourthSep + 1);

        string uname = line.substr(0, firstSep);
        string pword = line.substr(firstSep + 1, secondSep - firstSep - 1);
        string fname = line.substr(secondSep + 1, thirdSep - secondSep - 1);
        string address = line.substr(thirdSep + 1, fourthSep - thirdSep - 1);
        string phone = line.substr(fourthSep + 1,fifthSep - fourthSep - 1);
        string role = line.substr(fifthSep + 1);

        if(role == "Teacher") {
            teachers.push_back(new Teacher(uname, pword, fname, address, phone));
        }
        else if(role == "Manager"){
            managers.push_back(new Manager(uname, pword, fname, address, phone));
        }
        else if(role == "Administrator"){
            admin.push_back(new Administrator(uname, pword, fname, address, phone));
        }else if (role == "Employee"){
            employees.push_back(new Employee(uname, pword, fname, address, phone));
        }else if(role == "Director"){
            director.push_back(new Director(uname, pword, fname, address, phone));
        }
    }
    file.close();
}
void loadDepartments(vector<Department*>& depts, const vector<Manager*>& managers){
    ifstream file(DEPTMANAGER_FILE);
    string line1;

    while (getline(file, line1)) {
        size_t firstSep = line1.find(':');
        size_t secondSep = line1.find(':', firstSep + 1);

        string deptName = line1.substr(0, firstSep);
        string deptMngname = line1.substr(firstSep + 1, secondSep - firstSep - 1);
        for (const auto& manager : managers) {
            if(manager->getFullName() == deptMngname){
                depts.push_back(new Department(deptName, manager));
                break;
            }
        }
    }
    file.close();
}
void loadDepartmentEmployees(vector<Department*>& depts, const vector<Employee*>& employees){
    ifstream file(DEPTEMPLOYEE_FILE);
    string line2;
    while (getline(file, line2)) {
        size_t firstSep = line2.find(':');
        size_t secondSep = line2.find(':', firstSep + 1);

        string deptName = line2.substr(0, firstSep);
        string deptEmpname = line2.substr(firstSep + 1, secondSep - firstSep - 1);

        for(const auto & dept:depts){
            if(dept->getName() == deptName){
                for(const auto &employee : employees){
                    if(employee->getFullName() == deptEmpname){
                        dept->addEmployee(employee);
                        break;
                    }
                }
            }
        }
    }
    file.close();
}
void loadComplaints(vector<Complaint*>& complaints, const vector<Teacher*>& teachers, vector<Department*>& depts){
    ifstream file3(COMPLAINTS_FILE);
    string line3;
    while (getline(file3, line3)) {
        size_t firstSep = line3.find(':');
        size_t secondSep = line3.find(':', firstSep + 1);
        size_t thirdSep = line3.find(':', secondSep + 1);
        size_t fourthSep = line3.find(':', thirdSep + 1);

        string descr = line3.substr(0, firstSep);
        string status = line3.substr(firstSep + 1, secondSep - firstSep - 1);
        string teachername = line3.substr(secondSep + 1, thirdSep - secondSep - 1);
        string deptname = line3.substr(thirdSep + 1, fourthSep - thirdSep - 1);

        string assignDate, resolveDate, feedback;
        size_t fifthSep = line3.find(':', fourthSep + 1);
        if (fifthSep != string::npos) {
            assignDate = line3.substr(fourthSep + 1, fifthSep - fourthSep - 1);
            size_t sixthSep = line3.find(':', fifthSep + 1);
            if (sixthSep != string::npos) {
                resolveDate = line3.substr(fifthSep + 1, sixthSep - fifthSep - 1);
                size_t seventhSep = line3.find(':', sixthSep + 1);
                if (seventhSep != string::npos) {
                    feedback = line3.substr(sixthSep + 1);
                } else {
                    feedback = line3.substr(sixthSep + 1);
                }
            } else {
                resolveDate = line3.substr(fifthSep + 1);
            }
        }
        Teacher* matchedTeacher = nullptr;
        for (const auto &teacher : teachers) {
            if (teacher->getFullName() == teachername) {
                matchedTeacher = teacher;
                break;
            }
        }
        if (matchedTeacher) {
            ComplaintStatus *newStatus = new ComplaintStatus();
            newStatus->setStatus(status);
            Complaint* newComplaint = new Complaint(descr, newStatus, teachername, assignDate, resolveDate, feedback);
            complaints.push_back(newComplaint);

            // Associate the complaint with the appropriate department
            for (auto &dept : depts) {
                if (dept->getName() == deptname) {
                    dept->addComplaint(newComplaint);
                    break;
                }
            }
        }
    }
    file3.close();
}
void loadassignToEmployees(vector<Employee*>& assignedEmployees, Complaint* complaint , const string& date) {
    for (auto emp : assignedEmployees) {
        complaint->setEmployee(emp);
    }
    complaint->setAssignmentDate(generateRandomDate(2020,2022));
    ComplaintStatus *cmpStatus = new ComplaintStatus;
    cmpStatus = complaint->getStatus();
    if(cmpStatus->getStatus() != "Resolved"){
        cmpStatus->setStatus("Assigned");
    }
    complaint->setStatus(cmpStatus);
}
void loadAssignComplaint(vector<Department*>& depts, const vector<Employee*>& employees) {
    ifstream tasksFile(EMPLOYEETASK_FILE);
    string taskLine;

    while (getline(tasksFile, taskLine)) {
        size_t firstSep = taskLine.find(':');
        string descr = taskLine.substr(0, firstSep);
        string employeeNames = taskLine.substr(firstSep + 1);

        vector<Employee*> assignedEmployees;
        size_t pos = 0;
        while ((pos = employeeNames.find(':')) != string::npos) {
            string empName = employeeNames.substr(0, pos);
            for (auto& employee : employees) {
                if (employee->getFullName() == empName) {
                    assignedEmployees.push_back(employee);
                    break;
                }
            }
            employeeNames.erase(0, pos + 1);
        }
        for (auto& employee : employees) {
            if (employee->getFullName() == employeeNames) {
                assignedEmployees.push_back(employee);
                break; // Stop the search as we found the employee
            }
        }
        for(auto &dept : depts) {
            for (auto &complaint: dept->complaints) {
                if (complaint->getDescription() == descr && !assignedEmployees.empty()) {
                    loadassignToEmployees(assignedEmployees, complaint, generateRandomDate(2020,2022));
                    break; // Ensure this break is functioning correctly
                }
            }
        }
    }

    tasksFile.close();
}

void writeUsers(const vector<Teacher*>& teachers, const vector<Department*>& departments, const vector<Administrator*>& admins,vector<Director*> &director) {
    ofstream file(CREDENTIALS_FILE, ios::out); // Overwrite the file

    for (const auto& dir : director) {
        file << dir->getUsername() << ":"
             << dir->getPassword() << ":"
             << dir->getFullName() << ":"
             << dir->getAddress() << ":"
             << dir->getPhoneNo() << ":Director\n";
    }

    for (const auto& teacher : teachers) {
        file << teacher->getUsername() << ":"
             << teacher->getPassword() << ":"
             << teacher->getFullName() << ":"
             << teacher->getAddress() << ":"
             << teacher->getPhoneNo() << ":Teacher\n";
    }
    for (const auto& dept : departments) {

        file << dept->manager->getUsername() << ":"
             << dept->manager->getPassword() << ":"
             << dept->manager->getFullName() << ":"
             << dept->manager->getAddress() << ":"
             << dept->manager->getPhoneNo() << ":Manager\n";
        for (const auto& employee : dept->employees) {
            file << employee->getUsername() << ":"
                 << employee->getPassword() << ":"
                 << employee->getFullName() << ":"
                 << employee->getAddress() << ":"
                 << employee->getPhoneNo() << ":Employee\n";
        }
    }


    for (const auto& admin : admins) {
        file << admin->getUsername() << ":"
             << admin->getPassword() << ":"
             << admin->getFullName() << ":"
             << admin->getAddress() << ":"
             << admin->getPhoneNo() << ":Administrator\n";
    }
    file.close();
}
void writeDepartmentsToFile(const vector<Department*>& depts) {
    ofstream file(DEPTMANAGER_FILE, ios::out); // Overwrite the file
    for (const auto& dept : depts) {
        file << dept->getName() << ":" << dept->getManager() << "\n";
    }
    file.close();
}
void writeComplaintsToFile(const vector<Department*>& departments) {
    ofstream file(COMPLAINTS_FILE, ios::out); // Overwrite the file
    for (const auto& department : departments) {
        for (const auto& complaint : department->complaints) {
            ComplaintStatus *stat = new ComplaintStatus;
            stat = complaint->getStatus();
            file << complaint->getDescription() << ":"
                 << stat->getStatus() << ":"
                 << complaint->getTeachername() << ":"
                 << department->getName();

            if (!complaint->getAssignmentDate().empty()) {
                file << ":" <<complaint->getAssignmentDate();
            }

            if (!complaint->getResolutionDate().empty()) {
                file << ":" << complaint->getResolutionDate();
            }

            if (!complaint->getFeedback().empty()) {
                file << ":" << complaint->getFeedback();
            }
            file << "\n"; // End of complaint record
        }
    }

    file.close();
}
void writeAssignedEmployeesToFile(const vector<Department*>& departments) {
    ofstream outEmployeeFile(EMPLOYEETASK_FILE, ios::out); // Open the file in write mode to overwrite

    if (!outEmployeeFile.is_open()) {
        cerr << "Unable to open EmployeeTask.txt for writing." << endl;
        return;
    }

    for (const auto& department : departments) {
        for (const auto& complaint : department->complaints) {
            ComplaintStatus *stat = complaint->getStatus();
            if(stat->getStatus() == "Assigned" || stat->getStatus() == "Resolved") {
                outEmployeeFile << complaint->getDescription();
                for (const auto &employee: complaint->getEmployees()) {
                    outEmployeeFile << ":" << employee->getFullName();
                }
                outEmployeeFile << endl;
            }
        }
    }
    outEmployeeFile.close();
}
void writeDepartmentEmployees(const vector<Department*>& depts) {
    ofstream file(DEPTEMPLOYEE_FILE);
    if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& dept : depts) {
        for (const auto& employee : dept->getEmployees()) {
            file << dept->getName() << ":" << employee->getFullName() << endl;
        }
    }

    file.close();
}
void writeDepartments(const vector<Department*>& depts) {
    ofstream file(DEPTMANAGER_FILE);
    if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& dept : depts) {
        if (dept->manager != nullptr) { // Ensure the department has a manager
            file << dept->getName() << ":" << dept->manager->getFullName() << endl;
        }
    }

    file.close();
}


int main() {
    vector<Teacher*> teachers;
    vector<Manager*> managers;
    vector<Employee*> employees;
    vector<Administrator*> admin;
    vector<Complaint*> complaints;
    vector<Department*> depts;
    vector<Director*> director;

    loadUsers(teachers, managers, employees, admin,director);
    loadDepartments(depts, managers);
    loadDepartmentEmployees(depts, employees);
    loadComplaints(complaints, teachers, depts);
    loadAssignComplaint(depts, employees);

    string uname, pass;
    bool exitRequested = false;

    while (!exitRequested) {
        cout << "Enter Username (or type 'exit' to quit): ";
        getline(cin, uname);

        if (uname == "exit") {
            cout << "Exiting program.\n";
            break;
        }

        cout << "Enter Password: ";
        getline(cin, pass);

        UserRoleInterface* userRole = nullptr;

        // Checking each user type for a match
        for (auto& teacher : teachers) {
            if (teacher->getUsername() == uname && teacher->getPassword() == pass) {
                userRole = teacher;
                break;
            }
        }

        if (!userRole) {
            for (auto& manager : managers) {
                if (manager->getUsername() == uname && manager->getPassword() == pass) {
                    userRole = manager;
                    break;
                }
            }
        }

        if (!userRole) {
            for (auto& employee : employees) {
                if (employee->getUsername() == uname && employee->getPassword() == pass) {
                    userRole = employee;
                    break;
                }
            }
        }

        if (!userRole) {
            for (auto& adm : admin) {
                if (adm->getUsername() == uname && adm->getPassword() == pass) {
                    userRole = adm;
                    break;
                }
            }
        }

        if (!userRole) {
            for (auto& dir : director) {
                if (dir->getUsername() == uname && dir->getPassword() == pass) {
                    userRole = dir;
                    break;
                }
            }
        }

        // User role found, perform the task
        if (userRole) {
            userRole->performTask(depts, teachers);
        } else {
            cout << "Invalid username or password. Please try again.\n";
        }
        writeUsers(teachers,depts,admin, director);
        writeDepartmentsToFile(depts);
        writeComplaintsToFile(depts);
        writeAssignedEmployeesToFile(depts);
        writeDepartmentEmployees(depts);
        writeDepartments(depts);
    }
    return 0;
}