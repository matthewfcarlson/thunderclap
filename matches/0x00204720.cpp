#include "gen/owners.h"
struct Item {
    void Go(void*);
};
class Obj {
    char a[0x44];
    void* m;
    char b[0x570 - 0x48];
    void* slots[2];

  public:
    void Add(void* p);
};
void Obj::Add(void* p) {
    int i = 0;
    void** q = slots;
    do {
        if (!*q) {
            slots[i] = p;
            break;
        }
        ++i;
        ++q;
    } while (i < 2);
    ((Item *)((owners::Obj_203db0 *)this)->FUN_00203db0((hulk_intptr)p))->Go(m);
}