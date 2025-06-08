#include "head.h"

//void displayAllSportsEventInformation() 
//{
//    printf("所有运动项目信息：\n");
//    printf("编号\t名称\t类型\t参赛类型\t时间\t\t场地\t状态\t人数上限\n");
//
//    for (int i = 0; i < eve_num; i++) 
//    {
//        // 转换时间格式为可读字符串
//        char time_str[20];
//        strftime(time_str, 20, "%Y-%m-%d %H:%M", localtime(&eve[i].event_time));
//
//        printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
//            eve[i].event_id,
//            eve[i].event_name,
//            eve[i].event_kind,
//            eve[i].event_type,
//            time_str,
//            eve[i].event_venue,
//            eve[i].event_status,
//            eve[i].event_registration_num);
//    }
//}

//显示所有运动项目信息
void displayAllSportsEventInformation()
{
    printf("所有运动项目信息：\n");
    print_align("编号", 8);
    print_align("名称", 8);        
    print_align("类型", 10);
    print_align("参赛类型", 12);
    print_align("时间", 18);
    print_align("场地", 10);
    print_align("状态", 8);
    print_align("人数上限", 8);
    printf("\n");

    for (int i = 0; i < eve_num; i++)
    {
        char time_str[20];
        strftime(time_str, 20, "%Y-%m-%d %H:%M", localtime(&eve[i].event_time));

        char num_buf[16];
        snprintf(num_buf, sizeof(num_buf), "%d", eve[i].event_id);
        print_align(num_buf, 8);

        print_align(eve[i].event_name, 20);   
        print_align(eve[i].event_kind, 18);
        print_align(eve[i].event_type, 18);
        print_align(time_str, 18);
        print_align(eve[i].event_venue, 10);
        print_align(eve[i].event_status, 8);

        snprintf(num_buf, sizeof(num_buf), "%d", eve[i].event_registration_num);
        print_align(num_buf, 8);

        printf("\n");
    }
}
 
//添加运动项目信息
void addSportsEventInformation() 
{
    if (eve_num >= EVENT_NUM) 
    {
        printf("运动项目数量已达上限，无法添加！\n");
        return;
    }

    EVE newEvent;
    printf("请输入项目信息：\n");

    printf("项目编号: ");
    scanf("%d", &newEvent.event_id);

    printf("项目名称: ");
    scanf("%19s", newEvent.event_name);

    printf("项目类型（田赛，径赛等）: ");
    scanf("%9s", newEvent.event_kind);

    printf("参赛类型（男子项目，女子项目）: ");
    scanf("%9s", newEvent.event_type);

    printf("比赛时间(YYYY-MM-DD HH:MM): ");
    struct tm tm = { 0 };
    scanf("%d-%d-%d %d:%d",
        &tm.tm_year, &tm.tm_mon, &tm.tm_mday,
        &tm.tm_hour, &tm.tm_min);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    newEvent.event_time = mktime(&tm);

    printf("比赛场地: ");
    scanf("%9s", newEvent.event_venue);

    printf("项目状态（报名中，已结束）: ");
    scanf("%9s", newEvent.event_status);

    printf("人数上限: ");
    scanf("%d", &newEvent.event_registration_num);

    eve[eve_num++] = newEvent;
    printf("项目添加成功！\n");
}

