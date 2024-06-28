#ifndef FILEDESCRIPTOR_HPP
#define FILEDESCRIPTOR_HPP

#include "File.hpp"

class FileDescriptor {
private:
    File file;
    int position;

public:
    FileDescriptor(File file);
    File getFile();
    int getPosition();
    void setPosition(int pos);
};

#endif // FILEDESCRIPTOR_HPP
