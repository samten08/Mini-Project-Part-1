#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Room {
public:
    int rows;
    int cols;
    char** grid;

    Room(int r, int c) {
        rows = r;
        cols = c;
        grid = new char*[rows];
        for (int i = 0; i < rows; i++) {
            grid[i] = new char[cols];
            for (int j = 0; j < cols; j++) {
                if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1 || rand() % 5 == 0) {
                    grid[i][j] = '#';
                } else {
                    grid[i][j] = ' ';
                }
            }
        }
        grid[1][1] = ' ';
    }

    ~Room() {
        for (int i = 0; i < rows; i++) {
            delete[] grid[i];
        }
        delete[] grid;
    }

    bool isWall(int r, int c) {
        return grid[r][c] == '#';
    }

    void draw(int playerRow, int playerCol) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == playerRow && j == playerCol) {
                    cout << "@";
                } else {
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    }
};

class Player {
public:
    int row;
    int col;

    Player() {
        row = 1;
        col = 1;
    }

    void move(char key, Room& room) {
        int newRow = row;
        int newCol = col;

        if (key == 'w') newRow = row - 1;
        if (key == 's') newRow = row + 1;
        if (key == 'a') newCol = col - 1;
        if (key == 'd') newCol = col + 1;

        if (!room.isWall(newRow, newCol)) {
            row = newRow;
            col = newCol;
        }
    }
};

int main() {
    srand(time(0));

    int rows;
    cout << "How many rows? ";
    cin >> rows;

    int cols;
    cout << "How many cols? ";
    cin >> cols;

    Room room(rows, cols);
    Player player;

    room.draw(player.row, player.col);

    char key;
    cin >> key;
    while (key != 'q') {
        player.move(key, room);
        room.draw(player.row, player.col);
        cin >> key;
    }

    return 0;
}