#include <iostream>

template <typename T>
T smaller(T val1, T val2){
    return val1 <= val2 ? val1 :val2;
}
template <typename T>
T larger(T val1, T val2){
    return val1 <= val2 ? val2 :val1;
}

int main(int argc, char* argv[]){
    //int smallest, mid, largest, first, second, third = 0; //smaller, larger, diff, sum, product, ratio = 0;
    std::string smallest, mid, largest, first, second, third; //smaller, larger, diff, sum, product, ratio = 0;

    std::cout << "Enter three integers \n";
    while (std::cin >> first >> second >> third){
    if (smaller(first, second) == smaller(first, third)) 
    {smallest = first;
        mid = smaller(second, third);
        largest = larger(second, third);
    }
    else if (smaller(first, second) == smaller(second, third)){
            smallest = second;
            mid= smaller(first, third);
            largest= larger(first, third);
    }
    else {smallest = third;
            mid= smaller(first, second);
            largest= larger(first, second);
    }

    std::cout << "smallest, mid, largest: " << smallest << " " << mid << " " << largest << "\n";
    // larger = val < val2 ? val2 : val;
    // diff = val-val2;
    // sum = val+val2;
    // product = val*val2;
    // ratio= val/val2;
    // std::cout << "smaller" << smaller << "\n";
    // std::cout << "larger" << larger << "\n";
    // std::cout << "diff" << diff << "\n";
    // std::cout << "sum" << sum << "\n";
    // std::cout << "product" << product << "\n";
    // std::cout << "ratio" << ratio << "\n";
    }
    return 0;
}