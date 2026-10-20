#include "compat/ptr.h"
extern "C" char DAT_003f423c[];
struct ThisCall_001d0480 {
    void Init(void*, int);
};
extern "C" unsigned char __cdecl Get(void*);
extern char gA_2d960;
extern char gB_2d960;
extern char gC_2d960;
class Method5 {
  public:
    virtual void Dummy();
    char pad4[12];
    unsigned char x10;
    unsigned char x11;
    unsigned char x12;
    unsigned char x13;
    unsigned char x14;
    char pad15[3];
    unsigned char x18;
    char pad19[3];
    int arg;
    Method5* Build(void* p2, int p3);
};
Method5* Method5::Build(void* p2, int p3) {
    ((ThisCall_001d0480*)(this))->Init(p2, 5);
    *(void**)this = (void*)((hulk_intptr)DAT_003f423c);
    arg = p3;
    x18 = Get(&gA_2d960);
    x10 = Get(&gB_2d960);
    x11 = Get(&gB_2d960);
    x12 = Get(&gC_2d960);
    x13 = Get(&gC_2d960);
    x14 = Get(&gC_2d960);
    return this;
}
