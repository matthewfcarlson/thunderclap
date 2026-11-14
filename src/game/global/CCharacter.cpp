// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x000382c0..0x00044910 (kind game, layer game, confidence medium), dominant class CCharacter
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f35f7bdf {
#define TREE_TU_END }
namespace fn_f35f7bdf {} using namespace fn_f35f7bdf;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f35f7bdf {
struct Vec3_38410 { float x,y,z; };
struct Event_384e0 {
    int w[7];
    Event_384e0 *FUN_001ca210(int prev, int next, int id);
};
struct Channel {
    void FUN_001cbc20(Event_384e0 *e);
};
} // namespace fn_f35f7bdf
struct World {
    char pad[0x30];
    Channel *channel;
};
namespace fn_f35f7bdf {
struct Owner_384e0 {
    int id;
};
struct Controller_384e0 {
    char pad00[0x10];
    Owner_384e0 *owner;
    char pad14[0x134 - 0x14];
    int current;
    void FUN_000384e0(const char *name);
};
class Item_38c40 {
  public:
    virtual void f();
    virtual void Release();
};
struct Entry_38c40 {
    Item_38c40* volatile p;
    volatile unsigned char flag;
    char pad[0x33];
};
class Owner_38c40 {
  public:
    char pad[0x1ed8];
    Entry_38c40 entries[3];
    void Clear();
};
struct V3_38c70 { float x, y, z; };
struct Target_38c70 {
    char pad00[0x3c];
};
struct Anchor_38c70 {
    int FUN_00059a40();
    void FUN_00059a50(V3_38c70* out);
};
struct Holder_38c70 {
    char pad00[0x34];
    float scale;
};
class Probe_38c70 {
public:
    char pad00[0x10];
    Anchor_38c70* anchor;
    char pad14[0x30];
    float min44;
    float min48;
    float min4c;
    char pad50[0xcc];
    Holder_38c70* holder;
    char pad120[0x20];
    int mode;
    char pad144[4];
    float margin;
    char pad14c[0x19ac];
    float offsetX;
    float offsetY;
    float offsetZ;

    char FUN_00038660(const V3_38c70* p, float h, int a0, int a1, int a2, int a3, int a4, int a5, const V3_38c70* q);
    bool FUN_00038c70(int a0, int a1, int a2, int a3, int a4, int a5);
};
extern unsigned char Work_002027c0(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                          unsigned int, unsigned int);
typedef unsigned char u8_38e30;
extern "C" u8_38e30 __cdecl FUN_002029e0(int, int, int, int, int, int);
struct Vec3_38e80 { float x,y,z; };
struct Entry_38e80 {
 float x,y,z;
 Vec3_38e80 first,second;
 float time;
 void FUN_00037780(float a,float b,float c,const Vec3_38e80* d,const Vec3_38e80* e,float f);
};
struct Actor_392e0;
struct Handler_392e0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual int slot8(Request*, int);
};
struct State_392e0 {
 char pad0[0xf8]; Handler_392e0* handler;
 char pad1[0x1a4-0xfc]; int contribution;
 char pad2[8]; int identity;
};
struct Link_392e0 { char pad[8]; Actor_392e0* actor; int type; };
struct Data_392e0 {
 char pad0[0x24]; unsigned char enabled;
 char pad1[0x4c-0x25]; Link_392e0* link;
 char pad2[4]; int limit;
};
struct Request {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual Data_392e0* slot3();
};
struct Actor_392e0 {
 char pad0[0x11c]; State_392e0* state;
 char pad1[0x318-0x120]; int count1; int count2;
 char pad2[0x1cef-0x320]; unsigned char flag;
 char pad3[0x2138-0x1cf0]; unsigned char blocked;
 hulk_intptr FUN_000392e0(Request* request);
};
struct Target_393c0;
struct Mgr_393c0 {
    char pad[0x20];
    int sub;
};
struct Obj_393c0 {
    char pad[0x20];
};
struct Link_393c0 {
    virtual void V0();
    virtual void Release();
    int pad;
    Target_393c0* mTarget;
    int mKind;
};
struct Target_393c0 {
    char pad0[0x328];
    Link_393c0* mLink;
    char pad1[0x1b48 - 0x32c];
    char mFlag;
};
struct Holder_393c0 {
    char pad[0x20];
};
struct Reg_393c0 {
    char pad[0x20];
    Holder_393c0* h;
};
struct Sys_393c0 {
    bool Check(Target_393c0* t);
};
extern Sys_393c0* g_sys;
extern const float kZero_393c0;
struct Dummy_393c0 {};
struct Sub_393c0 {
    bool Check(void* t);
};
struct Global_393c0 {
    char pad[0x20];
    Sub_393c0* sub;
};
extern Global_393c0* gGlobal_393c0;
struct T2 {
    char pad0[0x328];
    Link_393c0* mLink;
    char pad1[0x1b48 - 0x32c];
    char mFlag;
    void Fn();
};
struct Other_393c0 {
    char pad[0x1b0c];
    float val;
};
struct LinkB {
    virtual void V0();
    virtual void Release();
    int pad;
    Other_393c0* mTarget;
    int mKind;
};
struct Sub2_393c0 {
    bool Check_000242d0(void* t);
};
struct Glob2 {
    char pad[0x20];
    Sub2_393c0* sub;
};
extern Glob2* hulk_at_004dd700;
struct CCharacter_393c0 {
    char pad0[0x328];
    LinkB* mLink;
    char pad1[0x1b48 - 0x32c];
    char mFlag;
    void Fn();
};
struct Vec_3a440 { float x,y,z; hulk_freg FUN_0022d110(); };
struct Query_3a440 {
 bool FUN_00039440(Object*,Vec_3a440*,Object**,int);
 bool test(Vec_3a440* origin,Vec_3a440* direction,float angle,float distance,Object* object);
};
class CCharacter_3a520 {
    char pad[0x328];
    void* p;
    char pad2[0x1b48 - 0x32c];
    char flag;

  public:
    void* Fn(hulk_intptr a, hulk_intptr b, int c, int d);
    char Do_0003a440(int a, int b, int c, int d, void* p);
    void Fail_000393c0();
};
class A_3a570 {
  public:
    virtual void f();
    virtual void g();
};
class B_3a570 {
    char pad[0x128];
    A_3a570* p;

  public:
    void run();
};
struct Vec_3a590 {
    float x, y, z;
};
struct State_3a590 {
    char pad[0x14];
    int kind;
};
struct Flag_3a590 {
    char pad[0x72];
    unsigned char enabled;
};
struct Result_3a590 {
    char pad[0x74];
    Flag_3a590* flag;
};
struct Link_3a590 {
};
bool __cdecl FUN_002027c0(Vec_3a590*, Vec_3a590*, int, int, Vec_3a590*, Vec_3a590*, int, int);
struct Pose {
    int FUN_00221c40();
};
struct Transform_3a680 {
    void FUN_00221c60(int v);
};
class JointDriver_3a680 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[0x14];
    Transform_3a680 transform;
    char rest[0x70 - 0x18 - sizeof(Transform_3a680)];
    JointDriver_3a680 *FUN_002248f0(unsigned int id);
};
struct Scene_3a680 {
    char pad0[0x10];
    Pose pose;
    void FUN_00222970(JointDriver_3a680 *obj, int flag);
    void FUN_00222d70(JointDriver_3a680 *obj, float v);
    void FUN_00222890(JointDriver_3a680 *obj, float a, float b, float c, float d, float e, float f);
};
struct Matrix {
  public:
    float m[16];
    void FUN_0022b980();
};
struct SubObject_3a680 {
    void FUN_00232240();
};
Scene_3a680 *__fastcall FUN_00059a40(void *x);
void *__cdecl FUN_00263ea0(unsigned int size);
class Entity {
public:
    char pad00[0x10];
    void *owner;
    char pad14[0xb4 - 0x14];
    SubObject_3a680 sub;
    char padb5[0x338 - 0xb5];
    Entity *target;
    int id;
    int idB;
    int idC;
    Matrix matrix;
    JointDriver_3a680 *joint;
    int f38c;
    Entity *prevTarget;
    void FUN_00037000();
    char SetTarget(Entity *t, int a, int b, int c, const Matrix *m, float e5, float e6, float e7);
};
struct Event_3a830;
struct Slot_3a830 {
};
struct Weapon_3a830 {
    char pad0[0xfc];
    int mode;
    char pad100[0x114 - 0x100];
    int f114;
    char pad118[0x148 - 0x118];
    struct Owner_3a830 *owner;
    bool FUN_001d6980();
    void FUN_001d69f0(int a);
};
struct SlotEntry_3a830 {
    Slot_3a830 *slot;
    char pad[0x4c];
};
struct Event_3a830 {
    char pad0[8];
    Weapon_3a830 *weapon;
    int kind;
};
struct Owner_3a830 {
    char pad0[0x128];
    Slot_3a830 *slot128;
    Event_3a830 *ev12c;
    char pad130[0x1b0c - 0x130];
    float f1b0c;
    char pad1b10[0x20b0 - 0x1b10];
    int f20b0;
};
struct Fighter_3a830 {
    char pad0[0x128];
    Slot_3a830 *slot128;
    Event_3a830 *ev12c;
    char pad130[0x14c - 0x130];
    Event_3a830 *ev14c;
    char pad150[0x334 - 0x150];
    Fighter_3a830 *t334;
    Fighter_3a830 *t338;
    char pad33c[0x3a8 - 0x33c];
    SlotEntry_3a830 slots[8];
    bool FUN_0003a830(Event_3a830 *ev, hulk_intptr arg);
};
class Obj_3b160 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_3b160 {
    char pad[0x62c];
    Obj_3b160* p;

  public:
    bool F(Obj_3b160* x);
};
class Thing_3b190 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_3b190 {
  public:
    char pad[0x630];
    Thing_3b190* ptr;
    bool Set(Thing_3b190* p);
};
struct Scene_3b4f0;
struct Camera {
    hulk_freg FUN_002220d0();
};
struct Scene_3b4f0 {
    char pad00[0x10];
    Camera camera;          // 0x10
};
struct Owner_3b4f0 {
    Scene_3b4f0 *FUN_00059a40();
};
hulk_freg __cdecl FUN_00224f10(float v);
hulk_freg __cdecl FUN_00224fc0(float a, float b);
union FloatBits_3b4f0 {
    float f;
    unsigned int u;
};
class AimCheck {
public:
    char pad00[0x10];
    Owner_3b4f0 *owner;           // 0x10
    char pad14[0x1b5c - 0x14];
    float threshold;        // 0x1b5c
    char pad1b60[0x1b91 - 0x1b60];
    char active;            // 0x1b91
    bool FUN_0003b4f0(float angle);
};
class Ref_3b580 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_3b580 {
    char pad[0x1b58];
    int count;
    float value;
    Ref_3b580* ref;

  public:
    void Fn(char, float, Ref_3b580*);
};
extern char DAT_0048e090[];
extern char DAT_0048e0ac[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
struct V3_3b7d0 {
    float x, y, z;
    bool FUN_0022d2b0(const V3_3b7d0 *other, float eps);
};
class RefObj_3b7d0 {
public:
    virtual void AddRef();
    virtual void Release();
};
struct Handle_3b7d0;
class Link_3b7d0 {
public:
    void FUN_00231ad0(void *h, int v, int flag);
};
struct Handle_3b7d0 {
    RefObj_3b7d0 *obj;
    bool FUN_00231ee0();
};
struct Anim_3b7d0 {
    void FUN_002322f0(int a, float dt);
    void FUN_00231f20(int a);
    void FUN_002324b0(int a);
    void FUN_00232240();
    bool FUN_00231ee0();
};
class Finder_3b7d0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Link_3b7d0 *Make(int v, int flag);
};
class Listener_3b7d0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual void Update(int a, float dt);
};
class Host_3b7d0 {
public:
    char pad0[0xec];
    Finder_3b7d0 *finder;
    char padf0[0x11c - 0xf0];
    Finder_3b7d0 *activeFinder;
};
struct Prop_3b7d0 {
    char pad[0xfc];
    int state;
};
struct PropSlot {
    Prop_3b7d0 *prop;
    char pad[0x4c];
};
struct Pool_3b7d0 {
    void FUN_00060170();
};
class CCharacter_3b7d0 {
public:
    char pad0[0xb4];
    Anim_3b7d0 anim;  // 0xb4
    char padb5[0x27];
    Handle_3b7d0 current;  // 0xdc
    char pade0[0x24];
    int key;  // 0x104
    RefObj_3b7d0 *previous;  // 0x108
    RefObj_3b7d0 *previous2;  // 0x10c
    char pad110[0x8];
    bool dead;  // 0x118
    bool frozen;  // 0x119
    char pad11a[0x2];
    Host_3b7d0 *host;  // 0x11c
    char pad120[0x1f4];
    float timeScale;  // 0x314
    char pad318[0x20];
    int lock;  // 0x338
    char pad33c[0x6c];
    PropSlot slots[8];  // 0x3a8
    char pad628[0x1540];
    V3_3b7d0 dir;  // 0x1b68
    char pad1b74[0x12c];
    Listener_3b7d0 *listener;  // 0x1ca0
    char pad1ca4[0x2b4];
    Pool_3b7d0 pool;  // 0x1f58
    char pad1f59[0x11b];
    V3_3b7d0 savedDir;  // 0x2074
    char pad2080[0x18];
    int idLo;  // 0x2098
    int idHi;  // 0x209c
    bool hasId;  // 0x20a0
    char pad20a1[0x7];
    int phase;  // 0x20a8
    char pad20ac[0x1f0];
    bool flagA;  // 0x229c
    bool flagB;  // 0x229d
    char pad229e[0x2];
    int z0;  // 0x22a0
    int z1;  // 0x22a4
    int z2;  // 0x22a8
    int poolCount;  // 0x22ac
    void FUN_0003acf0(int slot, int a, int b, int c, int d, int e);
    void FUN_0003b7d0(int a, float dt);
};
struct V3_3d350 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    char FUN_0022d2b0(const V3_3d350 *other, float eps);
    char FUN_000375a0();
};
char __cdecl FUN_002027c0(V3_3d350 *from, V3_3d350 *to, int a, int b, V3_3d350 *hitPos, V3_3d350 *hitNormal, int c, int d);
class Fighter_3d350;
struct Mover_3d350 {
    void FUN_002226f0(V3_3d350 *v);
};
struct Slot74 {
    char pad00[0x72];
    char b72;
};
struct Rig12c {
    char pad00[0x74];
    Slot74 *f74;
};
struct Obj1d72_3d350 {
    char pad00[0x74];
    Slot74 *f74;
};
struct Obj128_3d350 {
};
struct Hold10 {
    Mover_3d350 *FUN_00059a40();
    void FUN_00059a50(V3_3d350 *out);
};
struct Gear_3d350 {
    char pad00[0x10];
    char b10;
    char pad11[0x30 - 0x11];
    float f30;
    float f34;
};
struct Ez {
    char pad00[0x18];
    int f18;
};
struct Ey {
    float f0;
    Ez *f4;
};
struct Ex {
    char pad00[8];
    Ey *f8;
};
struct Ee {
    char FUN_002ee140(Ex *e, V3_3d350 *a, V3_3d350 *b, int z);
};
struct Wld {
    char pad00[8];
    Ee *f8;
};
struct Holder20_3d350 {
    char pad00[0x124];
    Fighter_3d350 *f124;
};
struct Hit202 {
    char FUN_00202460(V3_3d350 *from, V3_3d350 *dir, float len, int c, V3_3d350 *o1, V3_3d350 *o2, int d, int e);
};
struct Arg1_3d350 {
    char pad00[0x10];
    Wld *f10;
    char pad14[0x20 - 0x14];
    Holder20_3d350 *f20;
    Hit202 *f24;
};
extern "C" Ex *__cdecl FUN_00202f00();
class Fighter_3d350 {
public:
    char pad00[0x10];
    Hold10 *f10;
    char pad14[0x44 - 0x14];
    V3_3d350 p44;
    char pad50[0x68 - 0x50];
    V3_3d350 r68;
    char pad74[0x11c - 0x74];
    Gear_3d350 *f11c;
    char pad120[0x128 - 0x120];
    Obj128_3d350 *f128;
    Rig12c *f12c;
    char pad130[0x140 - 0x130];
    int mode;
    int f144;
    char pad148[0x14c - 0x148];
    int f14c;
    char pad150[0x1c0 - 0x150];
    float f1c0;
    float f1c4;
    float f1c8;
    char pad1cc[0x334 - 0x1cc];
    Fighter_3d350 *f334;
    Fighter_3d350 *f338;
    char pad33c[0x1b20 - 0x33c];
    int f1b20;

    void FUN_00035fa0(int a);
    void FUN_00035550(V3_3d350 *out);
    void FUN_000350c0(V3_3d350 *out);
    void FUN_0003d1c0(int a, unsigned int b, V3_3d350 *c, V3_3d350 *d);
    Obj128_3d350 *FUN_dummy128();
    void Update(Arg1_3d350 *a1, float a2);
};
struct Receiver_3dc40 {
    void FUN_002226e0(unsigned int);
};
struct Source_3dc40 {
    Receiver_3dc40* FUN_00059a40();
};
struct Child_3dc40 {
};
struct Node {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual unsigned int slot15();
    char pad[0x118];
    Child_3dc40* child;
    void FUN_001d6b60(Matrix, unsigned int);
};
struct State_3dc40 {
    char pad[0x2c];
    unsigned int value;
};
struct CCharacter_3dc40 {
    char pad0[0x10];
    Source_3dc40* source;
    char pad1[0x108];
    State_3dc40* state;
    char pad2[8];
    Node* node;
    char pad3[0x1c];
    unsigned int cached;
    char pad4[0x2194];
    unsigned char flag;
    void FUN_0003ba60(unsigned int, unsigned int);
    void FUN_000365f0(unsigned int, unsigned int);
    void FUN_00035160(Matrix*);
    void FUN_0003dc40(unsigned int, unsigned int);
};
struct Sub_3dd00 {
    void FUN_00232240();
};
struct Mgr_3dd00 {
    void FUN_00222b90(bool flag);
};
struct Owner_3dd00 {
    char pad[0x18];
    Mgr_3dd00 *mgr;
    Mgr_3dd00 *FUN_00059a40();
};
struct CCharacter_3dd00 {
    char pad00[0x10];
    Owner_3dd00 *owner;
    char pad14[0xb4 - 0x14];
    Sub_3dd00 subB4;
    char padB5[0xdc - 0xb5];
    Sub_3dd00 subDC;
    char padDD[0x114 - 0xdd];
    int refs;
    char pad118[1];
    bool enabled;
    char pad11a[0x1b1c - 0x11a];
    int enableDepth;
    void FUN_000393c0();
    void FUN_0003dd00(bool enable);
};
extern "C" void *FUN_0008d690(unsigned int size);
struct V3_3dd70 {
    union {
        float x;
        int ix;
    };
    union {
        float y;
        int iy;
    };
    union {
        float z;
        int iz;
    };
    hulk_freg FUN_000111f0();
};
struct Mat_3dd70 {
    float m[16];
    void FUN_0022b980();
};
struct Id64_3dd70 {
    unsigned int lo;
    unsigned int hi;
};
class Releasable_3dd70 {
public:
    virtual void v0();
    virtual void v1();
};
struct Desc_3dd70 {
    char pad0[0x28];
    V3_3dd70 rel;
    char pad34[0x5c - 0x34];
    float f5c;
    char pad60[0x98 - 0x60];
    void FUN_00059820();
    void FUN_00059300();
};
struct CFightParamsCollision_3dd70 : public Releasable_3dd70 {
    CFightParamsCollision_3dd70 *FUN_000598e0(void *a, Desc_3dd70 *d);
};
struct ListHead_3dd70 {
    void *first;
    void FUN_00232240();
};
class Emitter_3dd70 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Emitter_3dd70 *v8(CFightParamsCollision_3dd70 *o, int z);
    bool FUN_00231a40(ListHead_3dd70 *h, CFightParamsCollision_3dd70 *o);
    void FUN_00231ad0(ListHead_3dd70 *h, CFightParamsCollision_3dd70 *o, unsigned int flags);
};
struct Singleton_3dd70 {
    void FUN_00283a40(const Id64_3dd70 *id, Mat_3dd70 *m, float a, float b);
};
Singleton_3dd70 *FUN_0027f250();
extern "C" float __cdecl FUN_000186b0(float *a, float *b, float *c);
extern "C" int __cdecl FUN_00266da0(hulk_intptr v);
struct Pool_3dd70 {
    int first;
    void FUN_00059a50(V3_3dd70 *out);
};
struct P11c {
    char pad0[0x1c];
    float f1c;
    char pad20[0x30 - 0x20];
    float f30;
    char pad34[0x104 - 0x34];
    Emitter_3dd70 *emit;
};
struct Cfg_3dd70 {
    char pad0[0x18];
    float lim;
    char pad1c[4];
    Id64_3dd70 id;
    char name[1];
};
class Finder_3dd70 {
public:
    char FUN_001fe380(V3_3dd70 *o, V3_3dd70 *out);
};
class Host_3dd70;
struct Notify_3dd70 {
    void FUN_001ebfd0(Host_3dd70 *h, const char *s);
};
struct Target20 {
    char pad0[0x124];
    Host_3dd70 *host;
};
struct Arg0 {
    char pad0[0x20];
    Target20 *p20;
    Cfg_3dd70 *cfg;
    Finder_3dd70 *finder;
    char pad2c[0x34 - 0x2c];
    Notify_3dd70 *notify;
};
class Host_3dd70 {
public:
    char pad0[0x10];
    Pool_3dd70 *p10;
    char pad14[0x48 - 0x14];
    float t48;
    char pad4c[0x74 - 0x4c];
    V3_3dd70 w74;
    char pad80[0xb4 - 0x80];
    ListHead_3dd70 l_b4;
    char padbc[0xdc - 0xb8];
    ListHead_3dd70 head;
    char pade4[0x11c - 0xe0];
    P11c *p11c;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x1a39 - 0x144];
    bool b1a39;
    char pad1a3a[2];
    V3_3dd70 home;
    char pad1a48[0x1a88 - 0x1a48];
    float f1a88;
    char pad1a8c[0x22ec - 0x1a8c];
    V3_3dd70 last;
    float t;
    void FUN_00037000();
    void FUN_0003dd70(Arg0 *a0, float dt);
};
struct Frame_3dd70 {
    float sc;       // S0
    float lim;      // S4
    V3_3dd70 v;           // S8
    float vy;       // S20
    V3_3dd70 d;           // S24
    float t48;      // S36
    union {         // S40
        float half;
        int saved;
    };
    V3_3dd70 out;         // S44
    float four;     // S56
    Mat_3dd70 mat;        // S60
    Desc_3dd70 desc;      // S124
};
struct Vec3_3e2a0 {
    float x, y, z;
};
struct Mat_3e2a0 {
    float m[12];
    Vec3_3e2a0 t;
    float w;
};
struct Anchor_3e2a0 {
    void FUN_00059a50(Vec3_3e2a0* out);
};
struct Target_3e2a0 {
};
struct MatSource_3e2a0 {
    char pad00[0x10];
    Target_3e2a0* target;
    Mat_3e2a0* FUN_001c5e60();
};
struct PosSource_3e2a0 {
    char pad00[0x11c];
    Target_3e2a0* target;
    Vec3_3e2a0* FUN_001d6b40();
    void FUN_001d7810(Vec3_3e2a0 v);
    void FUN_001d8fc0(float f);
};
struct MatList {
    char pad00[0xc];
    int count;
    char pad10[0x1c - 0x10];
    Mat_3e2a0* data;
};
class CCharacter_3e2a0 {
public:
    char pad00[0x10];
    Anchor_3e2a0* anchor;
    char pad14[0x120 - 0x14];
    MatList* mats;
    MatSource_3e2a0* matSource;
    PosSource_3e2a0* posSource;
    char pad12c[0x20b0 - 0x12c];
    int mode;
    void FUN_00035250(Vec3_3e2a0* v);
    void FUN_0003ba60(int a, float b);
    void FUN_000365f0(int a, float b);
    void FUN_0003e2a0(int a, Vec3_3e2a0 off, float scale, int unused, bool enable);
};
struct Vec3_3e780 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Elem64 {
    char pad0[0x30];
    Vec3_3e780 pos;
    char pad1[0x40 - 0x3c];
};
struct ElemArray_3e780 {
    char pad[0x1c];
    Elem64 *items;
};
struct FlagHolder {
    char pad[0x72];
    char flag;
};
struct Slot_3e780 {
    char pad[0x74];
    FlagHolder *holder;
};
struct Locator_3e780 {
    void FUN_00222120(Vec3_3e780 *out);
};
struct Anchor_3e780 {
    char pad[0x10];
    Locator_3e780 loc;
};
struct AnchorOwner {
    Anchor_3e780 *FUN_00059a40();
};
struct CCharacter_3e780 {
    unsigned __int64 FUN_000443c0();
};
struct Gesture {
    char pad[8];
    unsigned __int64 id;
};
struct Probe_3e780 {
};
struct Actor_3e780 {
    char pad0[0x10];
    AnchorOwner *owner;
    char pad1[0xdc - 0x14];
    Gesture *gesture;
    char pad2[0x11c - 0xe0];
    CCharacter *hasher;
    ElemArray_3e780 *elems;
    char pad3[0x128 - 0x124];
    Probe_3e780 *probe;
    Slot_3e780 *slot;
    char pad4[0x1cc8 - 0x130];
    float angle;
    char pad5[0x1f54 - 0x1ccc];
    unsigned index;

    void FUN_00035fa0(int mode);
    bool FUN_0003e780(void *a1, Vec3_3e780 *target, float maxDist, bool *outA, bool *outB);
};
extern "C" bool __cdecl FUN_00036b10(void *a1, Vec3_3e780 *p, Vec3_3e780 *target, Vec3_3e780 *z, Vec3_3e780 *tmp, bool *outA, float *ang);
struct Frame_3e780 {
    float dot;
    float dist;
    Vec3_3e780 D;
    Vec3_3e780 P;
    Vec3_3e780 W;
    Vec3_3e780 tmp;
    Vec3_3e780 Z;
};
struct Part {
    char pad[8];
    char a;
    char b;
    void Copy_0027af70(const Part*);
};
class CCharacter_3ec70 {
    char pad[0x22b8];
    Part part;

  public:
    void Set(const Part* p);
};
struct Key_3eca0 {
    int lo;
    int hi;
    void FUN_0027af00();
};
struct Entry_3eca0 {
    int lo;
    int hi;
    float value;
    int pad;
};
extern "C" void __cdecl FUN_00363ba0();
} // namespace fn_f35f7bdf
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl atexit(void (__cdecl *fn)());
#endif
namespace fn_f35f7bdf {
class Table_3eca0 {
public:
    char pad00[0x1ba8];
    Entry_3eca0 entries[14];
    int count;

