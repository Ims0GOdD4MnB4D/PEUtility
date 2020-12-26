#pragma once
#include <iostream>
#include "../headers/headers/PE_Header.h"
#include "../headers/headers/DosHeader.h"
#include "../headers/headers/SectionsHeader.h"
#include "../headers/tables/BaseRelocation.h"
#include <ctime>

class ExePropertiesPrinter {
public:
    static void printDosHeader(MY_IMAGE_DOS_HEADER dosHeader) {
        std::cout << "-- MY_IMAGE_DOS_HEADER --\n";
        //TODO: print string (MZ)
        std::cout << "Magic number " << std::hex << dosHeader.e_magic << '\n';
        std::cout << "Bytes on last page of file " << std::hex << dosHeader.e_cblp << '\n';
        std::cout << "Pages in file " << std::hex << dosHeader.e_cp << '\n';
        std::cout << "Relocations " << std::hex << dosHeader.e_crlc << '\n';
        std::cout << "Size of header in paragraph " << std::hex << dosHeader.e_cparhdr << '\n';
        std::cout << "Minimum extra paragraph " << std::hex << dosHeader.e_minalloc << '\n';
        std::cout << "Maximum extra paragraph " << std::hex << dosHeader.e_maxalloc << '\n';
        std::cout << "Initial SS value " << std::hex << dosHeader.e_ss << '\n';
        std::cout << "Initial SP value " << std::hex << dosHeader.e_sp << '\n';
        std::cout << "Checksum " << std::hex << dosHeader.e_csum << '\n';
        std::cout << "Initial IP value " << std::hex << dosHeader.e_ip << '\n';
        std::cout << "Initial CS value " << std::hex << dosHeader.e_cs << '\n';
        std::cout << "File address of relocations " << std::hex << dosHeader.e_lfarlc << '\n';
        std::cout << "Overlay number " << std::hex << dosHeader.e_ovno << '\n';
        std::cout << "Res " << std::hex << dosHeader.e_res << '\n';
        std::cout << "OEM id " << std::hex << dosHeader.e_oemid << '\n';;
        std::cout << "OEM information " << std::hex << dosHeader.e_oeminfo << '\n';
        std::cout << "Res2 " << std::hex << dosHeader.e_res2 << '\n';
        std::cout << "File address of new extra ... " << std::hex << dosHeader.e_lfanew << '\n';
    }
    static void printOptionalHeader(MY_IMAGE_OPTIONAL_HEADER32 optionalHeader) {
        std::cout << "-- MY_IMAGE_OPTIONAL_HEADER32 --\n";
        std::cout << "Magic " << std::hex << optionalHeader.Magic << '\n';
        std::cout << "Major linker version " << std::hex << optionalHeader.MajorLinkerVersion << '\n';
        std::cout << "Minor linker version " << std::hex << optionalHeader.MinorLinkerVersion << '\n';
        std::cout << "Size of Code " << std::hex << optionalHeader.SizeOfCode << '\n';
        std::cout << "Size of initialized data " << std::hex << optionalHeader.SizeOfInitializedData << '\n';
        std::cout << "Size of uninitialized data " << std::hex << optionalHeader.SizeOfUninitializedData << '\n';
        std::cout << "Address of entry point " << std::hex << optionalHeader.AddressOfEntryPoint << '\n';
        std::cout << "Base of code " << std::hex << optionalHeader.BaseOfCode << '\n';
        std::cout << "Base of data " << std::hex << optionalHeader.BaseOfData << '\n';
        std::cout << "Image Base " << std::hex << optionalHeader.ImageBase << '\n';
        std::cout << "Section alignment " << std::hex << optionalHeader.SectionAlignment << '\n';
        std::cout << "File alignment " << std::hex << optionalHeader.FileAlignment << '\n';
        std::cout << "Major operating system version " << std::hex << optionalHeader.MajorOperatingSystemVersion << '\n';
        std::cout << "Minor operating system version " << std::hex << optionalHeader.MinorOperatingSystemVersion << '\n';
        std::cout << "Major image version " << std::hex << optionalHeader.MajorImageVersion<< '\n';
        std::cout << "Minor image version " << std::hex << optionalHeader.MinorImageVersion << '\n';
        std::cout << "Major subsystem version " << std::hex << optionalHeader.MajorSubsystemVersion << '\n';
        std::cout << "Minor subsystem version " << std::hex << optionalHeader.MinorSubsystemVersion << '\n';
        std::cout << "Win32 version value " << std::hex << optionalHeader.Win32VersionValue << '\n';
        std::cout << "Size of image " << std::hex << optionalHeader.SizeOfImage << '\n';
        std::cout << "Size of headers " << std::hex << optionalHeader.SizeOfHeaders << '\n';
        std::cout << "Checksum " << std::hex << optionalHeader.CheckSum << '\n';
        std::cout << "Subsystem " << std::hex << optionalHeader.Subsystem << '\n';
        std::cout << "DLL characteristics " << std::hex << optionalHeader.DllCharacteristics << '\n';
        std::cout << "Size of stack reserve " << std::hex << optionalHeader.SizeOfStackReserve << '\n';
        std::cout << "Size of stack commit " << std::hex << optionalHeader.SizeOfStackCommit << '\n';
        std::cout << "Size of heap reserve " << std::hex << optionalHeader.SizeOfHeapReserve << '\n';
        std::cout << "Size of heap commit " << std::hex << optionalHeader.SizeOfHeapCommit << '\n';
        std::cout << "Loader flags " << std::hex << optionalHeader.LoaderFlags << '\n';
        std::cout << "Number of rva and sizes " << std::hex << optionalHeader.NumberOfRvaAndSizes << '\n';
        for(auto & i : optionalHeader.DataDirectory)
            printDataDirectory(i);
    }
    static void printFileHeader(MY_IMAGE_FILE_HEADER fileHeader) {
        std::cout << "-- MY_IMAGE_FILE_HEADER --\n";
        //TODO: time date parse
        std::cout << "Machine " << std::hex << fileHeader.Machine << '\n';
        std::cout << "Number of Sections " << std::hex << fileHeader.NumberOfSections << '\n';
        std::cout << "Time date stamp " << fileHeader.TimeDateStamp << '\n';
        std::cout << "Pointer to symbol table " << std::hex << fileHeader.PointerToSymbolTable << '\n';
        std::cout << "Number of symbols " << std::hex << fileHeader.NumberOfSymbols << '\n';
        std::cout << "Size of optional header " << std::hex << fileHeader.SizeOfOptionalHeader << '\n';
        std::cout << "Characteristics " << fileHeader.Characteristics << '\n';
    }
    static void printPEHeader(MY_IMAGE_NT_HEADERS32 peHeader) {
        std::cout << "-- MY_IMAGE_NT_HEADERS32 --\n";
        std::cout << "Signature " << peHeader.Signature << '\n';
        printFileHeader(peHeader.FileHeader);
        printOptionalHeader(peHeader.OptionalHeader);
    }
    static void printDataDirectory(MY_IMAGE_DATA_DIRECTORY dirData) {
        std::cout << "-- MY_IMAGE_DATA_DIRECTORY --\n";
        std::cout << "Virtual Address " << std::hex << dirData.VirtualAddress << '\n';
        std::cout << "Size " << std::dec << dirData.Size << '\n';
    }
    static void printSectionHeader(MY_IMAGE_SECTION_HEADER sectionHeader) {
        std::cout << "-- MY_IMAGE_SECTION_HEADER --\n";
        std::cout << "Name " << sectionHeader.Name << '\n';
        std::cout << "Physical address " << std::hex << sectionHeader.PhysicalAddress << '\n';
        std::cout << "Virtual address " << std::hex << sectionHeader.VirtualAddress << '\n';
        std::cout << "Size of raw data " << std::hex << sectionHeader.SizeOfRawData << '\n';
        std::cout << "Pointer to raw data " << std::hex << sectionHeader.PointerToRawData << '\n';
        std::cout << "Pointer to relocations " << std::hex << sectionHeader.PointerToRelocations << '\n';
        std::cout << "Pointer to linenumbers " << std::hex << sectionHeader.PointerToLinenumbers << '\n';
        std::cout << "Number of relocations " << std::hex << sectionHeader.NumberOfRelocations << '\n';
        std::cout << "Number of linenumbers " << std::hex << sectionHeader.NumberOfLinenumbers << '\n';
        std::cout << "Characteristic " << std::hex << sectionHeader.Characteristics << '\n';
    }
    static void printRelocationTable(std::vector<IMAGE_BASE_RELOCATION>& relocationTable) {
        for(auto & i : relocationTable) {
            std::cout << "Size of block " << i.SizeOfBlock << '\n';
            std::cout << "Virtual address " << std::hex << i.VirtualAddress << '\n';
            for(TypeOffset item : i.typeOffsets) {
                std::cout << item.Offset << ' ' << item.Type << ' ';
            }
            std::cout << '\n';
        }
    }
};