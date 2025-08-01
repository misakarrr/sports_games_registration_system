#include "head.h"

//自动对齐打印字符串，考虑UTF-8中文字符的宽度
// 获取字符串的显示宽度（考虑UTF-8中文字符）
int get_display_width(const char* s)
{
    int width = 0;
    while (*s)
    {
        // 判断是否为UTF-8中文（首字节>=0x80）
        if ((unsigned char)*s >= 0x80)
        {
            width += 2;
            s += 3; // 跳过3字节
        }
        else
        {
            width += 1;
            s++;
        }
    }
    return width;
}

// 打印对齐的字符串，填充空格到指定宽度
void print_align(const char* s, int total_width)
{
    int w = get_display_width(s);
    printf("%s", s);
    for (int i = 0; i < total_width - w; i++)
        putchar(' ');
}

//光标定位函数
////void SetPosition(int x, int y)
//{
//	HANDLE hOut;
//	COORD pos;
//
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	pos.X = x;
//	pos.Y = y;
//	SetConsoleCursorPosition(hOut, pos);
//}

//int Menu(void)
//{
//	int posy = 5;
//	int option;
//	int i, j;
//	SetPosition(POS_X3, posy);
//	printf("学生成绩管理系统\n");
//	for (i = 0; i < 2; i++)
//	{
//		SetPosition(POS_X1, ++posy);
//		for (j = 0; j < 55; j++)
//		{
//			printf("-");
//		}
//	}
//	SetPosition(POS_X1, ++posy);
//	printf("1.输入学生信息");
//	SetPosition(POS_X4, posy);
//	printf("2.增加学生成绩");
//	SetPosition(POS_X1, posy += 2);
//	printf("3.删除学生信息");
//	SetPosition(POS_X4, posy);
//	printf("4.按学号查找记录");
//	SetPosition(POS_X1, posy += 2);
//	printf("5.按姓名查找记录");
//	SetPosition(POS_X4, posy);
//	printf("6.修改学生信息");
//	SetPosition(POS_X1, posy += 2);
//	printf("7.计算学生成绩");
//	SetPosition(POS_X4, posy);
//	printf("8.计算课程成绩");
//	SetPosition(POS_X1, posy += 2);
//	printf("9.按学号排序");
//	SetPosition(POS_X4, posy);
//	printf("10.按姓名排序");
//	SetPosition(POS_X1, posy += 2);
//	printf("11.按总成绩降序排序");
//	SetPosition(POS_X4, posy);
//	printf("12.按总成绩升序排序");
//	SetPosition(POS_X1, posy += 2);
//	printf("13.学生成绩统计");
//	SetPosition(POS_X4, posy);
//	printf("14.打印学生记录");
//	SetPosition(POS_X1, posy += 2);
//	printf("15.学生记录存盘");
//	SetPosition(POS_X4, posy);
//	printf("16.从磁盘读取学生记录");
//	SetPosition(POS_X1, posy += 2);
//	printf("0.退出");
//	for (i = 0; i < 2; i++)
//	{
//		SetPosition(POS_X1, ++posy);
//		for (j = 0; j < 55; j++)
//		{
//			printf("-");
//		}
//	}
//	SetPosition(POS_X1, ++posy);
//	printf("请选择你想要进行的操作[0-16]：[  ]\b\b\b");
//	scanf("%d", &option);
//	return option;
//}

