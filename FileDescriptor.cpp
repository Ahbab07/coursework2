#include "FileDescriptor.hpp"

FileDescriptor::FileDescriptor(File file) : file(file), position(0) {}

File FileDescriptor::getFile() {
    return file;
}

int FileDescriptor::getPosition() {
    return position;
}

void FileDescriptor::setPosition(int pos) {
    position = pos;
}
