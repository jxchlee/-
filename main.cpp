#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



int oddeven(int i, int j){
  return (j-i)%2;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
  
  int answer = 1;
  int len = strlen(s);        //주어진 문자열의 길이
  int i, j;                      //반복문 용
  int tem = 1;
    
  for(i=0; i<len-1; i++){
    for(j=i+1; j<len; j++){
      if(s[i] == s[j]){
        
        tem = 1 + oddeven(i,j);               //짝수면 1 더해서 2로 시작, 홀수면 0 더해서 1로시작
        int t, i1 = i, j1 = j;
        for(t=(j1-i1)/2; t<1; t--){            //t는 최소 1, 최대 len-1

          if(s[++i1] == s[++j1]){
            tem += 2;
          }
        }
      }
    }
  }


}


int main(){
  const char *hello = "aaa";
  solution(hello);
  
}