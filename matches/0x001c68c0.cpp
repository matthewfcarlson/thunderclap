#include "gen/owners.h"
typedef unsigned char u8;
struct Caller_1c68c0 {
};
struct Obj_1c68c0 {
    char pad[8];
    u8 enabled;
    char pad9[7];
    int value;
    void target(Caller_1c68c0* arg);
};
void Obj_1c68c0::target(Caller_1c68c0* arg) {
    if (enabled && value)
        ((owners::Target_1c16a0 *)arg)->FUN_001c16a0((void *)(hulk_uintptr)(int)value);
}