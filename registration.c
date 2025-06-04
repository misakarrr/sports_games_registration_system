#include "head.h"

//��������
// ����ѧ���������е�����
int find_student(int student_id)
{
    for (int i = 0; i < stu_num; i++)
    {
        if (stu[i].student_id == student_id)
        {
            return i;
        }
    }
    return -1; // δ�ҵ�
}
// ������Ŀ�������е�����
int find_event(int event_id)
{
    for (int i = 0; i < eve_num; i++)
    {
        if (eve[i].event_id == event_id)
        {
            return i;
        }
    }
    return -1; // δ�ҵ�
}

//���������Ϣ
void print_registration(REG* r)
{
    int sinx = find_student(r->registration_student_id);
    int einx = find_event(r->registration_event_id);

    // ��Ч�Լ��
    if (sinx == -1) 
    {
        printf("δ�ҵ���ѧ����Ϣ���������:%d\n", r->registration_id);
        return;
    }
    /*if (einx == -1) 
    {
        printf("δ�ҵ�����Ŀ���������:%d\n", r->registration_id);
        return;
    }*/

    char tm[30];
    strftime(tm, sizeof(tm), "%Y-%m-%d %H:%M:%S", localtime(&r->registration_time));
    printf("�������:%d ѧ��:%d ����:%s ��Ŀ���:%d ��Ŀ:%s ����ʱ��:%s �ɼ�:",
        r->registration_id,
        stu[sinx].student_id,
        stu[sinx].student_name,
        eve[einx].event_id,
        eve[einx].event_name,
        tm
    );
    if (r->registration_grade < 0) printf("δ¼��\n");
    else printf("%0.2f\n", r->registration_grade);
}

//ѧ����������
void studentRegistration()
{
    int student_id, event_id;
    printf("������ѧ��: ");
    scanf("%d", &student_id);
    int sinx = find_student(student_id);
    if (sinx == -1)
    {
        printf("δ�ҵ���ѧ��!\n");
        return;
    }

    printf("������Ҫ��������Ŀ���: ");
    scanf("%d", &event_id);
    int einx = find_event(event_id);
    if (einx == -1)
    {
        printf("δ�ҵ�����Ŀ!\n");
        return;
    }

    // ����Ƿ��ѱ���
    for (int i = 0; i < reg_num; i++)
    {
        if (reg[i].registration_student_id == student_id &&
            reg[i].registration_event_id == event_id)
        {
            printf("��ѧ���ѱ�������Ŀ!\n");
            return;
        }
    }

    // ��ӱ�����Ϣ
    REG new_reg;
    new_reg.registration_id = reg_num + 1;
    new_reg.registration_student_id = student_id;
    new_reg.registration_event_id = event_id;
    new_reg.registration_time = time(NULL);
    new_reg.registration_grade = -1; // δ¼��ɼ�

    reg[reg_num++] = new_reg;
    printf("�����ɹ�!\n");
}

// ȡ��������������ͨ��������Ż�ѧ��ɾ��������Ϣ
void cancelRegistration()
{
    int choice;
    printf("��ѡ��ȡ����ʽ��1.ͨ��������� 2.ͨ��ѧ��\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int reg_id;
        printf("�����뱨�����: ");
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
                printf("ͨ���������ȡ�������ɹ�!\n");
                return;
            }
        }
        printf("δ�ҵ��ñ�����ŵ���Ϣ!\n");
    }
    else if (choice == 2)
    {
        int student_id;
        printf("������ѧ��: ");
        scanf("%d", &student_id);

        // ͳ�Ƹ�ѧ�������б�����Ϣ
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
            printf("δ�ҵ���ѧ���ı�����Ϣ!\n");
            return;
        }

        printf("��ѧ���ı�����Ϣ���£�\n");
        for (int i = 0; i < count; i++)
        {
            print_registration(&reg[reg_indexes[i]]);
        }

        while (1)
        {
            int del_id;
            printf("������Ҫȡ���ı������(���� 0 ����): ");
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
                printf("δ�ҵ��ñ�����ŵ���Ϣ!\n");
            }
            else
            {
                for (int j = del_index; j < reg_num - 1; j++)
                {
                    reg[j] = reg[j + 1];
                }
                reg_num--;
                printf("�������%dȡ�������ɹ�!\n", del_id);
            }
        }
    }
    else
    {
        printf("��Ч��ѡ��!\n");
    }
}

//��ʾ������Ϣ����
void displayAllRegistrationInformation()
{
    if (reg_num == 0)
    {
        printf("��ǰû���κα�����Ϣ!\n");
        return;
    }
    printf("��ǰ������Ϣ����:\n");
    for (int i = 0; i < reg_num; i++)
    {
        print_registration(&reg[i]);
	}
}

//��ѯ������Ϣ����
void searchForRegistrationInformation()
{
    int choice;
    printf("��ѡ���ѯ��ʽ��1.ͨ��������� 2.ͨ��ѧ�� 3.ͨ����Ŀ���\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        int reg_id;
        printf("�����뱨�����: ");
        scanf("%d", &reg_id);
        for (int i = 0; i < reg_num; i++)
        {
            if (reg[i].registration_id == reg_id)
            {
                print_registration(&reg[i]);
                return;
            }
        }
        printf("δ�ҵ��ñ�����ŵ���Ϣ!\n");
    }
    else if (choice == 2)
    {
        int student_id;
        printf("������ѧ��: ");
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
        printf("��������Ŀ���: ");
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
        printf("��Ч��ѡ��!\n");
	}
}

//¼��ɼ�����
void enterGrades()
{
    int reg_id;
    int i;
    printf("�����뱨�����: ");
    scanf("%d", &reg_id);
    for (i = 0; i < reg_num; i++)
    {
        if (reg[i].registration_id == reg_id)
        {
            if (reg[i].registration_grade >= 0)
            {
                printf("�ñ�����Ϣ��¼��ɼ�!\n");
                return;
            }
            print_registration(&reg[i]);
            printf("������ɼ�: ");
            if (scanf("%lf", &reg[i].registration_grade))
            {
                printf("�ɼ�¼��ɹ�!\n");
                return;
            }
            else
            {
                printf("�ɼ�¼��ʧ��!\n");
                return;
            }
        }
    }
	printf("δ�ҵ��ñ�����ŵ���Ϣ!\n");
}