// 模拟登录和注册函数
void login() 
{
    char username[20];
    char password[20];
    int attempts = 3;
    char file_username[20], file_password[20];
    int found = 0;
    int choice;

    while (1)
    {
        printf("\n=== 登录系统 ===\n");
        printf("1. 登录\n");
        printf("2. 注册\n");
        printf("请选择操作：");
        scanf("%d", &choice);
        getchar(); // 吸收回车

        if (choice == 2)
        {
            // 注册功能
            printf("\n=== 用户注册 ===\n");
            printf("请输入新用户名: ");
            scanf("%s", username);
            printf("请输入新密码: ");
            scanf("%s", password);

            // 检查用户名是否已存在
            FILE *fp = fopen("login.txt", "r");
            int exists = 0;
            if (fp != NULL)
            {
                while (fscanf(fp, "%s %s", file_username, file_password) == 2)
                {
                    if (strcmp(username, file_username) == 0)
                    {
                        exists = 1;
                        break;
                    }
                }
                fclose(fp);
            }
            if (exists)
            {
                printf("用户名已存在，请重新注册！\n");
                continue;
            }
            // 写入新用户
            fp = fopen("login.txt", "a");
            if (fp == NULL)
            {
                printf("无法打开login.txt文件，无法注册！\n");
                continue;
            }
            fprintf(fp, "%s %s\n", username, password);
            fclose(fp);
            printf("注册成功，请登录！\n");
            continue;
        }
        else if (choice == 1)
        {
            // 登录功能
            attempts = 3;
            while (attempts > 0)
            {
                printf("\n用户名: ");
                scanf("%s", username);
                printf("密码: ");
                scanf("%s", password);

                FILE *fp = fopen("login.txt", "r");
                if (fp == NULL) 
                {
                    printf("无法打开login.txt文件，无法登录！\n");
                    return;
                }
                found = 0;
                while (fscanf(fp, "%s %s", file_username, file_password) == 2) 
                {
                    if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) 
                    {
                        found = 1;
                        break;
                    }
                }
                fclose(fp);

                if (found) 
                {
                    printf("登录成功！\n");
                    displayMainMenu();
                    return;
                } 
                else 
                {
                    attempts--;
                    printf("用户名或密码错误！剩余尝试次数: %d\n", attempts);
                }
            }
            printf("登录尝试次数过多，程序退出。\n");
            return;
        }
        else
        {
            printf("无效选择，请重新输入！\n");
        }
    }
}

// 主菜单
void displayMainMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== 运动会报名系统 ===\n");
        printf("1. 运动项目管理\n");
        printf("2. 学生信息管理\n");
        printf("3. 项目报名管理\n");
        printf("4. 统计查询\n");
        printf("5. 从文件中读取信息\n");
		printf("6. 保存信息到文件\n");
        printf("7. 退出系统\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            eventManagementMenu();
            break;
        case 2:
            studentManagementMenu();
            break;
        case 3:
            registrationManagementMenu();
            break;
        case 4:
            statisticsMenu();
            break;
        case 5:
			system("cls");
			printf("从文件中读取信息...\n");
			// 读取项目信息、学生信息和报名信息
			// 默认文件名为 event.txt, student.txt, registration.txt
            getc(stdin); // 清除缓冲区中的换行符
            readFromFileEvent();
			readFromFileStudent();
			readFromFileRegistration();
            break;
        case 6:
            system("cls");
			printf("保存信息到文件\n");
			// 保存项目信息、学生信息和报名信息到文件
			// 默认文件名为 event.txt, student.txt, registration.txt
            getc(stdin); // 清除缓冲区中的换行符
			saveToFileEvent();
            saveToFileStudent();
			saveToFileRegistration();
            break;
        case 7:
            printf("感谢使用运动会报名系统！\n");
            break;
        default:
            printf("无效选择，请重新输入！\n");
        }
    } while (choice != 7);
}

// 运动项目管理菜单
void eventManagementMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== 运动项目管理 ===\n");
        printf("1. 显示所有运动项目信息\n");
        printf("2. 添加运动项目信息\n");
        printf("3. 删除运动项目信息\n");
        printf("4. 修改运动项目信息\n");
        printf("5. 查找运动项目信息\n");
        printf("6. 返回主菜单\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("显示所有运动项目信息...\n");
            displayAllSportsEventInformation();
            break;
        case 2:
			system("cls");
            printf("添加运动项目信息...\n");
            addSportsEventInformation();
            break;
        case 3:
			system("cls");
            printf("删除运动项目信息...\n");
            deleteSportsEventInformation();
            break;
        case 4:
			system("cls");
            printf("修改运动项目信息...\n");
            modifySportsEventInformation();
            break;
        case 5:
			system("cls");
            printf("查找运动项目信息...\n");
            searchForSportsEventInformation();
            break;
        case 6:
            printf("返回主菜单...\n");
            break;
        default:
            printf("无效选择，请重新输入！\n");
        }
    } while (choice != 6);
}

