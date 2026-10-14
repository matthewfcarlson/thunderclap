// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 10/10)
// FUN_002f6220 @ 0x002f6220
// equiv-map: ??0SymMatrix@physics@@QAE@XZ = 0x002fca90
// equiv-map: ??0SimulatedObject@physics@@QAE@H@Z = 0x002fe570
// equiv-map: ??0SimTime@physics@@QAE@M@Z = 0x002ecf40
// equiv-map: ??0SimLength@physics@@QAE@M@Z = 0x002ecf20
// equiv-map: ??1SimUnits@physics@@UAE@XZ = 0x002ecca0
inline void *operator new(unsigned int, void *p) throw() { return p; }

extern unsigned int DAT_004d2b74;
extern float DAT_004d2b7c;
extern float DAT_004d2b80;
extern float DAT_00555450;
extern float DAT_00555454;
extern float DAT_00555458;

struct V3_2f6220 {
    float x, y, z;
};

struct Id64_2f6220 {
    int lo, hi;
    void FUN_0027af00() throw();
};

struct Matrix {
    float m[16];
    void FUN_0022b980() throw();
};


struct Filter_2f6220 {
    char data[0x64];
    void FUN_00308cc0() throw();
    void FUN_00308a70(void *owner) throw();
};

namespace physics {

class SimUnits {
public:
    virtual ~SimUnits() throw();
};

class SimCGSValue : public SimUnits {
public:
    virtual void vfunc_1(float v) throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual ~SimCGSValue() throw() {}
    float value;
    float scale;
};

class SimTime : public SimCGSValue {
public:
    SimTime(float v) throw();
    virtual ~SimTime() throw() {}
    virtual void vfunc_1(float v) throw();
};

class SimLength : public SimCGSValue {
public:
    SimLength(float v) throw();
    virtual ~SimLength() throw() {}
    virtual void vfunc_1(float v) throw();
};

class SymMatrix {
public:
    SymMatrix() throw();
    virtual ~SymMatrix() throw() {}
    float m[6];
};

class SimulatedObject {
public:
    SimulatedObject(int v) throw();
    virtual ~SimulatedObject() throw();
    virtual void vfunc_1() throw();
    char pad4[0xc];
    int f10;
    char pad14[0x10];
    int f24;
    int f28;
    int f2c;
};

class PhysicsObject : public SimulatedObject {
public:
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual void vfunc_5() throw();
    virtual void vfunc_6(int v) throw();
    virtual void vfunc_7() throw();
    virtual void vfunc_8() throw();
    virtual void vfunc_9() throw();
    virtual void vfunc_10() throw();
    virtual void vfunc_11() throw();
    virtual void vfunc_12() throw();
    virtual void vfunc_13() throw();
    virtual void vfunc_14() throw();
    virtual void vfunc_15() throw();
    virtual void vfunc_16() throw();
    virtual void vfunc_17() throw();
    virtual void vfunc_18() throw();
    virtual void vfunc_19() throw();
    virtual void vfunc_20() throw();
    virtual void vfunc_21() throw();
    virtual void vfunc_22() throw();
    virtual void vfunc_23() throw();
    virtual void vfunc_24() throw();
    virtual void vfunc_25() throw();
    virtual void vfunc_26() throw();
    virtual void vfunc_27() throw();
    virtual void vfunc_28() throw();
    virtual void vfunc_29() throw();
    virtual void vfunc_30() throw();
    virtual void vfunc_31() throw();
    virtual void vfunc_32() throw();
    virtual void vfunc_33() throw();
    virtual void vfunc_34() throw();
    virtual void vfunc_35() throw();
    virtual void vfunc_36() throw();
    virtual void vfunc_37() throw();
    virtual void vfunc_38() throw();
    virtual void vfunc_39() throw();
    Id64_2f6220 id30;
    int f38;
    int f3c;
    int f40;
    float f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    Matrix m58;
    V3_2f6220 v98;
    char pada4;
    char pada5[3];
    V3_2f6220 va8;
    V3_2f6220 vb4;
    V3_2f6220 vc0;
    V3_2f6220 vcc;
    float fd8;
    char symdc[0x1c];
    char symf8[0x1c];
    char sym114[0x1c];
    V3_2f6220 v130;
    V3_2f6220 v13c;
    char b148;
    char pad149[3];
    V3_2f6220 v14c;
    V3_2f6220 v158;
    float f164;
    Filter_2f6220 filt168;
    int f1cc;
    char b1d0;
    char pad1d1[3];
    int f1d4;
    float f1d8;
    int f1dc;
    float f1e0;
    float f1e4;
    float f1e8;
    int f1ec;
    union {
        unsigned int dw;
        unsigned char b[4];
    } w1f0;
    unsigned char b1f4;

    PhysicsObject(int arg, V3_2f6220 *pos, SymMatrix *inertia, int owner);
};

PhysicsObject::PhysicsObject(int arg, V3_2f6220 *pos, SymMatrix *inertia, int owner) : SimulatedObject(arg)
{
    id30.FUN_0027af00();
    f38 = owner;
    f44 = 1.0f;
    f48 = 5;
    f40 = owner;
    f3c = owner;
    new (symdc) SymMatrix(*inertia);
    new (symf8) SymMatrix();
    new (sym114) SymMatrix();
    b148 = 1;
    v14c.x = 0;
    v14c.y = 0;
    v14c.z = 0;
    v158.x = 0;
    v158.y = 0;
    v158.z = 0;
    filt168.FUN_00308cc0();
    f1cc = 0;
    b1d0 = 0;
    f1d4 = 0;
    f1d8 = 1.0f / (float)DAT_004d2b74;
    f1dc = 0;
    f1e0 = 1.0f / (float)DAT_004d2b74;
    f1e4 = DAT_004d2b80;
    f1e8 = DAT_004d2b7c;
    w1f0.b[0] = 0;
    b1f4 |= 3;
    f1ec = 0;
    w1f0.dw |= 0xff00;
    f24 = 0;
    f4c = 0;
    f50 = 0;
    f54 = 0;
    SimTime a(2.0f);
    f164 = 1.0f / a.value;
    if (DAT_00555450 == 0.0f) {
        SimLength b(0.1f);
        a.vfunc_1(1.0f);
        DAT_00555450 = b.value / a.value;
        a.vfunc_1(0.5f);
        DAT_00555454 = a.value;
        a.vfunc_1(0.1f);
        DAT_00555458 = a.value;
    }
    *(SymMatrix *)symf8 = *(SymMatrix *)symdc;
    filt168.FUN_00308a70(this);
    m58.FUN_0022b980();
    va8.z = 0;
    va8.y = 0;
    va8.x = 0;
    vb4.z = 0;
    vb4.y = 0;
    vb4.x = 0;
    v98 = *pos;
    va8.x = v98.x;
    va8.y = v98.y;
    va8.z = v98.z;
    pada4 = (va8.x * va8.x + va8.y * va8.y + va8.z * va8.z < 1e-05f) ? 1 : 0;
    if (f10) {
        vfunc_6(0);
    }
    vcc.z = 0;
    vcc.y = 0;
    vcc.x = 0;
    fd8 = 1.0f;
    v14c.z = 0;
    v14c.y = 0;
    v14c.x = 0;
    v158.z = 0;
    v158.y = 0;
    v158.x = 0;
    b148 = 1;
    vc0.z = 0;
    vc0.y = 0;
    vc0.x = 0;
    v130.z = 0;
    v130.y = 0;
    v130.x = 0;
    v13c.z = 0;
    v13c.y = 0;
    v13c.x = 0;
    b1d0 = 0;
    vfunc_39();
    vfunc_7();
}

}
