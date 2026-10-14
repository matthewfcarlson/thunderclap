// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 10/10)
// FUN_00029500 @ 0x00029500
typedef unsigned __int64 Key;
extern Key __cdecl FUN_002672f0(const char*, int, int);
extern Key __cdecl FUN_00096d80(const char*);

struct Slot {
    char pad[0x60];
    int value;
};

struct Item {
    int FUN_001d72e0();
};

struct Registry {
    Item* FUN_001dee40(Key key);
};

struct Core {
    char pad[0xc];
    Registry* registry;
};

struct Entry {
    char pad0[0x12c];
    int handle;                     // 0x12c
    char pad130[0x1ca0 - 0x130];
    Slot* slot;                     // 0x1ca0
    void FUN_0003ffa0(int value, bool flag);
};

struct Owner {
    Core* core;
    char pad04[0x120];
    Entry* current;                 // 0x124
    Entry* FUN_00024280(Key key);
    void FUN_00029500(const char* name, const char* other);
};

void Owner::FUN_00029500(const char* name, const char* other)
{
    Entry* entry = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (entry) {
        int value = 0;
        Entry* found = FUN_00024280(FUN_002672f0(other, 0, 0));
        if (found) {
            value = found->handle;
        } else {
            Item* item = core->registry->FUN_001dee40(FUN_00096d80(other));
            if (item) {
                value = item->FUN_001d72e0();
            }
        }
        Slot* slot = entry->slot;
        if (slot) {
            slot->value = value;
            entry->FUN_0003ffa0(value, entry != current);
        }
    }
}
