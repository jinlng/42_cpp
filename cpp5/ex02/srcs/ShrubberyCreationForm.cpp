#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbery Creation", 145, 137), _target("DefaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        this->_target = rhs._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    // 1. 检查签署状态与执行者等级
    this->checkExecution(executor);

    // 2. 创建并写入文件 <target>_shrubbery
    std::string filename = this->_target + "_shrubbery";
    std::ofstream outFile(filename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    outFile << "               ,@@@@@@@,\n"
            << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
            << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/88o\n"
            << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
            << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\8888' \n"
            << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' \n"
            << "   `&%\\ ` /%&'    |.|        \\ '|8'   \n"
            << "       |o|        | |         | |     \n"
            << "       |.|        | |         | |     \n"
            << "    _\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__\n";

    outFile.close();
    std::cout << "Tree created in " << filename << std::endl;
}