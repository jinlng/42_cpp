#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    int     _currentIndex;
    int     _totalContacts;

    void    _printColumn(std::string str) const;
    std::string _getInput(const std::string& prompt) const;

public:
    // OCF
    PhoneBook();
    PhoneBook(const PhoneBook& src);
    PhoneBook& operator=(const PhoneBook& rhs);
    ~PhoneBook();

    void addContact();
    void searchContacts();
};

#endif