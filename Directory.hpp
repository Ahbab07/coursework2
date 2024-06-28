#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include <string>
#include <vector>
#include "File.hpp" // Assuming you have a File class

class Directory {
public:
    Directory(std::string name);

    void createFile(std::string name);
    void deleteFile(std::string name);
    std::string readFile(std::string name);
    void writeFile(std::string name, std::string data);

    void createDirectory(std::string name);
    void deleteDirectory(std::string name);

    std::string getName() const;
    const std::vector<File>& getFiles() const;
    const std::vector<Directory>& getDirectories() const;

    void listContents() const;

private:
    std::string name;
    std::vector<File> files;
    std::vector<Directory> subdirectories;
};

#endif // DIRECTORY_HPP




