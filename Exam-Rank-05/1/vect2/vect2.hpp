#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
    private:
        int _x; // X coordinate
        int _y; // Y coordinate

    public:
        // ==========================================
        // 1. Orthodox Canonical Form (OCF)
        // ==========================================
        vect2();                             // Default constructor (e.g., vect2 v1;)
        vect2(int x, int y);                 // Parameterized constructor (e.g., vect2 v2(1, 2);)
        vect2(const vect2& other);           // Copy constructor (e.g., const vect2 v3(v2);)
        ~vect2();                            // Destructor (mandatory for OCF)

        // ==========================================
        // 2. Assignment & Compound Operators
        // ==========================================
        vect2& operator=(const vect2& other);  // Copy assignment (e.g., v4 = v2;)
        vect2& operator+=(const vect2& other); // Addition assignment (e.g., v2 += v3;)
        vect2& operator-=(const vect2& other); // Subtraction assignment (e.g., v1 -= v2;)
        vect2& operator*=(const int scalar);   // Scalar multiplication assignment (e.g., v1 *= 42;)

        // ==========================================
        // 3. Increment & Decrement Operators
        // ==========================================
        vect2& operator++();    // Prefix increment (++v): increments first, returns reference
        vect2  operator++(int); // Postfix increment (v++): saves copy, increments, returns copy
        vect2& operator--();    // Prefix decrement (--v)
        vect2  operator--(int); // Postfix decrement (v--)

        // ==========================================
        // 4. Unary Operators
        // ==========================================
        vect2 operator+() const; // Unary plus
        vect2 operator-() const; // Unary negation (-v) -> Must be const!

        // ==========================================
        // 5. Arithmetic Operators
        // ==========================================
        vect2 operator+(const vect2& other) const; // Vector addition (v3 + v3)
        vect2 operator-(const vect2& other) const; // Vector subtraction
        vect2 operator*(const int scalar) const;   // Scalar multiplication (v3 * 2)

        // ==========================================
        // 6. Subscript Operators (Index Access)
        // ==========================================
        int&       operator[](int i);       // Non-const: allows modifying (e.g., v1[1] = 12;)
        const int& operator[](int i) const; // Const: read-only for const objects (e.g., v3[1])

        // ==========================================
        // 7. Comparison Operators
        // ==========================================
        bool operator==(const vect2& other) const; // Equality check (v1 == v3) -> Must be const!
        bool operator!=(const vect2& other) const; // Inequality check (v1 != v3) -> Must be const!

        // ==========================================
        // 8. Friend Declarations
        // ==========================================
        // friend allows this external function to directly access private members (_x, _y)
        friend std::ostream& operator<<(std::ostream &os, const vect2& vector);
};

// ==========================================
// 9. Global Non-member Operators
// ==========================================
// Needed when the left-hand side is NOT a vect2 object (e.g., 3 * v2)
vect2 operator*(const int scalar, const vect2 &other);

#endif