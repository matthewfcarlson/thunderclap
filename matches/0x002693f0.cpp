class Pad { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual bool f3(); char rest[0x49c]; };
class ControllerSystemXBox { char pad[0x20]; Pad controllers[4]; public: int vfunc_3(); };
int ControllerSystemXBox::vfunc_3() { int n=0; for(int i=0;i<4;++i) if(controllers[i].f3()) ++n; return n; }