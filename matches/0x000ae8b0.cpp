// FUN_000ae8b0 @ 0x000ae8b0
#include "decls/data/game/global.h"
#include "gen/owners.h"

extern "C" int strcmp(const char*, const char*);

struct Item_ae8b0 {
    char pad0[0x14];
    char name[1];           // 0x14
};

struct List_ae8b0 {
    char pad0[0x10];
    int count;              // 0x10
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
        Item_ae8b0* item = ((Item_ae8b0 *)((owners::C_ace20 *)list)->FUN_000ace20(i));
        if (strcmp(item->name, name) == 0) {
            ((owners::Dev_b0740 *)item)->FUN_000b0740((const char *)(((float*)&DAT_003f335c)));
            return;
        }
    }
}
