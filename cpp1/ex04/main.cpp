#include "FileReplacer.hpp"

int main(int argc, char** argv) {
    // 严格检查 42 Subject 要求的三个参数
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }

    // 实例化我们的 OCF 安全替换类
    FileReplacer replacer(argv[1], argv[2], argv[3]);

    // 执行任务
    if (!replacer.execute()) {
        return 1; // 执行失败返回错误码
    }

    return 0; // 满分通关
}