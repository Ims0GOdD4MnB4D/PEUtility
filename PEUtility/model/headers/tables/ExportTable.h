#pragma once

typedef struct {
    unsigned long Characteristics;
    unsigned long TimeDateStamp;
    unsigned short MajorVersion;
    unsigned short MinorVersion;
    unsigned long Name;
    unsigned long Base;
    unsigned long NumberOfFunctions;
    unsigned long NumberOfNames;
    unsigned long *AddressOfFunctions;
    unsigned long *AddressOfNames;
    unsigned long *AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY;