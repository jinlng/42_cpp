#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    std::cout << "========== 1. 测试表单非法构造 ==========" << std::endl;
    try {
        Form invalidForm("Tax Form", 0, 50); // 应该抛出异常
    } catch (const std::exception& e) {
        std::cout << "Caught exception during Form creation: " << e.what() << std::endl;
    }

    std::cout << "\n========== 2. 测试权限不够签署失败 ==========" << std::endl;
    // try-catch在signForm里面
    Bureaucrat intern("Bob the Intern", 140);
    Form highLevelForm("Top Secret Document", 50, 20);

    std::cout << intern << std::endl;
    std::cout << highLevelForm << std::endl;

    // Bob 试图签署门槛为 50 的表单（失败）
    intern.signForm(highLevelForm);
    std::cout << highLevelForm << std::endl; // Signed 依然应当是 No

    std::cout << "\n========== 3. 测试权限足够签署成功 ==========" << std::endl;
    Bureaucrat boss("Alice the Boss", 10);

    std::cout << boss << std::endl;

    // Alice 签署门槛为 50 的表单（成功）
    boss.signForm(highLevelForm);
    std::cout << highLevelForm << std::endl; // Signed 应当变成 Yes

    return 0;
}