    float FUN_0003eca0(const char *name);
};
class Thing_3ee50 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_3ee50 {
  public:
    char pad[0x22b4];
    Thing_3ee50* item;
    void f();
};
class Item_3ee70 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_3ee70 {
  public:
    char pad[0x22b4];
    Item_3ee70* item;
    void Set(Item_3ee70*);
};
extern "C" char DAT_003f5d3c[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
class Owner_3eea0 {};
typedef void (Owner_3eea0::*Fn_3eea0)();
class Function7_3eea0 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_3eea0 func;
    Function7_3eea0* Init(const char* name, Fn_3eea0 fn);
};
struct Function_3ef30 {
    virtual void f0();
    virtual void f1();
};
void FUN_0003ef50(const char*, const char*, const char*, int);
typedef unsigned int DWORD;
typedef void (__cdecl *Callback)(DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD);
extern "C" char DAT_003f5d4c[];
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
class Owner_3efb0 {};
typedef void (Owner_3efb0::*Fn_3efb0)();
class Function3_3efb0 : public FUN_001d0480 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_3efb0 m1c;
    Function3_3efb0(const char*, Fn_3efb0);
};
class Ref_3ffa0 {
  public:
    virtual void Use();
    virtual void Release();
};
class Thing_3ffa0 {
  public:
    char pad[0x328];
    Ref_3ffa0* member;
    char pad2[0x1b48 - 0x32c];
    unsigned char state;
    void Set(Ref_3ffa0*, unsigned char);
};
struct CCharacter_nv_3ffa0 {
    void Missing_000393c0();
};
struct Vector { float x,y,z; };
struct Parent_3ffe0 { char pad[0x12c]; int value; };
struct Object {
  public:
    char _m_pad_0[0x11c];
    State_3a590* state;
    char _m_pad_120[0x8];
    Link_3a590* link;
    char _m_pad_12c[0xa0];
    Vec3_38410 position;
    Vec3_38410 velocity;
    char _m_pad_1e4[0x144];
    int current;
    unsigned char disabled;
    char _m_pad_32d[0x7];
    Parent_3ffe0* parent;
    Object* next;
    char _m_pad_33c[0x2f8];
    int count;
    Entry_38e80 entries[128];
    void FUN_00038410(const Vec3_38410* delta, const Vec3_38410* added);
    void target(float a,float b,float c,const Vec3_38e80* d,const Vec3_38e80* e,float f);
    bool FUN_000352b0(Vec_3a590*);
    void FUN_00035fa0(int);
    bool target(int unused, Object* other);
    void FUN_000350c0(Vector*);
    void FUN_00035dc0(int);
    bool FUN_0003a440(Vector*,int,int,int,int);
    int FUN_00039c60(Vector*,int,int,int,int,int,int);
    int target(int a,int b,unsigned char allow,int fallback,int mode);
};
class Item_400e0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_400e0 {
  public:
    char pad0[0x328];
    Item_400e0* current;
    char pad1[0x1b48 - 0x32c];
    char flag;
    Item_400e0* Helper_00039c60(int, int, int, int, int, int, int);
    Item_400e0* Build(hulk_intptr, hulk_intptr, int, int, int);
};
struct CCharacter_nv_40140 {
    void callee_0003acf0(int, int, int, int, int, int);
};
struct CCharacter_nv_40170 {
    bool Fnf_0003aef0(int);
};
static inline float Stored_40dc0(const float &v)
{
    return *(const volatile float *)&v;
}
struct V3_40dc0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    char FUN_0022d2b0(const V3_40dc0 *other, float eps);
};
struct Mat4_40dc0 {
    float m[12];
    V3_40dc0 trans;
    float w;
};
struct Xform_40dc0 {
    Mat4_40dc0 mat;
    float q[4];
    int type;
    void FUN_00221b70(const Mat4_40dc0 *m);
    void FUN_00221be0(const Xform_40dc0 *other);
    void FUN_00221c60(const Mat4_40dc0 *m);
    Mat4_40dc0 *FUN_00221c40();
    void FUN_00222120(V3_40dc0 *out);
    hulk_freg FUN_002220d0();
};
struct Bones_40dc0 {
    char pad0[0x1c];
    char *mats;
};
struct Scene_40dc0 {
    char pad0[0x10];
    Xform_40dc0 xf;
    Bones_40dc0 *bones;
    void FUN_00224260(unsigned int lo, unsigned int hi, Xform_40dc0 *x);
    void FUN_00222f40(float dt);
    void FUN_00223fa0();
    void FUN_00223060();
    void FUN_002226e0(const Mat4_40dc0 *m);
    void FUN_002226f0(const V3_40dc0 *v);
    void FUN_00222710(const V3_40dc0 *v);
    float FUN_00222da0(void *key);
};
struct Holder10_40dc0 {
    Scene_40dc0 *FUN_00059a40();
};
struct Prop_40dc0 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Mat4_40dc0 *v15();
};
struct Releasable_40dc0 {
    virtual void v0();
    virtual void v1();
};
struct Cfg_40dc0 {
    char pad0[0x30];
    float f30;
    float f34;
};
struct Obj338 {
    char pad0[0x10];
    Holder10_40dc0 *holder;
};
struct Obj388 {
    char pad0[0x18];
    Xform_40dc0 xf;
};
struct CCharacter_40dc0;
struct Sink_40dc0 {
    void FUN_00099d00(struct Args_40dc0 *a, CCharacter_40dc0 *f, int z);
};
struct Args_40dc0 {
    char pad0[8];
    Sink_40dc0 *f8;
};
struct Frame_40dc0 {
    float ang0;     // 0x00
    float inv;      // 0x04
    V3_40dc0 vA;          // 0x08
    V3_40dc0 vB;          // 0x14
    V3_40dc0 vC;          // 0x20
    V3_40dc0 vD;          // 0x2c
    V3_40dc0 P0;          // 0x38
    float S0;       // 0x44
    Mat4_40dc0 M58;       // 0x48
    Mat4_40dc0 M98;       // 0x88
    V3_40dc0 od8, oe4, of0, ofc;
    Xform_40dc0 x;        // 0xf8
    Mat4_40dc0 M15c;      // 0x14c
    Mat4_40dc0 M19c;      // 0x18c
};
class CCharacter_40dc0 {
public:
    char pad0[0x10];
    Holder10_40dc0 *holder;
    Xform_40dc0 x14;
    V3_40dc0 v68;
    V3_40dc0 v74;
    V3_40dc0 v80;
    float f8c;
    char pad90[0x110 - 0x90];
    float f110;
    int i114;
    char pad118;
    char b119;
    char pad11a[2];
    Cfg_40dc0 *cfg;
    char pad120[0x128 - 0x120];
    Prop_40dc0 *p128;
    char pad12c[0x13c - 0x12c];
    int i13c;
    int mode;
    char pad144[0x14c - 0x144];
    char *p14c;
    Mat4_40dc0 m150;
    V3_40dc0 v190;
    V3_40dc0 v19c;
    V3_40dc0 v1a8;
    V3_40dc0 v1b4;
    V3_40dc0 v1c0;
    char pad1cc[0x1e4 - 0x1cc];
    float f1e4;
    V3_40dc0 v1e8;
    float f1f4;
    float f1f8;
    int i1fc;
    char pad200[0x338 - 0x200];
    Obj338 *p338;
    unsigned int u33c;
    unsigned int lo340;
    unsigned int hi344;
    Mat4_40dc0 m348;
    Obj388 *p388;
    char pad38c[4];
    int i390;
    char pad394[0x3a4 - 0x394];
    Releasable_40dc0 *p3a4;
    char pad3a8[0x1b20 - 0x3a8];
    int i1b20;
    char pad1b24[0x22e0 - 0x1b24];
    char b22e0;
    char FUN_00035550(V3_40dc0 *out);
    void FUN_00036480(Args_40dc0 *a, float dt);
    void FUN_000365f0(Args_40dc0 *a, float dt);
    void FUN_00038c40();
    void FUN_0003ba60(Args_40dc0 *a, float dt);
    void FUN_0003be00();
    void FUN_00040dc0(Args_40dc0 *a1, float a2);
};
struct Vec3_42680 {
    float x, y, z;
    void Sub(const Vec3_42680 &b) { x = x - b.x; y = y - b.y; z = z - b.z; }
    void Scale(float s) { x = s * x; y = s * y; z = s * z; }
};
struct Xform_42680 {
    hulk_freg FUN_002220d0();
};
struct Tracker_42680 {
    char pad00[0x10];
    Xform_42680 xf;
    void FUN_002226e0(int v);
    void FUN_00223060();
};
struct Mgr_42680 {
    Tracker_42680* FUN_00059a40();
    bool FUN_00059a50(Vec3_42680* out);
};
class Releasable_42680 {
public:
    virtual void v0();
    virtual void Release();
};
class Provider_42680 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int GetHandle();
};
struct Source_42680 {
    char pad00[0x10];
    Matrix matrix;
};
struct Slot_42680 {
    Releasable_42680* first;
    Releasable_42680* second;
    char pad08[0x28 - 8];
};
class Mover_42680 {
public:
    char pad00[0x10];
    Mgr_42680* mgr;
    Xform_42680 xf14;
    char pad15[0x44 - 0x15];
    Vec3_42680 prevPos;
    char pad50[0x74 - 0x50];
    Vec3_42680 vel;
    char pad80[0x8c - 0x80];
    float angVel;
    char pad90[0x119 - 0x90];
    char disabled;
    char pad11a[0x128 - 0x11a];
    Provider_42680* provider;
    char pad12c[0x14c - 0x12c];
    Source_42680* source;
    Matrix matrix;
    char pad190[0x634 - 0x190];
    int slotCount;
    Slot_42680 slots[183];
    char pad22d0[0x10];
    char flag22e0;

    void FUN_0003c1d0(float a, float dt);
    void FUN_0003d350(float a, float dt);
    void FUN_000418f0(float a, float dt);
    void FUN_00036480(float a, float dt);
    void FUN_0003dd70(float a, float dt);

    void FUN_00042680(float a, float dt);
};
class Check_42890 {
  public:
    int Ready_00059a40();
};
class Inner_42890 {
  public:
    void Init_00231f20(int);
    char pad[0x4c];
};
class Res_42890 {
  public:
    void Scale_001d8fc0(float);
};
class CCharacter_42890 {
  public:
    char p0[0x10];
    Check_42890* thing;
    char p14[0xc8];
    Inner_42890 inner;
    Res_42890* res;
    void Finish_00040dc0(int, float);
    void Do(int, float);
};
class Context {
  public:
    int Check_00059a40();
};
class CCharacter_428e0 {
  public:
    char pad0[0x10];
    Context* mContext;
    char pad14[0x334 - 0x14];
    CCharacter_428e0* mNext;
    void UpdateA(int, int);
    void UpdateB_00042680(int, int);
    void UpdateC_0003dc40(int, int);
    void UpdateNext_00042890(int, int);
};
struct CCharacter_nv_42930 {
    void helper_00042890(int, float);
};
struct CCharacter_nv_42960 {
    void helper_000428e0(int, float);
};
} // namespace fn_f35f7bdf
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f35f7bdf {
class Registry_42ad0 { public:
    void FUN_00042ad0(const char* a1, Owner* a2);
};
class Function3_42ad0 { public: void* FUN_0003efb0(const char*, Owner*); };
} // namespace fn_f35f7bdf
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif
namespace fn_f35f7bdf {
extern "C" void FUN_00363b90();
struct Vec3_437a0 {
    float x, y, z;
};
struct Key_437a0 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
};
struct CFightParamsCollision_nv_437a0 {
    CFightParamsCollision* FUN_000598e0(int first, void* params);
};
struct Target2 {
    char pad00[0x1d20];
    float f1d20;
};
struct Target_437a0 {
    char pad00[8];
    Target2* f08;
    int f0c;
};
struct Params_437a0 {
    char pad00[0x24];
    char b24;
    char pad25[3];
    Vec3_437a0 vec28;
    char pad34[0x44 - 0x34];
    char b44;
    char pad45[3];
    int f48;
    Target_437a0* f4c;
    char pad50[4];
    int f54;
    char pad58[0x80 - 0x58];
    int f80;
    char pad84[0x90 - 0x84];
    char b90;
    unsigned char b91;
};
struct Actor_437a0 {
    void FUN_00231ad0(Vec3_437a0* where, CFightParamsCollision* ev, int t);
    char FUN_00231a40(Vec3_437a0* where, CFightParamsCollision* ev);
    char FUN_001d6ec0(int a, Target_437a0* t, int c);
};
class Holder110 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Actor_437a0* v8(CFightParamsCollision* ev, int z);
};
struct CCharacter_437a0 {
    char pad00[0x110];
    Holder110* f110;
    char pad114[0x1a4 - 0x114];
    int f1a4;
    unsigned __int64 FUN_000443c0();
};
struct Sub2_437a0 {
    hulk_freg FUN_002220d0();
};
struct Anchor2 {
    char pad00[0x10];
    Sub2_437a0 sub;
};
struct Owner_437a0 {
    int first;
    Anchor2* FUN_00059a40();
};
struct Sub_437a0 {
    void FUN_00232240();
};
struct Entry_437a0 {
    Actor_437a0* a;
    char pad[76];
};
extern "C" hulk_freg __cdecl FUN_00224f10(Vec3_437a0* v);
class Unit_437a0 {
public:
    char pad00[0x10];
    Owner_437a0* f10;
    char pad14[0xb4 - 0x14];
    Sub_437a0 subB4;
    char padB5[0xdc - 0xb5];
    Vec3_437a0 fdc;
    char pade8[0x11c - 0xe8];
    CCharacter_437a0* f11c;
    char pad120[0x318 - 0x120];
    int f318;
    int f31c;
    float f320;
    char pad324[0x3a8 - 0x324];
    Entry_437a0 entries[8];
    float f628;
    char pad62c[0x1d28 - 0x62c];
    char b1d28;
    int FUN_00035fe0();
    char FUN_00043350(float dt, Target_437a0* t, int a, int b, int c, int d);
    Actor_437a0* FUN_000392e0(CFightParamsCollision* ev);
    void FUN_00037000();
    char FUN_000437a0(float dt, Params_437a0* p, Vec3_437a0* where, Actor_437a0* actor, char flag5);
};
union FloatBits_437a0 {
    float f;
    unsigned int u;
};
class Obj_43fa0 {
  public:
    char pad[0x33c];
    int value;
    void Set(int x);
};
class Obj_44000 {
  public:
    char pad[0x360];
    int value;
    void Fn(int x);
};
class Obj_44030 {
  public:
    char pad[0x36c];
    int m36c;
    void Set(int value);
};
class Target_44090 {
  public:
    char pad[0x37e];
    char value;
    void SetValue(char v);
};
class C_44190 {
  public:
    char pad[0x1cb0];
    int m;
    void Set(int v);
};
struct Obj_44360 {
    char pad[0x3b0];
};
struct A_443b0 {
    char pad[0x3f0];
};
class CCharacter_443c0 {
  public:
    char pad[0x3f0];
    char field;
    unsigned __int64 Fn();
};
struct Obj_44400 {
    char pad[0x430];
};
class Result_44410 {
  public:
    char pad[8];
    int value;
};
class Inner_44410 {
  public:
    virtual Result_44410* f0();
    virtual Result_44410* f1();
    virtual Result_44410* f2();
    virtual Result_44410* f3();
    virtual Result_44410* f4();
    virtual Result_44410* f5();
    virtual Result_44410* f6();
    virtual Result_44410* f7();
    virtual Result_44410* f8();
    virtual Result_44410* f9();
    virtual Result_44410* f10();
    virtual Result_44410* f11();
};
class Source_44410 {
  public:
    char pad[8];
    Inner_44410* item;
    hulk_intptr FUN_00044410();
};
class A_44510 {
  public:
    char pad0[8];
    A_44510* next;
    int kind;
};
class D {
  public:
    char pad0[0x14];
    int value;
};
struct Result {
    char pad[0x14];
    int value;
};
struct Inner {
    char pad[0x11c];
    Result* result;
};
struct CCharacter_44560 {
    char pad[0x148];
    Inner* inner;
};
struct Param {
    char pad[8];
    CCharacter_44560* node;
    int type;
};
struct Vec {
    float x, y, z;
    Vec() : x(0.0f), y(0.0f), z(0.0f) {}
};
class CCharacter_44650 {
    char pad[0xa4];
    Vec elems[1];

  public:
    Vec* Get(int n);
};
struct Entry_446e0 {
    unsigned __int64 value;
    char pad[0x20];
};
class Thing_446e0 {
  public:
    char pad[0x1c0];
    Entry_446e0 values[8];
    unsigned __int64 Get(int index);
};
struct Id64_44820 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af70(const Id64_44820 *src);
};
union FloatBits_44820 {
    float f;
    int i;
};
union Slot_44820 {
    float f;
    int i;
};
struct Entry_44820 {
    Id64_44820 id;                // 0x0
    Slot_44820 value;             // 0x8
    int pad0c;
};
class ValueTable {
public:
    char pad000[0x480];
    Entry_44820 entries[14];      // 0x480
    int count;              // 0x560
    void FUN_00044820(const Id64_44820 *key, FloatBits_44820 value);
};


// 0x00038410 FUN_00038410 (203 B): equivalent/0x00038410.cpp
// sym: ?FUN_00038410@Object@fn_f35f7bdf@@QAEXPBUVec3_38410@2@0@Z @7933898eccd4 @w01ec2d981e41
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00038410 @ 0x00038410
void Object::FUN_00038410(const Vec3_38410* delta, const Vec3_38410* added) {
 double length = sqrt((double)added->x*added->x + (double)added->y*added->y + (double)added->z*added->z);
 if (length <= 0.0f) return;
 double oldLength = sqrt((double)velocity.x*velocity.x + (double)velocity.y*velocity.y + (double)velocity.z*velocity.z);
 double fraction = length / (oldLength + length);
 position.x = (float)(fraction * delta->x + position.x);
 position.y = (float)(fraction * delta->y + position.y);
 position.z = (float)(fraction * delta->z + position.z);
 velocity.x += added->x;
 velocity.y += added->y;
 velocity.z += added->z;
}


// 0x000384e0 FUN_000384e0 (111 B): matches/0x000384e0.cpp
// sym: ?FUN_000384e0@Controller_384e0@fn_f35f7bdf@@QAEXPBD@Z
// FUN_000384e0 @ 0x000384e0
void Controller_384e0::FUN_000384e0(const char *name)
{
    for (int i = 0; i < 8; i++) {
        if (_stricmp(name, ((const char**)&DAT_0048f590)[i]) == 0 && current != i) {
            Channel *ch = DAT_004dd700->channel;
            if (ch != 0) {
                Event_384e0 ev;
                ev.FUN_001ca210(current, i, owner->id);
                ch->FUN_001cbc20(&ev);
            }
            current = i;
        }
    }
}

} // namespace fn_f35f7bdf

// 0x000385a0 FUN_000385a0 (187 B): equivalent/0x000385a0.cpp [wrapped: conflict: World]
// sym: ?FUN_000385a0@Entity@fn_000385a0@@QAEXPAUHandle_385a0@2@_N@Z @da33a40749cb @waa308bf5f780
namespace fn_000385a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// FUN_000385a0 @ 0x000385a0
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

struct Handle_385a0;
struct Entity;
struct Resolver_385a0 {  };
struct Manager_385a0 { bool FUN_000242d0(void* object); };
struct World { char pad[0x20]; Manager_385a0* manager; };
struct Handle_385a0 {
 virtual void retain();
 virtual void release();
 unsigned int reserved;
 void* object;
 unsigned int kind;
};
void __cdecl FUN_00018810(Handle_385a0** destination, Handle_385a0* source);
struct Entity {
 char pad[0x22e4];
 Handle_385a0* handle;
 void FUN_000385a0(Handle_385a0* replacement, bool force);
};
void Entity::FUN_000385a0(Handle_385a0* replacement, bool force) {
 if (!force && handle && handle->kind == 1) {
  if (DAT_004dd700->manager->FUN_000242d0(handle->object)) return;
 }
 if (replacement) replacement->retain();
 if (handle) handle->release();
 handle = replacement;
 if (!replacement) return;
 if (replacement->kind == 5) {
  Resolver_385a0* resolver = static_cast<Resolver_385a0*>(replacement->object);
  if (((Handle_385a0 *)((owners::C_1d6490 *)resolver)->FUN_001d6490())) {
   Handle_385a0* resolved = ((Handle_385a0 *)((owners::C_1d6490 *)resolver)->FUN_001d6490());
   FUN_00018810(&handle, resolved);
  }
 } else if (replacement->kind == 1) {
  Entity* entity = static_cast<Entity*>(replacement->object);
  if (!DAT_004dd700->manager->FUN_000242d0(entity)) {
   Handle_385a0* resolved = entity->handle;
   if (resolved) FUN_00018810(&handle, resolved);
  }
 }
}
} // namespace fn_000385a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00038660 FUN_00038660 (1495 B): equivalent/0x00038660.cpp [wrapped: conflict: World]
// sym: ?F@Mover_38660@fn_00038660@@QAEDPAUV3_38660@2@H000PAHHPAD0@Z @6901f10ed96f @wb82245e32b24
namespace fn_00038660 {
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 77/92, incomplete)
// FUN_00038660 @ 0x00038660
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

struct V3_38660 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Rng_38660 {
};
extern "C" Rng_38660* FUN_000964d0();

struct Rc {
    char pad0[0xc];
    int f0c;
};

struct Sub74_38660 {
    char pad0[0x72];
    char b72;
};
struct Sub_38660 {
    char pad0[0x74];
    Sub74_38660* p74;
};
struct Link_38660 {
    char pad0[0x74];
    Sub74_38660* p74;
};
struct Ent_38660 {
};

struct Player_38660 {
    char pad0[0x124];
    void* f124;
};
struct World {
    char pad0[0x20];
    Player_38660* p20;
};

struct Slot_38660 {
    float x0, y0, z0;
    float x1, y1, z1;
    float x2, y2, z2;
    float x3, y3, z3;
    Rc* ptr;
    char flag;
    char pad35[3];
};

struct Opts_38660 {
    float a;
    int flag;
    float c;
};

void FUN_000187d0(Rc** slot);
void FUN_00018810(Rc** slot, int z);
extern "C" char FUN_00018960(float a, float b, float eps);
void FUN_00224d70(float angle, V3_38660* v);
hulk_freg FUN_00224f10(V3_38660* v);
extern "C" char FUN_00202560(V3_38660* from, int a2, int flag, V3_38660* a3, V3_38660* a4, V3_38660* o38, V3_38660* o48,
                  Opts_38660* opts);
extern "C" int __cdecl FUN_0034483c();

class Mover_38660 {
  public:
    char pad0[0x128];
    Ent_38660* p128;
    Link_38660* p12c;
    char pad130[0x334 - 0x130];
    void* f334;
    void* f338;
    char pad33c[0x1ea8 - 0x33c];
    Slot_38660 slots[3];
    void FUN_00035fa0(int z);
    char F(V3_38660* a1, int a2, V3_38660* a3, V3_38660* a4, V3_38660* a5, int* a6, int idx, char* a8,
           V3_38660* a9);
};

char Mover_38660::F(V3_38660* a1, int a2, V3_38660* a3, V3_38660* a4, V3_38660* a5, int* a6, int idx,
                    char* a8, V3_38660* a9) {
    struct Frame {
        Opts_38660 opts;
        V3_38660 D;
        V3_38660 Fp;
        V3_38660 o38;
        int pad44;
        V3_38660 o48;
    } fr;
    char result;
    char isPlayer;
    char* flagOut;

    World* w0 = DAT_004dd700;
    if (p12c) {
        Sub74_38660* x = p12c->p74;
        if (x)
            x->b72 = 0;
    }
    if (p128) {
        Sub_38660* r = ((Sub_38660 *)((owners::C_1d72e0 *)p128)->FUN_001d72e0());
        if (r) {
            Sub74_38660* y = r->p74;
            if (y)
                y->b72 = 0;
        }
    }
    FUN_00035fa0(0);
    if (idx >= 0 && idx < 3) {
        Slot_38660* s = &slots[idx];
        if (s->flag != 0) {
            Rc* rc = s->ptr;
            if (rc != 0 && rc->f0c == 0) {
                s->flag = 0;
                FUN_000187d0(&s->ptr);
            }
        }
    }
    flagOut = a8;
    if (flagOut)
        *flagOut = 0;
    isPlayer = w0->p20->f124 == (void*)this;
    result = 1;
    float tol1 = 0.4f, tol0 = 0.4f, tol2 = 0.4f;
    if (isPlayer) {
        tol1 = 0.01f;
        tol0 = 0.01f;
        tol2 = 0.01f;
    }
    fr.opts.c = tol2;
    // A cached result for this slot is reused when the query point has barely moved.
    bool cacheHit = false;
    if (idx >= 0 && idx < 3 && slots[idx].flag) {
        Slot_38660* s = &slots[idx];
        union {
            float f;
            unsigned int u;
        } t;
        t.f = a1->x - s->x0;
        t.u &= 0x7fffffff;
        if (t.f < tol1) {
            t.f = a1->y - s->y0;
            t.u &= 0x7fffffff;
            if (t.f < tol0) {
                t.f = a1->z - s->z0;
                t.u &= 0x7fffffff;
                if (t.f < tol2) {
                    a3->x = a1->x;
                    a3->y = a1->y;
                    a3->z = a1->z;
                    a3->y = s->y1;
                    a4->x = s->x2;
                    a4->y = s->y2;
                    a4->z = s->z2;
                    if (a5) {
                        a5->x = a1->x;
                        a5->y = a1->y;
                        a5->z = a1->z;
                        a5->y = s->y3;
                    }
                    if (a6)
                        *a6 = (hulk_intptr)slots[idx].ptr;
                    if (flagOut)
                        *flagOut = 1;
                    cacheHit = true;
                }
            }
        }
    }
    if (!cacheHit) {
        int notOwner = 0;
        void* pl = DAT_004dd700->p20->f124;
        if ((void*)this != pl && f338 != pl && f334 != pl)
            notOwner = 1;
        fr.opts.flag = notOwner;
        fr.o48.x = 0;
        fr.opts.a = 0;
        result = FUN_00202560(a1, a2, notOwner, a3, a4, &fr.o38, &fr.o48, &fr.opts);
        if (!result) {
            if (isPlayer && fr.opts.a == 0 && a9) {
                fr.Fp.x = a9->x;
                fr.Fp.y = a1->y;
                fr.Fp.z = a9->z;
                fr.D.x = a9->x - a1->x;
                fr.D.y = a1->y - a1->y;
                fr.D.z = a9->z - a1->z;
                float len = fr.D.FUN_0022d110();
                if (FUN_00018960(len, 0.0f, 1.0e-5f)) {
                    int r = ((owners::Random_11380 *)(FUN_000964d0()))->FUN_00011380(0, 0xb);
                    unsigned int u = r;
                    float ang = (float)(((double)u + 0.5f) * 60.0f * 0.017453292f);
                    fr.D.x = 0;
                    fr.D.y = 0;
                    fr.D.z = -0.05f;
                    FUN_00224d70(ang, &fr.D);
                } else {
                    float a = (FUN_00224f10(&fr.D) * 57.295776f) * 0.016666668f;
                    int t = (int)a;
                    float frac = a - (float)t;
                    if (frac > 0.5f)
                        frac = frac - 1.0f;
                    if (FUN_00018960(frac, 0.0f, 0.25f))
                        FUN_00224d70(0.5235988f, &fr.D);
                    fr.D.x = fr.D.x * 0.05f;
                    fr.D.y = fr.D.y * 0.05f;
                    fr.D.z = fr.D.z * 0.05f;
                }
                fr.Fp.x = a1->x + fr.D.x;
                fr.Fp.y = fr.D.y + a1->y;
                fr.Fp.z = a1->z + fr.D.z;
                result = FUN_00202560(&fr.Fp, a2, fr.opts.flag, a3, a4, &fr.o38, &fr.o48, &fr.opts);
                if (result) {
                    a3->x = a1->x;
                    a3->z = a1->z;
                    fr.o38.x = a1->x;
                    fr.o38.z = a1->z;
                }
            }
            if (!result && idx >= 0 && idx < 3)
                slots[idx].flag = 0;
        }
        if (result) {
            if (*(int*)&fr.o48.x == 0 && idx >= 0 && idx < 3) {
                Slot_38660* s = &slots[idx];
                s->flag = 1;
                s->x0 = a1->x;
                s->y0 = a1->y;
                s->z0 = a1->z;
                s->x1 = a3->x;
                s->y1 = a3->y;
                s->z1 = a3->z;
                s->x2 = a4->x;
                s->y2 = a4->y;
                s->z2 = a4->z;
                s->x3 = fr.o38.x;
                s->y3 = fr.o38.y;
                s->z3 = fr.o38.z;
                FUN_00018810(&slots[idx].ptr, 0);
            }
            if (a5) {
                a5->x = fr.o38.x;
                a5->y = fr.o38.y;
                a5->z = fr.o38.z;
            }
            if (a6)
                *a6 = *(int*)&fr.o48.x;
        }
    }
    FUN_00035fa0(1);
    if (p12c) {
        Sub74_38660* x = p12c->p74;
        if (x)
            x->b72 = 1;
    }
    if (p128) {
        Sub_38660* r = ((Sub_38660 *)((owners::C_1d72e0 *)p128)->FUN_001d72e0());
        if (r) {
            Sub74_38660* y = r->p74;
            if (y)
                y->b72 = 1;
        }
    }
    return result;
}
} // namespace fn_00038660
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35f7bdf {

// 0x00038c40 FUN_00038c40 (46 B): matches/0x00038c40.cpp
// sym: ?Clear@Owner_38c40@fn_f35f7bdf@@QAEXXZ
void Owner_38c40::Clear() {
    Entry_38c40* q = entries;
    int n = 3;
    do {
        q->flag = 0;
        Item_38c40* x = q->p;
        if (x) {
            x->Release();
            q->p = 0;
        }
        ++q;
    } while (--n);
}


// 0x00038c70 FUN_00038c70 (359 B): equivalent/0x00038c70.cpp
// sym: ?FUN_00038c70@Probe_38c70@fn_f35f7bdf@@QAE_NHHHHHH@Z @87266c446fe6 @wab2dc0ab7acf
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 14/14)
// FUN_00038c70 @ 0x00038c70
bool Probe_38c70::FUN_00038c70(int a0, int a1, int a2, int a3, int a4, int a5)
{
    if (holder == 0)
        return false;

    hulk_freg m = margin;
    if (!anchor->FUN_00059a40())
        return false;

    V3_38c70 base;
    base.x = 0.0f;
    base.y = 0.0f;
    base.z = 0.0f;
    anchor->FUN_00059a50(&base);

    V3_38c70 lo;
    lo.x = min44;
    lo.y = min48;
    lo.z = min4c;

    V3_38c70 p;
    p.x = base.x;
    p.y = base.y;
    p.z = base.z;
    if (lo.y > base.y)
        p.y = lo.y;

    if (mode == 1)
        p.y = p.y + m;
    else
        p.y = m * 0.25f + p.y;

    if (mode == 4) {
        hulk_freg s = holder->scale;
        p.x = s * offsetX + p.x;
        p.y = s * offsetY + p.y;
        p.z = s * offsetZ + p.z;
    }

    hulk_freg d = p.y - base.y;
    if (!(d >= 0.0f) && d == d)
        d = 0.0f;

    hulk_freg h = (m + m + d) + 35.0f;
    return FUN_00038660(&p, h, a0, a1, a2, a3, a4, a5, &lo) != 0;
}

} // namespace fn_f35f7bdf

// 0x00038de0 FUN_00038de0 (77 B): matches/0x00038de0.cpp
// sym: ?FUN_00038de0@Obj_38de0@owners@@QAEEIIIIIIII@Z
unsigned char owners::Obj_38de0::FUN_00038de0(hulk_uintptr a, hulk_uintptr b, unsigned int c, unsigned int d, hulk_uintptr e,
                        hulk_uintptr f, hulk_uintptr g, hulk_uintptr h) {
    Lock(0);
    unsigned char r = Work_002027c0(((unsigned int)a), ((unsigned int)b), c, d, ((unsigned int)e), ((unsigned int)f), ((unsigned int)g), ((unsigned int)h));
    Lock(1);
    return r;
}


// 0x00038e30 FUN_00038e30 (67 B): matches/0x00038e30.cpp
// sym: ?FUN_00038e30@Obj_38e30@owners@@QAEEHHHHHH@Z
u8_38e30 owners::Obj_38e30::FUN_00038e30(hulk_intptr a, hulk_intptr b, int c, int d, hulk_intptr e, hulk_intptr f) {
    Gate(0);
    u8_38e30 r = FUN_002029e0(((int)a), ((int)b), c, d, ((int)e), ((int)f));
    Gate(1);
    return r;
}

namespace fn_f35f7bdf {

// 0x00038e80 FUN_00038e80 (271 B): equivalent/0x00038e80.cpp
// sym: ?target@Object@fn_f35f7bdf@@QAEXMMMPBUVec3_38e80@2@0M@Z @e24c99eb6e1d @we6ab3b32f885
// STATUS: equivalent (tools/equiv.py level 3: 1390 inputs, branch coverage 18/18)
// FUN_00038e80 @ 0x00038e80
void Object::target(float a,float b,float c,const Vec3_38e80* d,const Vec3_38e80* e,float f) {
 Object* obj=this;
 while(obj->next) obj=obj->next;
 int count=obj->count;
 int index=0;
 bool insert=false;
 if(count>0) {
  do {
   if(f<obj->entries[index].time) { insert=true; break; }
   ++index;
  } while(index<obj->count);
 }
 if(!insert) {
  if(count<128) {
   obj->entries[count].FUN_00037780(a,b,c,d,e,f);
   ++obj->count;
  }
  return;
 }
 int end=count;
 if(end>=128) end=127;
 else obj->count=count+1;
 for(int i=end;i>index;--i) {
  Entry_38e80& src=obj->entries[i-1];
  obj->entries[i].FUN_00037780(src.x,src.y,src.z,&src.first,&src.second,src.time);
 }
 obj->entries[index].FUN_00037780(a,b,c,d,e,f);
}


// 0x000392e0 FUN_000392e0 (213 B): equivalent/0x000392e0.cpp
// sym: ?FUN_000392e0@Actor_392e0@fn_f35f7bdf@@QAEHPAURequest@2@@Z @91f1f9c61c0e @w94f5ca26a922
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 19/20, incomplete)
// FUN_000392e0 @ 0x000392e0
hulk_intptr Actor_392e0::FUN_000392e0(Request* request) {
 if (!state) return 0;
 Data_392e0* data = request->slot3();
 unsigned char enabled = data->enabled;
 int limit = data->limit;
 State_392e0* current = state;
 int contribution = current ? current->contribution : 0;
 int total = (int)((unsigned int)count2 + (unsigned int)count1 + (unsigned int)contribution);
 if (total > limit) enabled = 0;
 Link_392e0* link = data->link;
 if (link && link->type == 1 && link->actor && !blocked && (float)flag > 0.0f && link->actor->state->identity == current->identity) return 0;
 data->enabled = enabled;
 Handler_392e0* handler = state->handler;
 if (!handler) return 0;
 return handler->slot8(request, 0);
}


