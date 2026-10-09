typedef unsigned int uint;
extern uint __cdecl Decode(uint*, int);
struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(int,int,int); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); void *buf; int data; int pC; int p10; int p14; };
void Obj::f7(int a, int b, int d) {
 uint v=Decode((uint*)((char*)this+8), d);
 uint q=v >> 5;
 uint m=*((uint*)((char*)this+8)) >> 4;
 uint n=(m & 31) * q;
 uint bytes=n*20;
 pC=a; p14=bytes; p10=a-n*20+d;
 ((Obj*)buf)->f7(p10,b,bytes);
}