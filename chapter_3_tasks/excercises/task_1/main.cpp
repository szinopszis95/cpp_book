#include <iostream>

int main(int argc, char* argv[]){
    double miles_to_km = 1.609;
    double miles = 0;
    std::cout << "Enter number of miles: \n";
    while(std::cin >> miles){
        std::cout << "Converted to kms: " << miles * miles_to_km << "\n";

    }
    return 0;
}