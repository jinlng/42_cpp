#include "ScalarConverter.hpp"
#include <iostream>   // 用于 std::cout
#include <climits>    // 用于数值极限
#include <cstdlib>    // 用于 std::strtod
#include <cmath>      // 用于 std::isnan
#include <iomanip>    // 用于 std::fixed 和 std::setprecision
#include <cctype>     // 提供 std::isprint()

// --- Orthodox Canonical Form ---
// here just define empty bodies
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) {
    (void)rhs;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

// To check if string is a pseudo-literal (6 cases)
static bool isPseudoLiteral(const std::string& literal) {
    return (literal == "-inf" || literal == "+inf" || literal == "nan" ||
            literal == "-inff" || literal == "+inff" || literal == "nanf");
}

// main convert function
void ScalarConverter::convert(const std::string& literal) {
    // 1. Handle Pseudo-Literals (nan, inf)
    if (isPseudoLiteral(literal)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nan" || literal == "nanf") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (literal[0] == '-') {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        } else {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        return;
    }

    // 2. Determine and convert based on literal type
    // Parsing Standard Inputs (Character vs. Number)
    double d = 0.0;
    bool valid = true;

    // Check if it's a single printable character
    // (and not a digit string like "42")
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        // cast its ASCII value into double d backbone
        d = static_cast<double>(literal[0]);
    } else {
        char* end;
        // numerical parsing: e.g. 42.0f parse string to double
        // std::strtod gives where it stopped parsing via end pointer
        d = std::strtod(literal.c_str(), &end);
        // If parsing failed or there are trailing invalid characters 
        // (other than an 'f' suffix for floats)
        // only valid case is `f` at the very end of the string
        if (*end != '\0' && (*end != 'f' || *(end + 1) != '\0')) {
            valid = false;
        }
    }

    // If valid is false, it prints impossible across all four types and exits.
    if (!valid) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // --- CHAR CONVERSION ---
    std::cout << "char: ";
    // out of bound of ASCII or NaN
    if (d < 0 || d > 127 || std::isnan(d)) {
        std::cout << "impossible" << std::endl;
    // Non-Displayable Characters
    } else if (!std::isprint(static_cast<char>(d))) {
        std::cout << "Non displayable" << std::endl;
    // Otherwise, it prints the character wrapped in single quotes (e.g., 'a').
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }

    // --- INT CONVERSION ---
    // Set max and min bounds: Preventive overflow collapse
    std::cout << "int: ";
    if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX) || std::isnan(d)) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }

    // std::fixed and std::setprecision(1) 
    // force the output stream to always show exactly one digit after 
    // the decimal point. We append f to the float version, and leave 
    // the double version plain.
    // --- FLOAT CONVERSION ---
    float f = static_cast<float>(d);
    std::cout << "float: ";
    std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // --- DOUBLE CONVERSION ---
    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}