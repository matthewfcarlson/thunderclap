#include "decls/data/game/global.h"
// data: gFallback_1b5760 = DAT_004e216c
#include "gen/owners.h"

struct Inner_1b5760 {
    char pad[0x18];
};
struct Item_1b5760 {
    char pad[0x44];
    Inner_1b5760* p;
};
void* owners::Table_1b5760::FUN_001b5760(unsigned int key) {
    Item_1b5760* item = (Item_1b5760*)slots[(((int)key >> 16) & 0xffff)];
    if (item) {
        unsigned short lo = (unsigned short)key;
        return (char*)(*(void**)((char*)item->p + 0x18)) + lo * 24;
    }
    return ((char*)((char*)&DAT_004e215c + 16));
}
