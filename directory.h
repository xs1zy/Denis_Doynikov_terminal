#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "entry.h"
#include <unordered_map>
#include <memory>

class Directory : public Entry {
private:
    std::unordered_map<std::string, std::unique_ptr<Entry>> children_;

public:
    Directory(const std::string& name, Entry* parent = nullptr);

    bool isDirectory() const override;
    void list() const override;

    Entry* find(const std::string& name, bool includeHidden = false);
    bool add(std::unique_ptr<Entry> entry);
    bool rename(const std::string& oldName, const std::string& newName);
};

#endif