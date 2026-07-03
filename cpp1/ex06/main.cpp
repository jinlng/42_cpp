#include "Harl.hpp"

int main(int argc, char** argv) {
    // 严格检查参数数量
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <LOG_LEVEL>" << std::endl;
        return 1;
    }

    Harl harl;
    
    // 将命令行参数传入过滤器
    harl.complainFilter(argv[1]);

    return 0;
}