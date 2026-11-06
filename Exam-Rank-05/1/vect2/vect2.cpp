#include "vect2.hpp"

// ==========================================
// 1. Constructors & Destructor (OCF)
// ==========================================

vect2::vect2() : _x(0), _y(0) {}

vect2::vect2(int x, int y) : _x(x), _y(y) {}

vect2::vect2(const vect2& other) : _x(other._x), _y(other._y) {}

vect2::~vect2() {}

// ==========================================
// 2. Assignment & Compound Operators
// ==========================================

vect2& vect2::operator=(const vect2& other) {
    if (this != &other) { // Guard against self-assignment (e.g., v = v;)
        _x = other._x;
        _y = other._y;
    }
    return *this; // Returns reference to allow chaining (e.g., a = b = c;)
}

vect2& vect2::operator+=(const vect2& other) {
    _x += other._x;
    _y += other._y;
    return *this; // Returns reference to allow chaining (e.g., v2 += v2 += v3;)
}

vect2& vect2::operator-=(const vect2& other) {
    _x -= other._x;
    _y -= other._y;
    return *this;
}

vect2& vect2::operator*=(const int scalar) {
    _x *= scalar;
    _y *= scalar;
    return *this;
}

// ==========================================
// 3. Increment & Decrement Operators
// ==========================================

// Prefix (++v): increment first
// returns a reference to the updated object (*this).
vect2& vect2::operator++() {
    ++_x;
    ++_y;
    return *this;
}

// Postfix (v++): save current state in temp, increment object
// return the old, un-incremented copy (temp).
vect2 vect2::operator++(int) {
    vect2 temp(*this); // 1. Save the old state
    ++(*this);         // 2. Increment the current object (using prefix operator)
    return temp;       // 3. Return the saved old state
}

vect2& vect2::operator--() {
    --_x;
    --_y;
    return *this; // returns a reference to the updated object (*this).
}

vect2 vect2::operator--(int) {
    vect2 temp(*this); // 1. Save the old state
    --(*this);         // 2. Decrement the current object
    return temp;       // 3. Return the saved old state
}

// ==========================================
// 4. Unary Operators
// ==========================================

vect2 vect2::operator+() const {
    return *this;
}

// Returns a negated copy without modifying the original object (hence marked const)
vect2 vect2::operator-() const {
    return vect2(-_x, -_y);
}

// ==========================================
// 5. Arithmetic Operators
// ==========================================

vect2 vect2::operator+(const vect2& other) const {
    return vect2(_x + other._x, _y + other._y);
}

vect2 vect2::operator-(const vect2& other) const {
    return vect2(_x - other._x, _y - other._y);
}

vect2 vect2::operator*(const int scalar) const {
    return vect2(_x * scalar, _y * scalar);
}

// ==========================================
// 6. Subscript Operators ([])
// ==========================================

// Non-const version: returns reference so values can be changed (e.g., v1[1] = 12;)
int& vect2::operator[](int i) {
    return (i == 0) ? _x : _y;
}

// Const version:专供 const objects 使用 (e.g., std::cout << v3[1];)
const int& vect2::operator[](int i) const {
    return (i == 0) ? _x : _y;
}

// ==========================================
// 7. Comparison Operators
// ==========================================

bool vect2::operator==(const vect2& other) const {
    return (_x == other._x && _y == other._y);
}

bool vect2::operator!=(const vect2& other) const {
    return !(*this == other); // Cleanly reuses operator==
}

// ==========================================
// 8. Global / Friend Functions
// ==========================================

// Stream operator: lets you do `std::cout << v1`
// Since it's a friend function, it can directly access private members `vector._x` and `vector._y`
std::ostream& operator<<(std::ostream &os, const vect2& vector) {
    os << "{" << vector._x << ", " << vector._y << "}";
    return os;
}

// Global scalar multiplication: allows `3 * v2` (where the integer is on the left)
vect2 operator*(const int scalar, const vect2 &other) {
    return other * scalar; // Reuses the member function `operator*(int)`
}