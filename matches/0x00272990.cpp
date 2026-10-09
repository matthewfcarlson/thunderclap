class V { public: virtual void A(); virtual void B(); };
class C { public: char pad[0xc]; V v; char pad2[0x30]; int state; int value; void F(int); };
void C::F(int x) { v.A(); value=x; state=2; v.B(); }