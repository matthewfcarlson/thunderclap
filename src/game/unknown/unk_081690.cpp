// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00081690..0x000832e0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fbd4e3f0 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fbd4e3f0 {} using namespace fn_fbd4e3f0;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fbd4e3f0 {
struct V3_81690 {
    float x, y, z;
    void FUN_00023750(const V3_81690* other);
};
union FloatBits_81690 {
    float f;
    unsigned int u;
};
struct Anchor_81690 {
    void FUN_00059a50(V3_81690* out);
};
struct Node124_81690 {
    char pad00[0x10];
    Anchor_81690* anchor;
};
struct Game20_81690 {
    char pad00[0x124];
    Node124_81690* f124;
};
} // namespace fn_fbd4e3f0
struct World {
    char pad00[0x20];
    Game20_81690* f20;
};
namespace fn_fbd4e3f0 {
hulk_freg __cdecl FUN_00224f10(V3_81690* dir);
struct Sink_81690 {
};
struct Frame_81690 {
    V3_81690 w;
    V3_81690 pos;
    V3_81690 nd;
};
struct Vec3_82d30 {
    float x, y, z;
};
class Matrix {
  public:
    char _m_pad_0[0x30];
    V3_81690 pos;
    float w;
    void FUN_0022cc90(const V3_81690* dir);
    void FUN_0022bec0(const Vec3_82d30* a, const Vec3_82d30* b);
};
class Body_81690 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(Matrix* m, int zero);
};
struct Slot_81690 {
    char pad00[0x1c];
    Matrix* mat;
};
class Registry_81690 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Slot_81690* v11();
};
class Entity {
public:
    char pad00[0x10];
    unsigned int state;
    char pad14[0x20 - 0x14];
    int f20;
    char pad24[4];
    unsigned int flags;
    float f2c;
    char pad30[4];
    Matrix m34;
    char pad74[0x84 - 0x74];
    int f84;
    int f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    int f9c;
    char pada0[0xdc - 0xa0];
    V3_81690 fdc;
    Registry_81690* fe8;
    Sink_81690* fec;
    char padf0[0x100 - 0xf0];
    Body_81690* f100;
    void FUN_00081690(int a0, V3_81690* dir, float step, bool lock, int a4);
};
struct Frame_82d30 {
    Vec3_82d30 axis;
    Vec3_82d30 input;
};
struct Vec3_83080 {
    float x, y, z;
};
class Xform_83080 {
public:
    void FUN_0022cc90(Vec3_83080 *v);
};
void __cdecl FUN_00224d70(float angle, Vec3_83080 *axis);
class Aligner {
public:
    char pad0[0x1d];
    bool useXform;
    char pad1e[0x0e];
    Vec3_83080 dir;
    bool FUN_00083080(Xform_83080 *xf, Vec3_83080 *target, float angle);
};
extern void* hulk_at_003ff90c[];
class Ref_832b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_832b0 {
  public:
    void* vptr;
    void Fin_0027afd0();
};
class CCow_832b0 : public Entity_832b0 {
  public:
    char pad[0x3c - 4];
    Ref_832b0* m3c;
    ~CCow_832b0();
};


// 0x00081690 FUN_00081690 (797 B): equivalent/0x00081690.cpp
// sym: ?FUN_00081690@Entity@fn_fbd4e3f0@@QAEXHPAUV3_81690@2@M_NH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3032 inputs, branch coverage 40/40)
// FUN_00081690 @ 0x00081690
void Entity::FUN_00081690(int a0, V3_81690* dir, float step, bool lock, int a4)
{
    Frame_81690 f;
    FloatBits_81690 fb;
    fb.f = dir->y;
    fb.u &= 0x7fffffff;
    fb.f = fb.f - 1.0f;
    fb.u &= 0x7fffffff;
    bool nearY = fb.f <= 0.2f;
    bool move = true;
    if (nearY)
        f84 = 0;
    unsigned int fl = flags;
    if ((fl >> 7) & 1)
        return;
    if (!lock) {
        switch (state) {
        case 1:
            if (!nearY) {
                state = 0xe;
                flags = fl | 2;
            }
            break;
        case 2:
        case 3:
            if (!nearY) {
                Anchor_81690* anchor = DAT_004dd700->f20->f124->anchor;
                f.w.y = 0.0f;
                anchor->FUN_00059a50(&f.pos);
                f.pos.FUN_00023750(&m34.pos);
                if (f.pos.z * dir->x - f.pos.x * dir->z > 0.0f) {
                    f.w.x = dir->z;
                    f.w.z = -dir->x;
                } else {
                    f.w.z = dir->x;
                    f.w.x = -dir->z;
                }
                fdc = m34.pos;
                ((owners::Vec3_11160 *)&fdc)->FUN_00011160(100.0f, (const owners::Vec3_11160 *)(const V3_81690 *)(&f.w));
            }
            break;
        case 5:
        case 6:
            move = false;
            break;
        case 7:
        case 8:
            if (state == 8) {
                if (f2c >= 1.0f)
                    f20 = 0;
            }
            if (nearY) {
                if (f90 < 0.0f) {
                    if (f94 > 5.0f) {
                        ((owners::Mat_22ba70 *)&m34)->FUN_0022ba70(f8c + 3.1415927f);
                        flags = flags | 2;
                        state = 0xb;
                    } else if (f94 > 3.0f) {
                        ((owners::Mat_22ba70 *)&m34)->FUN_0022ba70(f8c + 3.1415927f);
                        flags = flags | 2;
                        state = 0xf;
                    } else {
                        state = 0xa;
                        flags = fl | 3;
                    }
                }
            } else {
                f.nd.x = -dir->x;
                f.nd.y = -dir->y;
                f.nd.z = -dir->z;
                m34.FUN_0022cc90(&f.nd);
                flags = flags | 3;
                state = 9;
            }
            break;
        default:
            break;
        }
    } else {
        if (state <= 0xf) {
            if (state == 5 || state == 6) {
                move = false;
            } else {
                flags = fl | 1;
                f94 = 4.0f;
                f90 = 4.0f;
                f8c = FUN_00224f10(dir);
                f88 = 0;
                f9c = 0;
                flags = flags | 2;
                f98 = 30.0f;
                state = 7;
            }
            f20 = f20 - 1;
        } else {
            f20 = f20 - 1;
        }
    }
    if (move) {
        m34.pos.x = step * dir->x + m34.pos.x;
        m34.pos.y = step * dir->y + m34.pos.y;
        m34.pos.z = step * dir->z + m34.pos.z;
    }
    f100->v6(&m34, 0);
    ((owners::X_1c4d60 *)fec)->FUN_001c4d60((unsigned int *)(Matrix *)(&m34));
    *fe8->v11()->mat = m34;
}

} // namespace fn_fbd4e3f0

