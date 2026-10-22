// STATUS: equivalent (tools/equiv.py level 3: 19977 inputs, branch coverage 10/10)
// FUN_00029500 @ 0x00029500
#include "decls/address.h"
typedef unsigned __int64 Key_29500;
extern Key_29500 __cdecl FUN_00096d80(const char*);

struct Slot_29500 {
    char pad[0x60];
    int value;
};

struct Item_29500 {
    int FUN_001d72e0();
};

struct Registry_29500 {
    Item_29500* FUN_001dee40(Key_29500 key);
};

struct Core_29500 {
    char pad[0xc];
    Registry_29500* registry;
};

struct Entry_29500 {
    char pad0[0x12c];
    int handle;                     // 0x12c
    char pad130[0x1ca0 - 0x130];
    Slot_29500* slot;                     // 0x1ca0
    void FUN_0003ffa0(int value, bool flag);
};

struct Owner_29500 {
    Core_29500* core;
    char pad04[0x120];
    Entry_29500* current;                 // 0x124
    Entry_29500* FUN_00024280(Key_29500 key);
    void FUN_00029500(const char* name, const char* other);
};

void Owner_29500::FUN_00029500(const char* name, const char* other)
{
    Entry_29500* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (entry) {
        int value = 0;
        Entry_29500* found = FUN_00024280(FUN_002672f0(other, 0, 0));
        if (found) {
            value = found->handle;
        } else {
            Key_29500 tmp1 = FUN_00096d80(other);
            Item_29500* item = core->registry->FUN_001dee40(tmp1);
            if (item) {
                value = item->FUN_001d72e0();
            }
        }
        Slot_29500* slot = entry->slot;
        if (slot) {
            slot->value = value;
            entry->FUN_0003ffa0(value, entry != current);
        }
    }
}
