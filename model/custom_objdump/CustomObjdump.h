#include <fstream>

class CustomObjdump {
    //TODO: make field private
private:
    ExeFile outFile;
public:
    [[nodiscard]] const ExeFile &getOutFile() const;

    void fileReader(const std::string& file);

    // -f Display summary information from the overall header of each of the objfile files.
    [[nodiscard]] MY_IMAGE_NT_HEADERS32 getFileHeader() const;
    // -h section-headers
    [[nodiscard]] MY_IMAGE_SECTION_HEADER getSectionInfo() const;
    // -r print the relocation entries of the file.
    void getRelocateEntries() const;
    // -p private headers Print information that is specific to the object file format
    void getPrivateHeader() const;
    // -t Print the symbol table entries of the file.
    void getSymbolTable() const;
};


void CustomObjdump::fileReader(const std::string& file) {
    std::ifstream input;
    input.open(file, std::ios_base::binary);
    input.read((char*)&outFile.getDosHeader(), sizeof(outFile.getDosHeader()));
    input.seekg(outFile.getDosHeader().e_lfanew, std::ios_base::beg);
    input.read((char*)&outFile.getPeHeader(), sizeof(outFile.getPeHeader()));
    input.seekg(outFile.getPeHeader().OptionalHeader
                        .DataDirectory[MY_IMAGE_NUMBEROF_DIRECTORY_ENTRIES-1].Size
            , std::ios_base::cur);
    input.read((char*)&outFile.getOptionalHeader(), sizeof(outFile.getOptionalHeader()));
    input.seekg(outFile.getOptionalHeader()
                        .DataDirectory[MY_IMAGE_NUMBEROF_DIRECTORY_ENTRIES-1].Size
            , std::ios_base::cur);
    input.read((char*)&outFile.getDataDirectory(), sizeof(outFile.getDataDirectory()));
    input.seekg(outFile.getDataDirectory().Size, std::ios_base::cur);
    input.read((char*)&outFile.getSectionHeader(), sizeof(outFile.getSectionHeader()));
    input.seekg(outFile.getSectionHeader().Characteristics, std::ios_base::cur);
    input.close();
}

MY_IMAGE_NT_HEADERS32 CustomObjdump::getFileHeader() const {
    return outFile.getPeHeader();
}

MY_IMAGE_SECTION_HEADER CustomObjdump::getSectionInfo() const {
    return outFile.getSectionHeader();
}

void CustomObjdump::getRelocateEntries() const {

}

void CustomObjdump::getPrivateHeader() const {

}

void CustomObjdump::getSymbolTable() const {

}

const ExeFile &CustomObjdump::getOutFile() const {
    return outFile;
}