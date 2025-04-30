#include "FileHandler.h"
#include <cstdio>

int main() {
    FileHandler file("data.txt", "a+");
    file.write("Hi. I am Damin");

    FileHandler file2 = std::move(file);
    file2.write(" Risho\n");

    file2.rewind();
    printf("%s\n", file2.readline().c_str());

    return 0;
}
