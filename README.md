# 🗂️ C++ Terminal File Manager

A lightweight and interactive terminal-based file manager built with modern C++17. This tool allows users to navigate, inspect, and manipulate directories and files directly from the command line.

## 📁 Features

- Navigate into directories using `cd` and `up`
- List contents of the current directory
- Copy, move, rename, or delete files and folders
- Displays current working directory prompt
- Built using the C++17 `<filesystem>` library

## 📸 Preview

```bash
/Users/yourname/Documents/C++ learn/test_folder > ls
- file1.txt
- subfolder

/Users/yourname/Documents/C++ learn/test_folder > cd subfolder
/Users/yourname/Documents/C++ learn/test_folder/subfolder > copy example.txt ../example_copy.txt
```

## 🛠️ Commands
```
| Command              | Description                            |
| -------------------- | -------------------------------------- |
| `ls`                 | List contents of the current directory |
| `cd <folder>`        | Change into the specified subdirectory |
| `up`                 | Go up one directory level              |
| `copy <src> <dest>`  | Copy file or directory                 |
| `move <src> <dest>`  | Move file or directory                 |
| `delete <name>`      | Delete a file or directory             |
| `rename <old> <new>` | Rename a file or directory             |
| `exit`               | Exit the application                   |
```

## 🧱 Project Structure
```
├── main.cpp
├── h_files/
│   └── FileManager.h
├── src/
│   └── FileManager.cpp
├── README.md
```

## 🚀 Getting Started

### Requirements

* C++17 compatible compiler (e.g. `g++`, `clang++`)
* CMake (optional, for building)

### Compile & Run

```bash
g++ -std=c++17 -o file_manager main.cpp cpp_files/FileManager.cpp
./file_manager
```
