#include <iostream>

int main(int argc, char* argv[]){
    std::string current;
    std::string previous;
    while (std::cin >> current){
        if (current == previous){
            std::cout << "same word: " << current << "\n";
        }
    previous = current;
    }  
    return 0;
}