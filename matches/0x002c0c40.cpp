#include "compat/ptr.h"
extern "C" char DAT_0042eb0c[];
class Sub_2c0c40 {
  public:
    void* Init();
};
class ImageLoader {
  public:
    void* v;
    int a;
    int b;
    int c;
    int d;
    hulk_intptr e;
    int f;
};
extern "C" void* alloc(hulk_intptr);
void* __fastcall FUN_002c0c40(ImageLoader* p) {
    p->a = 0;
    p->b = 0x19001;
    p->c = 0;
    p->d = 0;
    p->v = (void*)((hulk_intptr)DAT_0042eb0c);
    p->f = 0x20;
    Sub_2c0c40* s = (Sub_2c0c40*)alloc(0xa4);
    hulk_intptr r;
    if (s)
        r = (hulk_intptr)s->Init();
    else
        r = 0;
    p->e = r;
    return p;
}
