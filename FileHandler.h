#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <cstdio>
#include <stdexcept>
#include <string>

class FileHandler {
    private:
        FILE* file;
    
    public:
        FileHandler(const char* filename, const char* mode);
    
        FileHandler(const FileHandler&) = delete;
        FileHandler& operator=(const FileHandler&) = delete;
    
        FileHandler(FileHandler&& other) noexcept;
    
        FileHandler& operator=(FileHandler&& other) noexcept;
    
        std::string readline() ;
    
        void write(const char* data);
    
        void rewind() ;
    
        ~FileHandler() ;
    };

#endif