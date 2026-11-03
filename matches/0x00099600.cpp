#include "gen/owners.h"
struct Sub {
};
struct Obj {
    char pad[0xc4];
    Sub* p;
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    Sub* q = (Sub*)((char*)p + 0x170);
    ((owners::Target_ac780 *)q)->FUN_000ac780(a);
    q = (Sub*)((char*)p + 0x170);
    ((owners::Target_ac790 *)q)->FUN_000ac790(b);
}