#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <filesystem>

namespace fs = std::filesystem;

class FileManager
{
private:
    std::filesystem::path currentPath;

public:
    FileManager(const std::string &startPath);
    fs::path getCurrentPath() const;
    void listContent();
    void changeDirectory(const std::string &folder);
    void goUpDirectory();
    void copy(const std::string &src, const std::string &dest);
    void move(const std::string &src, const std::string &dest);
    void deleteEntry(const std::string &name);
    void renameEntry(const std::string &oldName, const std::string &newName);
    void search(const std::string &name);
};

#endif