// e-SPBT workshop1.cpp 
// Syakirah Hanim binti Zulkernain BITI S1G1

#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <conio.h>
#include <cstdlib>

using namespace std;

#include "admin.h"
#include "textbook.h"
#include "teacher.h"
#include "classes.h"
#include "student.h"
#include "student_class.h"
#include "returnget.h"
#include "penalty.h"
#include "adminManager.h" 

//ADMIN FUNCTION
void AdminInsertData();
void AdminViewProfile(string id);
void AdminInsertTextbook(string id);
void AdminRegisterTeacher();
void AdminRegisterClass(string id);
void AdminViewTextbook();
void AdminSearchTextbook();
void AdminUpdateTextbook(string id);
void AdminMenuTextbook(string id);
void AdminInsertReturnGet();
void AdminUpdateReturnGet();
void AdminViewReturnGet();
void AdminFindReturnGet();
void AdminLogin();
void AdminRegisterStudent();
void AdminPenaltyStudent();
void AdminConfirmPenaltyStudent();
void AdminMenuPenalty(string id);
void AdminViewPenaltyStudent();
void AdminFindPenaltyStudent();
void AdminMenuReturnGet(string id);
void AdminMenuRegister(string id);
void AdminMainMenu(string id);
void AdminReport();

//TEACHER FUNCTION
void TeacherAssignStudent();
void TeacherViewTextbook();
void TeacherLogin();
void TeacherViewProfile(string id);
void TeacherViewStudent(string id);
void TeacherViewStudentPenalty(string id);
void TeacherMenu(string id);

//STUDENT FUNCTION
void StudentLogin();
void StudentViewProfile(string id);
void StudentViewListTextbook(string id);
void StudentViewListPenalty(string id);
void StudentMenu(string id);

//DONE
int main()
{
    int role;
    cout << "\n\n\n\n\n\n";
    cout << setw(120) << "WELCOME TO E-SPBT SYSTEM \n\n";
    cout << setw(116) << "List of roles \n\n\n";
    cout << setw(115) << "1) Admin SPBT \n"; //~ALMOST DONE
    cout << setw(112) << "2) Teacher \n";
    cout << setw(115) << "3) Student \n\n\n\n";

    cout << setw(110) << "Your role: ";
    cin >> role;

    system("cls");

    //ADMIN
    if (role == 1) {
        int adminAction;

        cout << "\n\n\n\n\n\n";
        cout << setw(110) << "ADMIN\n";
        cout << "\n";
        cout << setw(116) << "List of action:\n";
        cout << setw(114) << "1) Log in \n";
        cout << setw(115) << "2) Sign up \n"; //DONE

        cout << "\n\n\n";
        cout << setw(115) << "Your action: ";
        cin >> adminAction;

        system("cls");

        //ADMIN: LOG IN
        if (adminAction == 1) {
            AdminLogin();
        }
        

        //ADMIN: SIGN UP DONE
        else if (adminAction == 2) {
            AdminInsertData();
        }
    }

    //TEACHER
    else if (role == 2) {
        TeacherLogin();
    }

    //STUDENT
    else if (role == 3) {
        StudentLogin();
    }

    else {
        cout << "Try again! You are entering wrong number!";
        main();
    }

}


//ADMIN: LOGIN 
void AdminLogin() {
    system("cls");
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(116) << "Login Staff SPBT\n\n";
    cout << "\n";

    cout << "\n\n\n";
    cout << setw(160) << "Please enter the data below. If you are from registering process, welcome! You already registered to this system!\n";
    admin* Admin = new admin();

    cout << "\n";
    cout << setw(100) << "Staff ID [eg: ADMIN1234]: ";
    cin >> Admin->spbt_id;

    cout << setw(99) << "Password: ";

    //* password
    char ch;
    while ((ch = _getch()) != 13)
    {
        Admin->admin_password += ch;
        cout << '*';
    }
    cin.ignore(); //detect enter after entering password
       
    string id = Admin->spbt_id;

    adminManager AdminManager;
    int status = AdminManager.loginAdmin(Admin);

    if (status == 1) {
        AdminMainMenu(id);
    }

    else {
        
        system("cls");
        cout << "\n\n\n";
        cout << setw (125) << "Try again! ID and Pasword are wrong!";   
        AdminLogin();
        
    }

}

//ADMIN: VIEW ADMIN PROFILE DONE EVERYTHING
void AdminViewProfile(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(117) << "e-SPBT SYSTEM\n";
    cout << setw(119) << "ADMIN: My Profile\n\n";
    cout << "\n";

    admin* Admin = new admin();
    Admin->spbt_id = id;
    
    //Admin->spbt_id = id;
    adminManager AdminManager;
    AdminManager.viewAdminData(Admin);

}

