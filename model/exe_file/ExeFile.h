#ifndef PORTABLEEXECUTABLEUTILITY_EXEFILE_H
#define PORTABLEEXECUTABLEUTILITY_EXEFILE_H
#include "../headers/PE_Header.h"
#include "../headers/DosHeader.h"
#include "../headers/OptionalHeader.h"
#include "../headers/DataDirectoryHeader.h"
#include "../headers/NumberOfSectionsHeader.h"

class ExeFile {
private:
    MY_IMAGE_DOS_HEADER dosHeader;
    MY_IMAGE_NT_HEADERS32 peHeader;
    MY_IMAGE_OPTIONAL_HEADER32 optionalHeader;
    MY_IMAGE_DATA_DIRECTORY dataDirectory;
    MY_IMAGE_SECTION_HEADER sectionHeader;
public:
    [[nodiscard]] const MY_IMAGE_DOS_HEADER &getDosHeader() const {
        return dosHeader;
    }

    [[nodiscard]] const MY_IMAGE_NT_HEADERS32 &getPeHeader() const {
        return peHeader;
    }

    [[nodiscard]] const MY_IMAGE_OPTIONAL_HEADER32 &getOptionalHeader() const {
        return optionalHeader;
    }

    [[nodiscard]] const MY_IMAGE_DATA_DIRECTORY &getDataDirectory() const {
        return dataDirectory;
    }

    [[nodiscard]] const MY_IMAGE_SECTION_HEADER &getSectionHeader() const {
        return sectionHeader;
    }
};


#endif //PORTABLEEXECUTABLEUTILITY_EXEFILE_H
