#include "model/printer/ExePropertyPrinter.h"
#include "model/exe_file/ExeFile.h"
#include "model/custom_objdump/CustomObjdump.h"

int main() {
    CustomObjdump customObjdump{};
    customObjdump.dontGiveAFuckAboutSingleResponsibility(
            R"(D:\jetbrains\projs\ClionProjects\PEUtility\resources\Sam2GameGui.dll)");
    ExePropertiesPrinter::printDosHeader(customObjdump.getOutFile().getDosHeader());
    ExePropertiesPrinter::printPEHeader(customObjdump.getOutFile().getPeHeader());
    for(int i=0; i<customObjdump.getOutFile().getPeHeader().FileHeader.NumberOfSections; ++i)
        ExePropertiesPrinter::printSectionHeader(customObjdump.getOutFile().getSection(i));
    ExePropertiesPrinter::printRelocationTable(customObjdump.getOutFile().getRelocationTable());
    return 0;
}
