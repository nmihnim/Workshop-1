#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "admin.h"
#include "teacher.h"
#include "textbook.h"
#include "classes.h"
#include "student.h"
#include "returnget.h"
#include "student_class.h"
#include "penalty.h"
#include "adminManager.h"


//ADMIN: LOGIN DONE EVERYTHING
int adminManager::loginAdmin(admin* Admin) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT SPBT_ID FROM admin WHERE SPBT_ID = ? AND ADMIN_PASSWORD = ?");

	ps->setString(1, Admin->spbt_id);
	ps->setString(2, Admin->admin_password);

	ResultSet* rs = ps->executeQuery();

	int status;
	while (rs->next()) {
		status = 1;
	}

	return status;
}

//ADMIN: VIEW ADMIN DATA DONE EVERYTHING
void adminManager::viewAdminData(admin* Admin) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT SPBT_ID, ADMIN_NAME, ADMIN_GENDER, ADMIN_PHONENUM, ROLE FROM ADMIN WHERE SPBT_ID = ?");

	ps->setString(1, Admin->spbt_id);
	ResultSet* rs = ps->executeQuery();

	cout << "\n\n\n";

	while (rs->next()) {
		cout << setw(110) << "SPBT ID: " << rs->getString("SPBT_ID") << endl;
		cout << setw(110) << "Name: " << rs->getString("ADMIN_NAME") << endl;
		cout << setw(110) << "Gender: " << rs->getString("ADMIN_GENDER") << endl;
		cout << setw(110) << "Phone Number: " << rs->getString("ADMIN_PHONENUM") << endl;
		cout << setw(110) << "Role: " << rs->getString("ROLE") << endl;
	}

	delete ps;
}

//ADMIN: INSERT NEW DATA DONE EVERYTHING
int adminManager::insertAdminData(admin* Admin) {
	DatabaseConnection dbConn;
		PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO admin VALUES (?, ?, ?, ?, ?, ?)");
		
	ps->setString(1, Admin->spbt_id);
	ps->setString(2, Admin->admin_name);
	ps->setString(3, Admin->admin_password);
	ps->setString(4, Admin->gender);
	ps->setInt(5, Admin->admin_phonenum);
	ps->setString(6, Admin->role);

	int status = ps->executeUpdate();
	delete ps;
	return 0;

}

//TEACHER: LOG IN DONE EVERYTHING
int adminManager::loginTeacher(teacher* Teacher) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT TEACHER_ID FROM teacher WHERE TEACHER_ID = ? AND TEACHER_PASSWORD = ?");

	ps->setString(1, Teacher->teacher_id);
	ps->setString(2, Teacher->teacher_password);

	ResultSet* rs = ps->executeQuery();

	int status;
	while (rs->next()) {
		status = 1;
	}

	return status;
}

//TEACHER: INSERT NEW DATA DONE EVERYTHING
int adminManager::insertTeacherData(teacher* Teacher) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO teacher VALUES (?, ?, ?, ?, ?)");

	ps->setString(1, Teacher->teacher_id);
	ps->setString(2, Teacher->teacher_name);
	ps->setString(3, Teacher->teacher_password);
	ps->setString(4, Teacher->teacher_gender);
	ps->setInt(5, Teacher->teacher_phonenum);

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//TEACHER: VIEW PROFILE DONE EVERYTHING
void adminManager::viewTeacherData(teacher* Teacher) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT TEACHER_ID, TEACHER_NAME, TEACHER_GENDER, TEACHER_PHONENUM FROM TEACHER WHERE TEACHER_ID = ?");

	ps->setString(1, Teacher->teacher_id);
	ResultSet* rs = ps->executeQuery();

	cout << "\n\n\n";

	while (rs->next()) {
		cout << setw(110) << "Teacher ID: " << rs->getString("TEACHER_ID") << endl;
		cout << setw(110) << "Name: " << rs->getString("TEACHER_NAME") << endl;
		cout << setw(110) << "Gender: " << rs->getString("TEACHER_GENDER") << endl;
		cout << setw(110) << "Phone Number: " << rs->getString("TEACHER_PHONENUM") << endl;
	}

	delete ps;
}

