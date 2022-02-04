// 너비우선 탐색 (BFS)

// 1 ------2 -------6
//  \     / \       /
//   \   /   4------5
//    \ /    / \
//     3 -- 7 -- 8 -- 9

// DFS : 1 --> 2 --> 3 --> 7 --> 4 --> 5 --> 6 --> 8 --> 9
// BFS : 1 --> 2 --> 3 --> 4 --> 6 --> 7 --> 5 --> 8 --> 9

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX= 100;
int n,m;
vector <int> myGraph[MAX];

// 깊이 우선 탐색은 재귀함수를 이용해서 STACK의 개념을 사용
// 너비 우선 탐색은?
// --> QUEUE만 사용하면 됨! 재귀함수를 사용할 필요가 없음

void BFS(){
  // 1. 시작점을 큐에다가 삽입한다
  // 2. 시작점을 색칠한다.
  
  // BFS 시작!
  // 3. 큐에서 하나를 뺀다. 우리의 현재 위치이다.
  // 4. 인접한 모든 정점에게 방문했는지 물어보고, 방문을 하지 않았다면, 색칠하고 큐에 삽입한다.
  // 5. 모두 완료했다면 다시 3을 돌아간다.
  bool check[MAX] = {0,}; // check[x] = true면 x가 색칠이 됨.
  queue <int> Queue;

  // Queue.push(x); // x를 큐에 삽입
  // Queue.pop();  // 큐의 맨 앞에 있는 원소를 제거
  // Queue.front(); // 맨 앞에 있는 원소를 반환
  // Queue.empty(); // 비었으면 true를 반환
  
  Queue.push(1);// 1
  check[1] = true;// 2
  // BFS 시작!
  
  while(!Queue.empty()){//Queue가 빌때까지 반복!
    
    // 끝나는 시점
    // if(Queue.empty()) break;
    
    int current = Queue.front();//맨 앞 받고
    printf("%d ",current);
    Queue.pop();//Queue에서 빼기!
    
    for(int i=0; i<myGraph[current].size(); i++)
    {
      int next = myGraph[current][i];
      // current -- next
      if (check[next] == false){
        check[next] = true;
        Queue.push(next);
      }
    }
  }
  
}

int main() {
  scanf("%d %d",&n,&m);
  
  for(int i=0; i<m; i++){
    int a,b;
    
    scanf("%d %d",&a,&b);// a --- b
    
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
    
  }
  BFS();
  
  return 0;
}