// 0x000819f0 FUN_000819f0 (289 B): equivalent/0x000819f0.cpp [wrapped: conflict: World]
// sym: ?FUN_000819f0@Object@fn_000819f0@@QAEXIIIMIII@Z
namespace fn_000819f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_000819f0 @ 0x000819f0
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

namespace pure3d { class Animation; }
namespace content { struct LoadInventory { template<class T> struct DynamicCaster { virtual T* cast(void*); }; }; }
struct Track { void* FUN_00288960(unsigned, unsigned); };
namespace pure3d { class Animation { public: Track* FUN_00288a20(int); }; }
struct Inventory_819f0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual pure3d::Animation* find(content::LoadInventory::DynamicCaster<pure3d::Animation>*, unsigned, unsigned); };
struct Resource_819f0 { Inventory_819f0* FUN_00203d70(); };
struct Manager_819f0 { Resource_819f0* FUN_000862a0(); };
struct World { char pad[0x54]; Manager_819f0* manager; };
struct Controller_819f0 {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
virtual void setValue(unsigned);
virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
virtual void setMode(int);
virtual void v17(); virtual void setEnabled(int); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
virtual void setAnimation(pure3d::Animation*, unsigned, unsigned);
char pad[0x144]; unsigned state;
};
struct Object {
char pad0[0x10]; int mode1; int mode2; char pad18[0x10]; unsigned flags; unsigned counter; float time; char pad34[0xbc]; Controller_819f0* controller; Track* track; void* translation; void* rotation;
void FUN_000819f0(unsigned a, unsigned b, unsigned c, float d, unsigned e, unsigned f, unsigned g);
};
void Object::FUN_000819f0(unsigned a,unsigned b,unsigned c,float d,unsigned e,unsigned f,unsigned g) {
Inventory_819f0* inventory = DAT_004dd700->manager->FUN_000862a0()->FUN_00203d70();
content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
pure3d::Animation* anim = inventory->find(&caster,a,b);
if (!anim) return;
mode1=6; mode2=6; counter=0;
track=anim->FUN_00288a20(0);
if(track) { translation=track->FUN_00288960(0x4e415254,0x54434556); rotation=track->FUN_00288960(0x544f52,0x544f52); }
else { translation=0; rotation=0; }
controller->setAnimation(anim,e,g);
controller->setMode(2);
controller->setValue(c);
controller->setEnabled((unsigned char)f ? 0:1);
controller->state=0;
flags &= ~8u;
if(d>0.0f) time=d;
}
} // namespace fn_000819f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00081b20 FUN_00081b20 (4266 B): equivalent/0x00081b20.cpp [wrapped: conflict: Matrix; World]
// sym: ?FUN_00081b20@CAnimState@fn_00081b20@@QAEXM@Z
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_00081b20 {
// STATUS: equivalent (tools/equiv.py level 3: 19925 inputs, branch coverage 177/179, incomplete)
// FUN_00081b20 @ 0x00081b20
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


namespace pure3d { class Animation; }
struct Loader;

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
    Loader *pad4;
};
}
}

struct Vec3_81b20;
struct Orient_81b20;

struct Vec3_81b20 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_00011160(float amount, Vec3_81b20 *dir);
    Vec3_81b20 *FUN_00011250(Vec3_81b20 *out, Vec3_81b20 *b);
    void FUN_00023750(Vec3_81b20 *b);
};

struct Orient_81b20 {
    char pad[0x30];
    void FUN_0022cc90(Vec3_81b20 *v);
    void FUN_0022c3b0(Vec3_81b20 *in, Vec3_81b20 *out);
    void FUN_0022ba70(float angle);
};

struct Quat_81b20 {
    float x, y, z, w;
    void FUN_0022b370(Orient_81b20 *o);
    void FUN_0022b120();
    void FUN_0022b650(Orient_81b20 *o);
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
};

struct Key {
    int lo;
    int hi;
    Key(const Key &o);
};
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30

struct Cue {
    char data[0x40];
    Cue(Key k, int x);
};
// equiv-map: ??0Cue@@QAE@UKey@@H@Z = 0x001c9c00

struct Rng_81b20 {
    float FUN_000787e0(float lo, float hi);
    int FUN_00011330(int n);
};

extern "C" Rng_81b20 *__cdecl FUN_000964d0();
float __cdecl FUN_00224f10(Vec3_81b20 *v);
void __cdecl FUN_00224d70(float angle, Vec3_81b20 *v);
float __cdecl FUN_00080ba0(float a, float b);
void __cdecl FUN_0022b080(Quat_81b20 *out, Quat_81b20 *a, Quat_81b20 *b);

