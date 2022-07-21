#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct date 
{
    int year;
    int month;
    int day;
};
typedef struct date date;

struct fruit
{
    char name[20];
    int price;
    date expire[4];
    char throw;
};
typedef struct fruit fruit;


void test() { 

    fruit store[5],*p;
    p=store;
    int ex;

    time_t now = time(NULL);
    struct tm *today;
    today = localtime(&now);

    for(int i=0; i<sizeof(store)/sizeof(fruit); i++) {
       
        printf("\n과일 이름 : ");
        gets((p+i)->name);

        printf("가격 : ");
        scanf("%d",&(p+i)->price);

        printf("만기년월일 yyyymmdddd : ");
        scanf("%d",&ex);

        (p+i)->throw='n';
        (p+i)->expire->year=ex/10000;
        (p+i)->expire->month=ex%10000/100;
        (p+i)->expire->day=ex%100;

        while(getchar() != '\n');
    }


    printf("\n오늘 날짜 : %d년 %d월 %d일\n\n",today->tm_year+1900,today->tm_mon+1,today->tm_mday);

    char day[10]={'\0',};
    sprintf(day,"%04d%02d%02d",today->tm_year+1900,today->tm_mon+1,today->tm_mday);
    
    for(int i=0; i<sizeof(store)/sizeof(fruit); i++) {  
        char exp[10]={'\0',};      
        sprintf(exp,"%04d%02d%02d",p[i].expire->year,p[i].expire->month,p[i].expire->day);

        if(atoi(day)>=atoi(exp)) {p[i].throw='y';}
    }

    for(int j=0; j<sizeof(store)/sizeof(fruit); j++) {
        printf("%d) name = %-7s, ",j,(p+j)->name);
        printf("price = %-4d, ",(p+j)->price);
        printf("year = %d, ",(p+j)->expire->year);
        printf("month = %d, ",(p+j)->expire->month);
        printf("day = %d, ",(p+j)->expire->day);
        printf("throw = %c\n",(p+j)->throw);
    }
    
}

void set_throw(fruit *p, int size) {  //폐기여부 결정
    
    time_t now = time(NULL);
    struct tm *today = localtime(&now);
    
    printf("\n오늘 날짜 : %d년 %d월 %d일\n\n",today->tm_year+1900,today->tm_mon+1,today->tm_mday);

    char day[10]={'\0',};
    sprintf(day,"%04d%02d%02d",today->tm_year+1900,today->tm_mon+1,today->tm_mday);

    
    for(int i=0; i<size; i++) {  
        char exp[10]={'\0',};      
        sprintf(exp,"%04d%02d%02d",p[i].expire->year,p[i].expire->month,p[i].expire->day);

        if(atoi(day)>=atoi(exp)) {p[i].throw='y';}
    }
}

 void print_all(fruit *f,int size) {
    for(int i=0; i<size; i++) {
        printf("%d, 이름:%s 가격:%d 만기일:%d%d%d 폐기여부:%c\n",i,f[i].name,f[i].price,f[i].expire->year,f[i].expire->month,f[i].expire->day,f[i].throw);
     }
 }


int main(int agrc, char *argv[]) {
    test();
    return 0;
    }
    