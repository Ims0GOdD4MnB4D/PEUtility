#ifndef PORTABLEEXECUTABLEUTILITY_EXEFILE_H
#define PORTABLEEXECUTABLEUTILITY_EXEFILE_H
#include "../headers/PE_Header.h"
#include "../headers/DosHeader.h"
#include "../headers/OptionalHeader.h"
#include "../headers/DataDirectoryHeader.h"
#include "../headers/NumberOfSectionsHeader.h"

class ExeFile {
public:
    MY_IMAGE_DOS_HEADER dosHeader;
    MY_IMAGE_NT_HEADERS32 peHeader;
    MY_IMAGE_OPTIONAL_HEADER32 optionalHeader;
    MY_IMAGE_DATA_DIRECTORY dataDirectory;
    MY_IMAGE_SECTION_HEADER sectionHeader;
};


#endif //PORTABLEEXECUTABLEUTILITY_EXEFILE_H
