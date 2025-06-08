#include "head.h"

//void displayAllSportsEventInformation() 
//{
//    printf("�����˶���Ŀ��Ϣ��\n");
//    printf("���\t����\t����\t��������\tʱ��\t\t����\t״̬\t��������\n");
//
//    for (int i = 0; i < eve_num; i++) 
//    {
//        // ת��ʱ���ʽΪ�ɶ��ַ���
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

//��ʾ�����˶���Ŀ��Ϣ
void displayAllSportsEventInformation()
{
    printf("�����˶���Ŀ��Ϣ��\n");
    print_align("���", 8);
    print_align("����", 8);        
    print_align("����", 10);
    print_align("��������", 12);
    print_align("ʱ��", 18);
    print_align("����", 10);
    print_align("״̬", 8);
    print_align("��������", 8);
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
 
//����˶���Ŀ��Ϣ
void addSportsEventInformation() 
{
    if (eve_num >= EVENT_NUM) 
    {
        printf("�˶���Ŀ�����Ѵ����ޣ��޷���ӣ�\n");
        return;
    }

    EVE newEvent;
    printf("��������Ŀ��Ϣ��\n");

    printf("��Ŀ���: ");
    scanf("%d", &newEvent.event_id);

    printf("��Ŀ����: ");
    scanf("%19s", newEvent.event_name);

    printf("��Ŀ���ͣ������������ȣ�: ");
    scanf("%9s", newEvent.event_kind);

    printf("�������ͣ�������Ŀ��Ů����Ŀ��: ");
    scanf("%9s", newEvent.event_type);

    printf("����ʱ��(YYYY-MM-DD HH:MM): ");
    struct tm tm = { 0 };
    scanf("%d-%d-%d %d:%d",
        &tm.tm_year, &tm.tm_mon, &tm.tm_mday,
        &tm.tm_hour, &tm.tm_min);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    newEvent.event_time = mktime(&tm);

    printf("��������: ");
    scanf("%9s", newEvent.event_venue);

    printf("��Ŀ״̬�������У��ѽ�����: ");
    scanf("%9s", newEvent.event_status);

    printf("��������: ");
    scanf("%d", &newEvent.event_registration_num);

    eve[eve_num++] = newEvent;
    printf("��Ŀ��ӳɹ���\n");
}

//ɾ���˶���Ŀ��Ϣ
void deleteSportsEventInformation() 
{
    int id;
    printf("������Ҫɾ������Ŀ���: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < eve_num; i++) 
    {
        if (eve[i].event_id == id) 
        {
            found = 1;
            // ��������Ŀǰ��
            for (int j = i; j < eve_num - 1; j++) 
            {
                eve[j] = eve[j + 1];
            }
            eve_num--;
            printf("��Ŀɾ���ɹ���\n");
            break;
        }
    }

    if (!found) 
    {
        printf("δ�ҵ����Ϊ%d����Ŀ��\n", id);
    }
}

//�޸��˶���Ŀ��Ϣ
void modifySportsEventInformation() 
{
    int id;
    printf("������Ҫ�޸ĵ���Ŀ���: ");
    scanf("%d", &id);
    getchar(); // ���ջس�

    int found = 0;
    for (int i = 0; i < eve_num; i++) 
    {
        if (eve[i].event_id == id) 
        {
            found = 1;
            printf("����������Ŀ��Ϣ�����޸���ֱ�ӻس�����\n");

            char input[100];

            // ��Ŀ����
            printf("��Ŀ����(%s): ", eve[i].event_name);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_name, input, EVENT_NAME - 1);
                eve[i].event_name[EVENT_NAME - 1] = '\0';
            }

            // ��Ŀ����
            printf("��Ŀ����(%s): ", eve[i].event_kind);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_kind, input, EVENT_KIND - 1);
                eve[i].event_kind[EVENT_KIND - 1] = '\0';
            }

            // ��������
            printf("��������(%s): ", eve[i].event_type);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_type, input, EVENT_TYPE - 1);
                eve[i].event_type[EVENT_TYPE - 1] = '\0';
            }

            // ����ʱ��
            printf("����ʱ��(YYYY-MM-DD HH:MM)(��ǰ:%s): ", "���·�");
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

            // ��������
            printf("��������(%s): ", eve[i].event_venue);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_venue, input, EVENT_VENUE - 1);
                eve[i].event_venue[EVENT_VENUE - 1] = '\0';
            }

            // ��Ŀ״̬
            printf("��Ŀ״̬(%s): ", eve[i].event_status);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                input[strcspn(input, "\n")] = 0;
                strncpy(eve[i].event_status, input, EVENT_STATUS - 1);
                eve[i].event_status[EVENT_STATUS - 1] = '\0';
            }

            // ��������
            printf("��������(%d): ", eve[i].event_registration_num);
            if (fgets(input, sizeof(input), stdin) && input[0] != '\n') 
            {
                int num = atoi(input);
                if (num > 0)
                    eve[i].event_registration_num = num;
            }

            printf("��Ŀ��Ϣ�޸ĳɹ���\n");
            break;
        }
    }

    if (!found) 
    {
        printf("δ�ҵ����Ϊ%d����Ŀ��\n", id);
    }
}

//�����˶���Ŀ��Ϣ
void searchForSportsEventInformation() 
{
    int option;
    while (1)
    {
        printf("��ѡ���ѯ��ʽ��\n");
        printf("1. ����Ŀ��Ų�ѯ\n");
        printf("2. ����Ŀ���Ʋ�ѯ\n");
        printf("3. ����Ŀ���Ͳ�ѯ\n");
        printf("0. ������һ���˵�\n");
        printf("������ѡ��: ");
        scanf("%d", &option);

        if (option == 0)
        {
            printf("������һ���˵���\n");
            break;
        }

        char keyword[50];
        int id;
        int found = 0;

        switch (option) 
        {
        case 1:
            printf("��������Ŀ���: ");
            scanf("%d", &id);
            printf("��ѯ�����\n");
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
            printf("��������Ŀ����: ");
            scanf("%49s", keyword);
            printf("��ѯ�����\n");
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
            printf("��������Ŀ����: ");
            scanf("%49s", keyword);
            printf("��ѯ�����\n");
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
            printf("��Чѡ�\n");
            continue;
        }

        if (!found) 
        {
            printf("δ�ҵ�ƥ�����Ŀ��\n");
        }
    }
}