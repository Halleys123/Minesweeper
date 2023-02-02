#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10
#define MINES 10

int board[ROWS][COLUMNS];
bool revealed[ROWS][COLUMNS];

void init_board() {
  int i, j;

  // Initialize all cells to zero
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLUMNS; j++) {
      board[i][j] = 0;
      revealed[i][j] = false;
    }
  }

  // Place mines randomly
  srand(time(NULL));
  for (i = 0; i < MINES; i++) {
    int row = rand() % ROWS;
    int col = rand() % COLUMNS;
    board[row][col] = -1;
      }

  // Calculate numbers for cells
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLUMNS; j++) {
      if (board[i][j] == -1) {
        continue;
      }

      int count = 0;
      if (i > 0 && j > 0 && board[i-1][j-1] == -1) count++;
      if (i > 0 && board[i-1][j] == -1) count++;
      if (i > 0 && j < COLUMNS-1 && board[i-1][j+1] == -1) count++;
      if (j > 0 && board[i][j-1] == -1) count++;
      if (j < COLUMNS-1 && board[i][j+1] == -1) count++;
      if (i < ROWS-1 && j > 0 && board[i+1][j-1] == -1) count++;
      if (i < ROWS-1 && board[i+1][j] == -1) count++;
      if (i < ROWS-1 && j < COLUMNS-1 && board[i+1][j+1] == -1) count++;
      board[i][j] = count;
    }
  }
}

void print_board() {
  int i, j;
    printf("  ");
  for (i = 0; i < COLUMNS; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (i = 0; i < ROWS; i++) {
    printf("%d ", i);
    for (j = 0; j < COLUMNS; j++) {
      if (revealed[i][j]) {
        if (board[i][j] == -1) {
          printf("* ");
        }
        else {
          printf("%d ", board[i][j]);
        }
      }
      else {
        printf(". ");
      }
    }
    printf("\n");
  }
}

int main() {
  init_board();
  while (true) {
    print_board();
    int row, col;
    printf("Enter a row and column to reveal: ");
    scanf("%d %d", &row, &col);
    revealed[row][col] = true;
  }
  return 0;
}


