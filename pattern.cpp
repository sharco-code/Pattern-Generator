#include <iostream>

class patterngen {
public:
    void fill();
    void print();
private:
    int rule_1_max = 45;
    int rule_1_count;
    int height = 20, width = 40;
    bool value = false;
    bool arr[20][40];
};
///////////////////////////////////////////////////////////////////
void patterngen::fill() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(rule_1_count <= rule_1_max) {
                if(arr[i-1][j] || arr[i+1][j] || arr[i][j-1] || arr[i][j+1]) {
                    value = true;
                    rule_1_count++;
                    arr[i][j] = value;
                } else {
                    value = false;
                    arr[i][j] = value;
                }
            } else {
                value = false;
                arr[i][j] = value;
            }
        }
    }
}
void patterngen::print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
} 
////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {
    patterngen pattern;
    pattern.fill();
    pattern.print();
    return 0;
}

/*
[x][y]
(0x 0y, 1x 0y, 2x 0y, 3x 0y, 4x 0y)
(0x 1y, 1x 1y, 2x 1y, 3x 1y, 4x 1y)
(0x 2y, 1x 2y, 2x 2y, 3x 2y, 4x 2y)
*/