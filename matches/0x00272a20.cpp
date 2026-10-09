class Inner { public: virtual void A(); virtual void B(); };
class Obj { public: char pad[0xc]; Inner inner; char pad2[0x30]; int value; int target(); };
int Obj::target() { inner.A(); int v = value; inner.B(); return v; }