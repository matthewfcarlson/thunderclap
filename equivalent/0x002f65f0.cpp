// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 6/6)
// FUN_002f65f0 @ 0x002f65f0
// equiv-map: ??0SimulatedObject@physics@@QAE@H@Z = 0x002fe570
// equiv-map: ??0SimTime@physics@@QAE@M@Z = 0x002ecf40
// equiv-map: ??0SimLength@physics@@QAE@M@Z = 0x002ecf20
// equiv-map: ??1SimUnits@physics@@UAE@XZ = 0x002ecca0
extern unsigned int DAT_004d2b74;
extern float DAT_004d2b7c;
extern float DAT_004d2b80;
extern float DAT_00555450;
extern float DAT_00555454;
extern float DAT_00555458;

struct V3 {
    float x, y, z;
};

struct Id64 {
    int lo, hi;
    void FUN_0027af00() throw();
};

struct Matrix {
    float m[16];
    void FUN_0022b980() throw();
};

struct SymMatrix {
    char data[0x1c];
    void FUN_002fca90() throw();
};

struct Filter {
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

class SimulatedObject {
public:
    SimulatedObject(int v) throw();
    virtual ~SimulatedObject() throw();
    virtual void vfunc_1() throw();
    char pad4[0x20];
    int f24;
    int f28;
    int f2c;
};

class PhysicsObject : public SimulatedObject {
public:
    Id64 id30;
    int f38;
    int f3c;
    int f40;
    float f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    Matrix m58;
    V3 v98;
    char pada4[4];
    V3 va8;
    V3 vb4;
    V3 vc0;
    V3 vcc;
    float fd8;
    SymMatrix symdc;
    SymMatrix symf8;
    SymMatrix sym114;
    V3 v130;
    V3 v13c;
    char b148;
    char pad149[3];
    V3 v14c;
    V3 v158;
    float f164;
    Filter filt168;
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

    PhysicsObject(int arg);
};

PhysicsObject::PhysicsObject(int arg) : SimulatedObject(arg)
{
    id30.FUN_0027af00();
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 1.0f;
    f48 = 5;
    symdc.FUN_002fca90();
    symf8.FUN_002fca90();
    sym114.FUN_002fca90();
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
    SimTime a(10.0f);
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
    va8.x = 0;
    va8.y = 0;
    va8.z = 0;
    vb4.x = 0;
    vb4.y = 0;
    vb4.z = 0;
    v98.x = 0;
    v98.y = 0;
    v98.z = 0;
    filt168.FUN_00308a70(this);
    m58.FUN_0022b980();
    vcc.x = 0;
    vcc.y = 0;
    vcc.z = 0;
    fd8 = 1.0f;
    v14c.x = 0;
    v14c.y = 0;
    v14c.z = 0;
    v158.x = 0;
    v158.y = 0;
    v158.z = 0;
    b148 = 1;
    vc0.x = 0;
    vc0.y = 0;
    vc0.z = 0;
    v130.x = 0;
    v130.y = 0;
    v130.z = 0;
    v13c.x = 0;
    v13c.y = 0;
    v13c.z = 0;
    b1d0 = 0;
}

}
