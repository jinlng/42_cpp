#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <iostream>
#include <fstream>
#include <string>

class FileReplacer {
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;

    FileReplacer(void); // 禁用无参构造，因为没有文件名和字符串就毫无意义

public:
    FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2); // 实用构造
    FileReplacer(const FileReplacer& src);            // OCF 2/4
    FileReplacer& operator=(const FileReplacer& rhs); // OCF 3/4
    ~FileReplacer(void);                              // OCF 4/4

    bool execute(void) const; // 核心执行函数
};

#endif