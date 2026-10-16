#include "gen/core.h"

extern "C" int strcmp(const char*, const char*);
class Entry_268a10 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* Name();
};

void* core::ControllerXBox::vfunc_10(void* __p0) { const char * s = (const char *)__p0;

    unsigned int i;
    for (i = 0; i < this->f_14; i++) {
        Entry_268a10* e = (Entry_268a10*)((char*)this + 0x18 + i * 0x34);
        if (strcmp(s, e->Name()) == 0)
            return (void*)((Entry_268a10*)((char*)this + 0x18 + i * 0x34));
    }
    return (void*)(0);
}
