#include "decls/data/engine/unknown.h"

struct CacheEntry {
    char name[16];
    char terminator;
    char unused[3];
    void* value;
    char details[0x104];
};
int __cdecl FUN_00270c10(const char* name);
unsigned char __cdecl FUN_002771b0(const char* name);
void __cdecl FUN_00277260(void** result, const char* name, unsigned int options, char* details);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
unsigned char __cdecl FUN_00270c80(void** result, const char* name, unsigned int options) {
    int index = FUN_00270c10(name);
    *result = 0;
    CacheEntry* entry;
    if (index != -1) {
        entry = &((CacheEntry*)&DAT_00528418)[index];
        if (entry->value) {
            *result = entry->value;
            return 0;
        }
    } else {
        unsigned int count = (*(unsigned int*)&DAT_0052a128);
        if (count >= 26) {
            *result = 0;
            return 1;
        }
        entry = &((CacheEntry*)&DAT_00528418)[count];
    }
    if (FUN_002771b0(name)) {
        FUN_00277260(result, name, options, entry->details);
        if (*result) {
            if (index == -1) {
                strncpy(entry->name, name, 16);
                entry->terminator = 0;
                (*(unsigned int*)&DAT_0052a128) = (*(unsigned int*)&DAT_0052a128) + 1;
            }
            entry->value = *result;
        }
    }
    return 1;
}