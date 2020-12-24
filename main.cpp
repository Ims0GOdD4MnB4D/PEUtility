#include "model/headers/PE_Header.h"
#include "model/headers/DosHeader.h"
#include "model/headers/NumberOfSectionsHeader.h"
#include <iostream>
#include <fstream>

class ExePropertiesPrinter {
public:
    static void printDosHeader(MY_IMAGE_DOS_HEADER);
    static void printFileHeader(MY_IMAGE_FILE_HEADER);
    static void printPEHeader(MY_IMAGE_NT_HEADERS32);
    static void printOptionalHeader(MY_IMAGE_OPTIONAL_HEADER32);
    static void printDataDirectory(MY_IMAGE_DATA_DIRECTORY);
    static void printSectionHeader(MY_IMAGE_SECTION_HEADER);
};

class ExeFile {
public:
    MY_IMAGE_DOS_HEADER dosHeader;
    MY_IMAGE_NT_HEADERS32 peHeader;
    MY_IMAGE_OPTIONAL_HEADER32 optionalHeader;
    MY_IMAGE_DATA_DIRECTORY dataDirectory;
    MY_IMAGE_SECTION_HEADER sectionHeader;
};

class CustomObjdump {
    //TODO: make field private
public:
    ExeFile outFile;
    void fileReader(const std::string& file);
    // -f     Display summary information from the overall header of each of the objfile files.
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

int main() {
    CustomObjdump customObjdump{};
    customObjdump.fileReader(R"(D:\jetbrains\projs\ClionProjects\PEUtility\resources\glew32.dll)");
    ExePropertiesPrinter::printDosHeader(customObjdump.outFile.dosHeader);
    ExePropertiesPrinter::printOptionalHeader(customObjdump.outFile.optionalHeader);
    ExePropertiesPrinter::printDataDirectory(customObjdump.outFile.dataDirectory);
    ExePropertiesPrinter::printPEHeader(customObjdump.outFile.peHeader);
    ExePropertiesPrinter::printSectionHeader(customObjdump.outFile.sectionHeader);
    return 0;
}

void CustomObjdump::fileReader(const std::string& file) {
    std::ifstream input;
    input.open(file, std::ios_base::binary);
    input.read((char*)&outFile.dosHeader, sizeof(outFile.dosHeader));
    input.seekg(outFile.dosHeader.e_lfanew, std::ios_base::beg);
    input.read((char*)&outFile.peHeader, sizeof(outFile.peHeader));
    input.seekg(outFile.peHeader.OptionalHeader
                .DataDirectory[MY_IMAGE_NUMBEROF_DIRECTORY_ENTRIES-1].Size
                , std::ios_base::cur);
    input.read((char*)&outFile.optionalHeader, sizeof(outFile.optionalHeader));
    input.seekg(outFile.optionalHeader
                .DataDirectory[MY_IMAGE_NUMBEROF_DIRECTORY_ENTRIES-1].Size
                , std::ios_base::cur);
    input.read((char*)&outFile.dataDirectory, sizeof(outFile.dataDirectory));
    input.seekg(outFile.dataDirectory.Size, std::ios_base::cur);
    input.read((char*)&outFile.sectionHeader, sizeof(outFile.sectionHeader));
    input.seekg(outFile.sectionHeader.Characteristics, std::ios_base::cur);
    input.close();
}

MY_IMAGE_NT_HEADERS32 CustomObjdump::getFileHeader() const {
    return outFile.peHeader;
}

MY_IMAGE_SECTION_HEADER CustomObjdump::getSectionInfo() const {

}

void CustomObjdump::getRelocateEntries() const {

}

void CustomObjdump::getPrivateHeader() const {

}

void CustomObjdump::getSymbolTable() const {

}

void ExePropertiesPrinter::printDosHeader(MY_IMAGE_DOS_HEADER dosHeader) {
    std::cout << "-- MY_IMAGE_DOS_HEADER --\n";
    std::cout << dosHeader.e_magic << '\n';
    std::cout << dosHeader.e_cblp << '\n';
    std::cout << dosHeader.e_cp << '\n';
    std::cout << dosHeader.e_crlc << '\n';
    std::cout << dosHeader.e_cparhdr << '\n';
    std::cout << dosHeader.e_minalloc << '\n';
    std::cout << dosHeader.e_maxalloc << '\n';
    std::cout << dosHeader.e_ss << '\n';
    std::cout << dosHeader.e_sp << '\n';
    std::cout << dosHeader.e_csum << '\n';
    std::cout << dosHeader.e_ip << '\n';
    std::cout << dosHeader.e_cs << '\n';
    std::cout << dosHeader.e_lfanew << '\n';
    std::cout << dosHeader.e_ovno << '\n';
    std::cout << dosHeader.e_res << '\n';
    std::cout << dosHeader.e_oemid << '\n';
    std::cout << dosHeader.e_oemid << '\n';
    std::cout << dosHeader.e_oeminfo << '\n';
    std::cout << dosHeader.e_res2 << '\n';
    std::cout << dosHeader.e_lfanew << '\n';
}

void ExePropertiesPrinter::printOptionalHeader(MY_IMAGE_OPTIONAL_HEADER32 optionalHeader) {
    std::cout << "-- MY_IMAGE_OPTIONAL_HEADER32 --\n";
    std::cout << optionalHeader.Magic << '\n';
    std::cout << optionalHeader.MajorLinkerVersion << '\n';
    std::cout << optionalHeader.MinorLinkerVersion << '\n';
    std::cout << optionalHeader.SizeOfCode << '\n';
    std::cout << optionalHeader.SizeOfInitializedData << '\n';
    std::cout << optionalHeader.SizeOfUninitializedData << '\n';
    std::cout << optionalHeader.AddressOfEntryPoint << '\n';
    std::cout << optionalHeader.BaseOfCode << '\n';
    std::cout << optionalHeader.BaseOfData << '\n';
    std::cout << optionalHeader.ImageBase << '\n';
    std::cout << optionalHeader.SectionAlignment << '\n';
    std::cout << optionalHeader.FileAlignment << '\n';
    std::cout << optionalHeader.MajorOperatingSystemVersion << '\n';
    std::cout << optionalHeader.MinorOperatingSystemVersion << '\n';
    std::cout << optionalHeader.MajorImageVersion<< '\n';
    std::cout << optionalHeader.MinorImageVersion << '\n';
    std::cout << optionalHeader.MajorSubsystemVersion << '\n';
    std::cout << optionalHeader.MinorSubsystemVersion << '\n';
    std::cout << optionalHeader.Win32VersionValue << '\n';
    std::cout << optionalHeader.SizeOfImage << '\n';
    std::cout << optionalHeader.SizeOfHeaders << '\n';
    std::cout << optionalHeader.CheckSum << '\n';
    std::cout << optionalHeader.Subsystem << '\n';
    std::cout << optionalHeader.DllCharacteristics << '\n';
    std::cout << optionalHeader.SizeOfStackReserve << '\n';
    std::cout << optionalHeader.SizeOfStackCommit << '\n';
    std::cout << optionalHeader.SizeOfHeapReserve << '\n';
    std::cout << optionalHeader.SizeOfHeapCommit << '\n';
    std::cout << optionalHeader.LoaderFlags << '\n';
    std::cout << optionalHeader.NumberOfRvaAndSizes << '\n';
    unsigned long NumberOfRvaAndSizes;
    MY_IMAGE_DATA_DIRECTORY DataDirectory[MY_IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
}

void ExePropertiesPrinter::printFileHeader(MY_IMAGE_FILE_HEADER fileHeader) {
    std::cout << "-- MY_IMAGE_FILE_HEADER --\n";
    std::cout << fileHeader.Machine << '\n';
    std::cout << fileHeader.NumberOfSections << '\n';
    //TODO: time date parse
    std::cout << "TIME DATE STAMP " << fileHeader.TimeDateStamp << '\n';
    std::cout << fileHeader.PointerToSymbolTable << '\n';
    std::cout << fileHeader.NumberOfSymbols << '\n';
    std::cout << fileHeader.SizeOfOptionalHeader << '\n';
    std::cout << fileHeader.Characteristics << '\n';
}

void ExePropertiesPrinter::printPEHeader(MY_IMAGE_NT_HEADERS32 peHeader) {
    unsigned long Signature; // Сигнатура
    std::cout << peHeader.Signature << '\n';
    printOptionalHeader(peHeader.OptionalHeader);
    printFileHeader(peHeader.FileHeader);
}

void ExePropertiesPrinter::printDataDirectory(MY_IMAGE_DATA_DIRECTORY dirData) {
    std::cout << "-- MY_IMAGE_DATA_DIRECTORY --\n";
    std::cout << dirData.VirtualAddress << '\n';
    std::cout << dirData.Size << '\n';
    unsigned long VirtualAddress;
    unsigned long Size;
}

void ExePropertiesPrinter::printSectionHeader(MY_IMAGE_SECTION_HEADER sectionHeader) {
    std::cout << "-- MY_IMAGE_SECTION_HEADER --\n";
    std::cout << (char*)sectionHeader.Name << '\n';
    std::cout << sectionHeader.Misc.PhysicalAddress
    << sectionHeader.Misc.VirtualSize << '\n';
    std::cout << sectionHeader.VirtualAddress << '\n';
    std::cout << sectionHeader.SizeOfRawData << '\n';
    std::cout << sectionHeader.PointerToRawData << '\n';
    std::cout << sectionHeader.PointerToRelocations << '\n';
    std::cout << sectionHeader.NumberOfLinenumbers << '\n';
    std::cout << sectionHeader.NumberOfRelocations << '\n';
    std::cout << sectionHeader.NumberOfLinenumbers << '\n';
    std::cout << sectionHeader.Characteristics << '\n';
}