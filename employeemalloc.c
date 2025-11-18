#include<stdio.h>
#include<stdlib.h>
struct Employee
{
     int id;
     char name[50];
     float salary;
};
int main()
{
    int N,i;
    float totalSalary=0;
    printf("Enter the number of employees");
    scanf("%d",&N);
    struct Employee*employees=(struct Employee *)malloc(N*sizeof(struct Employee));
    if (employees==NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (i=0;i<N;i++)
    {
        printf("\nEnter details for employee %d\n",i+1);
        printf("Name:");
        scanf(" %[^\n]s", employees[i].name);
        printf("Salary:");
        scanf("%f",&employees[i].salary);
        totalSalary+=employees[i].salary;
    }
    printf("\nTotal salary of %d employees is: %.2f\n",N,totalSalary);
    free(employees);
    return 0;
}
