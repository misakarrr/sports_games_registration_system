#pragma once
#include <stdio.h> //标准输入输出头文件
#include <stdlib.h> //标准库头文件
#include <windows.h> //Windows API头文件
#include <string.h> //字符串处理头文件
#include <time.h> //时间处理头文件

//运动项目数量、学生数量和报名数量宏定义
#define EVENT_NUM 50 //运动项目数量宏定义
#define STUDENT_NUM 500 //学生数量宏定义
#define REGISTRATION_NUM 500 //报名数量宏定义

//运动项目宏定义
#define EVENT_NAME 20 // 项目名称宏定义(100 米、跳高、跳远等)
#define EVENT_KIND 10 // 项目类型宏定义(田赛、径赛等)
#define EVENT_TYPE 10 // 参赛类型宏定义(男子项目、女子项目)
#define EVENT_VENUE 10 // 比赛场地宏定义
#define EVENT_STATUS 10 // 项目状态宏定义(报名中、已结束)
#define EVENT_REGISTRATION_NUM 50 // 报名人数上限宏定义

//学生信息宏定义
#define STUDENT_NAME 10 // 学生姓名宏定义
#define STUDENT_SEX 3 // 学生性别宏定义(男、女)
#define STUDENT_CLASS 10 // 学生班级宏定义
#define STUDENT_COLLEGE 20 // 学生学院宏定义
#define STUDENT_PHONE 20 // 学生电话宏定义

////菜单宏定义
//#define POS_X1 45
//#define POS_X2 40
//#define POS_X3 60
//#define POS_X4 65
//#define POS_Y 3

//运动项目结构体
typedef struct
{
	int event_id;// 项目编号
	char event_name[EVENT_NAME];// 项目名称(100 米、跳高、跳远等)
	char event_kind[EVENT_KIND];// 项目类型(田赛、径赛等)
	char event_type[EVENT_TYPE];// 参赛类型(男子项目、女子项目)
	time_t event_time;// 使用time_t类型存储时间
	char event_venue[EVENT_VENUE];// 比赛场地
	char event_status[EVENT_STATUS];// 项目状态(报名中、已结束)
	int event_registration_num;// 报名人数上限
}EVE;

//学生信息结构体
typedef struct
{
	int student_id;// 学生编号
	char student_name[STUDENT_NAME];// 学生姓名
	char student_sex[STUDENT_SEX];// 学生性别(男、女)
	char student_class[STUDENT_CLASS];// 学生班级
	char student_college[STUDENT_COLLEGE];// 学生学院
	char student_phone[STUDENT_PHONE];// 学生电话
}STU;

//报名信息结构体
typedef struct
{
	int registration_id;// 报名编号
	int registration_student_id;// 学生编号
	int registration_event_id;// 运动项目编号
	time_t registration_time;// 使用time_t类型存储时间
	double registration_grade;// 成绩(可为空，比赛结束后录入)
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
//void SetPosition(int x, int y);//光标定位
int get_display_width(const char* s);// 获取字符串的显示宽度（考虑UTF-8中文字符）
void print_align(const char* s, int total_width);// 打印对齐字符串

//菜单功能
void displayMainMenu();//显示主菜单
void eventManagementMenu();//运动项目菜单
void studentManagementMenu();//学生管理菜单
void registrationManagementMenu();//报名菜单
void statisticsMenu();//统计菜单

// 文件操作功能
void readFromFileEvent();//从文件读入项目信息
void readFromFileStudent();//从文件读入学生信息
void readFromFileRegistration();//从文件读入报名信息
void saveToFileEvent();//保存运动项目信息到文件
void saveToFileStudent();//保存学生信息到文件
void saveToFileRegistration();//保存报名信息到文件

#ifndef HEAD_H
#define HEAD_H
extern EVE eve[];
extern STU stu[];
extern REG reg[];
extern int eve_num;
extern int stu_num;
extern int reg_num;
#endif