//ADMIN: INSERT DATA ADMIN DONE
void AdminInsertData() {
    cout << "\n\n\n\n\n\n";
    cout << setw(117) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "Registering Staff SPBT\n\n";
    cout << "\n";

    cout << setw(130) << "READ: Note for Gender and Role choice.\n";
    cout << setw(118) << "Gender: F=Female \n" << setw(115) << "M=Male\n";
    cout << "\n";
    cout << setw(115) << "Role: A=Stock \n" << setw(125) << "B=Handle Students \n" << setw(128) << "C=Handle Class/Teacher";

    cout << "\n\n\n";
    cout << setw(119) << "Fill up the form below.\n";
    admin* Admin = new admin();
    
    cout << "\n";
    cout << setw(100) << "Staff ID [eg: ADMIN1234]: ";
    cin >> Admin->spbt_id;

    cout << setw(100) << "Name: ";
    cin.ignore();
    getline(cin, Admin->admin_name);

    cout << setw(99) << "Password: ";
    cin >> Admin->admin_password;

    cout << setw(99) << "Gender [F/M]: ";
    cin >> Admin->gender;

    cout << setw(100) << "Phone Num: ";
    cin >> Admin->admin_phonenum;

    cout << setw(100) << "Role [A/B/C]: ";
    cin >> Admin->role;

    adminManager AdminManager;
    int status = AdminManager.insertAdminData(Admin);

    if (status != 0)
        cout << setw(120) << "\n\nFailed to register account!." << endl;
    else {
        cout << setw(120) << "\n\nYou are registered!." << endl;
        AdminLogin();
    }
}

//ADMIN: INSERT TEXTBOOK DONE
void AdminInsertTextbook(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: Register new textbook\n\n";
    cout << "\n";

    cout << "\n\n\n";
    cout << setw(119) << "Fill up the form below.\n";

    cout << "\n\n";
    textbook* Textbook = new textbook();
    cout << setw(100) << "Textbook ID: ";
    cin >> Textbook->textbook_id;

    cout << setw(100) << "Name: ";
    cin.ignore();
    getline(cin, Textbook->textbook_name);

    cout << setw(100) << "Year Publish: ";
    cin >> Textbook->date;

    cout << setw(100) << "Publisher: ";
    cin.ignore();
    getline(cin, Textbook->publisher);

    cout << setw(100) << "Stock: ";
    cin >> Textbook->stock;

    cout << setw(100) << "Price: ";
    cin >> Textbook->price;

    cout << setw(102) << "Amount Lost: RM";
    cin >> Textbook->amountlost;

    cout << setw(100) << "Form [eg: F3 for Form 3]: ";
    cin >> Textbook->yearform;

    Textbook->spbt_id = id;

    adminManager AdminManager;
    int status = AdminManager.insertTextBookData(Textbook);

    if (status != 0)
        cout << setw(100) << "\n\nFailed to add new textbook!." << endl;
    else
        cout << setw(100) << "\n\nNew textbook already registered in system!." << endl;
}

//ADMIN: INSERT DATA TEACHER DONE
void AdminRegisterTeacher() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: Register teacher\n\n";
    cout << "\n";

    cout << setw(130) << "READ: Note for Gender choice.\n";
    cout << setw(118) << "Gender: F=Female \n" << setw(115) << "M=Male\n";
    cout << "\n";

    cout << "\n\n\n";
    cout << setw(119) << "Fill up the form below.\n";

    cout << "\n\n";

    teacher* Teacher = new teacher();
    cout << setw(100) << "Teacher ID [eg:TEACHER123]: ";
    cin >> Teacher->teacher_id;

    cout << setw(100) << "Name: ";
    cin.ignore();
    getline(cin, Teacher->teacher_name);

    cout << setw(100) << "Password: ";
    cin >> Teacher->teacher_password;

    cout << setw(100) << "Gender [F/M]: ";
    cin >> Teacher->teacher_gender;

    cout << setw(100) << "Phone Num: ";
    cin >> Teacher->teacher_phonenum;

    adminManager AdminManager;
    int status = AdminManager.insertTeacherData(Teacher);

    if (status != 0)
        cout << setw(100) << "\n\nFailed to register account!." << endl;
    else
        cout << setw(100) << "\n\nTeacher already registered!." << endl;
}

//ADMIN: REGISTER STUDENT DONE
void AdminRegisterStudent() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: Register student\n\n";
    cout << "\n";

    cout << setw(130) << "READ: Note for Gender choice.\n";
    cout << setw(118) << "Gender: F=Female \n" << setw(115) << "M=Male\n";
    cout << "\n";

    cout << "\n\n\n";
    cout << setw(119) << "Fill up the form below.\n";

    cout << "\n\n";

    student* Student = new student();
    cout << setw(100) << "IC Number [eg:000928110087]: ";
    cin >> Student->nric;

    cout << setw(100) << "Name: ";
    cin.ignore();
    getline(cin, Student->student_name);

    cout << setw(100) << "Date of Birth [YYYY-MM-DD]: ";
    cin >> Student->dob;

    cout << setw(100) << "Password: ";
    cin >> Student->student_password;

    cout << setw(100) << "Year Register School: ";
    cin >> Student->year;

    cout << setw(100) << "Phone Num: ";
    cin >> Student->student_phonenum;

    cout << setw(100) << "Gender [F/M]: ";
    cin >> Student->gender;

    adminManager AdminManager;
    int status = AdminManager.insertStudentData(Student);

    if (status != 0)
        cout << setw(100) << "\n\nFailed to register account!." << endl;
    else
        cout << setw(100) << "\n\nStudent already registered!." << endl;

}

