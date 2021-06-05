#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

void task_1(){
    std::vector<double> elements;
    for (double x; std::cin >> x;){
        elements.push_back(x);
    }
    // compute mean temperature:
    double sum = 0;
    for (int element : elements) sum += element;
    std::cout << "Average temperature: " << sum/elements.size() << '\n';
    // compute median temperature:
    std::sort(elements.begin(), elements.end());
    // sort temperatures
    if(elements.size()%2 == 0){
        std::cout << "Median temperature: " << (elements[elements.size()/2 - 1] + elements[elements.size()/2])/2 << '\n';
    }
    else {
        std::cout << "Median temperature: " << elements[elements.size()/2] << '\n';
    }
}

void task_2(){
    std::vector<double> cities;
    for (double x; std::cin >> x;){
    cities.push_back(x);
    }
}


void task_4(){
    char ans = ' ';
    int current_min = 0;
    int current_max = 100;
    int guess = 0;
    std::cout << "Enter number to guess!" << std::endl;
    std::cin >> guess;
    while (current_min != current_max ){
        std::cout << "Is your number smaller than " << (current_min+current_max+1)/2 << "?" << std::endl;
        std::cin >> ans;
        if (ans == 'y'){
            current_max = (current_min+current_max)/2;
        }
        else if (ans == 'n'){
            current_min = (current_min+current_max+1)/2;
        }
        else if (ans == '|'){
            std::cout << "Exiting...";
            return;
        }
        else {
            std::cout << "Enter a valid answer!" << std::endl;
        }
    }
    std::cout << "Your number is: " << (current_min+current_max+1)/2 << std::endl;
}

void task_4_vector(){
    char ans = ' ';
    int n;
    std::cout << "Enter range to guess from! \n";
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i){
        numbers[i] = i+1;
    }
    while (numbers.size() != 1){
        std::cout << "Is your number smaller than " << numbers[numbers.size()/2] << "?" << std::endl;
        std::cout << numbers.size() << std::endl;;
        std::cin >> ans;
        if (ans == 'y'){
            numbers.erase(numbers.begin()+numbers.size()/2, numbers.end());
        }
        else if (ans == 'n'){
            numbers.erase(numbers.begin(), numbers.begin()+numbers.size()/2);
        }
        else if (ans == '|'){
            std::cout << "Exiting...";
            return;
        }
        else {
            std::cout << "Enter a valid answer!" << std::endl;
        }
    }
    std::cout << "Your number is: " << numbers[0] << std::endl;
}

bool isNumber(std::string input){
    return input.find_first_not_of("-.0123456789") > 0;
}

bool isValidStr(std::string input){
    return input != "|";
}

bool isValidChar(char input){
    return input != '|';
}

int validCalc(std::string& input){
    //std::cout << "Type in a number" << std::endl;
    std::vector<std::string> digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    //std::string input;
    bool valid_input = false;
    //while(1){
    //std::cin >> input;
        for (int i = 0; i < digits.size(); ++i){
            if (isNumber(input) && std::stoi(input) == i){
                std::cout << "Entered number: " << digits[i] << std::endl;
                return i;
            }
            else if (input == digits[i]){
                std::cout << "Entered digit: " << i << std::endl;
                return i;
            }
        }
    if (!valid_input) std::cout << "Type in a single number or digit" << std::endl;
    return 0;
   // }
}

