#include <iostream>
#include <chrono>
#include <random>
#include <windows.h>

class patterngen {
public:
    patterngen(int a, int b, int c,int d);
    void fill();
    void print();

private:
    int rule_1_max = 120;
    int rule_1_count = 0;
    int rule_4_max = 3;
    int rule_4_count = 0;

    int height = 20, width = 40;
    bool value = false;
    bool arr[20][40];
};
///////////////////////////////////////////////////////////////////
patterngen::patterngen(int a, int b, int c,int d) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            arr[i][j] = false;
        }
    }
    rule_1_max = c;
    rule_4_max = d;
    arr[a][b] = true;
}

void patterngen::fill() {
    for (int i = 0; i < height; ++i) {          
        for (int j = 0; j < width; ++j) {

             //rule 1 - SOLO SE PUEDEN IMPRIMIR HASTA UN NUMERO DETERMINADO
            if(rule_1_count <= rule_1_max) {     

                //rule 2 - SOLO SE IMPRIME SI NO ESTA EN UNA DE CASLLA LATERAL
                if(j != 0 && i != 0 && j != 39 && i != 19) {                                

                    //rule 3 - SOLO IMPRIME SI TIENE ALGUNO A SU ALREDEDOR
                    //    TOP             BOT           LEFT           RIGHT         LEFT-TOP         LEFT-BOT        RIGHT-TOP       RIGHT-BOT
                    if(arr[i-1][j] || arr[i+1][j] || arr[i][j-1] || arr[i][j+1] || arr[i-1][j-1] || arr[i+1][j-1] || arr[i-1][j+1] || arr[i+1][j+1]) {
                    
                        //rule 4 -  SOLO PUEDE IMPRIMIR LINEAS HASTA UN NUMERO DETERMINADO
                        if(rule_4_count < rule_4_max) {

    value = true;
    rule_1_count++;
    rule_4_count++;
    arr[i][j] = value;

                        } else if (rule_4_count == rule_4_max) {
                            rule_4_count = 0;
                        }
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
    int a, b, c, d;
    std::default_random_engine generator;
    auto generar_entre = [&generator](int min, int max) -> int {
        std::uniform_int_distribution<int> d(min, max);
        return d(generator);
    };

    while(true) {
        system("CLS");
        a = generar_entre(2,18);
        b = generar_entre(2,40);
        c = generar_entre(50,700);
        d = generar_entre(3,9);
        patterngen pattern(a,b,c,d);
        pattern.fill();
        pattern.print(); 
    }
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