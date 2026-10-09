struct H { void run(); };
class C { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(int); char pad[0x54]; H h; void target(int x,int y,int z); };
void C::target(int x,int y,int z) { *(int*)((char*)this+0x58)=x; *(int*)((char*)this+0x5c)=y; *(int*)((char*)this+0x60)=z; h.run(); f9(1); }
