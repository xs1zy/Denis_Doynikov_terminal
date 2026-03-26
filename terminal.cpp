#include "terminal.h"
#include "multi_line_file.h"
#include <iostream>
#include <sstream>

Terminal::Terminal() : running_(true) {
    root_ = std::make_unique<Directory>("/");
    current_ = root_.get();
}

void Terminal::run() {
    std::string input;

    while (running_) {
        std::cout << getPath() << "> ";
        std::getline(std::cin, input);

        execute(input);
    }
}

void Terminal::execute(const std::string& input) {
    std::istringstream iss(input);
    std::string cmd;
    iss >> cmd;

    if (cmd == "help") {
        std::cout << "help, exit, ls, cd, cat, touch, mkdir, rm, restore, mv, edit\n";
    }
    else if (cmd == "exit") {
        running_ = false;
    }
    else if (cmd == "ls") {
        current_->list();
    }
    else if (cmd == "cd") {
        std::string name;
        iss >> name;

        if (name == "..") {
            if (current_->getParent())
                current_ = (Directory*)current_->getParent();
        } else {
            Entry* e = current_->find(name);
            if (e && e->isDirectory())
                current_ = (Directory*)e;
            else
                std::cout << "Not a directory\n";
        }
    }
    else if (cmd == "touch") {
        std::string name;
        iss >> name;

        auto f = std::make_unique<MultiLineFile>(name);
        current_->add(std::move(f));
    }
    else if (cmd == "mkdir") {
        std::string name;
        iss >> name;

        auto d = std::make_unique<Directory>(name);
        current_->add(std::move(d));
    }
    else if (cmd == "cat") {
        std::string name;
        iss >> name;

        Entry* e = current_->find(name);
        if (e) e->show();
    }
    else if (cmd == "edit") {
        std::string name;
        iss >> name;

        Entry* e = current_->find(name);
        if (e) e->edit();
    }
    else if (cmd == "rm") {
        std::string name;
        iss >> name;

        Entry* e = current_->find(name);
        if (e) e->setHidden(true);
    }
    else if (cmd == "restore") {
        std::string name;
        iss >> name;

        Entry* e = current_->find(name, true);
        if (e) e->setHidden(false);
    }
    else if (cmd == "mv") {
        std::string a, b;
        iss >> a >> b;

        current_->rename(a, b);
    }
}

std::string Terminal::getPath() const {
    std::string path;
    Entry* cur = current_;

    while (cur && cur->getParent()) {
        path = "/" + cur->getName() + path;
        cur = cur->getParent();
    }

    return path.empty() ? "/" : path;
}