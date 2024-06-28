#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include "Directory.hpp"
#include <stdexcept>
#include <sstream>

class FileSystem {
public:
    FileSystem();

    void createFile(std::string path, std::string name);
    void deleteFile(std::string path, std::string name);
    std::string readFile(std::string path, std::string name);
    void writeFile(std::string path, std::string name, std::string data);
    void createDirectory(std::string path, std::string name);
    void deleteDirectory(std::string path, std::string name);
    void listDirectoryContents(std::string path);

private:
    Directory root;

    Directory* findDirectory(std::string path);
};

#endif // FILESYSTEM_HPP







