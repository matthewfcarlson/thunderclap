typedef unsigned int u32;
void* operator_new(unsigned int);
class Condition { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); void Init(int); };
struct Tail { void InitTail(); };
class Factory { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual Condition* v5(); };
Condition* Factory::v5() { Condition* p = (Condition*)operator_new(0x10); if (p) { p->Init(0); *(u32*)p = 0x4288fc; ((Tail*)((char*)p+12))->InitTail(); return p; } return 0; }