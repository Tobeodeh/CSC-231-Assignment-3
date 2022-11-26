#include<stdio.h>
#include<stdlib.h>
int check(int,int);
int getNumDigits(int);

int main(){
    FILE*str;
    str = fopen("","r");
    if(str == NULL){
        printf("This file is empty");
    }
    int n;
    fscanf(str,"%d",&n);
    for(int i = 0;i<n;i++){
        int num;
        int temp=0, digit = 0, count = 0;
        fscanf(str,"%d",&num);
        temp = num;
        int flag =1;
        int numDigit = getNumDigits(temp);
        while(temp>0){
            digit = temp%10;
            int count = check(num,numDigit);
            if(count != digit){
                printf("Not self-describing");
                flag = 0;
                break;
            }
            temp-temp/10;
            numDigit--;


        }
        if(flag){
            printf("Self-describing");
        }
    }

   
}
// function to check the amount of times a digit appears
   int check(int num, int digit)
   {
    int count = 0;
    while(num>0){
        if(num%10 == digit){
            count++;
        }
        num = num/10;
   }
    return count;
   }
   // function to check the number of digits
   int getNumDigits(int num)
   {
    int digits;
    printf("%d",num);
    while(num>0){
        digits++;
        num=num/10;
    }
    return digits-1;
   }