#include <fstream>
#include "../headers/tables/BaseRelocation.h"

#define ALIGN_DOWN(x, align)  (x & ~(align-1))
#define ALIGN_UP(x, align)    ((x & (align-1))?ALIGN_DOWN(x,align)+align:x)
int sectionAligment;
class CustomObjdump {
    //TODO: make field private
private:
    ExeFile outFile;
public:
    [[nodiscard]] ExeFile getOutFile();

    void dontGiveAFuckAboutSingleResponsibility(const std::string& file);

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
    int defSection(unsigned long rva);
    unsigned long rvaToOff(unsigned long rva);
};

int CustomObjdump::defSection(unsigned long rva)
{
    for (int i = 0; i < outFile.getSections().size(); ++i)
    {
        unsigned long start = outFile.getSection(i).VirtualAddress;
        unsigned long end = start + ALIGN_UP(outFile.getSection(i).PhysicalAddress, sectionAligment);

        if(rva >= start && rva < end)
            return i;
    }
    return -1;
}

unsigned long CustomObjdump::rvaToOff(unsigned long rva) {
    int indexSection = defSection(rva);
    if(indexSection != -1)
        return rva -   outFile.getSection(indexSection).VirtualAddress
                            + outFile.getSection(indexSection).PointerToRawData;
    else
        return 0;
}


void CustomObjdump::dontGiveAFuckAboutSingleResponsibility(const std::string& file) {
    std::ifstream input;
    input.open(file, std::ios_base::binary);
    // dosheader
    input.read((char*)&outFile.getDosHeader(), sizeof(outFile.getDosHeader()));
    if (outFile.getDosHeader().e_magic != 0x5A4D)//  check if not MZ
        throw std::runtime_error("Wrong definition e_magic");
    input.seekg(outFile.getDosHeader().e_lfanew, std::ios_base::beg);
    //peheader
    input.read((char*)&outFile.getPeHeader(), sizeof(outFile.getPeHeader()));
    if(outFile.getPeHeader().Signature != 0x00004550) //IMAGE_NT_SIGNATURE
        throw std::runtime_error("Wrong definition signature");
    outFile.resizeSectionVector(outFile.getPeHeader().FileHeader.NumberOfSections);
    //sections
    for(int i=0; i<outFile.getSections().size(); ++i) {
        input.read((char *) &outFile.getSection(i), sizeof(outFile.getSection(i)));
    }

    // relocations
    sectionAligment = (int)outFile.getPeHeader().OptionalHeader.SectionAlignment;

    input.seekg(rvaToOff(outFile.getOptionalHeader()
                                 .DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC]
                                    .VirtualAddress));

    size_t relocationTableSize = outFile
                                    .getOptionalHeader()
                                        .DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC]
                                            .Size;
    size_t res = 0;
    while(relocationTableSize != res) {
        IMAGE_BASE_RELOCATION baseRelocation;
        input.read((char*) &baseRelocation, sizeof(baseRelocation.SizeOfBlock)
                                + sizeof(baseRelocation.VirtualAddress));
        int block = input.gcount();
        TypeOffset typeOffset;
        while(block < baseRelocation.SizeOfBlock) {
            block += input.read((char*)&typeOffset, sizeof(typeOffset)).gcount();
            baseRelocation.typeOffsets.push_back(typeOffset);
        }
        outFile.getRelocationTable().push_back(baseRelocation);
        res += block;
    }

    input.close();
}

MY_IMAGE_NT_HEADERS32 CustomObjdump::getFileHeader() const {
    return outFile.getPeHeader();
}

void CustomObjdump::getRelocateEntries() const {

}

void CustomObjdump::getPrivateHeader() const {

}

void CustomObjdump::getSymbolTable() const {

}

ExeFile CustomObjdump::getOutFile() {
    return outFile;
}

MY_IMAGE_SECTION_HEADER CustomObjdump::getSectionInfo() const {
    return MY_IMAGE_SECTION_HEADER();
}
