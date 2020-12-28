#pragma once

typedef struct {
    unsigned long *OriginalFirstThunk;
    unsigned long TimeDateStamp;
    unsigned long ForwarderChain;
    unsigned long Name;
    unsigned long *FirstThunk;
} IMAGE_IMPORT_DESCRIPTOR;