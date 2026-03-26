#ifndef SINGLE_LINE_FILE_H
#define SINGLE_LINE_FILE_H

#include "entry.h"
#include <string>

class SingleLineFile : public Entry {
private:
    std::string content_;

public:
    SingleLineFile(const std::string& name);

    void show() const override;
    void edit() override;
};

#endif