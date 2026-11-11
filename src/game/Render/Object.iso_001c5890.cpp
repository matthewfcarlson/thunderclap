// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c49c0..0x001c5ae0 (kind game, layer game, confidence high), dominant class Render::Object
// (tree_prelude.h: not needed)


// 0x001c5890 FUN_001c5890 (97 B): matches/0x001c5890.cpp [isolated: conflict: Store; on include/gen/ and not mergeable]
// sym: ??1ObjectManager_1c5890@@QAE@XZ
#include "gen/Render.h"
extern void* g_vtMgr[];
extern void* g_vtT[];
extern void* g_vtO[];
class Ref_1c5890 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Store {
    void* vptr;
    char pad[4];
    unsigned m8;
    char padc[4];
    int m10;
    Ref_1c5890** m14;
    char pad2[0x120 - 0x18];
    void B();
};
struct ObjectManager_1c5890 {
    void* vptr;
    char pad[4];
    Store base;
    Store tmpl;
    ~ObjectManager_1c5890();
};
ObjectManager_1c5890::~ObjectManager_1c5890() {
    int n = base.m10;
    vptr = g_vtMgr;
    for (int i = 0; i < n; i++) {
        if ((unsigned)i < base.m8) {
            Ref_1c5890* r = base.m14[i];
            if (r)
                r->Release();
        }
    }
    tmpl.vptr = g_vtT;
    ((Render::StoreBase *)&tmpl)->FUN_001c7720();
    tmpl.B();
    base.vptr = g_vtO;
    ((Render::StoreBase *)&base)->FUN_001c7720();
    base.B();
}

