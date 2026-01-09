#include <stdio.h>

struct student
{
    int id;
    char name[20];
    int kor, eng, mat;
    int total;
    double avg;
    char grade;
};

int main(void)
{
    int i, j;

    struct student box[5];
    struct student temp;

    for (i = 0; i < 5; i++)
    {
        printf("학번 : ");
        scanf("%d", &box[i].id);

        printf("이름 : ");
        scanf("%s", box[i].name);

        printf("국어 영어 수학 점수 : ");
        scanf("%d %d %d", &box[i].kor, &box[i].eng, &box[i].mat);
        
        box[i].total = box[i].kor + box[i].eng + box[i].mat;
        box[i].avg = box[i].total / 3.0;

        if (box[i].avg >= 90) box[i].grade = 'A';
        else if (box[i].avg >= 80) box[i].grade = 'B';
        else if (box[i].avg >= 70) box[i].grade = 'B';
        else box[i].grade = 'F';
        
    } 
    printf("# 정렬 전 데이터... \n");
    for (i = 0; i < 5; i++)
    {
        printf("%3d %s %3d %3d %3d %3d %.1lf %c\n", 
        box[i].id, box[i].name, box[i].kor, box[i].eng,
        box[i].mat, box[i].total, box[i].avg, box[i].grade);
    }
    
    // 학생들을 총점 기준으로 내림차순 정렬
    for (i = 0; i < 4; i++)  // i는 0부터 4까지 반복 (5명)
    {
        for (j = i + 1; j < 5; j++)  // j는 i+1부터 5까지 반복 (i와 비교)
        {
            if (box[i].total < box[j].total)
            {
                temp = box[i];
                box[i] = box[j];
                box[j] = temp;
            }
        }
    }

    // 정렬 후 데이터 출력
    printf("# 정렬 후 데이터...\n");
    for (i = 0; i < 5; i++)  // 5번 반복하여 정렬된 학생 정보 출력
    {
        printf("%3d %s %3d %3d %3d %3d %.1lf %c\n", 
        box[i].id, box[i].name, box[i].kor, box[i].eng,
        box[i].mat, box[i].total, box[i].avg, box[i].grade);
    }

    return 0;
}