#pragma once
///Это обязательный подзаголовок PE-заголовка. Он хранит в себе базовые характеристики исполняемого файла.

typedef struct MY_IMAGE_FILE_HEADER {
/*    1. IMAGE_FILE_MACHINE_I386 (0x014c) - означает, что программа может выполняться на x32
    2. IMAGE_FILE_MACHINE_IA64 (0x0200) - означает,
    что программа может выполняться на процессорах Intel Itanium (Intel x64).
    3. IMAGE_FILE_MACHINE_AMD64 (0x8664) - означает, что программа может выполняться на процессорах AMD64 (x64).*/
    unsigned short  Machine; // Архитектура процессора
    /*Двухбайтовоеполе NumberOfSections содержит в себе число секций в PE-файле.*/
    unsigned short  NumberOfSections; // Кол-во секций
    unsigned long TimeDateStamp; // Дата и время создания программы
    unsigned long PointerToSymbolTable; // Указатель на таблицу символов
    unsigned long NumberOfSymbols; // Число символов в таблицу
    /*Двухбайтовое поле содержащее размер дополнительного заголовка, который идёт сразу за файловым заголовком.*/
    unsigned short  SizeOfOptionalHeader; // Размер дополнительного заголовка
/*    Даное двухбайтовое поле содержит характеристики PE-файла.
    Например, является ли это exe-файлом, или dll.
    Также, тут описано, является ли данная программа x64-битной или x86-битной.*/
    unsigned short  Characteristics; // Характеристика
} MY_IMAGE_FILE_HEADER, *MY_PIMAGE_FILE_HEADER;

