#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

bool fileExists(const std::string& fileName) {
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}

bool directoryExists(const std::string& dirName) {
    struct stat info;
    return (stat(dirName.c_str(), &info) == 0 && (info.st_mode & S_IFDIR));
}

TEST_CASE("File Operations", "[file]") {
    std::string fileName = "testfile.txt";

    SECTION("File creation") {
        std::ofstream outFile(fileName);
        outFile << "This is a test file.";
        outFile.close();
        REQUIRE(fileExists(fileName));
    }

    SECTION("File reading and writing") {
        std::ofstream outFile(fileName, std::ios_base::app);
        outFile << " Additional text.";
        outFile.close();

        std::ifstream inFile(fileName);
        std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();

        REQUIRE(content == "This is a test file. Additional text.");
    }

    SECTION("File deletion") {
        std::remove(fileName.c_str());
        REQUIRE(!fileExists(fileName));
    }
}

TEST_CASE("Directory Operations", "[directory]") {
    std::string dirName = "testdir";

    SECTION("Directory creation") {
        mkdir(dirName.c_str(), 0777);
        REQUIRE(directoryExists(dirName));
    }

    SECTION("File creation in directory") {
        std::string filePath = dirName + "/testfile.txt";
        std::ofstream outFile(filePath);
        outFile << "This is a test file in a directory.";
        outFile.close();
        REQUIRE(fileExists(filePath));
    }

    SECTION("Directory listing and deletion") {
        std::string filePath = dirName + "/testfile.txt";
        std::remove(filePath.c_str());
        REQUIRE(!fileExists(filePath));

        rmdir(dirName.c_str());
        REQUIRE(!directoryExists(dirName));
    }
}