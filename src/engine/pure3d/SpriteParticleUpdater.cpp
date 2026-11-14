// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d1090..0x002d2070 (kind game, layer engine, confidence high), dominant class pure3d::SpriteParticleUpdater
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/particle_emitter.h"   // (x64t9-spe) the emitter views place their words at HULK_SPE(k)
#include "decls/data/engine/pure3d.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fd69ca5d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fd69ca5d {} using namespace fn_fd69ca5d;
namespace fn_fd69ca5d { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fd69ca5d {
extern int hulk_at_0042f034;
class SpriteParticleUpdater_2d11f0 {
  public:
    void* vptr;
    int a4, a8, ac, a10, a14, a18, a1c, a20, a24;
    SpriteParticleUpdater_2d11f0();
};
struct Obj_2d1310 {
    char pad[0x14];
    float field14;
    char pad2[4];
    float field1c;
};
struct Sub {
    char p[0x1c];
    float* samples;
};
struct Obj {
  public:
    char _m_pad_0[0x14];
    union { float a; float value; };
    char _m_pad_18[0x4];
    union { float b; float scale; };
    char _m_pad_20[HULK_SPE(0x1bc) - 0x20];
    Sub* sub;
};
struct Out {
    char p[0x14];
    float accum;
    char q[4];
    float scale;
};
struct V3_2d1390 {
    float x, y, z;
};
struct Heading_2d1390 {
    V3_2d1390 pos;
    char pad0c[0x14 - 0xc];
    float angle;
    char pad18[4];
    float angleOffset;
};
class Mapper_2d1390 {
public:
    void FUN_002947e0(V3_2d1390 in, V3_2d1390 *out);
};
struct Manager_2d1390 {
    char pad0[8];
    Mapper_2d1390 *mapper;
};
struct Globals_2d1390 {
    Manager_2d1390 *manager;
};
struct V3_2d1410 {
    float x, y, z;
};
struct Heading_2d1410 {
    V3_2d1410 pos;
    char pad0c[0x14 - 0xc];
    float angle;
    char pad18[4];
    float angleOffset;
};
class Mapper_2d1410 {
public:
    void FUN_002947e0(V3_2d1410 in, V3_2d1410 *out);
};
struct Manager_2d1410 {
    char pad0[8];
    Mapper_2d1410 *mapper;
};
struct Globals_2d1410 {
    Manager_2d1410 *manager;
};
struct RandomState_2d1490 {
    unsigned int first;
    unsigned int second;
};
struct Limits_2d1490 {
    char pad00[8];
    unsigned int range;
    float interval;
};
struct Owner_2d1490 {
    char pad00[HULK_SPE(0x1bc)];
    Limits_2d1490 *limits;
};
struct Entry_2d1490 {
    char pad00[0x19];
    unsigned char roll;
    char pad1a[0x2c - 0x1a];
    float now;
    char pad30[4];
    float last;
};
struct RandomState_2d1540 {
    unsigned int first;
    unsigned int second;
};
struct Limits_2d1540 {
    char pad00[8];
    unsigned int range;
    float interval;
};
struct Owner_2d1540 {
    char pad00[HULK_SPE(0x1bc)];
    Limits_2d1540 *limits;
};
struct Entry_2d1540 {
    char pad00[0x19];
    unsigned char roll;
    char pad1a[0x2c - 0x1a];
    float now;
    char pad30[4];
    float last;
};
struct S {
    char pad[8];
    int n;
    float f;
};
struct A {
    char pad[HULK_SPE(0x1bc)];
    S* s;
};
struct B {
    char pad[0x19];
    char v;
    char p[0x12];
    float f;
};
struct Data {
    char pad[8];
    int divisor;
    float scale;
};
struct Owner {
    char pad[HULK_SPE(0x1bc)];
    Data* data;
};
struct Item {
    char pad[0x19];
    char value;
    char pad2[0x12];
    float amount;
};
struct Inner_2d1650 {
    char pad[0x2c];
    int index;
};
struct Outer {
    char pad[HULK_SPE(0x1bc)];
    Inner_2d1650* inner;
};
struct Indices {
    char pad[0x24];
    unsigned int* values;
};
struct Source {
    char pad[HULK_SPE(0x1bc)];
    Indices* indices;
};
struct Destination {
    char pad0[0xc];
    unsigned int value;
    char pad1[0x2e];
    unsigned char flag;
};
unsigned int* __cdecl FUN_002e6780(Source** source, unsigned int color, unsigned char flag);
struct Color { char pad[12]; unsigned int value; char pad2[8]; unsigned char alpha; };
struct Palette { char pad[40]; signed char *entries; };
unsigned int * __cdecl FUN_002e6840(Color **color, unsigned int value, unsigned int alpha);
struct Lookup { char pad0[0x24]; unsigned *values; signed char *highBytes; };
struct Root { char pad0[HULK_SPE(0x1bc)]; Lookup *lookup; };
struct Result { char pad0[0xc]; unsigned value; char pad1[8]; unsigned char secondFlag; char pad2[0x25]; unsigned char firstFlag; };
unsigned * __cdecl FUN_002e6780(Root **root, unsigned packed, unsigned flag);
unsigned * __cdecl FUN_002e6840(Root **root, unsigned value, unsigned flag);
struct Curves_2d17b0 {
    char pad0[0x14];
    float *tableA;      // 0x14
    char pad18[8];
    float *tableB;      // 0x20
};
struct Owner_2d17b0 {
    char pad0[HULK_SPE(0x1a4)];
    float gain;         // 0x1a4
    char pad1a8[4];
    float weight;       // 0x1ac
    char pad1b0[0xc];
    Curves_2d17b0 *curves;     // 0x1bc
};
struct State_2d17b0 {
    float x;            // 0
    float y;            // 4
    float z;            // 8
    char pad0c[0x14];
    float vx;           // 0x20
    float vy;           // 0x24
    float vz;           // 0x28
    char pad2c[0xc];
    float accum;        // 0x38
    short steps;        // 0x3c
};
struct Obj_2d1850 {
    float pos[3];
    char a[0x14];
    float vel[3];
    char b[0xc];
    float x;
    short s;
};
struct Ctx_2d1850 {
    char a[HULK_SPE(0x1a4)];
    float scale;
    char b[4];
    float gravity;
};
struct Curves_2d18b0 { char pad[0x14]; float* speed; char pad2[8]; float* gravity; };
struct Origin_2d18b0 { char pad[0x30]; float x,y,z; };
struct Context {
  public:
    char _m_pad_0[HULK_SPE(0x140)];
    Origin_2d18b0* origin;
    char _m_pad_144[HULK_SPE(0x1a4) - HULK_SPE(0x144)];
    float gravityScale;
    char _m_pad_1a8[0x4];
    float speedScale;
    char _m_pad_1b0[0xc];
    union { Curves_2d18b0* curves; Palette *palette; };
};
struct Particle_2d18b0 { float x,y,z; char pad[0x14]; float vx,vy,vz; char pad2[0xc]; float fall; short weight; };
struct Vec_2d1970 { float x, y, z; };
struct Src_2d1970 { char pad[0x30]; Vec_2d1970 v30; };
struct Owner_2d1970 {
 char pad0[HULK_SPE(0x140)]; Src_2d1970* src;
 char pad1[HULK_SPE(0x1a4) - HULK_SPE(0x144)]; float k1a4;
 char pad2[4]; float k1ac;
};
struct Particle_2d1970 {
 float x, y, z;
 char pad0[0x20 - 0xc];
 float vx, f24, vz;
 char pad1[0x38 - 0x2c];
 float f38; short s3c;
};
struct Particle_2d1a00 { float x,y,z; char pad0[0x14]; float vx,vy,vz; char pad1[0xc]; float drift; short factor;  };
struct Curves_2d1a00 { char pad0[0x14]; float* speed; char pad1[8]; float* drift; };
struct Emitter_2d1a00 { char pad0[HULK_SPE(0xe0)]; float x,y,z; char pad1[HULK_SPE(0x140) - HULK_SPE(0xec)]; void* transform; char pad2[HULK_SPE(0x1a4) - HULK_SPE(0x144)]; float driftScale; char pad3[4]; float speedScale; char pad4[0xc]; Curves_2d1a00* curves; };
struct Particle_2d1b00 {
 float x,y,z;
 char pad0[0x20-12];
 float vx,vy,vz;
 char pad1[0x38-0x2c];
 float acceleration;
 short factor;
};
struct Emitter_2d1b00 {
 char pad0[HULK_SPE(0xe0)];
 float x,y,z;
 char pad1[HULK_SPE(0x140) - HULK_SPE(0xec)];
 void* transform;
 char pad2[HULK_SPE(0x1a4) - HULK_SPE(0x144)];
 float accelerationScale;
 char pad3[4];
 float speed;
};
struct Curves_2d1bc0 { char pad[0x14]; float *speed; char pad18[8]; float *acceleration; };
struct Particle_2d1bc0 { float x,y,z; char pad0c[0x14]; float vx,vy,vz; char pad2c[0xc]; float acceleration; short weight;  };
struct Emitter_2d1bc0 { char pad0[HULK_SPE(0xe0)]; float x,y,z; char padEC[HULK_SPE(0x140) - HULK_SPE(0xec)]; void *transform; char pad144[HULK_SPE(0x1a4) - HULK_SPE(0x144)]; float accelerationScale; char pad1a8[4]; float speedScale; char pad1b0[0xc]; Curves_2d1bc0 *curves; };
struct Particle_2d1cc0 {
 float x,y,z;
 char pad0[0x14];
 float vx,vy,vz;
 char pad1[0xc];
 float acceleration;
 short factor;
};
struct Emitter_2d1cc0 {
 char pad0[HULK_SPE(0xe0)];
 float x,y,z;
 char pad1[HULK_SPE(0x140) - HULK_SPE(0xec)];
 void* transform;
 char pad2[HULK_SPE(0x1a4) - HULK_SPE(0x144)];
 float accelerationScale;
 char pad3[4];
 float speed;
};
struct Vec3_2d1db0 {
    float x, y, z;
};
struct Particle_2d1db0 {
    Vec3_2d1db0 pos;
    char pad0c[4];
    float scaled;
    char pad14[6];
    short size;
    char pad1c[0x2c - 0x1c];
    float age;
    float life;
};
struct Curve_2d1db0 {
    char pad0[0x18];
    float *table;
};
class Emitter_2d1db0 {
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
    virtual unsigned int GetCount();
    char pad[HULK_SPE(0x1bc) - sizeof(void*)];
    Curve_2d1db0 *curve;
    char pad1c0[HULK_SPE(0x1c8) - HULK_SPE(0x1c0)];
    Particle_2d1db0 **particles;
};
struct SpriteParticleUpdater {
    char pad0[0x18];
    void (__cdecl *onUpdate)(float dt, int idx, Emitter_2d1db0 *em, Particle_2d1db0 *p);
    void (__cdecl *onUpdate2)(float dt, int idx, Emitter_2d1db0 *em, Particle_2d1db0 *p);
    void (__cdecl *onFrac)(float dt, int idx, float frac, Emitter_2d1db0 *em, Particle_2d1db0 *p);
    void (__cdecl *onFracPos)(float dt, int idx, float frac, Emitter_2d1db0 *em, Particle_2d1db0 *p, Vec3_2d1db0 *pos);
    void FUN_002d1db0(float dt, Emitter_2d1db0 *em);
};

} // namespace fn_fd69ca5d

// 0x002d1090 FUN_002d1090 (196 B): equivalent/0x002d1090.cpp [wrapped: conflict: pure3d::VertexAnimObject]
// sym: ?Initialize@VertexAnimObject@pure3d@fn_002d1090@@QAEPAV123@PAUSource_2d1090@3@@Z @deced7a979dc @w23fa2c7bcda8
namespace fn_002d1090 {
// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 12/12)
// FUN_002d1090 @ 0x002d1090
struct Object { virtual void AddRef(); virtual void Release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual unsigned Type(); };
struct Entry_2d1090 { Object* object; char pad[12]; };
struct Source_2d1090 { char pad[0x48]; Entry_2d1090* begin; Entry_2d1090* end; char gap[8]; Object* animation; };
namespace pure3d { class VertexAnimObject; }
struct InitContext { unsigned offset; pure3d::VertexAnimObject* owner; };
struct Storage_2d1090 { Object** data; unsigned other; void FUN_002d0eb0(unsigned count, InitContext* context); };
namespace pure3d {
class VertexAnimObject { public: virtual void v0_00018b30(); unsigned field4; Object* animation; Storage_2d1090 storage; VertexAnimObject* Initialize(Source_2d1090* source); };
VertexAnimObject* VertexAnimObject::Initialize(Source_2d1090* source) {
 this->VertexAnimObject::VertexAnimObject();
 field4=0; animation=0; storage.data=0; storage.other=0;
 unsigned count=(unsigned)(((int)((char*)source->end-(char*)source->begin)) >> 4);
 InitContext context; context.offset=0; context.owner=this;
 storage.FUN_002d0eb0(count,&context);
 VertexAnimObject* current=this;
 if(count) context.offset=0;
 for(unsigned i=0;i<count;++i) {
  Object* obj=source->begin[context.offset/16].object;
  if(obj->Type()==0x40) {
   Object** slot=current->storage.data+i;
   obj->AddRef();
   if(*slot) (*slot)->Release();
   *slot=obj;
   current=context.owner;
  }
  context.offset+=16;
 }
 Object* obj=source->animation;
 if(obj) obj->AddRef();
 if(current->animation) current->animation->Release();
 current->animation=obj;
 return current;
}
}
} // namespace fn_002d1090

namespace fn_fd69ca5d {

// 0x002d11f0 FUN_002d11f0 (38 B): matches/0x002d11f0.cpp
// sym: ??0SpriteParticleUpdater_2d11f0@fn_fd69ca5d@@QAE@XZ
SpriteParticleUpdater_2d11f0::SpriteParticleUpdater_2d11f0() {
    a4 = 0;
    vptr = &hulk_at_0042f034;
    a8 = 0;
    ac = 0;
    a10 = 0;
    a14 = 0;
    a18 = 0;
    a1c = 0;
    a20 = 0;
    a24 = 0;
}

} // namespace fn_fd69ca5d

// 0x002d1230 pure3d::SpriteParticleUpdater::vfunc_3 (6 B): matches/0x002d1230.cpp
// sym: ?vfunc_3@SpriteParticleUpdater@pure3d@@UAEIXZ
unsigned int pure3d::SpriteParticleUpdater::vfunc_3() {
    return 0x54525053;
}


// 0x002d1240 FUN_002d1240 (17 B): matches/0x002d1240.cpp
// sym: ?FUN_002d1240@C_2d1240@owners@@QAEXHH@Z
void owners::C_2d1240::FUN_002d1240(int x, int y) {
    a = x;
    b = y;
}


// 0x002d1260 FUN_002d1260 (17 B): matches/0x002d1260.cpp
// sym: ?FUN_002d1260@Target_2d1260@owners@@QAEXII@Z
void owners::Target_2d1260::FUN_002d1260(unsigned x, unsigned y) {
    a = x;
    b = y;
}


// 0x002d1280 FUN_002d1280 (17 B): matches/0x002d1280.cpp
// sym: ?FUN_002d1280@C_2d1280@owners@@QAEXHH@Z
void owners::C_2d1280::FUN_002d1280(int x, int y) {
    a = x;
    b = y;
}


// 0x002d12a0 FUN_002d12a0 (17 B): matches/0x002d12a0.cpp
// sym: ?FUN_002d12a0@C_2d12a0@owners@@QAEXHH@Z
void owners::C_2d12a0::FUN_002d12a0(int x, int y) {
    a = x;
    b = y;
}

namespace fn_fd69ca5d {

// 0x002d12c0 FUN_002d12c0 (1 B): matches/0x002d12c0.cpp
// sym: _FUN_002d12c0
extern "C" void FUN_002d12c0() {}


// 0x002d12d0 FUN_002d12d0 (1 B): matches/0x002d12d0.cpp
// sym: _FUN_002d12d0
extern "C" void __cdecl FUN_002d12d0() {}


// 0x002d12e0 FUN_002d12e0 (1 B): matches/0x002d12e0.cpp
// sym: _FUN_002d12e0
extern "C" void FUN_002d12e0() {}


// 0x002d12f0 FUN_002d12f0 (18 B): matches/0x002d12f0.cpp
// sym: _FUN_002d12f0
extern "C" void __cdecl FUN_002d12f0(float x, int p2, int p3, int p4, Obj* o) {
    o->a += x * o->b;
}


// 0x002d1310 FUN_002d1310 (18 B): matches/0x002d1310.cpp
// sym: _FUN_002d1310
extern "C" void FUN_002d1310(float value, int unused, Obj_2d1310* p) {
    p->field14 = value * p->field1c + p->field14;
}


// 0x002d1330 FUN_002d1330 (52 B): matches/0x002d1330.cpp
// sym: _FUN_002d1330
extern "C" void __cdecl FUN_002d1330(float gain, int index, float interp, Obj* obj, Out* out) {
    float* s = obj->sub->samples;
    float a = s[index];
    float b = s[index + 1];
    out->accum += (a + (b - a) * interp) * out->scale * gain;
}


// 0x002d1370 FUN_002d1370 (18 B): matches/0x002d1370.cpp
// sym: _FUN_002d1370
extern "C" void __cdecl FUN_002d1370(float delta, int unused, Obj* obj) {
    obj->value += delta * obj->scale;
}


// 0x002d1390 FUN_002d1390 (123 B): equivalent/0x002d1390.cpp
// sym: _FUN_002d1390 @d90efd67ca0f @w91f2126af737
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 0/0)
// FUN_002d1390 @ 0x002d1390
// Sets from->angle to the angle of the mapped vector (from - to) plus from->angleOffset.
extern "C" void FUN_002d1390(int unused1, int unused2, int unused3, int unused4, Heading_2d1390 *from, Heading_2d1390 *to) {
    Mapper_2d1390 *mapper = (*(Globals_2d1390**)&DAT_0052c2b0)->manager->mapper;
    V3_2d1390 a;
    V3_2d1390 b;
    mapper->FUN_002947e0(from->pos, &a);
    mapper->FUN_002947e0(to->pos, &b);
    from->angle = (float)(atan2(a.y - b.y, a.x - b.x) + from->angleOffset);
}


// 0x002d1410 FUN_002d1410 (123 B): equivalent/0x002d1410.cpp
// sym: _FUN_002d1410 @be0b3482b8ab @w87a2a2bb838b
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 0/0)
// FUN_002d1410 @ 0x002d1410
// Sets from->angle to the angle of the mapped vector (from - to) plus from->angleOffset.
extern "C" void FUN_002d1410(int unused1, int unused2, Heading_2d1410 *from, Heading_2d1410 *to) {
    Mapper_2d1410 *mapper = (*(Globals_2d1410**)&DAT_0052c2b0)->manager->mapper;
    V3_2d1410 a;
    V3_2d1410 b;
    mapper->FUN_002947e0(from->pos, &a);
    mapper->FUN_002947e0(to->pos, &b);
    from->angle = (float)(atan2(a.y - b.y, a.x - b.x) + from->angleOffset);
}


