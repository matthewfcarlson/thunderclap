class SpriteParticleEmitter {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void vfunc_15();
 char pad[0x14c-4];
 unsigned int count;
 char pad2[0x1c8-0x150];
 int* items;
};
struct Buffer { int a[2]; int used; int* data; };
void SpriteParticleEmitter::vfunc_15() {
 unsigned int i=0;
 Buffer* b=*(Buffer**)((char*)this+0x84);
 while (i<count) {
  int* p=items+i;
  int v=*p;
  if (v) { b->data[b->used++]=v; *p=0; }
  ++i;
 }
 count=0;
}