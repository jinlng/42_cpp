#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
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
    AForm* unknown = someRandomIntern.makeForm("coffee request", "Boss");
    if (unknown) {
        delete unknown;
    } else {
        std::cout << "Correctly handled non-existent form request (returned NULL)." << std::endl;
    }

    return 0;
}