//TEACHER: VIEW STUDENT DONE EVERYTHING
void adminManager::viewStudentData1(teacher* Teacher) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT student_class.NRIC, student.STUDENT_NAME, class.CLASS_NAME, student_class.YEAR FROM student_class NATURAL JOIN student NATURAL JOIN class WHERE class.TEACHER_ID = ?;");

	ps->setString(1, Teacher->teacher_id);
	ResultSet* rs = ps->executeQuery();

	cout << "\n\n\n";

	cout << setw(40) << "IC" << setw(35) << "Name" << setw(35) << "Class" << setw(35) << "Year" << endl;

	while (rs->next()) {
		cout << setw(40) << rs->getString("NRIC") << setw(35) << rs->getString("STUDENT_NAME") << setw(35)
			<< rs->getString("CLASS_NAME") << setw(35) << rs->getString("YEAR") << endl;
	}

	delete ps;
}

//TEACHER: VIEW STUDENT PENALTY DONE EVERYTHING
void adminManager::viewTeacherStudentPenaltyData(teacher* Teacher) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT student_class.NRIC, student.STUDENT_NAME, class.CLASS_NAME,textbook.TEXTBOOK_NAME, student_class.YEAR FROM student_class NATURAL JOIN student NATURAL JOIN class NATURAL JOIN returnget NATURAL JOIN textbook WHERE class.TEACHER_ID = ? AND returnget.STATUS_RETURN = 2;");

	ps->setString(1, Teacher->teacher_id);
	ResultSet* rs = ps->executeQuery();

	cout << "\n\n\n";

	cout << setw(40) << "IC" << setw(35) << "Name" << setw(35) << "Class" << setw(35) << "Year" << setw(35) << "Textbook Name" << endl;

	while (rs->next()) {
		cout << setw(40) << rs->getString("NRIC") << setw(35) << rs->getString("STUDENT_NAME") << setw(35)
			<< rs->getString("CLASS_NAME") << setw(35) << rs->getString("YEAR") << setw(35) << rs->getString("TEXTBOOK_NAME") << endl;
	}

	delete ps;
}

//TEXTBOOK: INSERT NEW DATA DONE EVERYTHING
int adminManager::insertTextBookData(textbook* Textbook) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO textbook VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, Textbook->textbook_id);
	ps->setString(2, Textbook->textbook_name);
	ps->setString(3, Textbook->date);
	ps->setString(4, Textbook->publisher);
	ps->setInt(5, Textbook->stock);
	ps->setDouble(6, Textbook->price);
	ps->setDouble(7, Textbook->amountlost);
	ps->setString(8, Textbook->yearform);
	ps->setString(9, Textbook->spbt_id);

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//CLASS: INSERT NEW DATA DONE EVERYTHING
int adminManager::insertClassData(classes* Classes) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO class (CLASS_ID, CLASS_NAME, TEACHER_ID, SPBT_ID) VALUES (?, ?, ?, ?)");

	ps->setString(1, Classes->class_id);
	ps->setString(2, Classes->class_name);
	ps->setString(3, Classes->teacher_id);
	ps->setString(4, Classes->spbt_id);

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//STUDENTS: LOGIN DONE EVERYTHING
int adminManager::loginStudent(student* Student) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT NRIC FROM student WHERE NRIC = ? AND STUDENT_PASSWORD = ?");

	ps->setString(1, Student->nric);
	ps->setString(2, Student->student_password);

	ResultSet* rs = ps->executeQuery();

	int status;
	while (rs->next()) {
		status = 1;
	}

	return status;
}

