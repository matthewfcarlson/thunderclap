#include "compat/ptr.h"
typedef unsigned char bool8_27aac0;
class Obj_27aac0 {
  public:
    char pad[0x10];
    int index;
    bool8_27aac0 Check(int);
    bool8_27aac0 Target(int, int*);
};
bool8_27aac0 Obj_27aac0::Target(int a, int* out) {
    if (Check(a)) {
        *(hulk_intptr*)out = index * 0x60 + (hulk_intptr)this + 0xd38;
        return 1;
    }
    *out = 0;
    return 0;
}