// 学生信息管理菜单
void studentManagementMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== 学生信息管理 ===\n");
        printf("1. 显示所有学生信息\n");
        printf("2. 添加学生信息\n");
        printf("3. 删除学生信息\n");
        printf("4. 修改学生信息\n");
        printf("5. 查找学生信息\n");
        printf("6. 返回主菜单\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
			system("cls");
            printf("显示所有学生信息...\n");
            displayAllStudentInformation();
            break;
        case 2:
			system("cls");
            printf("添加学生信息...\n");
            addStudentInformation();
            break;
        case 3:
			system("cls");
            printf("删除学生信息...\n");
            deleteStudentInformation();
            break;
        case 4:
			system("cls");
            printf("修改学生信息...\n");
            modifyStudentInformation();
            break;
        case 5:
			system("cls");
            printf("查找学生信息...\n");
            searchForStudentInformation();
            break;
        case 6:
            printf("返回主菜单...\n");
            break;
        default:
            printf("无效选择，请重新输入！\n");
        }
    } while (choice != 6);
}

// 项目报名管理菜单
void registrationManagementMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== 项目报名管理 ===\n");
        printf("1. 学生报名\n");
        printf("2. 取消报名\n");
        printf("3. 显示所有报名信息\n");
        printf("4. 查找报名信息\n");
        printf("5. 录入成绩\n");
        printf("6. 返回主菜单\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("学生报名...\n");
            studentRegistration();
            break;
        case 2:
			system("cls");
            printf("取消报名...\n");
            cancelRegistration();
            break;
        case 3:
			system("cls");
            printf("显示所有报名信息...\n");
            displayAllRegistrationInformation();
            break;
        case 4:
			system("cls");
            printf("查找报名信息...\n");
            searchForRegistrationInformation();
            break;
        case 5:
			system("cls");
            printf("录入成绩...\n");
            enterGrades();
            break;
        case 6:
			system("cls");
            printf("返回主菜单...\n");
            break;
        default:
			system("cls");
            printf("无效选择，请重新输入！\n");
        }
    } while (choice != 6);
}

// 统计查询菜单
void statisticsMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== 统计查询 ===\n");
        printf("1. 统计每个项目的报名人数\n");
        printf("2. 统计每个学院的报名人数\n");
        printf("3. 统计每个学生的报名项目数\n");
        printf("4. 查询比赛成绩\n");
        printf("5. 保存统计信息到文件\n");
        printf("6. 返回主菜单\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("统计每个项目的报名人数...\n");
            countTheNumberOfApplicantsForEachProject();
            break;
        case 2:
			system("cls");
            printf("统计每个学院的报名人数...\n");
            countTheNumberOfApplicantsForEachCollege();
            break;
        case 3:
			system("cls");
            printf("统计每个学生的报名项目数...\n");
            countTheNumberOfRegisteredProjectsForEachStudent();
            break;
        case 4:
			system("cls");
            printf("查询比赛成绩...\n");
            queryCompetitionResults();
            break;
        case 5:
			system("cls");
            printf("保存统计信息到文件...\n");
            saveStatisticalInformationToAFile();
            break;
        case 6:
            printf("返回主菜单...\n");
            break;
        default:
            printf("无效选择，请重新输入！\n");
        }
    } while (choice != 6);
}

// 读取运动项目信息
void readFromFileEvent()
{
    char filename[256];
    FILE *fp;
    int count = 0;
    EVE temp;
    printf("请输入要读取的运动项目信息文件名（默认 event.txt）：");
    fgets(filename, sizeof(filename), stdin);
    // 去除换行符
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0';
    }
    // 如果未输入内容，使用默认文件名
    if (filename[0] == '\0')
    {
        strcpy(filename, "event.txt");
    }
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("未找到运动项目信息文件，无法读取！\n");
        return;
    }
    while (fscanf(fp, "%d %s %s %s %lld %s %s %d",
                  &temp.event_id,
                  temp.event_name,
                  temp.event_kind,
                  temp.event_type,
		          (long long*)&temp.event_time,
		          temp.event_venue,
		          temp.event_status,
                  &temp.event_registration_num) == 8)
    {
        eve[count++] = temp;
        if (count >= EVENT_NUM) break;
    }
    eve_num = count;
    fclose(fp);
    printf("成功读取%d条运动项目信息。\n", count);
}

