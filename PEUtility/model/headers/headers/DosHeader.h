#pragma once

typedef struct MY_IMAGE_DOS_HEADER {
/*    Двухбайтовое поле e_magic хранит в себе специальную сигнатуру.
    Эта сигнатура нужна, чтобы указать что это действительно исполняемый файл.
    Вот она - "MZ". Каждый PE-файл обязан начинаться с неё. Если это не так, файл просто не запустится.*/
    unsigned short e_magic;
    unsigned short e_cblp;
    unsigned short e_cp;
    unsigned short e_crlc;
    unsigned short e_cparhdr;
    unsigned short e_minalloc;
    unsigned short e_maxalloc;
    unsigned short e_ss;
    unsigned short e_sp;
    unsigned short e_csum;
    unsigned short e_ip;
    unsigned short e_cs;
    unsigned short e_lfarlc;
    unsigned short e_ovno;
    unsigned short e_res[4];
    unsigned short e_oemid;
    unsigned short e_oeminfo;
    unsigned short e_res2[10];
/*    Четырёхбайтовое поле e_magic хранит в себе смещение до заголовка PE.
    То есть хранит, количество байтов, которое нужно отсчитать с начала файла,
    для того, чтобы попасть прямо к PE-заголовку, т.е. проще говоря, адрес
    PE-заголовка относительно начала файла. Только этот адрес хранится в обратном порядке.*/
    long   e_lfanew;
} MY_IMAGE_DOS_HEADER, *MY_PIMAGE_DOS_HEADER;

