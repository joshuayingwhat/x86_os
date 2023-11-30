#ifndef ELF_H
#define ELF_H

#define EI_MIDENT 16
typedef struct
{
    /* data */
    char e_ident[EI_MIDENT];
    Elf32_Half e_type;
    Elf32_Half e_mach
};

#endif