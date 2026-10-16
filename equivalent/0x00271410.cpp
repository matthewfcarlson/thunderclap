// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 16/16)
// FUN_00271410 @ 0x00271410
#include "decls/data/engine/unknown.h"

extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
int __cdecl FUN_00345b90(int);
void __cdecl FUN_0026d850(void *);
void __cdecl FUN_0026d840(void *);
int __cdecl FUN_00270c10(const char *);
void __cdecl FUN_00270f10(char *, int);
void * __cdecl FUN_00276680(unsigned int);
struct Created_271410 { Created_271410 * FUN_00277110(void *, void *); };
struct Entry_271410 { void *object; char padding[0x118]; };

void __cdecl FUN_00271410(Created_271410 **result, const char *name, void *argument)
{
    char buffer[20];
    strncpy(buffer, name, 16);
    buffer[16] = 0;
    for (char *p = buffer; *p; ++p)
        *p = (char)FUN_00345b90((int)*p);

    FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
    int index = FUN_00270c10(buffer);
    Entry_271410 *entry = 0;
    if (index != -1 && ((Entry_271410*)&DAT_0052842c)[index].object)
        entry = &((Entry_271410*)&DAT_0052842c)[index];
    if (!entry && (*(char*)&DAT_004cdc04)) {
        FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
        FUN_00270f10(buffer, DAT_0052a120);
        FUN_0026d850(((char*)((char*)&DAT_0052842c + 7364)));
        index = FUN_00270c10(buffer);
        if (index > -1 && ((Entry_271410*)&DAT_0052842c)[index].object)
            entry = &((Entry_271410*)&DAT_0052842c)[index];
    }
    if (entry) {
        Created_271410 *object = (Created_271410 *)FUN_00276680(0x24);
        if (object)
            object = object->FUN_00277110(entry->object, argument);
        *result = object;
    } else {
        *result = 0;
    }
    FUN_0026d840(((char*)((char*)&DAT_0052842c + 7364)));
}