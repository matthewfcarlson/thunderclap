// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 8/8)
// FUN_002a9ea0 @ 0x002a9ea0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
#include "compat/ptr.h"
void __cdecl thunk_FUN_00267090(void *p);
extern "C" void *__cdecl FUN_0008d6d0(hulk_uintptr size);

class Source_2a9ea0 {
public:
    virtual void AddRef();
    virtual void Release();
    char pad04[0x10];
    int *begin;
    int *end;
};

class Binder_2a9ea0 {
public:
    char pad00[0x40];
    Source_2a9ea0 *source;
    char pad44[4];
    hulk_intptr count;
    int *values;
    void FUN_002a9ea0(Source_2a9ea0 *src);
};

// Switches to a new source and allocates one zeroed value per element it holds.
void Binder_2a9ea0::FUN_002a9ea0(Source_2a9ea0 *src)
{
    count = 0;
    thunk_FUN_00267090(values);
    values = 0;
    if (src)
        src->AddRef();
    if (source)
        source->Release();
    source = src;
    count = src->end - src->begin;
    values = (int *)FUN_0008d6d0(count * 4);
    for (int i = 0; i < count; i++)
        values[i] = 0;
}
