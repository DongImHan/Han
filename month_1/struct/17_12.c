#include <stdio.h>

struct student
{
    int num;
    double grade;
};

// typedef를 사용하여 Student로 별칭 정의
typedef struct student Student;

// print_data 함수의 선언 (포인터를 받아서 데이터 출력)
void print_data(Student *ps);

int main(void)
{
    // s1 학생 정보 초기화 (학번: 215, 학점: 4.2)
    Student s1 = {215, 4.2};

    // s1의 주소를 print_data 함수에 전달
    print_data(&s1);

    return 0;
}

// print_data 함수 정의 (포인터를 통해 학생 데이터 출력)
void print_data(Student *ps)
{
    // 학번과 학점 출력
    printf("학번 : %d\n", ps -> num);
    printf("학점 : %.1lf\n", ps -> grade);
}
