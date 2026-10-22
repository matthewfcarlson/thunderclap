// STATUS: equivalent (tools/equiv.py level 3: 6630 inputs, branch coverage 6/6)
// FUN_002251d0 @ 0x002251d0
struct Vec_2251d0 { float x,y,z; };
// The single source fills a 16-byte vector (the real callee writes w = 1.0f after z).
struct Vec4_2251d0 { float x,y,z,w; };
struct Matrix { float m[16]; void FUN_0022c3b0(Vec_2251d0*,Vec_2251d0*); };
struct Quat_2251d0 { float x,y,z,w; void FUN_0022b650(Matrix*); };
void __cdecl FUN_0022b080(Quat_2251d0*,Quat_2251d0*,Vec4_2251d0*);
struct Input_2251d0 { Quat_2251d0* FUN_00221cd0(); Matrix* FUN_00221c40(); };
struct PairSource { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void sample(void*,void*,Vec_2251d0*); };
struct SingleSource { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void sample(void*,Vec4_2251d0*); };
struct AnimationDriver_2251d0 { char pad0[0x24]; PairSource* pair; SingleSource* single; char pad1[0x228-0x2c]; float direction; void run(Input_2251d0*,void*,void*,Vec_2251d0*); };
void AnimationDriver_2251d0::run(Input_2251d0* input, void* a, void* b, Vec_2251d0* out) {
 Vec_2251d0 offset;
 if(pair) {
  if(direction >= 0.0f) pair->sample(a,b,&offset);
  else { pair->sample(b,a,&offset); offset.x=-offset.x; offset.y=-offset.y; offset.z=-offset.z; }
 } else { offset.x=0.0f; offset.y=0.0f; offset.z=0.0f; }
 Matrix matrix;
 if(single) {
  Quat_2251d0 q=*input->FUN_00221cd0();
  Vec4_2251d0 v;
  single->sample(a,&v);
  v.x=-v.x; v.y=-v.y; v.z=-v.z;
  FUN_0022b080(&q,&q,&v);
  q.FUN_0022b650(&matrix);
 } else matrix=*input->FUN_00221c40();
 matrix.FUN_0022c3b0(&offset,out);
}
