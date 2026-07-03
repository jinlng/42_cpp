#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

FileReplacer::FileReplacer(const FileReplacer& src) {
    *this = src;
}

FileReplacer& FileReplacer::operator=(const FileReplacer& rhs) {
    if (this != &rhs) {
        this->_filename = rhs._filename;
        this->_s1 = rhs._s1;
        this->_s2 = rhs._s2;
    }
    return *this;
}

FileReplacer::~FileReplacer(void) {}

bool FileReplacer::execute(void) const {
    // 1. 极端边界条件防御
    if (this->_filename.empty()) {
        std::cerr << "Error: Filename cannot be empty." << std::endl;
        return false;
    }
    if (this->_s1.empty()) {
        std::cerr << "Error: The string to be replaced (s1) cannot be empty." << std::endl;
        return false;
    }

    // 2. 打开输入文件流（C++ 规范，严禁使用 C 的 fopen）
    std::ifstream inFile(this->_filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << this->_filename << std::endl;
        return false;
    }

    // 3. 打开输出文件流 (filename + ".replace")
    std::string outFilename = this->_filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file: " << outFilename << std::endl;
        inFile.close(); // 记得随手关闭已打开的流
        return false;
    }

    // 4. 读取整个文件内容到内存字符串
    std::string line;
    std::string content;
    while (std::getline(inFile, line)) {
        content += line;
        if (!inFile.eof()) {
            content += "\n"; // 补回被 getline 吞掉的换行符
        }
    }
    inFile.close(); // 读完了，安全关闭

    // 5. 核心算法：不产生死循环的精准替换
    std::string result;
    size_t prevPos = 0;
    size_t currentPos = 0;

    // 只要能找到 s1，就持续切片和拼接
    while ((currentPos = content.find(this->_s1, prevPos)) != std::string::npos) {
        // 先把 s1 之前那些安全的文本拷过来
        result.append(content, prevPos, currentPos - prevPos);
        // 拼接上替换后的新内容 s2
        result.append(this->_s2);
        // 关键：把下一次搜索的起点，死死锁定在当前找到的 s1 结束之后！
        prevPos = currentPos + this->_s1.length();
    }
    // 把最后剩下的一截文本（若有）补齐
    result.append(content, prevPos, std::string::npos);

    // 6. 写入目标文件
    outFile << result;
    outFile.close();

    std::cout << "Success: Replaced files saved to " << outFilename << std::endl;
    return true;
}