// 0x000393c0 FUN_000393c0 (121 B): matches/0x000393c0.cpp
// sym: ?Fn@CCharacter_393c0@fn_f35f7bdf@@QAEXXZ
void CCharacter_393c0::Fn() {
    if (mFlag)
        return;
    hulk_at_004dd700->sub->Check_000242d0(this);
    LinkB* l = mLink;
    if (l && l->mKind == 1) {
        Other_393c0* o = l->mTarget;
        if (o) {
            Sub2_393c0* s = hulk_at_004dd700->sub;
            if (s) {
                if (s->Check_000242d0(o)) {
                    if (o->val > 0.0f)
                        return;
                }
            }
        }
    }
    if (mLink) {
        mLink->Release();
        mLink = 0;
    }
}

} // namespace fn_f35f7bdf

// 0x00039440 FUN_00039440 (595 B): equivalent/0x00039440.cpp [wrapped: conflict: World]
// sym: ?FUN_00039440@Fighter_39440@fn_00039440@@QAE_NPAUEvent_39440@2@PAXPAHD@Z @db34c75b0cd3 @w65814a9aaca0
namespace fn_00039440 {
// STATUS: equivalent (tools/equiv.py level 3: 217 inputs, branch coverage 79/96, incomplete)
// FUN_00039440 @ 0x00039440
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

struct Fighter_39440;

struct Event_39440 {
    char pad0[8];
    Fighter_39440 *owner;
    int kind;
};

struct Handle_39440 {
    char pad0[0xa0];
    void *link;
};

struct Slot_39440 {
    Handle_39440 *handle;
    char pad04[0x4c];
};

struct Team_39440 {
    char pad0[0x1b0];
    void *id;
};

struct Control_39440 {
    char pad0[0x60];
    Event_39440 *current;
};

struct World {
    char pad0[0x20];
    struct Mode_39440 *mode;
};

struct Mode_39440 {
    char pad0[0x124];
    Fighter_39440 *fighter;
};


extern "C" bool __cdecl FUN_00096b50(Event_39440 *ev, void *out, int *result);

struct Fighter_39440 {
    char pad000[0x114];
    Event_39440 *f114;
    char pad118[4];
    Team_39440 *team;
    char pad120[8];
    Handle_39440 *held;
    Event_39440 *heldEvent;
    int mode130;
    char pad134[0x148 - 0x134];
    Fighter_39440 *f148;
    Event_39440 *target;
    char pad150[0x328 - 0x150];
    Event_39440 *grab;
    char pad32c[8];
    Fighter_39440 *partner;
    Fighter_39440 *partner2;
    char pad33c[0x3a8 - 0x33c];
    Slot_39440 slots[8];
    char pad628[0x1ca0 - 0x628];
    Control_39440 *control;
    bool FUN_00039440(Event_39440 *ev, void *out, int *result, char flag);
};

bool Fighter_39440::FUN_00039440(Event_39440 *ev, void *out, int *result, char flag)
{
    if (ev == 0)
        return false;

    for (int i = 0; i < 8; i++) {
        if (slots[i].handle != 0) {
            if (ev == ((Event_39440 *)((owners::C_1d72e0 *)(slots[i].handle))->FUN_001d72e0()))
                return false;
        }
    }

    if (partner != 0) {
        if (ev == partner->heldEvent)
            return false;
        if (partner->held != 0 && ev == ((Event_39440 *)((owners::C_1d72e0 *)(partner->held))->FUN_001d72e0()))
            return false;
        for (int i = 0; i < 8; i++) {
            Handle_39440 *h = partner->slots[i].handle;
            if (h != 0 && ev == ((Event_39440 *)((owners::C_1d72e0 *)h)->FUN_001d72e0()))
                return false;
        }
    }

    if (partner2 != 0) {
        if (ev == partner2->heldEvent)
            return false;
        if (partner2->held != 0 && ev == ((Event_39440 *)((owners::C_1d72e0 *)(partner2->held))->FUN_001d72e0()))
            return false;
        for (int i = 0; i < 8; i++) {
            Handle_39440 *h = partner2->slots[i].handle;
            if (h != 0 && ev == ((Event_39440 *)((owners::C_1d72e0 *)h)->FUN_001d72e0()))
                return false;
        }
    }

    if (ev == target)
        return false;

    void *teamId = team->id;
    if (!FUN_00096b50(ev, out, result))
        return false;

    switch (ev->kind) {
    case 1: {
        Fighter_39440 *other = ev->owner;
        if (other == this)
            return false;
        if (other == partner)
            return false;
        if (other->team->id != teamId)
            return true;
        return ev == control->current;
    }
    case 5: {
        if (mode130 == 0) {
            if (ev != control->current)
                return false;
        }
        Fighter_39440 *other = ev->owner;
        if (other == 0)
            return false;
        Event_39440 *grabbed = other->f114;
        if (grabbed != 0) {
            if (flag != 0)
                return false;
            Event_39440 *g = grab;
            Event_39440 *gh = 0;
            if (g != 0 && g->kind == 5 && g->owner != 0)
                gh = g->owner->f114;
            if (ev != g && grabbed != g && grabbed != gh)
                return false;
        }
        Fighter_39440 *third = other->f148;
        if (third == 0)
            return true;
        if (third == this)
            return false;
        if (third == partner)
            return false;
        if (third->team->id != teamId)
            return true;
        return ev == control->current;
    }
    case 7:
        return DAT_004dd700->mode->fighter == this;
    default:
        return true;
    }
}
} // namespace fn_00039440
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000396a0 FUN_000396a0 (1462 B): equivalent/0x000396a0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?F@Picker@fn_000396a0@@QAEPAUThing_396a0@2@MMH@Z @03136105d84b @w3ab900913270
namespace fn_000396a0 {
// STATUS: equivalent (tools/equiv.py level 3: 4020 inputs, branch coverage 69/78, incomplete)
// FUN_000396a0 @ 0x000396a0
// equiv-conv: FUN_00035e70 eax stack
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double atan2(double y, double x);
#endif


struct Obj13;

struct V3_396a0 {
    float x, y, z;
    float FUN_00018990();
    float FUN_000111f0();
    void FUN_0022d240(V3_396a0 *in, Obj13 *cam);
};

struct Obj13 {
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
    virtual void v11();
    virtual void v12();
    virtual Obj13 *v13();
};

struct Inner_396a0 {
    Obj13 *FUN_001c19a0();
};
struct Cam_396a0 {
    Inner_396a0 *inner;
    V3_396a0 *FUN_001c39d0();
};
Cam_396a0 *FUN_001c3d90();

struct HitObj_396a0 {
    char pad0[0x10];
    int f10;
};

struct Sub11c_396a0 {
    char pad0[0x1a0];
    float f1a0;
};
struct Sub8_396a0 {
    char pad0[0x40];
    int f40;
    char pad44[0x11c - 0x44];
    Sub11c_396a0 *p11c;
    HitObj_396a0 *FUN_001d75c0(int idx);
};
struct Thing_396a0 {
    char pad0[8];
    Sub8_396a0 *p8;
    int type;
};

struct Ray_396a0 {
    char FUN_00201e00(V3_396a0 *from, V3_396a0 *to, int one, V3_396a0 *outA, V3_396a0 *outB, int z1, HitObj_396a0 **hit);
};
struct List_396a0 {
    int **begin;
    int **end;
};
struct ListOwner_396a0 {
    List_396a0 *FUN_002ed700();
};
struct Mid_396a0 {
    char pad0[8];
    ListOwner_396a0 *p8;
};
struct World {
    char pad0[0x10];
    Mid_396a0 *p10;
    char pad14[0x24 - 0x14];
    Ray_396a0 *p24;
};

Thing_396a0 *FUN_000969d0(int a);
char FUN_00035e70(Thing_396a0 *t, float len);

static float HalfPi()
{
    return 1.5707964f;
}

class Picker {
public:
    char pad0[0x328];
    Thing_396a0 *p328;
    void FUN_000350c0(V3_396a0 *out);
    char FUN_00039440(Thing_396a0 *t, V3_396a0 *out, int *score, int flag);
    Thing_396a0 *F(float x, float z, int minScore);
};

Thing_396a0 *Picker::F(float x, float z, int minScore)
{
    struct Frame {
        char pad0c[3];
        char flag;
        float d;
        int best;
        V3_396a0 R;
        int score2;
        V3_396a0 Tp;
        V3_396a0 T;
        HitObj_396a0 *hit;
        float bestAngle;
        float dA;
        float dB;
        V3_396a0 D;
        V3_396a0 H;
        V3_396a0 P;
        float B;
        Thing_396a0 *result;
        float A;
        int idx;
        float inv;
        int thisSpill;
        int f24spill;
        Obj13 *cam;
        int count;
        V3_396a0 W;
        V3_396a0 outA;
        V3_396a0 X;
        V3_396a0 outB;
    } fr;

    float len = (float)sqrt(x * x + z * z);
    if (len <= 0.0f)
        return 0;
    float inv0 = 1.0f / len;
    x = x * inv0;
    z = z * inv0;
    fr.cam = FUN_001c3d90()->inner->FUN_001c19a0()->v13();
    fr.P.x = 0;
    fr.P.y = 0;
    fr.P.z = 0;
    FUN_000350c0(&fr.P);
    Thing_396a0 *cur = p328;
    fr.best = 0x80000000;
    fr.A = 0;
    fr.B = 0;
    if (cur) {
        fr.Tp.x = 0;
        fr.Tp.y = 0;
        fr.Tp.z = 0;
        FUN_00039440(cur, &fr.Tp, &fr.best, 0);
        fr.R.FUN_0022d240(&fr.Tp, fr.cam);
        fr.A = (float)atan2(fr.R.x, fr.R.z);
        fr.B = (float)atan2(fr.R.y, fr.R.z);
    }
    Ray_396a0 *ray = DAT_004dd700->p24;
    fr.result = 0;
    fr.bestAngle = 3.4028235e38f;
    fr.flag = 0;
    List_396a0 *list = DAT_004dd700->p10->p8->FUN_002ed700();
    if (!list)
        return fr.result;
    int count = (int)(list->end - list->begin);
    for (int i = 0; i < count; i++) {
        int *item = list->begin[i];
        if (!item)
            continue;
        Thing_396a0 *th = FUN_000969d0(item[6]);
        if (!th)
            continue;
        if (th == p328)
            continue;
        fr.T.x = 0;
        fr.T.y = 0;
        fr.T.z = 0;
        fr.score2 = 0x80000000;
        if (!FUN_00039440(th, &fr.T, &fr.score2, 0))
            continue;
        int score2 = fr.score2;
        if (score2 < minScore)
            continue;
        char bl;
        if (fr.best >= 50) {
            if (score2 < 50)
                continue;
            bl = 0;
        } else {
            bl = score2 >= 50;
        }
        fr.W.FUN_0022d240(&fr.T, fr.cam);
        fr.dA = (float)atan2(fr.W.x, fr.W.z) - fr.A;
        fr.dB = (float)atan2(fr.W.y, fr.W.z) - fr.B;
        fr.d = (float)sqrt(fr.dB * fr.dB + fr.dA * fr.dA);
        if (fr.d > 4.71238899f) {
            if (!bl)
                continue;
        }
        float u, v;
        if (fr.d > 0.0f) {
            fr.inv = 1.0f / fr.d;
            u = fr.inv * fr.dA;
            v = fr.inv * fr.dB;
        } else {
            u = 0.0f;
            v = 0.0f;
        }
        float dot = u * x + v * z;
        if (dot < 0.0f && !bl)
            continue;
        static float halfPi = HalfPi();
        fr.d = fr.d - dot * halfPi;
        if (!(fr.d < fr.bestAngle) && !fr.flag && !bl)
            continue;
        char ok = 1;
        if (th->type == 1) {
            fr.D.x = fr.T.x - fr.P.x;
            fr.D.y = fr.T.y - fr.P.y;
            fr.D.z = fr.T.z - fr.P.z;
            float dl = fr.D.FUN_00018990();
            ok = FUN_00035e70(th, dl);
        }
        bl = 0;
        if (ok) {
            V3_396a0 *cp = FUN_001c3d90()->FUN_001c39d0();
            fr.X.x = cp->x;
            fr.X.y = cp->y;
            fr.X.z = cp->z;
            fr.Tp.x = fr.T.x;
            fr.Tp.y = fr.T.y;
            fr.Tp.z = fr.T.z;
            fr.hit = 0;
            if (th->type == 1 && th->p8 && th->p8->p11c)
                fr.Tp.y = fr.Tp.y + th->p8->p11c->f1a0;
            bl = ray->FUN_00201e00(&fr.X, &fr.Tp, 1, &fr.outA, &fr.outB, 0, &fr.hit);
            if (bl) {
                fr.H.x = fr.outA.x - fr.Tp.x;
                fr.H.y = fr.outA.y - fr.Tp.y;
                fr.H.z = fr.outA.z - fr.Tp.z;
                if (fr.H.FUN_000111f0() < 100.0f) {
                    bl = 0;
                } else {
                    bool commit = false;
                    if (fr.hit && th->type == 5 && th->p8) {
                        HitObj_396a0 *ho = th->p8->FUN_001d75c0(th->p8->f40);
                        if (ho && ho->f10 == (hulk_intptr)fr.hit) {
                            bl = 0;
                            commit = true;
                        }
                    }
                    if (!commit) {
                        fr.D.x = fr.P.x - fr.T.x;
                        fr.D.y = fr.P.y - fr.T.y;
                        fr.D.z = fr.P.z - fr.T.z;
                        if (!(fr.D.FUN_000111f0() < 10000.0f))
                            continue;
                        if (score2 >= 100 && fr.best < 100) {
                            commit = true;
                        } else {
                            if (!fr.flag)
                                continue;
                            if (fr.d >= fr.bestAngle)
                                continue;
                            commit = true;
                        }
                    }
                }
            }
        }
        fr.result = th;
        fr.bestAngle = fr.d;
        fr.best = score2;
        fr.flag = bl;
    }
    return fr.result;
}
} // namespace fn_000396a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00039c60 FUN_00039c60 (2003 B): equivalent/0x00039c60.cpp [wrapped: conflict: World]
// sym: ?FUN_00039c60@Picker@fn_00039c60@@QAEPAUThing@2@PAUV3@2@0MMHPAPAU32@M@Z @328912fe5164 @wa79829360b43
namespace fn_00039c60 {
// STATUS: equivalent (tools/equiv.py level 3: 19400 inputs, branch coverage 118/150, incomplete)
// FUN_00039c60 @ 0x00039c60
// equiv-conv: FUN_00035e70 eax stack
// equiv-dead: +0x59 not taken, +0x405 not taken: a2 < 0 (or NaN) cannot also be > 2pi; ii < 100 with bestRank >= 100 is skipped at +0x26e before +0x405
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
extern "C" double cos(double);
#endif


struct V3 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    hulk_freg FUN_00018990();
    hulk_freg FUN_000111f0();
};

struct HitObj {
    char pad0[0x10];
    int f10;
};

struct Sub11c {
    char pad0[0x1a0];
    float f1a0;
};

struct Sub8 {
    char pad0[0x40];
    int f40;
    char pad44[0x11c - 0x44];
    Sub11c *p11c;
    HitObj *FUN_001d75c0(int idx);
};

struct Thing {
    char pad0[8];
    Sub8 *p8;
    int type;
    char pad10[8];
    int f18;
    float FUN_002ef420();
};

struct Ray {
    char FUN_00201e00(V3 *from, V3 *to, int one, V3 *outA, V3 *outB, int z1, int *hit);
};

struct Cam {
};
Cam *FUN_001c3d90();

struct List {
    int **begin;
    int **end;
};
struct ListOwner {
    List *FUN_002ed700();
};
struct Mid {
    char pad0[8];
    ListOwner *p8;
};
struct World {
    char pad0[0x10];
    Mid *p10;
    char pad14[0x24 - 0x14];
    Ray *p24;
};

Thing *__cdecl FUN_000969d0(int a);
char FUN_00035e70(Thing *t, float score);
hulk_freg __cdecl FUN_00224f10(V3 *v);
hulk_freg __cdecl FUN_00224fc0(float a, float b);

struct Frame {
    char pad0[3];
    char flag;          // 0x03
    float dot;          // 0x04
    float score;        // 0x08
    float bestDot;      // 0x0c
    float bestScore;    // 0x10
    V3 w;               // 0x14
    int ii;             // 0x20
    V3 e;               // 0x24
    V3 v88;             // 0x30
    V3 d;               // 0x3c
    int q70;            // 0x48
    int count;          // 0x4c
    void *best;         // 0x50
    V3 h;               // 0x54
    void *thisSpill;    // 0x60
    List *list;         // 0x64
    int index;          // 0x68
    V3 ww;              // 0x6c
    V3 v40;             // 0x78
    float cs;           // 0x84
    float t30;          // 0x88
    Ray *ray;           // 0x8c
    float t28;          // 0x90
    V3 r24;             // 0x94
    V3 o18;             // 0xa0
    V3 oc;              // 0xac
};

class Picker {
public:
    char pad0[8];
    Picker *f8;
    int fc;
    char pad10[0x80 - 0x10];
    V3 v80;
    char pad8c[0x11c - 0x8c];
    void *f11c;
    void FUN_000350c0(V3 *out);
    void FUN_00035550(V3 *out);
    hulk_freg FUN_000354c0();
    char FUN_00039440(Thing *t, V3 *out, int *score, int flag);
    Thing *FUN_00039c60(V3 *a0, V3 *a1, float a2, float a3, int a4, Thing **a5, float a6);
};

Thing *Picker::FUN_00039c60(V3 *a0, V3 *a1, float a2, float a3, int a4, Thing **a5, float a6)
{
    Frame f;
    int bestRank;

    f.thisSpill = this;
    if (f11c == 0)
        return 0;

    float c;
    if (a2 >= 0.0f) {
        if (a2 <= 6.2831854820251465f)
            c = a2;
        else
            c = 6.2831854820251465f;
    } else {
        c = 0.0f;
    }
    f.v88.x = 0.0f;
    f.v88.y = 0.0f;
    f.v88.z = 0.0f;
    f.cs = (float)cos((double)(c * 0.5f));
    FUN_000350c0(&f.v88);

    f.v40.x = v80.x;
    f.v40.y = v80.y;
    f.v40.z = v80.z;
    hulk_freg len = f.v40.FUN_0022d110();
    float m;
    if (len <= 0.0f) {
        FUN_00035550(&f.v40);
        m = 1.0f;
    } else if (len < 1.0f) {
        m = 1.0f;
    } else {
        m = len;
    }
    hulk_freg hh = m * 0.5f;
    f.w.x = f.v40.x;
    f.w.y = f.v40.y;
    f.w.z = f.v40.z;
    World *hub = DAT_004dd700;
    f.w.y = f.w.y * hh;
    f.best = 0;
    f.w.z = f.w.z * hh;
    f.bestScore = 3.4028234663852886e+38f;
    bestRank = (int)0x80000000;
    f.bestDot = -1.0f;
    f.flag = 0;
    f.v88.x = f.v88.x + f.w.x * hh;
    f.v88.y = f.w.y + f.v88.y;
    f.v88.z = f.w.z + f.v88.z;
    f.ray = hub->p24;
    f.list = hub->p10->p8->FUN_002ed700();
    if (f.list == 0)
        return (Thing *)f.best;

    f.count = (int)(f.list->end - f.list->begin);
    for (f.index = 0; f.index < f.count; f.index++) {
        int *item = f.list->begin[f.index];
        if (item == 0)
            continue;
        Thing *th = FUN_000969d0(item[6]);
        if (th == 0)
            continue;
        if (th == (Thing *)f.best)
            continue;
        if (a5 != 0) {
            Thing **p = a5;
            Thing *x = *p;
            bool excluded = false;
            while (x != 0) {
                if (th == x) {
                    excluded = true;
                    break;
                }
                x = p[1];
                p++;
            }
            if (excluded)
                continue;
        }

        f.w.x = 0.0f;
        f.w.y = 0.0f;
        f.w.z = 0.0f;
        f.ii = (int)0x80000000;
        if (!FUN_00039440(th, &f.w, &f.ii, 1))
            continue;
        if (f.ii < a4)
            continue;
        if (bestRank >= 100 && f.ii < 100)
            continue;

        f.d.x = f.w.x - f.v88.x;
        f.d.y = f.w.y - f.v88.y;
        f.d.z = f.w.z - f.v88.z;
        if (f.d.y > 0.0f)
            f.d.y = f.d.y * 0.5f;
        f.dot = f.d.FUN_00018990();
        double sc = f.dot - th->FUN_002ef420() * 0.3333333432674408f;
        f.score = (float)sc;
        if (sc > a3)
            continue;

        f.e.x = f.w.x - a0->x;
        f.e.y = f.w.y - a0->y;
        f.e.z = f.w.z - a0->z;
        f.e.FUN_0022d110();
        double dd = f.e.z * a1->z + f.e.y * a1->y + f.e.x * a1->x;
        f.dot = (float)dd;
        if (dd < f.cs)
            continue;

        if (a6 > 0.0f) {
            f.t30 = FUN_00224f10(&f.e);
            f.t28 = FUN_000354c0();
            if (FUN_00224fc0(f.t28, f.t30) > a6)
                continue;
        }

        // verdict: 0 skip, 1 accept
        int verdict = 1;
        int target;   // 0 = 0x415, 1 = 0x51d
        int ii = f.ii;
        if (ii < 100) {
            if (f.dot <= 0.0f)
                continue;
            target = (bestRank >= 100) ? 1 : 0;
        } else {
            target = (bestRank < 100) ? 1 : 0;
        }
        if (target == 0) {
            do {
                if (f.score < 15.0f && f.bestScore >= 15.0f) {
                    if (ii >= 104 || bestRank < 104)
                        break;
                }
                if (f.score >= 15.0f && f.bestScore < 15.0f) {
                    if (ii < 104 || bestRank >= 104) {
                        verdict = 0;
                        break;
                    }
                }
                if (f.dot > 0.7071067690849304f) {
                    if (f.bestDot < 0.7071067690849304f)
                        break;
                }
                if (f.score < 50.0f && f.bestScore >= 50.0f)
                    break;
                if (!f.flag) {
                    if (f.dot < 0.7071067690849304f && f.bestDot > 0.7071067690849304f) {
                        verdict = 0;
                        break;
                    }
                    if (f.score >= 50.0f && f.bestScore < 50.0f) {
                        verdict = 0;
                        break;
                    }
                }
                target = 1;
            } while (0);
        }
        if (target == 1) {
            if (ii > bestRank) {
                verdict = 1;
            } else if (ii != bestRank) {
                verdict = 0;
            } else {
                bool toTie = true;      // reach 0x599
                if (f.dot >= 0.0f && f.bestDot < 0.0f) {
                    verdict = 1;
                    toTie = false;
                } else if (f.dot < 0.0f && f.bestDot < 0.0f) {
                    toTie = true;
                } else if (f.dot < 0.0f || !(f.dot >= 0.0f) || f.bestDot < 0.0f || !(f.bestDot >= 0.0f)) {
                    verdict = 0;
                    toTie = false;
                }
                if (toTie)
                    verdict = (f.score < f.bestScore) ? 1 : 0;
            }
        }
        if (!verdict)
            continue;

        char bl = 0;
        if (FUN_00035e70(th, f.score)) {
            V3 *cp = ((V3 *)((owners::Object_1c39d0 *)(FUN_001c3d90()))->FUN_001c39d0());
            f.r24.x = cp->x;
            f.r24.y = cp->y;
            f.r24.z = cp->z;
            f.ww.x = f.w.x;
            f.ww.y = f.w.y;
            f.ww.z = f.w.z;
            f.q70 = 0;
            if (th->type == 1 && th->p8 && th->p8->p11c)
                f.ww.y = f.ww.y + th->p8->p11c->f1a0;
            bl = f.ray->FUN_00201e00(&f.r24, &f.ww, 1, &f.o18, &f.oc, 0, &f.q70);
            if (bl) {
                f.h.x = f.o18.x - f.ww.x;
                f.h.y = f.o18.y - f.ww.y;
                f.h.z = f.o18.z - f.ww.z;
                if (f.h.FUN_000111f0() < 100.0f) {
                    bl = 0;
                } else {
                    bool store = false;
                    if (f.q70 && th->type == 5 && th->p8) {
                        HitObj *ho = th->p8->FUN_001d75c0(th->p8->f40);
                        if (ho && ho->f10 == f.q70) {
                            bl = 0;
                            store = true;
                        }
                    }
                    if (!store) {
                        if (f.score >= 100.0f || !(f.score < 100.0f))
                            continue;
                        if (ii >= 100 && bestRank < 100) {
                            store = true;
                        } else {
                            if (!f.flag)
                                continue;
                            if (ii < bestRank)
                                continue;
                            if (f.dot < 0.0f && !(f.bestDot < 0.0f))
                                continue;
                            if (f.dot < 0.7071067690849304f && !(f.bestDot < 0.7071067690849304f))
                                continue;
                            if (!(f.score < f.bestScore))
                                continue;
                            store = true;
                        }
                    }
                }
            }
        }
        f.best = th;
        f.bestScore = f.score;
        f.bestDot = f.dot;
        bestRank = ii;
        f.flag = bl;
    }
    return (Thing *)f.best;
}
} // namespace fn_00039c60
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35f7bdf {

// 0x0003a440 FUN_0003a440 (217 B): equivalent/0x0003a440.cpp
// sym: ?test@Query_3a440@fn_f35f7bdf@@QAE_NPAUVec_3a440@2@0MMPAUObject@2@@Z @0b396549a892 @w252a6d7a5dd8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0003a440 @ 0x0003a440
bool Query_3a440::test(Vec_3a440* origin,Vec_3a440* direction,float angle,float distance,Object* object) {
 if (!object) return false;
 Vec_3a440 hit; hit.x=0; hit.y=0; hit.z=0;
 Object* input=object;
 object=0;
 if (!FUN_00039440(input,&hit,&object,0)) return false;
 Vec_3a440 delta;
 delta.x=hit.x-origin->x;
 delta.y=hit.y-origin->y;
 delta.z=hit.z-origin->z;
 float length=delta.FUN_0022d110();
 if (length>distance) return false;
 double dot=(double)delta.z*direction->z+(double)delta.y*direction->y+(double)delta.x*direction->x;
 return !(cos((double)angle*0.5f)>dot);
}


// 0x0003a520 FUN_0003a520 (74 B): matches/0x0003a520.cpp
// sym: ?Fn@CCharacter_3a520@fn_f35f7bdf@@QAEPAXHHHH@Z
void* CCharacter_3a520::Fn(hulk_intptr a, hulk_intptr b, int c, int d) {
    if (flag)
        return p;
    if (!Do_0003a440(a, b, c, d, p)) {
        Fail_000393c0();
        return 0;
    }
    return p;
}


// 0x0003a570 FUN_0003a570 (30 B): matches/0x0003a570.cpp
// sym: ?run@B_3a570@fn_f35f7bdf@@QAEXXZ
void B_3a570::run() {
    if (p) {
        p->g();
        p = 0;
    }
}


// 0x0003a590 FUN_0003a590 (237 B): matches/0x0003a590.cpp
// sym: ?target@Object@fn_f35f7bdf@@QAE_NHPAU12@@Z
bool Object::target(int unused, Object* other) {
    if (state && state->kind == 3)
        return true;
    if (other->state && other->state->kind == 5)
        return true;
    Vec_3a590 a, b, c, d;
    if (!FUN_000352b0(&a))
        return false;
    if (!other->FUN_000352b0(&b))
        return false;
    other->FUN_00035fa0(0);
    Flag_3a590* flag = 0;
    if (other->link) {
        Result_3a590* result = ((Result_3a590 *)((owners::C_1d72e0 *)(other->link))->FUN_001d72e0());
        if (result) {
            flag = result->flag;
            if (flag)
                flag->enabled = 0;
        }
    }
    FUN_00035fa0(0);
    bool hit = FUN_002027c0(&a, &b, 0, 0, &d, &c, 0, 0);
    FUN_00035fa0(1);
    bool answer = !hit;
    if (flag)
        flag->enabled = 1;
    other->FUN_00035fa0(1);
    return answer;
}


// 0x0003a680 FUN_0003a680 (422 B): equivalent/0x0003a680.cpp
// sym: ?SetTarget@Entity@fn_f35f7bdf@@QAEDPAV12@HHHPBUMatrix@2@MMM@Z @456484b8e669 @wbc4a584bdf33
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 23/24, incomplete)
// FUN_0003a680 @ 0x0003a680
char Entity::SetTarget(Entity *t, int a, int b, int c, const Matrix *m, float e5, float e6, float e7)
{
    Entity *old = target;
    target = t;
    prevTarget = old;
    Scene_3a680 *scene = FUN_00059a40(owner);
    FUN_00037000();
    sub.FUN_00232240();

    if (target != 0) {
        id = a;
        idB = b;
        idC = c;
        if (m != 0)
            matrix = *m;
        else
            matrix.FUN_0022b980();

        if (scene != 0) {
            scene->FUN_00222970(joint, 0);
            void *mem = FUN_00263ea0(0x70);
            JointDriver_3a680 *obj = 0;
            if (mem)
                obj = ((JointDriver_3a680 *)mem)->FUN_002248f0(0);
            if (obj)
                obj->vfunc_0();
            if (joint)
                joint->vfunc_1();
            joint = obj;
            int v = scene->pose.FUN_00221c40();
            joint->transform.FUN_00221c60(v);
            scene->FUN_00222890(joint, -1.0f, e5, e6, e7, e7, -1.0f);
        }
    } else {
        id = 0xffff;
        idB = 0;
        idC = 0;
        matrix.FUN_0022b980();
        if (joint != 0)
            scene->FUN_00222d70(joint, e7);
        if (scene != 0)
            scene->FUN_00222970(joint, 0);
        if (joint != 0) {
            joint->vfunc_1();
            joint = 0;
        }
    }

    Entity *cur = target;
    if (prevTarget != cur) {
        f38c = 0;
        if (cur != 0)
            cur->f38c = 0;
    }
    return 1;
}


// 0x0003a830 FUN_0003a830 (404 B): equivalent/0x0003a830.cpp
// sym: ?FUN_0003a830@Fighter_3a830@fn_f35f7bdf@@QAE_NPAUEvent_3a830@2@H@Z @d94ef39408b0 @w79d2995a6977
// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 51/66, incomplete)
// FUN_0003a830 @ 0x0003a830
bool Fighter_3a830::FUN_0003a830(Event_3a830 *ev, hulk_intptr arg)
{
    int i;
    if (!ev || ev->kind != 5)
        return false;
    Weapon_3a830 *w = ev->weapon;
    if (!w)
        return false;
    for (i = 0; i < 8; i++) {
        if (slots[i].slot && (Slot_3a830 *)w == slots[i].slot)
            return false;
    }
    for (int k = 0; k < 2; k++) {
        Fighter_3a830 *f = (k == 0) ? t334 : t338;
        if (!f)
            continue;
        if (ev == f->ev12c)
            return false;
        if (f->slot128 && ev == ((Event_3a830 *)((owners::C_1d72e0 *)(f->slot128))->FUN_001d72e0()))
            return false;
        for (i = 0; i < 8; i++) {
            // the callee may modify the table, so the pointer is re-read each time
            Fighter_3a830 *g = (k == 0) ? t334 : t338;
            Slot_3a830 *s = g->slots[i].slot;
            if (s && ev == ((Event_3a830 *)((owners::C_1d72e0 *)s)->FUN_001d72e0()))
                return false;
        }
    }
    if (ev == ev14c)
        return false;
    if (w->mode == 2 || w->mode == 3 || w->mode == 1)
        return false;
    if (w->FUN_001d6980())
        return false;
    if (w->f114)
        return false;
    Owner_3a830 *o = w->owner;
    if (o) {
        if (o->f20b0)
            return false;
        if (o->f1b0c <= 0.0f)
            return false;
    }
    w->FUN_001d69f0(arg);
    return true;
}

} // namespace fn_f35f7bdf

