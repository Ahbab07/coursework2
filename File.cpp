#include "File.hpp"

File::File(std::string name) : name(name), content("") {}

std::string File::getName() const {
    return name;
}

std::string File::read() const {
    return content;
}

void File::write(const std::string& data) {
    content = data;
}


