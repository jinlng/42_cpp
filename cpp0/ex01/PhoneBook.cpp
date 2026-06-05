#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>


// 1. 默认构造
PhoneBook::PhoneBook() : _currentIndex(0), _totalContacts(0) {}

// 2. 拷贝构造
PhoneBook::PhoneBook(const PhoneBook& src) {
    *this = src;
}

// 3. 赋值运算符重载
PhoneBook& PhoneBook::operator=(const PhoneBook& rhs) {
    if (this != &rhs) {
        this->_currentIndex = rhs._currentIndex;
        this->_totalContacts = rhs._totalContacts;
        // 必须用循环把数组里的 8 个 Contact 挨个拷贝一遍
        for (int i = 0; i < 8; i++) {
            this->_contacts[i] = rhs._contacts[i]; 
        }
    }
    return *this;
}

// 4. 析构函数
PhoneBook::~PhoneBook() {}

static std::string getInput(const std::string& prompt)
{
    std::string input;

    while (input.empty())
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (std::cin.eof())
            exit(0);

        if (input.empty())
            std::cout << "Field cannot be empty." << std::endl;
    }
    return input;
}

void PhoneBook::addContact()
{
    Contact contact;

    std::string firstName =
        getInput("First name: ");

    std::string lastName =
        getInput("Last name: ");

    std::string nickname =
        getInput("Nickname: ");

    std::string phoneNumber =
        getInput("Phone number: ");

    std::string darkestSecret =
        getInput("Darkest secret: ");

    contact.setContact(
        firstName,
        lastName,
        nickname,
        phoneNumber,
        darkestSecret);

    _contacts[_currentIndex] = contact;

    _currentIndex = (_currentIndex + 1) % 8;

    if (_totalContacts < 8)
        _totalContacts++;

    std::cout << "Contact successfully added.\n" << std::endl;
}

static std::string formatField(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";

    return str;
}

void PhoneBook::searchContacts()
{
    if (_totalContacts == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout
        << std::setw(10) << "Index" << "|"
        << std::setw(10) << "First Name" << "|"
        << std::setw(10) << "Last Name" << "|"
        << std::setw(10) << "Nickname"
        << std::endl;

    for (int i = 0; i < _totalContacts; i++)
    {
        std::cout
            << std::setw(10) << i << "|"
            << std::setw(10)
            << formatField(_contacts[i].getFirstName()) << "|"
            << std::setw(10)
            << formatField(_contacts[i].getLastName()) << "|"
            << std::setw(10)
            << formatField(_contacts[i].getNickname())
            << std::endl;
    }

    std::string input;

    std::cout << "Enter index: ";
    std::getline(std::cin, input);

    if (std::cin.eof())
        return;

    std::stringstream ss(input);

    int index;

    if (!(ss >> index) || index < 0 || index >= _totalContacts)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::cout
        << "First name: "
        << _contacts[index].getFirstName()
        << std::endl;

    std::cout
        << "Last name: "
        << _contacts[index].getLastName()
        << std::endl;

    std::cout
        << "Nickname: "
        << _contacts[index].getNickname()
        << std::endl;

    std::cout
        << "Phone number: "
        << _contacts[index].getPhoneNumber()
        << std::endl;

    std::cout
        << "Darkest secret: "
        << _contacts[index].getDarkestSecret()
        << std::endl;
}
