#include "decls/data/game/global.h"
// data: gFlag_9fa00 = DAT_004e222c
#include "gen/owners.h"

struct St_9fa00 {
    int a;
    char p1[8];
    int b;
    char p2[0x30 - 0x10];
    int c;
    char p3[0x48 - 0x34];
    int d;
    char p4[0xa4 - 0x4c];
};
struct Dev_9fa00 {
};
struct Mgr_9fa00 {
};
struct Root_9fa00 {
    char pad[0x54];
    Mgr_9fa00* mgr;
};
struct Sys_9fa00 {
    Mgr_9fa00* Get();
};
struct Glob_9fa00 {
    char pad[0x54];
    Sys_9fa00* sys;
};
extern Glob_9fa00* gGlob_9fa00;
extern "C" bool FUN_0009fa00() {
    Mgr_9fa00* m = gGlob_9fa00->sys->Get();
    int i = 0;
    do {
        St_9fa00 s;
        Dev_9fa00* d = ((Dev_9fa00 *)((owners::C_af3a0 *)m)->FUN_000af3a0(i));
        ((owners::C_af0f0 *)d)->FUN_000af0f0((St_9fa00 *)(&s));
        if (s.a == 1 || s.c == 1 || s.b == 1 || s.d == 1) {
            DAT_004e222c = 1;
            return true;
        }
        i++;
    } while (i < 1);
    return false;
}
