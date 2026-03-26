#include "single_line_file.h"
#include <iostream>

SingleLineFile::SingleLineFile(const std::string& name)
    : Entry(name) {}

void SingleLineFile::show() const {
    std::cout << content_ << std::endl;
}

void SingleLineFile::edit() {
    std::cout << "Enter one line:\n";
    std::getline(std::cin, content_);
}