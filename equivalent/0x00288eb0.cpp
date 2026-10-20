// STATUS: equivalent (tools/equiv.py level 3: 45 inputs, branch coverage 17/18, incomplete)
// FUN_00288eb0 @ 0x00288eb0
#include "compat/ptr.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" void *__cdecl memset(void *, int, unsigned int);
void *FUN_0008d690(hulk_uintptr size);
void *FUN_0008d6d0(hulk_uintptr size);

struct StrField_288eb0 {
    int a, b;
    void FUN_0027af00();
    void FUN_0027b040(const char *s);
    StrField_288eb0() { FUN_0027af00(); }
};

struct Alloc_288eb0 {
    virtual void v0();
    char pad4[0xc];
    unsigned int cur10;
    unsigned int cur14;
    char *base18;
    char *base1c;
};

namespace pure3d {
class AnimationGroup {
public:
    virtual void v0();
    char pad4[4];
    StrField_288eb0 name;
    int f10;
    unsigned int f14;
    int *f18;
    Alloc_288eb0 *f1c;
    AnimationGroup() {
        f10 = 0;
        f14 = 0;
        f18 = 0;
        f1c = 0;
    }
};
}

struct Stream {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};

struct Reader {
    char pad0[0x280];
    int depth;
    Stream *stream;
    bool FUN_002669f0();
    void FUN_00266a30();
    void FUN_00266be0();
};

struct Child_288eb0 {
    void *FUN_0028b0b0(Reader *r, int ctx, Alloc_288eb0 *a);
};

class Loader_288eb0 {
public:
    char pad0[0x14];
    Child_288eb0 *child;
    pure3d::AnimationGroup *FUN_00288eb0(Reader *r, int ctx, Alloc_288eb0 *alloc);
};

pure3d::AnimationGroup *Loader_288eb0::FUN_00288eb0(Reader *r, int ctx, Alloc_288eb0 *alloc)
{
    struct Frame {
        char pad[3];
        unsigned char len;
        int v;
        int spare;
        char name[0x100];
    } fr;

    r->stream->FUN_002647e0(&fr.v, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n = fr.len;
    r->stream->FUN_002647e0(fr.name, n, 1, 1);
    fr.name[n] = 0;

    void *mem;
    if (alloc == 0) {
        mem = FUN_0008d690(0x20);
    } else {
        unsigned int off = (alloc->cur10 + 7) & 0xfffffff8;
        mem = alloc->base18 + off;
        alloc->cur10 = off + 0x20;
    }
    pure3d::AnimationGroup *obj = 0;
    if (mem)
        obj = new (mem) pure3d::AnimationGroup();
    obj->name.FUN_0027b040(fr.name);
    r->stream->FUN_002647e0(&fr.v, 1, 4, 1);
    obj->f10 = fr.v;
    r->stream->FUN_002647e0(&fr.v, 1, 4, 1);
    obj->f14 = fr.v;
    obj->f1c = alloc;
    if (alloc != 0)
        alloc->v0();
    if (obj->f14 != 0) {
        if (alloc == 0) {
            obj->f18 = (int *)FUN_0008d6d0(obj->f14 * 4);
        } else {
            unsigned int bytes = obj->f14 * 4;
            char *p = 0;
            if (bytes > 0) {
                unsigned int off = (alloc->cur14 + 3) & 0xfffffffc;
                p = alloc->base1c + off;
                alloc->cur14 = off + bytes;
            }
            obj->f18 = (int *)p;
        }
        memset(obj->f18, 0, obj->f14 * 4);
        unsigned int i = 0;
        if (r->FUN_002669f0()) {
            while (i < obj->f14) {
                r->FUN_00266a30();
                obj->f18[i] = (hulk_intptr)child->FUN_0028b0b0(r, ctx, obj->f1c);
                r->FUN_00266be0();
                i++;
                if (!r->FUN_002669f0())
                    break;
            }
        }
    }
    return obj;
}