// 0x002d1490 FUN_002d1490 (161 B): matches/0x002d1490.cpp
// sym: _FUN_002d1490
// FUN_002d1490 @ 0x002d1490
// FUN_002d1490 @ 0x002d1490: re-rolls an entry's random byte once enough time has passed since the last roll
extern "C" void __cdecl FUN_002d1490(int a, int b, Owner_2d1490 *owner, Entry_2d1490 *entry)
{
    if (!(DAT_00554bec & 1)) {
        DAT_00554bec |= 1;
        ((owners::Random_22aba0 *)&((*(RandomState_2d1490*)&DAT_00554be4)))->FUN_0022aba0(0);
    }
    Limits_2d1490 *limits = owner->limits;
    if (entry->now - entry->last > limits->interval) {
        entry->last = entry->now;
        unsigned int bound = limits->range - 1;
        unsigned int first = ((*(RandomState_2d1490*)&DAT_00554be4).first & 0xffff) * 0x9069u + ((*(RandomState_2d1490*)&DAT_00554be4).first >> 16);
        unsigned int second = ((*(RandomState_2d1490*)&DAT_00554be4).second & 0xffff) * 0x4650u + ((*(RandomState_2d1490*)&DAT_00554be4).second >> 16);
        (*(RandomState_2d1490*)&DAT_00554be4).second = second;
        (*(RandomState_2d1490*)&DAT_00554be4).first = first;
        entry->roll = (unsigned char)(((first << 16) + (second & 0xffff)) % (bound + 1));
    }
}