// 读取学生信息
void readFromFileStudent()
{
    char filename[256];
    FILE *fp;
    int count = 0;
    STU temp;

    printf("请输入要读取的学生信息文件名（默认 student.txt）：");
    fgets(filename, sizeof(filename), stdin);
    // 去除换行符
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0';
    }
    // 如果未输入内容，使用默认文件名
    if (filename[0] == '\0')
    {
        strcpy(filename, "student.txt");
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("未找到学生信息文件，无法读取！\n");
        return;
    }
    while (fscanf(fp, "%d %s %s %s %s %s",
                  &temp.student_id,
                  temp.student_name,
                  temp.student_sex,
                  temp.student_class,
                  temp.student_college,
                  temp.student_phone) == 6)
    {
        stu[count++] = temp;
        if (count >= STUDENT_NUM) break;
    }
    stu_num = count;
    fclose(fp);
    printf("成功读取%d条学生信息。\n", count);
}

// 读取报名信息
void readFromFileRegistration()
{
    char filename[256];
    FILE *fp;
    int count = 0;
    REG temp;

    printf("请输入要读取的报名信息文件名（默认 registration.txt）：");
    fgets(filename, sizeof(filename), stdin);
    // 去除换行符
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0';
    }
    // 如果未输入内容，使用默认文件名
    if (filename[0] == '\0')
    {
        strcpy(filename, "registration.txt");
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("未找到报名信息文件，无法读取！\n");
        return;
    }
    while (fscanf(fp, "%d %d %d %lld %lf",
                  &temp.registration_id,
                  &temp.registration_student_id,
                  &temp.registration_event_id,
                  (long long*)&temp.registration_time,
                  &temp.registration_grade) == 5)
    {
        reg[count++] = temp;
        if (count >= REGISTRATION_NUM) break;
    }
    reg_num = count;
    fclose(fp);
    printf("成功读取%d条报名信息。\n", count);
}

// 保存运动项目信息到文件
void saveToFileEvent()
{
    char filename[256];
    FILE *fp;
    printf("请输入要保存的运动项目信息文件名（默认 event.txt）：");
    fgets(filename, sizeof(filename), stdin);
    // 去除换行符
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0';
    }
    // 如果未输入内容，使用默认文件名
    if (filename[0] == '\0')
    {
        strcpy(filename, "event.txt");
    }
    
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("无法打开文件 %s 进行写入！\n", filename);
        return;
    }
    
    for (int i = 0; i < eve_num; i++)
    {
        fprintf(fp, "%d %s %s %s %lld %s %s %d\n",
                eve[i].event_id,
                eve[i].event_name,
                eve[i].event_kind,
                eve[i].event_type,
                (long long)eve[i].event_time,
                eve[i].event_venue,
                eve[i].event_status,
                eve[i].event_registration_num);
    }
    
    fclose(fp);
    printf("成功保存%d条运动项目信息到文件 %s。\n", eve_num, filename);
}

// 保存学生信息到文件
void saveToFileStudent()
{
    char filename[256];
    FILE *fp;
    printf("请输入要保存的学生信息文件名（默认 student.txt）：");
    fgets(filename, sizeof(filename), stdin);
    // 去除换行符
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0';
    }
    // 如果未输入内容，使用默认文件名
    if (filename[0] == '\0')
    {
        strcpy(filename, "student.txt");
    }
    
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("无法打开文件 %s 进行写入！\n", filename);
        return;
    }
    
    for (int i = 0; i < stu_num; i++)
    {
        fprintf(fp, "%d %s %s %s %s %s\n",
                stu[i].student_id,
                stu[i].student_name,
                stu[i].student_sex,
                stu[i].student_class,
                stu[i].student_college,
                stu[i].student_phone);
    }
    
    fclose(fp);
    printf("成功保存%d条学生信息到文件 %s。\n", stu_num, filename);
}

// 保存报名信息到文件
void saveToFileRegistration()
{
    char filename[256];
    FILE *fp;
    printf("请输入要保存的报名信息文件名（默认 registration.txt）：");
    fgets(filename, sizeof(filename), stdin);
    // 去除换行符
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0';
    }
    // 如果未输入内容，使用默认文件名
    if (filename[0] == '\0')
    {
        strcpy(filename, "registration.txt");
    }
    
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("无法打开文件 %s 进行写入！\n", filename);
        return;
    }
    
    for (int i = 0; i < reg_num; i++)
    {
        fprintf(fp, "%d %d %d %lld %.2f\n",
                reg[i].registration_id,
                reg[i].registration_student_id,
                reg[i].registration_event_id,
                (long long)reg[i].registration_time,
                reg[i].registration_grade);
    }
    
    fclose(fp);
    printf("成功保存%d条报名信息到文件 %s。\n", reg_num, filename);
}
			