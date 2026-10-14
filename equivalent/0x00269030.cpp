// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00269030 @ 0x00269030
struct Pad_269030 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(int, int);
    char reserved[0x49a]; unsigned char enabled; char end;
    void FUN_00268fa0();
};
struct Device_269030 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(int, int); };
extern int DAT_004cdbb0;
extern Device_269030* DAT_00528388;
int FUN_002705f0();
int FUN_00267f80();
void __cdecl FUN_00270940(Device_269030**, int);
namespace core {
struct Object { virtual void b0(); int id; Object() : id(DAT_004cdbb0) { FUN_002705f0(); } };
struct IControllerSystem {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(int) = 0; virtual void a7(int, int) = 0;
};
struct ControllerSystemXBox : IControllerSystem, Object {
    int valuec; unsigned char value10; char gap11[3];
    int value14; int value18; int value1c;
    char padBytes[4 * 0x4a0];
    int value12a0; int value12a4;
    virtual void a6(int);
    virtual void a7(int, int);
    virtual void b0();
    void vfunc_7(int, int);
    ControllerSystemXBox(int first, int second);
};
ControllerSystemXBox::ControllerSystemXBox(int first, int second) {
    Pad_269030* pads = (Pad_269030*)padBytes;
    valuec = 0; value10 = 0; value14 = 0; value18 = 0; value1c = 0;
    for (int i = 0; i < 4; ++i) pads[i].FUN_00268fa0();
    FUN_002705f0();
    value12a0 = 10;
    value12a4 = FUN_00267f80();
    Device_269030** devices = &DAT_00528388;
    for (int j = 0; j < 4; ++j) {
        FUN_00270940(&devices[j], second);
        devices[j]->d3(3, 22);
    }
    if (first && !value1c) value1c = first;
    value12a0 = 10;
    IControllerSystem* sys = this;
    sys->a6(value18);
    ControllerSystemXBox::vfunc_7(0, 0);
    value10 = 0;
    sys->a7(0, 0);
    int x = value12a0;
    value18 = 10;
    for (int k = 0; k < 4; ++k)
        if (pads[k].enabled) pads[k].m20(10, x);
}
}
