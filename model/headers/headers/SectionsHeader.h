#pragma once

typedef struct MY_IMAGE_SECTION_HEADER {
    /*Это поле, размером в 8 байт, содержит имя секции, в ASCII кодировке.*/
    unsigned char Name[8]; // IMAGE_SIZEOF_SHORT_NAME
    unsigned long PhysicalAddress;
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

