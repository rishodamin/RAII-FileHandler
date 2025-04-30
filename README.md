# RAII-FileHandler

A modern C++ project demonstrating safe file handling using **RAII** (Resource Acquisition Is Initialization) and **move semantics**. This project ensures files are always closed properly and avoids common pitfalls with manual resource management.

## 🔧 Features

- Safe file opening and closing using RAII  
- Prevents accidental copies with deleted copy constructors  
- Efficient resource transfer with move semantics  
- Custom file reading and writing methods  
- Clean and modular project structure  
- Makefile included for easy compilation  

## 📁 File Structure

```
.
├── FileHandler.cpp     # Implementation of FileHandler class  
├── FileHandler.h       # Header file with class declaration  
├── main.cpp            # Example usage  
├── Makefile            # For building the project  
```

## 🚀 Getting Started

### Prerequisites

- C++17 or above  
- g++ or any modern C++ compiler  
- make  

### Build the project

```bash
make
```

### Run the executable

```bash
./main
```

### Clean the build files

```bash
make clean
```

## 📖 Example

```cpp
FileHandler file("data.txt", "a+");
file.write("Hello, RAII!");
FileHandler file2 = std::move(file);  // Transfer ownership
file2.rewind();
std::cout << file2.readline();
```

## 🧠 Concepts Used

- RAII (Resource Acquisition Is Initialization)  
- Move constructor and move assignment  
- File I/O in C++  
- Exception handling  