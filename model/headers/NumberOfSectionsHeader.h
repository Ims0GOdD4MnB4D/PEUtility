#pragma once

#include <winnls.h>

typedef struct MY_IMAGE_SECTION_HEADER {
    /*Это поле, размером в 8 байт, содержит имя секции, в ASCII кодировке.*/
    unsigned char Name[IMAGE_SIZEOF_SHORT_NAME];
    union {
        unsigned long PhysicalAddress;
        /*Это четырёхбайтовое поле содержит размер (в байтах) секции (той самой комнаты) в виртуальной памяти.*/
        unsigned long VirtualSize;
    } Misc;
    /*А это четырёхбайтовое поле уже содержит относительный адрес секции в виртуальной памяти.*/
    unsigned long VirtualAddress;
    /*Данное четырёхбайтовое поле содержит размер секции в файле.*/
    unsigned long SizeOfRawData;
    /*А указатель на эти самые данные, содержаться в этом четырёхбайтовом поле.*/
    unsigned long PointerToRawData;
    unsigned long PointerToRelocations;
    unsigned long PointerToLinenumbers;
    unsigned short  NumberOfRelocations;
    unsigned short  NumberOfLinenumbers;
/*    Это четырёхбайтовое поле содержит атрибуты секции.
    Например, права чтения, записи и исполнения (Read Write Execute) (RWE).*/
    unsigned long Characteristics;
} MY_IMAGE_SECTION_HEADER, *MY_PIMAGE_SECTION_HEADER;

