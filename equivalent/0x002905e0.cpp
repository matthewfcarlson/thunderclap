// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 32/32)
// FUN_002905e0 @ 0x002905e0
inline void *operator new(unsigned int, void *p) { return p; }

extern "C" void __cdecl FUN_0008d330(void *p);
extern "C" void __cdecl FUN_0008d340(void *p);

struct Part_2905e0 {
    char data[8];
    void FUN_0027af50();
};

struct Item10_2905e0 {
    char pad0[8];
    void *buffer;
    char pad1[4];
    void FUN_0027af50();
};

struct Item20 {
    char data[0x20];
    void FUN_0027af50();
};

struct Item30 {
    char data[0x30];
    void FUN_0027af50();
};

struct Item58 {
    char pad0[0x28];
    Part_2905e0 p28;
    Part_2905e0 p30;
    Part_2905e0 p38;
    Part_2905e0 p40;
    char pad1[0x58 - 0x48];
};

class Releasable_2905e0 {
public:
    virtual void vf0();
    virtual void release();
};

namespace core {
struct IRefCount {
    void FUN_0027afd0();
};
}

namespace pure3d {
namespace prop {
class StateData {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad04[0x14 - 4];
    int count14;
    Item10_2905e0 *items18;
    int count1c;
    Item20 *items20;
    int count24;
    Item10_2905e0 *items28;
    int count2c;
    Item30 *items30;
    int count34;
    Item10_2905e0 *items38;
    int count3c;
    Item10_2905e0 *items40;
    int count44;
    Item58 *items48;
    Releasable_2905e0 *owner4c;
    void *data50;

    void FUN_002905e0();
};
}
}

void pure3d::prop::StateData::FUN_002905e0()
{
    new (this) StateData;
    int i;
    for (i = 0; i < count14; i++)
        ((Part_2905e0 *)((char *)items18 + i * 0x10))->FUN_0027af50();
    for (i = 0; i < count1c; i++)
        ((Part_2905e0 *)((char *)items20 + i * 0x20))->FUN_0027af50();
    for (i = 0; i < count24; i++)
        ((Part_2905e0 *)((char *)items28 + i * 0x10))->FUN_0027af50();
    for (i = 0; i < count2c; i++)
        ((Part_2905e0 *)((char *)items30 + i * 0x30))->FUN_0027af50();
    for (i = 0; i < count34; i++)
        ((Part_2905e0 *)((char *)items38 + i * 0x10))->FUN_0027af50();
    for (i = 0; i < count44; i++) {
        Item58 *e = &items48[i];
        e->p40.FUN_0027af50();
        e->p38.FUN_0027af50();
        e->p30.FUN_0027af50();
        e->p28.FUN_0027af50();
    }
    for (i = 0; i < count3c; i++) {
        Item10_2905e0 *e = &items40[i];
        if (e->buffer) {
            FUN_0008d340(e->buffer);
            e->buffer = 0;
        }
        ((Part_2905e0 *)e)->FUN_0027af50();
    }
    if (owner4c) {
        owner4c->release();
        owner4c = 0;
    }
    FUN_0008d330(data50);
    ((core::IRefCount *)this)->FUN_0027afd0();
}
