#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& src) {
    (void)src;
}

Intern& Intern::operator=(const Intern& rhs) {
    // Intern 没有非静态成员变量，直接返回
    (void)rhs;
    return *this;
}

const char* Intern::InvalidFormException::what() const throw() {
    return "Intern Exception: Form not found!";
}

Intern::~Intern(void) {}

// --- 静态辅助函数：分别负责在堆上实例化对应的表单 ---
static AForm* createShrubbery(std::string const & target) {
    return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(std::string const & target) {
    return new RobotomyRequestForm(target);
}
static AForm* createPardon(std::string const & target) {
    return new PresidentialPardonForm(target);
}

// --- 定义一个内部映射结构体 ---
// 里面存了两样东西：表单的名字（字符串）和一个函数指针（Function Pointer）
// 这个指针指向一个返回 AForm* 且接收 std::string 的静态创建函数
// 一旦名字匹配，就直接通过 (*creator)(target) 在内存里动态实例化并返回对应的对象
struct FormMapping {
    std::string name;
    AForm* (*creator)(std::string const & target); // 函数指针
};

// 工厂核心方法（使用函数指针数组替代 if/else）
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // 静态映射表数组, 把“名字”和“对应的函数地址”绑在一起
    FormMapping const mappings[] = {
        { "shrubbery creation", &createShrubbery },
        { "robotomy request", &createRobotomy },
        { "presidential pardon", &createPardon }
    };

    int const totalForms = 3;

    // 循环匹配，触发相对应的函数指针
    for (int i = 0; i < totalForms; ++i) {
        if (mappings[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            // 🌟 通过 (*creator) 函数指针直接调用对应的函数并返回对象！
            return mappings[i].creator(target); // 触发对应的创建函数
        }
    }

    // 未找到对应表单名称时的错误处理
    // std::cout << "Error: Intern cannot create " << formName 
    //           << " because the form name is unknown!" << std::endl;
    // return NULL;
    throw Intern::InvalidFormException();
}
