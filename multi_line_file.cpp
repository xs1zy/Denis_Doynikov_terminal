#include "multi_line_file.h"
#include <iostream>

MultiLineFile::MultiLineFile(const std::string& name)
    : Entry(name) {}

void MultiLineFile::show() const {
    for (const auto& l : lines_) {
        std::cout << l << std::endl;
    }
}

void MultiLineFile::edit() {
    std::cout << "Enter text ('.' to finish):\n";

    lines_.clear();
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line == ".") break;
        lines_.push_back(line);
    }
}