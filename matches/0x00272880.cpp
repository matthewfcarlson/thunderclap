class Sub { public: virtual void A(); virtual void B(); };
class Obj { public: char pad[0x0c]; Sub sub; char pad2[0xa4]; int value; int Run(); };
int Obj::Run() { sub.A(); int v=value; sub.B(); return v; }