//STUDENTS: INSERT NEW DATA DONE EVERYTHING 
int adminManager::insertStudentData(student* Student) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO student VALUES (?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, Student->nric);
	ps->setString(2, Student->student_name);
	ps->setString(3, Student->dob);
	ps->setString(4, Student->student_password);
	ps->setInt(5, Student->year);
	ps->setInt(6, Student->student_phonenum);
	ps->setString(7, Student->gender);

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//STUDENTS: BRIDGE INSERT NEW DATA DONE EVERYTHING
int adminManager::insertStudentDataBridge(student_class* Student_Class) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO student_class VALUES (?, ?, ?)");

	ps->setString(1, Student_Class->nric);
	ps->setString(2, Student_Class->class_id);
	ps->setInt(3, Student_Class->year);

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//STUDENTS: VIEW PROFILE DONE EVERYTHING
void adminManager::viewStudentData(student* Student) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT student_class.NRIC, student.STUDENT_NAME, student.DOB, student.YEAR_STARTSCHOOL, student.STUDENT_PHONENUM, student.GENDER, class.CLASS_NAME FROM ((student INNER JOIN student_class ON student.NRIC = student_class.NRIC) INNER JOIN class ON student_class.CLASS_ID = class.CLASS_ID) WHERE student.NRIC = ?;");

	ps->setString(1, Student->nric);
	ResultSet* rs = ps->executeQuery();

	cout << "\n\n\n";

	while (rs->next()) {
		cout << setw(110) << "IC Number: " << rs->getString("NRIC") << endl;
		cout << setw(110) << "Name: " << rs->getString("STUDENT_NAME") << endl;
		cout << setw(110) << "DOB: " << rs->getString("DOB") << endl;
		cout << setw(110) << "Gender: " << rs->getString("GENDER") << endl;
		cout << setw(110) << "Phone Number: " << rs->getString("STUDENT_PHONENUM") << endl;
		cout << setw(110) << "Batch: " << rs->getString("YEAR_STARTSCHOOL") << endl;
		cout << setw(110) << "Class: " << rs->getString("CLASS_NAME") << endl << endl;
	}
	

	delete ps;
}

//STUDENTS: VIEW PENALTY DATA DONE EVERYTHING
void adminManager::viewStudentPenaltyData(student* Student) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT penalty.RECEIPT_ID, penalty.TOTAL_PENALTY, penalty.DATE_PENALTY, returnget.RETURNGET_ID, returnget.TEXTBOOK_ID, textbook.TEXTBOOK_NAME FROM penalty NATURAL JOIN returnget NATURAL JOIN textbook WHERE returnget.NRIC = ?;");

	ps->setString(1, Student->nric);
	ResultSet* rs = ps->executeQuery();

	cout << "\n\n\n";
	cout << "Receipt ID" << setw(35) << "Total Penalty" << setw(35) << "Date Penalty" << setw(35) << "Return Get ID" << setw(35) << "Textbook ID" << setw(35) << "Textbook Name" << endl;

	while (rs->next()) {
		cout << setw(10) << rs->getString("RECEIPT_ID") << setw(35) << rs->getString("TOTAL_PENALTY") << setw(35) <<
			rs->getString("DATE_PENALTY") << setw(35) << rs->getString("RETURNGET_ID") << setw(35) << rs->getString("TEXTBOOK_ID") <<
			setw(35) << rs->getString("TEXTBOOK_NAME") << endl;
	}


	delete ps;
}


//TEXTBOOK: VIEW LIST TEXTBOOK DONE EVERYTHING
void adminManager::viewTextBookData(textbook* Textbook) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM textbook");

	ResultSet* rs = ps->executeQuery();
	cout << setw(20) << "Textbook ID " << setw(35) << "Textbook Name " << setw(30) <<
		"Year Publish " << setw(25) << "Publisher " << setw(33) << "Stock " <<
		setw(10) << "Price " << setw(18) << "Amount Lost " << setw(10) <<
		"Form " << setw(10) << "SPBT ID" << endl;


	while (rs->next()) {
		cout << setw(17) << rs->getString("TEXTBOOK_ID") << setw(45) << rs->getString("TEXTBOOK_NAME") << setw(20) <<
			rs->getString("YEARPUBLISH") << setw(35) << rs->getString("PUBLISHER") << setw(25) << rs->getInt("STOCK") <<
			setw(10) << rs->getDouble("PRICE") << setw(13) << rs->getDouble("AMOUNTLOST") << setw(15) <<
			rs->getString("YEAR_FORM") << setw(12) << rs->getString("SPBT_ID") << endl;

	}

	delete ps;
}