// 0x002d1540 FUN_002d1540 (161 B): matches/0x002d1540.cpp
// sym: _FUN_002d1540
// FUN_002d1540 @ 0x002d1540
// FUN_002d1540 @ 0x002d1540: re-rolls an entry's random byte once enough time has passed since the last roll
extern "C" void __cdecl FUN_002d1540(int a, Owner_2d1540 *owner, Entry_2d1540 *entry)
{
    if (!(DAT_00554bf8 & 1)) {
        DAT_00554bf8 |= 1;
        ((owners::Random_22aba0 *)&((*(RandomState_2d1540*)&DAT_00554bf0)))->FUN_0022aba0(0);
    }
    Limits_2d1540 *limits = owner->limits;
    if (entry->now - entry->last > limits->interval) {
        entry->last = entry->now;
        unsigned int bound = limits->range - 1;
        unsigned int first = ((*(RandomState_2d1540*)&DAT_00554bf0).first & 0xffff) * 0x9069u + ((*(RandomState_2d1540*)&DAT_00554bf0).first >> 16);
        unsigned int second = ((*(RandomState_2d1540*)&DAT_00554bf0).second & 0xffff) * 0x4650u + ((*(RandomState_2d1540*)&DAT_00554bf0).second >> 16);
        (*(RandomState_2d1540*)&DAT_00554bf0).second = second;
        (*(RandomState_2d1540*)&DAT_00554bf0).first = first;
        entry->roll = (unsigned char)(((first << 16) + (second & 0xffff)) % (bound + 1));
    }
}


