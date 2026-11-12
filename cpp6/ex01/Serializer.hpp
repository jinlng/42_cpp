#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
    // Non-instantiable class: private constructors & destructor
    // 构造函数、析构函数、拷贝构造全部私有化！拒绝任何人实例化或拷贝它
    // Purely a stateless utility Class - a static toolbox
    // --- Orthodox Canonical Form ---
    Serializer();
    Serializer(const Serializer& src);
    Serializer& operator=(const Serializer& rhs);
    ~Serializer();

public:
    // 唯一对外暴露的静态接口
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif