#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

//ͳ��ÿ����Ŀ�ı�������
void countTheNumberOfApplicantsForEachProject() 
{
    int projectCounts[EVENT_NUM] = { 0 };


    for (int i = 0; i < reg_num; i++) 
    {
        for (int j = 0; j < eve_num; j++) 
        {
            if (reg[i].registration_event_id == eve[j].event_id)
            {
                projectCounts[j]++;
                break;
            }
        }
    }

    printf("��Ŀ��������ͳ�ƽ����\n");
    printf("��ĿID          ��Ŀ����         ��������\n");

    for (int j = 0; j < eve_num; j++) 
    {
        //SetPosition(POS_X2, POS_Y + 3 + j);
        printf("%-15d %-16s %-8d\n", eve[j].event_id, eve[j].event_name, projectCounts[j]);
    }

    system("pause");
}

//ͳ��ÿ��ѧԺ�ı�������
void countTheNumberOfApplicantsForEachCollege() 
{
    char colleges[STUDENT_NUM][STUDENT_COLLEGE] = { 0 };
    int collegeCounts[STUDENT_NUM] = { 0 };
    int collegeCount = 0;

    for (int i = 0; i < STUDENT_NUM; i++) 
    {
        int found = 0;
        for (int j = 0; j < collegeCount; j++) 
        {
            if (strcmp(stu[i].student_college, colleges[j]) == 0) 
            {
                found = 1;
                break;
            }
        }
        if (!found && stu[i].student_college[0] != '\0') 
        {
            strcpy(colleges[collegeCount], stu[i].student_college);
            collegeCount++;
        }
    }
    for (int i = 0; i < reg_num; i++) 
    {
        for (int j = 0; j < STUDENT_NUM; j++) 
        {
            if (reg[i].registration_student_id == stu[j].student_id)
            {
                for (int k = 0; k < collegeCount; k++) 
                {
                    if (strcmp(stu[j].student_college, colleges[k]) == 0) 
                    {
                        collegeCounts[k]++;
                        break;
                    }
                }
                break;
            }
        }
    }

    printf("ѧԺ��������ͳ�ƽ����\n");
    printf("ѧԺ����\t\t\t��������\n");

    for (int k = 0; k < collegeCount; k++) 
    {
        printf("%s\t\t\t%d\n",colleges[k],collegeCounts[k]);
    }
    system("pause");
}

//ͳ��ÿ��ѧ���ı�����Ŀ��
void countTheNumberOfRegisteredProjectsForEachStudent() 
{
    int studentCounts[STUDENT_NUM] = { 0 };

    for (int i = 0; i < reg_num; i++) 
    {
        for (int j = 0; j < STUDENT_NUM; j++) 
        {
            if (reg[i].registration_student_id == stu[j].student_id)
            {
                studentCounts[j]++;
                break;
            }
        }
    }


    printf("ѧ��������Ŀ��ͳ�ƽ����\n");
    printf("ѧ��ID          ѧ������         ������Ŀ��\n");

    int displayCount = 0;
    for (int j = 0; j < STUDENT_NUM; j++) 
    {
        if (studentCounts[j] > 0) 
        {
            //SetPosition(POS_X2, POS_Y + 3 + displayCount);
            printf("%-15d %-16s %-8d\n",stu[j].student_id,stu[j].student_name,studentCounts[j]);
            displayCount++;
        }
    }

    system("pause");
}

// ��ѯ�����ɼ�
void queryCompetitionResults() 
{
    int eventId;

    printf("������Ҫ��ѯ�ɼ�����ĿID��");
    scanf("%d", &eventId);

    char eventName[EVENT_NAME] = { 0 };
    for (int j = 0; j < eve_num; j++) 
    {
        if (eventId == eve[j].event_id)
        {
            strcpy(eventName, eve[j].event_name);
            break;
        }
    }

    int foundCount = 0;

	// ����Ƿ��б�����¼
    for (int i = 0; i < reg_num; i++) 
    {
        if (reg[i].registration_event_id == eventId)
        {
            for (int j = 0; j < STUDENT_NUM; j++) 
            {
                if (reg[i].registration_student_id == stu[j].student_id)
                {
                    foundCount++;
                    break;
                }
            }
        }
    }

    if (foundCount == 0) 
    {
        printf("δ�ҵ�����Ŀ�ĳɼ���¼��\n");
    }
    else 
    {
        foundCount = 0;
        printf("��Ŀ %d(%s) �ĳɼ����£�\n", eventId, eventName);
        printf("ѧ��ID          ѧ������         �ɼ�\n");
        for (int i = 0; i < reg_num; i++) 
        {
            if (reg[i].registration_event_id == eventId)
            {
                for (int j = 0; j < STUDENT_NUM; j++) 
                {
                    if (reg[i].registration_student_id == stu[j].student_id)
                    {
                        printf("%-15d %-16s %-8lf\n",stu[j].student_id,stu[j].student_name,reg[i].registration_grade);
                        foundCount++;
                        break;
                    }
                }
            }
        }
    }
    system("pause");
}



// ����ͳ����Ϣ���ļ�
void saveStatisticalInformationToAFile() 
{
    FILE* fp = fopen("statistic.txt", "w");
    if (fp == NULL) 
    {
        //SetPosition(POS_X2, POS_Y);
        printf("�޷������ļ���\n");
        system("pause");
        return;
    }


    fprintf(fp, "========== ��Ŀ��������ͳ�� ==========\n");
    int projectCounts[EVENT_NUM] = { 0 };

    for (int i = 0; i < reg_num; i++) 
    {
        for (int j = 0; j < eve_num; j++) 
        {
            if (reg[i].registration_event_id == eve[j].event_id)
            {
                projectCounts[j]++;
                break;
            }
        }
    }

    fprintf(fp, "��ĿID          ��Ŀ����         ��������\n");
    for (int j = 0; j < eve_num; j++) 
    {
        fprintf(fp, "%-15d %-16s %-8d\n",eve[j].event_id,eve[j].event_name,projectCounts[j]);
    }

    fprintf(fp, "\n\n========== ѧԺ��������ͳ�� ==========\n");
    char colleges[STUDENT_NUM][STUDENT_COLLEGE] = { 0 };
    int collegeCounts[STUDENT_NUM] = { 0 };
    int collegeCount = 0;

    for (int i = 0; i < stu_num; i++) 
    {
        int found = 0;
        for (int j = 0; j < collegeCount; j++) 
        {
            if (strcmp(stu[i].student_college, colleges[j]) == 0) 
            {
                found = 1;
                break;
            }
        }
        if (!found && stu[i].student_college[0] != '\0') 
        {
            strcpy(colleges[collegeCount], stu[i].student_college);
            collegeCount++;
        }
    }

    memset(collegeCounts, 0, sizeof(collegeCounts));
    for (int i = 0; i < reg_num; i++) 
    {
        for (int j = 0; j < stu_num; j++) 
        {
            if (reg[i].registration_student_id == stu[j].student_id)
            {
                for (int k = 0; k < collegeCount; k++) 
                {
                    if (strcmp(stu[j].student_college, colleges[k]) == 0) 
                    {
                        collegeCounts[k]++;
                        break;
                    }
                }
                break;
            }
        }
    }

    fprintf(fp, "ѧԺ����                  ��������\n");
    for (int k = 0; k < collegeCount; k++) 
    {
        fprintf(fp, "%-25s %-16d\n",colleges[k],collegeCounts[k]);
    }

    fclose(fp);
    printf("ͳ����Ϣ�ѱ��浽 statistic.txt\n");
    system("pause");
}