//ADMIN: REGISTER CLASS DONE
void AdminRegisterClass(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: Register class\n\n";
    cout << "\n";

    cout << "\n\n\n";
    cout << setw(119) << "Fill up the form below.\n";

    cout << "\n\n";

    classes* Classes = new classes();
    cout << setw(100) << "Class ID [eg: FORM+CLASSNAME+YEAR -> MELATI2019]: ";
    cin >> Classes->class_id;

    cout << setw(100) << "Name [eg: 5 MELATI]: ";
    cin.ignore();
    getline(cin, Classes->class_name);


    cout << setw(100) << "Teacher ID: ";
    cin >> Classes->teacher_id;

    Classes->spbt_id = id;

    adminManager AdminManager;
    int status = AdminManager.insertClassData(Classes);

    if (status != 0)
        cout << setw(100) << "\n\nFailed to register account!." << endl;
    else
        cout << setw(100) << "\n\nClass already registered!." << endl;

}

//ADMIN: VIEW TEXTBOOK DONE
void AdminViewTextbook() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: View list of textbook\n\n";
    cout << "\n\n";

    textbook* Textbook = new textbook();

    adminManager AdminManager;
    AdminManager.viewTextBookData(Textbook);
}

//ADMIN: SEARCH TEXTBOOK DONE
void AdminSearchTextbook() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: Find textbook\n\n";
    cout << "\n\n";

    cout << "\n\n\n";
    cout << setw(128) << "Find textbook based on Textbook ID.\n";

    textbook* Textbook = new textbook();

    cout << "\n\n";
    cout << setw(112) << "Textbook ID: ";
    cin >> Textbook->textbook_id;

    cout << "\n\n";

    adminManager AdminManager;
    AdminManager.findTextBookData(Textbook);
}

//ADMIN: UPDATE TEXTBOOK DONE
void AdminUpdateTextbook(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: Update textbook data\n\n";
    cout << "\n";

    cout << "\n\n\n";
    cout << setw(119) << "Fill up the form below.\n";

    cout << "\n\n";
    textbook* Textbook = new textbook();
    cout << setw(100) << "Textbook ID: ";
    cin >> Textbook->textbook_id;

    cout << setw(100) << "Name: ";
    cin.ignore();
    getline(cin, Textbook->textbook_name);

    cout << setw(100) << "Year Publish: ";
    cin >> Textbook->date;

    cout << setw(100) << "Publisher: ";
    cin.ignore();
    getline(cin, Textbook->publisher);

    cout << setw(100) << "Stock: ";
    cin >> Textbook->stock;

    cout << setw(100) << "Price: ";
    cin >> Textbook->price;

    Textbook->spbt_id = id;

    adminManager AdminManager;
    int status = AdminManager.updateTextBookData(Textbook);

    if (status != 0)
        cout << setw(100) << "\n\nFailed to update textbook data!." << endl;
    else
        cout << setw(100) << "\n\nNew textbook already updated in system!." << endl;
}

//ADMIN: INSERT NEW RETURN GET TEXTBOOK (TOLAK STOCK TEXTBOOK) DONE AUTO INCREMENT DALAM MYSQL DONE
void AdminInsertReturnGet() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(127) << "ADMIN: Register new return get textbook\n\n";
    cout << "\n";

    cout << setw(120) << "READ: Note for status.\n";
    cout << setw(118) << "Status: 0=Return \n" << setw(115) << "1=Take\n" << setw(118) << "2=Penalty\n" << setw(115) << "3=Hold\n";
    cout << "\n";

    cout << "\n\n\n";
    cout << setw(119) << "Fill up the form below.\n";

    cout << "\n\n";
    returnget* ReturnGet = new returnget();
    cout << setw(100) << "Return Get ID [eg: IC+TEXTBOOKID]: ";
    cin >> ReturnGet->returnget_id;

    cout << setw(100) << "Date Get [YYYY-MM-DD]: ";
    cin >> ReturnGet->date_get;

    cout << setw(100) << "Status Get: ";
    cin >> ReturnGet->status_get;

    cout << setw(100) << "Textbook ID: ";
    cin >> ReturnGet->textbook_id;

    cout << setw(102) << "NRIC: ";
    cin >> ReturnGet->nric;

    adminManager AdminManager;
    int status = AdminManager.insertReturnGetTextbook(ReturnGet);
   
    if (status != 0)
        cout << setw(100) << "\n\nFailed to add new data of return get textbook!." << endl;
    else
        cout << setw(100) << "\n\nNew data of return get textbook already registered in system!." << endl;

}

//ADMIN: UPDATE RETURN GET TEXTBOOK (TAMBAH STOCK TEXTBOOK) DONE AUTO DECREMENT DALAM MYSQL
void AdminUpdateReturnGet() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(127) << "ADMIN: Update new return get textbook\n\n";
    cout << "\n";

    cout << setw(120) << "READ: Note for status.\n";
    cout << setw(118) << "Status: 0=Return \n" << setw(115) << "1=Take\n" << setw(118) << "2=Penalty\n" << setw(115) << "3=Hold\n";
    cout << "\n";

    cout << "\n\n\n";
    cout << setw(119) << "Fill up the form below.\n";

    cout << "\n\n";
    returnget* ReturnGet = new returnget();
    cout << setw(100) << "Return Get ID [eg: IC+TEXTBOOKID]: ";
    cin >> ReturnGet->returnget_id;

    cout << setw(100) << "Date Return [YYYY-MM-DD]: ";
    cin >> ReturnGet->date_return;

    cout << setw(100) << "Status Return: ";
    cin >> ReturnGet->status_return;

    adminManager AdminManager;
    int status = AdminManager.updateReturnGetTextbook(ReturnGet);

    if (status != 0)
        cout << setw(100) << "\n\nFailed to update data of return get textbook!." << endl;
    else
        cout << setw(100) << "\n\nReturn get textbook data already updated in system!." << endl;
}