// 0x0003a9d0 FUN_0003a9d0 (285 B): equivalent/0x0003a9d0.cpp [wrapped: conflict: Entity]
// sym: ?FUN_0003a9d0@Actor_3a9d0@fn_0003a9d0@@QAE_NPAUTarget_3a9d0@2@@Z @6ed40b6d4581 @w4a1daa507aa5
namespace fn_0003a9d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 29/30, incomplete)
// FUN_0003a9d0 @ 0x0003a9d0
struct Vec3_3a9d0 { float x,y,z; };
struct Entity { char pad[0x114]; void* owner; int FUN_001d64a0(); };
struct Target_3a9d0 { virtual void retain(); virtual void release(); int unused; Entity* entity; int type; };
struct Position_3a9d0 { bool FUN_00059a50(Vec3_3a9d0*); };
struct Height { char pad[0x2c]; float offset; };
struct Actor_3a9d0 {
 char pad0[0x10]; Position_3a9d0* position;
 char pad1[0x108]; Height* height;
 char pad2[0xc]; void* owner;
 char pad3[0x274]; Target_3a9d0* current;
 bool FUN_0003a830(Target_3a9d0*, Vec3_3a9d0*);
 bool FUN_00038de0(Vec3_3a9d0*, Vec3_3a9d0*, int, int, Vec3_3a9d0*, Vec3_3a9d0*, Target_3a9d0**, int);
 bool FUN_0003a9d0(Target_3a9d0*);
};
bool Actor_3a9d0::FUN_0003a9d0(Target_3a9d0* target) {
 if (target && target != current && target->type == 5) {
  Entity* entity = target->entity;
  int state = entity->FUN_001d64a0();
  if (entity->owner && entity->owner != owner) return false;
  if (state != 5 && state != 0) {
   Vec3_3a9d0 start = {0.0f,0.0f,0.0f};
   if (!position->FUN_00059a50(&start)) return false;
   if (height) start.y += height->offset;
   Vec3_3a9d0 end;
   if (!FUN_0003a830(target,&end)) return false;
   Vec3_3a9d0 auxiliary, hit;
   Target_3a9d0* found = 0;
   if (FUN_00038de0(&start,&end,0,1,&hit,&auxiliary,&found,0)) {
    if (!found || found != target) return false;
   }
  }
 }
 if (target) target->retain();
 if (current) current->release();
 current = target;
 return true;
}
} // namespace fn_0003a9d0


// 0x0003aaf0 FUN_0003aaf0 (429 B): equivalent/0x0003aaf0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Select@Host_3aaf0@fn_0003aaf0@@QAE_NPAUEnt_3aaf0@2@@Z @e6e5e5c32055 @w0cb34156a4eb
namespace fn_0003aaf0 {
// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 33/34, incomplete)
// FUN_0003aaf0 @ 0x0003aaf0
struct V3_3aaf0 {
    float x, y, z;
    float FUN_000111f0();
};

struct Ref_3aaf0 { int FUN_001d64a0(); };

struct Ent_3aaf0 {
    char pad0[8];
    Ref_3aaf0* ref;
    int type;
};

struct Cam_3aaf0 { bool FUN_00059a50(V3_3aaf0* out); };

struct Host_3aaf0 {
    char pad0[0x10];
    Cam_3aaf0* cam;
    char pad14[0x14c - 0x14];
    Ent_3aaf0* current;
    char pad150[0x3a4 - 0x150];
    Ent_3aaf0* target;

    bool FUN_0003a9d0(Ent_3aaf0* e);
    bool FUN_0003a830(Ent_3aaf0* e, V3_3aaf0* out);
    bool FUN_00039440(Ent_3aaf0* e, V3_3aaf0* a, int* b, int c);

    bool Select(Ent_3aaf0* e);
};

static int Rank(Ent_3aaf0* e)
{
    int t = 0;
    if (e->type == 5) t = e->ref->FUN_001d64a0();
    if (t == 2 || t == 17) return -1;
    if (t == 3 || t == 4 || t == 6 || t == 7 || t == 18 || t == 19) return -3;
    if (t == 5 || t == 20) return -2;
    if (t == 8 || t == 9 || t == 10 || t == 12) return -4;
    return 0;
}

bool Host_3aaf0::Select(Ent_3aaf0* e)
{
    if (e == 0 || e == current) return 0;
    if (target == 0) return FUN_0003a9d0(e);

    V3_3aaf0 camPos;
    camPos.x = 0; camPos.y = 0; camPos.z = 0;
    cam->FUN_00059a50(&camPos);
    V3_3aaf0 ePos;
    if (!FUN_0003a830(e, &ePos)) return 0;

    int rankNew = Rank(e);
    V3_3aaf0 tPos;
    int extra = 0;
    if (FUN_00039440(target, &tPos, &extra, 0)) {
        int rankOld = Rank(target);
        if (rankNew < rankOld) return FUN_0003a9d0(e);
        if (rankNew > rankOld) return 0;
        tPos.x -= camPos.x; tPos.y -= camPos.y; tPos.z -= camPos.z;
        ePos.x -= camPos.x; ePos.y -= camPos.y; ePos.z -= camPos.z;
        float lenNew = ePos.FUN_000111f0();
        float lenOld = tPos.FUN_000111f0();
        if (lenOld <= lenNew) return 0;
    }
    return FUN_0003a9d0(e);
}
} // namespace fn_0003aaf0


// 0x0003acf0 FUN_0003acf0 (501 B): equivalent/0x0003acf0.cpp [wrapped: conflict: World]
// sym: ?FUN_0003acf0@CCharacter_3acf0@fn_0003acf0@@QAEDHPAUObj_3acf0@2@HHHPAUMatrix@2@@Z @54b90e0f5ad5 @w1ce54d67738e
namespace fn_0003acf0 {
// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 39/40, incomplete)
// FUN_0003acf0 @ 0x0003acf0
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
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

struct Key {
    int lo;
    int hi;
    Key(const Key &o);
};

struct Matrix {
    float f[16];
    void FUN_0022b980();
};

struct Event_3acf0 {
    char data[0x30];
    Event_3acf0 *FUN_001ca830(Key a, Key b, int c, int d);
    Event_3acf0 *FUN_001ca3d0(Key a, Key b, int c, int d);
};

struct Sink_3acf0 {
    char pad0[0x30];
    void FUN_001cbc20(Event_3acf0 *e);
};

struct World {
    char pad0[0x30];
    Sink_3acf0 *sink;
};

struct CCharacter_3acf0;

struct Obj_3acf0;

struct Owner_3acf0 {
    char pad0[8];
    CCharacter_3acf0 *holder;
    int count;
};

struct Obj_3acf0 {
    virtual void AddRef();
    virtual void Release();
    int pad4;
    Key key;
    char pad10[0xec - 0x10];
    Obj_3acf0 *fec;
    char pad_f0[0x114 - 0xf0];
    Owner_3acf0 *owner;
    void FUN_001d7ee0(int v);
    void FUN_001d71e0(int v);
};

struct Slot_3acf0 {
    Obj_3acf0 *obj;
    int k0;
    int k1;
    int k2;
    Matrix m;
};

struct CCharacter_3acf0 {
    char pad0[0x10];
    int *f10;
    char pad14[0x12c - 0x14];
    int f12c;
    char pad130[0x3a8 - 0x130];
    Slot_3acf0 slots[8];
    char pad628[0x1f51 - 0x628];
    char b1f51;
    char FUN_0003acf0(int slot, Obj_3acf0 *newObj, int a3, int a4, int a5, Matrix *m);
};


char CCharacter_3acf0::FUN_0003acf0(int slot, Obj_3acf0 *newObj, int a3, int a4, int a5, Matrix *m)
{
    World *g = DAT_004dd700;
    if (slot < 0 || slot >= 8)
        return 0;
    Slot_3acf0 *s = &slots[slot];
    Obj_3acf0 *old = s->obj;
    Event_3acf0 e;
    if (old != 0 && old != newObj) {
        old->FUN_001d7ee0(0);
        old->FUN_001d71e0(0);
        Sink_3acf0 *sink = g->sink;
        if (sink != 0) {
            e.FUN_001ca830(old->key, old->fec->key, *f10, slot);
            sink->FUN_001cbc20(&e);
        }
    }
    if (newObj != 0) {
        Owner_3acf0 *o = newObj->owner;
        if (o != 0 && o->count == 1 && o->holder != 0) {
            CCharacter_3acf0 *h = o->holder;
            for (int j = 0; j < 8; j++) {
                if (((Obj_3acf0 *)((owners::C_35ef0 *)h)->FUN_00035ef0((hulk_intptr)j)) == newObj && (h != this || j != slot)) {
                    h->FUN_0003acf0(j, 0, -1, 0, 0, 0);
                    break;
                }
            }
        }
        newObj->AddRef();
    }
    if (s->obj != 0)
        s->obj->Release();
    s->obj = newObj;
    s->k0 = a3;
    s->k1 = a4;
    s->k2 = a5;
    if (m != 0)
        s->m = *m;
    else
        s->m.FUN_0022b980();
    if (s->obj != 0)
        s->obj->FUN_001d7ee0(f12c);
    b1f51 = 0;
    if (newObj != 0 && newObj != old) {
        Sink_3acf0 *sink = g->sink;
        if (sink != 0) {
            e.FUN_001ca3d0(newObj->key, newObj->fec->key, *f10, slot);
            sink->FUN_001cbc20(&e);
        }
    }
    return 1;
}
} // namespace fn_0003acf0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35f7bdf {

// 0x0003b160 FUN_0003b160 (46 B): matches/0x0003b160.cpp
// sym: ?F@Owner_3b160@fn_f35f7bdf@@QAE_NPAVObj_3b160@2@@Z
bool Owner_3b160::F(Obj_3b160* x) {
    if (x)
        x->A();
    if (p)
        p->B();
    p = x;
    return true;
}


// 0x0003b190 FUN_0003b190 (46 B): matches/0x0003b190.cpp
// sym: ?Set@Owner_3b190@fn_f35f7bdf@@QAE_NPAVThing_3b190@2@@Z
bool Owner_3b190::Set(Thing_3b190* p) {
    if (p)
        p->A();
    if (ptr)
        ptr->B();
    ptr = p;
    return true;
}


// 0x0003b4f0 FUN_0003b4f0 (130 B): equivalent/0x0003b4f0.cpp
// sym: ?FUN_0003b4f0@AimCheck@fn_f35f7bdf@@QAE_NM@Z @317703ade098 @w1c772184b546
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0003b4f0 @ 0x0003b4f0
bool AimCheck::FUN_0003b4f0(float angle)
{
    if (!active)
        return false;

    Scene_3b4f0 *scene = owner->FUN_00059a40();
    float heading;
    if (scene == 0)
        heading = 0.0f;
    else
        heading = scene->camera.FUN_002220d0();

    FloatBits_3b4f0 diff;
    diff.f = FUN_00224fc0(heading, FUN_00224f10(angle) + 3.14159274f);
    diff.u &= 0x7fffffff;
    return !(threshold * 0.5f < diff.f);
}


// 0x0003b580 FUN_0003b580 (150 B): matches/0x0003b580.cpp
// sym: ?Fn@Obj_3b580@fn_f35f7bdf@@QAEXDMPAVRef_3b580@2@@Z
void Obj_3b580::Fn(char enable, float x, Ref_3b580* r) {
    if (enable) {
        ++count;
        if (count <= 0)
            return;
        if (x > value)
            value = x;
        if (r)
            r->A();
        if (ref)
            ref->B();
        ref = r;
    } else {
        --count;
        if (count > 0)
            return;
        float* q = &value;
        *q = 0.0f;
        if (ref) {
            ref->B();
            ref = 0;
        }
    }
}


// 0x0003b7d0 FUN_0003b7d0 (641 B): equivalent/0x0003b7d0.cpp
// sym: ?FUN_0003b7d0@CCharacter_3b7d0@fn_f35f7bdf@@QAEXHM@Z @3813a07303da @w41fa1fc9728c
// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 53/54, incomplete)
// FUN_0003b7d0 @ 0x0003b7d0
void CCharacter_3b7d0::FUN_0003b7d0(int a, float dt)
{
    V3_3b7d0 zero;
    if (dead)
        return;
    if (frozen)
        return;
    dt = dt * timeScale;
    flagA = false;
    flagB = false;
    z2 = 0;
    z1 = 0;
    z0 = 0;
    if (host == 0)
        return;
    if (listener != 0)
        listener->Update(a, dt);
    if (phase < 0) {
        Finder_3b7d0 *f = host->activeFinder;
        if (f != 0 && !anim.FUN_00231ee0()) {
            Link_3b7d0 *l = f->Make(key, 0);
            if (l != 0)
                l->FUN_00231ad0(&anim, key, 0);
        }
        anim.FUN_002322f0(1, dt);
        anim.FUN_00231f20(0);
        anim.FUN_002324b0(1);
    } else {
        anim.FUN_00232240();
    }
    for (int i = 0; i < 8; i++) {
        if (slots[i].prop != 0) {
            int st = slots[i].prop->state;
            if (st == 2 || st == 3)
                FUN_0003acf0(i, 0, -1, 0, 0, 0);
        }
    }
    zero.z = 0;
    zero.y = 0;
    zero.x = 0;
    if (!dir.FUN_0022d2b0(&zero, 1e-5f))
        savedDir = dir;
    if (poolCount > 0)
        pool.FUN_00060170();
    RefObj_3b7d0 *cur = current.obj;
    if (cur != 0)
        cur->AddRef();
    if (previous != 0)
        previous->Release();
    previous = cur;
    Finder_3b7d0 *f2 = host->finder;
    if (f2 != 0 && !current.FUN_00231ee0() && lock == 0) {
        Link_3b7d0 *l = 0;
        if (hasId && (idLo | idHi) != 0) {
            Link_3b7d0 *r = ((Link_3b7d0 *)((owners::Node_233320 *)f2)->FUN_00233320(idLo, idHi));
            if (r != 0)
                l = (Link_3b7d0 *)FUN_00344e74(r, 0, DAT_0048e090, DAT_0048e0ac, 0);
        }
        if (l == 0)
            l = f2->Make(key, 0);
        if (l != 0)
            l->FUN_00231ad0(&current, key, 0);
    }
    RefObj_3b7d0 *p = previous;
    if (current.obj != p) {
        if (p != 0)
            p->AddRef();
        if (previous2 != 0)
            previous2->Release();
        previous2 = p;
    }
}

} // namespace fn_f35f7bdf

// 0x0003be00 FUN_0003be00 (972 B): equivalent/0x0003be00.cpp [wrapped: conflict: World]
// sym: ?FUN_0003be00@Controller_3be00@fn_0003be00@@QAEXXZ @8d7235ba7061 @wd53fdcea546b
namespace fn_0003be00 {
// STATUS: equivalent (tools/equiv.py level 3: 3051 inputs, branch coverage 20/20)
// FUN_0003be00 @ 0x0003be00
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

struct Vec3_3be00 {
    float x, y, z;
};

struct Quat_3be00 {
    float x, y, z, w;
    char FUN_000375f0(const Quat_3be00 *other, float eps);
};

extern "C" void FUN_0022b080(Quat_3be00 *out, const Quat_3be00 *a, const Quat_3be00 *b);

struct Skeleton {
    char pad00[0x100];
    Quat_3be00 qa;
    Quat_3be00 qb;
    Quat_3be00 qc;
};

struct Pose {
    char pad00[0xb0];
    Vec3_3be00 pos;
};

struct Reference {
    char pad00[0x14];
    Skeleton *skeleton;
};

struct Rig_3be00 {
    char pad00[8];
    Reference *ref;
    char padc[4];
    Skeleton *skeleton;
    Pose *pose;
};

struct Actor_3be00 {
    char pad00[0x64];
    Rig_3be00 *rig;
};

struct Owner_3be00 {
    Actor_3be00 *FUN_00059a40();
};

struct Pad_3be00 {
};

struct Input_3be00 {
};

struct Holder_3be00 {
    char pad00[0x124];
    void *current;
};

struct World {
    char pad00[0x20];
    Holder_3be00 *holder;
    char pad24[0x54 - 0x24];
    Input_3be00 *input;
};


class Controller_3be00 {
public:
    char pad00[0x10];
    Owner_3be00 *owner;
    char pad14[0x140 - 0x14];
    int state;
    void FUN_0003be00();
};

void Controller_3be00::FUN_0003be00()
{
    World *g = DAT_004dd700;
    if (g->holder->current != this) {
        return;
    }
    Pad_3be00 *pad = ((Pad_3be00 *)((owners::A_86340 *)(g->input))->FUN_00086340());
    Rig_3be00 *rig = owner->FUN_00059a40()->rig;
    Reference *ref = rig->ref;
    Quat_3be00 q;
    Quat_3be00 l;
    if (((char)((owners::ThisWrap_00092de0 *)pad)->FUN_00092de0(4))) {
        ((owners::Quaternion_22b220 *)&l)->FUN_0022b220(0.0f, 0.0f, -0.7853982f);
        q = rig->skeleton->qa;
        FUN_0022b080(&q, &q, &l);
        rig->skeleton->qa = q;

        ((owners::Quaternion_22b220 *)&l)->FUN_0022b220(0.0f, 0.0f, -0.7853982f);
        q = rig->skeleton->qb;
        FUN_0022b080(&q, &q, &l);
        rig->skeleton->qb = q;

        q = rig->skeleton->qc;
        l = ref->skeleton->qc;
        if (!q.FUN_000375f0(&l, 1e-05f)) {
            ((owners::Quaternion_22b220 *)&l)->FUN_0022b220(0.0f, 0.0f, 1.2217305f);
            FUN_0022b080(&q, &q, &l);
            rig->skeleton->qc = q;
        }
        int s = state;
        if (s <= 0) {
            return;
        }
        if (s > 2) {
            if (s != 4) {
                return;
            }
            Vec3_3be00 v;
            v.x = 0.0f;
            v.y = 1.3125f;
            v.z = -0.6f;
            ((owners::C_34d80 *)rig)->FUN_00034d80(2, (unsigned int *)(Vec3_3be00 *)(&v));
            return;
        }
        Pose *pose = rig->pose;
        Vec3_3be00 p = pose->pos;
        pose->pos.x = p.x;
        pose->pos.y = p.y - 0.6625f;
        pose->pos.z = p.z;
        return;
    }
    if (((char)((owners::ThisWrap_00092de0 *)pad)->FUN_00092de0(3))) {
        ((owners::Quaternion_22b220 *)&l)->FUN_0022b220(0.0f, 0.0f, -0.69813174f);
        q = rig->skeleton->qa;
        FUN_0022b080(&q, &q, &l);
        rig->skeleton->qa = q;

        q = rig->skeleton->qc;
        l = ref->skeleton->qc;
        if (!q.FUN_000375f0(&l, 1e-05f)) {
            ((owners::Quaternion_22b220 *)&l)->FUN_0022b220(0.0f, 0.0f, 0.5235988f);
            FUN_0022b080(&q, &q, &l);
            rig->skeleton->qc = q;
        }
        int s = state;
        if (s > 0 && s <= 2) {
            Vec3_3be00 p = rig->pose->pos;
            Vec3_3be00 v;
            v.x = p.x;
            v.y = p.y + 0.6375f;
            v.z = p.z;
            ((owners::C_34d80 *)rig)->FUN_00034d80(2, (unsigned int *)(Vec3_3be00 *)(&v));
        }
    }
}
} // namespace fn_0003be00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0003d1c0 FUN_0003d1c0 (396 B): equivalent/0x0003d1c0.cpp [wrapped: conflict: FUN_00059a40]
// sym: ?FUN_0003d1c0@Owner_3d1c0@fn_0003d1c0@@QAE_NPAUEvent_3d1c0@2@PAXPAUV3_3d1c0@2@2@Z @79f71338eaeb @wa43ebe45a52f
namespace fn_0003d1c0 {
// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 24/26, incomplete)
// FUN_0003d1c0 @ 0x0003d1c0
struct V3_3d1c0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct Target_3d1c0 {
    char pad0[0x74];
    V3_3d1c0 dir;
    char pad80[0x114 - 0x80];
    int f114;
    char pad118[0x140 - 0x118];
    int state140;
    char pad144[0x20b0 - 0x144];
    int f20b0;
};

struct Event_3d1c0 {
    char pad0[8];
    Target_3d1c0 *target;
    int kind;
};

struct Sink_3d1c0 {
    void FUN_002226f0(V3_3d1c0 *v);
};

struct Owner_3d1c0 {
    char pad0[0x10];
    void *obj10;
    char pad14[0x74 - 0x14];
    V3_3d1c0 dir;
    char pad80[0x334 - 0x80];
    Target_3d1c0 *t334;
    Target_3d1c0 *t338;
    char pad33c[0x1b24 - 0x33c];
    int f1b24;
    bool FUN_0003d1c0(Event_3d1c0 *ev, void *unused, V3_3d1c0 *in, V3_3d1c0 *out);
};

Sink_3d1c0 *__fastcall FUN_00059a40(void *obj);
extern "C" char __cdecl FUN_00018960(float a, float b, float eps);

bool Owner_3d1c0::FUN_0003d1c0(Event_3d1c0 *ev, void *unused, V3_3d1c0 *in, V3_3d1c0 *out)
{
    if (!ev)
        return false;
    Sink_3d1c0 *sink = FUN_00059a40(obj10);
    if (ev->kind == 1) {
        Target_3d1c0 *t = ev->target;
        if (!t || t->f20b0 || t->state140 == 2 || t == t334 || t == t338 || f1b24 > 0)
            return false;
        V3_3d1c0 a;
        a.x = dir.x;
        a.y = dir.y;
        a.z = dir.z;
        a.FUN_0022d110();
        V3_3d1c0 b;
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        b.x = t->dir.x;
        b.y = t->dir.y;
        b.z = t->dir.z;
        if (FUN_00018960(b.FUN_0022d110(), 0.0f, 1e-05f))
            return false;
        if (b.z * a.z + b.y * a.y + b.x * a.x > 0.5f)
            return false;
    } else if (ev->kind == 5) {
        if (ev->target->f114)
            return false;
    }
    V3_3d1c0 tmp;
    tmp.x = in->x;
    tmp.y = in->y;
    tmp.z = in->z;
    if (out->y <= in->y)
        tmp.y = out->y;
    sink->FUN_002226f0(&tmp);
    out->x = tmp.x;
    out->y = tmp.y;
    out->z = tmp.z;
    return true;
}
} // namespace fn_0003d1c0

