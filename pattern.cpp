#include <iostream>

class patterngen {
public:
    patterngen();
    void seed(int a, int b);
    void fill();
    void print();


    bool wtfx;
    std::string wtf;

private:
    int rule_1_max = 45;
    int rule_1_count;
    int height = 20, width = 40;
    bool value = false;
    bool arr[20][40];
};
///////////////////////////////////////////////////////////////////
patterngen::patterngen() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            arr[i][j] = false;
        }
    }
}
void patterngen::seed(int a, int b) {
    arr[a][b] = true;
}
void patterngen::fill() {
    for (int i = 0; i < height; ++i) {          
        for (int j = 0; j < width; ++j) {
            if(rule_1_count <= rule_1_max) {                                                //rule 1

                if(j != 0 && i != 0 && j != 39 && i != 19) {                                //rule 2

                    if(arr[i-1][j] || arr[i+1][j] || arr[i][j-1] || arr[i][j+1]) {          //rule 3
                        value = true;
                        rule_1_count++;
                        arr[i][j] = value;
                        wtfx = arr[i-1][j];
                    }
                }
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
    pattern.seed(10,8);
    pattern.fill();
    pattern.print();
    std::cout << pattern.wtfx;
    return 0;
}

/*
[i] height [j] width
(0i  0j , 0i  1j  , 0i  2j  , 0i  3j  , 0i  4j ...   0i  40j)
(1i  0j , 1i  1j  , 1i  2j  , 1i  3j  , 1i  4j ...   1i  40j)
(2i  0j , 2i  1j  , 2i  2j  , 2i  3j  , 2i  4j ...   2i  40j)
(3i  0j , 3i  1j  , 3i  2j  , 3i  3j  , 3i  4j ...   3i  40j)
( ......    												)
(20i 0j , 20i 20j , 20i 20j , 20i 20j , 20i 4j ...   20i 40j)
*/