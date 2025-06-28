#include "../h_files/FileManager.h"
#include <iostream>

namespace fs = std::filesystem;

FileManager::FileManager(const std::string &startPath)
{
    currentPath = fs::path(startPath);
}

fs::path FileManager::getCurrentPath() const
{
    return currentPath;
}

void FileManager::listContent()
{
    try
    {
        for (const auto &entry : fs::directory_iterator(currentPath))
        {
            auto fname = entry.path().filename();
            auto fpath = entry.path();

            if (fs::is_directory(entry.status()))
            {
                std::cout << "📁 " << fname << std::endl;
            }
            else if (fs::is_regular_file(entry.status()))
            {
                std::cout << "📄 " << fname << " (" << fs::file_size(fpath) / 1024 << " KB)" << std::endl;
            }
            else
            {
                std::cout << "❓ " << fname << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void FileManager::changeDirectory(const std::string &folder)
{
    try
    {
        fs::path folderPath = currentPath / folder;

        if (fs::exists(folderPath) && fs::is_directory(folderPath))
        {
            currentPath = fs::canonical(folderPath);
        }
        else
        {
            std::cerr << "Error: " << folder << " is not valid directory.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void FileManager::goUpDirectory()
{
    try
    {
        fs::path folderPath = currentPath.parent_path();

        if (fs::exists(folderPath) && fs::is_directory(folderPath))
        {
            currentPath = fs::canonical(folderPath);
        }
        else
        {
            std::cerr << "Error: is not valid directory.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void FileManager::copy(const std::string &src, const std::string &dest)
{
    try
    {
        fs::path srcPath = fs::path(src).is_absolute() ? fs::path(src) : currentPath / src;
        fs::path destPath = fs::path(dest).is_absolute() ? fs::path(dest) : currentPath / dest;

        if (!fs::exists(srcPath))
        {
            std::cout << "Error: source path does not exist.\n";
            return;
        }

        if (fs::exists(destPath) && fs::is_directory(destPath))
        {
            destPath /= srcPath.filename();
        }else{
			fs::path destParent = destPath.parent_path();
			if(!destParent.exists() && !destParent.is_directory()){
				std::cout << "Error: Destination parent directory does not exist.\n";
			}
		}

		if (fs::is_directory(srcPath)){
			fs::path canonicalsrc = fs::canonical(srcPath);
			fs::path canonicaldest = fs::weakly_canonical(destPath);

			if(canonicaldest.string().starts_with(canonicalsrc)){
				std::cout<<"Error: Cannot move directory into itself or its subdirectory.\n"<<std::endl;
				return;
			}
		}

        fs::copy(srcPath, destPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        std::cout << "Copied successfully!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void FileManager::move(const std::string &src, const std::string &dest)
{
    try
    {
        fs::path srcPath = fs::path(src).is_absolute() ? fs::path(src) : currentPath / src;
        fs::path destPath = fs::path(dest).is_absolute() ? fs::path(dest) : currentPath / dest;

        if (!fs::exists(srcPath))
        {
            std::cout << "Error: source path does not exist.\n";
            return;
        }

        if (fs::exists(destPath) && fs::is_directory(destPath))
        {
            destPath /= srcPath.filename();
        }else{
			fs::path destParent = destPath.parent_path();
			if(!destParent.exists() && !destParent.is_directory()){
				std::cout << "Error: Destination parent directory does not exist.\n";
			}
		}

		if (fs::is_directory(srcPath)){
			fs::path canonicalsrc = fs::canonical(srcPath);
			fs::path canonicaldest = fs::weakly_canonical(destPath);

			if(canonicaldest.string().starts_with(canonicalsrc)){
				std::cout<<"Error: Cannot move directory into itself or its subdirectory.\n"<<std::endl;
				return;
			}
		}

        fs::rename(srcPath, destPath);
        std::cout << "Moved successfully!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void FileManager::deleteEntry(const std::string &name)
{
    try
    {
        fs::path fPath = fs::path(name).is_absolute() ? fs::path(name) : currentPath / name;

        if (fs::exists(fPath))
        {
            std::cout << "Error: file or directory does not exist.\n";
            return;
        }

        if (fs::is_directory(fPath))
        {
            fs::remove_all(fPath);
        }
        else
        {
            fs::remove(fPath);
        }
        std::cout << "File or diectory has been deleted!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void FileManager::renameEntry(const std::string &oldName, const std::string &newName)
{
    try
    {
        fs::path oldPath = fs::path(oldName).is_absolute() ? fs::path(oldName) : currentPath / oldName;
        if (!fs::exists(oldPath))
        {
            std::cout << "Error source file does not exist.\n";
            return;
        }

        fs::path newPath = oldPath.parent_path() / newName;
        fs::rename(oldPath, newPath);
        std::cout << "Renamed file or directory!\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}