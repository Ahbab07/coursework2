#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "FileSystem.hpp"

TEST_CASE("File operations", "[FileSystem]") {
    FileSystem fs;
    fs.createFile("/", "test.txt");
    REQUIRE(fs.readFile("/", "test.txt") == "");
    fs.writeFile("/", "test.txt", "Hello, World!");
    REQUIRE(fs.readFile("/", "test.txt") == "Hello, World!");
    fs.deleteFile("/", "test.txt");
    REQUIRE(fs.readFile("/", "test.txt") == "");
}

TEST_CASE("Directory operations", "[FileSystem]") {
    FileSystem fs;
    fs.createDirectory("/", "subdir");
    fs.createFile("/subdir", "test.txt");
    REQUIRE(fs.readFile("/subdir", "test.txt") == "");
    fs.writeFile("/subdir", "test.txt", "Hello, Subdir!");
    REQUIRE(fs.readFile("/subdir", "test.txt") == "Hello, Subdir!");
    fs.deleteFile("/subdir", "test.txt");
    REQUIRE(fs.readFile("/subdir", "test.txt") == "");
    fs.deleteDirectory("/", "subdir");
}

TEST_CASE("Error handling", "[FileSystem]") {
    FileSystem fs;

    SECTION("Reading from non-existent file should return empty string") {
        REQUIRE(fs.readFile("/", "non_existent.txt") == "");
    }

    SECTION("Writing to non-existent file should create the file") {
        fs.writeFile("/", "new_file.txt", "New file content");
        REQUIRE(fs.readFile("/", "new_file.txt") == "New file content");
    }

    SECTION("Deleting non-existent file should not throw an error") {
        fs.deleteFile("/", "non_existent.txt");
        // No assertion needed, just ensure no exception is thrown
    }

    SECTION("Deleting non-empty directory should delete all files inside") {
        fs.createDirectory("/", "non_empty_dir");
        fs.writeFile("/non_empty_dir", "file1.txt", "File 1 content");
        fs.writeFile("/non_empty_dir", "file2.txt", "File 2 content");
        fs.deleteDirectory("/", "non_empty_dir");
        REQUIRE(fs.readFile("/non_empty_dir", "file1.txt") == "");
        REQUIRE(fs.readFile("/non_empty_dir", "file2.txt") == "");
    }

    SECTION("Creating file in non-existent directory should throw an error") {
        REQUIRE_THROWS_AS(fs.createFile("/non_existent_dir", "new_file.txt"), std::runtime_error);
    }

    SECTION("Deleting non-existent directory should throw an error") {
        REQUIRE_THROWS_AS(fs.deleteDirectory("/", "non_existent_dir"), std::runtime_error);
    }
}
