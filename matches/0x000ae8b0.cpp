// FUN_000ae8b0 @ 0x000ae8b0
#include "decls/data/game/global.h"

extern "C" int strcmp(const char*, const char*);

struct Item_ae8b0 {
    char pad0[0x14];
    char name[1];           // 0x14
    void FUN_000b0740(const float* value);
};

struct List_ae8b0 {
    char pad0[0x10];
    int count;              // 0x10
    Item_ae8b0* FUN_000ace20(int index);
};

class Owner_ae8b0 {
public:
    int pad0;
    List_ae8b0* list;             // 0x04
    void FUN_000ae8b0(const char* name);
};

// Finds the list item with the given name and resets it.
void Owner_ae8b0::FUN_000ae8b0(const char* name)
{
    for (int i = 0; i < list->count; i++) {
        Item_ae8b0* item = list->FUN_000ace20(i);
        if (strcmp(item->name, name) == 0) {
            item->FUN_000b0740(((float*)&DAT_003f335c));
            return;
        }
    }
}