//ADMIN: VIEW RETURN GET TEXTBOOK (need to fix by adding year, its much better to find it)
void AdminViewReturnGet() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: View list of return get\n\n";
    cout << "\n\n";

    returnget* ReturnGet = new returnget();

    adminManager AdminManager;
    AdminManager.viewReturnGetTextbook(ReturnGet);
}

//ADMIN: FIND RETURN GET TEXTBOOK
void AdminFindReturnGet() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: Find list of return get\n\n";
    cout << "\n\n";

    cout << "\n\n\n";
    cout << setw(119) << "Find data about return textbook by using NRIC.\n";

    returnget* ReturnGet = new returnget();

    cout << setw(100) << "NRIC: ";
    cin >> ReturnGet->nric;

    cout << "\n\n\n";
    adminManager AdminManager;
    AdminManager.findReturnGetTextbook(ReturnGet);
}

//ADMIN: INSERT NEW PENALTY TO STUDENT DONE EVERYTHING
void AdminPenaltyStudent() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: Penalty Student\n\n";
    cout << "\n";

    cout << "\n\n";
    penalty* Penalty = new penalty();
    cout << setw(100) << "Return Get ID [eg: IC+TEXTBOOKID]: ";
    cin >> Penalty->returnget_id;

    adminManager AdminManager;
    int status = AdminManager.insertPenaltyTextbook(Penalty);

}

//ADMIN: CONFIRM PENALTY STUDENT DONE EVERYTHING
void AdminConfirmPenaltyStudent() {
    penalty* Penalty = new penalty();
    cout << "\n\n\n";
    cout << setw(125) << "Please enter again for confirmation" << endl;
    cout << setw(100) << "Return Get ID [eg: IC+TEXTBOOKID]: ";
    cin >> Penalty->returnget_id;

    adminManager AdminManager;
    int status = AdminManager.confirmPenaltyTextbook(Penalty);

    cout << "\n\n";

    if (status != 0)
        cout << setw(115) << "Failed to confirm!." << endl;
    else
        cout << setw(115) << "Already confirm!." << endl;
}

//ADMIN: VIEW PENALTY STUDENT DONE EVERYTHING
void AdminViewPenaltyStudent() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: View list of penalty\n\n";
    cout << "\n\n";

    penalty* Penalty = new penalty();

    adminManager AdminManager;
    AdminManager.viewPenaltyTextbook(Penalty);
}

//ADMIN: FIND PENALTY STUDENT DONE EVERYTHING
void AdminFindPenaltyStudent() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "ADMIN: Find penalty based on NRIC\n\n";
    cout << "\n\n";

    penalty* Penalty = new penalty();

    cout << "\n\n\n";
    cout << setw(119) << "Find data about penalty by using NRIC.\n";

    cout << setw(100) << "NRIC: ";
    cin >> Penalty->nric;

    adminManager AdminManager;
    AdminManager.findPenaltyTextbook(Penalty);
}

//ADMIN: REPORT
void AdminReport() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(117) << "ADMIN: View Report\n\n";
    cout << "\n\n";

    adminManager AdminManager;
    cout << setw(127) << "TOTAL ALL OF PROCESS GET AND RETURN TEXTBOOK" << endl;
    AdminManager.ReportSuccessGet();
    AdminManager.ReportSuccessReturn();
    AdminManager.ReportPenalty();
    AdminManager.ReportPenalty2();
    cout << "\n\n\n\n";
    cout << setw(110) << "TEXTBOOK" << endl;
    AdminManager.ReportTextbook();
    cout << "\n\n\n\n";
    cout << setw(108) << "CLASS" << endl;
    AdminManager.ReportStudent();
}

//ADMIN: MENU TEXTBOOK DONE EVERYTHING
void AdminMenuTextbook(string id){
    char admintextbookmenu;
    string idadmin = id;

        cout << "\n\n\n\n\n\n";
        cout << setw(115) << "e-SPBT SYSTEM\n";
        cout << setw(122) << "ADMIN: Textbook Menu \n\n";

        cout << setw(118) << "List of action: \n";
        cout << setw(121) << "1)View List Textbook\n"; //DONE
        cout << setw(116) << "2)Find Textbook\n"; //DONE
        cout << setw(118) << "3)Insert Textbook\n"; //DONE
        cout << setw(118) << "4)Update Textbook\n"; //done
        cout << setw(112) << "5)Main Menu\n";
        cout << setw(110) << "6)Log Out\n";

        int textbookchoice;
        cout << "\n\n\n";
        cout << setw(116) << "Your Action: ";
        cin >> textbookchoice;

        system("cls");

        char choiceMenuTextbook;

        do {
            //ADMIN: VIEW TEXTBOOK LIST
            if (textbookchoice == 1) {
                AdminViewTextbook();
            }

            //ADMIN: FIND TEXTBOOK
            else if (textbookchoice == 2) {
                AdminSearchTextbook();
            }

            //ADMIN: INSERT TEXTBOOK DONE
            else if (textbookchoice == 3) {
                AdminInsertTextbook(idadmin);
            }

            //ADMIN: UPDATE TEXTBOOK
            else if (textbookchoice == 4) {
                AdminUpdateTextbook(id);
            }

            else if (textbookchoice == 5) {
                AdminMainMenu(id);
            }

            else if (textbookchoice == 6) {
                AdminLogin();
            }

            else {
               cout << setw(120) << "Wrong number! Please enter the number based on list!";
               AdminMenuTextbook(id);
            }
             
            cout << "\n\n\n";
            cout << setw(120) << "Do you wish to continue at this part?" << endl;
            cout << setw(125) << "If YES, type Y. If NO, just type any alphabet." << endl;
            cout << setw(110) << "Your choice: ";
            cin >> choiceMenuTextbook;
            system("cls");

            } while (choiceMenuTextbook == 'Y' || choiceMenuTextbook == 'y');
            
        AdminMenuTextbook(id);
}

