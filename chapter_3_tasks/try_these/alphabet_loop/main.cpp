#include <iostream>

int main(int argc, char* argv[]){
    char lowercase = 'a';
    char uppercase = 'A';
    int val_lower = int{lowercase};
    int val_upper = int{uppercase};
    for (int i = 0; i < 26; ++i){
        std::cout << char{val_lower} << ' ' << val_lower << '\n';
        std::cout << char{val_upper} << ' ' << val_upper << '\n';
        val_lower += 1;
        val_upper += 1;
    }
    return 0;
}