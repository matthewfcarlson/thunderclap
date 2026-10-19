// STATUS: equivalent (tools/equiv.py level 3: 2743 inputs, branch coverage 75/75)
// FUN_000835a0 @ 0x000835a0
// FUN_000835a0 @ 0x000835a0
// equiv-conv: FUN_00082d30 esi
#include "decls/data/game/hulkfight.h"
namespace content { namespace LoadInventory { class __declspec(novtable) DynamicCasterBase { public: virtual void cast(void *); }; template<class T> class DynamicCaster : public DynamicCasterBase { public: virtual void cast(void *); }; } }
namespace pure3d { class Animation; }
inline void *operator new(unsigned int, void *p) { return p; }
inline void operator delete(void *, void *) {}
struct Vec3_835a0 { float x,y,z; float FUN_0022d110(); };
struct Mat_835a0 { float m[16]; void FUN_0022c3b0(Vec3_835a0 *,Vec3_835a0 *); void FUN_0022cc90(Vec3_835a0 *); };
void __cdecl FUN_00224d70(float, Vec3_835a0 *);
void FUN_00082d30(Mat_835a0 *);
struct Rng_835a0 { unsigned int s0,s1; float FUN_000787e0(float,float); };
Rng_835a0 *FUN_000964d0();
struct Chan_835a0 { void *FUN_00288960(unsigned int,unsigned int); };
struct Anim_835a0 { Chan_835a0 *FUN_00288a20(int); };
class Factory_835a0 { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual Anim_835a0 *f3(content::LoadInventory::DynamicCaster<pure3d::Animation> *,unsigned int,unsigned int); };
struct Holder44_835a0 { Factory_835a0 *FUN_00203d70(); };
struct Holder28_835a0 { Holder44_835a0 *FUN_000862a0(); };
struct VObj70 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual char v11(); };
struct EntB { char pad00[0x6c]; int f6c; VObj70 *f70; void FUN_002ef8b0(int); };
struct Ent_835a0 { char pad00[0x114]; int f114; EntB *FUN_001d72e0(); void FUN_001d7510(); };
struct Fighter_835a0 { void FUN_00059a50(Vec3_835a0 *); };
struct Player_835a0 { char pad00[0x10]; Fighter_835a0 *f10; };
struct List_835a0 { char pad00[0x124]; Player_835a0 *player; };
class Action;
struct Mgr2_835a0 { void FUN_001ebc80(Action *,const char *); };
struct World { void FUN_001dd520(int,Mat_835a0 *); char FUN_001dd800(int); Ent_835a0 *FUN_001dc0d0(int); Vec3_835a0 *FUN_001dc3b0(int); void FUN_001dd470(int,Mat_835a0 *,float); };
struct Globals_835a0 { char pad00[0xc]; World *world; char pad10[0x10]; List_835a0 *list; char pad24[0x10]; Mgr2_835a0 *mgr2; char pad38[0x1c]; Holder28_835a0 *holder; };
extern Globals_835a0 *DAT_004dd700;
struct Entry_835a0 { int id0,id1; char b08; char pad09[7]; };
class Ctl_835a0 { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(float); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(int); virtual void v17(); virtual void v18(int); virtual int v19(); virtual void v20(); virtual void v21(); virtual char v22(); virtual void v23(); virtual void v24(void *,int,float); };
class Action { public: char pad00[0x10]; int f10,state,prevState; char b1c,b1d,pad1e[2]; float f20,f24,f28,f2c,f30,f34; Anim_835a0 *f38; Ctl_835a0 *f3c; Chan_835a0 *f40; void *f44,*f48; void FUN_00082db0(float,Mat_835a0 *); void FUN_00083080(Mat_835a0 *,Vec3_835a0 *,float); void FUN_000835a0(float); };
void Action::FUN_000835a0(float dt)
{
    World *world = DAT_004dd700->world;
    Mat_835a0 transform;
    world->FUN_001dd520(f10, &transform);
    Ent_835a0 *entity = 0;
    char alive = world->FUN_001dd800(f10);
    if (alive) {
        entity = world->FUN_001dc0d0(f10);
        if (entity->f114) {
            if (state != 5) { state = 5; f24 = 0.0f; }
        } else if (state == 5) { state = 6; f24 = 0.0f; }
    }
    if (state != prevState) {
        prevState = state;
        int count = ((int*)&DAT_003ff8bc)[state];
        Rng_835a0 *rng = FUN_000964d0();
        unsigned int a = rng->s0;
        rng->s0 = (a & 0xffff) * 0x9069 + (a >> 16);
        unsigned int b = rng->s1;
        rng->s1 = (b & 0xffff) * 0x4650 + (b >> 16);
        unsigned int random = ((rng->s1 & 0xffff) + (rng->s0 << 16)) % (unsigned int)count;
        int index = random + ((int*)&DAT_003ff8e0)[state];
        Factory_835a0 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
        Entry_835a0 *entry = &((Entry_835a0*)&DAT_004dd270)[index];
        char casterStorage[sizeof(content::LoadInventory::DynamicCaster<pure3d::Animation>)];
        content::LoadInventory::DynamicCaster<pure3d::Animation> *caster = new (casterStorage) content::LoadInventory::DynamicCaster<pure3d::Animation>;
        f38 = factory->f3(caster, entry->id0, entry->id1);
        if (!f38) return;
        f40 = f38->FUN_00288a20(0);
        if (f40) {
            f44 = f40->FUN_00288960(0x4e415254,0x54434556);
            f48 = f40->FUN_00288960(0x544f52,0x544f52);
        } else { f44 = 0; f48 = 0; }
        float blend = b1c ? 0.0f : 10.0f;
        b1c = 0;
        if (alive && b1d) f3c->v24(f38,0,blend);
        char selected = entry->b08;
        f3c->v16(2);
        f3c->v18(selected ? 0 : 1);
        Mgr2_835a0 *manager = DAT_004dd700->mgr2;
        switch (state) {
        case 0:
            f20 = FUN_000964d0()->FUN_000787e0(2.0f,10.0f);
            f34 = f30 = f2c = 0.0f; break;
        case 1:
            f20 = FUN_000964d0()->FUN_000787e0(30.0f,60.0f);
            f34 = f30 = f2c = 0.0f; break;
        case 2: {
            Vec3_835a0 direction, rotated;
            direction.x = 0.0f; direction.y = 0.0f; direction.z = 1.0f;
            transform.FUN_0022c3b0(&direction,&rotated);
            volatile float angle = FUN_000964d0()->FUN_000787e0(-0.03f,0.03f);
            FUN_00224d70(angle,&rotated);
            transform.FUN_0022cc90(&rotated);
            f20 = FUN_000964d0()->FUN_000787e0(2.0f,15.0f);
            break;
        }
        case 4:
            f3c->v8(1.5f);
            f20 = FUN_000964d0()->FUN_000787e0(5.0f,20.0f);
            if (entity) entity->FUN_001d72e0()->FUN_002ef8b0(0);
            manager->FUN_001ebc80(this,"moo"); break;
        case 5:
            manager->FUN_001ebc80(this,"moo"); f20 = 3.4028235e+38f; break;
        case 6:
            if (entity) entity->FUN_001d7510();
            manager->FUN_001ebc80(this,"moo");
            f20 = 3.4028235e+38f; break;
        case 7:
            if (entity) entity->FUN_001d7510();
            manager->FUN_001ebc80(this,"moo");
            f20 = 1.0f; break;
        case 8:
            if (entity) entity->FUN_001d72e0()->FUN_002ef8b0(0);
            f20 = 3.4028235e+38f; break;
        default: f20 = 3.4028235e+38f; break;
        }
    }
    volatile float elapsed = dt + f24;
    f24 = elapsed;
    f28 = dt + f28;
    if (state == 4) {
        Vec3_835a0 delta;
        DAT_004dd700->list->player->f10->FUN_00059a50(&delta);
        Vec3_835a0 *position = DAT_004dd700->world->FUN_001dc3b0(f10);
        delta.x = delta.x - position->x;
        delta.y = delta.y - position->y;
        delta.z = delta.z - position->z;
        delta.FUN_0022d110();
        delta.x = delta.x * -1.0f;
        delta.y = delta.y * -1.0f;
        delta.z = delta.z * -1.0f;
        FUN_00083080(&transform,&delta,0.01f);
    } else if (state == 5) f28 = 0.0f;
    else if (state == 8 && !alive && elapsed > 1.5f) { state = 0; f24 = 0.0f; }
    bool transition = false;
    if (f3c->v19() == 0 && f24 >= f20) transition = true;
    else if (f3c->v22()) transition = true;
    if (transition) {
        switch (state) {
        case 0: case 4: state = 2; f24 = 0.0f; break;
        case 1: case 2: case 3: case 5: state = 0; f24 = 0.0f; break;
        case 6: break;
        case 7:
            if (alive && entity && entity->FUN_001d72e0()->f70->v11()) {
                FUN_00082d30(&transform);
                f30 = 0.0f;
                entity->FUN_001d72e0()->FUN_002ef8b0(0);
                state = 8; f24 = 0.0f;
            }
            break;
        default: state = 0; f24 = 0.0f; break;
        }
    }
    if (alive) FUN_00082db0(dt,&transform);
    else {
        transform.m[12] = dt * f2c + transform.m[12];
        transform.m[13] = dt * f30 + transform.m[13];
        f28 = 0.0f;
        transform.m[14] = dt * f34 + transform.m[14];
    }
    if (!alive || entity->FUN_001d72e0()->f6c == 0)
        world->FUN_001dd470(f10,&transform,dt);
    b1d = alive;
}