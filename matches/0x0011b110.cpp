extern void* Alloc(unsigned int);
class Obj { public: void Init(int); };
class Factory { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual Obj* f(); };
Obj* Factory::f() { Obj* p=(Obj*)Alloc(0x24); if(p) { p->Init(0); *(unsigned int*)p=0x40eae0; *(float*)((char*)p+12)=15.0f; *(float*)((char*)p+16)=100.0f; *(float*)((char*)p+20)=20.0f; *(float*)((char*)p+24)=2.0f; *((char*)p+28)=0; *(int*)((char*)p+32)=0; return p; } return 0; }