//ADMIN: MENU PENALTY DONE EVERYTHING
void AdminMenuPenalty(string id) {
    system("cls");
    char adminpenaltymenu, choiceMenuPenalty;
    int penaltychoice, adminanotheraction;

        cout << "\n\n\n\n\n\n";
        cout << setw(115) << "e-SPBT SYSTEM\n";
        cout << setw(118) << "ADMIN: Penalty \n\n";

        cout << setw(118) << "List of action: \n";
        cout << setw(122) << "1)View List Penalty\n";
        cout << setw(117) << "2)Find Receipt\n";
        cout << setw(116) << "3)New Penalty\n";
        cout << setw(114) << "4)Main Menu\n";
        cout << setw(112) << "5)Log Out\n";

        cout << "\n\n\n";
        cout << setw(116) << "Your choice: ";
        cin >> penaltychoice;

        system("cls");
        do {
            if (penaltychoice == 1) {
                AdminViewPenaltyStudent();
            }
            else if (penaltychoice == 2) {
                AdminFindPenaltyStudent();
            }
            else if (penaltychoice == 3) {
                AdminPenaltyStudent();
                AdminConfirmPenaltyStudent();
            }
            else if (penaltychoice == 4) {
                AdminMainMenu(id);
            }

            else if (penaltychoice == 5) {
                AdminLogin();
            }

            else {
                cout << setw(124) << "Try again! You are entering the wrong number!" << endl;
                AdminMenuPenalty(id);
            }

        cout << "\n\n";
        cout << setw(120) << "Do you wish to continue at this part?" <<endl;
        cout << setw(123) << "If YES, type Y. If NO, just type any alphabet." << endl;
        cout << setw(110) << "Your choice: " ;
        cin >> choiceMenuPenalty;
        system("cls");

        } while (choiceMenuPenalty == 'Y' || choiceMenuPenalty == 'y');
        AdminMenuPenalty(id);
}

//ADMIN: MENU RETURNGET TEXTBOOK DONE EVERYTHING
void AdminMenuReturnGet(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(115) << "e-SPBT SYSTEM\n";
    cout << setw(120) << "ADMIN: Return Get Textbook";

    cout << "\n\n";

    cout << setw(116) << "List of action:" << endl;
    cout << setw(122) << "1)View List Return Get" << endl;
    cout << setw(126) << "2)Find Return Get Textbook" << endl;
    cout << setw(123) << "3)Insert New Return Get" << endl;
    cout << setw(119) << "4)Update Return Get" << endl;
    cout << setw(111) << "5)Main Menu" << endl;
    cout << setw(109) << "6)Log Out" << endl;

    int returngetchoice;
    char option;
    cout << "\n\n\n";
    cout << setw(112) << "Your Action: ";
    cin >> returngetchoice;

    system("cls");
    do {
        if (returngetchoice == 1) {
            AdminViewReturnGet();
        }

        else if (returngetchoice == 2) {
            AdminFindReturnGet();
        }

        else if (returngetchoice == 3) {
            AdminInsertReturnGet();
        }

        else if (returngetchoice == 4) {
            AdminUpdateReturnGet();
        }

        else if (returngetchoice == 5) {
            AdminMainMenu(id);
        }

        else if (returngetchoice == 6) {
            AdminLogin();
        }

        else {
            cout << "Wrong number! Please enter again then number based on list!";
            AdminMenuReturnGet(id);
        }

        cout << "\n\n";
        cout << setw(120) << "Do you wish to continue at this part?" << endl;
        cout << setw(123) << "If YES, type Y. If NO, just type any alphabet." << endl;
        cout << setw(110) << "Your choice: ";
        cin >> option;
        system("cls");
    } while (option == 'Y' || option == 'y');

    AdminMenuReturnGet(id);
}

