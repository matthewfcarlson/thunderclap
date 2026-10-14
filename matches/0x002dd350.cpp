typedef unsigned char u8_2dd350;
struct Obj_2dd350 {
    char pad[4];
    int count;
    char pad2[1];
    u8_2dd350 mode;
};
extern u8_2dd350 table1[256];
extern u8_2dd350 table2[256];
extern u8_2dd350 table4[256];
void FUN_002dd350(Obj_2dd350* obj, u8_2dd350* p) {
    u8_2dd350 mode = obj->mode;
    if (mode < 8) {
        u8_2dd350* end = p + obj->count;
        u8_2dd350* table;
        if (mode == 1)
            table = table1;
        else if (mode == 2)
            table = table2;
        else if (mode == 4)
            table = table4;
        else
            return;
        while (p < end) {
            *p = table[*p];
            ++p;
        }
    }
}