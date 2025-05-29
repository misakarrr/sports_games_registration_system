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
        printf("5. 退出系统\n");
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
            printf("感谢使用运动会报名系统！\n");
            break;
        default:
            printf("无效选择，请重新输入！\n");
        }
    } while (choice != 5);
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
            printf("学生报名...\n");
            studentRegistration();
            break;
        case 2:
            printf("取消报名...\n");
            // 实现代码
            break;
        case 3:
            printf("显示所有报名信息...\n");
            // 实现代码
            break;
        case 4:
            printf("查找报名信息...\n");
            // 实现代码
            break;
        case 5:
            printf("录入成绩...\n");
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

