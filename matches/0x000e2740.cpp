// Same code shape as 0x000e21a0 (propagated; names are from that function)
class FELayout { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); char pad[0x34 - 4]; };
class SingleLayout : public FELayout { public: virtual void g5(); virtual void g6(); virtual void g7(); virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15(); virtual float g16(int); float value; };
float SingleLayout::g16(int) { return value; }