#include <iostream>

int main(int argc, char* argv[]){
    double i,i2 = 0;
    char c = i;
    while(std::cin >> i){
    c = i;
    i2= c;
    std::cout << "orig, char, new: " << i << " " << c << " " << i2 << "\n";    
    }
    return 0;
}