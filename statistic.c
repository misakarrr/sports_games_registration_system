#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

//统计每个项目的报名人数
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

    printf("项目报名人数统计结果：\n");
    printf("项目ID          项目名称         报名人数\n");

    for (int j = 0; j < eve_num; j++) 
    {
        //SetPosition(POS_X2, POS_Y + 3 + j);
        printf("%-15d %-16s %-8d\n", eve[j].event_id, eve[j].event_name, projectCounts[j]);
    }

    system("pause");
}

//统计每个学院的报名人数
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

    printf("学院报名人数统计结果：\n");
    printf("学院名称\t\t\t报名人数\n");

    for (int k = 0; k < collegeCount; k++) 
    {
        printf("%s\t\t\t%d\n",colleges[k],collegeCounts[k]);
    }
    system("pause");
}

//统计每个学生的报名项目数
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


    printf("学生报名项目数统计结果：\n");
    printf("学生ID          学生姓名         报名项目数\n");

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

// 查询比赛成绩
void queryCompetitionResults() 
{
    int eventId;

    printf("请输入要查询成绩的项目ID：");
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

	// 检查是否有报名记录
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
        printf("未找到该项目的成绩记录！\n");
    }
    else 
    {
        foundCount = 0;
        printf("项目 %d(%s) 的成绩如下：\n", eventId, eventName);
        printf("学生ID          学生姓名         成绩\n");
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



// 保存统计信息到文件
void saveStatisticalInformationToAFile() 
{
    FILE* fp = fopen("statistic.txt", "w");
    if (fp == NULL) 
    {
        //SetPosition(POS_X2, POS_Y);
        printf("无法创建文件！\n");
        system("pause");
        return;
    }


    fprintf(fp, "========== 项目报名人数统计 ==========\n");
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

    fprintf(fp, "项目ID          项目名称         报名人数\n");
    for (int j = 0; j < eve_num; j++) 
    {
        fprintf(fp, "%-15d %-16s %-8d\n",eve[j].event_id,eve[j].event_name,projectCounts[j]);
    }

    fprintf(fp, "\n\n========== 学院报名人数统计 ==========\n");
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

    fprintf(fp, "学院名称                  报名人数\n");
    for (int k = 0; k < collegeCount; k++) 
    {
        fprintf(fp, "%-25s %-16d\n",colleges[k],collegeCounts[k]);
    }

    fclose(fp);
    printf("统计信息已保存到 statistic.txt\n");
    system("pause");
}