// 0x002d15f0 FUN_002d15f0 (37 B): matches/0x002d15f0.cpp
// sym: _FUN_002d15f0
extern "C" void __cdecl FUN_002d15f0(int a, int b, A* x, B* y) {
    S* s = x->s;
    y->v = (char)(__int64)(((int)(__int64)(y->f / s->f)) % s->n);
}


// 0x002d1620 FUN_002d1620 (37 B): matches/0x002d1620.cpp
// sym: _FUN_002d1620
extern "C" void __cdecl FUN_002d1620(int unused, Owner* owner, Item* item) {
    Data* d = owner->data;
    item->value = (char)(__int64)((int)(__int64)(item->amount / d->scale) % d->divisor);
}


// 0x002d1650 FUN_002d1650 (28 B): matches/0x002d1650.cpp
// sym: _FUN_002d1650
extern "C" void __cdecl FUN_002d1650(void* unused, void* in, Outer* src, void* out) {
    int idx = src->inner->index;
    ((char*)out)[0x19] = ((char*)in)[idx];
}


// 0x002d1680 FUN_002d1680 (66 B): matches/0x002d1680.cpp
// sym: _FUN_002d1680
extern "C" void __cdecl FUN_002d1680(void* unused, unsigned int index, Source* source, Destination* destination) {
    unsigned int color = (source->indices->values[index] & 0xffffff) |
                         ((unsigned int)((unsigned char*)&destination->value)[3] << 24);
    destination->value = *FUN_002e6780(&source, color, destination->flag);
}


