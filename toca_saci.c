#include <stdio.h>

int map[1010][1010];

int visited[1010][1010];

int clock_directions[4][2] = {
  {-1, 0},
  {0, 1},
  {1, 0},
  {0, -1},
};

int look_around(int line, int column, int counter) {
  for (int i=0; i < 4; i++) {
    int future_line = line + clock_directions[i][0];
    int future_column = column + clock_directions[i][1];

    int future_position = map[future_column][future_line];

    printf("%d\n", counter);

    if (future_position != 0) {
      if (future_position == 1) {
        look_around(future_line, future_column, counter++);
        printf("%d -- %d %d", future_position, future_column, future_line);
      }
      else if (future_position == 3)
        return counter;
    }
  }
  return -1;
}

int main() {
  int lines, columns;
  int stater_line, stater_column;

  scanf("%d%d", &lines, &columns);

  for (int i=0; i < lines; i++)
    for (int j=0; j < columns; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j] == 2) {
        stater_line = i;
        stater_column = j;
      }
    }

  int result = look_around(stater_line, stater_column, 0);
  printf("%d\n", result);

  return 0;
}

