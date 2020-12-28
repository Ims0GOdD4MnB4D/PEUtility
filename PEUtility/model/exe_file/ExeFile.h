#ifndef PORTABLEEXECUTABLEUTILITY_EXEFILE_H
#define PORTABLEEXECUTABLEUTILITY_EXEFILE_H
#include "../headers/headers/PE_Header.h"
#include "../headers/headers/DosHeader.h"
#include "../headers/headers/OptionalHeader.h"
#include "../headers/headers/DataDirectoryHeader.h"
#include "../headers/headers/SectionsHeader.h"
#include "../headers/tables/BaseRelocation.h"
#include "../headers/tables/ImportTable.h"
#include "../headers/tables/ExportTable.h"
#include <vector>

class ExeFile {
private:
    MY_IMAGE_DOS_HEADER dosHeader{};
    MY_IMAGE_NT_HEADERS32 peHeader{};
    MY_IMAGE_DATA_DIRECTORY dataDirectory{};
    IMAGE_IMPORT_DESCRIPTOR importTable;
    IMAGE_EXPORT_DIRECTORY exportDirectory;
    std::vector <MY_IMAGE_SECTION_HEADER> sections;
    std::vector <IMAGE_BASE_RELOCATION> relocationTable;
public:

    [[nodiscard]] const std::vector<MY_IMAGE_SECTION_HEADER> &getSections() const {
        return sections;
    }

    [[nodiscard]]  std::vector<IMAGE_BASE_RELOCATION> &getRelocationTable() {
        return relocationTable;
    }

    ExeFile() = default;

    void resizeSectionVector(size_t i) {
        sections.resize(i);
    }

    [[nodiscard]] const MY_IMAGE_DOS_HEADER &getDosHeader() const {
        return dosHeader;
    }

    [[nodiscard]] const MY_IMAGE_NT_HEADERS32 &getPeHeader() const {
        return peHeader;
    }

    [[nodiscard]] const MY_IMAGE_OPTIONAL_HEADER32 &getOptionalHeader() const {
        return peHeader.OptionalHeader;
    }

    [[nodiscard]] const MY_IMAGE_DATA_DIRECTORY &getDataDirectory() const {
        return dataDirectory;
    }

    [[nodiscard]] const MY_IMAGE_SECTION_HEADER &getSection(int i) const {
        return sections[i];
    }
};



#endif //PORTABLEEXECUTABLEUTILITY_EXEFILE_H