//ADMIN: MENU REGISTER DONE EVERYTHING
void AdminMenuRegister(string id) {
    char adminregisterchoice;

    int registerchoice;
    cout << "\n\n\n\n\n\n";
    cout << setw(120) << "e-SPBT SYSTEM\n";
    cout << setw(124) << "ADMIN: Register Account" <<endl <<endl;

    cout << setw(120) << "Register Account:" << endl;
    cout << setw(116) << "1)Teacher" << endl;
    cout << setw(114) << "2)Class" << endl;
    cout << setw(120) << "3)New Student" << endl;
    cout << setw(118) << "4)Main Menu" << endl;
    cout << setw(116) << "5)Log Out" << endl;

    cout << "\n\n";
    cout << setw(120) << "Your choice: ";
    cin >> registerchoice;

    system("cls");

    char registermenuchoice;

    do {
        //REGISTER: TEACHER DONE 
        if (registerchoice == 1) {
            AdminRegisterTeacher();
        }

        //REGISTER: CLASS DONE
        else if (registerchoice == 2) {
            AdminRegisterClass(id);
        }

        else if (registerchoice == 3) {
            AdminRegisterStudent();
        }

        else if (registerchoice == 4) {
            AdminMainMenu(id);
        }

        else if (registerchoice == 5) {
            AdminLogin();
        }

        else {
            cout << setw(120) << "Wrong number! Please enter again then number based on list!" <<endl;
            AdminMenuRegister(id);
        }

        cout << setw(120) << "\nDo you wish to continue this part?" << endl;
        cout << setw(120) << "\nIf YES, type Y. If NO, just type any alphabet." << endl;
        cout << setw(120) << "\nYour choice: ";
        cin >> registermenuchoice;

        system("cls");
    } while (registermenuchoice == 'Y' || registermenuchoice == 'y');
    AdminMainMenu(id);
}

//ADMIN: MAIN MENU DONE EVERYTHING
void AdminMainMenu(string id) {
    system("cls");

    int adminAccountAction, adminanotherchoice;
    char adminmenuchoice, adminsubmenuchoice;


    //DONE PERBAIKI OUTPUT
    cout << "\n\n\n\n\n\n";
    cout << setw(113) << "e-SPBT SYSTEM\n\n";
    cout << setw(115) << "Admin Account \n\n\n";

    cout << setw(113) << "List of action:" << endl;
    cout << setw(115) << "1)View My Profile" << endl; //DONE EVERYTHING
    cout << setw(107) << "2)Penalty" << endl; //DONE EVERYTHING
    cout << setw(108) << "3)Textbook" << endl; //DONE EVERYTHING
    cout << setw(119) << "4)Return Get Textbook" << endl; //DONE DONE EVERYTHING
    cout << setw(106) << "5)Report" << endl;
    cout << setw(116) << "6)Register Account" << endl; //DONE EVERYTHING
    cout << setw(107) << "7)Log Out" << endl; //DONE EVERYTHING

    cout << "\n\n\n";
    cout << setw(112) << "Your Role: ";
    cin >> adminAccountAction;

    system("cls");

    //ADMIN: VIEW PROFILE
    if (adminAccountAction == 1) {
        AdminViewProfile(id);

        cout << "\n\n\n";
        cout << setw(135) << "Do you wish to go to main menu? Or want to exit this system?" << endl;
        cout << setw(145) << "Type 1 if you to go to main menu, otherwise, just type anything to exit the system." << endl;
        cout << "\n\n";
        cout << setw(115) << "Your choice: ";
        cin >> adminanotherchoice;

        if (adminanotherchoice == 1) {
            AdminMainMenu(id);
        }
    }

    //ADMIN:PENALTY CLASS
    else if (adminAccountAction == 2) {
        AdminMenuPenalty(id);
    }

    //ADMIN: TEXTBOOK (KENA MODIFY OUTPUT EACH SUBMENU DULU) DONE
    else if (adminAccountAction == 3) {
        AdminMenuTextbook(id);
    }

    //ADMIN: RETURN GET DONDE
    else if (adminAccountAction == 4) {
        AdminMenuReturnGet(id);
    }

    //ADMIN: REPORT
    else if (adminAccountAction == 5) {
        AdminReport();

        cout << "\n\n\n";
        cout << setw(135) << "Do you wish to go to main menu? Or want to exit this system?" << endl;
        cout << setw(145) << "Type 1 if you to go to main menu, otherwise, just type anything to exit the system." << endl;
        cout << "\n\n";
        cout << setw(115) << "Your choice: ";
        cin >> adminanotherchoice;

        if (adminanotherchoice == 1) {
            AdminMainMenu(id);
        }
    }

    //ADMIN: REGISTER ACCOUNT DONE (kena modify sikit width)
    else if (adminAccountAction == 6) {
       AdminMenuRegister(id);
    }

    else if (adminAccountAction == 7) {
        main();
    }

    else {
       cout << setw(120) << "Wrong number! Please enter again then number based on list!";
       AdminMainMenu(id);
    }
}


//TEACHER: LOG IN
void TeacherLogin() {
    cout << "\n\n\n\n\n\n";
    cout << setw(110) << "TEACHER\n";
    cout << "\n";
    cout << setw(116) << "Log In Account\n";

    cout << "\n\n\n";
    cout << setw(119) << "Please enter the data below.\n";
    teacher* Teacher = new teacher();

    cout << "\n";
    cout << setw(100) << "Teacher ID [eg: TEACHER1234]: ";
    cin >> Teacher->teacher_id;

    cout << setw(99) << "Password: ";

    //* password
    char ch;
    while ((ch = _getch()) != 13)
    {
        Teacher->teacher_password+= ch;
        cout << '*';
    }
    cin.ignore();

    string id = Teacher->teacher_id;

    adminManager AdminManager;
    int status = AdminManager.loginTeacher(Teacher);
    int login;

    system("cls");
    if (status == 1) {
        TeacherMenu(id);
    }

    else {
        system("cls");
        cout << "Try again! ID and Pasword are wrong!";
        TeacherLogin();
    }
}

