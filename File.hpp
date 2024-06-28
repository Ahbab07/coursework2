#ifndef FILE_HPP
#define FILE_HPP

#include <string>

class File {
private:
    std::string name;
    std::string content;

public:
    File(std::string name);

    std::string getName() const; // Marked as const
    std::string read() const;
    void write(const std::string& data);
};

#endif // FILE_HPP
