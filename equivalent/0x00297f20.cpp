// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 13/14, incomplete)
// pure3d::scenegraph::ScenegraphLoader::vfunc_5 @ 0x00297f20
#include "gen/pure3d.h"

extern "C" void *__cdecl FUN_00263ea0(unsigned int size);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct RefObject_297f20 {
    virtual void AddRef();
    virtual void Release();
};

struct Name_297f20 {
    char data[8];
    void FUN_0027b040(const char *s);
};

namespace pure3d {
class __declspec(novtable) DrawableHierarchy_297f20 {
public:
    virtual void d0();
    char pad4[4];
    Name_297f20 name;
    char pad10[0x30];
    void FUN_002a3480();
    DrawableHierarchy_297f20() throw() { FUN_002a3480(); }
};

namespace scenegraph {
class Scenegraph_297f20 : public DrawableHierarchy_297f20 {
public:
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void Finish();
    RefObject_297f20 *child;
    Scenegraph_297f20() throw() { child = 0; }
};
}
}
using pure3d::scenegraph::Scenegraph_297f20;

struct Reader_297f20 {
    void FUN_002647e0(void *dst, int count, int size, int flag);
};

struct Stream_297f20 {
    char pad0[0x284];
    Reader_297f20 *reader;
    bool FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
};

struct Frame_297f20 {
    char pad[3];
    unsigned char len;
    int version;
    char name[0x100];
};

struct ScenegraphLoader_nv_297f20 {
    RefObject_297f20 *FUN_00297680(Stream_297f20 *s, void *ctx);
    RefObject_297f20 *FUN_00297ba0(Stream_297f20 *s, void *ctx);
};

void pure3d::scenegraph::ScenegraphLoader::vfunc_5(void* __p0, void* __p1, void* __p2, int __p3) { Scenegraph_297f20 ** outSg = (Scenegraph_297f20 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Stream_297f20 * s = (Stream_297f20 *)__p2; void * ctx = (void *)__p3;

    Frame_297f20 f;
    s->reader->FUN_002647e0(&f.len, 1, 1, 1);
    s->reader->FUN_002647e0(f.name, f.len, 1, 1);
    s->reader->FUN_002647e0(&f.version, 1, 4, 1);
    f.name[f.len] = 0;

    void *mem = FUN_00263ea0(0x48);
    Scenegraph_297f20 *sg = 0;
    if (mem)
        sg = new (mem) Scenegraph_297f20();
    sg->name.FUN_0027b040(f.name);

    while (s->FUN_002669f0()) {
        int id = s->FUN_00266a30();
        if (id == 0x120101 || id == 0x12010b) {
            RefObject_297f20 *child;
            if (id == 0x120101) {
                s->FUN_00266a30();
                child = ((ScenegraphLoader_nv_297f20*)this)->FUN_00297ba0(s, ctx);
            } else {
                s->FUN_00266a30();
                child = ((ScenegraphLoader_nv_297f20*)this)->FUN_00297680(s, ctx);
            }
            if (child)
                child->AddRef();
            if (sg->child)
                sg->child->Release();
            sg->child = child;
            s->FUN_00266be0();
        }
        s->FUN_00266be0();
    }
    sg->Finish();
    *outSg = sg;
    *outId = FUN_002672f0(f.name, 0);
}