namespace fn_f35f7bdf {

// 0x0003d350 FUN_0003d350 (2288 B): equivalent/0x0003d350.cpp
// sym: ?Update@Fighter_3d350@fn_f35f7bdf@@QAEXPAUArg1_3d350@2@M@Z @0fedb5ba84de @w6fc397a7a55c
// STATUS: equivalent (tools/equiv.py level 3: 3148 inputs, branch coverage 90/90; Wine build 3115 inputs, 88/90)
// FUN_0003d350 @ 0x0003d350
void Fighter_3d350::Update(Arg1_3d350 *a1, float a2)
{
    if (f1b20 > 0)
        return;
    Mover_3d350 *mv = f10->FUN_00059a40();
    V3_3d350 p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    f10->FUN_00059a50(&p);
    V3_3d350 q = p44;
    Hit202 *a1f24 = a1->f24;
    V3_3d350 pc;
    hulk_freg len;
    V3_3d350 hitV;
    if (f338 != 0) {
        V3_3d350 c;
        c.x = 0;
        c.y = 0;
        c.z = 0;
        f338->FUN_000350c0(&c);
        V3_3d350 c2 = c;
        V3_3d350 pcopy = p;
        V3_3d350 d;
        d.x = p.x - c2.x;
        d.y = p.y - c2.y;
        d.z = p.z - c2.z;
        len = d.FUN_0022d110();
        if (!(len > 0.0f))
            return;
        f338->FUN_00035fa0(0);
        FUN_00035fa0(0);
        V3_3d350 hitPos;
        V3_3d350 hitNormal;
        if (FUN_002027c0(&c2, &pcopy, 0, 0, &hitPos, &hitNormal, 0, 0)) {
            hitV = hitPos;
            if (hitNormal.y < 0.5f) {
                if (len > 0.1f) {
                    hitV.x = hitPos.x - c2.x;
                    hitV.y = hitPos.y - c2.y;
                    hitV.z = hitPos.z - c2.z;
                    double L = hitV.FUN_0022d110();
                    double sc = L - 0.1f;
                    // x87: the x product stays in st(0) for the add; y and z go through their rounded frame copies
                    hulk_freg hx = hitV.x * sc;
                    volatile float hy = hitV.y * sc;
                    volatile float hz = hitV.z * sc;
                    hitV.y = hy;
                    hitV.z = hz;
                    hitV.x = hx + c2.x;
                    hitV.y = hitV.y + c2.y;
                    hitV.z = hitV.z + c2.z;
                } else {
                    hitV = c;
                }
            }
            mv->FUN_002226f0(&hitV);
        }
        FUN_00035fa0(1);
        f338->FUN_00035fa0(1);
        return;
    }

    if (f14c == 0 && f144 == 0) {
        if (p.FUN_0022d2b0(&q, 1e-05f))
            return;
    }
    if (f128 != 0)
        return;

    V3_3d350 dd;
    dd.x = p.x - q.x;
    dd.y = p.y - q.y;
    dd.z = p.z - q.z;
    hulk_freg lenSq = dd.x * dd.x + dd.y * dd.y + dd.z * dd.z;
    Fighter_3d350 *cur = a1->f20->f124;
    union { unsigned int w; unsigned char b; } flag34;
    if (cur == this || f334 == cur || f338 == cur)
        flag34.b = 1;
    else
        flag34.b = 0;
    char al = (f334 != 0 || f338 != 0) ? 1 : 0;
    int bl = flag34.b;
    int ebx;
    if (!bl) {
        Gear_3d350 *g = f11c;
        ebx = 0;
        if (!g->b10 && mode != 3 && al == 0) {
            if (lenSq < 1.0f)
                return;
        }
    } else {
        ebx = 0;
    }
    Gear_3d350 *gear = f11c;
    hulk_freg g30 = gear->f30;
    hulk_freg g34 = gear->f34;
    V3_3d350 r = r68;
    V3_3d350 P3 = p;
    if (mode == 1 || mode == 2) {
        P3.y = g30 * 0.5f + P3.y;
    } else if (mode == 4) {
        V3_3d350 s;
        s.x = 0;
        s.y = 0;
        s.z = 0;
        FUN_00035550(&s);
        ((owners::Vec3_11160 *)&P3)->FUN_00011160(-g34, (const owners::Vec3_11160 *)(const V3_3d350 *)(&s));
    }
    V3_3d350 D;
    D.x = P3.x - r.x;
    D.y = P3.y - r.y;
    D.z = P3.z - r.z;
    hulk_freg dl = D.FUN_0022d110();
    V3_3d350 U = D;
    P3.x = D.x * dl;
    P3.y = D.y * dl;
    P3.z = D.z * dl;
    if (mode != 4)
        U.y = 0;
    hulk_freg ux = U.x * g34;
    hulk_freg uy = U.y * g34;
    hulk_freg uz = U.z * g34;
    P3.x = ux + P3.x;
    P3.y = uy + P3.y;
    P3.z = uz + P3.z;
    P3.x = P3.x + r.x;
    P3.y = r.y + P3.y;
    P3.z = P3.z + r.z;
    D.x = P3.x - r.x;
    D.y = P3.y - r.y;
    D.z = P3.z - r.z;
    hulk_freg len2 = D.FUN_0022d110();
    if (!D.FUN_000375a0())
        return;

    V3_3d350 o1, o2;
    if (a1f24->FUN_00202460(&r, &D, len2, !flag34.b, &o1, &o2, 0, 0)) {
        if (mode == 3 && o2.y > 0.5f) {
            V3_3d350 H = o1;
            mv->FUN_002226f0(&H);
            return;
        }
        V3_3d350 W = q;
        if (mode != 4) {
            if (p.y <= q.y)
                W.y = p.y;
        }
        mv->FUN_002226f0(&W);
        p = W;
        V3_3d350 N = o2;
        if (!(mode == 3 && o2.y < 0.0f)) {
            N.y = 0;
            N.FUN_0022d110();
        }
        double s = a2 * 10.0f; // stays in a register
        volatile float py = s * N.y; // y and z products are rounded frame copies in the original
        volatile float pz = N.z * s;
        f1c0 = N.x * s + f1c0;
        f1c4 = py + f1c4;
        f1c8 = pz + f1c8;
        return;
    }

    Ex *ob = FUN_00202f00();
    DAT_004d2a3c = 2;
    (*(char*)&DAT_004d2a40) = 0;
    (*(char*)&DAT_00554c1c) = 1;
    DAT_00554c18 = 0;
    Ee *world = a1->f10->f8;
    f12c->f74->b72 = 0;
    if (f128)
        ((Obj1d72_3d350 *)((owners::C_1d72e0 *)f128)->FUN_001d72e0())->f74->b72 = 0;
    if (f334) {
        f334->f12c->f74->b72 = 0;
        if (f334->f128)
            ((Obj1d72_3d350 *)((owners::C_1d72e0 *)(f334->f128))->FUN_001d72e0())->f74->b72 = 0;
        f334->FUN_00035fa0(0);
    }
    if (f338) {
        f338->f12c->f74->b72 = 0;
        if (f338->f128)
            ((Obj1d72_3d350 *)((owners::C_1d72e0 *)(f338->f128))->FUN_001d72e0())->f74->b72 = 0;
        f338->FUN_00035fa0(0);
    }
    FUN_00035fa0(0);
    if (world->FUN_002ee140(ob, &r, &P3, 0)) {
        if (ob->f8->f0 > 0.0f)
            FUN_0003d1c0(ob->f8->f4->f18, flag34.w, &q, &p);
    }
    FUN_00035fa0(1);
    if (f338) {
        f338->FUN_00035fa0(1);
        if (f338->f128)
            ((Obj1d72_3d350 *)((owners::C_1d72e0 *)(f338->f128))->FUN_001d72e0())->f74->b72 = 1;
        f338->f12c->f74->b72 = 1;
    }
    if (f334) {
        f334->FUN_00035fa0(1);
        if (f334->f128)
            ((Obj1d72_3d350 *)((owners::C_1d72e0 *)(f334->f128))->FUN_001d72e0())->f74->b72 = 1;
        f334->f12c->f74->b72 = 1;
    }
    if (f128)
        ((Obj1d72_3d350 *)((owners::C_1d72e0 *)f128)->FUN_001d72e0())->f74->b72 = 1;
    f12c->f74->b72 = 1;
}


// 0x0003dc40 FUN_0003dc40 (178 B): matches/0x0003dc40.cpp
// sym: ?FUN_0003dc40@CCharacter_3dc40@fn_f35f7bdf@@QAEXII@Z
void CCharacter_3dc40::FUN_0003dc40(unsigned int a, unsigned int b) {
    Receiver_3dc40* receiver = source->FUN_00059a40();
    FUN_0003ba60(a, b);
    FUN_000365f0(a, b);
    if (node && node->child) {
        if (flag) {
            Matrix matrix;
            FUN_00035160(&matrix);
            node->FUN_001d6b60(matrix, 0);
            ((owners::X_1c4d60 *)(node->child))->FUN_001c4d60((unsigned int *)(Matrix *)(&matrix));
        } else {
            unsigned int result = node->slot15();
            receiver->FUN_002226e0(result);
        }
    }
    cached = state->value;
}


// 0x0003dd00 FUN_0003dd00 (110 B): equivalent/0x0003dd00.cpp
// sym: ?FUN_0003dd00@CCharacter_3dd00@fn_f35f7bdf@@QAEX_N@Z @78360e8e6a25 @wc47096667716
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0003dd00 @ 0x0003dd00
void CCharacter_3dd00::FUN_0003dd00(bool enable)
{
    enabled = enable;
    if (enable) {
        enableDepth++;
        refs++;
        owner->FUN_00059a40()->FUN_00222b90(true);
        subB4.FUN_00232240();
        subDC.FUN_00232240();
        FUN_000393c0();
    } else {
        enableDepth--;
        refs--;
    }
}


// 0x0003dd70 FUN_0003dd70 (1319 B): equivalent/0x0003dd70.cpp
// sym: ?FUN_0003dd70@Host_3dd70@fn_f35f7bdf@@QAEXPAUArg0@2@M@Z @1f4f1e126ba9 @w8582197897cf
// STATUS: equivalent (tools/equiv.py level 3: 20072 inputs, branch coverage 68/68)
// FUN_0003dd70 @ 0x0003dd70
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void Host_3dd70::FUN_0003dd70(Arg0 *a0, float dt)
{
    if (p11c == 0)
        return;
    Frame_3dd70 f;
    t = dt + t;
    f.v.x = 0.0f;
    f.v.y = 0.0f;
    f.v.z = 0.0f;
    p10->FUN_00059a50(&f.v);
    float tcur = t;
    Cfg_3dd70 *cfg = a0->cfg;
    f.lim = cfg->lim;
    f.vy = f.v.y;
    f.t48 = t48;

    bool update = false;
    bool cross = false;
    if (tcur > 1.0f) {
        if (f.v.y <= f.lim) {
            if (f.t48 > f.lim)
                cross = true;
        }
        if (!cross) {
            if (f.v.y >= f.lim) {
                if (f.t48 < f.lim)
                    cross = true;
            }
        }
    }
    if (cross) {
        update = true;
    } else {
        hulk_freg sumsq = (w74.x * w74.x + w74.y * w74.y) + w74.z * w74.z;
        if (sumsq > 0.0f) {
            P11c *pc = p11c;
            float s0 = pc->f30;
            float a;
            float s0v;
            if (mode > 0 && mode <= 2) {
                a = f.v.y;
                s0v = s0 + f.v.y;
            } else {
                s0 = s0 * 0.5f;
                a = f.v.y - s0;
                s0v = s0 + f.v.y;
            }
            f.sc = s0v;
            if (a < f.lim && s0v > f.lim) {
                if (t > 1.0f) {
                    update = true;
                } else {
                    f.d.x = last.x - f.v.x;
                    f.d.iy = 0;
                    f.d.z = last.z - f.v.z;
                    float c2 = pc->f30 + pc->f30;
                    f.sc = c2;
                    float len = f.d.FUN_000111f0();
                    if ((double)f.sc * (double)f.sc < (double)len)
                        update = true;
                }
            }
        }
    }

    if (update) {
        t = 0.0f;
        last.ix = f.v.ix;
        last.iy = f.v.iy;
        last.iz = f.v.iz;
        const Id64_3dd70 *id = &cfg->id;
        if ((id->lo | id->hi) != 0) {
            Singleton_3dd70 *sg = FUN_0027f250();
            f.mat.FUN_0022b980();
            f.mat.m[12] = f.v.x;
            f.mat.m[13] = f.lim;
            f.mat.m[14] = f.v.z;
            float sc;
            if (p11c == 0) {
                sc = 1.0f;
            } else {
                float c1c = p11c->f1c;
                if (c1c < 1000.0f)
                    sc = c1c * 0.001f;
                else if (c1c < 10000.0f)
                    sc = (c1c - 1000.0f) * 0.00011111111f + 1.0f;
                else if (c1c < 100000.0f)
                    sc = ((c1c - 10000.0f) * 1.1111111e-05f + 1.0f) * 2.0f;
                else
                    sc = 4.0f;
            }
            f.sc = sc;
            f.four = 4.0f;
            f.half = 0.5f;
            float r = FUN_000186b0(&f.sc, &f.half, &f.four);
            f.sc = r;
            sg->FUN_00283a40(id, &f.mat, -1.0f, r);
        }
        const char *name = cfg->name;
        if (*name)
            a0->notify->FUN_001ebfd0(this, name);
    }

    if (a0->p20->host == this) {
        if (!(f.vy <= f.lim))
            return;
        if (!(f.vy < f.t48))
            return;
        if (b1a39) {
            if (!(f.lim - 10.0f > f1a88))
                return;
        }
    } else {
        if (!(f.vy <= f.lim))
            return;
        if (!(f.t48 > f.lim))
            return;
    }

    int saved = FUN_00266da0(0xd);
    Emitter_3dd70 *emit = p11c->emit;
    if (emit != 0) {
        bool found = false;
        void *cur = head.first;
        while (cur != 0) {
            if (cur == (void *)emit) {
                found = true;
                break;
            }
            cur = *(void **)((char *)cur + 0x14);
        }
        if (!found) {
            f.d.ix = home.ix;
            f.d.iy = home.iy;
            f.d.iz = home.iz;
            f.out.x = 0.0f;
            f.out.y = 0.0f;
            f.out.z = 0.0f;
            if (a0->finder->FUN_001fe380(&f.v, &f.out)) {
                f.d.ix = f.out.ix;
                f.d.iy = f.out.iy;
                f.d.iz = f.out.iz;
            }
            f.desc.FUN_00059820();
            f.desc.rel.x = f.d.x - f.v.x;
            f.desc.f5c = 1.0f;
            f.desc.rel.y = f.d.y - f.v.y;
            f.desc.rel.z = f.d.z - f.v.z;
            void *mem = FUN_0008d690(0xb0);
            CFightParamsCollision_3dd70 *o = 0;
            if (mem)
                o = ((CFightParamsCollision_3dd70 *)mem)->FUN_000598e0(*(void **)p10, &f.desc);
            o->v0();
            Emitter_3dd70 *em2 = emit->v8(o, 0);
            if (em2 != 0) {
                if (em2->FUN_00231a40(&head, o)) {
                    head.FUN_00232240();
                    FUN_00037000();
                    l_b4.FUN_00232240();
                }
                em2->FUN_00231ad0(&head, o, 0x80000000u);
            }
            o->v1();
            f.desc.FUN_00059300();
        }
    }
    FUN_00266da0(saved);
}


// 0x0003e2a0 FUN_0003e2a0 (924 B): equivalent/0x0003e2a0.cpp
// sym: ?FUN_0003e2a0@CCharacter_3e2a0@fn_f35f7bdf@@QAEXHUVec3_3e2a0@2@MH_N@Z @0191f8adbd5b @w434ad259d568
// STATUS: equivalent (tools/equiv.py level 3: 1287 inputs, branch coverage 22/22)
// FUN_0003e2a0 @ 0x0003e2a0
void CCharacter_3e2a0::FUN_0003e2a0(int a, Vec3_3e2a0 off, float scale, int unused, bool enable)
{
    if (!enable)
        return;
    if (scale <= 0.0f)
        return;

    Vec3_3e2a0 pos;
    Mat_3e2a0 m;

    off.x = off.x * scale;
    off.y = off.y * scale;
    off.z = off.z * scale;
    anchor->FUN_00059a50(&pos);
    pos.x = pos.x + off.x;
    pos.y = pos.y + off.y;
    pos.z = pos.z + off.z;
    FUN_00035250(&pos);

    if (matSource) {
        m = *matSource->FUN_001c5e60();
        m.t.x = m.t.x + off.x;
        m.t.y = m.t.y + off.y;
        m.t.z = m.t.z + off.z;
        ((owners::Obj_1c5e40 *)matSource)->FUN_001c5e40((hulk_uintptr)(Mat_3e2a0 *)(&m));
    } else if (posSource) {
        pos = *posSource->FUN_001d6b40();
        pos.x = pos.x + off.x;
        pos.y = pos.y + off.y;
        pos.z = pos.z + off.z;
        posSource->FUN_001d7810(pos);
        posSource->FUN_001d8fc0(scale * 1000.0f);
    } else {
        return;
    }

    MatList* list = mats;
    int n = list->count;
    for (int i = 0; i < n; i++) {
        m = list->data[i];
        m.t.x = m.t.x + off.x;
        m.t.y = m.t.y + off.y;
        m.t.z = m.t.z + off.z;
        list->data[i] = m;
    }

    if (mode == 1) {
        Target_3e2a0* t;
        if (matSource)
            t = matSource->target;
        else
            t = posSource->target;
        if (t)
            ((owners::Blend_1c5080 *)t)->FUN_001c5080((*(float*)&DAT_00421894), 1.5f);
    }

    FUN_0003ba60(a, scale);
    FUN_000365f0(a, scale);
}

} // namespace fn_f35f7bdf

// 0x0003e640 FUN_0003e640 (310 B): equivalent/0x0003e640.cpp [wrapped: conflict: World]
// sym: ?FUN_0003e640@Detector@fn_0003e640@@QAEXXZ @ffa4cfabd28e @w641b6598d84e
namespace fn_0003e640 {
// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 24/26, incomplete)
// FUN_0003e640 @ 0x0003e640
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

struct Region_3e640 {
    char data[1];
};

struct Target_3e640 {
    int FUN_000243d0();
};

struct Detector;

struct Probe_3e640 {
    bool FUN_000242d0(Detector *d);
    int FUN_000243d0();
    hulk_freg FUN_00029f20(Region_3e640 *r, int target);
};

struct World {
    char pad0[0x20];
    Probe_3e640 *probe;
};


struct Detector {
    char pad0[0x1d78];
    char locked;
    char flag;
    char pad1d7a[2];
    int mode;
    int result;
    char pad1d84[0x20b8 - 0x1d84];
    Region_3e640 region;
    void FUN_0003e640();
};

void Detector::FUN_0003e640()
{
    if (locked == 1) {
        flag = 0;
        return;
    }
    Probe_3e640 *p = DAT_004dd700->probe;
    if (!p)
        return;
    if (p->FUN_000242d0(this)) {
        flag = 0;
        return;
    }
    if (mode == 0x7fffffff) {
        result = 0x7fffffff;
        return;
    }
    int target = p->FUN_000243d0();
    if (!target)
        return;
    float score = p->FUN_00029f20(&region, target);
    if (score > DAT_0048f5b0[mode]) {
        if (mode == 0)
            result = flag ? 1 : 2;
        else if (mode == 1)
            result = flag ? 3 : 4;
        else if (mode == 2)
            result = flag ? 7 : 8;
        else
            result = 0x7fffffff;
    } else {
        if (mode == 0)
            result = flag ? 5 : 10;
        else if (mode == 1)
            result = flag ? 6 : 11;
        else if (mode == 2)
            result = flag ? 9 : 12;
        else
            result = 0x7fffffff;
    }
}
} // namespace fn_0003e640
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35f7bdf {

// 0x0003e780 FUN_0003e780 (647 B): equivalent/0x0003e780.cpp
// sym: ?FUN_0003e780@Actor_3e780@fn_f35f7bdf@@QAE_NPAXPAUVec3_3e780@2@MPA_N2@Z @8b5a72ad35f4 @wf911fe0441ed
// STATUS: equivalent (tools/equiv.py level 3: 19983 inputs, branch coverage 34/34)
// FUN_0003e780 @ 0x0003e780
bool Actor_3e780::FUN_0003e780(void *a1, Vec3_3e780 *target, float maxDist, bool *outA, bool *outB)
{
    *outA = false;
    *outB = false;
    if (index == 0xffff)
        return false;

    Frame_3e780 fr;
    Vec3_3e780 &P = fr.P;
    Vec3_3e780 &D = fr.D;
    Vec3_3e780 &W = fr.W;
    Vec3_3e780 &tmp = fr.tmp;
    P = elems->items[index].pos;
    if (((CCharacter_3e780*)(hasher))->FUN_000443c0() == FUN_0027b020("tank"))
        P.y = P.y + 1.0f;

    D.x = target->x - P.x;
    D.y = 0.0f;
    D.z = target->z - P.z;
    float &dist = fr.dist;
    dist = (float)sqrt((double)(D.z * D.z + D.x * D.x));
    D.FUN_0022d110();

    Anchor_3e780 *g = owner->FUN_00059a40();
    if (g) {
        g->loc.FUN_00222120(&tmp);
        W.x = tmp.x;
        W.z = tmp.z;
    }
    W.y = 0.0f;
    W.FUN_0022d110();

    float &dot = fr.dot;
    dot = W.z * D.z + W.x * D.x + W.y * D.y;
    float ang = angle * 0.008726646f;
    if (gesture) {
        unsigned __int64 gid = gesture->id;
        if (gid == FUN_0027b020("gesture_3"))
            ang = angle;
    }
    double c = cos((double)ang);

    if (!((double)dot > c)) {
        ang = (float)fabs((double)dot - c);
        if (!(ang <= 1e-05f)) {
            if (!(dist < 3.0f))
                return false;
        }
    }
    if ((double)dot < c)
        *outB = true;

    if (!(dist <= maxDist))
        return false;

    if (slot->holder)
        slot->holder->flag = 0;
    FUN_00035fa0(0);

    FlagHolder *saved = 0;
    char savedFlag = 0;
    if (probe) {
        Slot_3e780 *s = ((Slot_3e780 *)((owners::C_1d72e0 *)probe)->FUN_001d72e0());
        saved = s->holder;
        if (saved) {
            savedFlag = saved->flag;
            saved->flag = 0;
        }
    }
    bool result = FUN_00036b10(a1, &P, target, &fr.Z, &tmp, outA, &ang);
    if (slot->holder)
        slot->holder->flag = 1;
    FUN_00035fa0(1);
    if (saved)
        saved->flag = savedFlag;
    return result;
}

} // namespace fn_f35f7bdf

// 0x0003ebb0 FUN_0003ebb0 (77 B): matches/0x0003ebb0.cpp
// sym: ?FUN_0003ebb0@ClampOwner_3ebb0@owners@@QAEMH@Z
// data: gOne_3ebb0 = DAT_003f32dc, gZero_3ebb0 = DAT_003f32e0
float owners::ClampOwner_3ebb0::FUN_0003ebb0(int key) {
    float value = mValue;
    if (key != mKey)
        return DAT_003f32e0;
    if (value >= DAT_003f32e0 && value <= DAT_003f32dc)
        return value;
    if (value > DAT_003f32dc)
        return DAT_003f32dc;
    return DAT_003f32e0;
}


// 0x0003ec00 FUN_0003ec00 (106 B): equivalent/0x0003ec00.cpp
// sym: ?FUN_0003ec00@Progress_3ec00@owners@@QAEMH@Z @23c9ea524210 @wc6e9c5801719
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0003ec00 @ 0x0003ec00
float owners::Progress_3ec00::FUN_0003ec00(int k)
{
    float v = value;
    if (k != key) {
        value = 0.0f;
        return 0.0f;
    }
    if (v >= 0.0f && v <= 1.0f) {
        value = 0.0f;
        return v;
    }
    value = 0.0f;
    if (v > 1.0f)
        return 1.0f;
    return 0.0f;
}

namespace fn_f35f7bdf {

// 0x0003ec70 FUN_0003ec70 (37 B): matches/0x0003ec70.cpp
// sym: ?Set@CCharacter_3ec70@fn_f35f7bdf@@QAEXPBUPart@2@@Z
void CCharacter_3ec70::Set(const Part* p) {
    Part* q = &part;
    q->Copy_0027af70(p);
    q->a = p->a;
    q->b = p->b;
}


// 0x0003eca0 FUN_0003eca0 (155 B): equivalent/0x0003eca0.cpp
// sym: ?FUN_0003eca0@Table_3eca0@fn_f35f7bdf@@QAEMPBD@Z @a369de1cc064 @w0b74eee5ce99
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 10/10)
// FUN_0003eca0 @ 0x0003eca0
// FUN_0003eca0: look up a named value by key, -1 when absent
float Table_3eca0::FUN_0003eca0(const char *name)
{
    if (!((*(unsigned int*)&DAT_004dc2d0) & 1)) {
        (*(unsigned int*)&DAT_004dc2d0) |= 1;
        (*(Key_3eca0*)&DAT_004dc2c8).FUN_0027af00();
        atexit(FUN_00363ba0);
    }
    ((owners::Target_27b040 *)&((*(Key_3eca0*)&DAT_004dc2c8)))->FUN_0027b040((hulk_uintptr)name);
    for (int i = 0; i < count; i++) {
        if (entries[i].lo == (*(Key_3eca0*)&DAT_004dc2c8).lo && entries[i].hi == (*(Key_3eca0*)&DAT_004dc2c8).hi)
            return entries[i].value;
    }
    return -1.0f;
}

} // namespace fn_f35f7bdf

// 0x0003ed40 FUN_0003ed40 (271 B): equivalent/0x0003ed40.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_0003ed40@@QAEXPBDM@Z @ff7eff98d449 @w293b5b149cbd
namespace fn_0003ed40 {
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 14/14)
// FUN_0003ed40 @ 0x0003ed40

struct Key_3ed40 { unsigned lo, hi; void FUN_0027af00();  void FUN_0027af70(const Key_3ed40*); };
extern "C" void __cdecl FUN_00363bb0();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
int __cdecl _atexit(void (__cdecl*)());
#endif

struct Source_3ed40 { float FUN_000448b0(unsigned,unsigned); };
struct Entry_3ed40 { Key_3ed40 key; float value; unsigned unused; };
struct Object { char pad0[0x11c]; Source_3ed40* source; char pad1[0x1ba8-0x120]; Entry_3ed40 entries[14]; int count; void target(const char*,float); };
void Object::target(const char* name,float value) {
 if (!(DAT_004dc2e0 & 1)) { DAT_004dc2e0 |= 1; (*(Key_3ed40*)&DAT_004dc2d8).FUN_0027af00(); _atexit(FUN_00363bb0); }
 ((owners::Target_27b040 *)&((*(Key_3ed40*)&DAT_004dc2d8)))->FUN_0027b040((hulk_uintptr)name);
 int n=count;
 if(n>0) { unsigned lo=(*(Key_3ed40*)&DAT_004dc2d8).lo, hi=(*(Key_3ed40*)&DAT_004dc2d8).hi; for(int i=0;i<count;++i) { if(entries[i].key.lo==lo && entries[i].key.hi==hi) { if(value == -2.0f) entries[i].value=source->FUN_000448b0(lo,hi); else entries[i].value=value; return; } } }
 if(n<14) { entries[n].key.FUN_0027af70(((Key_3ed40*)&DAT_004dc2d8)); entries[count].value=value; ++count; }
}
} // namespace fn_0003ed40

namespace fn_f35f7bdf {

// 0x0003ee50 FUN_0003ee50 (30 B): matches/0x0003ee50.cpp
// sym: ?f@Owner_3ee50@fn_f35f7bdf@@QAEXXZ
void Owner_3ee50::f() {
    if (item) {
        item->B();
        item = 0;
    }
}


// 0x0003ee70 FUN_0003ee70 (44 B): matches/0x0003ee70.cpp
// sym: ?Set@Owner_3ee70@fn_f35f7bdf@@QAEXPAVItem_3ee70@2@@Z
void Owner_3ee70::Set(Item_3ee70* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}


// 0x0003eea0 FUN_0003eea0 (141 B): matches/0x0003eea0.cpp
// sym: ?Init@Function7_3eea0@fn_f35f7bdf@@QAEPAV12@PBDP8Owner_3eea0@2@AEXXZ@Z
// FUN_0003eea0 @ 0x0003eea0
Function7_3eea0* Function7_3eea0::Init(const char* name, Fn_3eea0 fn) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 7);
    vptr = (void*)DAT_003f5d3c;
    func = fn;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f35f7bdf

// 0x0003ef30 Function7<void,int,float,float,float,float,float,float>::vfunc_2 (30 B): matches/0x0003ef30.cpp
// sym: ?vfunc_2@?$Function7@XHMMMMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Function7<void, int, float, float, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0003ef50(a, b, c, this->f_1c);
}

namespace fn_f35f7bdf {

// 0x0003ef50 FUN_0003ef50 (84 B): equivalent/0x0003ef50.cpp
// sym: ?FUN_0003ef50@fn_f35f7bdf@@YAXIPBIIP6AXIIIIIII@Z@Z @a1f5ef63af23 @wc85cfe30d7a7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0003ef50 @ 0x0003ef50
void __cdecl FUN_0003ef50(DWORD unused, const DWORD* args, DWORD unused2, Callback callback) {
    callback(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
}


// 0x0003efb0 FUN_0003efb0 (89 B): matches/0x0003efb0.cpp
// sym: ??0Function3_3efb0@fn_f35f7bdf@@QAE@PBDP8Owner_3efb0@1@AEXXZ@Z
Function3_3efb0::Function3_3efb0(const char* a, Fn_3efb0 b) : FUN_001d0480(a, 3) {
    vptr = (void*)DAT_003f5d4c;
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e0f0)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_f35f7bdf

// 0x0003f010 Function3<void,const_char_*,const_char_*,float>::vfunc_2 (26 B): matches/0x0003f010.cpp [wrapped: conflict: Function; Function3]
// sym: ?vfunc_2@Function3@fn_0003f010@@UAEXHPAXH@Z
namespace fn_0003f010 {
class Function {
  public:
    char pad[0x18];
    void(__cdecl* mFn)(const char*, const char*, float);
};
class Function3 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int, void*, int);
};
void Function3::vfunc_2(int, void* arg, int) {
    volatile unsigned long* p = (volatile unsigned long*)arg;
    hulk_ulongptr a = p[0];
    unsigned long c = p[2];
    hulk_ulongptr b = p[1];
    mFn((const char*)a, (const char*)b, *(float*)&c);
}
} // namespace fn_0003f010


// 0x0003f030 Function7<void,int,float,float,float,float,float,float>::vfunc_0 (30 B): matches/0x0003f030.cpp
// sym: ??_G?$Function7@XHMMMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function7<void, int, float, float, float, float, float, float>::~Function7() {}
#if defined(HULK_PTR64)
template class Function7<void, int, float, float, float, float, float, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x3f030)
#endif


// 0x0003f050 Function3<void,const_char_*,const_char_*,float>::vfunc_0 (30 B): matches/0x0003f050.cpp
// sym: ??_G?$Function3@XPBDPBDM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Function3<void, const char *, const char *, float>::~Function3() {}
#if defined(HULK_PTR64)
template class Function3<void, const char *, const char *, float>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x3f050)
#endif


// 0x0003f090 FUN_0003f090 (841 B): equivalent/0x0003f090.cpp [wrapped: conflict: CCharacter; FUN_001c3d90; World]
// sym: ?FUN_0003f090@CCharacter@fn_0003f090@@QAEXXZ @9b89f5e266b3 @w27161814913c
namespace fn_0003f090 {
// STATUS: equivalent (tools/equiv.py level 3: 564 inputs, branch coverage 53/54, incomplete)
// FUN_0003f090 @ 0x0003f090
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



class Releasable_3f090 {
public:
    virtual void v0();
    virtual void release();
};

class Wide {
public:
    virtual void v0();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct Id64_3f090 {
    unsigned int lo, hi;
    void FUN_0027af10(unsigned int lo, unsigned int hi);
    void FUN_0027af50() throw();
};

struct Id16 {
    Id64_3f090 id;
    char pad8[8];
    void FUN_0027af50() throw();
};

struct Pair2 {
    char pad0[8];
    int f8;
    int fc;
    char pad10[0x148 - 0x10];
    int f148;
};

struct Linked_3f090 {
    virtual void v0();
    virtual void release();
    char pad4[4];
    int f8;
    int fc;
};

struct Linked2 {
    virtual void v0();
    virtual void release();
    char pad4[0x144];
    int f148;
};

struct SlotOwner {
    void FUN_001e5bb0(Releasable_3f090 *r, int flag);
};

struct World {
    char padx[0xc];
    SlotOwner *f0c;
};

struct Handle_3f090 {
    void FUN_001c3b30(Id64_3f090 *id);
};
Handle_3f090 *FUN_001c3d90();

struct Registry_3f090 {
    void FUN_001b4140(void *owner);
};
extern "C" Registry_3f090 *FUN_001b6580();

struct Slot_3f090 {
    Releasable_3f090 *a;
    Releasable_3f090 *b;
    char pad8[0x28 - 8];
};

struct Item50 {
    Releasable_3f090 *obj;
    char pad4[0x4c];
};

struct SubObj {
    char data[0x28];
    void FUN_002325f0() throw();
};

class CCharacter {
public:
    virtual void v0_00038290();
    virtual void v1_000382a0();
    char pad04[4];
    unsigned int f08;
    unsigned int f0c;
    char pad10[0xb4 - 0x10];
    SubObj sub_b4;
    SubObj sub_dc;
    Releasable_3f090 *f104;
    Releasable_3f090 *f108;
    Releasable_3f090 *f10c;
    char pad110[0x11c - 0x110];
    Releasable_3f090 *f11c;
    Releasable_3f090 *f120;
    int f124;
    Linked2 *f128;
    Linked_3f090 *f12c;
    Releasable_3f090 *f130;
    char pad134[0x14c - 0x134];
    Releasable_3f090 *f14c;
    char pad150[0x328 - 0x150];
    Releasable_3f090 *f328;
    char pad32c[0x388 - 0x32c];
    Releasable_3f090 *f388;
    char pad38c[0x3a4 - 0x38c];
    Releasable_3f090 *f3a4;
    Item50 items[8];
    char pad628[0x638 - 0x628];
    Slot_3f090 slots[0x80];
    char pad1a38[0x1ad0 - 0x1a38];
    Releasable_3f090 *f1ad0;
    char pad1ad4[0x1b50 - 0x1ad4];
    Id64_3f090 id1b50;
    char pad1b58[0x1b98 - 0x1b58];
    Id64_3f090 id1b98;
    char pad1ba0[0x1ba8 - 0x1ba0];
    Id16 ids1ba8[14];
    char pad1c88[0x1c98 - 0x1c88];
    Id64_3f090 id1c98;
    Wide *f1ca0;
    Releasable_3f090 *f1ca4;
    char pad1ca8[0x1d68 - 0x1ca8];
    Id64_3f090 id1d68;
    Id64_3f090 id1d70;
    char pad1d78[0x2098 - 0x1d78];
    Id64_3f090 id2098;
    char pad20a0[0x2150 - 0x20a0];
    Id16 ids2150[16];
    char pad2250[0x2258 - 0x2250];
    Id16 ids2250[4];
    char pad2298[0x22b4 - 0x2298];
    Releasable_3f090 *f22b4;
    Id64_3f090 id22b8;
    char pad22c0[0x22e4 - 0x22c0];
    Releasable_3f090 *f22e4;

