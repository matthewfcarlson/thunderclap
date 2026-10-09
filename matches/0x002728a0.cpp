class Sub { public: virtual void A(); virtual void B(); };
class Obj { public: char pad[0x0c]; Sub sub; char pad2[0xa4]; int value; void F(int); };
void Obj::F(int x) { sub.A(); value = x; sub.B(); }