// 0x002d16d0 FUN_002d16d0 (1 B): matches/0x002d16d0.cpp
// sym: _FUN_002d16d0
extern "C" void FUN_002d16d0() {}


// 0x002d16e0 FUN_002d16e0 (70 B): equivalent/0x002d16e0.cpp
// sym: _FUN_002d16e0 @d5d784b7ab39 @w074da0ed5772
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d16e0 @ 0x002d16e0
extern "C" void __cdecl FUN_002d16e0(int unused, int index, Context *context, Color *color)
{
    Color *original = color;
    unsigned int value = ((unsigned int)(int)context->palette->entries[index] << 24) | (original->value & 0xffffff);
    original->value = value;
    unsigned int *result = FUN_002e6840(&color, value, original->alpha);
    original->value = *result;
}


// 0x002d1730 FUN_002d1730 (1 B): matches/0x002d1730.cpp
// sym: _FUN_002d1730
extern "C" void FUN_002d1730() {
    return;
}


// 0x002d1740 FUN_002d1740 (88 B): equivalent/0x002d1740.cpp
// sym: _FUN_002d1740 @5cbb0586a35b @w570925626566
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d1740 @ 0x002d1740
extern "C" void __cdecl FUN_002d1740(int unused, int index, Root *root, Result *result) {
    Lookup *lookup = root->lookup;
    unsigned packed = (lookup->values[index] & 0xffffff) | ((unsigned)lookup->highBytes[index] << 24);
    unsigned value = *FUN_002e6780(&root, packed, result->firstFlag);
    result->value = *FUN_002e6840(&root, value, result->secondFlag);
}


