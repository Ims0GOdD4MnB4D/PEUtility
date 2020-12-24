#pragma once
#include "FileHeader.h"
#include "OptionalHeader.h"

typedef struct MY_IMAGE_NT_HEADERS {
/*    Это четырёхбайтовое поле содержит сигнатуру, а именно значение 50 45 00 00 (или "PE\x00\x00").
    Эта сигнатура указывает на то, что перед нами действительно PE-файл.*/
    unsigned long Signature; // Сигнатура

//    Это обязательный подзаголовок PE-заголовка.
//    Он хранит в себе базовые характеристики исполняемого файла.
    MY_IMAGE_FILE_HEADER FileHeader; // Файловый заголовка
    MY_IMAGE_OPTIONAL_HEADER32 OptionalHeader; // Дополнительный
} MY_IMAGE_NT_HEADERS32, *MY_PIMAGE_NT_HEADERS32;

