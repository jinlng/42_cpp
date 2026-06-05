#include "Contact.hpp"

// 1. 默认构造
Contact::Contact() {}

// 2. 拷贝构造：通常直接复用赋值运算符的逻辑
Contact::Contact(const Contact &src)
{
	*this = src;
}

// 3. 赋值运算符重载
Contact &Contact::operator=(const Contact &rhs)
{
	// 防止自我赋值（例如 a = a;）
	if (this != &rhs)
	{
		this->_firstName = rhs._firstName;
		this->_lastName = rhs._lastName;
		this->_nickname = rhs._nickname;
		this->_phoneNumber = rhs._phoneNumber;
		this->_darkestSecret = rhs._darkestSecret;
	}
	return *this;
}

// 4. 析构函数
Contact::~Contact() {}

void Contact::setContact(
	const std::string &firstName,
	const std::string &lastName,
	const std::string &nickname,
	const std::string &phoneNumber,
	const std::string &darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

bool Contact::isEmpty() const { return _firstName.empty(); }