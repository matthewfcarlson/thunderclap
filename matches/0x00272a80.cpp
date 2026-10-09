class Inner { public: virtual void A(); virtual void B(); };
class Obj { public: char pad[0xc]; Inner p; char pad2[0x54-0x10]; unsigned char value; unsigned char target(); };
unsigned char Obj::target() { p.A(); unsigned char v = value; p.B(); return v; }