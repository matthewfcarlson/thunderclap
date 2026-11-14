// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00295c40..0x002980b0 (kind game, layer engine, confidence high), dominant class pure3d::scenegraph::Scenegraph
#include "tree_prelude.h"
#include "compat/ptr.h"


// 0x00297f20 pure3d::scenegraph::ScenegraphLoader::vfunc_5 (338 B): equivalent/0x00297f20.cpp [isolated: using-directive; on include/gen/ and not mergeable]
// sym: ?vfunc_5@ScenegraphLoader@scenegraph@pure3d@@UAEXPAX00H@Z @8856e92257c8 @w10a13db26f70
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 13/14, incomplete)
// pure3d::scenegraph::ScenegraphLoader::vfunc_5 @ 0x00297f20
#include "gen/pure3d.h"

extern "C" void *__cdecl FUN_00263ea0(unsigned int size);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
inline void *operator new(size_t, void *p) throw() { return p; }

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
    virtual void d0_00038290();
    char pad4[4];
    Name_297f20 name;
    char pad10[0x30];
    void FUN_002a3480();
    DrawableHierarchy_297f20() { FUN_002a3480(); }
};

namespace scenegraph {
class Scenegraph_297f20 : public DrawableHierarchy_297f20 {
public:
    virtual void s1_000382a0();
    virtual void* s2_002970a0(char);
    virtual void s3_00296110();
    virtual void s4_00297130();
    virtual void s5_00296100();
    virtual void s6_00296120(int, int);
    virtual void s7_00296140();
    virtual void s8_00296160(hulk_intptr, int);
    virtual void s9_002961c0();
    virtual void s10_002a34c0(hulk_intptr);
    virtual void s11();
    virtual void Finish_00296cb0();
    RefObject_297f20 *child;
    Scenegraph_297f20() { child = 0; }
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

void pure3d::scenegraph::ScenegraphLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { Scenegraph_297f20 ** outSg = (Scenegraph_297f20 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Stream_297f20 * s = (Stream_297f20 *)__p2; void * ctx = (void *)__p3;

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
    sg->Finish_00296cb0();
    *outSg = sg;
    *outId = FUN_002672f0(f.name, 0);
}

