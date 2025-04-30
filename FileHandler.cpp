#include "FileHandler.h"

FileHandler::FileHandler(const char* filename, const char* mode)
: file(fopen(filename, mode)) {
if (!file) {
    throw std::runtime_error("Failed to open the file");
}
}

FileHandler::FileHandler(FileHandler&& other) noexcept : file(other.file) {
other.file = nullptr;
}

FileHandler& FileHandler::operator=(FileHandler&& other) noexcept {
if (this != &other) {
    if (file) fclose(file);
    file = other.file;
    other.file = nullptr;
}
return *this;
}

std::string FileHandler::readline() {
char buffer[1000];
if (fgets(buffer, sizeof(buffer), file)) {
    return std::string(buffer);
}
return {};
}

void FileHandler::write(const char* data) {
if (fputs(data, file) == EOF) {
    throw std::runtime_error("Failed to write the data");
}
}

void FileHandler::rewind() {
std::rewind(file); // Moves file pointer to beginning
}

FileHandler::~FileHandler() {
if (file) fclose(file);
}