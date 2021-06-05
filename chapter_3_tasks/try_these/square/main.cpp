#include <iostream>

int square(int x){
    int val = 0;
    for(int i = 0; i < x; ++i){
        val += x;
    }
    return val;
}

int main(int argc, char* argv[]){
    for (int i = 0; i < 100; ++i){
        std::cout << i << '\t' << square(i) << '\n';
    }
    return 0;
}