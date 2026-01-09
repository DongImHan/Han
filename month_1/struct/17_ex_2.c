#include <stdio.h>

// 학생 정보를 저장할 구조체 정의
struct student {
    char name[30];    // 이름
    int kor;       // 국어 점수
    int eng;      // 영어 점수
    int mat;         // 수학 점수
    int total;        // 총점
    double avg;   // 평균
    char grade;       // 학점
};

// 학점 계산 함수
void calculate_grade(struct student* s) {
    s -> total = s -> kor + s -> eng + s -> mat;       // 총점 계산
    s -> avg = s -> total / 3.0;                        // 평균 계산

    // 학점 계산
    if (s -> avg >= 90) {
        s -> avg = 'A';
    } else if (s -> avg >= 80) {
        s->grade = 'B';
    } else if (s -> avg >= 70) {
        s->grade = 'C';
    } else {
        s->grade = 'F';
    }
}

// 총점 기준으로 내림차순 정렬 함수
void sort_students(struct student* students, int n) {
    struct student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (students[i].total < students[j].total) {
                // 학생 i와 학생 j의 데이터를 교환
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    struct student students[5];  // 학생 5명의 정보를 저장할 배열
    int n = 5;

    // 학생 5명에 대한 정보 입력 받기
    for (int i = 0; i < n; i++) {
        printf("학생 %d의 이름을 입력하세요: ", i + 1);
        scanf("%s", students[i].name);
        printf("학생 %d의 국어 점수를 입력하세요: ", i + 1);
        scanf("%d", &students[i].kor);
        printf("학생 %d의 영어 점수를 입력하세요: ", i + 1);
        scanf("%d", &students[i].eng);
        printf("학생 %d의 수학 점수를 입력하세요: ", i + 1);
        scanf("%d", &students[i].mat);

        // 학점 계산
        calculate_grade(&students[i]);
    }

    // 학생들의 총점 기준 내림차순으로 정렬
    sort_students(students, n);

    // 결과 출력
    printf("\n학생 정보 (총점 순으로 정렬):\n");
    printf("이름\t국어\t영어\t수학\t총점\t평균\t학점\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%.2lf\t%c\n", 
               students[i].name, 
               students[i].kor, 
               students[i].eng, 
               students[i].mat, 
               students[i].total, 
               students[i].avg, 
               students[i].grade);
    }

    return 0;
}
