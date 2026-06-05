#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
// 1. 默认构造函数
    Contact();
    // 2. 拷贝构造函数
    Contact(const Contact& src);
    // 3. 赋值运算符重载
    Contact& operator=(const Contact& rhs);
    // 4. 析构函数
    ~Contact();

    void setContact(
        const std::string& firstName,
        const std::string& lastName,
        const std::string& nickname,
        const std::string& phoneNumber,
        const std::string& darkestSecret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    bool isEmpty() const;
};

#endif