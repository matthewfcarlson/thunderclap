// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000a94c0 @ 0x000a94c0
namespace pure3d {
struct Camera {
 Camera();
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6();
 virtual void vfunc_7(float);
 virtual float slot8();
 virtual void vfunc_9(float);
 virtual float slot10();
 virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual unsigned slot14();
 virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void vfunc_21(unsigned);
 char pad[0xd0]; unsigned d4; char padD8[8]; float e0; unsigned e4,e8,ec; unsigned char f0,f1; char padF2[6]; unsigned f8; char pfc[12]; unsigned f108; char p10c[12]; unsigned f118; char p11c[12]; unsigned f128; char p12c[12]; unsigned f138; char p13c[12]; unsigned f148; char p14c[8]; float x,y,z,u,v,w;
 void FUN_000a9090(unsigned);
};
}
struct Clock { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual float s16(); };
extern Clock* DAT_0052c2a4;
struct CGameCamera: pure3d::Camera { CGameCamera(const CGameCamera& src); };
CGameCamera::CGameCamera(const CGameCamera& src) {
 e4=src.e4; e8=src.e8; ec=src.ec; f0=src.f0; f1=src.f1;
 x=0.0f; y=0.0f; z=1.0f; u=0.0f; v=0.0f; w=1.0f;
 e0=DAT_0052c2a4->s16(); d4=0;
 FUN_000a9090(src.d4);
 pure3d::Camera::vfunc_7(const_cast<CGameCamera&>(src).slot8());
 pure3d::Camera::vfunc_9(const_cast<CGameCamera&>(src).slot10());
 pure3d::Camera::vfunc_21(const_cast<CGameCamera&>(src).slot14());
 x=src.x; y=src.y; z=src.z; u=src.u; v=src.v; w=src.w;
 f8=src.f8; f108=src.f108; f118=src.f118; f128=src.f128; f138=src.f138; f148=src.f148;
}
