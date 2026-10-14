// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000a9400 @ 0x000a9400
namespace pure3d {
struct Camera {
    Camera();
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void vfunc_7(float);
    virtual void slot8();
    virtual void vfunc_9(float);
    char pad[0xcc];
};
}
struct Clock_a9400 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual float s16();
};
extern Clock_a9400* DAT_0052c2a4;
struct Vector { float x,y,z; };
struct CGameCamera : pure3d::Camera {
 int d0; int d4; int d8; int dc;
 float e0,e4,e8,ec;
 unsigned char f0,f1; char padf2[6];
 int f8; char pfc[12]; int f108; char p10c[12]; int f118; char p11c[12];
 int f128; char p12c[12]; int f138; char p13c[12]; int f148; char p14c[8];
 Vector v154,v160;
 CGameCamera();
 virtual void slot0();
 void FUN_000a9090(float);
};
CGameCamera::CGameCamera() {
 e4=0.0f; ec=0.0f; e8=1.0f; f0=0; f1=0;
 v154.x=0.0f; v154.y=0.0f; v154.z=1.0f;
 v160.x=0.0f; v160.y=0.0f; v160.z=1.0f;
 e0=DAT_0052c2a4->s16();
 d4=0;
 FUN_000a9090(75.0f);
 pure3d::Camera::vfunc_7(0.1f);
 pure3d::Camera::vfunc_9(3000.0f);
 f8=0; f108=0; f118=0; f128=0; f138=0; f148=0;
}