//TEXTBOOK: SEARCH TEXTBOOK DONE EVERYTHING
void adminManager::findTextBookData(textbook* Textbook) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM textbook WHERE TEXTBOOK_ID = ?");

	ps->setString(1, Textbook->textbook_id);

	ResultSet* rs = ps->executeQuery();
	cout << setw(20) << "Textbook ID " << setw(35) << "Textbook Name " << setw(30) <<
		"Year Publish " << setw(25) << "Publisher " << setw(33) << "Stock " <<
		setw(10) << "Price " << setw(18) << "Amount Lost " << setw(10) <<
		"Form " << setw(10) << "SPBT ID" << endl;


	while (rs->next()) {
		cout << setw(17) << rs->getString("TEXTBOOK_ID") << setw(45) << rs->getString("TEXTBOOK_NAME") << setw(20) <<
			rs->getString("YEARPUBLISH") << setw(35) << rs->getString("PUBLISHER") << setw(25) << rs->getInt("STOCK") <<
			setw(10) << rs->getDouble("PRICE") << setw(13) << rs->getDouble("AMOUNTLOST") << setw(15) <<
			rs->getString("YEAR_FORM") << setw(12) << rs->getString("SPBT_ID") << endl;

	}
	delete ps;
}

//TEXTBOOK: UPDATE TEXTBOOK DATA DONE EVERYTHING
int adminManager::updateTextBookData(textbook* Textbook) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE textbook SET TEXTBOOK_NAME = ?, YEARPUBLISH = ?, PUBLISHER = ?, STOCK = ?, PRICE = ?, SPBT_ID = ? WHERE TEXTBOOK_ID = ? ");

	ps->setString(7, Textbook->textbook_id);
	ps->setString(1, Textbook->textbook_name);
	ps->setString(2, Textbook->date);
	ps->setString(3, Textbook->publisher);
	ps->setInt(4, Textbook->stock);
	ps->setDouble(5, Textbook->price);
	ps->setString(6, Textbook->spbt_id);

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//TEXTBOOK: INSERT NEW RETURN GET ID DONE EVERYTHING
int adminManager::insertReturnGetTextbook(returnget* ReturnGet) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO returnget (TEXTBOOK_ID, DATE_GET, STATUS_GET, RETURNGET_ID, NRIC) VALUES (?, ?, ?, ?, ?)");

	ps->setString(4, ReturnGet->returnget_id);
	ps->setString(2, ReturnGet->date_get);
	ps->setInt(3, ReturnGet->status_get);
	ps->setString(1, ReturnGet->textbook_id);
	ps->setString(5, ReturnGet->nric);
	

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//TEXTBOOK: UPDATE RETURN GET ID DONE EVERYTHING
int adminManager::updateReturnGetTextbook(returnget* ReturnGet) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE returnget SET DATE_RETURN = ?, STATUS_RETURN = ? WHERE RETURNGET_ID = ?");

	ps->setString(3, ReturnGet->returnget_id);
	ps->setString(1, ReturnGet->date_return);
	ps->setInt(2, ReturnGet->status_return);

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//TEXTBOOK: VIEW RETURN GET DONE EVERYTHING 
void adminManager::viewReturnGetTextbook(returnget* ReturnGet) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM returnget");

	ResultSet* rs = ps->executeQuery();
	cout << setw(35) << "Return Get ID " << setw(35) << "Date Get " << setw(30) <<
		"Date Return " << setw(20) << "Status Get " << setw(20) << "Status return " <<
		setw(20) << "Textbook ID " << setw(20) << "NRIC " << endl;


	while (rs->next()) {
		cout << setw(35) << rs->getString("RETURNGET_ID") << setw(35) << rs->getString("DATE_GET") << setw(28) <<
			rs->getString("DATE_RETURN") << setw(17) << rs->getString("STATUS_GET") << setw(20) << rs->getInt("STATUS_RETURN") <<
			setw(23) << rs->getString("TEXTBOOK_ID") << setw(24) << rs->getString("NRIC") << endl;
	}

	delete ps;
}

