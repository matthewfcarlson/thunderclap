// STATUS: equivalent (tools/equiv.py level 3: 2173 inputs, branch coverage 0/0)
// FUN_002c5ad0 @ 0x002c5ad0
struct Vec_2c5ad0 { unsigned int x; float y,z; };
struct Buffer_2c5ad0 { char pad0[8]; Vec_2c5ad0* position; char pad1[4]; unsigned int* color; void FUN_0008ef00(); };
struct Renderer_2c5ad0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual Buffer_2c5ad0* create(unsigned int,int,int,int,int); virtual void finish(Buffer_2c5ad0*); };
extern Renderer_2c5ad0* DAT_0052c2a8;
struct Object { unsigned int type,color; void FUN_002c5ad0(Vec_2c5ad0* vertices); };
void Object::FUN_002c5ad0(Vec_2c5ad0* vertices) {
 Buffer_2c5ad0* b=DAT_0052c2a8->create(type,3,0x2020,4,0);
 for(int i=0;i<4;++i) {
  *b->color=color;
  Vec_2c5ad0* v=vertices+(i==3?0:i);
  float z=v->z; float y=v->y; unsigned int x=v->x;
  b->position->x=x;
  b->position->y=y;
  b->position->z=z;
  b->FUN_0008ef00();
 }
 DAT_0052c2a8->finish(b);
}
