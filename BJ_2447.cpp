#include <iostream>
#define N_MAX 6561

using namespace std;

int stars[N_MAX][N_MAX]; 

void make_stars(int start_y, int start_x, int n) {
   int next = n / 3;
   if (next == 1) {
      for (int i = start_y; i < start_y + n; i++) {
         for (int j = start_x; j < start_x + n; j++) {
            stars[i][j] = 1;
         }
      }
      stars[start_y + 1][start_x + 1] = 0;
      return;
   }
   for (int i = start_y + next; i < start_y + 2 * next; i++) {
      for (int j = start_x + next; j < start_x + 2 * next; j++) {
         stars[i][j] = 0;
      }
   }
   make_stars(start_y, start_x, next);
   make_stars(start_y, start_x + next, next);
   make_stars(start_y, start_x + next + next, next);
   make_stars(start_y + next, start_x, next);
   make_stars(start_y + next, start_x + next + next, next);
   make_stars(start_y + next + next, start_x, next);
   make_stars(start_y + next + next, start_x + next, next);
   make_stars(start_y + next + next, start_x + next + next, next);
}

int main(void) {
   int n;
   cin >> n;
   make_stars(0, 0, n);
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout<< (stars[i][j]==1?'*':' ');
      }
      cout << '\n';
   }
   return 0;
}