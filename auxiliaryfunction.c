#include "head.h"

//��궨λ����
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
//	printf("ѧ���ɼ�����ϵͳ\n");
//	for (i = 0; i < 2; i++)
//	{
//		SetPosition(POS_X1, ++posy);
//		for (j = 0; j < 55; j++)
//		{
//			printf("-");
//		}
//	}
//	SetPosition(POS_X1, ++posy);
//	printf("1.����ѧ����Ϣ");
//	SetPosition(POS_X4, posy);
//	printf("2.����ѧ���ɼ�");
//	SetPosition(POS_X1, posy += 2);
//	printf("3.ɾ��ѧ����Ϣ");
//	SetPosition(POS_X4, posy);
//	printf("4.��ѧ�Ų��Ҽ�¼");
//	SetPosition(POS_X1, posy += 2);
//	printf("5.���������Ҽ�¼");
//	SetPosition(POS_X4, posy);
//	printf("6.�޸�ѧ����Ϣ");
//	SetPosition(POS_X1, posy += 2);
//	printf("7.����ѧ���ɼ�");
//	SetPosition(POS_X4, posy);
//	printf("8.����γ̳ɼ�");
//	SetPosition(POS_X1, posy += 2);
//	printf("9.��ѧ������");
//	SetPosition(POS_X4, posy);
//	printf("10.����������");
//	SetPosition(POS_X1, posy += 2);
//	printf("11.���ܳɼ���������");
//	SetPosition(POS_X4, posy);
//	printf("12.���ܳɼ���������");
//	SetPosition(POS_X1, posy += 2);
//	printf("13.ѧ���ɼ�ͳ��");
//	SetPosition(POS_X4, posy);
//	printf("14.��ӡѧ����¼");
//	SetPosition(POS_X1, posy += 2);
//	printf("15.ѧ����¼����");
//	SetPosition(POS_X4, posy);
//	printf("16.�Ӵ��̶�ȡѧ����¼");
//	SetPosition(POS_X1, posy += 2);
//	printf("0.�˳�");
//	for (i = 0; i < 2; i++)
//	{
//		SetPosition(POS_X1, ++posy);
//		for (j = 0; j < 55; j++)
//		{
//			printf("-");
//		}
//	}
//	SetPosition(POS_X1, ++posy);
//	printf("��ѡ������Ҫ���еĲ���[0-16]��[  ]\b\b\b");
//	scanf("%d", &option);
//	return option;
//}

// ģ���¼����
void login() 
{
    char username[20];
    char password[20];
    int attempts = 3;

    while (attempts > 0)
    {
        printf("\n=== ��¼ϵͳ ===\n");
        printf("�û���: ");
        scanf("%s", username);
        printf("����: ");
        scanf("%s", password);

        // ����֤��ʵ��Ӧ����Ӧ��洢���û���Ϣ�ȶ�
        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
        {
            printf("��¼�ɹ���\n");
            displayMainMenu();
            return;
        }
        else
        {
            attempts--;
            printf("�û������������ʣ�ೢ�Դ���: %d\n", attempts);
        }
    }

    printf("��¼���Դ������࣬�����˳���\n");
}

// ���˵�
void displayMainMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== �˶��ᱨ��ϵͳ ===\n");
        printf("1. �˶���Ŀ����\n");
        printf("2. ѧ����Ϣ����\n");
        printf("3. ��Ŀ��������\n");
        printf("4. ͳ�Ʋ�ѯ\n");
        printf("5. ���ļ��ж�ȡ��Ϣ\n");
        printf("6. �˳�ϵͳ\n");
        printf("��ѡ��: ");
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
			printf("���ļ��ж�ȡ��Ϣ...\n");
			// ��ȡ��Ŀ��Ϣ��ѧ����Ϣ�ͱ�����Ϣ
			// Ĭ���ļ���Ϊ event.txt, student.txt, registration.txt
            getc(stdin); // ����������еĻ��з�
            readFromFileEvent();
			readFromFileStudent();
			readFromFileRegistration();
            break;
        case 6:
            printf("��лʹ���˶��ᱨ��ϵͳ��\n");
            break;
        default:
            printf("��Чѡ�����������룡\n");
        }
    } while (choice != 6);
}

// �˶���Ŀ����˵�
void eventManagementMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== �˶���Ŀ���� ===\n");
        printf("1. ��ʾ�����˶���Ŀ��Ϣ\n");
        printf("2. ����˶���Ŀ��Ϣ\n");
        printf("3. ɾ���˶���Ŀ��Ϣ\n");
        printf("4. �޸��˶���Ŀ��Ϣ\n");
        printf("5. �����˶���Ŀ��Ϣ\n");
        printf("6. �������˵�\n");
        printf("��ѡ��: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("��ʾ�����˶���Ŀ��Ϣ...\n");
            // ʵ�ִ���
            break;
        case 2:
            printf("����˶���Ŀ��Ϣ...\n");
            // ʵ�ִ���
            break;
        case 3:
            printf("ɾ���˶���Ŀ��Ϣ...\n");
            // ʵ�ִ���
            break;
        case 4:
            printf("�޸��˶���Ŀ��Ϣ...\n");
            // ʵ�ִ���
            break;
        case 5:
            printf("�����˶���Ŀ��Ϣ...\n");
            // ʵ�ִ���
            break;
        case 6:
            printf("�������˵�...\n");
            break;
        default:
            printf("��Чѡ�����������룡\n");
        }
    } while (choice != 6);
}

