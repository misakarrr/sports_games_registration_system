#include "head.h"

//显示所有学生信息
void displayAllStudentInformation() 
{
    printf("所有学生信息：\n");
    printf("学号\t姓名\t性别\t班级\t学院\t电话\n");

    for (int i = 0; i < stu_num; i++) 
    {
        printf("%d\t%s\t%s\t%s\t%s\t%s\n",
            stu[i].student_id,
            stu[i].student_name,
            stu[i].student_sex,
            stu[i].student_class,
            stu[i].student_college,
            stu[i].student_phone);
    }
}

//添加学生信息
void addStudentInformation() 
{
    if (stu_num >= STUDENT_NUM) 
    {
        printf("学生数量已达上限，无法添加！\n");
        return;
    }

    STU newStudent;
    printf("请输入学生信息：\n");

    printf("学号: ");
    scanf("%d", &newStudent.student_id);

    printf("姓名: ");
    scanf("%9s", newStudent.student_name);

    printf("性别: ");
    scanf("%2s", newStudent.student_sex);

    printf("班级: ");
    scanf("%9s", newStudent.student_class);

    printf("学院: ");
    scanf("%19s", newStudent.student_college);

    printf("电话: ");
    scanf("%19s", newStudent.student_phone);

    stu[stu_num++] = newStudent;
    printf("学生信息添加成功！\n");
}

//删除学生信息
void deleteStudentInformation() 
{
    int id;
    printf("请输入要删除的学生学号: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < stu_num; i++) 
    {
        if (stu[i].student_id == id) 
        {
            found = 1;
            // 将后续学生前移
            for (int j = i; j < stu_num - 1; j++) 
            {
                stu[j] = stu[j + 1];
            }
            stu_num--;
            printf("学生信息删除成功！\n");
            break;
        }
    }

    if (!found) 
    {
        printf("未找到学号为%d的学生！\n", id);
    }
}

//修改学生信息
void modifyStudentInformation() 
{
    int id;
    printf("请输入要修改的学生学号: ");
    scanf("%d", &id);
    getchar(); // 吸收回车

    int found = 0;
    for (int i = 0; i < stu_num; i++) 
    {
        if (stu[i].student_id == id) 
        {
            found = 1;

            printf("请输入新学生信息（不修改请直接回车）：\n");

            char input[50];

            printf("姓名(%s): ", stu[i].student_name);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_name, input, STUDENT_NAME - 1);
                    stu[i].student_name[STUDENT_NAME - 1] = '\0';
                }
            }

            printf("性别(%s): ", stu[i].student_sex);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_sex, input, STUDENT_SEX - 1);
                    stu[i].student_sex[STUDENT_SEX - 1] = '\0';
                }
            }

            printf("班级(%s): ", stu[i].student_class);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_class, input, STUDENT_CLASS - 1);
                    stu[i].student_class[STUDENT_CLASS - 1] = '\0';
                }
            }

            printf("学院(%s): ", stu[i].student_college);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_college, input, STUDENT_COLLEGE - 1);
                    stu[i].student_college[STUDENT_COLLEGE - 1] = '\0';
                }
            }

            printf("电话(%s): ", stu[i].student_phone);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_phone, input, STUDENT_PHONE - 1);
                    stu[i].student_phone[STUDENT_PHONE - 1] = '\0';
                }
            }

            printf("学生信息修改成功！\n");
            break;
        }
    }

    if (!found) 
    {
        printf("未找到学号为%d的学生！\n", id);
    }
}

//查找学生信息
void searchForStudentInformation() 
{
    int option;
    while (1) 
    {
        printf("请选择查询方式：\n");
        printf("1. 按学号查询\n");
        printf("2. 按姓名查询\n");
        printf("3. 按学院查询\n");
        printf("0. 返回上级菜单\n");
		printf("请输入选项: ");
        scanf("%d", &option);

        if (option == 0) 
        {
            printf("返回上级菜单。\n");
            return;
        }

        char keyword[50];
        int id;
        int found = 0;

        switch (option) 
        {
        case 1:
            printf("请输入学号: ");
            scanf("%d", &id);
            printf("查询结果：\n");
            printf("学号\t姓名\t性别\t班级\t学院\t电话\n");
            for (int i = 0; i < stu_num; i++) 
            {
                if (stu[i].student_id == id) 
                {
                    found = 1;
                    printf("%d\t%s\t%s\t%s\t%s\t%s\n",
                        stu[i].student_id,
                        stu[i].student_name,
                        stu[i].student_sex,
                        stu[i].student_class,
                        stu[i].student_college,
                        stu[i].student_phone);
                }
            }
            break;
        case 2:
            printf("请输入姓名: ");
            scanf("%49s", keyword);
            printf("查询结果：\n");
            printf("学号\t姓名\t性别\t班级\t学院\t电话\n");
            for (int i = 0; i < stu_num; i++) 
            {
                if (strstr(stu[i].student_name, keyword) != NULL) 
                {
                    found = 1;
                    printf("%d\t%s\t%s\t%s\t%s\t%s\n",
                        stu[i].student_id,
                        stu[i].student_name,
                        stu[i].student_sex,
                        stu[i].student_class,
                        stu[i].student_college,
                        stu[i].student_phone);
                }
            }
            break;
        case 3:
            printf("请输入学院: ");
            scanf("%49s", keyword);
            printf("查询结果：\n");
            printf("学号\t姓名\t性别\t班级\t学院\t电话\n");
            for (int i = 0; i < stu_num; i++) 
            {
                if (strstr(stu[i].student_college, keyword) != NULL) 
                {
                    found = 1;
                    printf("%d\t%s\t%s\t%s\t%s\t%s\n",
                        stu[i].student_id,
                        stu[i].student_name,
                        stu[i].student_sex,
                        stu[i].student_class,
                        stu[i].student_college,
                        stu[i].student_phone);
                }
            }
            break;
        default:
            printf("无效选项！请重新选择。\n");
            continue;
        }

        if (!found) 
        {
            printf("未找到匹配的学生！\n");
        }
        // 查询后返回上级菜单
        return;
    }
}