//TEACHER: ASSIGN STUDENT
void TeacherAssignStudent() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "TEACHER: Assign student to my class\n\n";
    cout << "\n";

    cout << "\n\n\n";
    cout << setw(119) << "Fill up the form below.\n";

    cout << "\n\n";
    student_class* Student_Class = new student_class();
 
    cout << setw(100) << "Student IC: ";
    cin >> Student_Class->nric;

    cout << setw(100) << "Class ID: ";
    cin >> Student_Class->class_id;

    cout << setw(100) << "Current Year: ";
    cin >> Student_Class->year;

    adminManager AdminManager;
    int status = AdminManager.insertStudentDataBridge(Student_Class);

    cout << "\n\n";

    if (status != 0)
        cout << setw(100) << "Failed to assign your student!." << endl;
    else
        cout << setw(100) << "Student already in your class!." << endl;
}

//TEACHER: VIEW TEXTBOOK DONE
void TeacherViewTextbook() {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "TEACHER: View list of textbook\n\n";
    cout << "\n\n";

    textbook* Textbook = new textbook();

    adminManager AdminManager;
    AdminManager.viewTextBookData(Textbook);
}

//TEACHER: VIEW PROFILE DONE EVERYTHING
void TeacherViewProfile(string id) {
    system("cls");

    cout << "\n\n\n\n\n\n";
    cout << setw(117) << "e-SPBT SYSTEM\n";
    cout << setw(120) << "TEACHER: My Profile\n\n";
    cout << "\n";

    teacher* Teacher = new teacher();
    Teacher->teacher_id = id;

    //Admin->spbt_id = id;
    adminManager AdminManager;
    AdminManager.viewTeacherData(Teacher);
}

//TEACHER: VIEW STUDENT LIST DONE EVERYTHING
void TeacherViewStudent(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(122) << "TEACHER: List Of My Student\n\n";
    cout << "\n";

    teacher* Teacher = new teacher();
    Teacher->teacher_id = id;

    //Admin->spbt_id = id;
    adminManager AdminManager;
    AdminManager.viewStudentData1(Teacher);
}

//TEACHER: VIEW STUDENT PENALTY DONE EVERYTHING
void TeacherViewStudentPenalty(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(114) << "e-SPBT SYSTEM\n";
    cout << setw(128) << "TEACHER: List Of My Student that have penalty\n\n";
    cout << "\n";

    teacher* Teacher = new teacher();
    Teacher->teacher_id = id;

    adminManager AdminManager;
    AdminManager.viewTeacherStudentPenaltyData(Teacher);
}

//TEACHER: MAIN MENU DONE EVERYTHING
void TeacherMenu(string id) {
    system("cls");
    int teacherAccountAction, teacheroption;
    cout << "\n\n\n\n\n\n";
    cout << setw(119) << "e - SPBT SYSTEM\n\n";
    cout << setw(121) << "Teacher Account \n\n\n";

    cout << setw(120) << "List of action: \n";
    cout << setw(120) << "1)View My Profile\n";
    cout << setw(125) << "2)List of penalty students\n";
    cout << setw(120) << "3)List Of My Student\n"; 
    cout << setw(125) << "4)Assign student to my class\n"; //DONE
    cout << setw(115) << "5)Log Out\n";

    cout << "\n\n\n";
    cout << setw(115) << "Your choice: ";
    cin >> teacherAccountAction;

    system("cls");

    //TEACHER: VIEW PROFILE //DONE (modify output)
    if (teacherAccountAction == 1) {
        TeacherViewProfile(id);

        cout << "\n\n\n";
        cout << setw(135) << "Do you wish to go to main menu? Or want to exit this system?" << endl;
        cout << setw(145) << "Type 1 if you to go to main menu, otherwise, just type anything to exit the system." << endl;
        cout << "\n\n";
        cout << setw(115) << "Your choice: ";
        cin >> teacheroption;

        if (teacheroption == 1) {
            TeacherMenu(id);
        }
    }

    //TEACHER: PENALTY
    else if (teacherAccountAction == 2) {
        TeacherViewStudentPenalty(id);

        cout << "\n\n\n";
        cout << setw(135) << "Do you wish to go to main menu? Or want to exit this system?" << endl;
        cout << setw(145) << "Type 1 if you to go to main menu, otherwise, just type anything to exit the system." << endl;
        cout << "\n\n";
        cout << setw(115) << "Your choice: ";
        cin >> teacheroption;

        if (teacheroption == 1) {
            TeacherMenu(id);
        }
    }

    //TEACHER: STUDENTS
    else if (teacherAccountAction == 3) {
        TeacherViewStudent(id);

        cout << "\n\n\n";
        cout << setw(135) << "Do you wish to go to main menu? Or want to exit this system?" << endl;
        cout << setw(145) << "Type 1 if you to go to main menu, otherwise, just type anything to exit the system." << endl;
        cout << "\n\n";
        cout << setw(115) << "Your choice: ";
        cin >> teacheroption;

        if (teacheroption == 1) {
            TeacherMenu(id);
        }
    }

    //TEACHER: ASSIGN STUDENT // KENA PERBAIKI OUTPUT, JUST KENA MASUKKAN YEAR, TARIK ID TEACHER
    else if (teacherAccountAction == 4) {
        do {
            system("cls");
            TeacherAssignStudent();
            cout << setw(135) << "Do you wish to go to continue this part?" << endl;
            cout << setw(145) << "Type 1 if you want to continue, otherwise, just type anything to go the main menu." << endl;
            cout << "\n\n";
            cout << setw(115) << "Your choice: ";
            cin >> teacheroption;
        } while (teacheroption == 1);

        TeacherMenu(id);
    }

    //TEACHER: LOG OUT
    else if (teacherAccountAction == 5) {
        main();
    }
}