// 0x002d17a0 FUN_002d17a0 (1 B): matches/0x002d17a0.cpp
// sym: _FUN_002d17a0
extern "C" void __cdecl FUN_002d17a0(int) {}


// 0x002d17b0 FUN_002d17b0 (151 B): equivalent/0x002d17b0.cpp
// sym: _FUN_002d17b0 @cc396d4e519a @w00a55032387b
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_002d17b0 @ 0x002d17b0
extern "C" void __cdecl FUN_002d17b0(float dt, int index, float t, Owner_2d17b0 *owner, State_2d17b0 *state)
{
    float *a = owner->curves->tableA;
    float *b = owner->curves->tableB;
    float w = owner->weight;
    // x87: the interpolated values stay in registers (53 bits)
    hulk_freg ia = a[index] + ((hulk_freg)a[index + 1] - a[index]) * t;
    hulk_freg ib = b[index] + ((hulk_freg)b[index + 1] - b[index]) * t;
    state->accum += ib * (int)state->steps * owner->gain * 0.00390625f * dt;
    state->x += ia * state->vx * w * dt;
    state->y += (ia * state->vy + state->accum) * w * dt;
    state->z += ia * state->vz * w * dt;
}


// 0x002d1850 FUN_002d1850 (93 B): matches/0x002d1850.cpp
// sym: _FUN_002d1850
// data: factor = DAT_004d0ed4
extern "C" void FUN_002d1850(float dt, Ctx_2d1850* c, Obj_2d1850* o) {
    float g = c->gravity;
    o->x += (float)o->s * c->scale * (*(const float*)&DAT_004d0ed4) * dt;
    o->pos[0] += g * o->vel[0] * dt;
    o->pos[1] += g * (o->vel[1] + o->x) * dt;
    o->pos[2] += g * o->vel[2] * dt;
}


// 0x002d18b0 FUN_002d18b0 (190 B): equivalent/0x002d18b0.cpp
// sym: _FUN_002d18b0 @4737df937ecf @w773d0d4a3877
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_002d18b0 @ 0x002d18b0
extern "C" void __cdecl FUN_002d18b0(float dt,int index,float t,Context* context,Particle_2d18b0* p) {
 float scale=context->speedScale;
 // x87: the interpolated speed and gravity stay in registers (53 bits); x and y are rounded frame copies
 hulk_freg speed=context->curves->speed[index]+((hulk_freg)context->curves->speed[index+1]-context->curves->speed[index])*t;
 hulk_freg gravity=context->curves->gravity[index]+((hulk_freg)context->curves->gravity[index+1]-context->curves->gravity[index])*t;
 p->fall=gravity*p->weight*context->gravityScale*0.00390625f*dt+p->fall;
 float x=speed*p->vx*scale*dt+p->x;
 p->x=x;
 float y=(speed*p->vy+p->fall)*scale*dt+p->y;
 p->y=y;
 double z=(double)speed*p->vz*scale*dt+p->z;
 p->z=(float)z;
 Origin_2d18b0* origin=context->origin;
 p->x=x+origin->x;
 p->y=y+origin->y;
 p->z=(float)(z+origin->z);
}


// 0x002d1970 FUN_002d1970 (136 B): equivalent/0x002d1970.cpp
// sym: ?Integrate@fn_fd69ca5d@@YAXMPAUOwner_2d1970@1@PAUParticle_2d1970@1@@Z @ca05a10af42e @w462af7f66f29
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// FUN_002d1970 @ 0x002d1970
void Integrate(float dt, Owner_2d1970* o, Particle_2d1970* p) {
 float t = o->k1ac;
 p->f38 = (float)p->s3c * o->k1a4 * DAT_004d0ed4 * dt + p->f38;
 double x = t * p->vx * dt + p->x;
 p->x = (float)x;
 volatile float y = (p->f24 + p->f38) * t * dt + p->y;
 p->y = y;
 volatile float z = t * p->vz * dt + p->z;
 p->z = z;
 // y and z are spilled (rounded) in the original and reloaded below; x stays in a register
 Vec_2d1970* q = &o->src->v30;
 p->x = (float)(x + q->x);
 p->y = y + q->y;
 p->z = z + q->z;
}


