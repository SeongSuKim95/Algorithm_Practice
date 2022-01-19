#include <stdio.h>

int main()
{

    // node x,y 에 대해
    // 1. x의 모든 조상은 누구인가
    // 2. y의 모든 조상은 누구인가
    // 3. 그중 가장 가까운 공통 조상이 누구인가

    // 두 노드의 조상을 표시할 때, 두번 표시했으면 공통 조상임을 알수있음
    // 가장 가까운 공통 조상을 판별하는 방법 : 두번째 노드를 표시해 나갈때 제일 먼저 만난 "표시된 노드"를 출력하면 됨
    // IDEA : 가장 가까우니까 가장 먼저 보였을 것이다.

    // ROOT 는 node 0이다.

    // parent라는 배열 선언
    int parent[1005] = {
        0,
    };     // parent[x] : 정점 x의 부모노드
    int n; //정점의 개수
    int X, Y;
    bool color[1005] = {
        0,
    }; // color[x]가 true라면 x가 색칠되어있음

    scanf("%d %d %d", &n, &X, &Y);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        //b의 위에 a가 있다
        parent[b] = a;
    }

    while (1)
    {
        color[X] = true;
        //언제까지? root까지!
        if (X == 0)
            break;
        X = parent[X]; // node 위로
    }

    while (1)
    {

        if (color[Y] == true)
        {
            printf("%d\n", Y);
            return 0;
        }

        color[Y] = true;
        Y = parent[Y]; // node 위로
    }
    // (1) X의 모든 조상을 구한다. 색칠한다.
    // (2) Y의 모든 조상을 색칠한다.
    // 만약, 이미 조상이 체크가 되어있다면
    // 이 조상을 출력한다.(가장 가까운 조상이므로)

    return 0;
}