//TEXTBOOK: FIND RETURN GET DONE EVERYTHING
void adminManager::findReturnGetTextbook(returnget* ReturnGet) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM returnget WHERE nric=?");

	ps->setString(1, ReturnGet->nric);

	ResultSet* rs = ps->executeQuery();
	cout << setw(35) << "Return Get ID " << setw(35) << "Date Get " << setw(30) <<
		"Date Return " << setw(20) << "Status Get " << setw(20) << "Status return " <<
		setw(20) << "Textbook ID " << setw(20) << "NRIC " <<endl;


	while (rs->next()) {
		cout << setw(38) << rs->getString("RETURNGET_ID") << setw(32) << rs->getString("DATE_GET") << setw(28) <<
			rs->getString("DATE_RETURN") << setw(18) << rs->getString("STATUS_GET") << setw(18) << rs->getInt("STATUS_RETURN") <<
			setw(24) << rs->getString("TEXTBOOK_ID") << setw(24) << rs->getString("NRIC") << endl;

	}

	delete ps;
}

//TEXTBOOK: LIST OF TEXTBOOK OF STUDENTS DONE EVERYTHING
void adminManager::viewTextBookStudent(returnget* ReturnGet) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT returnget.RETURNGET_ID, returnget.TEXTBOOK_ID, textbook.TEXTBOOK_NAME FROM returnget NATURAL JOIN textbook WHERE returnget.NRIC = ?;");

	ps->setString(1, ReturnGet->nric);
	ResultSet* rs = ps->executeQuery();

	cout << "\n\n\n";

	cout << setw(80) << "Return Get ID " << setw(33) << "Textbook ID " << setw(35) << "Textbook Name " << endl;

	while (rs->next()) {
		cout << setw(83) << rs->getString("RETURNGET_ID") << setw(28) << rs->getString("TEXTBOOK_ID") << setw(37) << rs->getString("TEXTBOOK_NAME") << endl;
	}

	delete ps;
}

//PENALTY: INSERT PENALTY DONE EVERYTHING
int adminManager::insertPenaltyTextbook(penalty* Penalty) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO penalty (penalty.TOTAL_PENALTY, penalty.RETURNGET_ID) SELECT textbook.PRICE, returnget.RETURNGET_ID FROM textbook NATURAL JOIN returnget WHERE RETURNGET_ID = ?");

	ps->setString(1, Penalty->returnget_id);

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//PENALTY: INSERT PENALTY DONE EVERYTHING
int adminManager::confirmPenaltyTextbook(penalty* Penalty) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE TEXTBOOK NATURAL JOIN returnget NATURAL JOIN penalty SET textbook.AMOUNTLOST = textbook.AMOUNTLOST + textbook.PRICE WHERE returnget.RETURNGET_ID = ?;");

	ps->setString(1, Penalty->returnget_id);

	int status = ps->executeUpdate();
	delete ps;
	return 0;
}

//PENALTY: VIEW PENALTY DONE EVERYTHING
void adminManager::viewPenaltyTextbook(penalty* Penalty) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT penalty.RECEIPT_ID, penalty.TOTAL_PENALTY, penalty.DATE_PENALTY, penalty.RETURNGET_ID, returnget.TEXTBOOK_ID, returnget.NRIC FROM penalty NATURAL JOIN returnget");

	ResultSet* rs = ps->executeQuery();

	cout << "\n\n\n";

	cout << setw(25) << "Receipt ID " << setw(33) << "Date Penalty " << setw(35) << "Return Get ID " << setw(39) << "Textbook ID " << setw(36) << "Total Penalty " << setw(20) << "Student IC" << endl;

	while (rs->next()) {
		cout << setw(20) << rs->getString("RECEIPT_ID") << setw(40) << rs->getString("DATE_PENALTY") << setw(35) << rs->getString("RETURNGET_ID") << setw(35) << rs->getString("TEXTBOOK_ID") <<
			setw(35) << rs->getString("TOTAL_PENALTY") << setw(24) << rs->getString("NRIC") << endl;
	}

	delete ps;
}

