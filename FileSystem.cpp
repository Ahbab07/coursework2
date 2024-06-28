#include "FileSystem.hpp"

FileSystem::FileSystem() : root("root") {}

void FileSystem::createFile(std::string path, std::string name) {
    Directory* dir = findDirectory(path);
    if (!dir) {
        throw std::runtime_error("Directory does not exist.");
    }
    dir->createFile(name);
}

void FileSystem::deleteFile(std::string path, std::string name) {
    Directory* dir = findDirectory(path);
    if (!dir) {
        throw std::runtime_error("Directory does not exist.");
    }
    dir->deleteFile(name);
}

std::string FileSystem::readFile(std::string path, std::string name) {
    Directory* dir = findDirectory(path);
    if (!dir) {
        throw std::runtime_error("Directory does not exist.");
    }
    return dir->readFile(name);
}

void FileSystem::writeFile(std::string path, std::string name, std::string data) {
    Directory* dir = findDirectory(path);
    if (!dir) {
        throw std::runtime_error("Directory does not exist.");
    }
    dir->writeFile(name, data);
}

void FileSystem::createDirectory(std::string path, std::string name) {
    Directory* dir = findDirectory(path);
    if (!dir) {
        throw std::runtime_error("Directory does not exist.");
    }
    dir->createDirectory(name);
}

void FileSystem::deleteDirectory(std::string path, std::string name) {
    Directory* dir = findDirectory(path);
    if (!dir) {
        throw std::runtime_error("Directory does not exist.");
    }
    dir->deleteDirectory(name);
}

void FileSystem::listDirectoryContents(std::string path) {
    Directory* dir = findDirectory(path);
    if (!dir) {
        throw std::runtime_error("Directory does not exist.");
    }
    dir->listContents();
}

Directory* FileSystem::findDirectory(std::string path) {
    std::stringstream ss(path);
    std::string segment;
    Directory* current = &root;

    while (std::getline(ss, segment, '/')) {
        if (segment.empty()) continue;
        bool found = false;
        for (auto& dir : current->getDirectories()) {
            if (dir.getName() == segment) {
                current = const_cast<Directory*>(&dir); // Cast away constness
                found = true;
                break;
            }
        }
        if (!found) return nullptr;
    }
    return current;
}

