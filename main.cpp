#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "How many rows? ";
    cin >> rows;

    int cols;
    cout << "How many cols? ";
    cin >> cols;

    cout << "Map Size: " << rows << " rows, " << cols << " cols" << endl;

    for (int r = 0; r < rows; r++){
        for (int c= 0; c < cols; c++) {
            if (r == 0 || c == 0 || c == (cols-1) || r == (rows-1)) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

noooo