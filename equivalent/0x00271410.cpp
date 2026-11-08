// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 16/16)
// FUN_00271410 @ 0x00271410
#include "decls/data/engine/unknown.h"
#include "gen/core.h"
#include "compat/ptr.h"

extern "C" char * __cdecl strncpy(char *, const char *, unsigned int);
int __cdecl FUN_00345b90(int);
void __cdecl FUN_0026d850(void *);
void __cdecl FUN_0026d840(void *);
extern "C" int __cdecl FUN_00270c10(const char *);
extern "C" int __cdecl FUN_00270f10(const char *, void *);
extern "C" void * __cdecl FUN_00276680(unsigned int);
struct InstanceDrive_nv_271410 {
    core::InstanceDrive * FUN_00277110(void *, void *);
};
// the drive registry (records.h CoreDriveRegistryEntry): the entry's drive

void __cdecl FUN_00271410(core::InstanceDrive **result, const char *name, void *argument)
{
    char buffer[20];
    strncpy(buffer, name, 16);
    buffer[16] = 0;
    for (char *p = buffer; *p; ++p)
        *p = (char)FUN_00345b90((int)*p);

    FUN_0026d850(((char*)DAT_0052a0f0));
    int index = FUN_00270c10(buffer);
    void **entry = 0;
    if (index != -1 && DAT_00528418[index].drive)
        entry = &DAT_00528418[index].drive;
    if (!entry && (*(char*)&DAT_004cdc04)) {
        FUN_0026d840(((char*)DAT_0052a0f0));
        FUN_00270f10(buffer, (void *)(hulk_uintptr)(int)DAT_0052a120);
        FUN_0026d850(((char*)DAT_0052a0f0));
        index = FUN_00270c10(buffer);
        if (index > -1 && DAT_00528418[index].drive)
            entry = &DAT_00528418[index].drive;
    }
    if (entry) {
        core::InstanceDrive *object = (core::InstanceDrive *)FUN_00276680(0x24);
        if (object)
            object = ((InstanceDrive_nv_271410*)(((core::InstanceDrive*)(object))))->FUN_00277110(*entry, argument);
        *result = object;
    } else {
        *result = 0;
    }
    FUN_0026d840(((char*)DAT_0052a0f0));
}