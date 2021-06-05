#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
T smaller(T number_1, T number_2){
    return number_1 < number_2 ? number_1 : number_2;
}
template <typename T>
T larger(T number_1, T number_2){
    return number_1 > number_2 ? number_1 : number_2;
}

double cm_to_meter(double cm){
    return cm/100;
}

double inch_to_cm(double inch){
    return inch*2.54;
}

double ft_to_inch(double ft){
    return ft*12;
}

double inch_to_meter(double inch){
    return inch_to_cm(cm_to_meter(inch));
}

double ft_to_meter(double ft){
    return ft_to_inch(inch_to_meter(ft));
}

int main(int argc, char* argv[]){
    double x = 0;
    double smallest = 0;
    double largest = 0;
    double sum = 0;
    std::vector<double> values_vector;
    while(!std::cin.fail()){
        // if (std::cin >> x >> y) {
        //     std::cout << "Entered integers: "<< x << ' ' << y << std::endl;
        //     if (x == y){
        //         std::cout << "The numbers are equal"<< std::endl;
        //     }
        //     else {
        //         std::cout << "The smaller value is: "<< smaller(x,y) << std::endl;
        //         std::cout << "The larger value is: "<< larger(x,y) << std::endl;
        //         if ((larger(x,y) - smaller(x,y)) < 1.0/100){
        //             std::cout << "The two numbers are almost equal " << 1.0/100 << std::endl;
        //         }
        //     }
        // }
        double temp = 0; 
        std::string unit = "";
        if (std::cin >> x >> unit){
            if (unit == "cm" ||
                unit == "m" ||
                unit == "in" ||
                unit == "ft"){
                std::cout << "Entered double and unit: "<< x << unit;

                temp = x;

                if(unit == "cm"){
                    temp = cm_to_meter(x);
                    values_vector.push_back(temp);
                    sum+= temp;
                }

                if(unit == "in"){
                    temp = inch_to_meter(x);
                    values_vector.push_back(temp);
                    sum+= temp;
                }

                if(unit == "ft"){
                    temp = ft_to_meter(x);
                    values_vector.push_back(temp);
                    sum+= temp;
                }
                

                if (temp < smallest || smallest == 0) {
                    std::cout << " it is the smallest so far";
                    smallest = temp;
                }
                if (temp > largest || largest == 0) {
                    std::cout << " it is the largest so far";
                    largest = temp;
                }
                std::cout << std::endl;
            }
            else {
                std::cout << "Enter proper units!" << std::endl;
                std::cin.ignore();
            }
        }
        else { 
            std::cin.clear();
            if (std::cin.peek() == '|'){
                std::cout << "Exiting..." << std::endl;
                break;
            }
            else {
                std::cout << "Enter numbers!" << std::endl;
                std::cin.ignore();
            }
        }
    }
    std::sort(values_vector.begin(), values_vector.end());
    for (double value : values_vector){
        std::cout << value << "m " << std::endl;
    }
    std::cout << "Smallest, largest, sum: " << smallest << "m, " << largest << "m, " << sum << "m" << std::endl;
    return 0;
}