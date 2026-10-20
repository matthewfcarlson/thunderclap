#include "compat/ptr.h"
extern char g_vtbl[];

class Elem_3375f0 {
  public:
    void Init();
};

class Container_3375f0 {
  public:
    int m_vptr;         // 0x00
    int field4;         // 0x04
    char elems[0x5100]; // 0x08 .. 0x5108
    int f5108;          // 0x5108
    int f510c;          // 0x510c

    Container_3375f0* Init();
};

Container_3375f0* Container_3375f0::Init() {
    *(hulk_intptr*)this = (hulk_intptr)g_vtbl;
    char* p = elems;
    for (int i = 0x20; i != 0; --i) {
        ((Elem_3375f0*)p)->Init();
        p += 0x288;
    }
    field4 = 0;
    f5108 = 0;
    f510c = 0;
    return this;
}
