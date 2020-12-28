#pragma once
#include "DataDirectoryHeader.h"
#include "../macroses/DataDirectoryMacroses.h"


typedef struct MY_IMAGE_OPTIONAL_HEADER {
/*    Это двухбайтовое поле отвечает за битность программы (x32/x64). Оно может принимать следующие значения:
    1. IMAGE_NT_OPTIONAL_HDR32_MAGIC (0x10b) - означает, что это x32 (x86) исполняемый образ.
    2. IMAGE_NT_OPTIONAL_HDR64_MAGIC (0x20b) - означает, что это x64 исполняемый образ.
    3. IMAGE_ROM_OPTIONAL_HDR_MAGIC (0x107) - означает, что это ROM образ.*/
    unsigned short Magic;
    unsigned char MajorLinkerVersion;
    unsigned char MinorLinkerVersion;
    unsigned long SizeOfCode;
    unsigned long SizeOfInitializedData;
    unsigned long SizeOfUninitializedData;
/*    Четырёхбайтовое поле AddressOfEntryPoint содержит адрес начала кода, т.е. указатель на дверь в команту кода.
    Техника инфекции, которую мы изучим в будующем, основана на изменении этого значения.*/
    unsigned long AddressOfEntryPoint;
    unsigned long BaseOfCode;
    unsigned long BaseOfData;
    /*Это четырёхбайтовое поле содержит предпочтительный адрес загрузки программы в память.*/
    unsigned long ImageBase;
/*    Это четырёхбайтовое поле содержит относительный виртуальный адрес
    (относительно ImageBase, т. е. сколько байтов нужно отсчитать с адреса загрузки программы
     , чтобы попасть к началу секций) начала секций в виртуальной памяти.*/
    unsigned long SectionAlignment;
/*    Это четырёхбайтовое поле содержит смещение относительной файла
    (сколько байтов нужно отсчитать с начала файла) начала секций в исполняемом файле.*/
    unsigned long FileAlignment;
    unsigned short MajorOperatingSystemVersion;
    unsigned short MinorOperatingSystemVersion;
    unsigned short MajorImageVersion;
    unsigned short MinorImageVersion;
    /*В этих двухбайтовых полях содержится необходимая версия Windows.
     * next 2 fields
     * */
    unsigned short MajorSubsystemVersion;
    unsigned short MinorSubsystemVersion;
    unsigned long Win32VersionValue;
    /*Это четырёхбайтовое поле содержит размер (в байтах) загруженного исполняемого файла в памяти.*/
    unsigned long SizeOfImage;
    /*Четырёхбайтовое поле SizeOfHeaders содержит размер (в байтах) заголовков файла в памяти.*/
    unsigned long SizeOfHeaders;
    unsigned long CheckSum;
    /*Двухбайтовое поле содержащее тип подсистемы (GUI, CLI, Driver, ...).*/
    unsigned short Subsystem;
    unsigned short DllCharacteristics;
    unsigned long SizeOfStackReserve;
    unsigned long SizeOfStackCommit;
    unsigned long SizeOfHeapReserve;
    unsigned long SizeOfHeapCommit;
    unsigned long LoaderFlags;
    /*Данное четырёхбайтовое поле содержит число каталогов в массиве каталогов. По умолчанию равна 16.*/
    unsigned long NumberOfRvaAndSizes;
/*    Это поле - на самом деле массив, которая содержит информацию о каталогах.
    Их число определено в поле NumberOfRvaAndSizes (по умолчанию (и почти всегда) 16) дополнительного заголовка.
    Каждый элемент информации о каталоге хранит относительный виртуальный адрес
    (относительно ImageBase, т. е. сколько байтов нужно отсчитать с адреса загрузки программы,
     чтобы попасть к началу секций) и размер какого-либо каталога (которые являются и секциями),
     которая определяется по её позиции в массиве.*/
    MY_IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} MY_IMAGE_OPTIONAL_HEADER32, *MY_PIMAGE_OPTIONAL_HEADER32;