    void FUN_0003b620(int v);
    void FUN_0003acf0(int a, int b, int c, int d, int e, int f);
    void FUN_000393c0();
    void FUN_0027afd0();
    void FUN_0003f090();
};

void CCharacter::FUN_0003f090()
{
    new (this) CCharacter;
    World *w = DAT_004dd700;
    FUN_0003b620(0);
    if (f22e4) {
        f22e4->release();
        f22e4 = 0;
    }
    f1ca0->v7();
    f1ca0->release();
    if (f1ad0) {
        f1ad0->release();
        f1ad0 = 0;
    }
    SlotOwner *owner = w->f0c;
    for (int i = 0; i < 8; i++) {
        Releasable_3f090 *r = items[i].obj;
        if (r) {
            r->v0();
            FUN_0003acf0(i, 0, -1, 0, 0, 0);
            owner->FUN_001e5bb0(r, 1);
            r->release();
        }
    }
    if (f3a4) {
        f3a4->release();
        f3a4 = 0;
    }
    if (f22b4) {
        f22b4->release();
        f22b4 = 0;
    }
    if (f388) {
        f388->release();
        f388 = 0;
    }
    FUN_000393c0();
    if (f328) {
        f328->release();
        f328 = 0;
    }
    if (f14c) {
        f14c->release();
        f14c = 0;
    }
    FUN_001b6580()->FUN_001b4140(this);
    if (f130) {
        f130->release();
        f130 = 0;
    }
    if (f12c) {
        f12c->fc = 0;
        f12c->f8 = 0;
        if (f12c) {
            f12c->release();
            f12c = 0;
        }
    }
    if (f128) {
        f128->f148 = 0;
        owner->FUN_001e5bb0((Releasable_3f090 *)f128, 1);
    }
    if (f128) {
        f128->release();
        f128 = 0;
    }
    if (f124) {
        Id64_3f090 key;
        key.FUN_0027af10(f08, f0c);
        FUN_001c3d90()->FUN_001c3b30(&key);
        key.FUN_0027af50();
    }
    if (f120) {
        f120->release();
        f120 = 0;
    }
    if (f11c) {
        f11c->release();
        f11c = 0;
    }
    if (f108) {
        f108->release();
        f108 = 0;
    }
    if (f10c) {
        f10c->release();
        f10c = 0;
    }
    if (f104) {
        f104->release();
        f104 = 0;
    }
    if (f1ca4) {
        f1ca4->release();
        f1ca4 = 0;
    }

    id22b8.FUN_0027af50();
    int i;
    for (i = 3; i >= 0; i--)
        ids2250[i].FUN_0027af50();
    for (i = 15; i >= 0; i--)
        ids2150[i].FUN_0027af50();
    id2098.FUN_0027af50();
    id1d70.FUN_0027af50();
    id1d68.FUN_0027af50();
    id1c98.FUN_0027af50();
    for (i = 13; i >= 0; i--)
        ids1ba8[i].FUN_0027af50();
    id1b98.FUN_0027af50();
    id1b50.FUN_0027af50();
    for (i = 0x7f; i >= 0; i--) {
        if (slots[i].b) {
            slots[i].b->release();
            slots[i].b = 0;
        }
        if (slots[i].a) {
            slots[i].a->release();
            slots[i].a = 0;
        }
    }
    sub_dc.FUN_002325f0();
    sub_b4.FUN_002325f0();
    FUN_0027afd0();
}
} // namespace fn_0003f090
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0003f7b0 FUN_0003f7b0 (2027 B): equivalent/0x0003f7b0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Probe@Chara_3f7b0@fn_0003f7b0@@QAEDPAUV3_3f7b0@2@00000PAI@Z @eb4c92718384 @w1c33a8e009d0
namespace fn_0003f7b0 {
// STATUS: equivalent (tools/equiv.py level 3: 20092 inputs, branch coverage 71/72, incomplete)
// FUN_0003f7b0 @ 0x0003f7b0
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
extern "C" double __cdecl sin(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl cos(double);
#endif


struct V3_3f7b0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    void FUN_000111b0(const V3_3f7b0 *a, const V3_3f7b0 *b);
    void FUN_00011090();
};

void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (V3_3f7b0::*ctor)());

struct Info_3f7b0 {
    char pad00[0x16];
    unsigned char flags16;
};

struct Holder5 {
    char pad00[0x40];
    int f40;
    char pad44[0xec - 0x44];
    struct Checker_3f7b0 *chk;
};

struct HitObj_3f7b0 {
    char pad00[8];
    Holder5 *sub;
    int kind;
};

struct Checker_3f7b0 {
    char FUN_001d6000(int a);
};

struct Cfg_3f7b0 {
    char pad00[0x30];
    float f30;
    float radius;
};

struct Player_3f7b0 {
    char pad00[0x124];
    struct Chara_3f7b0 *current;
};

struct World {
    char pad00[0x20];
    Player_3f7b0 *player;
};


char FUN_002027c0(V3_3f7b0 *from, V3_3f7b0 *to, int a, int b, V3_3f7b0 *hitPos, V3_3f7b0 *hitNormal, HitObj_3f7b0 **hitObj, Info_3f7b0 **info);

struct Chara_3f7b0 {
    char pad00[0x11c];
    Cfg_3f7b0 *cfg;
    char pad120[0x140 - 0x120];
    int mode;
    char pad144[0x334 - 0x144];
    Chara_3f7b0 *ignoreA;
    Chara_3f7b0 *ignoreB;
    char pad33c[0x1b08 - 0x33c];
    char allowMiss;
    void FUN_00035fa0(int a);
    char Probe(V3_3f7b0 *p1, V3_3f7b0 *p2, V3_3f7b0 *out1, V3_3f7b0 *out2, V3_3f7b0 *d, V3_3f7b0 *n2, unsigned int *flags);
};

struct Frame_3f7b0 {
    V3_3f7b0 n;               // 0x00
    char pad0c[3];
    char found;         // 0x0f
    int i;              // 0x10
    int count;          // 0x14
    union {
        double sx;      // x accumulator (0x18)
        struct { float tmp18; float w1c; };
    };
    float radius;       // 0x20
    Info_3f7b0 *info;         // 0x24
    V3_3f7b0 w;               // 0x28
    V3_3f7b0 c;               // 0x34
    int flagArg;        // 0x40
    int k;              // 0x44
    V3_3f7b0 hn;              // 0x48 (up vector, then hit normal)
    V3_3f7b0 s;               // 0x54
    V3_3f7b0 nn;              // 0x60
    float dd;           // 0x6c
    HitObj_3f7b0 *hitObj;     // 0x70
    V3_3f7b0 t;               // 0x74
    V3_3f7b0 hp;              // 0x80
    V3_3f7b0 arr2[3];         // 0x8c
    V3_3f7b0 hp2;             // 0xb0
    V3_3f7b0 arr[5];          // 0xbc
};

static float AbsF(float v)
{
    union { float f; unsigned int u; } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

char Chara_3f7b0::Probe(V3_3f7b0 *p1, V3_3f7b0 *p2, V3_3f7b0 *out1, V3_3f7b0 *out2, V3_3f7b0 *d, V3_3f7b0 *n2, unsigned int *flags)
{
    if (cfg == 0)
        return 0;

    Chara_3f7b0 *cur = DAT_004dd700->player->current;
    Frame_3f7b0 f;
    f.flagArg = 0;
    if (this != cur && ignoreB != cur && ignoreA != cur)
        f.flagArg = 1;

    f.hitObj = 0;
    f.info = 0;
    FUN_00035fa0(0);
    char ok = FUN_002027c0(p1, p2, 0, f.flagArg, &f.hp, &f.n, &f.hitObj, &f.info);
    FUN_00035fa0(1);
    if (!ok) {
        if (flags)
            *flags = 0xf;
        return 0;
    }
    if (f.info && (f.info->flags16 & 0x10))
        return 0;
    if (f.hitObj) {
        if (f.hitObj->kind != 5)
            return 0;
        Holder5 *h = f.hitObj->sub;
        if (!h)
            return 0;
        if (!h->chk->FUN_001d6000(h->f40))
            return 0;
    }

    *(float *)&f.i = f.n.y;
    *(unsigned int *)&f.i &= 0x7fffffff;
    float ay = *(float *)&f.i;
    if (!(ay <= 0.01f)) {
        if ((float)sin((double)(DAT_0048f694 * 0.017453292f)) > ay) {
            f.n.y = 0;
            f.n.FUN_0022d110();
        }
    }
    if (!(DAT_004dc2e8 & 1)) {
        DAT_004dc2e8 |= 1;
        DAT_004dc2e4 = (float)cos(1.1344640453656516);
    }

    FUN_00011520(f.arr, 12, 5, &V3_3f7b0::FUN_00011090);
    f.count = 0;
    f.k = 0;
    if (d && (f.n.z * d->z + f.n.y * d->y + f.n.x * d->x) <= DAT_004dc2e4) {
        f.k = 1;
    } else {
        f.arr[0] = f.n;
        f.count = 1;
    }

    f.w1c = cfg->f30;
    f.radius = cfg->radius;
    f.w.x = p2->x - p1->x;
    f.w.y = p2->y - p1->y;
    f.w.z = p2->z - p1->z;
    f.w.FUN_0022d110();

    FUN_00011520(f.arr2, 12, 3, &V3_3f7b0::FUN_00011090);
    float hy = DAT_0048f690 * f.w1c;
    f.arr2[0].x = 0;
    f.arr2[0].y = hy;
    f.arr2[0].z = 0;
    if (mode != 4)
        f.arr2[0].y = hy * 0.5f;
    f.hn.x = 0;
    f.hn.y = 1.0f;
    f.hn.z = 0;
    f.arr2[2].FUN_000111b0(&f.hn, &f.w);
    f.arr2[2].x = f.arr2[2].x * f.radius;
    f.arr2[2].y = f.arr2[2].y * f.radius;
    f.arr2[2].z = f.arr2[2].z * f.radius;
    f.nn = f.n;
    f.arr2[1].x = -f.arr2[2].x;
    f.arr2[1].y = -f.arr2[2].y;
    f.arr2[1].z = -f.arr2[2].z;
    f.hp2.z = -f.arr2[2].z;
    f.dd = -(f.hp.z * f.nn.z + f.hp.x * f.nn.x + f.hp.y * f.nn.y);
    f.found = 1;
    for (f.i = 0; f.i < 3; f.i++) {
        if (n2) {
            f.t = f.arr2[f.i];
            f.t.FUN_0022d110();
            if ((f.t.z * n2->z + f.t.y * n2->y + f.t.x * n2->x) <= 0.0f)
                continue;
        }
        f.s.x = p1->x + f.arr2[f.i].x;
        f.s.y = p1->y + f.arr2[f.i].y;
        f.s.z = p1->z + f.arr2[f.i].z;
        f.c = *p2;
        hulk_freg dist = f.nn.z * p1->z;     // plane distance of p1, kept in a register (listing order)
        dist += f.nn.y * p1->y;
        dist += f.nn.x * p1->x;
        dist += f.dd;
        hulk_freg cx = f.c.x + f.arr2[f.i].x;
        hulk_freg cy = f.c.y + f.arr2[f.i].y;
        f.c.z = f.c.z + f.arr2[f.i].z;
        f.c.x = f.w.x * dist + cx;
        f.c.y = f.w.y * dist + cy;
        f.c.z = f.w.z * dist + f.c.z;
        f.found = 0;
        FUN_00035fa0(0);
        char ok2 = FUN_002027c0(&f.s, &f.c, 0, f.flagArg, &f.hp2, &f.hn, 0, &f.info);
        FUN_00035fa0(1);
        if (!ok2) {
            if (flags) {
                *flags |= 1u << f.i;
                return 0;
            }
            if (!allowMiss)
                return 0;
            continue;
        }
        if (f.info && (f.info->flags16 & 0x10))
            return 0;
        f.found = 1;
        if (!((f.hn.z * f.n.z + f.hn.x * f.n.x + f.hn.y * f.n.y) < DAT_004dc2e4)) {
            f.arr[f.count] = f.hn;
            f.count++;
        } else {
            f.k++;
            if (f.k > 1)
                return 0;
        }
        f.tmp18 = f.hp2.z * f.nn.z + f.hp2.y * f.nn.y + f.hp2.x * f.nn.x + f.dd;
        *(unsigned int *)&f.tmp18 &= 0x7fffffff;
        if (f.tmp18 > f.radius) {
            if (flags) {
                *flags |= 1u << f.i;
                return 0;
            }
            return 0;
        }
    }
    if (!f.found)
        return 0;
    if (f.count > 0) {
        f.sx = 0;
        float sy = 0;
        float sz = 0;
        for (int j = 0; j < f.count; j++) {
            f.sx += f.arr[j].x;
            sy += f.arr[j].y;
            sz += f.arr[j].z;
        }
        double inv = 1.0f / f.count;
        f.n.x = (float)(inv * f.sx);
        f.tmp18 = (float)inv;
        f.n.y = f.tmp18 * sy;
        f.n.z = sz * f.tmp18;
        f.n.FUN_0022d110();
    }
    out1->x = f.n.x * 0.01f + f.hp.x;
    out1->y = f.n.y * 0.01f + f.hp.y;
    out1->z = f.n.z * 0.01f + f.hp.z;
    out2->x = f.n.x;
    out2->y = f.n.y;
    out2->z = f.n.z;
    return 1;
}
} // namespace fn_0003f7b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35f7bdf {

// 0x0003ffa0 FUN_0003ffa0 (64 B): matches/0x0003ffa0.cpp
// sym: ?Set@Thing_3ffa0@fn_f35f7bdf@@QAEXPAVRef_3ffa0@2@E@Z
void Thing_3ffa0::Set(Ref_3ffa0* value, unsigned char flag) {
    if (value == 0) {
        ((CCharacter_nv_3ffa0*)(((CCharacter*)(((CCharacter*)(this))))))->Missing_000393c0();
        return;
    }
    state = flag;
    value->Use();
    if (member)
        member->Release();
    member = value;
}


// 0x0003ffe0 FUN_0003ffe0 (256 B): equivalent/0x0003ffe0.cpp
// sym: ?target@Object@fn_f35f7bdf@@QAEHHHEHH@Z @176b23c61cbb @w1d81168e6085
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_0003ffe0 @ 0x0003ffe0
int Object::target(int a,int b,unsigned char allow,int fallback,int mode) {
 Vector v; v.x=0; v.y=0; v.z=0;
 FUN_000350c0(&v);
 FUN_00035dc0(mode);
 int result=current;
 if (!disabled) {
  if (!FUN_0003a440(&v,mode,a,b,result)) result=0;
 }
 if(result) return result;
 if(!allow) return result;
 if(FUN_0003a440(&v,mode,a,b,fallback) && fallback) return fallback;
 result=FUN_00039c60(&v,mode,a,b,0,0,0);
 if(result) return result;
 if(!parent) return result;
 result=parent->value;
 if(!FUN_0003a440(&v,mode,a,b,result)) return 0;
 return result;
}


// 0x000400e0 FUN_000400e0 (91 B): matches/0x000400e0.cpp
// sym: ?Build@Owner_400e0@fn_f35f7bdf@@QAEPAVItem_400e0@2@HHHHH@Z
Item_400e0* Owner_400e0::Build(hulk_intptr a, hulk_intptr b, int c, int d, int e) {
    Item_400e0* p = Helper_00039c60(a, b, c, d, e, 0, 0);
    if (p) {
        flag = 0;
        p->A();
        if (current)
            current->B();
        current = p;
    }
    return current;
}

} // namespace fn_f35f7bdf

// 0x00040140 FUN_00040140 (35 B): matches/0x00040140.cpp
// sym: ?FUN_00040140@CCharacter@@QAEXHHHHH@Z
void CCharacter::FUN_00040140(int a, int b, int c, int d, int e) {
    ((CCharacter_nv_40140*)this)->callee_0003acf0(0, a, b, c, d, e);
}


// 0x00040170 FUN_00040170 (47 B): matches/0x00040170.cpp
// sym: ?FUN_00040170@CCharacter@@QAEHXZ
int CCharacter::FUN_00040170() {
    bool bad = false;
    for (int i = 0; i < 8; i++)
        if (!((CCharacter_nv_40170*)this)->Fnf_0003aef0(i))
            bad = true;
    return !bad;
}


// 0x000403f0 FUN_000403f0 (347 B): equivalent/0x000403f0.cpp [wrapped: conflict: World]
// sym: ?FUN_000403f0@CCharacter_403f0@fn_000403f0@@QAEXXZ @9e892ca0aa47 @w4f3ad370efd6
namespace fn_000403f0 {
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 18/22, incomplete)
// FUN_000403f0 @ 0x000403f0
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

struct Vec3_403f0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

class Node {
public:
    char FUN_00059a50(Vec3_403f0 *out);
};

class Ref_403f0 {
public:
    virtual void vf0();
    virtual void vf1();
};

class Team_403f0 {
public:
    char pad0[0x1b0];
    int id;
};

class Actor_403f0 {
public:
    char pad0[0x10];
    Node *node;
    char pad1[0x11c - 0x14];
    Team_403f0 *team;
    char pad2[0x12c - 0x120];
    Ref_403f0 *target;
    void FUN_000393c0();
};

class Roster_403f0 {
public:
    char pad0[0xc];
    int count;
    Actor_403f0 *FUN_00024190(int index);
    char FUN_000242d0(Actor_403f0 *a);
};

class CCharacter_403f0 {
public:
    char pad0[0x10];
    Node *node;
    char pad1[0x11c - 0x14];
    Team_403f0 *team;
    char pad2[0x328 - 0x120];
    Ref_403f0 *current;
    char pad3[0x1b48 - 0x32c];
    char flag;
    char pad4[0x1d40 - 0x1b49];
    char enabled;
    void FUN_000393c0();
    void FUN_000403f0();
};

struct World {
    char pad0[0x20];
    Roster_403f0 *roster;
};


void CCharacter_403f0::FUN_000403f0()
{
    if (DAT_004dd700->roster->FUN_000242d0((Actor_403f0 *)this))
        return;
    if (!enabled)
        return;
    Vec3_403f0 me;
    node->FUN_00059a50(&me);
    int count = DAT_004dd700->roster->count;
    Actor_403f0 *best = 0;
    float bestDist = 0;
    for (int i = 0; i < count; i++) {
        Actor_403f0 *other = DAT_004dd700->roster->FUN_00024190(i);
        me.x = 0;
        me.y = 0;
        me.z = 0;
        node->FUN_00059a50(&me);
        if (other && other->team->id != team->id) {
            Vec3_403f0 op;
            other->node->FUN_00059a50(&op);
            me.x = me.x - op.x;
            me.y = me.y - op.y;
            me.z = me.z - op.z;
            float d = me.FUN_0022d110();
            if (best == 0 || d < bestDist) {
                bestDist = d;
                best = other;
            }
        }
    }
    if (best) {
        Ref_403f0 *t = best->target;
        if (t == 0) {
            FUN_000393c0();
            return;
        }
        flag = 1;
        t->vf0();
        if (current)
            current->vf1();
        current = t;
    }
}
} // namespace fn_000403f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x00040550 FUN_00040550 (1049 B): equivalent/0x00040550.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00040550@Fighter_40550@fn_00040550@@QAEXM@Z @b5375edd928d @w1206cb58d73f
namespace fn_00040550 {
// STATUS: equivalent (tools/equiv.py level 3: 3061 inputs, branch coverage 57/60, incomplete)
// FUN_00040550 @ 0x00040550
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
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

struct V3_40550 {
    float x, y, z;
    bool FUN_0022d2b0(V3_40550 *other, float eps);
};

struct Key {
    unsigned int lo;
    unsigned int hi;
    Key(const Key &src) throw();
    Key() {}
    Key *FUN_0027b0e0(const char *name) throw();
    void FUN_0027af50() throw();
};

struct Event_40550 {
    char data[0x28];
    void FUN_001cadf0(Key k) throw();
};

struct Sink_40550 {
    void FUN_001cbc20(Event_40550 *e) throw();
};

struct Gate_40550 {
    char FUN_001ccff0();
};

struct Hud_40550 {
};

class Fighter_40550;

struct Hero_40550 {
    char pad0[0x124];
    Fighter_40550 *f124;
};

struct World {
    char pad0[0x20];
    Hero_40550 *hero;                      // 0x20
    char pad24[8];
    Gate_40550 *gate;                      // 0x2c
    Sink_40550 *sink;                      // 0x30
    Hud_40550 *hud;                        // 0x34
};

struct Mgr_40550 {
    V3_40550 *FUN_001c39c0();
};
Mgr_40550 *__cdecl FUN_001c3d90();

struct Obj_40550 {
    char pad0[0x114];
    Obj_40550 *f114;
};

struct Link_40550 {
    char pad0[8];
    Obj_40550 *f08;
    int kind;                        // 0xc
};

static float TwoPi()
{
    return 6.2831855f;
}

class Fighter_40550 {
public:
    char pad0[0x328];
    Obj_40550 *f328;
    char b32c;
    char b32d;
    char pad32e[0x1fa0 - 0x32e];
    int mode;                        // 0x1fa0
    char pad1fa4[0x202c - 0x1fa4];
    int f202c;
    char pad2030[4];
    unsigned int f2034;
    unsigned int f2038;
    char pad203c[0x2080 - 0x203c];
    V3_40550 v2080;
    char pad208c[0x20a8 - 0x208c];
    int f20a8;
    Link_40550 *FUN_000396a0(unsigned int lo, unsigned int hi, int z);
    void FUN_0003ffa0(Link_40550 *l, int z);
    void FUN_000350c0(V3_40550 *out);
    void FUN_00035dc0(V3_40550 *out);
    void FUN_000400e0(V3_40550 *a, V3_40550 *b, float tau, float range, int z);
    void FUN_00040550(float dt) throw();
};

void Fighter_40550::FUN_00040550(float dt) throw()
{
    if (f20a8 < 0 || f20a8 >= 4)
        return;
    if (b32c != 0 && f328 == 0) {
        b32c = 0;
        b32d = 0;
    }
    int m = mode;
    if ((*(char*)&DAT_004dc290) != 0) {
        if (m == 1)
            b32c = (b32c == 0);
    } else if (m == 1 || (m == 2 && f202c == 1)) {
        b32c = 1;
    } else if (m == 3 || m == 0) {
        if (b32c != 0 && m == 3)
            ((owners::Owner_1ebd00 *)(DAT_004dd700->hud))->FUN_001ebd00("targetting", "lost");
        b32c = 0;
    }
    b32d = b32c;
    if (b32c == 0)
        return;

    static float tau = TwoPi();

    if (f202c == 1) {
        Obj_40550 *old = f328;
        Link_40550 *l = FUN_000396a0(f2034, f2038, 0);
        if (l == 0)
            return;
        FUN_0003ffa0(l, 0);
        if (DAT_004dd700->gate->FUN_001ccff0()) {
            Sink_40550 *s = DAT_004dd700->sink;
            Key k;
            Event_40550 ev;
            k.FUN_0027b0e0("hulk_target_switched");
            ev.FUN_001cadf0(k);
            s->FUN_001cbc20(&ev);
            k.FUN_0027af50();
        }
        if (old != 0 && l->kind == 5) {
            Obj_40550 *o = l->f08;
            if (o != 0 && o->f114 == old) {
                Sink_40550 *s = DAT_004dd700->sink;
                Key k;
                Event_40550 ev;
                k.FUN_0027b0e0("SH_sub_targeting");
                ev.FUN_001cadf0(k);
                s->FUN_001cbc20(&ev);
                k.FUN_0027af50();
            }
        }
        ((owners::Owner_1ebd00 *)(DAT_004dd700->hud))->FUN_001ebd00("targetting", "switched");
        return;
    }

    if (f328 != 0 && m != 1)
        return;

    V3_40550 a;
    V3_40550 b;
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    if (DAT_004dd700->hero->f124 == this) {
        bool direct = false;
        // the original re-tests f202c here (never true on this path); a volatile read keeps the test
        if (*(volatile int *)&f202c == 1) {
            b.x = 0.0f;
            b.y = 0.0f;
            b.z = 0.0f;
            if (!v2080.FUN_0022d2b0(&b, 1e-5f)) {
                FUN_000350c0(&a);
                b = v2080;
                direct = true;
            }
        }
        if (!direct) {
            Mgr_40550 *mgr = FUN_001c3d90();
            a = *((V3_40550 *)((owners::Object_1c39d0 *)mgr)->FUN_001c39d0());
            b = *mgr->FUN_001c39c0();
        }
    } else {
        b.x = 0.0f;
        b.y = 0.0f;
        b.z = 0.0f;
        FUN_00035dc0(&b);
        a.x = 0.0f;
        a.y = 0.0f;
        a.z = 0.0f;
        FUN_000350c0(&a);
    }
    FUN_000400e0(&a, &b, tau, 500.0f, 0);

    if (f328 == 0) {
        b32c = 0;
        b32d = 0;
        ((owners::Owner_1ebd00 *)(DAT_004dd700->hud))->FUN_001ebd00("targetting", "lost");
        return;
    }
    if (DAT_004dd700->gate->FUN_001ccff0()) {
        Sink_40550 *s = DAT_004dd700->sink;
        Key k;
        Event_40550 ev;
        k.FUN_0027b0e0("hulk_target_acquired");
        ev.FUN_001cadf0(k);
        s->FUN_001cbc20(&ev);
        k.FUN_0027af50();
    }
    ((owners::Owner_1ebd00 *)(DAT_004dd700->hud))->FUN_001ebd00("targetting", "acquired");
}
} // namespace fn_00040550
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35f7bdf {

// 0x00040dc0 FUN_00040dc0 (2851 B): equivalent/0x00040dc0.cpp
// sym: ?FUN_00040dc0@CCharacter_40dc0@fn_f35f7bdf@@QAEXPAUArgs_40dc0@2@M@Z @2416436ab89d @wd13c3e404b01
// STATUS: equivalent (tools/equiv.py level 3: 20049 inputs, branch coverage 78/78)
// FUN_00040dc0 @ 0x00040dc0
// the value a float slot holds after a store: the original reloads it (rounded) where MSVC 7.1 would reuse the
// unrounded register
void CCharacter_40dc0::FUN_00040dc0(Args_40dc0 *a1, float a2)
{
    Scene_40dc0 *scene = holder->FUN_00059a40();
    Frame_40dc0 f;
    f.P0 = x14.mat.trans;
    f.S0 = scene->xf.mat.trans.y;
    float absA2 = a2;
    if (absA2 < 0.0f)
        absA2 = -absA2;
    if (b119)
        return;

    if (p338 != 0 && p388 != 0) {
        Scene_40dc0 *s2 = p338->holder->FUN_00059a40();
        if (s2 != 0) {
            Mat4_40dc0 *src;
            if (u33c != 0xffff)
                src = (Mat4_40dc0 *)(s2->bones->mats + (u33c << 6));
            else
                src = s2->xf.FUN_00221c40();
            f.M98 = *src;
            if ((lo340 | hi344) != 0) {
                f.M15c = f.M98;
                ((owners::Matrix_22c120 *)&(f.M15c))->FUN_0022c120();
                f.x.FUN_00221b70(p388->xf.FUN_00221c40());
                ((owners::Obj_221e60 *)&(f.x))->FUN_00221e60((hulk_uintptr)(const Mat4_40dc0 *)(&f.M15c));
                s2->FUN_00224260(lo340, hi344, &f.x);
                ((owners::Matrix_22ca90 *)&(f.M58))->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat4_40dc0 *)(&m348), (const owners::Matrix_22ca90 *)(const Mat4_40dc0 *)(f.x.FUN_00221c40()));
            } else {
                f.M58 = m348;
            }
            ((owners::Matrix_22ca90 *)&(f.M19c))->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat4_40dc0 *)(&f.M58), (const owners::Matrix_22ca90 *)(const Mat4_40dc0 *)(&f.M98));
            p388->xf.FUN_00221c60(&f.M19c);
        }
    }

    x14.FUN_00221be0(&scene->xf);
    v68 = x14.mat.trans;
    if (mode == 1 || mode == 2) {
        v68.y = cfg->f30 * 0.5f + v68.y;
    } else if (mode == 4) {
        V3_40dc0 &t = f.vA;
        t.x = 0.0f;
        t.y = 0.0f;
        t.z = 0.0f;
        FUN_00035550(&t);
        float k = -cfg->f34;
        v68.x = t.x * k + v68.x;
        v68.y = t.y * k + v68.y;
        v68.z = t.z * k + v68.z;
    }

    scene->FUN_00222f40(a2);
    scene->FUN_00223fa0();
    if (!b22e0 && p128 != 0)
        scene->FUN_002226e0(p128->v15());
    FUN_0003be00();
    scene->FUN_00223060();

    if (p338 != 0 && p388 != 0) {
        Scene_40dc0 *s2 = p338->holder->FUN_00059a40();
        if (s2 != 0) {
            if (scene->FUN_00222da0(p388) >= 1.0f) {
                Mat4_40dc0 *src;
                if (u33c != 0xffff)
                    src = (Mat4_40dc0 *)(s2->bones->mats + (u33c << 6));
                else
                    src = s2->xf.FUN_00221c40();
                f.M58 = *src;
                f.M19c = *scene->xf.FUN_00221c40();
                f.M98 = f.M58;
                ((owners::Matrix_22c120 *)&(f.M98))->FUN_0022c120();
                ((owners::Matrix_22ca90 *)&(f.M15c))->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat4_40dc0 *)(&f.M19c), (const owners::Matrix_22ca90 *)(const Mat4_40dc0 *)(&f.M98));
                if ((lo340 | hi344) != 0) {
                    f.x.FUN_00221b70(p388->xf.FUN_00221c40());
                    ((owners::Obj_221e60 *)&(f.x))->FUN_00221e60((hulk_uintptr)(const Mat4_40dc0 *)(&f.M98));
                    s2->FUN_00224260(lo340, hi344, &f.x);
                    f.M58 = *f.x.FUN_00221c40();
                    ((owners::Matrix_22c120 *)&(f.M58))->FUN_0022c120();
                    ((owners::Matrix_22ca90 *)&m348)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Mat4_40dc0 *)(&f.M15c), (const owners::Matrix_22ca90 *)(const Mat4_40dc0 *)(&f.M58));
                } else {
                    m348 = f.M15c;
                }
            }
        }
    }

    V3_40dc0 *sp = &scene->xf.mat.trans;
    V3_40dc0 cp = *sp;
    V3_40dc0 &w = f.vB;
    hulk_freg wx = (hulk_freg)cp.x + v19c.x;   // x and y stay in registers, z goes through w.z (rounded)
    hulk_freg wy = (hulk_freg)cp.y + v19c.y;
    w.z = cp.z + v19c.z;
    v1a8.x = a2 * v1a8.x;
    v1a8.y = a2 * v1a8.y;
    v1a8.z = a2 * v1a8.z;
    w.x = wx + Stored_40dc0(v1a8.x);
    w.y = wy + Stored_40dc0(v1a8.y);
    w.z = Stored_40dc0(w.z) + Stored_40dc0(v1a8.z);
    scene->FUN_002226f0(&w);
    v19c.z = 0.0f;
    v19c.y = 0.0f;
    v19c.x = 0.0f;
    v1a8.z = 0.0f;
    v1a8.y = 0.0f;
    v1a8.x = 0.0f;
    if (!(absA2 <= 1e-05f)) {
        v80 = *sp;
        v80.x = v80.x - x14.mat.trans.x;
        v80.y = v80.y - x14.mat.trans.y;
        v80.z = v80.z - x14.mat.trans.z;
        hulk_freg inv = 1.0f / a2;
        v80.x = inv * Stored_40dc0(v80.x);
        v80.y = inv * Stored_40dc0(v80.y);
        v80.z = inv * Stored_40dc0(v80.z);
    }

    V3_40dc0 &w2 = f.vC;
    w2 = *sp;
    w2.x = w2.x + v1b4.x;
    w2.y = w2.y + v1b4.y;
    w2.z = w2.z + v1b4.z;
    if (f1e4 > 0.0f) {
        if (!(i1fc > 0) && !(f110 > 0.0f) && !(i114 > 0) && !(i1b20 > 0)) {
            V3_40dc0 &d = f.vB;
            d.x = w2.x - x14.mat.trans.x;
            d.y = w2.y - x14.mat.trans.y;
            d.z = w2.z - x14.mat.trans.z;
            d.FUN_0022d110();
            double dot = d.z * v1e8.z;        // dot, t and s stay in registers (double: MSVC spills dot)
            dot += d.y * v1e8.y;
            dot += d.x * v1e8.x;
            double t = 1.0f;
            if (dot > 0.0f)
                t = 1.0f - dot;
            double s = t * f1f4 * a2;
            V3_40dc0 &p = f.vA;
            p.x = v1e8.x;
            p.y = v1e8.y;
            p.z = v1e8.z;
            w2.x = p.x * s + w2.x;
            p.y = p.y * s;
            p.z = p.z * s;
            w2.y = Stored_40dc0(p.y) + w2.y;
            w2.z = Stored_40dc0(p.z) + w2.z;
            if (f1f4 >= 1.0f)
                a1->f8->FUN_00099d00(a1, this, 0);
        }
        f1f4 = a2 * f1f8 + f1f4;
        f1e4 = f1e4 - a2;
    }
    scene->FUN_002226f0(&w2);
    v1b4.z = 0.0f;
    v1b4.y = 0.0f;
    v1b4.x = 0.0f;

    V3_40dc0 &w3 = f.vA;
    w3 = *sp;
    w3.x = w3.x + v1c0.x;
    w3.y = w3.y + v1c0.y;
    w3.z = w3.z + v1c0.z;
    scene->FUN_002226f0(&w3);
    v1c0.z = 0.0f;
    v1c0.y = 0.0f;
    v1c0.x = 0.0f;

    int m13c = i13c;
    float s44 = scene->xf.mat.trans.y;
    if (m13c != 0) {
        mode = m13c;
        i13c = 0;
    } else if (p128 == 0) {
        float dd = f.S0 - s44;
        if (dd < 0.0f)
            dd = -dd;
        if (dd <= 0.01f)
            mode = 1;
        else
            mode = 3;
    } else {
        mode = 3;
    }
    if (mode == 1 || mode == 2 || mode == 4)
        i390 = 0;

    if (p14c != 0) {
        f.M98 = m150;
        ((owners::Matrix_22c120 *)&(f.M98))->FUN_0022c120();
        f.M58 = *(Mat4_40dc0 *)(p14c + 0x10);
        V3_40dc0 &w4 = f.vB;
        w4 = *sp;
        V3_40dc0 &od8 = f.od8;
        ((owners::Mat_22c2b0 *)&(f.M98))->FUN_0022c2b0((float *)(const V3_40dc0 *)(&w4), (float *)(V3_40dc0 *)(&od8));
        V3_40dc0 &o18 = f.vA;
        ((owners::Mat_22c2b0 *)&(f.M58))->FUN_0022c2b0((float *)(const V3_40dc0 *)(&od8), (float *)(V3_40dc0 *)(&o18));
        if (!(absA2 <= 1e-05f)) {
            v190 = *sp;
            v190.x = v190.x - o18.x;
            V3_40dc0 &z3 = f.vC;
            z3.x = 0.0f;
            v190.y = v190.y - o18.y;
            z3.y = 0.0f;
            z3.z = 0.0f;
            v190.z = v190.z - o18.z;
            hulk_freg ninv = -1.0f / a2;
            v190.x = ninv * Stored_40dc0(v190.x);
            v190.y = ninv * Stored_40dc0(v190.y);
            v190.z = ninv * Stored_40dc0(v190.z);
            if (!v190.FUN_0022d2b0(&z3, 1e-05f))
                FUN_00038c40();
        }
        scene->FUN_002226f0(&o18);
        V3_40dc0 &oe4 = f.oe4;
        scene->xf.FUN_00222120(&oe4);
        V3_40dc0 &ofc = f.ofc;
        ((owners::M_22c3b0 *)&(f.M98))->FUN_0022c3b0((float *)(const V3_40dc0 *)(&oe4), (float *)(V3_40dc0 *)(&ofc));
        V3_40dc0 &of0 = f.of0;
        ((owners::M_22c3b0 *)&(f.M58))->FUN_0022c3b0((float *)(const V3_40dc0 *)(&ofc), (float *)(V3_40dc0 *)(&of0));
        scene->FUN_00222710(&of0);
    } else {
        v190.z = 0.0f;
        v190.y = 0.0f;
        v190.x = 0.0f;
    }

    FUN_00036480(a1, a2);
    V3_40dc0 &w5 = f.vD;
    w5 = *sp;
    if (!w5.FUN_0022d2b0(&f.P0, 1e-05f)) {
        if (p3a4 != 0)
            p3a4->v1();
        p3a4 = 0;
        FUN_0003ba60(a1, a2);
        FUN_000365f0(a1, a2);
    }
    if (!(absA2 <= 1e-05f)) {
        float &inv = f.inv;
        inv = 1.0f / a2;
        v74 = w5;
        v74.x = v74.x - f.P0.x;
        v74.y = v74.y - f.P0.y;
        v74.z = v74.z - f.P0.z;
        v74.x = Stored_40dc0(inv) * Stored_40dc0(v74.x);
        v74.y = Stored_40dc0(inv) * Stored_40dc0(v74.y);
        v74.z = Stored_40dc0(inv) * Stored_40dc0(v74.z);
        Scene_40dc0 *s3 = holder->FUN_00059a40();
        float &ang0 = f.ang0;
        if (s3 == 0)
            ang0 = 0.0f;
        else
            ang0 = s3->xf.FUN_002220d0();
        f8c = FUN_00224fc0(x14.FUN_002220d0(), ang0) * inv;
    }
}

} // namespace fn_f35f7bdf