struct Rig_81b20;
struct Animation2 {
    char pad00[0x10];
    float f10;
    float f14;
    Rig_81b20 *FUN_00288a20(int x);
};

struct Part_81b20 {
    char pad00[4];
    void FUN_0028a8f0(float a, float b, Quat_81b20 *q);
};

struct Rig_81b20 {
    Part_81b20 *FUN_00288960(int a, int b);
};

void __cdecl FUN_00080f60(Part_81b20 *f8, Part_81b20 *fc, Orient_81b20 *o, float a, float b, Vec3_81b20 *out);

struct Controller_81b20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vf6(float a, int b);
    virtual void v7();
    virtual void vf8(float a);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual float vf13();
    virtual void v14();
    virtual void v15();
    virtual void vf16(int a);
    virtual void v17();
    virtual void vf18(int a);
    virtual int vf19();
    virtual void v20();
    virtual void v21();
    virtual char vf22();
    virtual void v23();
    virtual void vf24(Animation2 *a, float b, float c);
    char pad04[0x148 - 4];
    int f148;
};

struct Pose {
    char pad00[0x10];
    Quat_81b20 *q;
    Matrix *mat;
    void FUN_00284820(Orient_81b20 *o);
};

struct PoseOwner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Pose *vf11();
};

struct Releasable_81b20 {
    virtual void v0();
    virtual void vf1();
};

struct Fx_81b20 {
    void FUN_001c5080(float a, float b);
    void FUN_001c4d60(Orient_81b20 *o);
};

struct Slot_81b20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vf6(Orient_81b20 *o, int x);
};

struct Entity {
    char pad00[0x10];
    struct Holder_81b20 *holder;
    char pad14[0x140 - 0x14];
    int f140;
    void FUN_00035660(Vec3_81b20 *out);
};

struct Holder_81b20 {
    void FUN_00059a50(Vec3_81b20 *out);
};

struct Player_81b20 {
    char pad00[0x124];
    Entity *entity;
    void FUN_00029bb0(struct Slot_81b20 *a, Releasable_81b20 *b, float c);
};

struct Splash {
    void FUN_00283a40(Key *k, Matrix *m, float a, float b);
};

struct W24 {
    char pad00[0x18];
    float level;
    char pad1c[4];
    Key key;
    char name[1];
};

struct Mgr34 {
    void FUN_001ebbc0(void *who, const char *name);
    void FUN_001ec0f0(void *who, const char *name);
};

struct Obj30 {
    void FUN_001cbc20(Cue *p);
};

struct Factory_81b20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Animation2 *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, int a, int b);
};

struct Mid_81b20 {
    Factory_81b20 *FUN_00203d70();
};

struct Flags_81b20 {
    bool FUN_00092940(int id);
};

struct Holder54_81b20 {
    Mid_81b20 *FUN_000862a0();
    Flags_81b20 *FUN_00086340();
};

struct World {
    char pad00[0x20];
    Player_81b20 *player;
    W24 *w24;
    char pad28[8];
    Obj30 *obj30;
    Mgr34 *mgr;
    char pad38[0x54 - 0x38];
    Holder54_81b20 *holder;
};

struct Gravity_81b20 {
    char pad00[0x10];
    Vec3_81b20 g;
};

struct EntryRec {
    unsigned lo;
    unsigned hi;
    char flag8;
    char pad9[7];
};

extern "C" int __cdecl FUN_00098190(float a, float b, float c, int d, Releasable_81b20 *o, float e, Vec3_81b20 *pos, Vec3_81b20 *va, int f, int g, int h, int i);
extern "C" Splash *__cdecl FUN_0027f250();

static __forceinline void AbsInPlace(float &v)
{
    *(unsigned *)&v &= 0x7fffffff;
}

struct Frame81 {
    Vec3_81b20 v10;
    float s1c;
    Vec3_81b20 v20;
    float s2c;
    Quat_81b20 q30;
    char cbuf[8];
    char slot48[16];
    char slot58[0x40];
};

class CAnimState {
public:
    char pad00[8];
    Key name;
    int state;
    int prev;
    char pad18[4];
    float f1c;
    int f20;
    int f24;
    unsigned flags;
    float timer;
    float limit;
    Orient_81b20 orient;
    Vec3_81b20 pos;
    char pad70[4];
    Vec3_81b20 old;
    float f80;
    float f84;
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    int v9c;
    float fa0;
    Vec3_81b20 va4;
    float fb0;
    float fb4;
    Releasable_81b20 *fb8;
    int fbc;
    float fc0;
    float fc4;
    char pad_c8[4];
    int fcc;
    Vec3_81b20 vd0;
    Vec3_81b20 vdc;
    PoseOwner *fe8;
    Fx_81b20 *fec;
    Controller_81b20 *volatile ctrl;
    Rig_81b20 *rig;
    Part_81b20 *part;
    Part_81b20 *joint;
    Slot_81b20 *fx100;

    void FUN_00081b20(float dt);
};

