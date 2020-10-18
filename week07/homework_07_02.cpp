#include <iostream>

bool funcA() {
    int c;
    std::cin >> c;
    if (c < 10) //Let's assume this is exception
        throw std::out_of_range("Invalid Input!!");
}

int main() {
    try{
        funcA();
    }
    catch (const std::out_of_range& c){
        std::cout << "Exception : "<< c.what() <<  std::endl;
    }
}
