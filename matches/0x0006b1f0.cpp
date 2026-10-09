class CTrack { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual int vfunc_12(int); };
class Alloc { public: int method(CTrack*, int); };
extern void* __cdecl FUN_0008d690(unsigned int);
int CTrack::vfunc_12(int param) { Alloc* p = (Alloc*)FUN_0008d690(0x38); if (p) return p->method(this, param); return 0; }