void CAnimState::FUN_00081b20(float dt)
{
    Frame81 fr;
    char *cbuf = fr.cbuf;
    char *slot58 = fr.slot58;
    char *slot48 = fr.slot48;
    Vec3_81b20 &v48 = *(Vec3_81b20 *)slot48;
    Vec3_81b20 &v10 = fr.v10;
    Vec3_81b20 &v20 = fr.v20;
    Vec3_81b20 &v30 = *(Vec3_81b20 *)&fr.q30;
    int &next = *(int *)(cbuf + 4);
    next = 0x10;
    hulk_freg dx = pos.x - old.x;
    hulk_freg dy = pos.y - old.y;
    hulk_freg dz = pos.z - old.z;
    fr.s1c = (float)sqrt((dx * dx + dz * dz) + dy * dy);
    AbsInPlace(fr.s1c);
    if ((fr.s1c / dt) < 3.0f)
        f80 = dt + f80;
    else
        f80 = 0.0f;
    old.x = pos.x;
    old.y = pos.y;
    old.z = pos.z;

    if ((flags & 0x20) && (state == 1 || state == 3)) {
        flags &= ~0x20u;
        v20.x = pos.x - vdc.x;
        v20.y = pos.y - vdc.y;
        v20.z = pos.z - vdc.z;
        if (v20.x != 0.0f || v20.z != 0.0f)
            orient.FUN_0022cc90(&v20);
    }

    EntryRec *rec;
    if (state != prev) {
        prev = state;
        timer = 0.0f;
        f84 = 0.0f;
        f80 = 0.0f;
        int pick;
        if (state == 7) {
            pick = v9c;
        } else {
            Rng_81b20 *rg = FUN_000964d0();
            int cnt = (flags & 4) ? ((int*)&DAT_003ff508)[state] : ((int*)&DAT_003ff488)[state];
            pick = rg->FUN_00011330(cnt - 1);
            if (fb8 != 0) {
                fb8->vf1();
                fb8 = 0;
            }
        }
        int base = (flags & 4) ? ((int*)&DAT_003ff548)[state] : ((int*)&DAT_003ff4c8)[state];
        int idx = base + pick;
        Factory_81b20 *fac = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        rec = &((EntryRec*)&DAT_004dd090)[idx];
        content::LoadInventory::DynamicCaster<pure3d::Animation> *caster = new (cbuf) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        Animation2 *anim = fac->f3(caster, rec->lo, rec->hi);
        if (anim == 0)
            return;
        Rig_81b20 *r = anim->FUN_00288a20(0);
        rig = r;
        if (r != 0) {
            part = r->FUN_00288960(0x4e415254, 0x54434556);
            joint = rig->FUN_00288960(0x544f52, 0x544f52);
        } else {
            part = 0;
            joint = 0;
        }
        float &blend = fr.s1c;
        blend = (flags & 1) ? 5.0f : 0.0f;
        flags &= ~1u;
        switch (state) {
        case 1: {
            float &rr = fr.s2c;
            float hi = anim->f10 - 1.0f;     // read before FUN_000964d0, as the original does
            rr = FUN_000964d0()->FUN_000787e0(0.0f, hi);
            ctrl->vf24(anim, rr, blend);
            ctrl->vf8(f1c);
            break;
        }
        case 5:
        case 9:
        case 10:
            ctrl->vf24(anim, 0.0f, 0.0f);
            ctrl->vf8(1.0f);
            break;
        case 7:
            ctrl->vf24(anim, 0.0f, 0.0f);
            ctrl->vf8(0.5f);
            break;
        case 6:
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 8:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            ctrl->vf24(anim, 0.0f, blend);
            ctrl->vf8(1.0f);
            break;
        default:
            break;
        }
        char flag8 = rec->flag8;
        if (flag8) {
            ctrl->vf16(2);
            ctrl->vf18(1);
            ctrl->vf18(0);
        } else {
            ctrl->vf16(2);
            ctrl->vf18(0);
            ctrl->vf18(1);
        }
        if (state == 7 || state == 8) {
            if (state == 8) {
                orient.FUN_0022c3b0(((Vec3_81b20*)&DAT_0049bf1c), &v30);
                f8c = FUN_00224f10(&v30);
            }
            flags |= 8;
            ctrl->f148 = 0xffff;
        } else {
            flags &= ~8u;
            ctrl->f148 = 0;
        }
        switch (state) {
        case 2:
            limit = FUN_000964d0()->FUN_000787e0(0.3f, 1.0f);
            break;
        case 4:
            limit = FUN_000964d0()->FUN_000787e0(5.0f, 10.0f);
            break;
        case 12:
            if (f20 > 0)
                limit = FUN_000964d0()->FUN_000787e0(0.5f, 3.0f);
            else
                limit = 1.0f;
            break;
        case 5:
            limit = 2.5f;
            break;
        case 0:
            if (fbc >= 0)
                limit = FUN_000964d0()->FUN_000787e0(1.0f, 5.0f);
            else
                limit = 20.0f / anim->f14;
            break;
        case 11:
            limit = 20.0f / anim->f14;
            break;
        default:
            limit = 3.4028235e+38f;
            break;
        }
        Mgr34 *mgr = DAT_004dd700->mgr;
        switch (state) {
        case 2: mgr->FUN_001ebbc0(this, "startled"); break;
        case 3: mgr->FUN_001ebbc0(this, "running"); break;
        case 4: mgr->FUN_001ebbc0(this, "cowering"); break;
        case 5: mgr->FUN_001ebbc0(this, "grabbed"); break;
        case 7: mgr->FUN_001ebbc0(this, "flying"); break;
        case 8: mgr->FUN_001ebbc0(this, "falling"); break;
        case 9: mgr->FUN_001ebbc0(this, "hit_wall"); break;
        case 10: mgr->FUN_001ebbc0(this, "hit_ground"); break;
        case 11: mgr->FUN_001ebbc0(this, "rolling"); break;
        case 12: mgr->FUN_001ebbc0(this, "lying_down"); break;
        case 15: mgr->FUN_001ebbc0(this, "rolling"); break;
        default: break;
        }
    }

    if (state == 3) {
        Holder_81b20 *h = DAT_004dd700->player->entity->holder;
        Entity *tgt = DAT_004dd700->player->entity;
        h->FUN_00059a50(&v10);
        v10.x = v10.x - pos.x;
        v10.y = v10.y - pos.y;
        v10.z = v10.z - pos.z;
        tgt->FUN_00035660(&v48);
        if ((v48.z * v10.z + v48.y * v10.y) + v48.x * v10.x < 0.0f) {
            hulk_freg l2 = (v10.z * v10.z + v10.x * v10.x) + v10.y * v10.y;
            if (l2 < DAT_0049b8a4) {
                double d = sqrt(l2);
                v30.x = 0.0f;
                v30.y = 0.0f;
                v30.z = 1.0f;
                hulk_freg k = -1.0f / d;
                v10.x = v10.x * k;
                v10.y = v10.y * k;
                v10.z = v10.z * k;
                orient.FUN_0022c3b0(&v30, &v20);
                if ((v10.z * v20.z + v10.x * v20.x) + v10.y * v20.y > -0.99f) {
                    if (v20.z * v10.x - v20.x * v10.z > 0.0f)
                        FUN_00224d70(-0.05f, &v20);
                    else
                        FUN_00224d70(0.05f, &v20);
                    orient.FUN_0022cc90(&v20);
                }
            }
        }
        if (f80 > 0.5f)
            next = 4;
    } else if (state > 4 && state <= 6) {
        f84 = 0.0f;
    }

    float &A = fr.s2c;
    A = ctrl->vf13();
    ctrl->vf6(dt * 1000.0f, 1);
    float &B = fr.s1c;
    B = ctrl->vf13();
    Pose *ps = fe8->vf11();
    Quat_81b20 &qz = fr.q30;
    qz.x = 0.0f;
    qz.y = 0.0f;
    qz.z = 0.0f;
    qz.w = 1.0f;
    *ps->q = qz;
    float *trans = &ps->mat->m[12];   // the original reads ps->mat once for the three stores
    trans[0] = 0.0f;
    trans[1] = 0.0f;
    trans[2] = 0.0f;

    if (!(flags & 8)) {
        v20 = pos;
        Quat_81b20 &qi = *(Quat_81b20 *)slot48;
        qi.x = 0.0f;
        qi.y = 0.0f;
        qi.z = 0.0f;
        qi.w = 1.0f;
        if (joint != 0)
            joint->FUN_0028a8f0(A, B, &qi);
        Quat_81b20 &q58 = *(Quat_81b20 *)slot58;
        q58.FUN_0022b370(&orient);
        FUN_0022b080(&q58, &q58, &qi);
        FUN_00080f60(part, joint, &orient, A, B, &v10);
        q58.FUN_0022b120();
        q58.FUN_0022b650(&orient);
        pos.x = v20.x;
        pos.y = v20.y;
        pos.z = v20.z;
        if (state == 3 || state == 1 || state == 11 || state == 15) {
            if (f84 > 0.5f) {
                f88 = 0.0f;
                f98 = 30.0f;
                f94 = 1.0f;
                f90 = -1.0f;
                next = 8;
            } else if (f84 > 0.1f) {
                v30 = (*(Gravity_81b20**)&DAT_00554c10)->g;
                v10.y = v10.y + (((v30.y * 0.01f) * dt) * dt);
            }
        }
        pos.x = v10.x + pos.x;
        pos.y = v10.y + pos.y;
        pos.z = v10.z + pos.z;
    } else if (fb8 != 0) {
        fa0 = fa0 - (dt * fb0);
        int hit = FUN_00098190(dt, fb0, fb4, 0, fb8, 0.5f, &pos, &va4, 0, 0, 0, 1);
        if (hit) {
            DAT_004dd700->player->FUN_00029bb0(fx100, fb8, fa0);
        } else {
            if (fb8 != 0) {
                fb8->vf1();
                fb8 = 0;
            }
            f90 = va4.y * fb0;
            f94 = sqrt(va4.x * va4.x + va4.z * va4.z) * fb0;
            f8c = FUN_00224f10(&va4);
        }
        v10.x = va4.x * fb0;
        v10.y = va4.y * fb0;
        v10.z = va4.z * fb0;
        if (fb8 == 0) {
            v20 = (*(Gravity_81b20**)&DAT_00554c10)->g;
            v10.x = v20.x * dt + v10.x;
            v10.y = ((v20.y * 0.01f) * dt) + v10.y;
            va4.y = v10.y;
            v10.z = v20.z * dt + v10.z;
            va4.z = v10.z;
            va4.x = v10.x;
            fb0 = va4.FUN_0022d110();
        }
        v20.x = v10.x * dt;
        v20.y = v10.y * dt;
        v20.z = v10.z * dt;
        v20.x = v20.x + pos.x;
        v20.y = v20.y + pos.y;
        v20.z = v20.z + pos.z;
        float &h = fr.s2c;
        h = FUN_00224f10(&va4) + f8c;
        pos.x = v20.x;
        pos.y = v20.y;
        pos.z = v20.z;
        orient.FUN_0022ba70(h);
    } else {
        v10 = (*(Vec3_81b20*)&DAT_0049bf1c);
        FUN_00224d70(f8c, &v10);
        hulk_freg t = dt * f94;
        // the original keeps the x product in a register and stores the z product (rounded) before the sums
        struct { hulk_freg x; float z; } step = { v10.x * t, v10.z * t };
        v10.x = step.x + pos.x;
        v10.y = v10.y + pos.y;
        v10.z = step.z + pos.z;
        hulk_freg left = f88 - dt;     // stored, and compared below unrounded
        f88 = left;
        v30 = (*(Gravity_81b20**)&DAT_00554c10)->g;
        float &c = fr.s2c;
        c = v30.y * 0.01f;
        if (left <= 0.0f) {
            float &ac = fr.s1c;
            ac = c;
            AbsInPlace(ac);
            if (f98 < ac)
                f98 = ac;
        }
        if (DAT_004dd700->holder->FUN_00086340()->FUN_00092940(0x13))
            f98 = (*(Gravity_81b20**)&DAT_00554c10)->g.y * -0.01f;
        hulk_freg vy = f90 - (dt * f98);   // stored, and used unrounded below
        f90 = vy;
        pos.x = v10.x;
        pos.z = v10.z;
        pos.y = (vy * dt) + v10.y;
    }


    timer = dt + timer;
    f84 = dt + f84;
    int ns = next;
    bool force = false;
    if ((flags & 2) && ((ctrl->vf19() == 0 && timer >= limit) || ctrl->vf22())) {
        {
            switch (state) {
            case 0:
                flags |= 0x20;
                ns = 1;
                force = true;
                break;
            case 2:
            case 4:
                force = true;
                ns = 3;
                if (flags & 0x40) {
                    flags &= ~0x40u;
                    flags |= 0x20;
                } else {
                    Holder_81b20 *h = DAT_004dd700->player->entity->holder;
                    h->FUN_00059a50(&v20);
                    v20.FUN_00023750(&pos);
                    vdc.FUN_00011250(&v10, &pos);
                    if ((v20.z * v10.z + v20.x * v10.x) + v20.y * v10.y > 0.0f) {
                        Vec3_81b20 *r = vd0.FUN_00011250(&v48, &pos);
                        if ((v20.z * r->z + v20.x * r->x) + v20.y * r->y < 0.0f) {
                            v20 = vdc;
                            vdc = vd0;
                            vd0 = v20;
                        } else {
                            vdc = pos;
                            vdc.FUN_00011160(-10.0f, &v20);
                        }
                    } else if (v10.x == 0.0f && v10.z == 0.0f) {
                        vdc = pos;
                        vdc.FUN_00011160(-10.0f, &v20);
                    }
                    flags |= 0x20;
                }
                break;
            case 5:
                if (DAT_004dd700->player->entity->f140 == 3) {
                    DAT_004dd700->mgr->FUN_001ebbc0(this, "grabbed");
                    limit = 2.5f;
                }
                break;
            case 6:
                ns = 7;
                force = true;
                break;
            case 9:
                pos.y = pos.y - 0.8f;
                ns = 8;
                force = true;
                f88 = 0.0f;
                f98 = 30.0f;
                f94 = 2.0f;
                f90 = -3.0f;
                break;
            case 10:
            case 15:
                ns = 12;
                force = true;
                break;
            case 11: {
                ns = 10;
                force = true;
                orient.FUN_0022c3b0(((Vec3_81b20*)&DAT_0049bf1c), &v30);
                float &hh = v20.x;
                hh = FUN_00224f10(&v30);
                float &rr = fr.s1c;
                rr = FUN_00080ba0(1.5707963705062866f, 4.71238899230957f) + hh;
                orient.FUN_0022ba70(rr);
                break;
            }
            case 12:
                if (f20 > 0) {
                    ns = 13;
                    force = true;
                } else if (!(flags & 0x80)) {
                    fec->FUN_001c5080((*(float*)&DAT_00421894), 1.0f);
                    flags |= 0x80;
                    new (slot58) Cue(name, f24);
                    DAT_004dd700->obj30->FUN_001cbc20((Cue *)slot58);
                }
                break;
            case 13:
                ns = 0;
                force = true;
                break;
            case 14:
                fcc = (fcc == 0);
                ns = 0;
                force = true;
                vdc = pos;
                fc4 = fc0;
                break;
            default:
                break;
            }
        }
    }
    if (force || (ns != 0x10 && ns >= 0 && ns < 0x10)) {
        state = ns;
        flags |= 2;
    }
    World *&w = *(World **)fr.cbuf;
    w = DAT_004dd700;
    W24 *w24 = w->w24;
    float &L = fr.s1c;
    L = w24->level;
    if ((pos.y <= L && old.y > L) || (pos.y >= L && old.y < L)) {
        if ((w24->key.lo | w24->key.hi) != 0) {
            Splash *sp = FUN_0027f250();
            Matrix &m = *(Matrix *)slot58;
            m.FUN_0022b980();
            m.m[12] = pos.x;
            m.m[13] = L;
            m.m[14] = pos.z;
            sp->FUN_00283a40(&w24->key, &m, -1.0f, 0.5f);
        }
        char *nm = w24->name;
        if (nm != 0 && *nm != 0)
            w->mgr->FUN_001ec0f0(this, nm);
    }
    fe8->vf11()->FUN_00284820(&orient);
    fec->FUN_001c4d60(&orient);
    fx100->vf6(&orient, 0);
}
} // namespace fn_00081b20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00082cd0 FUN_00082cd0 (17 B): matches/0x00082cd0.cpp
// sym: ?FUN_00082cd0@Target_82cd0@owners@@QAEXH@Z
void owners::Target_82cd0::FUN_00082cd0(int) {
    a = 4;
    b = 0;
}

