#ifndef FILE_ENTRY_H
#define FILE_ENTRY_H

#include <string>
#include <filesystem>
#include <iostream>
#include <chrono>

class FileEntry
{
public:
    std::string name;
    std::string path;
    bool is_Directory;
    uintmax_t size;
    std::chrono::system_clock::time_point lastModified;

    FileEntry(const std::filesystem::directory_entry &entry);
    void display() const;
};

#endif