class Sub { public: void second(int); void third(); };
class C { char pad[0x20c]; int a; int b; public: void f(); };
void FUN_00310550();
void C::f() { a = b; FUN_00310550(); b = 0x4e6e6b28; Sub* p = (Sub*)((char*)this + 0x168); p->second(0x3c83126f); p->third(); }