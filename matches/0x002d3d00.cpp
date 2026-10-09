// Same code shape as 0x00297130 (propagated; names are from that function)
class Scenegraph { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual int vfunc_4(); };
class Obj { public: int helper(Scenegraph*); };
extern Obj* alloc(int);
int Scenegraph::vfunc_4() { Obj* p=alloc(0x48); if(p) return p->helper(this); return 0; }