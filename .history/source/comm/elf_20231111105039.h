#ifndef ELF_H
#define ELF_H

typedef uint
#define EI_MIDENT 16
typedef struct
{
    /* data */
    char e_ident[EI_MIDENT];
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Half e_version;
    Elf32_Addr e_entry;
    Elf32_Off e_phoff;
    Elf32_Off e_shoff;
    Elf32_Word e_flags;
    Elf32_Half e_ehsize;
    Elf32_Half e_phentsize;
    Elf32_Half e_phnum;
    Elf32_Half e_shentsize;
    Elf32_Half e_shnum;
    Elf32_Half e_shstrndx;
} Elf32_Ehdr;

#endif