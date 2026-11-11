// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00016db0..0x00017020 (kind game, layer game, confidence high), dominant class CCameraDramaticAction
#include "tree_prelude.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fd226368 {
#define TREE_TU_END }
namespace fn_fd226368 {} using namespace fn_fd226368;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd226368 {
class CAction_16ff0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
};

} // namespace fn_fd226368

// 0x00016db0 CCameraDramaticAction::vfunc_6 (567 B): equivalent/0x00016db0.cpp [wrapped: conflict: CCameraDramaticAction]
// sym: ?vfunc_6@CCameraDramaticAction@fn_00016db0@@QAEDH@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00016db0 {
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 16/16)
// CCameraDramaticAction::vfunc_6 @ 0x00016db0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_16db0 {
    float x, y, z;
};

struct Id_16db0 {
    int lo, hi;
};

struct Mat_16db0 {
    float m[16];
};

struct Scene_16db0 {
    void FUN_00035160(Mat_16db0* out);
};

struct Handle_16db0 {
    char pad[4];
};

struct Config_16db0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad04[0x10];
    Vec3_16db0 offset;
    Id_16db0 ids[8];
    int values[8];
    int count;
    char flag;
    char pad85[3];
    int params[6];
};

struct Sub_16db0 {
    void FUN_0009d100(Id_16db0* id, float scale, int value);
    void FUN_00098f50(int a, int b, int c, int d, int e, int f);
    void FUN_0009bd80(struct World* mgr, Mat_16db0* mat, Vec3_16db0 offset, int count);
};

struct World {
    char pad0[8];
    Sub_16db0* sub;
};


Handle_16db0* __fastcall FUN_000592a0(void* owner);
extern "C" Scene_16db0* __fastcall FUN_00059a30(Handle_16db0* h);

class CCameraDramaticAction {
public:
    char pad0[0x1c];
    void* owner;
    Config_16db0* cfg;
    int field24;
    char vfunc_6(int arg);
};

char CCameraDramaticAction::vfunc_6(int arg)
{
    Mat_16db0 mat;

    FUN_00059a30(FUN_000592a0(owner))->FUN_00035160(&mat);

    for (int i = 0; i < 8; i++) {
        Config_16db0* c = cfg;
        if ((c->ids[i].lo | c->ids[i].hi) != 0) {
            Sub_16db0* sub = DAT_004dd700->sub;
            int value = c->values[i];
            float scale = c->v7();
            sub->FUN_0009d100(&c->ids[i], scale, value);
        }
    }

    Config_16db0* c = cfg;
    DAT_004dd700->sub->FUN_00098f50(c->params[0], c->params[1], c->params[2], c->params[3], c->params[4], c->params[5]);
    c = cfg;
    DAT_004dd700->sub->FUN_0009bd80(DAT_004dd700, &mat, c->offset, c->count);
    Config_16db0* c2 = cfg;
    field24 = arg;
    return c2->flag;
}
} // namespace fn_00016db0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00016ff0 CCameraDramaticAction::vfunc_7 (12 B): matches/0x00016ff0.cpp
// sym: ?vfunc_7@CCameraDramaticAction@@UAE_NH@Z
bool CCameraDramaticAction::vfunc_7(int __p0) { unsigned int x = (unsigned int)__p0;

    this->f_24 = x;
    return (bool)(1);
}


// 0x00017000 CCameraDramaticAction::vfunc_4 (28 B): matches/0x00017000.cpp [wrapped: conflict: CCameraDramaticAction]
// sym: ?vfunc_4@CCameraDramaticAction@fn_00017000@@UAEXXZ
namespace fn_00017000 {
class CCameraDramaticAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    char pad[0x1C];
    char* mPtr;
};

class Sub_17000 {
  public:
    void Fn_0009a1e0(void* arg);
};

class Obj_17000 {
  public:
    char pad[8];
    Sub_17000* sub;
};

extern Obj_17000* hulk_at_004dd700;

void CCameraDramaticAction::vfunc_4() {
    if (*(char*)(mPtr + 0x84) != 0) {
        hulk_at_004dd700->sub->Fn_0009a1e0(hulk_at_004dd700);
    }
}
} // namespace fn_00017000

