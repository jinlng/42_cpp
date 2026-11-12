#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
private:
    // Non-instantiable class: private constructors & destructor
    // 构造函数、析构函数、拷贝构造全部私有化！拒绝任何人实例化或拷贝它
    // Purely a stateless utility Class - a static toolbox
    // --- Orthodox Canonical Form ---
    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ScalarConverter& operator=(const ScalarConverter& rhs);
    ~ScalarConverter();

public:
    // 唯一对外暴露的静态接口
    static void convert(const std::string& literal);
};

#endif