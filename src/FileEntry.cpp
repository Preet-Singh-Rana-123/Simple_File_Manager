#include "../h_files/FileEntry.h"
#include <iostream>
#include <chrono>
#include <iomanip>

FileEntry::FileEntry(const std::filesystem::directory_entry &entry)
{
    this->path = entry.path().string();
    this->name = entry.path().filename().string();
    this->is_Directory = entry.is_directory();
    this->size = is_Directory ? 0 : entry.file_size();

    auto ftime = entry.last_write_time();
    auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        ftime - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());
    this->lastModified = sctp;
}

void FileEntry::display() const
{
    std::time_t cftime = std::chrono::system_clock::to_time_t(lastModified);

    std::cout << name << " (" << size / 1024 << " KB)" << " - modified: " << std::put_time(std::localtime(&cftime), "%F %T") << std::endl;
}