//PENALTY: SEARCH PENALTY DONE EVERYTHING
void adminManager::findPenaltyTextbook(penalty* Penalty) {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT penalty.RECEIPT_ID, penalty.TOTAL_PENALTY, penalty.DATE_PENALTY, penalty.RETURNGET_ID, returnget.TEXTBOOK_ID FROM penalty NATURAL JOIN returnget WHERE returnget.NRIC=?");

	ps->setString(1, Penalty->nric);
	ResultSet* rs = ps->executeQuery();

	cout << "\n\n\n";

	cout << setw(25) << "Receipt ID " << setw(33) << "Date Penalty " << setw(35) << "Return Get ID " << setw(39) << "Textbook ID " << setw(36) << "Total Penalty " << endl;
	
	while (rs->next()) {
		cout << setw(20) << rs->getString("RECEIPT_ID") << setw(40) << rs->getString("DATE_PENALTY") << setw(35) << rs->getString("RETURNGET_ID") << setw(35) << rs->getString("TEXTBOOK_ID") <<
			setw(35) << rs->getString("TOTAL_PENALTY") << endl;
	}

	delete ps;
}

//REPORT: COUNT STUDENT BASED ON CLASS DONE EVERYTHING
void adminManager::ReportStudent() {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT class.CLASS_ID, class.CLASS_NAME, class.TOTALSTUDENTS FROM class GROUP BY class.CLASS_ID;");

	ResultSet* rs = ps->executeQuery();
	cout << "\n";
	cout << setw(70) << "Class ID " << setw(33) << "Class Name " << setw(35) << "Total Students" <<  endl;

	while (rs->next()) {
		cout << setw(70) << rs->getString("CLASS_ID") << setw(30) << rs->getString("CLASS_NAME") << setw(30) << rs->getString("TOTALSTUDENTS")<< endl;
	}

	delete ps;
}

//REPORT: CALCULATE AMOUNT LOST OF TEXTBOOK DONE EVERYTHING
void adminManager::ReportTextbook() {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT textbook.TEXTBOOK_NAME, SUM(textbook.AMOUNTLOST) FROM TEXTBOOK GROUP BY textbook.TEXTBOOK_NAME");

	ResultSet* rs = ps->executeQuery();
	cout << "\n";
	cout << setw(100) << "Textbook Name " << setw(33) << "Amount Lost " << setw(35) << endl;

	while (rs->next()) {
		cout << setw(100) << rs->getString("TEXTBOOK_NAME") << setw(30) << rs->getString("SUM(textbook.AMOUNTLOST)") << endl;
	}

	delete ps;
}

//REPORT: COUNT PENALTY
void adminManager::ReportPenalty() {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT COUNT(penalty.RECEIPT_ID) FROM penalty;");

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		cout << setw(115) << "Total Penalty:" << rs->getString("COUNT(penalty.RECEIPT_ID)") << endl;
	}

	delete ps;
}

//REPORT: STATUS PENALTY
void adminManager::ReportPenalty2() {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT COUNT(returnget.STATUS_RETURN) FROM returnget WHERE returnget.STATUS_RETURN = 2 GROUP BY DATE_RETURN;");

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		cout << setw(115) << "Total Return That Get Penalty:" << rs->getString("COUNT(returnget.STATUS_RETURN)") << endl;
	}

	delete ps;
}

//REPORT: SUCCESS GET
void adminManager::ReportSuccessGet() {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT COUNT(returnget.STATUS_GET) FROM returnget WHERE returnget.STATUS_GET = 1 GROUP BY DATE_GET;");
	cout << "\n";
	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		cout << setw(115) << "Total students success get textbook:" << rs->getString("COUNT(returnget.STATUS_GET)") << endl;
	}

	delete ps;
}

//REPORT: SUCCESS GET
void adminManager::ReportSuccessReturn() {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT COUNT(returnget.STATUS_RETURN) FROM returnget WHERE returnget.STATUS_RETURN = 0 GROUP BY DATE_RETURN;");

	ResultSet* rs = ps->executeQuery();

	while (rs->next()) {
		cout << setw(115) << "Total students return get textbook:" << rs->getString("COUNT(returnget.STATUS_RETURN)") << endl;
	}

	delete ps;
}

