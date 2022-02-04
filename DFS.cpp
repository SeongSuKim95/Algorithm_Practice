
//깊이우선탐색(Depth First Search) 스택을 이용하여 그래프를 순회하는 방법
//너비우선탐색(Breadth First Search) Queue를 이용하여 그래프를 순회하는 방법
// Stack을 언제 쓰지?
// 1.일들을 처리하는데에 선행관계가 존재할때!
// 2.Stack은 발자취를 많이 남길때 사용된다.
// 3.Stack = 선행관계
// 철학 : 나를 먼저 방문하고 그 다음으로 인접한 노드를 차례로 방문 (단, 방문했던 노드는 방문하지 않는다)


//    6
//  /    \
// /      \
// 1 ---- 2 ------3 
//          \    / \
//           \  /   \
//             4------5
// 1에서 시작? (작은 이웃 node먼저 순회)
// 1 2 3 4 5 ( 4 3 2 ) 6
// DFS(v,visited) 정점 v에서 시작,재귀함수(재귀함수는 스택을 사용)

// 1. v를 방문했다고 처리한다
// 2. v와 인접한 모든 w에 대하여 다음을 반복
// 3. 만약 w를 아직 방문하지 않았다면,
// 4. DFS(w, visited)
// 5. 방문순서 반환
  
// void DFS(Graph graph, int x, bool visited[]){//graph라는 그래프를 x부터 DFS하라!(단,visited는 방문 기록)
//   visited[x] = true; // true = 방문함, false = 아직 방문 안함
//   for (int i=0; i<graph[x].size(); i++){//for문? 이웃들 하나하나를 보겠다.
//     int y = graph[x][i];//y로 하나의 이웃을 check
//     if(visited[y] == false){
//       DFS(graph,y,visited);//graph라는 그래프를 y부터 시작해서 DFS하라!
//     }   
//   }
// }

// 깊이우선 탐색 예제 (DFS)
// 1 ------2 -------6
//  \     / \       /
//   \   /   4------5
//    \ /    / \
//     3 -- 7 -- 8 -- 9

// 1 --> 2 --> 3 --> 7 --> 4 --> 5 --> 6 --> 8 --> 9

// 9 12 노드, 간선

// 1 2
// 1 3
// 2 3
// 2 4 
// 2 6
// 3 7
// 4 5 
// 4 7
// 4 8 
// 5 6
// 7 8
// 8 9

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100;
int n,m;

vector <int> myGraph[MAX]; // myGraph[x] = x의 인접리스트
bool visited[MAX]; // visited[MAX] = node 방문 기록
//어차피 recursive에서 계속 참조하므로 global로 선언하자.

void DFS(int x){
  // x부터 시작해서 DFS하여 그 순서를 출력하는 함수
  // 단, visited에 방문 기록이 있음
  visited[x] = true;
  printf("%d \n",x);
  for(int i=0; i<myGraph[x].size();i++){
    int y = myGraph[x][i];
    if (visited[y] == false){
      DFS(y);
    }
  }
}

int main() {

  scanf("%d %d",&n,&m);
  
  for(int i=0; i<m; i++){
    int a,b;
    scanf("%d %d",&a,&b);
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
    
  }
  DFS(1);
  return 0;
}