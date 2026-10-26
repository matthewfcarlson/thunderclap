#include "decls/data/engine/pure3d.h"

typedef unsigned char u8_2dd350;
struct Obj_2dd350 {
    char pad[4];
    int count;
    char pad2[1];
    u8_2dd350 mode;
};
void FUN_002dd350(Obj_2dd350* obj, u8_2dd350* p) {
    u8_2dd350 mode = obj->mode;
    if (mode < 8) {
        u8_2dd350* end = p + obj->count;
        u8_2dd350* table;
        if (mode == 1)
            table = ((u8_2dd350*)&DAT_004d1188);
        else if (mode == 2)
            table = ((u8_2dd350*)&DAT_004d1288);
        else if (mode == 4)
            table = ((u8_2dd350*)&DAT_004d1388);
        else
            return;
        while (p < end) {
            *p = table[*p];
            ++p;
        }
    }
}