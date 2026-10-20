#include "compat/ptr.h"
extern "C" char DAT_0042bc00[];
extern "C" void InitMore();
extern "C" char* strncpy(char*, const char*, unsigned int);
class DriveFindFirstRequest {
  public:
    virtual void V0();
    void InitBase(void*);
    DriveFindFirstRequest* Init(void* a, char* src, int v);
    char pad0[8];
    char name[0x100];
    char pad[4];
    int value;
};
DriveFindFirstRequest* DriveFindFirstRequest::Init(void* a, char* src, int v) {
    InitBase(a);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042bc00);
    value = v;
    InitMore();
    strncpy(name, src, 0x100);
    name[0x100] = 0;
    return this;
}
