#include "head.h"

//辅助函数
//输出报名信息
void print_registration(REG* r)
{
    int sinx = find_student(r->registration_student_id);
    int einx = find_event(r->registration_event_id);
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

void studentRegistration()
{

}