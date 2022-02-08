#include <stdio.h>

int binarySearch(int arr[],int start, int end, int value){
  // arr의 start부터 end까지 값들 중에서
  
  
}

int main() {

  int n,m;
  int arr[100];
  
  scanf("%d",&n);
  // arr은 정렬이 되어 있어야함.
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    
  scanf("%d",&m);
  
  int idx = binarySearch(arr,0,n-1,m);//0번째 부터 n-1까지 m을 찾아달라.
  
  if(idx==-1){
    printf("수가 없습니다.\n");
  }
  else {
    printf("%d번째에 숫자가 있습니다.\n",idx);
  }
  
  return 0;
}