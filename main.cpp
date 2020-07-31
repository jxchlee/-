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
  if(flag == 0){
    return 0;
  }
  return pel[flag--];
}

void clear(){
  flag = 0;
}

void repeat(int answer){

}



// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 1;
    int len = strlen(s);        //주어진 문자열의 길이
    int i;                      //반복문 용
    int tem;
    
    for(i=0; i<len; i++){
      restart:
      if(i>=1 && s[i] == s[i-1]){ //바로 이전 것과 같은 값을 가질 때 답은 짝수다
        printf("정답은 짝수\n");
        printf("%d 조건\n", flag);
        pop();
        tem = 2;
        while(1){                 //이제 반복문을 통해 다음 값과 이전 스택 값을 비교하며 길이를 늘려나간다.
        printf("%d 반복\n", flag);
          if(s[++i] == pop() && i<len){      //다음값도 스택값과 같다면 길이를 늘린다.
            tem += 2;
          }
          else{
            clear();                // 팰린드롬이 아닐경우 스택 초기화(정확히는 flag를 초기화. 값 자체는 배열에 남아 있음.)
            if(tem>answer) answer = tem;
            goto restart;
          }
        }
      }
      if(i>=2 && s[i] == s[i-2]){ // 2개 전 것과 같은 값을 가질 때 답은 홀수다
        printf("정답은 홀수\n");
        printf("%d 조건\n", flag);
        tem = 3;
        pop();
        pop();
        while(1){                 //이제 반복문을 통해 다음 값과 이전 스택 값을 비교하며 길이를 늘려나간다.
          printf("%d 반복\n", flag);
          if(s[++i] == pop() && i<len){      //다음값도 스택값과 같다면 길이를 늘린다.
            tem += 2;
          }
          else{
            clear();                // 팰린드롬이 아닐경우 스택 초기화(정확히는 flag를 초기화. 값 자체는 배열에 남아 있음.)
            if(tem>answer) answer = tem;
            goto restart;
          }
        }
      }
      else{                       //이도저도 아니라면 스택에 값을 집어넣고 다음으로 넘어가라
        push(s[i]);
        printf("%d 푸시\n", flag);
      }
    }
    printf("%d", answer);

    return answer;
}


int main(){
  const char *hello = "abacde";
  solution(hello);
  
}