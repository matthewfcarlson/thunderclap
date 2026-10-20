// STATUS: equivalent (tools/equiv.py level 3: 19974 inputs, branch coverage 16/16)
// hulkfight::motion::AnimationPhaseMatchedAction::vfunc_3 @ 0x0013d7b0
#include "gen/hulkfight.h"
#include "decls/address.h"

namespace pure3d { class Animation_13d7b0; }
namespace content {
class LoadInventory_13d7b0 {
  public:
    template <class T> class DynamicCaster_13d7b0 {
      public:
        virtual T *Cast(void *p);
    };
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void *Find(const DynamicCaster_13d7b0<pure3d::Animation_13d7b0> &c, __int64 uid);
};
}

struct Name_13d7b0 {
    char pad[8];
    void FUN_0027af70(const void *v);
};
struct Instance_13d7b0;
struct Stage_13d7b0 {
    void *FUN_0027b670(__int64 key);
};
struct Instance_13d7b0 {
    virtual void vfn0();
    virtual void vfn1();
    char pad[8 - 4];
    Name_13d7b0 name;                // 0x8
    char pad2[0x224 - 0x10];
    char active;              // 0x224
    Instance_13d7b0 *FUN_00225950(Stage_13d7b0 *stage, void *anim);
    void FUN_002224a0(void *v);
    void FUN_00225e00(float v, float one, int a, int b);
    void FUN_00225cf0(int v);
};
struct Part_13d7b0 {
    Stage_13d7b0 *FUN_002226b0();
    void FUN_00222890(Instance_13d7b0 *inst, float v, int a, float one, int b, int c, float minusOne);
};
struct Holder_13d7b0 {
    Part_13d7b0 *FUN_00059a40();
};
struct Target_13d7b0 { float FUN_00225b30(); };
struct Params_13d7b0 {
    Holder_13d7b0 *FUN_000592a0();
};
void *__cdecl FUN_00263ea0(unsigned int size);

struct Services_13d7b0 {
    content::LoadInventory_13d7b0 *FUN_00203d70();
};
struct Registry_13d7b0 {
    Services_13d7b0 *FUN_000862a0();
};
struct World {
    char pad[0x54];
    Registry_13d7b0 *registry;       // 0x54
};

struct Spec_13d7b0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual float vfn7(float one, int a, int b);
    char pad[0x18 - 4];
    int uidLo;                // 0x18
    int uidHi;                // 0x1c
    int f20;
    int f24;
    int f28;
    char pad2[0x30 - 0x2c];
    int keyLo;                // 0x30
    int keyHi;                // 0x34
    int f38;
    int f3c;
    int f40;
};


bool hulkfight::motion::AnimationPhaseMatchedAction::vfunc_3(int unused0, int unused1) {
    if ((*(Params_13d7b0 * *)&this->f_20) == 0) return false;
    Part_13d7b0 *part = (*(Params_13d7b0 * *)&this->f_20)->FUN_000592a0()->FUN_00059a40();
    if (part == 0) return false;
    Stage_13d7b0 *stage = part->FUN_002226b0();
    Registry_13d7b0 *reg = DAT_004dd700->registry;
    __int64 uid = ((__int64)(*(Spec_13d7b0 * *)&this->f_1c)->uidHi << 32) | (unsigned int)(*(Spec_13d7b0 * *)&this->f_1c)->uidLo;
    content::LoadInventory_13d7b0 *inv = reg->FUN_000862a0()->FUN_00203d70();
    void *anim = inv->Find(content::LoadInventory_13d7b0::DynamicCaster_13d7b0<pure3d::Animation_13d7b0>(), uid);
    if (anim == 0) return false;
    Instance_13d7b0 *mem = (Instance_13d7b0 *)FUN_00263ea0(0x240);
    Instance_13d7b0 *inst = 0;
    if (mem != 0)
        inst = mem->FUN_00225950(stage, anim);
    if (inst != 0)
        inst->vfn0();
    if ((*(Instance_13d7b0 * *)&this->f_24) != 0)
        (*(Instance_13d7b0 * *)&this->f_24)->vfn1();
    (*(Instance_13d7b0 * *)&this->f_24) = inst;
    inst->name.FUN_0027af70((char *)anim + 8);
    if (((*(Spec_13d7b0 * *)&this->f_1c)->keyLo | (*(Spec_13d7b0 * *)&this->f_1c)->keyHi) != 0) {
        void *r = stage->FUN_0027b670(((__int64)(*(Spec_13d7b0 * *)&this->f_1c)->keyHi << 32) | (unsigned int)(*(Spec_13d7b0 * *)&this->f_1c)->keyLo);
        if (r != 0)
            (*(Instance_13d7b0 * *)&this->f_24)->FUN_002224a0(r);
    }
    int a38 = (*(Spec_13d7b0 * *)&this->f_1c)->f38;
    int a3c = (*(Spec_13d7b0 * *)&this->f_1c)->f3c;
    int a40 = (*(Spec_13d7b0 * *)&this->f_1c)->f40;
    (*(Instance_13d7b0 * *)&this->f_24)->active = 1;
    Spec_13d7b0 *s = (*(Spec_13d7b0 * *)&this->f_1c);
    int a24 = s->f24;
    int a28 = s->f28;
    float v = s->vfn7(1.0f, a24, a28);
    (*(Instance_13d7b0 * *)&this->f_24)->FUN_00225e00(v, 1.0f, a24, a28);
    (*(Instance_13d7b0 * *)&this->f_24)->FUN_00225cf0((*(Spec_13d7b0 * *)&this->f_1c)->f20);
    float w = ((Target_13d7b0*)(*(Instance_13d7b0 * *)&this->f_24))->FUN_00225b30();
    part->FUN_00222890((*(Instance_13d7b0 * *)&this->f_24), w, a38, 1.0f, a3c, a40, -1.0f);
    return true;
}
