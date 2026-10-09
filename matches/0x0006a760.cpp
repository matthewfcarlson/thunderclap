class COrientTargetTrack { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual int vfunc_12(void*); virtual void f13(); };
class A { public: char pad[0x33c]; A* Next(); };
class B { public: A* Get(); };
class D { public: int Run(COrientTargetTrack*, void*, int); };
extern void* __cdecl FUN_0008d690(unsigned int);
extern D* __cdecl FUN_0001fc60(void*);
int COrientTargetTrack::vfunc_12(void* p) {
 B* b = (B*)p; A* a = b->Get(); a = a->Next();
 int v = *(int*)((char*)a + 0x338);
 if (!v) v = *(int*)((char*)a + 0x334);
 if (!v) v = *(int*)((char*)a + 0x330);
 if (v) { D* d = (D*)FUN_0008d690(0x2c); if (d) return d->Run(this,p,v); }
 return 0;
}