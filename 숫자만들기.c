#include <stdio.h>
const int MAX = 100001;
const int div = 1000007;
int Table[MAX];
int n;

int main()
{

    //Please Enter Your Code Here
    //맨끝이 1,2,3 인 경우 각각에 대해 세면 전체 경우를 다 센것으로 볼수있음
    //동적계획법

    // N    1 2 --- main
    // +1  (N-1)을 만드는 경우의 수
    // +2  (N-2)을 만드는 경우의 수
    // +3  (N-3)을 만드는 경우의 수
    // .
    // .
    // .
    // +M  (N-M)을 만드는 경우의 수

    // T(i) = T(i-1) + T(i-2) + ... + T(i-M)
    // 초기값 T(0) = 0, T(1) = 1, T(2) = 2 , T(3) = 1 + 2 + (1)

    // scanf("%d %d", &n, &m);

    // // M = 4
    // // Table[1] = 1
    // // Table[2] = Table[1] + 1
    // // Table[3] = Table[1] + Table[2] + 1
    // // Table[4] = Table[3] + Table[2] + Table[1] + 1

    // // M까지는 이렇게 구하고 이후는 앞의 M개를 더하면 됨
    // // Table[5] = Table[1] + Table[2] + Table[3] + Table[4]

    // // 1 ~M
    // Table[1] = 1;
    // int sum = 0;

    // for(int i=2; i<=m; i++){
    //     sum += Table[i-1];
    //     Table[i] = sum + 1;
    // }

    // for(int i=m+1; i<=n; i++){
    //   for (int j=i-m; j<=i-1; j++){
    //     Table[i] += Table[j];
    //   }
    // }

    // printf("%d\n",Table[n]%1000007);

    scanf("%d", &n);
    Table[1] = 1;
    Table[2] = 2;
    Table[3] = 4;

    for (int i = 4; i <= n; i++)
    {
        Table[i] = (Table[i - 1] % div + Table[i - 2] % div + Table[i - 3] % div) % div;
    }
    printf("%d", Table[n]);
    return 0;
}