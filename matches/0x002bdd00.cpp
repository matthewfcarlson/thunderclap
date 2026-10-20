#include "compat/ptr.h"
class Thing_2bdd00 {
  public:
    char pad0[0x40];
    int count;
    void* base;
    char pad48[8];
    void* value;
    void set(void* p);
};
void Thing_2bdd00::set(void* p) {
    value = p;
    for (int i = 0; i < count * 4; ++i) {
        hulk_intptr off = i * 0x18;
        *(void**)((char*)off + (hulk_intptr)base + 0xc) = value;
    }
}