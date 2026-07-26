#include "ClapTrap.hpp"

int main(void) {
    std::cout << "=== 1. Creating ClapTraps ===" << std::endl;
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    std::cout << "\n=== 2. Basic Actions ===" << std::endl;
    a.attack("Beta");
    b.takeDamage(0);
    b.beRepaired(5);

    std::cout << "\n=== 3. Energy Depletion Test ===" << std::endl;
    // Alpha 还有 9 点能量，循环消耗完它
    for (int i = 0; i < 10; i++) {
        a.attack("Beta");
    }
    a.attack("Beta"); // 试图攻击已经死亡的 Beta（应该被拒绝）
    
    std::cout << "\n=== 4. Death Test ===" << std::endl;
    b.takeDamage(20); // 造成致命伤害
    b.attack("Alpha"); // 试图在死亡后攻击（应该被拒）
    b.beRepaired(10);  // 试图在死亡后修复（应该被拒）

    std::cout << "\n=== 5. Destructors Call ===" << std::endl;

    std::cout << "=== Army Scenario ===" << std::endl;

    std::cout << "=== 1. 单体机甲出场 ===" << std::endl;
    ClapTrap clap("Clappy");
    ClapTrap bandit("Bandit");

    std::cout << "\n=== 2. 批量生成 ClapTrap 军团 ===" << std::endl;
    // 数组开辟空间时无法传参，直接触发 3 次无参默认构造函数
    ClapTrap army[3]; 

    std::cout << "\n=== 3. 军团集体作战 ===" << std::endl;
    for (int i = 0; i < 3; i++) {
        army[i].attack("Dummy");
    }

    std::cout << "\n=== 4. 战斗受损与修复 ===" << std::endl;
    clap.attack("Bandit");
    bandit.takeDamage(5);
    bandit.beRepaired(3);

    std::cout << "\n=== 5. 离场销毁（注意看栈内存的倒序销毁顺序！） ===" << std::endl;
    return 0;
}