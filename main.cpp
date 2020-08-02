#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>




// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s){
  
  int answer = 1;
  int len = strlen(s);        //주어진 문자열의 길이
  char *ss = (char*)malloc(sizeof(char) * len);
  strcpy(ss, s);
  int i, j;                      //반복문 용
  int tem;

  for(i=0; i<len-1; i++){
    for(j=i+1; j<len; j++){
      if(ss[i] == ss[j])    {
        tem = 1 + (j-i)%2;               //짝수면 1 더해서 2로 시작, 홀수면 0 더해서 1로시작
        int t, i1 = i, j1 = j;
        printf("%d번째? %d\n", i, j);
        for(t=(j-i)/2; t>0; t--){            //t는 최소 1, 최대 len-1
          printf("여기는?\n");
          if(ss[++i1] == ss[--j1])  {
            printf("진입성공? %d\n", tem);
            tem += 2;
          }
          else{
            tem = 0;
            break;
          }
        }
        if(tem > answer) answer = tem;
      }
    }
  }
  printf("%d", answer);
  return answer;
}



int main(){
  const char *hello = "abcabcddsa";
  solution(hello);
  
}