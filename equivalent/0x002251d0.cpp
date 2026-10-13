// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002251d0 @ 0x002251d0
struct Vec { float x,y,z; };
struct Matrix { float m[16]; void FUN_0022c3b0(Vec*,Vec*); };
struct Quat { float x,y,z,w; void FUN_0022b650(Matrix*); };
void __cdecl FUN_0022b080(Quat*,Quat*,Vec*);
struct Input { Quat* FUN_00221cd0(); Matrix* FUN_00221c40(); };
struct PairSource { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void sample(void*,void*,Vec*); };
struct SingleSource { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void sample(void*,Vec*); };
struct Target { char pad0[0x24]; PairSource* pair; SingleSource* single; char pad1[0x228-0x2c]; float direction; void run(Input*,void*,void*,Vec*); };
void Target::run(Input* input, void* a, void* b, Vec* out) {
 Vec offset;
 if(pair) {
  if(direction >= 0.0f) pair->sample(a,b,&offset);
  else { pair->sample(b,a,&offset); offset.x=-offset.x; offset.y=-offset.y; offset.z=-offset.z; }
 } else { offset.x=0.0f; offset.y=0.0f; offset.z=0.0f; }
 Matrix matrix;
 if(single) {
  Quat q=*input->FUN_00221cd0();
  Vec v;
  single->sample(a,&v);
  v.x=-v.x; v.y=-v.y; v.z=-v.z;
  FUN_0022b080(&q,&q,&v);
  q.FUN_0022b650(&matrix);
 } else matrix=*input->FUN_00221c40();
 matrix.FUN_0022c3b0(&offset,out);
}
