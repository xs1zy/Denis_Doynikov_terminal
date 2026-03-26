#ifndef TERMINAL_H
#define TERMINAL_H

#include "directory.h"
#include <memory>

class Terminal {
private:
    std::unique_ptr<Directory> root_;
    Directory* current_;
    bool running_;

    void execute(const std::string& input);
    std::string getPath() const;

public:
    Terminal();
    void run();
};

#endif