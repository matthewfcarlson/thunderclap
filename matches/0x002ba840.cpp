struct V { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(int); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(int, void*); };
struct Inner { V *v; char pad[0x7c]; unsigned int x; };
struct Obj { Inner *p; };
struct Billboard { char pad[0x48]; Obj *obj; char pad2[0x0c]; unsigned int value; void vfunc_8(unsigned int, unsigned int); void helper(unsigned int, unsigned int); };
extern V **gObj;
void Billboard::vfunc_8(unsigned int a, unsigned int b) { gObj[0]->f23(0, (char*)obj->p + 0x40); obj->p->x = value; helper(a, b); obj->p->x = 0x3f800000; gObj[0]->f16(0); }
