// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001d5730 @ 0x001d5730
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
#include "compat/ptr.h"
void thunk_FUN_00267090(void *p);
void *FUN_0008d6d0(hulk_uintptr size);

class Resource_1d5730 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x1c - 4];
    int *begin;
    int *end;
};

struct Holder_1d5730 {
    char pad[0x90];
    Resource_1d5730 *resource;
    char pad94[0xb8 - 0x94];
    void *buffer;
    void FUN_001d5730(Resource_1d5730 *r);
};

void Holder_1d5730::FUN_001d5730(Resource_1d5730 *r)
{
    if (r != 0)
        r->AddRef();
    if (resource != 0)
        resource->Release();
    resource = r;
    if (buffer != 0) {
        thunk_FUN_00267090(buffer);
        buffer = 0;
    }
    buffer = FUN_0008d6d0((resource->end - resource->begin) * 4);
}
