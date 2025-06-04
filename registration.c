#include "head.h"

//辅助函数
// 查找学生在数组中的索引
int find_student(int student_id)
{
    for (int i = 0; i < stu_num; i++)
    {
        if (stu[i].student_id == student_id)
        {
            return i;
        }
    }
    return -1; // 未找到
}
// 查找项目在数组中的索引
int find_event(int event_id)
{
    for (int i = 0; i < eve_num; i++)
    {
        if (eve[i].event_id == event_id)
        {
            return i;
        }
    }
    return -1; // 未找到
}

//输出报名信息
void print_registration(REG* r)
{
    int sinx = find_student(r->registration_student_id);
    int einx = find_event(r->registration_event_id);

    // 有效性检查
    if (sinx == -1) 
    {
        printf("未找到该学生信息，报名编号:%d\n", r->registration_id);
        return;
    }
    /*if (einx == -1) 
    {
        printf("未找到该项目，报名编号:%d\n", r->registration_id);
        return;
    }*/

    char tm[30];
    strftime(tm, sizeof(tm), "%Y-%m-%d %H:%M:%S", localtime(&r->registration_time));
    printf("报名编号:%d 学号:%d 姓名:%s 项目编号:%d 项目:%s 报名时间:%s 成绩:",
        r->registration_id,
        stu[sinx].student_id,
        stu[sinx].student_name,
        eve[einx].event_id,
        eve[einx].event_name,
        tm
    );
    if (r->registration_grade < 0) printf("未录入\n");
    else printf("%0.2f\n", r->registration_grade);
}

//学生报名函数
void studentRegistration()
{
    int student_id, event_id;
    printf("请输入学号: ");
    scanf("%d", &student_id);
    int sinx = find_student(student_id);
    if (sinx == -1)
    {
        printf("未找到该学生!\n");
        return;
    }

    printf("请输入要报名的项目编号: ");
    scanf("%d", &event_id);
    int einx = find_event(event_id);
    if (einx == -1)
    {
        printf("未找到该项目!\n");
        return;
    }

    // 检查是否已报名
    for (int i = 0; i < reg_num; i++)
    {
        if (reg[i].registration_student_id == student_id &&
            reg[i].registration_event_id == event_id)
        {
            printf("该学生已报名该项目!\n");
            return;
        }
    }

    // 添加报名信息
    REG new_reg;
    new_reg.registration_id = reg_num + 1;
    new_reg.registration_student_id = student_id;
    new_reg.registration_event_id = event_id;
    new_reg.registration_time = time(NULL);
    new_reg.registration_grade = -1; // 未录入成绩

    reg[reg_num++] = new_reg;
    printf("报名成功!\n");
}

// 取消报名函数：可通过报名编号或学号删除报名信息
void cancelRegistration()
{
    int choice;
    printf("请选择取消方式：1.通过报名编号 2.通过学号\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int reg_id;
        printf("请输入报名编号: ");
        scanf("%d", &reg_id);
        for (int i = 0; i < reg_num; i++)
        {
            if (reg[i].registration_id == reg_id)
            {
                for (int j = i; j < reg_num - 1; j++)
                {
                    reg[j] = reg[j + 1];
                }
                reg_num--;
                printf("通过报名编号取消报名成功!\n");
                return;
            }
        }
        printf("未找到该报名编号的信息!\n");
    }
    else if (choice == 2)
    {
        int student_id;
        printf("请输入学号: ");
        scanf("%d", &student_id);

        // 统计该学生的所有报名信息
        int found = 0;
        int reg_indexes[REGISTRATION_NUM];
        int reg_ids[REGISTRATION_NUM];
        int count = 0;
        for (int i = 0; i < reg_num; i++)
        {
            if (reg[i].registration_student_id == student_id)
            {
                reg_indexes[count] = i;
                reg_ids[count] = reg[i].registration_id;
                count++;
            }
        }

        if (count == 0)
        {
            printf("未找到该学生的报名信息!\n");
            return;
        }

        printf("该学生的报名信息如下：\n");
        for (int i = 0; i < count; i++)
        {
            print_registration(&reg[reg_indexes[i]]);
        }

        while (1)
        {
            int del_id;
            printf("请输入要取消的报名编号(输入 0 结束): ");
            scanf("%d", &del_id);
            if (del_id == 0)
                break;

            int del_index = -1;
            for (int i = 0; i < reg_num; i++)
            {
                if (reg[i].registration_id == del_id && reg[i].registration_student_id == student_id)
                {
                    del_index = i;
                    break;
                }
            }
            if (del_index == -1)
            {
                printf("未找到该报名编号的信息!\n");
            }
            else
            {
                for (int j = del_index; j < reg_num - 1; j++)
                {
                    reg[j] = reg[j + 1];
                }
                reg_num--;
                printf("报名编号%d取消报名成功!\n", del_id);
            }
        }
    }
    else
    {
        printf("无效的选择!\n");
    }
}

//显示报名信息函数
void displayAllRegistrationInformation()
{
    if (reg_num == 0)
    {
        printf("当前没有任何报名信息!\n");
        return;
    }
    printf("当前报名信息如下:\n");
    for (int i = 0; i < reg_num; i++)
    {
        print_registration(&reg[i]);
	}
}

//查询报名信息函数
void searchForRegistrationInformation()
{
    int choice;
    printf("请选择查询方式：1.通过报名编号 2.通过学号 3.通过项目编号\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        int reg_id;
        printf("请输入报名编号: ");
        scanf("%d", &reg_id);
        for (int i = 0; i < reg_num; i++)
        {
            if (reg[i].registration_id == reg_id)
            {
                print_registration(&reg[i]);
                return;
            }
        }
        printf("未找到该报名编号的信息!\n");
    }
    else if (choice == 2)
    {
        int student_id;
        printf("请输入学号: ");
        scanf("%d", &student_id);
        for (int i = 0; i < reg_num; i++)
        {
            if (reg[i].registration_student_id == student_id)
            {
                print_registration(&reg[i]);
            }
        }
    }
    else if (choice == 3)
    {
        int event_id;
        printf("请输入项目编号: ");
        scanf("%d", &event_id);
        for (int i = 0; i < reg_num; i++)
        {
            if (reg[i].registration_event_id == event_id)
            {
                print_registration(&reg[i]);
            }
        }
    }
    else
    {
        printf("无效的选择!\n");
	}
}

//录入成绩函数
void enterGrades()
{
    int reg_id;
    int i;
    printf("请输入报名编号: ");
    scanf("%d", &reg_id);
    for (i = 0; i < reg_num; i++)
    {
        if (reg[i].registration_id == reg_id)
        {
            if (reg[i].registration_grade >= 0)
            {
                printf("该报名信息已录入成绩!\n");
                return;
            }
            print_registration(&reg[i]);
            printf("请输入成绩: ");
            if (scanf("%lf", &reg[i].registration_grade))
            {
                printf("成绩录入成功!\n");
                return;
            }
            else
            {
                printf("成绩录入失败!\n");
                return;
            }
        }
    }
	printf("未找到该报名编号的信息!\n");
}