//STUDENT: LOG IN
void StudentLogin() { 
    system("cls");

    cout << "\n\n\n\n\n\n";
    cout << setw(110) << "STUDENT\n";
    cout << "\n";
    cout << setw(116) << "Log In Account\n";

    cout << "\n\n\n";
    cout << setw(119) << "Please enter the data below.\n";
    student* Student = new student();

    cout << "\n";
    cout << setw(100) << "IC Number (without -): ";
    cin >> Student->nric;

    cout << setw(99) << "Password: ";

    //* password
    char ch;
    while ((ch = _getch()) != 13)
    {
        Student->student_password += ch;
        cout << '*';
    }
    cin.ignore();

    string id = Student->nric;

    adminManager AdminManager;
    int status = AdminManager.loginStudent(Student);

    system("cls");

    if (status == 1) {
        StudentMenu(id);
    }

    else {
        cout << setw (120) << "Wrong IC and Password!";
        StudentLogin();
    }
}

//STUDENTS: VIEW PROFILE
void StudentViewProfile(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(120) << "e - SPBT SYSTEM\n\n";
    cout << setw(125) << "STUDENT: View My Profile \n\n\n";

    student* Student = new student();
    Student->nric = id;

    adminManager AdminManager;
    AdminManager.viewStudentData(Student);
}

//STUDENTS: VIEW LIST TEXTBOOK
void StudentViewListTextbook(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(115) << "e - SPBT SYSTEM\n\n";
    cout << setw(121) << "STUDENT: List Textbook \n\n\n";

    returnget* ReturnGet = new returnget();
    ReturnGet->nric = id;

    adminManager AdminManager;
    AdminManager.viewTextBookStudent(ReturnGet);
}

//STUDENTS: VIEW LIST PENALTY
void StudentViewListPenalty(string id) {
    cout << "\n\n\n\n\n\n";
    cout << setw(115) << "e - SPBT SYSTEM\n\n";
    cout << setw(121) << "STUDENT: List Penalty \n\n\n";

    student* Student = new student();
    Student->nric = id;

    adminManager AdminManager;
    AdminManager.viewStudentPenaltyData(Student);
}

//STUDENTS: MAIN MENU
void StudentMenu(string id) {
    system("cls");
    int studchoice, studoption;
    cout << "\n\n\n\n\n\n";
    cout << setw(119) << "e - SPBT SYSTEM\n\n";
    cout << setw(121) << "Student Account \n\n\n";

    cout << setw(120) << "List of action: \n";
    cout << setw(120) << "1)View My Profile\n";
    cout << setw(115) << "2)Penalty\n";
    cout << setw(120) << "3)List of Textbook\n";
    cout << setw(115) << "4)Logout";

    cout << "\n\n\n";
    cout << setw(115) << "Your choice: ";
    cin >> studchoice;

    system("cls");

    if (studchoice == 1) {
        StudentViewProfile(id);

        cout << "\n\n\n";
        cout << setw(135) << "Do you wish to go to main menu? Or want to exit this system?" << endl;
        cout << setw(145) << "Type 1 if you to go to main menu, otherwise, just type anything to exit the system." << endl;
        cout << "\n\n";
        cout << setw(115) << "Your choice: ";
        cin >> studoption;

        if (studoption == 1) {
            StudentMenu(id);
        }

    }

    else if (studchoice == 2) {
        StudentViewListPenalty(id);

        cout << "\n\n\n";
        cout << setw(135) << "Do you wish to go to main menu? Or want to exit this system?" << endl;
        cout << setw(145) << "Type 1 if you to go to main menu, otherwise, just type anything to exit the system." << endl;
        cout << "\n\n";
        cout << setw(115) << "Your choice: ";
        cin >> studoption;

        if (studoption == 1) {
            StudentMenu(id);
        }
    }

    else if (studchoice == 3) {
        StudentViewListTextbook(id);

        cout << "\n\n\n";
        cout << setw(135) << "Do you wish to go to main menu? Or want to exit this system?" << endl;
        cout << setw(145) << "Type 1 if you to go to main menu, otherwise, just type anything to exit the system." << endl;
        cout << "\n\n";
        cout << setw(115) << "Your choice: ";
        cin >> studoption;

        if (studoption == 1) {
            StudentMenu(id);
        }
    }

    else if (studchoice == 4) {
        main();
    }

    else {
        cout << "Wrong number! Please enter again then number based on list!";
        StudentMenu(id);
    }
}