void task_5_6_7(){
    std::string input_1_s = "";
    std::string input_2_s = "";
    int input_1 = 0;
    int input_2 = 0;
    char operation = ' ';

    while (1){
        std::cout << "Enter 2 doubles and an operation" << std::endl;
        do {
        std::cin >> input_1_s;
        if (!isValidStr(input_1_s)) return;
        input_1 = validCalc(input_1_s);
        }
        while (!input_1);
        do
        {
        std::cin >> input_2_s;
        if (!isValidStr(input_2_s)) return;
        input_2 = validCalc(input_2_s);
        }
        while (!input_2);
        do {
        std::cin >> operation;
        if (!isValidChar(operation)) return;

            switch (operation){
                case '+':
                std::cout << "The sum of " << input_1 << " and " << input_2 << " is " << input_1+input_2 << std::endl;
                break;
                case '-':
                std::cout << "The diff of " << input_1 << " and " << input_2 << " is " << input_1-input_2 << std::endl;
                break;
                case '*':
                std::cout << "The product of " << input_1 << " and " << input_2 << " is " << input_1*input_2 << std::endl;
                break;
                case '/':
                std::cout << "The remainder of " << input_1 << " and " << input_2 << " is " << input_1/input_2 << std::endl;
                break;
                default:
                std::cin.clear();
                std::cout << "Enter a valid operation!" << std::endl;
                std::cin.ignore();
            }
        }
        while (!(operation == '+' || operation == '-' || operation == '*' || operation == '/'));
    }
}

double power(double number, int pow){
    if (pow == 0) return 1;
    else {
    for (int i = 0; i < pow; ++i){
        number+= number;
    }
    return number;}
}

void task_8(){
    std::cout << "Enter required grains!" << std::endl;
    double required_grains;
    double current_amount = 0;
    double sum = 0;
    std::cin >> required_grains;
    for (int i = 0; i < 64; ++i){
        if (sum >= required_grains){
            std::cout << "required tiles: " << i+1 << " for: " << required_grains << " grains" << std::endl;
            return;
        }
        current_amount = power(2, i);
        sum+= current_amount;
    }
}

void task_9(){
    std::string input = "";
    std::vector<std::string> options = {"rock", "paper", "scissors"};
    
    while (input != "rock" || input != "paper" || input != "scissors"){
        std::cout << "Enter rock, paper or scissors" << std::endl;
        std::cin >> input;

        std::random_shuffle(options.begin(), options.end());
        if (input == options[0]){
            std::cout << "Its a draw" << std::endl;
        }
        if (input == "rock" && options[0] == "paper"){
            std::cout << "You lose " << std::endl;
        }
        if (input == "rock" && options[0] == "scissors"){
            std::cout << "You win " << std::endl;
        }
        if (input == "paper" && options[0] == "scissors"){
            std::cout << "You lose " << std::endl;
        }
        if (input == "paper" && options[0] == "rock"){
            std::cout << "You win " << std::endl;
        }
        if (input == "scissors" && options[0] == "paper"){
            std::cout << "You win " << std::endl;
        }
        if (input == "scissors" && options[0] == "rock"){
              std::cout << "You win " << std::endl;
        }
        if (input == "|"){
            return;
        }
    }
}

void task_11(){
    int max;
    std::cout << "Enter range to search primes in!" << std::endl;
    std::cin >> max;
    std::vector<int> primes = {2};
    for (int i = 3; i < max; ++i){
        bool isPrime = true;
        for (int j : primes){
            if (i % j == 0){
                isPrime = false;
            }
        }
        if (isPrime){
            primes.push_back(i);
        }
    }
    std::cout << "Primes in range: " << max << std::endl;
    for (auto k : primes){
        std::cout << k << " ";
    }
}

void task_13_14_15_sieve(){
    int n = 0;
    int m = 0;
    int counter = 0;
    std::cout << "Enter range to search primes in and number of them!" << std::endl;
    std::cin >> n >> m;
    std::vector<bool> primes(n, true);
    for (int i = 2; i < sqrt(n); ++i){
        if (primes[i]){
            for (int j = i*i; j < n; j+=i){
                primes[j] = false;
            }
        }
    }
    std::cout << "Primes in range: " << n << std::endl;
    for (int k = 2; k < primes.size(); k++){
        if (primes[k] && counter < m ) {
        counter++;
        std::cout << k << " ";
        }
    }
}


int main(int argc, char* argv[]){
    task_13_14_15_sieve();
    return 0;
}