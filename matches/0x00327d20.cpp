typedef unsigned int u32;
class Obj { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual int l(); virtual void m(); virtual void n(); virtual void o(u32); void target(u32); };
extern u32 gSentinel;
extern Obj* gObj;
void Obj::target(u32 arg) {
 if (*(u32*)((char*)this+12) != gSentinel) {
  if (gObj) gObj->n();
  gSentinel=*(u32*)((char*)this+12);
  m();
  o(arg);
  gObj=this;
 } else if (l()!=1) o(arg);
}