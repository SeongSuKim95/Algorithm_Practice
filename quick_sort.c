/*
 재귀함수 디자인의 과정
1. 작성하려는 함수의 역할을 말로 명확하게 정의
2. 함수가 기저조건에서 제대로 동작하게 작성
3. 함수가 제대로 동작한다고 가정하고 함수를 완성한다.
4. 함수를 완성한 후, 기저조건으로 수렴함을 보인다.
*/

/*
 퀵정렬
-원소를 하나 정하여, 해당 원소보다 작은 수들과 큰 수들로 나눈다. 합병정렬에서 절반으로 나눈것과 다름.
1. pivot의 위치는 이후 단계의 정렬 후에도 변하지 않는다.
2. pivot의 왼쪽과 오른쪽 원소들의 자리(방향)가 바뀌지 않는다. (= 왼쪽과 오른쪽을 따로 정렬해도 된다.)
3. 재귀적으로 정렬을 사용한다. 
4. 정렬할 숫자가 하나밖에 없을때까지 정렬

 시간복잡도
pivot이 원소의 개수를 절반으로 나눈다고 할 수 있는가? 당연히 NO
퀵정렬은 평균적으로 O(nlogn)이 걸린다고 말한다.
최악의 경우에는 O(n^2)이 걸림 : 원소가 다 정렬되어있을때!
*/

#include <stdio.h>

int getLeft(int arr[], int start, int end, int pivot, int result[]){
  // arr의 start부터 end까지의 숫자들 중에서
  // pivot보다 작거나 같은 값을 result에 채우는 함수
  // 원소 개수까지 반환
  int idx = 0;
  for(int i=start;i<=end;i++){
    if(arr[i] <= pivot){
      result[idx++] = arr[i];
    }
  }
  return idx;
}

int getRight(int arr[], int start, int end, int pivot, int result[]){
  // arr의 start부터 end까지의 숫자들 중에서
  // pivot보다 큰 값을 result에 채우는 함수
  // 원소 개수까지 반환

  int idx = 0;
  for(int i=start;i<=end;i++){
    if(arr[i] > pivot){
      result[idx++] = arr[i];
    }
  }
  return idx;
}

// arr은 call by reference
void quickSort(int arr[], int start, int end){
  //arr을 start부터 end까지 퀵정렬하는 함수
  if (start >=end) //하나밖에 없는 상태라서 이미 그자체로 정렬이 되어있는 상태임
    return;
  
  int pivot = arr[start];
  int left[100], right[100];
  
  int left_cnt = getLeft(arr,start+1,end,pivot,left);//left를 넘겨주고 채워주면 됨
  int right_cnt = getRight(arr,start+1,end,pivot,right);
  
  // 4 8 2 2 1 7 6 2 3 1
  // pivot = 4
  // left = 2 2 1 2 3 1
  // right = 8 7 6  
  
  // arr => 2 2 1 2 3 4 8 7 6
  // 이 순서대로 array에 넣어야함!
  // for문을 돌려서 하나하나 넣을껀데, 그를 위해 left,right 각각 몇개를 넣었는지 알아야함
  
  for(int i=0; i<left_cnt; i++){
    arr[start + i] = left[i];
  }
  arr[start + left_cnt] = pivot;
  for(int i= 0;i<right_cnt;i++){
    arr[start+left_cnt+1+i] = right[i];
  }
  quickSort(arr,start,start+left_cnt-1);
  quickSort(arr,start+left_cnt+1,end);
}


int main() {
  int n;
  int arr[100];
  
  scanf("%d",&n);
  
  for(int i=0; i<n;i++) scanf("%d ",&arr[i]);
  
  quickSort(arr,0,n-1);
  
  for(int i=0; i<n;i++) printf("%d ",arr[i]);
  
  return 0;
}