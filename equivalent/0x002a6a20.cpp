// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 22/22)
// FUN_002a6a20 @ 0x002a6a20
#include "compat/ptr.h"
class pure3d_PrimGroup {
public:
    virtual void vfunc_0();
};

class pure3d_PrimGroupSkinnedStreamed : public pure3d_PrimGroup {
public:
    virtual void vfunc_0();
    char pad04[0x58];
    int streamHandle;
};

class pure3d_PrimGroupSkinnedPC : public pure3d_PrimGroup {
public:
    virtual void vfunc_0();
    char pad04[0x64];
    int geometryHandle;
};

struct Entry_2a6a20 {
    pure3d_PrimGroup *group;
    int pad[3];
};

struct Source_2a6a20 {
    char pad0[0x48];
    Entry_2a6a20 *begin;
    Entry_2a6a20 *end;
};

class RefCounted_2a6a20 {
public:
    virtual void AddRef();
    virtual void Release();
};

class VertexList_2a6a20 : public RefCounted_2a6a20 {
public:
    RefCounted_2a6a20 *FUN_002c8730(int handle);
};

void *__cdecl FUN_0008d690(unsigned int size);
void *__cdecl FUN_0008d6d0(unsigned int size);

class ProceduralVertexAnimController_2a6a20 {
public:
    char pad0[0x44];
    Source_2a6a20 *source;
    hulk_uintptr count;
    RefCounted_2a6a20 **items;

    void FUN_002a68b0();
    void FUN_002a6a20(Source_2a6a20 *src);
};

void ProceduralVertexAnimController_2a6a20::FUN_002a6a20(Source_2a6a20 *src)
{
    FUN_002a68b0();
    source = src;
    if (src == 0)
        return;

    count = src->end - src->begin;
    items = (RefCounted_2a6a20 **)FUN_0008d6d0(count * 4);
    for (unsigned int i = 0; i < count; i++) {
        items[i] = 0;
        pure3d_PrimGroupSkinnedPC *pc = dynamic_cast<pure3d_PrimGroupSkinnedPC *>(source->begin[i].group);
        RefCounted_2a6a20 *res;
        RefCounted_2a6a20 **slot;
        if (pc != 0) {
            VertexList_2a6a20 *mem = (VertexList_2a6a20 *)FUN_0008d690(0x5c);
            if (mem != 0)
                res = mem->FUN_002c8730(pc->geometryHandle);
            else
                res = 0;
        } else {
            pure3d_PrimGroupSkinnedStreamed *st = dynamic_cast<pure3d_PrimGroupSkinnedStreamed *>(source->begin[i].group);
            if (st == 0)
                continue;
            VertexList_2a6a20 *mem = (VertexList_2a6a20 *)FUN_0008d690(0x5c);
            if (mem != 0)
                res = mem->FUN_002c8730(st->streamHandle);
            else
                res = 0;
        }
        slot = &items[i];
        if (res != 0)
            res->AddRef();
        if (*slot != 0)
            (*slot)->Release();
        *slot = res;
    }
}
