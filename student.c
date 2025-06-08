#include "head.h"

//��ʾ����ѧ����Ϣ
void displayAllStudentInformation() 
{
    printf("����ѧ����Ϣ��\n");
    printf("ѧ��\t����\t�Ա�\t�༶\tѧԺ\t�绰\n");

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

//���ѧ����Ϣ
void addStudentInformation() 
{
    if (stu_num >= STUDENT_NUM) 
    {
        printf("ѧ�������Ѵ����ޣ��޷���ӣ�\n");
        return;
    }

    STU newStudent;
    printf("������ѧ����Ϣ��\n");

    printf("ѧ��: ");
    scanf("%d", &newStudent.student_id);

    printf("����: ");
    scanf("%9s", newStudent.student_name);

    printf("�Ա�: ");
    scanf("%2s", newStudent.student_sex);

    printf("�༶: ");
    scanf("%9s", newStudent.student_class);

    printf("ѧԺ: ");
    scanf("%19s", newStudent.student_college);

    printf("�绰: ");
    scanf("%19s", newStudent.student_phone);

    stu[stu_num++] = newStudent;
    printf("ѧ����Ϣ��ӳɹ���\n");
}

//ɾ��ѧ����Ϣ
void deleteStudentInformation() 
{
    int id;
    printf("������Ҫɾ����ѧ��ѧ��: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < stu_num; i++) 
    {
        if (stu[i].student_id == id) 
        {
            found = 1;
            // ������ѧ��ǰ��
            for (int j = i; j < stu_num - 1; j++) 
            {
                stu[j] = stu[j + 1];
            }
            stu_num--;
            printf("ѧ����Ϣɾ���ɹ���\n");
            break;
        }
    }

    if (!found) 
    {
        printf("δ�ҵ�ѧ��Ϊ%d��ѧ����\n", id);
    }
}

//�޸�ѧ����Ϣ
void modifyStudentInformation() 
{
    int id;
    printf("������Ҫ�޸ĵ�ѧ��ѧ��: ");
    scanf("%d", &id);
    getchar(); // ���ջس�

    int found = 0;
    for (int i = 0; i < stu_num; i++) 
    {
        if (stu[i].student_id == id) 
        {
            found = 1;

            printf("��������ѧ����Ϣ�����޸���ֱ�ӻس�����\n");

            char input[50];

            printf("����(%s): ", stu[i].student_name);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_name, input, STUDENT_NAME - 1);
                    stu[i].student_name[STUDENT_NAME - 1] = '\0';
                }
            }

            printf("�Ա�(%s): ", stu[i].student_sex);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_sex, input, STUDENT_SEX - 1);
                    stu[i].student_sex[STUDENT_SEX - 1] = '\0';
                }
            }

            printf("�༶(%s): ", stu[i].student_class);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_class, input, STUDENT_CLASS - 1);
                    stu[i].student_class[STUDENT_CLASS - 1] = '\0';
                }
            }

            printf("ѧԺ(%s): ", stu[i].student_college);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_college, input, STUDENT_COLLEGE - 1);
                    stu[i].student_college[STUDENT_COLLEGE - 1] = '\0';
                }
            }

            printf("�绰(%s): ", stu[i].student_phone);
            if (fgets(input, sizeof(input), stdin) != NULL) 
            {
                if (input[0] != '\n') 
                {
                    input[strcspn(input, "\n")] = 0;
                    strncpy(stu[i].student_phone, input, STUDENT_PHONE - 1);
                    stu[i].student_phone[STUDENT_PHONE - 1] = '\0';
                }
            }

            printf("ѧ����Ϣ�޸ĳɹ���\n");
            break;
        }
    }

    if (!found) 
    {
        printf("δ�ҵ�ѧ��Ϊ%d��ѧ����\n", id);
    }
}

//����ѧ����Ϣ
void searchForStudentInformation() 
{
    int option;
    while (1) 
    {
        printf("��ѡ���ѯ��ʽ��\n");
        printf("1. ��ѧ�Ų�ѯ\n");
        printf("2. ��������ѯ\n");
        printf("3. ��ѧԺ��ѯ\n");
        printf("0. �����ϼ��˵�\n");
		printf("������ѡ��: ");
        scanf("%d", &option);

        if (option == 0) 
        {
            printf("�����ϼ��˵���\n");
            return;
        }

        char keyword[50];
        int id;
        int found = 0;

        switch (option) 
        {
        case 1:
            printf("������ѧ��: ");
            scanf("%d", &id);
            printf("��ѯ�����\n");
            printf("ѧ��\t����\t�Ա�\t�༶\tѧԺ\t�绰\n");
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
            printf("����������: ");
            scanf("%49s", keyword);
            printf("��ѯ�����\n");
            printf("ѧ��\t����\t�Ա�\t�༶\tѧԺ\t�绰\n");
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
            printf("������ѧԺ: ");
            scanf("%49s", keyword);
            printf("��ѯ�����\n");
            printf("ѧ��\t����\t�Ա�\t�༶\tѧԺ\t�绰\n");
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
            printf("��Чѡ�������ѡ��\n");
            continue;
        }

        if (!found) 
        {
            printf("δ�ҵ�ƥ���ѧ����\n");
        }
        // ��ѯ�󷵻��ϼ��˵�
        return;
    }
}