namespace fn_fbd4e3f0 {

// 0x00082d30 FUN_00082d30 (121 B): equivalent/0x00082d30.cpp
// sym: _FUN_00082d30
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00082d30 @ 0x00082d30
// The matrix is passed in esi.
// equiv-conv: FUN_00082d30 esi
extern "C" void FUN_00082d30(Matrix* m) {
    Frame_82d30 f;
    f.input.x = 0.0f;
    f.input.y = 0.0f;
    f.input.z = 1.0f;
    ((owners::M_22c3b0 *)m)->FUN_0022c3b0((float *)(const Vec3_82d30 *)(&f.input), (float *)(Vec3_82d30 *)(&f.axis));
    f.axis.y = 0.0f;
    if (f.axis.x == 0.0f)
        f.axis.x = 1.0f;
    f.input.x = 0.0f;
    f.input.y = 1.0f;
    f.input.z = 0.0f;
    m->FUN_0022bec0(&f.axis, &f.input);
}

} // namespace fn_fbd4e3f0

// 0x00082db0 FUN_00082db0 (714 B): equivalent/0x00082db0.cpp [wrapped: conflict: World]
// sym: ?FUN_00082db0@Fx_82db0@fn_00082db0@@QAEXMPAUXform_82db0@2@@Z
namespace fn_00082db0 {
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 14/14)
// FUN_00082db0 @ 0x00082db0
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