//删除运动项目信息
void deleteSportsEventInformation() 
{
    int id;
    printf("请输入要删除的项目编号: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < eve_num; i++) 
    {
        if (eve[i].event_id == id) 
        {
            found = 1;
            // 将后续项目前移
            for (int j = i; j < eve_num - 1; j++) 
            {
                eve[j] = eve[j + 1];
            }
            eve_num--;
            printf("项目删除成功！\n");
            break;
        }
    }

    if (!found) 
    {
        printf("未找到编号为%d的项目！\n", id);
    }
}

//修改运动项目信息
void modifySportsEventInformation() 
{
    int id;
    printf("请输入要修改的项目编号: ");
    scanf("%d", &id);
    getchar(); // 吸收回车

    int found = 0;
    for (int i = 0; i < eve_num; i++) 
    {
        if (eve[i].event_id == id) 
        {
            found = 1;
            printf("请输入新项目信息（不修改请直接回车）：\n");

            char input[100];

            // 项目名称
            printf("项目名称(%s): ", eve[i].event_name);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_name, input, EVENT_NAME - 1);
                eve[i].event_name[EVENT_NAME - 1] = '\0';
            }

            // 项目类型
            printf("项目类型(%s): ", eve[i].event_kind);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_kind, input, EVENT_KIND - 1);
                eve[i].event_kind[EVENT_KIND - 1] = '\0';
            }

            // 参赛类型
            printf("参赛类型(%s): ", eve[i].event_type);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_type, input, EVENT_TYPE - 1);
                eve[i].event_type[EVENT_TYPE - 1] = '\0';
            }

            // 比赛时间
            printf("比赛时间(YYYY-MM-DD HH:MM)(当前:%s): ", "见下方");
            char time_input[32];
            if (fgets(time_input, sizeof(time_input), stdin) && time_input[0] != '\n')
            {
                int y, m, d, h, min;
                if (sscanf(time_input, "%d-%d-%d %d:%d", &y, &m, &d, &h, &min) == 5)
                {
                    struct tm tm = {0};
                    tm.tm_year = y - 1900;
                    tm.tm_mon = m - 1;
                    tm.tm_mday = d;
                    tm.tm_hour = h;
                    tm.tm_min = min;
                    eve[i].event_time = mktime(&tm);
                }
            }

            // 比赛场地
            printf("比赛场地(%s): ", eve[i].event_venue);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_venue, input, EVENT_VENUE - 1);
                eve[i].event_venue[EVENT_VENUE - 1] = '\0';
            }

            // 项目状态
            printf("项目状态(%s): ", eve[i].event_status);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_status, input, EVENT_STATUS - 1);
                eve[i].event_status[EVENT_STATUS - 1] = '\0';
            }

            // 人数上限
            printf("人数上限(%d): ", eve[i].event_registration_num);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                int num = atoi(input);
                if (num > 0)
                    eve[i].event_registration_num = num;
            }

            printf("项目信息修改成功！\n");
            break;
        }
    }

    if (!found) 
    {
        printf("未找到编号为%d的项目！\n", id);
    }
}

//查找运动项目信息
void searchForSportsEventInformation() 
{
    int option;
    while (1)
    {
        printf("请选择查询方式：\n");
        printf("1. 按项目编号查询\n");
        printf("2. 按项目名称查询\n");
        printf("3. 按项目类型查询\n");
        printf("0. 返回上一级菜单\n");
        printf("请输入选项: ");
        scanf("%d", &option);

        if (option == 0)
        {
            printf("返回上一级菜单。\n");
            break;
        }

        char keyword[50];
        int id;
        int found = 0;

        switch (option) 
        {
        case 1:
            printf("请输入项目编号: ");
            scanf("%d", &id);
            printf("查询结果：\n");
            for (int i = 0; i < eve_num; i++) 
            {
                if (eve[i].event_id == id) 
                {
                    found = 1;
                    char time_str[20];
                    strftime(time_str, 20, "%Y-%m-%d %H:%M", localtime(&eve[i].event_time));
                    printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
                        eve[i].event_id,
                        eve[i].event_name,
                        eve[i].event_kind,
                        eve[i].event_type,
                        time_str,
                        eve[i].event_venue,
                        eve[i].event_status,
                        eve[i].event_registration_num);
                }
            }
            break;
        case 2:
            printf("请输入项目名称: ");
            scanf("%49s", keyword);
            printf("查询结果：\n");
            for (int i = 0; i < eve_num; i++) 
            {
                if (strstr(eve[i].event_name, keyword) != NULL) 
                {
                    found = 1;
                    char time_str[20];
                    strftime(time_str, 20, "%Y-%m-%d %H:%M", localtime(&eve[i].event_time));
                    printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
                        eve[i].event_id,
                        eve[i].event_name,
                        eve[i].event_kind,
                        eve[i].event_type,
                        time_str,
                        eve[i].event_venue,
                        eve[i].event_status,
                        eve[i].event_registration_num);
                }
            }
            break;
        case 3:
            printf("请输入项目类型: ");
            scanf("%49s", keyword);
            printf("查询结果：\n");
            for (int i = 0; i < eve_num; i++) 
            {
                if (strstr(eve[i].event_kind, keyword) != NULL) 
                {
                    found = 1;
                    char time_str[20];
                    strftime(time_str, 20, "%Y-%m-%d %H:%M", localtime(&eve[i].event_time));
                    printf("%d\t%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
                        eve[i].event_id,
                        eve[i].event_name,
                        eve[i].event_kind,
                        eve[i].event_type,
                        time_str,
                        eve[i].event_venue,
                        eve[i].event_status,
                        eve[i].event_registration_num);
                }
            }
            break;
        default:
            printf("无效选项！\n");
            continue;
        }

        if (!found) 
        {
            printf("未找到匹配的项目！\n");
        }
    }
}