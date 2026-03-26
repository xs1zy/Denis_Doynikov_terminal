#include "entry.h"
#include <iostream>

Entry::Entry(const std::string& name, Entry* parent)
    : name_(name), hidden_(false), parent_(parent) {}

std::string Entry::getName() const { return name_; }
void Entry::setName(const std::string& name) { name_ = name; }

bool Entry::isHidden() const { return hidden_; }
void Entry::setHidden(bool hidden) { hidden_ = hidden; }

Entry* Entry::getParent() const { return parent_; }
void Entry::setParent(Entry* parent) { parent_ = parent; }

bool Entry::isDirectory() const { return false; }

void Entry::list() const {
    std::cout << name_ << std::endl;
}

void Entry::show() const {
    std::cout << "Cannot show this entry\n";
}

void Entry::edit() {
    std::cout << "Cannot edit this entry\n";
}