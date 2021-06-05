#include <iostream>

int main(int argc, char* argv[]){
    std::string first_name,friend_name;
    char friend_sex = 0;
    int age = 0;
    std::cout << "Please enter firstname and friend name and sex(m,f) and age \n";
    while (std::cin >> first_name >> friend_name >> friend_sex >> age){

        std::cout << "Hello " << first_name << "\n";

        std::cout << "Have you seen " << friend_name << "?\n";

        if (friend_sex == 'm'){
        std::cout << "If you see " << friend_name << " please ask him to call me. \n";
        }
        if (friend_sex == 'f'){
        std::cout << "If you see " << friend_name << " please ask her to call me. \n";
        }
        if (age > 0 && age < 120){
        std::cout << "I hear you just had a birthday and you are " << age << " years old";
        }
        else {
            std::cerr << "You're kidding \n";
        }

         
    }
    return 0;
}