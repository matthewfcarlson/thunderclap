#include "gen/owners.h"
struct Config_2923b0 {
    int a;
    int b;
    int c;
    int d;
    int e;
    char pad[0x10];
    int f;
    int g;
};
Config_2923b0* __fastcall FUN_002923b0(Config_2923b0* p) {
    ((owners::Settings_292330 *)p)->FUN_00292330();
    p->a = 0x280;
    p->b = 0x1e0;
    p->c = 0x20;
    p->d = 2;
    p->e = 3;
    p->f = 0x11;
    p->g = 0;
    return p;
}