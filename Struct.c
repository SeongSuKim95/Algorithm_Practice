//최댓값 기계(maxMachine)

//M.insertNumber(x)
//M.removeNumber(x)
//M.getMax()
#include <stdio.h>

struct maxMachine{
  
  int data[100];
  int len = 0;
  
  void insertNumber(int x){
    data[len++] = x;
  }
  
  void removeNumber(int x){
    for(int i=0; i<len;i++){
      if (data[i] == x){
          for(int j=i; j<len; j++){
            data[j] = data[j+1];
          }
          len--;
          return;
      }
    }
  }
  
  int getMax(){
    int myMax = -999999;
    for(int i=0; i<len; i++){
      
      if(data[i] > myMax){
        myMax = data[i];
      }
    }
    return myMax;
  }
};

int main() {
  
  // 구조체는 capsule화를 구현하기 위한 문법.
  // 구조체는 type을 정의하는 것
  // 구조체를 이용하여 maxMachine이라는 자료구조를 "정의"
  // maxMachine이라는 자료구조 m1,m2를 "선언"
  // maxMachine <- type, struct, class (C++) : 설명서
  // m1,m2 <- 변수, 인스턴스(instance) 개체, 실체가 있는 무언가.
  
  // maxMachine이라는 struct의 인스턴스 m1,m2
  maxMachine m1, m2;
  
  m1.insertNumber(10);
  m1.insertNumber(20);
  m1.insertNumber(5);
  m1.insertNumber(30);
  
  printf("%d\n",m1.getMax());
  
  m1.removeNumber(30);
  m1.removeNumber(10);
  
  printf("%d\n",m1.getMax());
  
  m1.removeNumber(20);
  
  printf("%d\n",m1.getMax());
  return 0;
}