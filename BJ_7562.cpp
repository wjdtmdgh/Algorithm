#include <iostream>

using namespace std;

int T, I;
int target_x, target_y;
int queue[3300000][3];
bool check[300][300];
int front = -1, rear = -1;

int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };

void initialize() {
   front = rear = -1;
   for (int i = 0; i < 300; i++) {
      for (int j = 0; j < 300; j++) {
         check[i][j] = false;
      }
   }
}

int bfs() {
   while(front != rear){
      // 큐에서 꺼냄
      front++;
      int cur_x = queue[front][0];
      int cur_y = queue[front][1];
      int cur_t = queue[front][2];
      if (!check[cur_x][cur_y]) {
         check[cur_x][cur_y] = true;
         if (cur_x == target_x && cur_y == target_y) {
            return cur_t;
         }
         for (int k = 0; k < 8; k++) {
            int new_x = cur_x + dx[k];
            int new_y = cur_y + dy[k];
            if (0 <= new_x && new_x < I && 0 <= new_y && new_y < I) { // 범위 확인
               if (!check[new_x][new_y]) {
                  rear++;
                  queue[rear][0] = new_x;
                  queue[rear][1] = new_y;
                  queue[rear][2] = cur_t + 1;
               } 
            }
         }
      }
   }
   return -1;
}


int main(void) {
   cin >> T;
   while (T--) {
      initialize();
      int start_x, start_y;
      cin >> I;
      cin >> start_x >> start_y;
      cin >> target_x >> target_y;
      rear++;
      queue[rear][0] = start_x;
      queue[rear][1] = start_y;
      queue[rear][2] = 0;
      int answer = bfs();
      cout << answer << '\n';
   }
   return 0;
}