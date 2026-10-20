// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 26/26)
// FUN_000f8500 @ 0x000f8500
// cl-flags: /GS
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/unknown.h"
extern "C" unsigned int strlen(const char*);

class Manager_f8500 {
  public:
    int FUN_000f7240(unsigned long long key);
};
class Entry_f8500 {
  public:
    void FUN_000f8500(const char* name, Manager_f8500* manager, char flag);
    char pad_00[0x10];
    short* text;
    int id;
    char pad_18[8];
    int field_20;
};

Manager_f8500* FUN_000fc1b0();
int FUN_000dfcc0(char* dst, int size, const char* fmt, ...);
void* FUN_0008d6d0(unsigned int size);
void FUN_000fb740(short* dst, const char* src, hulk_intptr count);
void FUN_0008d340(void* p);

void Entry_f8500::FUN_000f8500(const char* name, Manager_f8500* manager, char flag) {
    char prefix[0x20];
    char full[0x100];
    if (name == 0) {
        return;
    }
    if (manager == 0) {
        manager = FUN_000fc1b0();
        if (manager == 0) {
            return;
        }
    }
    field_20 = -1;
    int newId = manager->FUN_000f7240(FUN_0027b020(name));
    id = newId;
    if (newId != -1) {
        if (text != 0) {
            FUN_0008d340(text);
            text = 0;
        }
        return;
    }
    if (text != 0) {
        FUN_0008d340(text);
        text = 0;
    }
    FUN_000dfcc0(prefix, 0x20, "[NITB]");
    if (name[0] != 0 && flag != 0 && (*(char*)&DAT_004dd8e8) != 0)
        FUN_000dfcc0(full, 0x100, "%s %s", prefix, name);
    else
        FUN_000dfcc0(full, 0x100, "%s", name);
    hulk_intptr count = strlen(prefix) + strlen(name) + 2;
    text = (short*)FUN_0008d6d0(count * 2);
    if (text != 0) {
        FUN_000fb740(text, full, count);
        id = -1;
    }
}
