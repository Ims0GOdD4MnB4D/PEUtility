#include "CustomObjdump.h"

void CustomObjdump::fileReader(std::string file) {
    std::ifstream input;
    input.open(file, std::ios_base::binary);
    input.read((char*)&outFile.dosHeader, sizeof(outFile.dosHeader));
    input.seekg(outFile.dosHeader.e_lfanew, std::ios_base::beg);
    input.read((char*)&outFile.peHeader, sizeof(outFile.peHeader));
    input.seekg(outFile.peHeader.OptionalHeader
        .DataDirectory[MY_IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 1].Size
        , std::ios_base::cur);
    input.read((char*)&outFile.optionalHeader, sizeof(outFile.optionalHeader));
    input.seekg(outFile.optionalHeader
        .DataDirectory[MY_IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 1].Size
        , std::ios_base::cur);
    input.read((char*)&outFile.dataDirectory, sizeof(outFile.dataDirectory));
    input.seekg(outFile.dataDirectory.Size, std::ios_base::cur);
    input.read((char*)&outFile.sectionHeader, sizeof(outFile.sectionHeader));
    input.seekg(outFile.sectionHeader.Characteristics, std::ios_base::cur);
}

void CustomObjdump::getFileHeader() {

}

void CustomObjdump::getSectionInfo() {

}

void CustomObjdump::getRelocateEntries() {

}

void CustomObjdump::getPrivateHeader() {

}

void CustomObjdump::getSymbolTable() {

}