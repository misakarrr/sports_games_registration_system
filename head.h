#pragma once
#include <stdio.h> //��׼�������ͷ�ļ�
#include <stdlib.h> //��׼��ͷ�ļ�
#include <windows.h> //Windows APIͷ�ļ�
#include <string.h> //�ַ�������ͷ�ļ�
#include <time.h> //ʱ�䴦��ͷ�ļ�

//�˶���Ŀ������ѧ�������ͱ��������궨��
#define EVENT_NUM 50 //�˶���Ŀ�����궨��
#define STUDENT_NUM 500 //ѧ�������궨��
#define REGISTRATION_NUM 500 //���������궨��

//�˶���Ŀ�궨��
#define EVENT_NAME 20 // ��Ŀ���ƺ궨��(100 �ס����ߡ���Զ��)
#define EVENT_KIND 10 // ��Ŀ���ͺ궨��(������������)
#define EVENT_TYPE 10 // �������ͺ궨��(������Ŀ��Ů����Ŀ)
#define EVENT_VENUE 10 // �������غ궨��
#define EVENT_STATUS 10 // ��Ŀ״̬�궨��(�����С��ѽ���)
#define EVENT_REGISTRATION_NUM 50 // �����������޺궨��

//ѧ����Ϣ�궨��
#define STUDENT_NAME 10 // ѧ�������궨��
#define STUDENT_SEX 3 // ѧ���Ա�궨��(�С�Ů)
#define STUDENT_CLASS 10 // ѧ���༶�궨��
#define STUDENT_COLLEGE 20 // ѧ��ѧԺ�궨��
#define STUDENT_PHONE 20 // ѧ���绰�궨��

////�˵��궨��
//#define POS_X1 45
//#define POS_X2 40
//#define POS_X3 60
//#define POS_X4 65
//#define POS_Y 3

//�˶���Ŀ�ṹ��
typedef struct
{
	int event_id;// ��Ŀ���
	char event_name[EVENT_NAME];// ��Ŀ����(100 �ס����ߡ���Զ��)
	char event_kind[EVENT_KIND];// ��Ŀ����(������������)
	char event_type[EVENT_TYPE];// ��������(������Ŀ��Ů����Ŀ)
	time_t event_time;// ʹ��time_t���ʹ洢ʱ��
	char event_venue[EVENT_VENUE];// ��������
	char event_status[EVENT_STATUS];// ��Ŀ״̬(�����С��ѽ���)
	int event_registration_num;// ������������
}EVE;

//ѧ����Ϣ�ṹ��
typedef struct
{
	int student_id;// ѧ�����
	char student_name[STUDENT_NAME];// ѧ������
	char student_sex[STUDENT_SEX];// ѧ���Ա�(�С�Ů)
	char student_class[STUDENT_CLASS];// ѧ���༶
	char student_college[STUDENT_COLLEGE];// ѧ��ѧԺ
	char student_phone[STUDENT_PHONE];// ѧ���绰
}STU;

//������Ϣ�ṹ��
typedef struct
{
	int registration_id;// �������
	int registration_student_id;// ѧ�����
	int registration_event_id;// �˶���Ŀ���
	time_t registration_time;// ʹ��time_t���ʹ洢ʱ��
	double registration_grade;// �ɼ�(��Ϊ�գ�����������¼��)
}REG;

//��Ҫ��������
//�˶���Ŀ������
void displayAllSportsEventInformation();//��ʾ�����˶���Ŀ��Ϣ
void addSportsEventInformation();//����˶���Ŀ��Ϣ
void deleteSportsEventInformation();//ɾ���˶���Ŀ��Ϣ
void modifySportsEventInformation();//�޸��˶���Ŀ��Ϣ
void searchForSportsEventInformation();//�����˶���Ŀ��Ϣ

//ѧ����Ϣ������
void displayAllStudentInformation();//��ʾ����ѧ����Ϣ
void addStudentInformation();//���ѧ����Ϣ
void deleteStudentInformation();//ɾ��ѧ����Ϣ
void modifyStudentInformation();//�޸�ѧ����Ϣ
void searchForStudentInformation();//����ѧ����Ϣ

//��Ŀ����������
void studentRegistration();//ѧ������
void cancelRegistration();//ȡ������
void displayAllRegistrationInformation();//��ʾ���б�����Ϣ
void searchForRegistrationInformation();//���ұ�����Ϣ
void enterGrades();//¼��ɼ�

//ͳ�Ʋ�ѯ����
void countTheNumberOfApplicantsForEachProject();//ͳ��ÿ����Ŀ�ı�������
void countTheNumberOfApplicantsForEachCollege();//ͳ��ÿ��ѧԺ�ı�������
void countTheNumberOfRegisteredProjectsForEachStudent();//ͳ��ÿ��ѧ���ı�����Ŀ��
void queryCompetitionResults();//��ѯ�����ɼ�
void saveStatisticalInformationToAFile();//����ͳ����Ϣ���ļ�

//��������
void login();//��¼ϵͳ
//void SetPosition(int x, int y);//��궨λ
int get_display_width(const char* s);// ��ȡ�ַ�������ʾ��ȣ�����UTF-8�����ַ���
void print_align(const char* s, int total_width);// ��ӡ�����ַ���

//�˵�����
void displayMainMenu();//��ʾ���˵�
void eventManagementMenu();//�˶���Ŀ�˵�
void studentManagementMenu();//ѧ������˵�
void registrationManagementMenu();//�����˵�
void statisticsMenu();//ͳ�Ʋ˵�

// �ļ���������
void readFromFileEvent();//���ļ�������Ŀ��Ϣ
void readFromFileStudent();//���ļ�����ѧ����Ϣ
void readFromFileRegistration();//���ļ����뱨����Ϣ
void saveToFileEvent();//�����˶���Ŀ��Ϣ���ļ�
void saveToFileStudent();//����ѧ����Ϣ���ļ�
void saveToFileRegistration();//���汨����Ϣ���ļ�

#ifndef HEAD_H
#define HEAD_H
extern EVE eve[];
extern STU stu[];
extern REG reg[];
extern int eve_num;
extern int stu_num;
extern int reg_num;
#endif