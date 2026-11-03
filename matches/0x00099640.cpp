#include "gen/owners.h"
struct Part {
};
struct Obj {
    char pad[0xc4];
    struct Holder {
        char pad[0x1a8];
        Part part;
    }* holder;
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    ((owners::Target_ac780 *)&(holder->part))->FUN_000ac780(a);
    ((owners::Target_ac790 *)&(holder->part))->FUN_000ac790(b);
}