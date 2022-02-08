// 합병정렬, 퀵정렬, 힙정렬
// O(n log n) 
// 배열을 절반씩 나누어 각각 정렬한 후 합친다. (숫자가 한개일때까지 나눈다.)
// 재귀함수를 사용한다.

// 시간복잡도

/* T(n) = n개의 숫자를 합병정렬할 때의 시간복잡도
 1.왼쪽 합병정렬 = T(n/2)
 2.오른족 합병정렬 = T(n/2)
 3.합치기 = O(n)
   T(n) = 2*T(n/2) + O(n)
        = 2(2T(n/4)+O(n/2)) + O(n)
        = 4T(n/4) + 2O(n)
        = 8T(n/8) + 3O(n)
        = 2^(k+1) T(n/(k+1)) + (k+1)O(n) (k+1 = log2 n)
        = n * T(1) + log n * O(n)
        = n * O(1) + O(nlogn)
        = O(n) + O(nlogn)
        = O(nlogn)
*/

/* 재귀 함수 design의 과정

1. 작성하려는 함수의 역할을 말로 명확하게 정의한다. (재귀적으로 할 일)

--> void mergeSort(int arr[], int s,int e)
--> arr을 s번째 값부터 e번째 값까지 합병정렬하는 함수

2. 함수가 기저조건에서 제대로 동작하게 작성한다.

   if( s == e ){ //index가 같으므로 숫자가 1개
     return;
   }
   
3. 함수가 제대로 동작한다고 가정하고 함수를 완성한다.
   
   mid = (s+e)/2;
   mergeSort(arr,s,mid); 왼쪽 정렬
   mergeSort(arr,mid+1,e); 오른쪽 정렬
   merging(s,mid,mid+1,e); 합치기
   
4. 함수를 완성한 후, 기저조건을 수렴함을 보인다.

*/
#include <stdio.h>

void merging(int arr[], int s1, int e1, int s2, int e2){
  //arr의 s1~e1이 왼쪽 절반, s2~e2가 오른쪽 절반일 때
  //이 둘을 합쳐서 arr의 s1~e2를 정렬된 결과로 만드는 함수
  
  // 1 2 4 8  3 4 6 7
  // p        q
  // temp 라는 array에 정렬결과를 저장

  int p,q; // p 와 q의 현재 최솟값을 가리키는 변수
  int temp[100];
  int temp_idx = 0;
  p = s1;
  q = s2;
  while(p <= e1 && q <= e2){
    if(arr[p] <= arr[q]){
      temp[temp_idx++] = arr[p];
      p++;
    }
    else{
      temp[temp_idx++] = arr[q];
      q++;
    }
  }
  
  if(p>e1){
    for(int i=q;i<=e2;i++)
      temp[temp_idx++] = arr[i];
  }
  else if(q>e2){
    for(int i=p;i<=e1;i++)
      temp[temp_idx++] = arr[i];
  }
  
  // temp 완성 후 arr에 넣기
  // arr[s1~e2]까지의 temp 값을 복사
  for(int i=s1; i<=e2; i++){
    arr[i] = temp[i-s1];
  }
}

void mergeSort(int arr[], int start, int end){
  
  //arr의  start 부터 end까지를 합병정렬하는 함수
  
  if(start == end)
    return;
  else{
    // 1. 왼쪽 절반을 합병정렬
    // 2. 오른쪽 절반을 합병정렬
    // 3. 그 둘을 합친다.
    int mid = (start + end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    // arr[start~mid], arr[mid+1~end] 는 정렬이 이미 되어있음
    
    merging(arr,start,mid,mid+1,end);
    
  }
}

int main() {

  int n;
  scanf("%d",&n);
  
  int numbers[n];
  
  for(int i=0; i<n; i++)
    scanf("%d",&numbers[i]);
  
  mergeSort(numbers,0,n-1);
  
  for(int i=0; i<n; i++)
    printf("%d ",numbers[i]);