// 0x000418f0 FUN_000418f0 (3459 B): equivalent/0x000418f0.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ?FUN_000418f0@Chara_418f0@fn_000418f0@@QAEXPAUCtx_418f0@2@M@Z @549849162889 @w792cf92f3a94
namespace fn_000418f0 {
// STATUS: equivalent (tools/equiv.py level 3: 20118 inputs, branch coverage 132/132)
// FUN_000418f0 @ 0x000418f0
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
extern "C" double __cdecl sqrt(double);
#endif


// the value a float slot holds after a store: the original reloads it (rounded) where MSVC 7.1 would reuse the
// unrounded register
static inline float Stored_418f0(const float &v)
{
    return *(const volatile float *)&v;
}

struct V3_418f0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    char FUN_0022d2b0(V3_418f0 *other, float eps);
};

struct RefObj_418f0 {
    virtual void AddRef();
    virtual void Release();
};

struct Sub10_418f0 {
    void FUN_00222120(V3_418f0 *out);
};

struct Mover_418f0 {
    char pad0[0x10];
    Sub10_418f0 s10;
    char pad14[0x40 - 0x14];
    V3_418f0 p40;
    void FUN_002226f0(V3_418f0 *pos);
    void FUN_00222700(float a);
};

struct Locator {
    char pad0[0x18];
    Mover_418f0 *f18;
    Mover_418f0 *FUN_00059a40();
    void FUN_00059a50(V3_418f0 *out);
};

struct Cell_418f0 {
    int FUN_00204200(float x, float y, float z);
    char FUN_00204440(int c);
};
struct Holder_418f0 {
};
struct Flt {
    float FUN_00099b70();
};
struct Ctx_418f0;
struct Chara_418f0;
struct Owner_418f0 {
    char pad0[0x124];
    Chara_418f0 *f124;
};
struct Ctx_418f0 {
    char pad0[8];
    Flt *f08;
    char pad0c[0x20 - 0xc];
    Owner_418f0 *f20;
    char pad24[0x54 - 0x24];
    Holder_418f0 *f54;
};

struct CCharacter_418f0 {
    char pad0[0x14];
    int f14;
    char pad18[0x34 - 0x18];
    float f34;
    unsigned __int64 FUN_000443c0();
};

struct Fx_418f0 {
    char FUN_0023f730(const char *s);
    void FUN_0023f740();
};

struct Ref14c : RefObj_418f0 {
    char pad4[8];
    int f0c;
};

hulk_freg __cdecl FUN_00224ea0(float a, float b);
hulk_freg __cdecl FUN_00224fc0(float a, float b);
V3_418f0 *__cdecl FUN_00083e00(V3_418f0 *out, V3_418f0 *in, float s);

struct Hit_418f0 {
    char FUN_00201e00(V3_418f0 *a, V3_418f0 *b, int c, V3_418f0 *d, V3_418f0 *e, int f, int g);
};
struct World {
    char pad0[0x24];
    Hit_418f0 *f24;
};

struct Sub14 {
    hulk_freg FUN_002220d0();
};

struct Ref14c;
struct Frame_418f0 {
    V3_418f0 w88;
    float fl;
    Mover_418f0 *obj18;
    V3_418f0 w74;
    char pad68[2];
    char b66;
    char flag65;
    V3_418f0 w64;
    V3_418f0 w58;
    V3_418f0 A;
    Ref14c *D;
    V3_418f0 pos;
    float adiff;
    int ctype;
    V3_418f0 B;
    float thr;
    V3_418f0 w18;
    V3_418f0 cur;
};

class Chara_418f0 {
public:
    char pad000[0x10];
    Locator *f10;
    char pad14[0x44 - 0x14];
    V3_418f0 p44;
    char pad50[0x68 - 0x50];
    V3_418f0 p68;
    char pad74[0x84 - 0x74];
    float f84;
    char pad88[0x11c - 0x88];
    CCharacter_418f0 *f11c;
    char pad120[0x134 - 0x120];
    int f134;
    int f138;
    char pad13c[4];
    int mode;
    unsigned int f144;
    float f148;
    Ref14c *f14c;
    char pad150[0x1c0 - 0x150];
    float f1c0, f1c4, f1c8;
    char pad1cc[0x334 - 0x1cc];
    Chara_418f0 *ignoreA;
    Chara_418f0 *ignoreB;
    char pad33c[0x3a4 - 0x33c];
    RefObj_418f0 *f3a4;
    char pad3a8[0x1a38 - 0x3a8];
    char b1a38;
    char b1a39;
    char pad1a3a[2];
    V3_418f0 p1a3c;
    V3_418f0 p1a48;
    V3_418f0 p1a54;
    V3_418f0 p1a60;
    V3_418f0 p1a6c;
    V3_418f0 p1a78;
    V3_418f0 p1a84;
    char pad1a90[0x1ad4 - 0x1a90];
    V3_418f0 p1ad4;
    V3_418f0 p1ae0;
    V3_418f0 p1aec;
    V3_418f0 p1af8;
    int f1b04;
    char b1b08;
    char pad1b09[0x1b20 - 0x1b09];
    int f1b20;

    void FUN_00038c40();
    char FUN_00038c70(V3_418f0 *a, V3_418f0 *b, V3_418f0 *c, Ref14c **d, int e, char *f);
    void FUN_00035550(V3_418f0 *out);
    char FUN_0003f7b0(V3_418f0 *p1, V3_418f0 *p2, V3_418f0 *o1, V3_418f0 *o2, V3_418f0 *d, V3_418f0 *n2, unsigned int *flags);
    void FUN_000418f0(Ctx_418f0 *a1, float a2);
};

static float K1() { return 1.04719758f; }
static float K2() { return 0.52359879f; }

void Chara_418f0::FUN_000418f0(Ctx_418f0 *a1, float a2)
{
    Frame_418f0 f;
    f.obj18 = f10->FUN_00059a40();
    f.pos.x = 0.0f;
    f.pos.y = 0.0f;
    f.pos.z = 0.0f;
    f10->FUN_00059a50(&f.pos);
    f.cur.x = p44.x;
    f.cur.y = p44.y;
    f.cur.z = p44.z;
    Chara_418f0 *own = a1->f20->f124;
    f.b66 = 0;
    if (!(own == this || ignoreA == own || ignoreB == own)) {
        Cell_418f0 *cell = ((Cell_418f0 *)((owners::Target_862a0 *)(a1->f54))->FUN_000862a0());
        int idx = cell->FUN_00204200(f.pos.x, f.pos.y, f.pos.z);
        if (!((Cell_418f0 *)((owners::Target_862a0 *)(a1->f54))->FUN_000862a0())->FUN_00204440(idx))
            return;
    } else {
        f.b66 = 1;
    }
    f.fl = f148;
    f.thr = f.fl * 0.5f;
    f.ctype = f11c->f14;
    (*(Fx_418f0**)&DAT_004dd6e8)->FUN_0023f730("World Collision Manager");
    (*(Fx_418f0**)&DAT_004dd6e8)->FUN_0023f740();
    if (f1b20 > 0 || (f14c != 0 && f14c->f0c != 5 && f14c->f0c == 0))
        FUN_00038c40();
    b1a38 = b1a39;
    f.D = 0;
    f.flag65 = 0;
    f.B.x = 0.0f;
    char hit = FUN_00038c70(&f.A, &f.B, &f.w64, &f.D, 0, &f.flag65);
    b1a39 = hit;
    Ref14c *obj = 0;
    if (hit) {
        p1a3c = f.A;
        p1a48 = f.A;
        char bl = 0;
        if (f.b66) {
            if (f.A.y >= a1->f08->FUN_00099b70())
                bl = 1;
        }
        int ty = mode;
        int path;
        if (ty == 3 || ty == 4) {
            path = 2;
        } else if (bl) {
            path = 3;
        } else {
            f.adiff = f.pos.y - f.A.y;
            if (f.adiff < 0.0f)
                f.adiff = -f.adiff;
            if (f.adiff > f.fl || f.B.y < 0.5f)
                path = 3;
            else
                path = 1;
        }
        if (path == 1) {
            f144 = f144 | 1;
            if (f.ctype != 5)
                f.obj18->FUN_002226f0(&f.A);
            if (!f.flag65) {
                p1a54 = f.A;
                p1a78 = f.B;
            }
            obj = f.D;
        } else if (path == 2) {
            if (!bl && (f.pos.y - f.A.y) < f.fl && f.B.y > 0.5f) {
                f144 = f144 | 1;
                p1a54 = f.A;
                p1a78 = f.B;
                obj = f.D;
            } else if (ty == 3 && (f.pos.y - f.A.y) < f.fl) {
                f.w88.x = f.B.x;
                f.w88.y = 0.0f;
                f.w88.z = f.B.z;
                f.w88.FUN_0022d110();
                hulk_freg k = -f84;
                if (!(40.0f < k))
                    k = 40.0f;
                hulk_freg g = k * a2;
                f.w88.y = g * f.w88.y;
                f.w88.z = f.w88.z * g;
                f1c0 = f.w88.x * g + f1c0;
                f1c4 = f.w88.y + f1c4;
                f1c8 = f.w88.z + f1c8;
            }
        } else {
            f.A = p1a54;
            f.B = p1a78;
            if (ignoreB == 0 && !(f1b20 > 0)) {
                f.w58.x = p44.x;
                f.w58.y = p44.y;
                f.w58.z = p44.z;
                f.w88.x = p1a54.x - f.w58.x;
                f.w88.y = p1a54.y - f.w58.y;
                f.w88.z = p1a54.z - f.w58.z;
                if (f.w88.FUN_0022d110() < a2) {
                    f.w74 = p1a54;
                } else {
                    f.w74.z = f.w88.z * a2;     // z goes through w74.z (rounded) before the add
                    f.w74.x = f.w88.x * a2 + f.w58.x;
                    f.w74.y = f.w88.y * a2 + f.w58.y;
                    f.w74.z = Stored_418f0(f.w74.z) + f.w58.z;
                }
                f.obj18->FUN_002226f0(&f.w74);
                FUN_00038c40();
            }
        }
        p1a60 = f.A;
        p1a6c = f.B;
        p1a84 = f.w64;
        if ((mode == 3 || mode == 4) && ignoreB == 0 && !(f1b20 > 0)) {
            hulk_freg lim = f.A.y + f.thr;
            if (f134 == 7 || f.ctype == 5)
                lim = lim - f.thr;
            if (f.pos.y < lim) {
                f.pos.y = lim;
                f.obj18->FUN_002226f0(&f.pos);
            }
        } else {
            if (f.pos.y < f.A.y) {
                f.pos.y = f.A.y;
                f.obj18->FUN_002226f0(&f.pos);
            }
        }
        if (f11c->FUN_000443c0() == (*(unsigned __int64*)&DAT_004dc060) ||
            (f11c->FUN_000443c0() == (*(unsigned __int64*)&DAT_004dc090) && f138 > 0)) {
            if (f.pos.y < f.A.y) {
                f.pos.y = f.A.y;
                f.obj18->FUN_002226f0(&f.pos);
            } else {
                hulk_freg lim2 = f.A.y + 0.25f;
                if (f.pos.y > lim2) {
                    f.pos.y = lim2;
                    f.obj18->FUN_002226f0(&f.pos);
                }
            }
        }
        if (obj)
            obj->AddRef();
        if (f14c)
            f14c->Release();
        f14c = obj;
        if (obj == (Ref14c *)f3a4) {
            if (f3a4)
                f3a4->Release();
            f3a4 = 0;
        }
    } else {
        if (f14c) {
            f14c->Release();
            f14c = 0;
        }
        if (mode != 3 && mode != 4 && ignoreB == 0 && !(f1b20 > 0)) {
            f.w64.x = p44.x;
            f.w64.y = p44.y;
            f.w64.z = p44.z;
            f.obj18->FUN_002226f0(&f.w64);
        }
    }

    if (mode != 4) {
        p1af8.z = 0.0f;
        p1af8.y = 0.0f;
        p1af8.x = 0.0f;
        b1b08 = 0;
        return;
    }
    f.w64.x = 0.0f;
    f.w64.y = 0.0f;
    f.w64.z = 0.0f;
    if (p1af8.FUN_0022d2b0(&f.w64, 1e-005f)) {
        f.w64.x = 0.0f;
        f.w64.y = 0.0f;
        f.w64.z = 0.0f;
        if (!p1ae0.FUN_0022d2b0(&f.w64, 1e-005f)) {
            p1aec = p1ad4;
            p1af8 = p1ae0;
            p1ad4.x = 0.0f; p1ad4.y = 0.0f; p1ad4.z = 0.0f;
            p1ae0.x = 0.0f; p1ae0.y = 0.0f; p1ae0.z = 0.0f;
            f.obj18->FUN_002226f0(&p1aec);
            f.obj18->FUN_00222700(FUN_00224ea0(-p1af8.x, -p1af8.z));
            b1b08 = 1;
        } else {
            f.thr = f11c->f34;
            FUN_00035550(&f.w74);
            f.w88.x = f.w74.x;
            f.w88.y = f.w74.y;
            f.w88.z = f.w74.z;
            hulk_freg ns = -f.thr;
            f.w74.y = f.w74.y * ns;
            f.w74.z = f.w74.z * ns;
            f.w74.x = f.w74.x * ns + f.obj18->p40.x;
            f.w74.y = Stored_418f0(f.w74.y) + f.obj18->p40.y;
            f.w74.z = Stored_418f0(f.w74.z) + f.obj18->p40.z;
            double k = f.thr * 4.5f;
            f.w88.y = f.w88.y * k;
            f.w88.z = f.w88.z * k;
            f.w88.x = f.w88.x * k + Stored_418f0(f.w74.x);
            f.w88.y = Stored_418f0(f.w88.y) + Stored_418f0(f.w74.y);
            f.w88.z = Stored_418f0(f.w88.z) + Stored_418f0(f.w74.z);
            char ok = FUN_0003f7b0(&f.w74, &f.w88, &p1aec, &p1af8, 0, 0, 0);
            b1b08 = ok;
            if (ok) {
                f.obj18->FUN_002226f0(&p1aec);
                f.obj18->FUN_00222700(FUN_00224ea0(-p1af8.x, -p1af8.z));
            }
        }
    } else {
        f.thr = f11c->f34;
        f.w74.x = f.thr * p1af8.x + f.obj18->p40.x;
        f.w74.y = f.thr * p1af8.y + f.obj18->p40.y;
        f.w74.z = f.thr * p1af8.z + f.obj18->p40.z;
        f.w88.x = p1af8.x;
        f.w88.y = p1af8.y;
        f.w88.z = p1af8.z;
        f.w58.x = f.pos.x;
        f.w58.y = f.pos.y;
        f.w58.z = f.pos.z;
        double m3 = f.thr * -3.0f;
        f.w88.y = f.w88.y * m3;
        f.w88.z = f.w88.z * m3;
        f.w88.x = f.w88.x * m3 + Stored_418f0(f.w74.x);
        f.w88.y = Stored_418f0(f.w88.y) + Stored_418f0(f.w74.y);
        f.w88.z = Stored_418f0(f.w88.z) + Stored_418f0(f.w74.z);
        f.w58.x = f.w58.x - f.cur.x;
        f.w58.y = f.w58.y - f.cur.y;
        f.w58.z = f.w58.z - f.cur.z;
        f.w58.FUN_0022d110();
        f.w64.x = p1af8.x;
        f.w64.y = p1af8.y;
        f.w64.z = p1af8.z;
        f.w18.x = p1aec.x;
        f.w18.y = p1aec.y;
        f.w18.z = p1aec.z;
        char ok = FUN_0003f7b0(&f.w74, &f.w88, &f.w18, &f.w64, &p1af8, &f.w58, (unsigned int *)&f1b04);
        b1b08 = ok;
        if (ok) {
            p1aec = f.w18;
            f.obj18->FUN_002226f0(&p1aec);
            p1af8 = f.w64;
            // x87: both headings are stored (fstp) before use; float locals round them (a (float) cast on a call is
            // folded away by the Wine build's float-return handling)
            float ang0 = ((Sub14 *)((char *)this + 0x14))->FUN_002220d0();
            float ang1 = FUN_00224ea0(-p1af8.x, -p1af8.z);
            static float k1 = K1();
            f.fl = k1 * a2;
            hulk_freg dif = FUN_00224fc0(ang0, ang1);
            float difs = dif;   // fst [esp+0x68]: the magnitude test reads the stored float, the sign test st0
            hulk_freg adif = difs < 0.0f ? -difs : difs;
            if (adif <= f.fl)
                f.fl = ang1;
            else if (dif < 0.0f)
                f.fl = ang0 - f.fl;
            else
                f.fl = f.fl + ang0;
            static float k2 = K2();
            hulk_freg res = FUN_00224fc0(ang1, f.fl);
            if (res < -k2)
                f.fl = ang1 - k2;
            else if (res > k2)
                f.fl = ang1 + k2;
            f.obj18->FUN_00222700(f.fl);
        } else {
            if (f1b04 != 0)
                b1b08 = 1;
            f.obj18->FUN_002226f0(&p1aec);
            f.obj18->FUN_00222700(FUN_00224ea0(-p1af8.x, -p1af8.z));
        }
    }

    f.w18.x = p68.x;
    f.w18.y = p68.y;
    f.w18.z = p68.z;
    f.w58.x = f.obj18->p40.x;
    f.w58.y = f.obj18->p40.y;
    f.w58.z = f.obj18->p40.z;
    f.w64.x = 0.0f;
    f.w64.y = 0.0f;
    f.w64.z = 0.0f;
    Mover_418f0 *m2 = f10->FUN_00059a40();
    hulk_freg xx, zz;
    if (m2) {
        m2->s10.FUN_00222120(&f.w88);
        f.w64.y = f.w88.y;
        xx = f.w88.x;
        zz = f.w88.z;
    } else {
        xx = f.w64.x;
        zz = f.w64.z;
    }
    hulk_freg ns2 = -f11c->f34;
    f.w58.x = ns2 * xx + f.w58.x;
    f.w58.y = f.w64.y * ns2 + f.w58.y;
    f.w58.z = zz * ns2 + f.w58.z;
    if (!f.w18.FUN_0022d2b0(&f.w58, 1e-005f)) {
        if (DAT_004dd700->f24->FUN_00201e00(&f.w18, &f.w58, 0, &f.w88, &f.w64, 0, 0))
            f.obj18->FUN_002226f0(&f.cur);
    }
}
} // namespace fn_000418f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35f7bdf {

// 0x00042680 FUN_00042680 (518 B): equivalent/0x00042680.cpp
// sym: ?FUN_00042680@Mover_42680@fn_f35f7bdf@@QAEXMM@Z @5a5cca6a1478 @w1632af930002
// STATUS: equivalent (tools/equiv.py level 3: 19969 inputs, branch coverage 22/22)
// FUN_00042680 @ 0x00042680
void Mover_42680::FUN_00042680(float a, float dt)
{
    if (disabled)
        return;

    if (flag22e0)
        FUN_0003c1d0(a, dt);

    for (int i = 0; i < slotCount; i++) {
        if (slots[i].second) {
            slots[i].second->Release();
            slots[i].second = 0;
        }
        if (slots[i].first) {
            slots[i].first->Release();
            slots[i].first = 0;
        }
    }
    slotCount = 0;

    FUN_0003d350(a, dt);
    FUN_000418f0(a, dt);

    Tracker_42680* tracker = mgr->FUN_00059a40();
    if (!flag22e0 && provider)
        tracker->FUN_002226e0(provider->GetHandle());
    tracker->FUN_00223060();

    if (source)
        matrix = source->matrix;

    FUN_00036480(a, dt);

    union {
        float f;
        unsigned int u;
    } mag;
    mag.f = dt;
    mag.u &= 0x7fffffff;
    if (!(mag.f <= 1e-5f)) {
        Vec3_42680 prev = prevPos;
        Vec3_42680 pos;
        pos.x = 0.0f;
        pos.y = 0.0f;
        pos.z = 0.0f;
        mgr->FUN_00059a50(&pos);
        float invDt = 1.0f / dt;
        vel = pos;
        vel.Sub(prev);
        vel.Scale(invDt);

        Tracker_42680* t = mgr->FUN_00059a40();
        float target;
        if (t == 0)
            target = 0.0f;
        else
            target = t->xf.FUN_002220d0();
        angVel = FUN_00224fc0(xf14.FUN_002220d0(), target) * invDt;
    }

    FUN_0003dd70(a, dt);
}


// 0x00042890 FUN_00042890 (78 B): matches/0x00042890.cpp
// sym: ?Do@CCharacter_42890@fn_f35f7bdf@@QAEXHM@Z
void CCharacter_42890::Do(int a, float b) {
    inner.Init_00231f20(0);
    if (thing->Ready_00059a40()) {
        if (res)
            res->Scale_001d8fc0(b * 1000.0f);
        Finish_00040dc0(a, b);
    }
}


// 0x000428e0 FUN_000428e0 (77 B): matches/0x000428e0.cpp
// sym: ?UpdateA@CCharacter_428e0@fn_f35f7bdf@@QAEXHH@Z
void CCharacter_428e0::UpdateA(int a, int b) {
    CCharacter_428e0* p = this;
    do {
        if (p->mContext->Check_00059a40()) {
            p->UpdateB_00042680(a, b);
            p->UpdateC_0003dc40(a, b);
        }
        if (!p->mNext)
            break;
        p->mNext->UpdateNext_00042890(a, b);
        p = p->mNext;
    } while (1);
}

} // namespace fn_f35f7bdf

// 0x00042930 FUN_00042930 (47 B): matches/0x00042930.cpp
// sym: ?FUN_00042930@C_42930@owners@@QAEXHM@Z
void owners::C_42930::FUN_00042930(int a, float b) {
    if (!flag && field338 == 0)
        ((CCharacter_nv_42930*)(((CCharacter*)(this))))->helper_00042890(a, b * scale);
}


// 0x00042960 FUN_00042960 (47 B): matches/0x00042960.cpp
// sym: ?FUN_00042960@C_42960@owners@@QAEXHM@Z
// Same code shape as 0x00042930 (propagated; names are from that function)
void owners::C_42960::FUN_00042960(int a, float b) {
    if (!flag && field338 == 0)
        ((CCharacter_nv_42960*)(((CCharacter*)(this))))->helper_000428e0(a, b * scale);
}


