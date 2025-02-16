#include <stdio.h>
#define MAXSIZE 100
// danah Abu Rayya  1210195  lab:6 lecture:3
void uploadDataFile();
void Exit ();
void displayMainMenu();
void addStudent(int ids[],double avgs[],int *size);
void removeStudent(int ids[],double avgs[], int *size);
void searchStudent();
void updateDataFile();
void matchAvgsIds(int ids[],double avgs[],int id,int*size,double avg);
void asc_sort(int ids[], int *size);
void printStudent(int ids[], double avgs[], int *size);
void shift_array_left(int ids[], double avgs[], int *size, int index);
int main() {
    int n=5;


    int ids[MAXSIZE]={5555,6666,7777,8888,9999};
    double avgs[MAXSIZE]={88.7,99.4,77.6,78.6,98.6};
    int x=0;
    printf("Welcome to my student management system");
    uploadDataFile();
    while(x!=4){
        displayMainMenu();
        scanf("%d",&x);
        if(x==1)
        {
            addStudent(ids,avgs,&n);
        }else if(x==2)
        {
            removeStudent(ids,avgs,&n);
        } else if(x==3)
        {
            searchStudent(ids,avgs,&n);
        }else if(x==4)
        {
            printStudent(ids,avgs,&n);
        }else if(x==5)
        {
            Exit();
        }else
        {
            printf("No such operation!\tplease try again");
        }
    }
    return 0;
}
void uploadDataFile()
{
    printf("uploading data file");
    printf("The student's information has been loaded");
}
void displayMainMenu()
{
    printf("\n1- Add a Student\n2- Remove a Student\n3- Search for a Student\n4-Print student list\n5- Exit System\n");
}
void addStudent(int ids[], double avgs[], int *size)
{
    int flag_exists = 0;

    if((*size)<MAXSIZE)
    {
        int entered_id;
        double entered_avg;
        printf("enter a four digits user id\n");
        scanf("%d",&entered_id);
        printf("Entered ID : %d\n",entered_id);
        for (int i = 0; i < (*size); ++i) {
            if(entered_id==ids[i]){
                flag_exists = 1;
                break;
            }
        }
        if(flag_exists==1) {
            printf("Student with corresponding id exists in the list\n");
        }
        else {
            (*size)++;//6
            ids[(*size)-1]=entered_id;
            printf("enter the average of the student\n");
            scanf("%lf",&entered_avg);
        }
        asc_sort(ids,size);
        matchAvgsIds(ids, avgs, entered_id, size,entered_avg);

    }
    printStudent(ids,avgs,size);
}
void removeStudent(int ids[],double avgs[],int *size)
{
    int index=0;
    int flag_not_exsist=0;
    int removed_id;
    if((*size)>0) {
        printf("Enter the ID of the student to be removed\n");
        scanf("%d", &removed_id);
        for (int i = 0; i < *size; ++i) {
            if (removed_id!=ids[i]){
                flag_not_exsist=1;
            }else{
                index=i;
                shift_array_left(ids, avgs, size, index);
                break;
            }
        }
        if(flag_not_exsist==1){
            printf("Student with corresponding id DOES NOT exists in the list\n");
        }
    }
    printStudent(ids,avgs,size);
}
void searchStudent(int ids[],double avgs[],int *size)
{
    int id;
    printf("Enter the id of the student to be searched");
    scanf("%d",&id);
    for (int i = 0; i < (*size); ++i) {
        if(id==ids[i]){
            printf("id : %d\t\tavg : %lf",ids[i],avgs[i]);
            break;
        }
    }
}
void updateDataFile(int ids[],double avgs[],int *size)
{
    printf("updating data file\n");
    printf("data file has been updated\n");
}
void printStudent(int ids[], double avgs[], int *size) {
    for (int i = 0; i < (*size); ++i) {
        printf("%d\t -> %lf\n",ids[i],avgs[i]);
    }
}
void Exit ()
{
    //updateDataFile(int ids[],double avgs[],int *size);
    printf("thank you for using my student management system. GoodBye\n");
}

void asc_sort(int ids[], int * size)
{
    int i, j, temp;
    for(i=0;i< *size;i++)
    {
        for(j=i+1;j< *size;j++)
        {
            if(ids[i]>ids[j])
            {
                temp = ids[i];
                ids[i] = ids[j];
                ids[j] = temp;
            }
        }
    }
}
void matchAvgsIds(int ids[],double avgs[],int id,int*size,double avg){
    int index;
    avgs[(*size)]=avg;
    for (int i = 0; i < *size; ++i) {
        if(id==ids[i]){
            index=i;
        }
        for (int j = index; j <(*size) ; ++j) {
            double temp=avgs[j+1];
            avgs[j+1]=avgs[j];
            avgs[j]=temp;
        }
    }

}
void shift_array_left(int ids[], double avgs[], int *size, int index){
    for ( int i=index ; i < *size; ++i) {


                    int temp = ids[i];
                    double temp2=avgs[i];
                    ids[i] = ids[i+1];
                    avgs[i]=avgs[i+1];
                    ids[i+1] = temp;
                    avgs[i+1]=temp2;

    }
    (*size)--;
}