// 0x002d1a00 FUN_002d1a00 (241 B): equivalent/0x002d1a00.cpp
// sym: _FUN_002d1a00 @323575a8edcd @wa541186a89cd
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d1a00 @ 0x002d1a00
extern "C" void __cdecl FUN_002d1a00(float dt, int index, float fraction, Emitter_2d1a00* emitter, Particle_2d1a00* p) {
 double scale=emitter->speedScale;
 double speed=emitter->curves->speed[index]+((double)emitter->curves->speed[index+1]-emitter->curves->speed[index])*fraction;
 double drift=emitter->curves->drift[index]+((double)emitter->curves->drift[index+1]-emitter->curves->drift[index])*fraction;
 p->drift=(float)(drift*p->factor*emitter->driftScale*0.00390625f*dt+p->drift);
 float x=(float)(speed*p->vx*scale*dt+p->x); p->x=x;
 float y=(float)((speed*p->vy+p->drift)*scale*dt+p->y); p->y=y;
 double z=speed*p->vz*scale*dt+p->z; p->z=(float)z;
 p->x=x-emitter->x; p->y=y-emitter->y; p->z=(float)(z-emitter->z);
 ((owners::Obj_22d260 *)p)->FUN_0022d260((owners::Obj_22d260 *)(emitter->transform));
 p->x=emitter->x+p->x; p->y=emitter->y+p->y; p->z=emitter->z+p->z;
}


// 0x002d1b00 FUN_002d1b00 (189 B): equivalent/0x002d1b00.cpp
// sym: ?FUN_002d1b00@fn_fd69ca5d@@YAXMPAUEmitter_2d1b00@1@PAUParticle_2d1b00@1@@Z @b76d1052aab7 @wc05e1ef9de21
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// FUN_002d1b00 @ 0x002d1b00
void __cdecl FUN_002d1b00(float dt, Emitter_2d1b00* emitter, Particle_2d1b00* particle) {
 float speed = emitter->speed;
 particle->acceleration = (float)particle->factor * emitter->accelerationScale * 0.00390625f * dt + particle->acceleration;
 hulk_freg x = speed * particle->vx * dt + particle->x;
 particle->x = x;
 float y = (particle->vy + particle->acceleration) * speed * dt + particle->y;
 particle->y = y;
 float z = speed * particle->vz * dt + particle->z;
 particle->z = z;
 particle->x = x - emitter->x;
 particle->y = y - emitter->y;
 particle->z = z - emitter->z;
 ((owners::Obj_22d260 *)particle)->FUN_0022d260((owners::Obj_22d260 *)(emitter->transform));
 particle->x = emitter->x + particle->x;
 particle->y = emitter->y + particle->y;
 particle->z = emitter->z + particle->z;
}


// 0x002d1bc0 FUN_002d1bc0 (241 B): equivalent/0x002d1bc0.cpp
// sym: _FUN_002d1bc0 @85093b56240a @w84f55e0336bd
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_002d1bc0 @ 0x002d1bc0
extern "C" void __cdecl FUN_002d1bc0(float dt, int index, float blend, Emitter_2d1bc0 *emitter, Particle_2d1bc0 *p) {
 hulk_freg speed = emitter->curves->speed[index] + (emitter->curves->speed[index+1]-emitter->curves->speed[index])*blend;
 p->acceleration += (emitter->curves->acceleration[index] + (emitter->curves->acceleration[index+1]-emitter->curves->acceleration[index])*blend) * p->weight * emitter->accelerationScale * 0.00390625f * dt;
 float x = speed * p->vx * emitter->speedScale * dt + p->x;
 p->x = x;
 float y = (speed * p->vy + p->acceleration) * emitter->speedScale * dt + p->y;
 p->y = y;
 double z = speed * p->vz * emitter->speedScale * dt + p->z;
 p->z = (float)z;
 p->x = x - emitter->x;
 p->y = y - emitter->y;
 p->z = (float)(z - emitter->z);
 ((owners::Obj_22d210 *)p)->FUN_0022d210((owners::Obj_22d210 *)(emitter->transform));
 p->x += emitter->x;
 p->y += emitter->y;
 p->z += emitter->z;
}


// 0x002d1cc0 FUN_002d1cc0 (189 B): equivalent/0x002d1cc0.cpp
// sym: _FUN_002d1cc0 @e7426f349ae7 @wef3b8805223e
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// FUN_002d1cc0 @ 0x002d1cc0
extern "C" void __cdecl FUN_002d1cc0(float dt, Emitter_2d1cc0* emitter, Particle_2d1cc0* particle) {
 float speed = emitter->speed;
 particle->acceleration = particle->acceleration + particle->factor * emitter->accelerationScale * 0.00390625f * dt;
 hulk_freg x = particle->x + speed * particle->vx * dt;
 particle->x = x;
 float y = particle->y + (particle->vy + particle->acceleration) * speed * dt;
 particle->y = y;
 float z = particle->z + speed * particle->vz * dt;
 particle->z = z;
 particle->x = x - emitter->x;
 particle->y = y - emitter->y;
 particle->z = z - emitter->z;
 ((owners::Obj_22d210 *)particle)->FUN_0022d210((owners::Obj_22d210 *)(emitter->transform));
 particle->x = emitter->x + particle->x;
 particle->y = emitter->y + particle->y;
 particle->z = emitter->z + particle->z;
}

} // namespace fn_fd69ca5d

