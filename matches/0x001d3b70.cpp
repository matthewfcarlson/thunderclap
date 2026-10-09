typedef unsigned int u32;
class A { public: void f(u32); };
class B { public: void f(u32); };
class Obj { public: char pad[8]; void* field8; char pad2[4]; void run(u32 a,u32 b); };
void __cdecl F3(void*, u32);
void __cdecl F4(void*, void*, int);
void __cdecl F5(void*, int, u32);
void Obj::run(u32 a,u32 b) {
 ((A*)b)->f(a);
 ((B*)((char*)this+0xc))->f(b);
 void* x=field8;
 F3(x,b);
 F4(x,(void*)0x1d22a0,1);
 F5(x,0xffffd8ef,a);
}
