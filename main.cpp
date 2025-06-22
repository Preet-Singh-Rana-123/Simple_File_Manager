#include <iostream>
#include "h_files/FileManager.h"
#include <string>
#include <sstream>

using namespace std;
namespace fs = std::filesystem;

int main()
{

    FileManager f1("/Users/preetrana/Documents/C++ learn/test_folder");

    string input;

    while (true)
    {
        std::cout << f1.getCurrentPath().string() << " > ";
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::string command, arg1, arg2;
        iss >> command >> arg1 >> arg2;

        if (command == "exit")
            break;
        else if (command == "ls")
            f1.listContent();
        else if (command == "cd")
            f1.changeDirectory(arg1);
        else if (command == "up")
            f1.goUpDirectory();
        else if (command == "copy")
            f1.copy(arg1, arg2);
        else if (command == "move")
            f1.move(arg1, arg2);
        else if (command == "delete")
            f1.deleteEntry(arg1);
        else if (command == "rename")
            f1.renameEntry(arg1, arg2);
        else
            std::cout << "Unknown command: " << command << "\n";
    }

    return 0;
}