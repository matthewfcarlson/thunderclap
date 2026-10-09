class Track { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual int v10(int,int,int); };
class Param {};
class NISAnimationTrack : public Track, public Param { public: virtual int v10(int,int,int); };
class X { public: int helper(int,int); };
extern "C" void* __cdecl FUN_0008d690(int);
int NISAnimationTrack::v10(int a, int b, int c) { void* x=FUN_0008d690(0x218); if(x) return ((X*)x)->helper((int)this,c); return 0; }