// 0x00042990 FUN_00042990 (238 B): equivalent/0x00042990.cpp [wrapped: conflict: World]
// sym: ?FUN_00042990@Target_42990@fn_00042990@@QAEEIPAUObject@2@III@Z @b58543415460 @wb7f87d8a186a
namespace fn_00042990 {
// STATUS: equivalent (tools/equiv.py level 3: 2980 inputs, branch coverage 22/22)
// FUN_00042990 @ 0x00042990
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

struct Object;
struct Flag_42990 { char pad[0x72]; unsigned char enabled; };
struct Link_42990 {  };
struct Owner_42990 { char pad[0x128]; Link_42990* link; };
struct Object { char pad[8]; Owner_42990* owner; int kind; char pad2[0x64]; Flag_42990* flag; };
struct Local_42990 { unsigned int data[3]; };
extern "C" void __cdecl FUN_00096a40(Object*, Local_42990*);
struct Renderer_42990 {   };
struct World { char pad[0x20]; Renderer_42990* renderer; };
struct Target_42990 {
 unsigned char FUN_0003e780(unsigned int, Local_42990*, unsigned int,unsigned int,unsigned int);
 unsigned char FUN_00042990(unsigned int,Object*,unsigned int,unsigned int,unsigned int);
};
unsigned char Target_42990::FUN_00042990(unsigned int a,Object* object,unsigned int c,unsigned int d,unsigned int e) {
 if (!object) return 0;
 Local_42990 local;
 FUN_00096a40(object,&local);
 if(object->flag) object->flag->enabled=0;
 if(object->kind==1 && object->owner->link) {
  Object* linked=((Object *)((owners::C_1d72e0 *)(object->owner->link))->FUN_001d72e0());
  if(linked && linked->flag) linked->flag->enabled=0;
 }
 Renderer_42990* renderer=DAT_004dd700->renderer;
 ((owners::C_25260 *)renderer)->FUN_00025260(0, 0, 0);
 ((owners::Target_253c0 *)renderer)->FUN_000253c0(0);
 unsigned char result=FUN_0003e780(a,&local,c,d,e);
 if(object->flag) object->flag->enabled=1;
 if(object->kind==1 && object->owner->link) {
  Object* linked=((Object *)((owners::C_1d72e0 *)(object->owner->link))->FUN_001d72e0());
  if(linked && linked->flag) linked->flag->enabled=1;
 }
 ((owners::C_25260 *)renderer)->FUN_00025260(1, 0, 0);
 ((owners::Target_253c0 *)renderer)->FUN_000253c0(1);
 return result;
}
} // namespace fn_00042990
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f35f7bdf {

// 0x00042ad0 FUN_00042ad0 (65 B): equivalent/0x00042ad0.cpp
// sym: ?FUN_00042ad0@Registry_42ad0@fn_f35f7bdf@@QAEXPBDPAUOwner@2@@Z @ce355a9a4c2b @waca2744d2a21
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00042ad0 @ 0x00042ad0
// FUN_00042ad0 @ 0x00042ad0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_42ad0::FUN_00042ad0(const char* a1, Owner* a2) {
    Function3_42ad0* e = (Function3_42ad0*)FUN_0008d690(0x20);
    void* x = 0;
    if (e)
        x = e->FUN_0003efb0(a1, a2);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f35f7bdf

// 0x00042b20 CCharacter::vfunc_2 (30 B): matches/0x00042b20.cpp
// sym: ??_GCCharacter@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CCharacter::~CCharacter() {}


// 0x00043350 FUN_00043350 (918 B): equivalent/0x00043350.cpp [wrapped: conflict: World]
// sym: ?FUN_00043350@Unit_43350@fn_00043350@@QAEDMTArg2_43350@2@HMDTArg6@2@@Z @da35434e99f3 @w9bae3ef77ef4
namespace fn_00043350 {
// STATUS: equivalent (tools/equiv.py level 3: 20076 inputs, branch coverage 66/76, incomplete)
// FUN_00043350 @ 0x00043350
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

struct Unit_43350;
struct Target_43350;

union Arg2_43350 {
    Target_43350 *t;
    char result;
};

union Arg6 {
    char d;
    int neg;
};

struct CCharacter_43350 {
    char pad0[0x174];
    float f174;
    char pad178[0x188 - 0x178];
    float f188;
    float f18c;
    char pad190[0x1b0 - 0x190];
    int f1b0;
    char pad1b4[0x310 - 0x1b4];
    float f310;
    unsigned __int64 FUN_000443c0();
};

struct Timer {
    float FUN_00086080();
};

struct Next_43350 {
    void FUN_00067870(Unit_43350 *u);
};
Next_43350 *__cdecl FUN_000678d0();

struct Check_43350 {
    char FUN_00092940(int v);
};

struct Holder54_43350 {
    Check_43350 *FUN_00086340();
    struct W { void FUN_000d6e00(int v); };
    W *FUN_000862b0();
};

struct Hook_43350 {
    void FUN_001cd5b0(float v);
};

struct Listener_43350 {
    void FUN_000fe4d0(void *target, int flag);
};

struct World {
    char pad0[0x20];
    Unit_43350 *player;               // 0x20
    char pad24[0x2c - 0x24];
    Hook_43350 *hook;                 // 0x2c
    char pad30[0x54 - 0x30];
    Holder54_43350 *holder;           // 0x54
    Timer *timer;               // 0x58
};

struct Target_43350 {
    char pad0[8];
    Unit_43350 *unit;                 // 0x08
    int kind;                   // 0x0c
};

struct Link128 {
    char pad0[0x11c];
    CCharacter_43350 *obj;
};

struct Out_43350 {
    void FUN_001c4ac0(int *tmp, float f);
};

struct Unit_43350 {
    char pad0[0x10];
    Unit_43350 *link10;               // 0x10
    char pad14[0x11c - 0x14];
    CCharacter_43350 *obj;                // 0x11c
    char pad120[4];
    Unit_43350 *link124;              // 0x124
    Link128 *link128;           // 0x128
    void *f12c;                 // 0x12c
    char pad130[0x1b0c - 0x130];
    float f1b0c;
    char pad1b10[0x1b28 - 0x1b10];
    int f1b28;
    float f1b2c;
    float f1b30;
    char pad1b34[0x1ca0 - 0x1b34];
    Listener_43350 *listener;         // 0x1ca0
    char pad1ca4[0x1cef - 0x1ca4];
    unsigned char b1cef;
    char pad1cf0[0x1d20 - 0x1cf0];
    float f1d20;
    char pad1d24[0x1e4c - 0x1d24];
    int f1e4c;
    char pad1e50[0x20b0 - 0x1e50];
    int f20b0;
    char pad20b4[0x2138 - 0x20b4];
    char b2138;
    char pad2139[3];
    float f213c;
    char pad2140[0x22e8 - 0x2140];
    char b22e8;
    char pad22e9[3];
    void FUN_000403f0();
    void FUN_000385a0(Target_43350 *t, int v);
    char FUN_0003b1c0(float v, char flag);
    void FUN_00025720(int v);
    Out_43350 *FUN_00036a80(int a);
    char FUN_00043350(float dt, Arg2_43350 p2, int a, float one, char c, Arg6 p6);
};

struct Scale_43350 { float FUN_00045670(); };

struct Frame_43350 {
    Unit_43350 *player;               // R-8
    World *mgr;                   // R-4
};


char Unit_43350::FUN_00043350(float dt, Arg2_43350 p2, int a, float one, char c, Arg6 p6)
{
    Frame_43350 f;
    f.mgr = DAT_004dd700;
    f.player = f.mgr->player;
    Timer *timer = f.mgr->timer;
    obj->FUN_000443c0();
    if ((*(float*)&DAT_004dc308) == 0.0f || timer->FUN_00086080() - 0.8f > (*(float*)&DAT_004dc308)) {
        (*(float*)&DAT_004dc308) = timer->FUN_00086080();
        FUN_000678d0()->FUN_00067870(this);
    }
    if (DAT_004dc304 == 0.0f || timer->FUN_00086080() - 0.8f > DAT_004dc304)
        FUN_000403f0();
    if (obj == 0)
        return 0;

    Target_43350 *t = p2.t;
    Unit_43350 *ptarget = 0;
    if (t != 0 && t->kind == 1) {
        ptarget = t->unit;
        if (ptarget != 0 && !c && !b2138) {
            if ((float)b1cef != 0.0f) {
                if (ptarget->obj->f1b0 == obj->f1b0)
                    dt = 0;
            }
        }
        if (f.player->link124 == ptarget) {
            if (one < f213c)
                dt = 0;
            Check_43350 *chk = DAT_004dd700->holder->FUN_00086340();
            if (chk->FUN_00092940(0x14))
                dt = dt + dt;
        }
        if (ptarget != 0)
            dt = dt * ptarget->f1d20;
    }
    FUN_000385a0(t, 0);
    double v;
    World *mgr = f.mgr;
    if (f.player->link124 == this) {
        Check_43350 *chk = mgr->holder->FUN_00086340();
        if (chk->FUN_00092940(0x2e4))
            v = 0.0f;
        else
            v = dt;
    } else {
        v = dt;
    }
    CCharacter_43350 *o = obj;
    if (f1b28 == 0) {
        dt = (float)(v * o->f310);
    } else {
        hulk_freg sel;
        if (!(o->f18c >= f1b2c))
            sel = o->f174;
        else
            sel = o->f188;
        dt = (float)(sel * o->f310 * v);
    }
    dt = ((Scale_43350*)o)->FUN_00045670() * dt;
    char ok = FUN_0003b1c0(f1b0c - dt, (char)c);
    p2.result = 0;
    if (ok && dt > 0.0f && f20b0 == 0) {
        p2.result = 1;
        if (ptarget != 0 && a != 0 && mgr->player != 0 && mgr->player->link124 == ptarget && mgr->hook != 0)
            mgr->hook->FUN_001cd5b0(dt);
        f1e4c = 0;
        f1b30 = dt + f1b30;
        if (f1b0c <= 0.0f && p6.d)
            b22e8 = 1;
    }
    if (this == mgr->player->link124) {
        Holder54_43350 *h = DAT_004dd700->holder;
        h->FUN_000862b0()->FUN_000d6e00(4);
    }
    Unit_43350 *pl = f.player;
    if (pl->link124 != this) {
        if (listener != 0)
            listener->FUN_000fe4d0(pl->link124->f12c, 1);
    }
    if (p2.result == 0) {
        pl->FUN_00025720(a);
        return p2.result;
    }
    void *tgt;
    if (link124 != 0) {
        tgt = link124->link10;
    } else if (link128 != 0) {
        tgt = link128->obj;
    } else {
        return p2.result;
    }
    if (tgt != 0 && dt > 0.0f) {
        p6.neg = -1;
        FUN_00036a80(1)->FUN_001c4ac0(&p6.neg, 0.3f);
    }
    return p2.result;
}
} // namespace fn_00043350
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000436f0 FUN_000436f0 (175 B): equivalent/0x000436f0.cpp [wrapped: macros]
// sym: _FUN_000436f0 @ac7762b63551 @w1b75ac443e58
void* operator new(hulk_uintptr) throw();
namespace fn_000436f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000436f0 @ 0x000436f0


void* FUN_0008d690(unsigned int);
class Unused;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
// The free functions bound as Function<N> (0x00086fa0's Invoke calls them __cdecl); their types are the game's
// Function7<void, int, float x6> (helper 0x0003eea0) and Function3<void, const char*, const char*, float> (0x0003efb0).
void __cdecl FUN_00044c60(int, float, float, float, float, float, float);
void __cdecl FUN_00044cb0(const char*, const char*, float);
void __cdecl FUN_000452e0(const char*, const char*, float);
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
    void* FUN_0003eea0(const char*, void (__cdecl*)(int, float, float, float, float, float, float));
    void* FUN_0003efb0(const char*, void (__cdecl*)(const char*, const char*, float));
};
Registry* FUN_001d4c90();
#define EF(n, c, b) { HULK_SIZE32(ScriptStaticFunctionView, 0x20); Entry* e = (Entry*)FUN_0008d690((unsigned int)sizeof(ScriptStaticFunctionView)); void* x = 0; if (e) x = e->FUN_##c(n, FUN_##b); r->FUN_001d3b70(n, x); }
extern "C" void FUN_000436f0() {
    Registry* r = FUN_001d4c90();
    if (r) {
EF("char_DefineForceReactionProfile", 0003eea0, 00044c60)
EF("char_SetNPCDefault", 0003efb0, 00044cb0)
EF("char_SetNPCParameter", 0003efb0, 000452e0)
    }
}
} // namespace fn_000436f0
#undef EF

namespace fn_f35f7bdf {

// 0x000437a0 FUN_000437a0 (824 B): equivalent/0x000437a0.cpp
// sym: ?FUN_000437a0@Unit_437a0@fn_f35f7bdf@@QAEDMPAUParams_437a0@2@PAUVec3_437a0@2@PAUActor_437a0@2@D@Z @11cd0c660135 @w77276ca682d0
// STATUS: equivalent (tools/equiv.py level 3: 20037 inputs, branch coverage 64/65, incomplete)
// FUN_000437a0 @ 0x000437a0
char Unit_437a0::FUN_000437a0(float dt, Params_437a0* p, Vec3_437a0* where, Actor_437a0* actor, char flag5)
{
    if (f11c == 0)
        return 0;
    int saved = FUN_00266da0(0xd);
    int limit = p->f54;
    char counted = p->b24;
    int extra = 0;
    if (f11c != 0)
        extra = f11c->f1a4;
    if (f31c + f318 + extra > limit)
        counted = 0;
    char behind = 0;
    int idx = FUN_00035fe0();
    if (idx >= 0) {
        float yawBase = FUN_00224f10(&p->vec28) + 3.1415927f;
        Anchor2* anchor = f10->FUN_00059a40();
        float ang;
        if (anchor == 0)
            ang = 0.0f;
        else
            ang = anchor->sub.FUN_002220d0();
        FloatBits_437a0 r;
        r.f = FUN_00224fc0(yawBase, ang);
        r.u &= 0x7fffffff;
        if (f628 * 0.5f > r.f)
            behind = 1;
    }
    if (b1d28 && !p->b90)
        dt = 0.0f;
    if (f11c != 0) {
        if (f11c->FUN_000443c0() == ((unsigned __int64)(*(unsigned int*)((char*)&DAT_004dc080 + 4)) << 32 | (*(unsigned int*)&DAT_004dc080)) && p->b90)
            dt = 0.0f;
    }
    char ok;
    if (behind) {
        Actor_437a0* target = 0;
        if (idx >= 0 && idx < 8)
            target = entries[idx].a;
        ok = target->FUN_001d6ec0((int)dt, p->f4c, 0);
    } else {
        ok = FUN_00043350(dt, p->f4c, p->f48, p->f80, 0, p->b91);
    }
    p->b44 = !ok;
    if (!counted) {
        float factor = 1.0f;
        Target_437a0* t = p->f4c;
        if (t != 0 && t->f0c == 1 && t->f08 != 0)
            factor = t->f08->f1d20;
        f320 = factor * dt + f320;
    }
    CFightParamsCollision* ev = (CFightParamsCollision*)FUN_0008d690(0xb0);
    if (ev != 0)
        ev = ((CFightParamsCollision_nv_437a0*)(((CFightParamsCollision*)(ev))))->FUN_000598e0(f10->first, p);
    else
        ev = 0;
    ev->vfunc_0();
    if (!flag5) {
        Actor_437a0* act = actor;
        if (act == 0)
            act = FUN_000392e0(ev);
        if (act != 0) {
            Vec3_437a0* w = where;
            if (w == 0)
                w = &fdc;
            act->FUN_00231ad0(w, ev, -(int)dt);
            if (act->FUN_00231a40(w, ev) && ok) {
                ((owners::Obj_35930 *)this)->FUN_00035930(6);
                if ((DAT_004dc318 & 1) == 0) {
                    DAT_004dc318 |= 1;
                    (*(Key_437a0*)&DAT_004dc310).FUN_0027af00();
                    atexit(FUN_00363b90);
                }
                ((owners::Target_27b040 *)&((*(Key_437a0*)&DAT_004dc310)))->FUN_0027b040((hulk_uintptr)"no_ai_reset");
                int r = ((int)((owners::Obj_36e40 *)this)->FUN_00036e40((hulk_uintptr)(Key_437a0 *)(((Key_437a0*)&DAT_004dc310))));
                Sub_437a0* sub = &subB4;
                if (sub != 0 && r == 0) {
                    FUN_00037000();
                    sub->FUN_00232240();
                }
            }
        }
    } else {
        Holder110* h = f11c->f110;
        if (h != 0) {
            Actor_437a0* act = h->v8(ev, 0);
            if (act != 0) {
                Vec3_437a0* w = where;
                if (w == 0)
                    w = &fdc;
                act->FUN_00231ad0(w, ev, -(int)dt);
            }
        }
    }
    ev->vfunc_1();
    FUN_00266da0(saved);
    return ok;
}

} // namespace fn_f35f7bdf

// 0x00043ae0 FUN_00043ae0 (1089 B): equivalent/0x00043ae0.cpp [wrapped: conflict: Request]
// sym: ?FUN_00043ae0@Obj_43ae0@fn_00043ae0@@QAEXPAVRefObj_43ae0@2@PAUV3_43ae0@2@MHMHHD0@Z @f163d0102b3a @wf9007624b681
namespace fn_00043ae0 {
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 46/48, incomplete)
// FUN_00043ae0 @ 0x00043ae0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


class RefObj_43ae0 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct V3_43ae0 {
    float x, y, z;
    hulk_freg FUN_00018990();
    hulk_freg FUN_0022d110();
};

struct Request {
    int e0;                          // 0x00
    int e4;                          // 0x04
    V3_43ae0 target;                       // 0x08
    char pad14[4];
    V3_43ae0 aim;                          // 0x18
    char b24;                        // 0x24
    char pad25[3];
    V3_43ae0 vec28;                        // 0x28
    char pad34[0x4c - 0x34];
    RefObj_43ae0 *p4c;                     // 0x4c
    RefObj_43ae0 *p50;                     // 0x50
    int r54;                         // 0x54
    float f58;                       // 0x58
    float f5c;                       // 0x5c
    RefObj_43ae0 *p60;                     // 0x60
    float f64;                       // 0x64
    float f68;                       // 0x68
    char pad6c[8];
    int mode;                        // 0x74
    float val;                       // 0x78
    char pad7c[4];
    float one;                       // 0x80
    char pad84[0x90 - 0x84];
    char b90;                        // 0x90
    char pad91[7];
    Request *FUN_00059820();
    void FUN_00059300();
};

struct Entry_43ae0 {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
};

struct Params {
    float g0[7];
    float g1c;
    float g20;
    float g24;
};


struct CCharacter_43ae0 {
    char pad00[0x14];
    int f14;
    unsigned __int64 FUN_000443c0();
};

struct Obj_43ae0 {
    char pad00[8];
    int f8;
    int fc;
    char pad10[0x110 - 0x10];
    float f110;
    int f114;
    char pad118[4];
    CCharacter_43ae0 *f11c;
    char pad120[0x12c - 0x120];
    RefObj_43ae0 *f12c;
    char FUN_00043350(float dt, RefObj_43ae0 *r, int a, int b, int c, int d);
    void FUN_000350c0(V3_43ae0 *out);
    void FUN_000352b0(V3_43ae0 *out);
    char FUN_000437a0(float dt, Request *r, int a, int b, int c);
    void FUN_00043ae0(RefObj_43ae0 *a1, V3_43ae0 *p, float dt, int a4, float a5, int a6, int a7, char a8, RefObj_43ae0 *a9);
};

void Obj_43ae0::FUN_00043ae0(RefObj_43ae0 *a1, V3_43ae0 *p, float dt, int a4, float a5, int a6, int a7, char a8, RefObj_43ae0 *a9)
{
    struct Frame {
        float s;                     // 0x00
        V3_43ae0 d;                        // 0x04
        V3_43ae0 e;                        // 0x10
        V3_43ae0 a;                        // 0x1c
        Request x;                   // 0x28
    } f;

    if (dt <= 0.0f)
        return;
    if (f110 > 0.0f || f114 > 0) {
        FUN_00043350(a5, a1, 0, 0, 0, 0);
        return;
    }

    f.x.FUN_00059820();
    int idx = f11c->f14;
    if (f12c != 0) {
        f.a.x = 0.0f;
        f.a.y = 0.0f;
        f.a.z = 0.0f;
        FUN_000350c0(&f.a);
        f.d.x = f.a.x - p->x;
        f.d.y = f.a.y - p->y;
        f.d.z = f.a.z - p->z;
        if (sqrt(f.d.z * f.d.z + f.d.y * f.d.y + f.d.x * f.d.x) < 0.001f) {
            f.d.x = 0.0f;
            f.d.y = 1.0f;
            f.d.z = 0.0f;
        }
        f.e = f.d;
        f.e.FUN_0022d110();

        Entry_43ae0 *t = &((Entry_43ae0*)&DAT_004dc360)[idx];
        if (t->f0 <= 0.0f) {
            f.s = 0.0f;
        } else {
            f.s = dt / t->f0;
            if (f.s > 1.0f)
                f.s = 1.0f;
        }

        f.x.e0 = a6;
        f.x.e4 = a7;
        if (a1 != 0)
            a1->AddRef();
        if (f.x.p4c != 0)
            f.x.p4c->Release();
        f.x.p4c = a1;
        RefObj_43ae0 *owner = f12c;
        if (owner != 0)
            owner->AddRef();
        if (f.x.p50 != 0)
            f.x.p50->Release();
        f.x.p50 = owner;
        f.x.mode = 2;
        FUN_000352b0(&f.x.target);

        f.x.f58 = f.s * t->f8;
        f.x.aim = f.e;
        f.x.r54 = a4;
        f.x.val = a5;
        Params *g = (*(Params**)&DAT_00554c10);
        f.x.b90 = a8;
        f.x.one = 1.0f;
        f.x.f64 = (float)sqrt(g->g1c * g->g1c + g->g20 * g->g20 + g->g24 * g->g24);
        f.x.f5c = f.s * t->f10;
        if (a9 != 0)
            a9->AddRef();
        if (f.x.p60 != 0)
            f.x.p60->Release();
        f.x.p60 = a9;
        if (f.s < 0.15f || !(f.s < 25.0f))
            f.x.f68 = 0.0f;
        else
            f.x.f68 = f.s * t->f14;

        if (f.s < 0.25f) {
            f.x.b24 = 0;
        } else {
            f.x.b24 = 1;
            f.x.vec28.y = 0.0f;
            if (f.s < 0.5f) {
                f.x.vec28.x = 0.0f;
                f.x.vec28.z = 0.0f;
            } else {
                if (f.s < 0.75) {
                    f.x.vec28.x = f.e.x;
                    f.x.vec28.z = f.e.z;
                    if (f8 == (*(int*)&DAT_004dc0e0) && fc == (*(int*)((char*)&DAT_004dc0e0 + 4)))
                        ((owners::Vec3_344b0 *)&(f.x.vec28))->FUN_000344b0(f.s * t->f4 * 0.5f);
                    else
                        ((owners::Vec3_344b0 *)&(f.x.vec28))->FUN_000344b0(f.s * t->f4);
                } else {
                    f.x.vec28.x = f.d.x;
                    f.x.vec28.z = f.d.z;
                    f.x.vec28.y = f.x.vec28.FUN_00018990() * f.s;
                    f.x.vec28.FUN_0022d110();
                    ((owners::Vec3_344b0 *)&(f.x.vec28))->FUN_000344b0(f.s * t->f4);
                }
            }
        }

        unsigned __int64 key = f11c->FUN_000443c0();
        if ((unsigned int)key == (*(unsigned int*)&DAT_004dc080) && (unsigned int)(key >> 32) == (*(unsigned int*)((char*)&DAT_004dc080 + 4)) && f.x.b90 != 0)
            a5 = 0.0f;
        FUN_000437a0(a5, &f.x, 0, 0, 0);
    }
    f.x.FUN_00059300();
}
} // namespace fn_00043ae0

namespace fn_f35f7bdf {

// 0x00043fa0 FUN_00043fa0 (13 B): matches/0x00043fa0.cpp
// sym: ?Set@Obj_43fa0@fn_f35f7bdf@@QAEXH@Z
void Obj_43fa0::Set(int x) {
    value = x;
}


// 0x00044000 FUN_00044000 (13 B): matches/0x00044000.cpp
// sym: ?Fn@Obj_44000@fn_f35f7bdf@@QAEXH@Z
void Obj_44000::Fn(int x) {
    value = x;
}


// 0x00044030 FUN_00044030 (13 B): matches/0x00044030.cpp
// sym: ?Set@Obj_44030@fn_f35f7bdf@@QAEXH@Z
void Obj_44030::Set(int value) {
    m36c = value;
}


// 0x00044090 FUN_00044090 (13 B): matches/0x00044090.cpp
// sym: ?SetValue@Target_44090@fn_f35f7bdf@@QAEXD@Z
void Target_44090::SetValue(char v) {
    value = v;
}


// 0x00044190 FUN_00044190 (13 B): matches/0x00044190.cpp
// sym: ?Set@C_44190@fn_f35f7bdf@@QAEXH@Z
void C_44190::Set(int v) {
    m = v;
}


// 0x00044360 FUN_00044360 (7 B): matches/0x00044360.cpp
// sym: ?FUN_00044360@fn_f35f7bdf@@YIPAUObj_44360@1@PAU21@@Z
Obj_44360* __fastcall FUN_00044360(Obj_44360* self) {
    return (Obj_44360*)((char*)self + 0x3b0);
}


// 0x00044370 FUN_00044370 (16 B): matches/0x00044370.cpp
// sym: ?FUN_00044370@fn_f35f7bdf@@YI_KPAD@Z
unsigned __int64 __fastcall FUN_00044370(char* self) {
    return FUN_0027b020(self + 0x3b0);
}


// 0x000443b0 FUN_000443b0 (7 B): matches/0x000443b0.cpp
// sym: ?FUN_000443b0@fn_f35f7bdf@@YIPAUA_443b0@1@PAU21@@Z
A_443b0* __fastcall FUN_000443b0(A_443b0* self) {
    return (A_443b0*)((char*)self + 0x3f0);
}


// 0x000443c0 FUN_000443c0 (16 B): matches/0x000443c0.cpp
// sym: ?Fn@CCharacter_443c0@fn_f35f7bdf@@QAE_KXZ
unsigned __int64 CCharacter_443c0::Fn() {
    return FUN_0027b020(&field);
}


// 0x00044400 FUN_00044400 (7 B): matches/0x00044400.cpp
// sym: ?FUN_00044400@fn_f35f7bdf@@YIPAXPAUObj_44400@1@@Z
void* __fastcall FUN_00044400(Obj_44400* self) {
    return (char*)self + 0x430;
}


// 0x00044410 FUN_00044410 (22 B): matches/0x00044410.cpp
// sym: ?FUN_00044410@Source_44410@fn_f35f7bdf@@QAEHXZ
hulk_intptr Source_44410::FUN_00044410() {
    if (!item)
        return 0;
    return item->f11()->value;
}

} // namespace fn_f35f7bdf

// 0x00044430 FUN_00044430 (114 B): equivalent/0x00044430.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_00044430@Owner_44430@fn_00044430@@QAEXXZ @4ffb4135301f @wd6f47899fa06
namespace fn_00044430 {
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 2/2)
// FUN_00044430 @ 0x00044430
struct Id64_44430 {
    unsigned int lo, hi;
    void FUN_0027af50() throw();
};
struct Pair_44430 {
    char pad0[8];
    unsigned int f08;
    unsigned int f0c;
};
struct Sub_44430 {
    int FUN_001c5b00(Id64_44430 *id);
};
struct Singleton_44430 {
    char pad0[0xc];
    Sub_44430 *sub;
    void FUN_001c3740(Id64_44430 *id);
};
Singleton_44430 *FUN_001c3d90();

struct Owner_44430 {
    char pad0[8];
    Pair_44430 *pair;
    void FUN_00044430();
};

void Owner_44430::FUN_00044430()
{
    Id64_44430 id;
    ((owners::Pair_27af10 *)&id)->FUN_0027af10(pair->f08, pair->f0c);
    int found = FUN_001c3d90()->sub->FUN_001c5b00(&id);
    id.FUN_0027af50();
    if (found) {
        ((owners::Pair_27af10 *)&id)->FUN_0027af10(pair->f08, pair->f0c);
        FUN_001c3d90()->FUN_001c3740(&id);
        id.FUN_0027af50();
    }
}
} // namespace fn_00044430

namespace fn_f35f7bdf {

// 0x000444f0 FUN_000444f0 (12 B): matches/0x000444f0.cpp
// sym: _FUN_000444f0
extern "C" bool FUN_000444f0(void* ptr) {
    return ptr == 0;
}


// 0x00044500 FUN_00044500 (12 B): matches/0x00044500.cpp
// sym: _FUN_00044500
extern "C" bool FUN_00044500(void* ptr) {
    return ptr != 0;
}


// 0x00044510 FUN_00044510 (71 B): matches/0x00044510.cpp
// sym: _FUN_00044510
extern "C" bool FUN_00044510(A_44510* a, int b) {
    if (!a)
        return false;
    A_44510* p = 0;
    switch (a->kind) {
    case 1:
        p = a->next;
        break;
    case 5:
        p = a->next;
        if (!p)
            return false;
        p = *(A_44510**)((char*)p + 0x148);
        break;
    default:
        return false;
    }
    if (!p)
        return false;
    D* d = *(D**)((char*)p + 0x11c);
    if (!d)
        return false;
    return d->value == b;
}


// 0x00044560 FUN_00044560 (61 B): matches/0x00044560.cpp
// sym: _FUN_00044560
extern "C" int FUN_00044560(Param* p) {
    if (!p)
        return 6;
    Inner* i;
    switch (p->type) {
    case 1:
        i = (Inner*)p->node;
        break;
    case 5:
        if (!p->node)
            return 6;
        i = p->node->inner;
        break;
    default:
        return 6;
    }
    if (!i)
        return 6;
    Result* r = i->result;
    if (!r)
        return 6;
    return r->value;
}

} // namespace fn_f35f7bdf

// 0x000445a0 FUN_000445a0 (7 B): matches/0x000445a0.cpp [wrapped: conflict: CKeyPoseTrack]
// sym: ?vfunc_7@CKeyPoseTrack@fn_000445a0@@UAEMXZ
namespace fn_000445a0 {
// Same code shape as 0x000695a0 (propagated; names are from that function)

class CKeyPoseTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual float vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};

float CKeyPoseTrack::vfunc_7() {
    return DAT_003f60a4;
}
} // namespace fn_000445a0


// 0x000445b0 FUN_000445b0 (7 B): matches/0x000445b0.cpp [wrapped: conflict: CKeyPoseTrack]
// sym: ?vfunc_7@CKeyPoseTrack@fn_000445b0@@UAEMXZ
namespace fn_000445b0 {
// Same code shape as 0x000695a0 (propagated; names are from that function)

class CKeyPoseTrack {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual float vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
};

float CKeyPoseTrack::vfunc_7() {
    return DAT_003f5d24;
}
} // namespace fn_000445b0


// 0x00044630 FUN_00044630 (24 B): matches/0x00044630.cpp
// sym: ?FUN_00044630@C_44630@owners@@QAEHH@Z
int owners::C_44630::FUN_00044630(int i) {
    if (!i)
        return -1;
    return *(int*)((char*)this + 0xa0 + i * 4);
}

namespace fn_f35f7bdf {

// 0x00044650 FUN_00044650 (80 B): matches/0x00044650.cpp
// sym: ?Get@CCharacter_44650@fn_f35f7bdf@@QAEPAUVec@2@H@Z
Vec* CCharacter_44650::Get(int n) {
    static Vec zero;
    if (n == 0)
        return &zero;
    return &elems[n];
}

} // namespace fn_f35f7bdf

// 0x000446a0 FUN_000446a0 (27 B): matches/0x000446a0.cpp
// sym: ?FUN_000446a0@C_446a0@owners@@QAEMH@Z
// data: gZero_446a0 = DAT_003f32e0
float owners::C_446a0::FUN_000446a0(int index) {
    if (index == 0)
        return DAT_003f32e0;
    return *(float*)((char*)this + 0xd0 + index * 4);
}


// 0x000446c0 FUN_000446c0 (28 B): matches/0x000446c0.cpp
// sym: ?FUN_000446c0@Obj_446c0@owners@@QAEHH@Z
hulk_intptr owners::Obj_446c0::FUN_000446c0(int index) {
    if (index >= 0 && index < 8)
        return *(int*)((char*)this + (index * 5 + 0x37) * 8);
    return 0;
}

namespace fn_f35f7bdf {

// 0x000446e0 FUN_000446e0 (40 B): matches/0x000446e0.cpp
// sym: ?Get@Thing_446e0@fn_f35f7bdf@@QAE_KH@Z
unsigned __int64 Thing_446e0::Get(int index) {
    if (index >= 0 && index < 8)
        return values[index].value;
    return 0;
}

} // namespace fn_f35f7bdf

// 0x00044710 FUN_00044710 (67 B): matches/0x00044710.cpp [wrapped: conflict: Object]
// sym: ?FUN_00044710@Object@fn_00044710@@QAEPAUVec3@2@PAU32@H@Z
namespace fn_00044710 {
struct Vec3 {
    unsigned int x, y, z;
};
struct Entry {
    Vec3 position;
    char pad[0x28 - sizeof(Vec3)];
};
struct Object {
    char pad[0x1c8];
    Entry entries[8];
    Vec3* FUN_00044710(Vec3* out, int index);
};
Vec3* Object::FUN_00044710(Vec3* out, int index) {
    if (index >= 0 && index < 8) {
        *out = entries[index].position;
    } else {
        out->x = 0;
        out->y = 0;
        out->z = 0;
    }
    return out;
}
} // namespace fn_00044710


// 0x00044760 FUN_00044760 (67 B): matches/0x00044760.cpp [wrapped: conflict: Entry]
// sym: ?Get@Thing@fn_00044760@@QAEPAUVec@2@PAU32@H@Z
namespace fn_00044760 {
struct Vec {
    int x, y, z;
};
struct Entry {
    Vec v;
    char pad[28];
};
class Thing {
    char pad[0x1d4];
    Entry entries[8];

  public:
    Vec* Get(Vec* out, int index);
};
Vec* Thing::Get(Vec* out, int index) {
    if (index >= 0 && index < 8)
        *out = entries[index].v;
    else {
        out->x = 0;
        out->y = 0;
        out->z = 0;
    }
    return out;
}
} // namespace fn_00044760


// 0x000447b0 FUN_000447b0 (103 B): matches/0x000447b0.cpp
// sym: ?FUN_000447b0@Config_447b0@owners@@QAEXPBD@Z
// FUN_000447b0 @ 0x000447b0
void owners::Config_447b0::FUN_000447b0(const char* name) {
    if (!name)
        return;
    for (int i = 0; i < 4; i++) {
        if (strcmp(name, ((const char**)&DAT_0048f6a4)[i]) == 0) {
            mode = i;
            return;
        }
    }
}

namespace fn_f35f7bdf {

// 0x00044820 FUN_00044820 (130 B): equivalent/0x00044820.cpp
// sym: ?FUN_00044820@ValueTable@fn_f35f7bdf@@QAEXPBUId64_44820@2@TFloatBits_44820@2@@Z @bf6ad0c223c6 @w6e95fc89a078
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 10/10)
// FUN_00044820 @ 0x00044820
void ValueTable::FUN_00044820(const Id64_44820 *key, FloatBits_44820 value)
{
    for (int i = 0; i < count; i++) {
        if (entries[i].id.lo == key->lo && entries[i].id.hi == key->hi)
            entries[i].value.i = value.i;
    }

    if (count < 14) {
        entries[count].id.FUN_0027af70(key);
        entries[count].value.f = value.f;
        count++;
    }
}

} // namespace fn_f35f7bdf

// 0x000448b0 FUN_000448b0 (83 B): equivalent/0x000448b0.cpp [wrapped: conflict: Entry]
// sym: ?FUN_000448b0@Obj@fn_000448b0@@QAEMHH@Z @d158c44c9711 @wf41f960df913
namespace fn_000448b0 {
// STATUS: equivalent (tools/equiv.py level 3: 2270 inputs, branch coverage 8/8)
// FUN_000448b0 @ 0x000448b0

struct Entry { int first; int second; float value; int unused; };
struct Obj { char pad[0x480]; Entry entries[14]; int count; float FUN_000448b0(int first, int second); };
float Obj::FUN_000448b0(int first, int second) {
    for (int i = 0; i < count; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return entries[i].value;
    }
    return (*(float*)&DAT_003f3388);
}
} // namespace fn_000448b0

