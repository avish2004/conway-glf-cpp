//by AV

#include <iostream>
#include <vector>

using namespace std;

const int width = 800;
const int height = 800;
vector<bool> cells(width * height);

void update_cells() {
    vector<bool> new_cells(width * height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int neighbors = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = (i + di + width) % width;
                    int nj = (j + dj + height) % height;
                    if (cells[ni * height + nj]) neighbors++;
                }
            }
            int index = i * height + j;
            if (cells[index]) new_cells[index] = (neighbors == 2 || neighbors == 3);
            else new_cells[index] = (neighbors == 3);
        }
    }
    cells = new_cells;
}

void draw_cells() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int index = i * height + j;
            if (cells[index]) point(i, j);
        }
    }
}

void setup() {
    size(width, height);
    background(255);
    cells[width/2 * height + height/2] = true;
}

void draw() {
    update_cells();
    draw_cells();
}
