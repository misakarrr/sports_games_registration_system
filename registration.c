#include "head.h"

//��������
//���������Ϣ
void print_registration(REG* r)
{
    int sinx = find_student(r->registration_student_id);
    int einx = find_event(r->registration_event_id);
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

void studentRegistration()
{

}