// 0x002d1d90 pure3d::ParticleUpdater::vfunc_2 (31 B): matches/0x002d1d90.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002d1d90@@UAEPAV123@E@Z
namespace fn_002d1d90 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class NonCopyable_2d1d90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public NonCopyable_2d1d90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002d1d90

namespace fn_fd69ca5d {

// 0x002d1db0 pure3d::SpriteParticleUpdater::vfunc_4 (350 B): equivalent/0x002d1db0.cpp
// sym: ?FUN_002d1db0@SpriteParticleUpdater@fn_fd69ca5d@@QAEXMPAVEmitter_2d1db0@2@@Z @45c6dcd28574 @wde08f32fb534
// STATUS: equivalent (tools/equiv.py level 3: 16142 inputs, branch coverage 10/10)
// pure3d::SpriteParticleUpdater::vfunc_4 @ 0x002d1db0
void SpriteParticleUpdater::FUN_002d1db0(float dt, Emitter_2d1db0 *em)
{
    if (!(dt > 0.0f))
        return;

    unsigned int count = em->GetCount();
    Curve_2d1db0 *curve = em->curve;
    unsigned int i;
    for (i = 0; i < count; i++) {
        Particle_2d1db0 *p = em->particles[i];
        hulk_freg step = dt;
        if (p->age >= 0.0f) {
            p->age = dt + p->age;
        } else {
            step = dt - p->age;
            p->age = step;
        }
        if (p->age < p->life) {
            hulk_freg t = (p->age / p->life) * 20.0f;
            int idx = (int)t;
            hulk_freg frac = t - (float)idx;
            Vec3_2d1db0 pos = p->pos;
            float *tbl = curve->table;
            hulk_freg a = tbl[idx];
            hulk_freg b = tbl[idx + 1];
            p->scaled = ((b - a) * frac + a) * (float)p->size * DAT_004d0ed4;
            onUpdate(step, idx, em, p);
            onUpdate2(step, idx, em, p);
            onFrac(step, idx, frac, em, p);
            onFracPos(step, idx, frac, em, p, &pos);
        }
    }
}

} // namespace fn_fd69ca5d

// 0x002d1f10 pure3d::SpriteParticleUpdater::vfunc_5 (209 B): equivalent/0x002d1f10.cpp [wrapped: conflict: pure3d::ParticleSystem; pure3d::SpriteParticleUpdater]
// sym: ?vfunc_5@SpriteParticleUpdater@pure3d@fn_002d1f10@@UAEXMPAUParticleSystem@23@@Z @1a49c8c8fd5a @wad556fe87aca
namespace fn_002d1f10 {
// STATUS: equivalent (tools/equiv.py level 3: 30 inputs, branch coverage 8/8)
// pure3d::SpriteParticleUpdater::vfunc_5 @ 0x002d1f10
namespace pure3d {
struct Particle_2d1f10 { float position[3]; char pad[32]; float age; };
struct ParticleSystem { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual unsigned s13(); char pad[HULK_SPE(0x1c8) - sizeof(void*)]; Particle_2d1f10** particles; };
typedef void (__cdecl *Update_2d1f10)(float, ParticleSystem*, Particle_2d1f10*);
typedef void (__cdecl *Finish_2d1f10)(float, ParticleSystem*, Particle_2d1f10*, float*);
struct SpriteParticleUpdater {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(float dt, ParticleSystem* system);
char pad[4]; Update_2d1f10 a; Update_2d1f10 b; Update_2d1f10 c; Finish_2d1f10 d;
};
void SpriteParticleUpdater::vfunc_5(float dt, ParticleSystem* system) {
 if (!(dt > 0.0f)) return;
 unsigned count = system->s13();
 for(unsigned i=0;i<count;++i) {
 Particle_2d1f10* p=system->particles[i];
 float oldPosition[3]; oldPosition[0]=p->position[0]; oldPosition[1]=p->position[1]; oldPosition[2]=p->position[2];
 float step=dt;
 if(!(p->age >= 0.0f)) { step=dt-p->age; p->age=step; } else { p->age=dt+p->age; }
 a(step,system,p); b(step,system,p); c(step,system,p); d(step,system,p,oldPosition);
 }
}
}
} // namespace fn_002d1f10


// 0x002d1ff0 pure3d::SpriteParticleUpdater::vfunc_2 (31 B): matches/0x002d1ff0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002d1ff0@@UAEPAV123@E@Z
namespace fn_002d1ff0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ParticleUpdater_2d1ff0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ParticleUpdater_2d1ff0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002d1ff0

