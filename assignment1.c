#include<stdio.h>
#include<string.h>

struct Student{
    int id;
    char name[50];
    int marks[5];
    float average;
};

void inputStudents(struct Student S[],int N);
void calculateAverage(struct Student *S);
void displayTopper(struct Student S[],int N);

int main(){
    int N=5;
    struct Student students[5];
    inputStudents(students,N);
}
void inputStudents(struct Student S[], int N){
    for(int i=0;i<N;i++){
        printf("\nEnter the details for Student %d:\n",i+1);
        printf("ID: ");
        scanf("%d",&S[i].id);
        printf("Name: ");
        scanf("%[^\n]",S[i].name);
        printf("Enter 5 subject marks\n");
        for(int j=0;j<5;j++){
            printf("Mark %d",j+1);
            scanf("%d",&S[i].marks[j]);
        }
        calculateAverage(&S[i]);
    }
}

void calculateAverage(struct Student *S){
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=S->marks[i];
    }
    S->average=sum/5.0f;
}

void displayTopper(struct Student S[], int N){
    int topperIndex=0;
    for(int i=1;i<N;i++){
        if(S[i].average>S[topperIndex].average){
            topperIndex=i;
        }
    }
    printf("\n--- Topper Student ---\n");
    printf("ID : %d\n",S[topperIndex].id);
    printf("Name : %s\n",S[topperIndex].name);
    printf("Average : %.2f\n",S[topperIndex].average);
}