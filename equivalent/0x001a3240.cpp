// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001a3240 @ 0x001a3240
namespace hulkfight { namespace scenario {

struct Slot_1a3240 {
    int a;
    int b;
    int c;
    char d;
    char e;
    char pad[2];
};

// equiv-map: ??0Base@scenario@hulkfight@@QAE@XZ = 0x00236d40
class Base {
public:
    Base();
    virtual void vfunc_0();
    int f4;
    int f8;
};

class NISAnimationTrack : public Base {
public:
    NISAnimationTrack();
    virtual void vfunc_0();
    int fc;
    float f10;
    float f14;
    int f18;
    int f1c;
    float f20;
    int f24;
    int f28;
    int f2c;
    char f30;
    char pad31[3];
    int f34[7];
    char f50;
    char f51;
    char f52;
    char pad53;
    int f54;
    char f58;
    char f59;
    char pad5a[2];
    Slot_1a3240 slots[19];     // 0x5c
    int f18c;
    int f190;
    int f194;
};

NISAnimationTrack::NISAnimationTrack() {
    f10 = -1.0f;
    f20 = -1.0f;
    f14 = 1.0f;
    fc = 0; f18 = 0; f1c = 0; f24 = 0; f28 = 0; f2c = 0;
    f30 = 1;
    for (int i = 0; i < 7; i++) f34[i] = 0;
    f50 = 0; f51 = 0; f52 = 1;
    f54 = 0; f58 = 0; f59 = 1;
    for (int i = 0; i < 19; i++) {
        slots[i].a = 0; slots[i].b = 0; slots[i].c = 0;
        slots[i].d = 0; slots[i].e = 1;
    }
    f18c = 0; f190 = 0; f194 = 0;
}
}}