struct V3_82db0 { float x, y, z; };

struct Quat_82db0 {
    float x, y, z, w;
    void FUN_0022b650(struct Xform_82db0 *m);
};

struct Xform_82db0 {
    char pad0[0x30];
    V3_82db0 pos;                 // 0x30
};

struct Body_82db0 {
    char pad0[0x10];
    V3_82db0 *rot;                // 0x10 (x,y,z,w quaternion storage)
    V3_82db0 *vec;                // 0x14
};

struct Node {
    char pad0[0x50];
    V3_82db0 vel;                 // 0x50
    char pad5c[0x6c - 0x5c];
    int link;               // 0x6c
    void FUN_002ef8b0(int a);
};

struct Src_82db0;
struct Link_82db0 {
    char pad0[0x9c];
    Src_82db0 *src;        // 0x9c
    void FUN_001d7510();
};

struct Src_82db0 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10();
    virtual Body_82db0 *s11();
};

struct Player_82db0 {
};

struct World {
    char pad0[0xc];
    Player_82db0 *players;        // 0xc
};

struct Anim_82db0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(float a, int b);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12();
    virtual float v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23();
    virtual void v24(int a, int b, int c);
    void FUN_00288080(Body_82db0 *b);
};

struct Orient_82db0 {
    void FUN_0028a8f0(float a, float b, Quat_82db0 *q);
};

