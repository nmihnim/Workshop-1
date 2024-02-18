#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

class adminManager {
public:
	int loginAdmin(admin* Admin);
	int insertAdminData(admin* Admin);
	int searchAdminData(admin* Admin);
	void viewAdminData(admin* Admin);

	int loginTeacher(teacher* Teacher);
	int insertTeacherData(teacher* Teacher);
	void viewTeacherData(teacher* Teacher);
	void viewStudentData1(teacher* Teacher);
	void viewTeacherStudentPenaltyData(teacher* Teacher);

	int insertTextBookData(textbook* Textbook);
	int updateTextBookData(textbook* Textbook);
	void viewTextBookData(textbook* Textbook);
	void findTextBookData(textbook* Textbook);

	void viewTextBookStudent(returnget* ReturnGet);

	int insertReturnGetTextbook(returnget* ReturnGet);
	int updateReturnGetTextbook(returnget* ReturnGet);
	void viewReturnGetTextbook(returnget* ReturnGet);
	void findReturnGetTextbook(returnget* ReturnGet);

	int insertClassData(classes* Classes);

	int loginStudent(student* Student);
	int insertStudentData(student* Student);
	int insertStudentDataBridge(student_class* Student_Class);
	void viewStudentData(student* Student);
	void viewStudentPenaltyData(student* Student);

	int insertPenaltyTextbook(penalty* Penalty);
	int confirmPenaltyTextbook(penalty* Penalty);
	void viewPenaltyTextbook(penalty* Penalty);
	void findPenaltyTextbook(penalty* Penalty);

	void ReportStudent();
	void ReportTextbook();
	void ReportPenalty();
	void ReportPenalty2();
	void ReportSuccessGet();
	void ReportSuccessReturn();
};

#endif