#include "gen/owners.h"
struct Item_27f410 {
    int key;
    char pad[0x44];
    int flag;
    char tail[0x14];
};
struct Caller_27f410 {
    char pad[0x20];
};
struct Obj_27f410 {
    char pad[0x18];
    Item_27f410 items[100];
    int run(int key, int arg);
};
int Obj_27f410::run(int key, int arg) {
    int i = 0;
    while (items[i].flag == 0 || items[i].key != key) {
        ++i;
        if (i >= 100)
            return 0;
    }
    ((owners::Target_22be40 *)(((Caller_27f410*)((char*)this + 0x20 + i * 0x60))))->FUN_0022be40((const int *)(hulk_uintptr)(int)arg);
    return key;
}
