#include <iostream>
#include <string>

int main() {
    // 1. 初始化字符串变量
    std::string str = "HI THIS IS BRAIN";

    // 2. stringPTR: 指向字符串的指针 (C 语言老朋友，存的是地址)
    std::string* stringPTR = &str;

    // 3. stringREF: 字符串的引用 (C++ 新特性，原变量的别名)
    std::string& stringREF = str;

    // --- 打印内存地址 ---
    std::cout << "=== Memory Addresses ===" << std::endl;
    std::cout << "Address of string variable: " << &str << std::endl;
    std::cout << "Address held by stringPTR:  " << stringPTR << std::endl;
    std::cout << "Address held by stringREF:  " << &stringREF << std::endl;

    std::cout << "----------------------------------------" << std::endl;

    // --- 打印变量的值 ---
    std::cout << "=== Values ===" << std::endl;
    std::cout << "Value of string variable:  " << str << std::endl;
    std::cout << "Value pointed to stringPTR: " << stringPTR << std::endl;// edited
    // std::cout << "Value pointed to stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to stringREF: " << stringREF << std::endl;

    return 0;
}
