/*
This is a simple life program that allows the user to change the size of the grid.
The program follows these rules:

1. The neighbors of a given cell are the eight cells that touch
it vertically, horizontally, or diagonally. Every cell is either
living or dead.

2. A living cell stays alive in the next generation if it has either
2 or 3 living neighbors; it dies if it has 0, 1, 4, or more living
neighbors.

3. A dead cell becomes alive in the next generation if it has exactly three neighboring cells,
no more or fewer, that are already alive. All other dead cells remain dead in the next generation.

4. All births and deaths take place at exactly the same time, so
that a dying cell can help to give birth to another, but cannot
prevent the death of others by reducing overcrowding, nor
can cells being born either preserve or kill cells living in the
previous generation.
*/

#include <iostream>
using namespace std;

class Life {
public:
    void initialize(int rows, int cols);
    void print();
    void update();

private:
    int maxrow, maxcol;
    int **grid;
    int neighbor_count(int row, int col);
};

void Life::initialize(int rows, int cols) {
    maxrow = rows;
    maxcol = cols;

    grid = new int *[maxrow + 2];
    for (int i = 0; i < maxrow + 2; ++i)
        grid[i] = new int[maxcol + 2];

    for (int row = 0; row <= maxrow + 1; row++)
        for (int col = 0; col <= maxcol + 1; col++)
            grid[row][col] = 0;

    cout << "List the coordinates for living cells." << endl;
    cout << "Terminate the list with the special pair -1 -1" << endl;
    int row, col;
    cin >> row >> col;

    while (row != -1 || col != -1) {
        if (row >= 1 && row <= maxrow)
            if (col >= 1 && col <= maxcol)
                grid[row][col] = 1;
            else
                cout << "Column " << col << " is out of range." << endl;
        else
            cout << "Row " << row << " is out of range." << endl;
        cin >> row >> col;
    }
}

void Life::print() {
    cout << "\nThe current Life configuration is:" << endl;
    for (int row = 1; row <= maxrow; row++) {
        for (int col = 1; col <= maxcol; col++)
            if (grid[row][col] == 1)
                cout << '*';
            else
                cout << ' ';
        cout << endl;
    }
    cout << endl;
}

int Life::neighbor_count(int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++)
        for (int j = col - 1; j <= col + 1; j++)
            count += grid[i][j];

    count -= grid[row][col];
    return count;
}

void Life::update() {
    int **new_grid = new int *[maxrow + 2];
    for (int i = 0; i < maxrow + 2; ++i)
        new_grid[i] = new int[maxcol + 2];

    for (int row = 1; row <= maxrow; row++)
        for (int col = 1; col <= maxcol; col++)
            switch (neighbor_count(row, col)) {
            case 2:
                new_grid[row][col] = grid[row][col];
                break;
            case 3:
                new_grid[row][col] = 1;
                break;
            default:
                new_grid[row][col] = 0;
            }

    for (int row = 1; row <= maxrow; row++)
        for (int col = 1; col <= maxcol; col++)
            grid[row][col] = new_grid[row][col];

    for (int i = 0; i < maxrow + 2; ++i)
        delete[] new_grid[i];
    delete[] new_grid;
}

void instructions() {
    cout << "Welcome to Conway's game of Life." << endl;
    cout << "This game uses a grid of size m by n in which" << endl;
    cout << "each cell can either be occupied by an organism or not." << endl;
    cout << "The occupied cells change from generation to generation" << endl;
    cout << "according to the number of neighboring cells which are alive." << endl;
}

bool user_says_yes() {
    char response;
    cout << "Continue viewing new generations? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}

int main() {
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    Life configuration;
    instructions();
    configuration.initialize(m, n);
    configuration.print();

    while (user_says_yes()) {
        configuration.update();
        configuration.print();
    }

    return 0;
}
