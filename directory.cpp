#include "directory.h"
#include <iostream>

Directory::Directory(const std::string& name, Entry* parent)
    : Entry(name, parent) {}

bool Directory::isDirectory() const {
    return true;
}

void Directory::list() const {
    for (const auto& [name, ptr] : children_) {
        if (!ptr->isHidden()) {
            std::cout << (ptr->isDirectory() ? "[DIR] " : "[FILE] ")
                      << name << std::endl;
        }
    }
}

Entry* Directory::find(const std::string& name, bool includeHidden) {
    auto it = children_.find(name);
    if (it == children_.end()) return nullptr;

    if (!includeHidden && it->second->isHidden())
        return nullptr;

    return it->second.get();
}

bool Directory::add(std::unique_ptr<Entry> entry) {
    if (!entry || children_.count(entry->getName()))
        return false;

    entry->setParent(this);
    children_[entry->getName()] = std::move(entry);
    return true;
}

bool Directory::rename(const std::string& oldName, const std::string& newName) {
    if (!children_.count(oldName) || children_.count(newName))
        return false;

    auto node = std::move(children_[oldName]);
    children_.erase(oldName);

    node->setName(newName);
    children_[newName] = std::move(node);
    return true;
}