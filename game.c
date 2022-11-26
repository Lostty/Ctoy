#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5
#define SIZE 1024

struct data{
  int initial [SIZE];
  int played [SIZE];
  char choose [SIZE];
  int num [SIZE];
}set[MAX];

int play(int b_number);
int verify(int b_number);
int randomize(int buff);
int check(int check);
int rejoin(char* choosed);

int main(void){

   printf("\n\033[1;32mQuiz number!\033[1;0m\n\nSay a number(limit: 1024):  ");
   scanf("%i", &set[0].played);
   play(*set[0].played);
   
}

int play(int b_number) {
 
if(!b_number) {
   printf("\nJust numbers are allowed.\n");
 } else if(b_number > 1024) { 
   printf("Number is more high than 1024.\n");
 } else if(*set[0].initial == 0) randomize(b_number);
   else if(*set[0].initial != 0 && *set[0].initial != *set[0].played) verify(*set[0].played);
   else if(*set[0].played == *set[0].initial) { 
   printf("\nYou win. Play again?(Y/n):  ");
   scanf("%s", set[0].choose);
   rejoin(set[0].choose);
  }
}

int randomize(int buff) {
int i;
srand(time(NULL));

    for (i = 1; i <= 1; i++) {  
    *set[0].num = rand() % SIZE;
}
    if(*set[0].num > 0) *set[0].initial = *set[0].num;
    else if(!*set[0].num) printf("Fail in alocation.\n");
    
    verify(*set[0].played);
  }

int verify(int buffering) {

  if(buffering != *set[0].initial) {
    check(buffering);
  } 
  }

int check(int check) {

  if(check > *set[0].initial) { 
    printf("Number is more high than X number:  ");
    scanf("%i", &set[0].played);
    play(*set[0].played);
  } else if(check < *set[0].initial){
    printf("Number is more small than X number:  ");
    scanf("%i", &set[0].played);
    play(*set[0].played);
  } 
  }

int rejoin(char* choosed) {

   if(!(strcmp(choosed, "Y"))) {
     *set[0].num = 0;
     *set[0].initial = 0;
     printf("\nSay a number(limit: 1024):  ");
     scanf("%i", &set[0].played);
     play(*set[0].played);
   } else if(!(strcmp(choosed, "n"))) printf("\nFinished.\n");
}