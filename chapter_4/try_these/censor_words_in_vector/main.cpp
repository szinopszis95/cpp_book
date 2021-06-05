#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> fill(std::vector<std::string>& aVector){
    std::string temp;
    std::getline(std::cin, temp);
    std::stringstream ss(temp);
    std::string str;
    while (std::getline(ss, str, ' ')){   
        aVector.push_back(str);
    }
    return aVector;
}

int main(int argc, char* argv[]){
    std::vector<std::string> list;
    fill(list);
    std::vector<std::string> disliked_list;
    fill(disliked_list);


    bool badword = false;
    for (auto x : list){
        badword = false;
        for (auto y : disliked_list){
           if (x == y){
               std::cout << "BLEEP" << ' ';
               badword = true;
               break;
           }
       }
       if (badword){
           continue;
       }
       else {
       std::cout << x << ' ';
       }
    }
    return 0;
}