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
        printf("5. �˳�ϵͳ\n");
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
            printf("��лʹ���˶��ᱨ��ϵͳ��\n");
            break;
        default:
            printf("��Чѡ�����������룡\n");
        }
    } while (choice != 5);
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
            printf("ѧ������...\n");
            studentRegistration();
            break;
        case 2:
            printf("ȡ������...\n");
            // ʵ�ִ���
            break;
        case 3:
            printf("��ʾ���б�����Ϣ...\n");
            // ʵ�ִ���
            break;
        case 4:
            printf("���ұ�����Ϣ...\n");
            // ʵ�ִ���
            break;
        case 5:
            printf("¼��ɼ�...\n");
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

