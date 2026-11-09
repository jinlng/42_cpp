#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void) {
    // 初始化随机数种子（用于 Robotomy 50% 概率判定）
    std::srand(std::time(NULL));

    std::cout << "========== 1. 创建不同等级的官僚 ==========" << std::endl;
    Bureaucrat president("President", 1);       // 最高阶 (1)
    Bureaucrat manager("Manager", 40);          // 中阶 (40)
    Bureaucrat intern("Intern", 140);            // 低阶 (140)

    std::cout << president << std::endl;
    std::cout << manager << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n========== 2. 测试 ShrubberyCreationForm (145 Sign, 137 Exec) ==========" << std::endl;
    ShrubberyCreationForm shrub("here_is");
    std::cout << shrub << std::endl;

    // 尝试在未签署状态下执行（应当失败）
    manager.executeForm(shrub);

    // 实习生 (140) 签署 (145 门槛，成功)
    intern.signForm(shrub);

    // 实习生 (140) 尝试执行 (137 门槛，等级不够，失败)
    intern.executeForm(shrub);

    // 经理 (40) 执行 (137 门槛，成功，生成 home_shrubbery 文件)
    manager.executeForm(shrub);

    std::cout << "\n========== 3. 测试 RobotomyRequestForm (72 Sign, 45 Exec) ==========" << std::endl;
    RobotomyRequestForm robot("Bender");
    
    // 经理 (40) 签署并多次执行（测试 50% 概率）
    manager.signForm(robot);
    manager.executeForm(robot);
    manager.executeForm(robot);
    manager.executeForm(robot);

    std::cout << "\n========== 4. 测试 PresidentialPardonForm (25 Sign, 5 Exec) ==========" << std::endl;
    PresidentialPardonForm pardon("Arthur Dent");
    
    // 经理 (40) 尝试签署 (25 门槛，失败)
    manager.signForm(pardon);

    // 总统 (1) 签署并执行
    president.signForm(pardon);
    president.executeForm(pardon);

    return 0;
}