struct Wind {
    char pad0[0x10];
    V3_82db0 v;                   // 0x10
};

extern void FUN_0022b080(Quat_82db0 *out, Quat_82db0 *a, Quat_82db0 *b);
extern void FUN_00080f60(int a, Orient_82db0 *o, Xform_82db0 *x, float f1, float f2, V3_82db0 *v);

struct Fx_82db0 {
    char pad0[0x10];
    int owner;              // 0x10
    int state;              // 0x14
    char pad18[5];
    char skipAnim;          // 0x1d
    char pad1e[0x24 - 0x1e];
    float f24;              // 0x24
    float f28;              // 0x28
    V3_82db0 vel;                 // 0x2c
    int link;               // 0x38
    Anim_82db0 *anim;             // 0x3c
    char pad40[4];
    int kind;               // 0x44
    Orient_82db0 *orient;         // 0x48
    void FUN_00082db0(float dt, Xform_82db0 *x);
};

void Fx_82db0::FUN_00082db0(float dt, Xform_82db0 *x)
{
    if (link == 0)
        return;
    Link_82db0 *lk = ((Link_82db0 *)((owners::Obj_1dc0d0 *)(DAT_004dd700->players))->FUN_001dc0d0((hulk_intptr)owner));
    Body_82db0 *body = lk->src->s11();
    if (skipAnim == 0) {
        anim->FUN_00288080(body);
        anim->v24(link, 0, 0);
        ((Node *)((owners::C_1d72e0 *)lk)->FUN_001d72e0())->FUN_002ef8b0(0);
    }
    float f1 = anim->v13();
    anim->v6(dt * 1000.0f, 1);
    float f2 = anim->v13();
    V3_82db0 *p = &x->pos;
    V3_82db0 v = *p;
    Quat_82db0 q;
    q.x = 0.0f; q.y = 0.0f; q.z = 0.0f; q.w = 1.0f;
    if (orient != 0)
        orient->FUN_0028a8f0(f1, f2, &q);
    Quat_82db0 r;
    ((owners::Quat_22b370 *)&r)->FUN_0022b370((const float *)(struct Xform_82db0 *)x);
    FUN_0022b080(&r, &r, &q);
    FUN_00080f60(kind, orient, x, f1, f2, &vel);
    ((owners::Vec4_22b120 *)&r)->FUN_0022b120();
    r.FUN_0022b650(x);
    *p = v;
    V3_82db0 *rot = (V3_82db0 *)body->rot;
    rot->x = 0.0f; rot->y = 0.0f; rot->z = 0.0f;
    ((float *)rot)[3] = 1.0f;
    V3_82db0 *bv = (V3_82db0 *)((char *)body->vec + 0x30);
    bv->x = 0.0f; bv->y = 0.0f; bv->z = 0.0f;
    ((owners::C_284820 *)body)->FUN_00284820((hulk_intptr)(Xform_82db0 *)x);
    if (((Node *)((owners::C_1d72e0 *)lk)->FUN_001d72e0())->link != 0) {
        Node *n = ((Node *)((owners::C_1d72e0 *)lk)->FUN_001d72e0());
        vel.x = n->vel.x;
        vel.y = n->vel.y;
        vel.z = n->vel.z;
        return;
    }
    if (dt > 0.0f) {
        double inv = 1.0f / dt;
        vel.x = (float)(inv * vel.x);
        vel.y = (float)(inv * vel.y);
        vel.z = (float)(inv * vel.z);
    }
    if (f28 > 1.0f) {
        lk->FUN_001d7510();
        state = 7;
        f24 = 0.0f;
    }
    if (f28 > 0.1f) {
        V3_82db0 w = (*(Wind**)&DAT_00554c10)->v;
        double wy = w.y * 0.01f;
        vel.x = (float)(w.x * dt + vel.x);
        vel.y = (float)(wy * dt + vel.y);
        vel.z = (float)(w.z * dt + vel.z);
    }
    p->x = (float)(dt * vel.x + p->x);
    p->y = (float)(dt * vel.y + p->y);
    p->z = (float)(dt * vel.z + p->z);
}
} // namespace fn_00082db0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fbd4e3f0 {

