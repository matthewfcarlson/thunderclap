// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 6/6)
// FUN_00214250 @ 0x00214250
struct EntryList { char pad[12]; unsigned int* entries; };
// equiv-conv: FUN_00214250 eax edx
int FUN_00214250(EntryList* list, int index) {
    unsigned int value = list->entries[index + 1];
    unsigned int type = value & 0x3f;
    if (type >= 0x19 && type <= 0x1b)
        return (value & 0xff8000) == 0;
    return type == 0x21;
}
