#pragma once
#include <vector>

typedef struct {
    unsigned short Offset:12;
    unsigned short Type:4;
} TypeOffset;

typedef struct {
    unsigned long VirtualAddress;
    unsigned long SizeOfBlock;
    std::vector <TypeOffset> typeOffsets;
}IMAGE_BASE_RELOCATION ;
