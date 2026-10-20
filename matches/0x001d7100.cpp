#include "compat/ptr.h"
#include "decls/data/game/global.h"

struct Table_1d7100 {
    char pad[0x1c];
    int* entries;
};
struct Obj_1d7100 {
    char pad0[0x40];
    int index;
    char pad1[0x54];
    Table_1d7100* table;
    int Find(int);
};
int Obj_1d7100::Find(int index) {
    if (index == -1)
        index = this->index;
    int* p = (int*)this->table->entries[index];
    int a = p[2];
    int b = p[3];
    int result = -1;
    for (int i = 0; i < 8; ++i) {
        if (a == ((int*)((hulk_intptr)DAT_004e2560))[i * 2] && b == ((int*)((hulk_intptr)((char*)((char*)&DAT_004e2560 + 4))))[i * 2]) {
            result = i;
            break;
        }
    }
    return result;
}
