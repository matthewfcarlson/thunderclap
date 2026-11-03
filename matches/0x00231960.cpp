#include "gen/fight.h"
extern void* vtable_231960;
struct Sub_231960 {
    void init();
};
struct Node_231960 {
    void* vt;
    char pad[0x24];
    void target();
};
void Node_231960::target() {
    vt = &vtable_231960;
    ((Sub_231960*)((char*)this + 0x28))->init();
    ((fight::Branch *)this)->FUN_00233970();
}
