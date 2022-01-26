#include <stdio.h>

int a[105] = {
    0,
};
int n;
const int div = 1000007;
int main()
{
    //Please Enter Your Code Here
    //동적계획법
    //맨끝이 1자인
    //경우 맨 끝이 누워있는 경우로 나누어서 센다

    // 2x4를 채우는 경우의 수 : 2x3을 채우는 경우의 수 + 2x2를 채우는 경우의 수
    // 2x5를 채우는 경우의 수 : 2x4를 채우는 경우의 수 + 2x3을 채우는 경우의 수

    // 1. 부분 문제를 정의
    // T(i) = 2 x i의 상자를 채우는 경우의 수
    // T(2) = 2
    // T(3) = 3

    // T(i) = T(i-1) + T(i-2)
    // = 피보나치 수열
    // for (int i=0; i<=105; i++){
    //   printf("%d\n",a[i]);
    // }
    scanf("%d", &n);

    a[0] = 0, a[1] = 1, a[2] = 2;
    int temp;
    for (int i = 3; i <= n; i++)
    {
        a[i] = (a[i - 1] % div + a[i - 2] % div) % div;
    }
    printf("%d\n", a[n]);

    return 0;
}