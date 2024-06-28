#include "Directory.hpp"
#include <stdexcept> // For std::runtime_error
#include <algorithm> // For std::find_if
#include <iostream>  // For std::cout and std::endl

Directory::Directory(std::string name) : name(name) {}

void Directory::createFile(std::string name) {
    // Check if the file already exists
    auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
        return file.getName() == name;
    });
    if (it != files.end()) {
        throw std::runtime_error("File already exists.");
    }
    
    files.emplace_back(name);
}

void Directory::deleteFile(std::string name) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
        return file.getName() == name;
    });
    if (it == files.end()) {
        throw std::runtime_error("File not found.");
    }

    files.erase(it);
}

std::string Directory::readFile(std::string name) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
        return file.getName() == name;
    });
    if (it == files.end()) {
        throw std::runtime_error("File not found.");
    }

    return it->read();
}

void Directory::writeFile(std::string name, std::string data) {
    auto it = std::find_if(files.begin(), files.end(), [&](const File& file) {
        return file.getName() == name;
    });
    if (it == files.end()) {
        throw std::runtime_error("File not found.");
    }

    it->write(data);
}

void Directory::createDirectory(std::string name) {
    // Check if the directory already exists
    auto it = std::find_if(subdirectories.begin(), subdirectories.end(), [&](const Directory& dir) {
        return dir.getName() == name;
    });
    if (it != subdirectories.end()) {
        throw std::runtime_error("Directory already exists.");
    }

    subdirectories.emplace_back(name);
}

void Directory::deleteDirectory(std::string name) {
    auto it = std::find_if(subdirectories.begin(), subdirectories.end(), [&](const Directory& dir) {
        return dir.getName() == name;
    });
    if (it == subdirectories.end()) {
        throw std::runtime_error("Directory not found.");
    }

    subdirectories.erase(it);
}

std::string Directory::getName() const {
    return name;
}

const std::vector<File>& Directory::getFiles() const {
    return files;
}

const std::vector<Directory>& Directory::getDirectories() const {
    return subdirectories;
}

void Directory::listContents() const {
    std::cout << "Contents of directory '" << name << "':" << std::endl;
    std::cout << "Files:" << std::endl;
    for (const auto& file : files) {
        std::cout << "- " << file.getName() << std::endl;
    }
    std::cout << "Subdirectories:" << std::endl;
    for (const auto& subdir : subdirectories) {
        std::cout << "- " << subdir.getName() << std::endl;
    }
}
