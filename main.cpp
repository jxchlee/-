#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2500


char pel[MAX];
int flag=0;


void push(char a){
  pel[++flag] = a;
}



char pop(){
  return pel[flag--];
}



// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int len = strlen(s);        //주어진 문자열의 길이
    int i;                      //반복문 용
    
    printf("Hello C\n");

    return answer;
}


int main(){
  const char *hello = "aaaaa";
  
}