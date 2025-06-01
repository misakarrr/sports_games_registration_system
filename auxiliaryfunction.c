#include "head.h"

//光标定位函数
void SetPosition(int x, int y)
{
	HANDLE hOut;
	COORD pos;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

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

// 模拟登录函数
void login() 
{
    char username[20];
    char password[20];
    int attempts = 3;

    while (attempts > 0)
    {
        printf("\n=== 登录系统 ===\n");
        printf("用户名: ");
        scanf("%s", username);
        printf("密码: ");
        scanf("%s", password);

        // 简单验证，实际应用中应与存储的用户信息比对
        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
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
        printf("6. 退出系统\n");
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
            printf("感谢使用运动会报名系统！\n");
            break;
        default:
            printf("无效选择，请重新输入！\n");
        }
    } while (choice != 6);
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
            printf("显示所有运动项目信息...\n");
            // 实现代码
            break;
        case 2:
            printf("添加运动项目信息...\n");
            // 实现代码
            break;
        case 3:
            printf("删除运动项目信息...\n");
            // 实现代码
            break;
        case 4:
            printf("修改运动项目信息...\n");
            // 实现代码
            break;
        case 5:
            printf("查找运动项目信息...\n");
            // 实现代码
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
            printf("显示所有学生信息...\n");
            // 实现代码
            break;
        case 2:
            printf("添加学生信息...\n");
            // 实现代码
            break;
        case 3:
            printf("删除学生信息...\n");
            // 实现代码
            break;
        case 4:
            printf("修改学生信息...\n");
            // 实现代码
            break;
        case 5:
            printf("查找学生信息...\n");
            // 实现代码
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
            printf("统计每个项目的报名人数...\n");
            // 实现代码
            break;
        case 2:
            printf("统计每个学院的报名人数...\n");
            // 实现代码
            break;
        case 3:
            printf("统计每个学生的报名项目数...\n");
            // 实现代码
            break;
        case 4:
            printf("查询比赛成绩...\n");
            // 实现代码
            break;
        case 5:
            printf("保存统计信息到文件...\n");
            // 实现代码
            break;
        case 6:
            printf("返回主菜单...\n");
            break;
        default:
            printf("无效选择，请重新输入！\n");
        }
    } while (choice != 6);
}

// 读取项目信息
void readFromFileEvent()
{
    char filename[256];
    FILE *fp;
    int count = 0;
    EVE temp;

    printf("请输入要读取的项目信息文件名（默认 event.txt）：");
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
        printf("未找到项目信息文件，无法读取！\n");
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
        if (count >= 100) break;
    }
    eve_num = count;
    fclose(fp);

    printf("成功读取%d条项目信息。\n", count);
}

// 读取学生信息
void readFromFileStudent()
{
    char filename[256];
    FILE *fp;
    int count = 0;
    STU temp;

    printf("请输入要读取的项目信息文件名（默认 student.txt）：");
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
        if (count >= 100) break;
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

    printf("请输入要读取的项目信息文件名（默认 registration.txt）：");
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
        if (count >= 100) break;
    }
    reg_num = count;
    fclose(fp);
    printf("成功读取%d条报名信息。\n", count);
}