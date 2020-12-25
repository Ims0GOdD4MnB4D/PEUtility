#include "model/printer/ExePropertyPrinter.h"
#include "model/exe_file/ExeFile.h"
#include "model/custom_objdump/CustomObjdump.h"

int main() {
    CustomObjdump customObjdump{};
    customObjdump.fileReader(R"(D:\jetbrains\projs\ClionProjects\PEUtility\resources\glew32.dll)");
    ExePropertiesPrinter::printDosHeader(customObjdump.getOutFile().getDosHeader());
    ExePropertiesPrinter::printOptionalHeader(customObjdump.getOutFile().getOptionalHeader());
    ExePropertiesPrinter::printDataDirectory(customObjdump.getOutFile().getDataDirectory());
    ExePropertiesPrinter::printPEHeader(customObjdump.getOutFile().getPeHeader());
    ExePropertiesPrinter::printSectionHeader(customObjdump.getOutFile().getSectionHeader());
    return 0;
}
