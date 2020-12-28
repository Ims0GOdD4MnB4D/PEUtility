#pragma once

typedef struct MY_IMAGE_DATA_DIRECTORY {
    const unsigned long VirtualAddress;
    const unsigned long Size;
} MY_IMAGE_DATA_DIRECTORY, *MY_PIMAGE_DATA_DIRECTORY;

