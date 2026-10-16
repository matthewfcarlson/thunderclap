#include "gen/core.h"

extern "C" int strcmp(const char*, const char*);
class Item_268a80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual const char* get();
};

void* core::ControllerXBox::vfunc_15(void* __p0) { const char * s = (const char *)__p0;

    for (unsigned i = 0; i < 2; i++) {
        Item_268a80* p = (Item_268a80*)((char*)this + 0x428 + i * 16);
        if (strcmp(s, p->get()) == 0)
            return (void*)((core::ControllerXBox*)((char*)this + i * 16 + 0x428));
    }
    return (void*)(0);
}
