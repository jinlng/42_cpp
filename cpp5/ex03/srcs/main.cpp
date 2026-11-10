#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
    // 初始化随机数种子（用于 Robotomy 50% 概率判定）
    std::srand(std::time(NULL));

    Intern  someRandomIntern;
    Bureaucrat boss("CEO", 1);

    std::cout << "========== 1. 正常创建 Robotomy 表单 ==========" << std::endl;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; // 必须手动 delete，防止内存泄漏！
    }

    std::cout << "\n========== 2. 正常创建 Shrubbery 表单 ==========" << std::endl;
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Coffee_tree");
    if (scf) {
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
    }

    std::cout << "\n========== 3. 正常创建 Presidential 表单 ==========" << std::endl;
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (ppf) {
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
    }

    std::cout << "\n========== 4. 尝试创建未知表单（失败测试） ==========" << std::endl;
    try {
        // 这一步会直接抛出异常，不会有内存泄漏风险
        someRandomIntern.makeForm("phantom coffee request", "Opera");
    } catch (const std::exception& e) {
        std::cout << "Caught error: " << e.what() << std::endl;
    }
    

    return 0;
}