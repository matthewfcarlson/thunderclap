typedef unsigned char u8;
struct Obj { char pad[4]; int count; char pad2[1]; u8 mode; };
extern u8 table1[256];
extern u8 table2[256];
extern u8 table4[256];
void FUN_002dd350(Obj* obj, u8* p) {
    u8 mode = obj->mode;
    if (mode < 8) {
        u8* end = p + obj->count;
        u8* table;
        if (mode == 1) table = table1;
        else if (mode == 2) table = table2;
        else if (mode == 4) table = table4;
        else return;
        while (p < end) {
            *p = table[*p];
            ++p;
        }
    }
}