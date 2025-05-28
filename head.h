#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define EVENT_NUM 50
#define STUDENT_NUM 500
#define REGISTRATION_NUM 500

//运动项目宏定义
#define EVENT_ID 20
#define EVENT_NAME 20
#define EVENT_KIND 10
#define EVENT_TYPE 5
#define EVENT_TIME 20
#define EVENT_VENUE 50
#define EVENT_STATUS 5
#define EVENT_REGISTRATION_NUM 50

//学生信息宏定义
#define STUDENT_ID 20
#define STUDENT_NAME 10
#define STUDENT_SEX 3
#define STUDENT_CLASS 10
#define STUDENT_COLLEGE 20
#define STUDENT_PHONE 20

//报名信息宏定义
#define REGISTRATION_ID 20
#define REGISTRATION_STUDENT_ID 20
#define REGISTRATION_EVENT_ID 20
#define REGISTRATION_TIME 10

//菜单宏定义
#define POS_X1 45
#define POS_X2 40
#define POS_X3 60
#define POS_X4 65
#define POS_Y 3

//运动项目结构体
typedef struct
{
	char event_id[EVENT_ID];
	char event_name[EVENT_NAME];
	char event_kind[EVENT_KIND];
	char event_type[EVENT_TYPE];
	char event_time[EVENT_TIME];
	char event_venue[EVENT_VENUE];
	char event_status[EVENT_STATUS];
	int event_registration_num;
}PRO;

//学生信息结构体
typedef struct
{
	char student_id[STUDENT_ID];
	char student_name[STUDENT_NAME];
	char student_sex[STUDENT_SEX];
	char student_class[STUDENT_CLASS];
	char student_college[STUDENT_COLLEGE];
	char student_phone[STUDENT_PHONE];
}STU;

//报名信息结构体
typedef struct
{
	char registration_id[REGISTRATION_ID];
	char registration_student_id[REGISTRATION_STUDENT_ID];
	char registration_event_id[REGISTRATION_EVENT_ID];
	char registration_time[REGISTRATION_TIME];
	double registration_grade;
}REG;

//主要函数声明
//运动项目管理功能
void displayAllSportsEventInformation();//显示所有运动项目信息
void addSportsEventInformation();//添加运动项目信息
void deleteSportsEventInformation();//删除运动项目信息
void modifySportsEventInformation();//修改运动项目信息
void searchForSportsEventInformation();//查找运动项目信息

//学生信息管理功能
void displayAllStudentInformation();//显示所有学生信息
void addStudentInformation();//添加学生信息
void deleteStudentInformation();//删除学生信息
void modifyStudentInformation();//修改学生信息
void searchForStudentInformation();//查找学生信息

//项目报名管理功能
void studentRegistration();//学生报名
void cancelRegistration();//取消报名
void displayAllRegistrationInformation();//显示所有报名信息
void searchForRegistrationInformation();//查找报名信息
void enterGrades();//录入成绩

//统计查询功能
void countTheNumberOfApplicantsForEachProject();//统计每个项目的报名人数
void countTheNumberOfApplicantsForEachCollege();//统计每个学院的报名人数
void countTheNumberOfRegisteredProjectsForEachStudent();//统计每个学生的报名项目数
void queryCompetitionResults();//查询比赛成绩
void saveStatisticalInformationToAFile();//保存统计信息到文件

//辅助功能
void login();//登录系统
void displayMainMenu();//显示主菜单
void eventManagementMenu();//运动项目菜单
void studentManagementMenu();//学生管理菜单
void registrationManagementMenu();//报名菜单
void statisticsMenu();//统计菜单
void SetPosition(int x, int y);//光标定位

#ifndef HEAD_H
#define HEAD_H
extern PRO pro[];
extern STU stu[];
extern REG reg[];
extern int pro_count;
extern int stu_count;
extern int reg_count;
#endif