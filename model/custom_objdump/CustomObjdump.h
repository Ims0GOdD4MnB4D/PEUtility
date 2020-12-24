#pragma once
#include <fstream>
#include "../exe_file/ExeFile.h"

class CustomObjdump {
private:
    ExeFile outFile;
public:
    void fileReader(std::string file);
    MY_IMAGE_NT_HEADERS32 getFileHeader() const; // -f
    void getSectionInfo(); // -h
    void getRelocateEntries(); // -r
    void getPrivateHeader(); // -p
    void getSymbolTable(); // -t
};