// 0x00083080 FUN_00083080 (309 B): equivalent/0x00083080.cpp
// sym: ?FUN_00083080@Aligner@fn_fbd4e3f0@@QAE_NPAVXform_83080@2@PAUVec3_83080@2@M@Z
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 10/10)
// FUN_00083080 @ 0x00083080
bool Aligner::FUN_00083080(Xform_83080 *xf, Vec3_83080 *target, float angle)
{
    if (useXform) {
        Vec3_83080 up;
        Vec3_83080 rotated;
        up.x = 0.0f;
        up.y = 0.0f;
        up.z = 1.0f;
        ((owners::M_22c3b0 *)xf)->FUN_0022c3b0((float *)(Vec3_83080 *)(&up), (float *)(Vec3_83080 *)(&rotated));
        hulk_freg d = rotated.y * target->y + rotated.x * target->x + rotated.z * target->z;
        if (d < -0.99f)
            return false;
        hulk_freg c = rotated.z * target->x - rotated.x * target->z;
        if (c > 0.0f)
            FUN_00224d70(-angle, &rotated);
        else
            FUN_00224d70(angle, &rotated);
        xf->FUN_0022cc90(&rotated);
        return true;
    }
    hulk_freg d = dir.y * target->y + dir.z * target->z + dir.x * target->x;
    if (d > 0.99f)
        return false;
    hulk_freg c = dir.z * target->x - dir.x * target->z;
    if (c > 0.0f)
        FUN_00224d70(-angle, &dir);
    else
        FUN_00224d70(angle, &dir);
    return true;
}

} // namespace fn_fbd4e3f0

// 0x000831c0 FUN_000831c0 (230 B): equivalent/0x000831c0.cpp [wrapped: conflict: World]
// sym: ??0CCow@fn_000831c0@@QAE@IIIII@Z
namespace fn_000831c0 {
// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// FUN_000831c0 @ 0x000831c0
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

struct Handle_831c0 { void FUN_0027b040(unsigned); };
struct PoseAnimationController_831c0 {
 virtual void slot0(); virtual void slot1();
 char pad[0x144]; unsigned mode;
 PoseAnimationController_831c0* FUN_00287860();
 void FUN_00284ad0(unsigned);
 void FUN_00288080(unsigned);
};
struct Source_831c0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual unsigned s11(); };
struct Entry_831c0 { char pad[0x9c]; Source_831c0* source; };
struct Manager_831c0 { bool FUN_001dd800(unsigned); Entry_831c0* FUN_001dc0d0(unsigned); };
struct World { char pad[12]; Manager_831c0* manager; };
void* __cdecl FUN_00263ea0(unsigned);
struct FUN_0027b070 { FUN_0027b070(); virtual void v0(); };
struct CCow : FUN_0027b070 {
 unsigned field4; Handle_831c0 handle; unsigned fieldC;
 unsigned id, value, type;
 unsigned char flag1,flag2; char pad1[2];
 unsigned f20,f24,f28,f2c,f30,f34,f38;
 PoseAnimationController_831c0* resource;
 unsigned f40,f44,f48;
 virtual void v0();
 CCow(hulk_uintptr h,unsigned i,unsigned v,hulk_uintptr a,hulk_uintptr b);
};
CCow::CCow(hulk_uintptr h,unsigned i,unsigned v,hulk_uintptr a,hulk_uintptr b) {
 id=i; value=v; type=9; flag1=0; flag2=0;
 f20=f24=f28=f2c=f30=f34=f38=0; resource=0; f40=f44=f48=0;
 handle.FUN_0027b040(h);
 PoseAnimationController_831c0* p=(PoseAnimationController_831c0*)FUN_00263ea0(0x150);
 if(p) p=p->FUN_00287860();
 if(p) p->slot0();
 if(resource) resource->slot1();
 resource=p;
 p->FUN_00284ad0(0);
 resource->mode=3;
 Manager_831c0* m=DAT_004dd700->manager;
 if(m->FUN_001dd800(id)) {
 Entry_831c0* e=m->FUN_001dc0d0(id);
 unsigned x=e->source->s11();
 resource->FUN_00288080(x);
 }
}
} // namespace fn_000831c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fbd4e3f0 {

// 0x000832b0 FUN_000832b0 (36 B): matches/0x000832b0.cpp
// sym: ??1CCow_832b0@fn_fbd4e3f0@@QAE@XZ
CCow_832b0::~CCow_832b0() {
    vptr = hulk_at_003ff90c;
    _ReadWriteBarrier();
    if (m3c) {
        m3c->Release();
        m3c = 0;
    }
    Fin_0027afd0();
}

} // namespace fn_fbd4e3f0
