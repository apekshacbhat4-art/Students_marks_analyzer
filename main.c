#include<stdio.h>
void print(char c)
{
    for (int i=0;i<100;i++)
    printf("%c",c);
    printf("\n");
}
struct student_marks{
    float marks;
};
typedef struct student_details{
    char gender;
    char grade;
    char name[100];
    char usn[20];
    char course[20];
    struct student_marks M[3];
    float avg;
}Stdet;
void average(Stdet *p,int n)
{
    int i,j;
    float sum=0;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<3;j++)
        sum+=p->M[j].marks;
        p->avg=sum/3.0;
        p++;
    }
}
void GRADES(Stdet *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(p->avg >= 90 && p->avg <= 100)
           p->grade='O';
        else if(p->avg >= 80 && p->avg <= 89)
           p->grade='A';
        else if(p->avg >= 70 && p->avg <= 79)
           p->grade='B';
        else if(p->avg >= 60 && p->avg <= 69)
           p->grade='C';
        else if(p->avg >= 50 && p->avg <= 59)
           p->grade='D';
        else if(p->avg >= 40 && p->avg <= 49)
           p->grade='E';
        else
           p->grade='F';
      p++;
    }
}
int main()
{
    int n,i,j;
    printf("Enter number of students: ");
    scanf("%d",&n);
    Stdet S[n];
    for(i=0;i<n;i++)
    {
        printf("\n\n%50s %d***\n\n","***ENTER DETAILS OF STUDENT",i+1);
        printf("NAME: ");
        scanf(" %[^\n]",S[i].name);
        getchar();
        printf("USN: ");
        scanf(" %[^\n]",S[i].usn);
        getchar();
        printf("COURSE: ");
        scanf(" %[^\n]",S[i].course);
        getchar();
        printf("GENDER (M/F) : ");
        scanf("%c",&S[i].gender);
        getchar();
        printf("MARKS:\n");
        for(j=0;j<3;j++)
        {
            if(j==0)
            printf("Mathematics: ");
            else if(j==1)
            printf("Physics: ");
            else
            printf("Chemistry: ");
        scanf("%f",&S[i].M[j].marks);
        }
    }
    Stdet *p=S;
    average(p,n);
    GRADES(p,n);
    print('*');
    printf("%50s\n","STUDENT DETAILS");
    print('*');
    print('-');
    printf("| %-11s | %-20s | %-6s | %-6s | %-24s | %-6s | %-6s |\n","USN","NAME","GENDER","COURSE","        MARKS","AVG","GRADE");
    print('-');
    printf("| %-11c | %-20c | %-6c | %-6c | %-6s | %-6s | %-6s | %-6c | %-6c |\n",' ',' ',' ',' ',"MATHS","PHY","CHEM",' ',' ');
    print('-');
    for(i=0;i<n;i++)
    {
       printf("| %-11s | %-20s | %-6c | %-6s | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-6c |\n",p->usn,p->name,p->gender,p->course,(*p).M[0].marks,(*p).M[1].marks,(*p).M[2].marks,p->avg,p->grade);
       p++;
       
    }
    return 0;
}