// ѧ����Ϣ����˵�
void studentManagementMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== ѧ����Ϣ���� ===\n");
        printf("1. ��ʾ����ѧ����Ϣ\n");
        printf("2. ���ѧ����Ϣ\n");
        printf("3. ɾ��ѧ����Ϣ\n");
        printf("4. �޸�ѧ����Ϣ\n");
        printf("5. ����ѧ����Ϣ\n");
        printf("6. �������˵�\n");
        printf("��ѡ��: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("��ʾ����ѧ����Ϣ...\n");
            // ʵ�ִ���
            break;
        case 2:
            printf("���ѧ����Ϣ...\n");
            // ʵ�ִ���
            break;
        case 3:
            printf("ɾ��ѧ����Ϣ...\n");
            // ʵ�ִ���
            break;
        case 4:
            printf("�޸�ѧ����Ϣ...\n");
            // ʵ�ִ���
            break;
        case 5:
            printf("����ѧ����Ϣ...\n");
            // ʵ�ִ���
            break;
        case 6:
            printf("�������˵�...\n");
            break;
        default:
            printf("��Чѡ�����������룡\n");
        }
    } while (choice != 6);
}

// ��Ŀ��������˵�
void registrationManagementMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== ��Ŀ�������� ===\n");
        printf("1. ѧ������\n");
        printf("2. ȡ������\n");
        printf("3. ��ʾ���б�����Ϣ\n");
        printf("4. ���ұ�����Ϣ\n");
        printf("5. ¼��ɼ�\n");
        printf("6. �������˵�\n");
        printf("��ѡ��: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("cls");
            printf("ѧ������...\n");
            studentRegistration();
            break;
        case 2:
			system("cls");
            printf("ȡ������...\n");
            cancelRegistration();
            break;
        case 3:
			system("cls");
            printf("��ʾ���б�����Ϣ...\n");
            displayAllRegistrationInformation();
            break;
        case 4:
			system("cls");
            printf("���ұ�����Ϣ...\n");
            searchForRegistrationInformation();
            break;
        case 5:
			system("cls");
            printf("¼��ɼ�...\n");
            enterGrades();
            break;
        case 6:
			system("cls");
            printf("�������˵�...\n");
            break;
        default:
			system("cls");
            printf("��Чѡ�����������룡\n");
        }
    } while (choice != 6);
}

// ͳ�Ʋ�ѯ�˵�
void statisticsMenu()
{
    system("cls");
    int choice;

    do
    {
        printf("\n=== ͳ�Ʋ�ѯ ===\n");
        printf("1. ͳ��ÿ����Ŀ�ı�������\n");
        printf("2. ͳ��ÿ��ѧԺ�ı�������\n");
        printf("3. ͳ��ÿ��ѧ���ı�����Ŀ��\n");
        printf("4. ��ѯ�����ɼ�\n");
        printf("5. ����ͳ����Ϣ���ļ�\n");
        printf("6. �������˵�\n");
        printf("��ѡ��: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("ͳ��ÿ����Ŀ�ı�������...\n");
            // ʵ�ִ���
            break;
        case 2:
            printf("ͳ��ÿ��ѧԺ�ı�������...\n");
            // ʵ�ִ���
            break;
        case 3:
            printf("ͳ��ÿ��ѧ���ı�����Ŀ��...\n");
            // ʵ�ִ���
            break;
        case 4:
            printf("��ѯ�����ɼ�...\n");
            // ʵ�ִ���
            break;
        case 5:
            printf("����ͳ����Ϣ���ļ�...\n");
            // ʵ�ִ���
            break;
        case 6:
            printf("�������˵�...\n");
            break;
        default:
            printf("��Чѡ�����������룡\n");
        }
    } while (choice != 6);
}

// ��ȡ��Ŀ��Ϣ
void readFromFileEvent()
{
    char filename[256];
    FILE *fp;
    int count = 0;
    EVE temp;

    printf("������Ҫ��ȡ����Ŀ��Ϣ�ļ�����Ĭ�� event.txt����");
    fgets(filename, sizeof(filename), stdin);
    // ȥ�����з�
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') 
    {
        filename[len - 1] = '\0';
    }
    // ���δ�������ݣ�ʹ��Ĭ���ļ���
    if (filename[0] == '\0') 
    {
        strcpy(filename, "event.txt");
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("δ�ҵ���Ŀ��Ϣ�ļ����޷���ȡ��\n");
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

    printf("�ɹ���ȡ%d����Ŀ��Ϣ��\n", count);
}

// ��ȡѧ����Ϣ
void readFromFileStudent()
{
    char filename[256];
    FILE *fp;
    int count = 0;
    STU temp;

    printf("������Ҫ��ȡ����Ŀ��Ϣ�ļ�����Ĭ�� student.txt����");
    fgets(filename, sizeof(filename), stdin);
    // ȥ�����з�
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0';
    }
    // ���δ�������ݣ�ʹ��Ĭ���ļ���
    if (filename[0] == '\0')
    {
        strcpy(filename, "student.txt");
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("δ�ҵ�ѧ����Ϣ�ļ����޷���ȡ��\n");
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
    printf("�ɹ���ȡ%d��ѧ����Ϣ��\n", count);
}

// ��ȡ������Ϣ
void readFromFileRegistration()
{
    char filename[256];
    FILE *fp;
    int count = 0;
    REG temp;

    printf("������Ҫ��ȡ����Ŀ��Ϣ�ļ�����Ĭ�� registration.txt����");
    fgets(filename, sizeof(filename), stdin);
    // ȥ�����з�
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0';
    }
    // ���δ�������ݣ�ʹ��Ĭ���ļ���
    if (filename[0] == '\0')
    {
        strcpy(filename, "registration.txt");
    }

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("δ�ҵ�������Ϣ�ļ����޷���ȡ��\n");
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
    printf("�ɹ���ȡ%d��������Ϣ��\n", count);
}