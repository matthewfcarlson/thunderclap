// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 8/8)
// FUN_00335bd0 @ 0x00335bd0
#include "gen/owners.h"
struct Entry { char pad0[8]; int kind; void* detail; };
struct Table { char pad0[0x44]; int count;  };
int __cdecl FUN_00337f20(int size);
struct Item { int value; };
struct Object {
    char pad0[4];
    Table* table;
    Item** items;
    int FUN_00335bd0(int index, int offset);
};
int Object::FUN_00335bd0(int index, int offset)
{
    if (index < 0 || index >= table->count || ((Entry *)((owners::Thing_337090 *)table)->FUN_00337090(index))->kind != 9)
        return 0;
    Item* item = items[index];
    Entry* entry = ((Entry *)((owners::Thing_337090 *)table)->FUN_00337090(index));
    if (*(int*)entry->detail != 4)
        return 0;
    int stride = FUN_00337f20(4);
    return *(int*)((char*)item + 4 + stride * offset);
}