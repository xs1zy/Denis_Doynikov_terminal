#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry {
protected:
    std::string name_;
    bool hidden_;
    Entry* parent_;

public:
    Entry(const std::string& name, Entry* parent = nullptr);
    virtual ~Entry() = default;

    std::string getName() const;
    void setName(const std::string& name);

    bool isHidden() const;
    void setHidden(bool hidden);

    Entry* getParent() const;
    void setParent(Entry* parent);

    virtual bool isDirectory() const;
    virtual void list() const;
    virtual void show() const;
    virtual void edit();
};

#endif