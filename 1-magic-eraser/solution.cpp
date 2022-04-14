#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int cube_area = y * y * 6;
    int n_cubes = (x / y) * (x / y) * (x / y);
    cout << cube_area * n_cubes << endl;
}

